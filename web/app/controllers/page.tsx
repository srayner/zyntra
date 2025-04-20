"use client";

import { useEffect, useState } from "react";

export default function ControllersPage() {
  const [controllers, setControllers] = useState<any[]>([]);
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    async function fetchControllers() {
      try {
        const res = await fetch("/api/controllers");
        const data = await res.json();

        if (res.ok) {
          setControllers(data);
        } else {
          throw new Error(data?.error || "Failed to fetch controllers.");
        }
      } catch (err: any) {
        setError(err.message || "Something went wrong!");
      }
    }

    fetchControllers();
  }, []);

  return (
    <div>
      <h2>Controllers</h2>
      {error && <p style={{ color: "red" }}>{error}</p>}
      {!error && controllers.length === 0 && <p>No controllers found.</p>}
      <ul>
        {controllers.map((controller: any, index: number) => (
          <li key={index}>{controller.type}</li>
        ))}
      </ul>
    </div>
  );
}
