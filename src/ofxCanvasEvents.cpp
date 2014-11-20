// =============================================================================
//
// Copyright (c) 2014 Brannon Dorsey <http://brannondorsey.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#include "ofxCanvasEvents.h"

namespace ofx {


CanvasEvents::CanvasEvents()
{
}


CanvasEvents::~CanvasEvents()
{
}


void CanvasEvents::registerMethods(HTTP::BasicJSONRPCServer::SharedPtr server)
{
    server->registerMethod("onPointerEvent",
                           "Process HTML5 canvas pointer events.",
                           this,
                           &CanvasEvents::onPointerEvent);

    server->registerMethod("onKeyboardEvent",
                           "Process HTML5 canvas keyboard events.",
                           this,
                           &CanvasEvents::onKeyboardEvent);

    server->getWebSocketRoute()->registerWebSocketEvents(this);

}


void CanvasEvents::unregisterMethods(HTTP::BasicJSONRPCServer::SharedPtr server)
{
    server->getWebSocketRoute()->unregisterWebSocketEvents(this);
    server->unregisterMethod("onKeyboardEvent");
    server->unregisterMethod("onPointerEvent");
}


bool CanvasEvents::onWebSocketOpenEvent(HTTP::WebSocketOpenEventArgs& evt)
{
    return false;  // We did not attend to this event, so pass it along.
}


bool CanvasEvents::onWebSocketCloseEvent(HTTP::WebSocketCloseEventArgs& evt)
{
    return false;  // We did not attend to this event, so pass it along.
}


bool CanvasEvents::onWebSocketFrameReceivedEvent(HTTP::WebSocketFrameEventArgs& evt)
{
    return false;
}


bool CanvasEvents::onWebSocketFrameSentEvent(HTTP::WebSocketFrameEventArgs& evt)
{
    return false;  // We did not attend to this event, so pass it along.
}


bool CanvasEvents::onWebSocketErrorEvent(HTTP::WebSocketErrorEventArgs& evt)
{
    return false;  // We did not attend to this event, so pass it along.
}


void CanvasEvents::onPointerEvent(JSONRPC::MethodArgs& args)
{
    PointerEvent event = PointerEvent::fromJSON(args.params);
    std::cout << args.params.toStyledString() << endl;
    cout << event.toString() << endl;
}

void CanvasEvents::onKeyboardEvent(JSONRPC::MethodArgs& args)
{
    cout << args.toString() << endl;
}


};  // namespace ofx
