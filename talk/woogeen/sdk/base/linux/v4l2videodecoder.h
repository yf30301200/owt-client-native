/*
 *  Copyright (c) 2013 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef WEBRTC_VIDEO_ENGINE_V4L2_DECODER_H_
#define WEBRTC_VIDEO_ENGINE_V4L2_DECODER_H_

#include <vector>

#include "webrtc/modules/video_coding/include/video_codec_interface.h"
#include "webrtc/system_wrappers/include/clock.h"

namespace webrtc{
class V4L2Decoder : public VideoDecoder {
 public:
  V4L2Decoder();
  virtual ~V4L2Decoder() {}

  int32_t InitDecode(const VideoCodec* config,
                     int32_t number_of_cores) override;

  int32_t Decode(const EncodedImage& input,
                 bool missing_frames,
                 const RTPFragmentationHeader* fragmentation,
                 const CodecSpecificInfo* codec_specific_info,
                 int64_t render_time_ms) override;

  int32_t RegisterDecodeCompleteCallback(
      DecodedImageCallback* callback) override;

  int32_t Release() override;

  const char* ImplementationName() const override;

 private:
  VideoCodec config_;
  DecodedImageCallback* decoded_image_callback_;
};

class V4L2H264Decoder : public V4L2Decoder {
 public:
  virtual ~V4L2H264Decoder() {}

  int32_t Decode(const EncodedImage& input,
                 bool missing_frames,
                 const RTPFragmentationHeader* fragmentation,
                 const CodecSpecificInfo* codec_specific_info,
                 int64_t render_time_ms) override;
};

class V4L2NullDecoder : public V4L2Decoder {
 public:
  virtual ~V4L2NullDecoder() {}

  int32_t Decode(const EncodedImage& input,
                 bool missing_frames,
                 const RTPFragmentationHeader* fragmentation,
                 const CodecSpecificInfo* codec_specific_info,
                 int64_t render_time_ms) override {
    return 0;
  }
};
}
#endif  // WEBRTC_VIDEO_ENGINE_TEST_COMMON_FAKE_DECODER_H_
