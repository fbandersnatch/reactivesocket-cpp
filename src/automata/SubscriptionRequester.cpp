// Copyright 2004-present Facebook. All Rights Reserved.

#include "src/automata/SubscriptionRequester.h"

namespace reactivesocket {

void SubscriptionRequester::sendRequestFrame(
    FrameFlags flags,
    size_t initialN,
    Payload&& request) {
  Frame_REQUEST_SUB frame(
      streamId_, flags, static_cast<uint32_t>(initialN), std::move(request));
  connection_->outputFrameOrEnqueue(frame.serializeOut());
}
}
