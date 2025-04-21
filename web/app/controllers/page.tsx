"use client";

import { useEffect, useState } from "react";

export default function ControllersPage() {
  const [controllers, setControllers] = useState<any[]>([]);
  const [error, setError] = useState<string | null>(null);
  const [lastUpdated, setLastUpdated] = useState<string | null>(null); // Store the last updated time
  const [eventSource, setEventSource] = useState<EventSource | null>(null); // Keep a reference to the EventSource

  // Fetch initial controller list
  const fetchControllers = async () => {
    try {
      const res = await fetch("/api/controllers");
      const data = await res.json();

      if (res.ok) {
        setControllers(data);
        const currentTime = new Date().toLocaleString(); // Get the current date/time
        setLastUpdated(currentTime); // Set the last updated time
      } else {
        throw new Error(data?.error || "Failed to fetch controllers.");
      }
    } catch (err: any) {
      setError(err.message || "Something went wrong!");
    }
  };

  useEffect(() => {
    // Fetch initial controller list on component mount
    fetchControllers();

    // Set up SSE listener for real-time updates
    const eventSource = new EventSource("/api/events"); // The route that sends SSE events

    eventSource.onmessage = (event) => {
      const data = JSON.parse(event.data);
      if (data.message === "controllers_updated") {
        // If the message is "controllers_updated", re-fetch the controllers
        fetchControllers();
      }
    };

    eventSource.onerror = (error) => {
      console.error("Error with SSE connection:", error);
      setError("Error with SSE connection.");
    };

    // When the SSE connection is closed, ensure we don't use it again
    eventSource.onclose = () => {
      console.log("SSE connection closed");
      setEventSource(null); // Reset the EventSource when closed
    };

    // Store the event source reference in the state
    setEventSource(eventSource);

    // Clean up the EventSource when the component unmounts
    return () => {
      console.log("Closing SSE connection");
      eventSource.close();
      setEventSource(null); // Cleanup state on unmount
    };
  }, []);

  return (
    <div>
      <h2>Controllers</h2>
      {error && <p style={{ color: "red" }}>{error}</p>}
      {!error && controllers.length === 0 && <p>No controllers found.</p>}

      {lastUpdated && (
        <p>
          <strong>Last updated:</strong> {lastUpdated}
        </p>
      )}

      <ul>
        {controllers.map((controller: any, index: number) => (
          <li key={index}>{controller.type}</li>
        ))}
      </ul>
    </div>
  );
}
