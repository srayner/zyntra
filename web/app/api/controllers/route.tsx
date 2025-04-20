import { NextResponse } from "next/server";

export async function GET() {
  try {
    const res = await fetch("http://localhost:8080/controllers"); // Talk to C++ server

    // If the C++ server responds, we parse the JSON
    if (!res.ok) {
      throw new Error("Failed to fetch from C++ server");
    }

    const controllers = await res.json();
    return NextResponse.json(controllers);
  } catch (error) {
    console.error("Error contacting CORE server:", error.message);
    return NextResponse.json(
      { error: "Error contacting CORE server." },
      { status: 500 }
    );
  }
}
