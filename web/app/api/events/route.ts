import { NextResponse } from "next/server";

let streamController: ReadableStreamDefaultController | null = null;

export async function GET() {
  const stream = new ReadableStream({
    start(controller) {
      streamController = controller;
    },
    cancel() {
      console.log("Stream cancelled by client.");
      streamController = null;
    },
  });

  return new NextResponse(stream, {
    headers: {
      "Content-Type": "text/event-stream",
      "Cache-Control": "no-cache",
      Connection: "keep-alive",
    },
  });
}

export async function POST(req: Request) {
  console.log("Received trigger from CORE.");

  if (streamController) {
    const message = {
      message: "controllers_updated",
      time: new Date().toISOString(),
    };
    streamController.enqueue(`data: ${JSON.stringify(message)}\n\n`);
  } else {
    console.log("No active stream connection to send message to.");
  }

  return NextResponse.json({ status: "ok" });
}
