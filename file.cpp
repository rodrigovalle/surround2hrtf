#include "file.hpp"
#include "util.hpp"
#include <stdexcept>
#include <string>

#include <iostream>

/* use libav to open a video file */
VideoFile::VideoFile(std::string& filepath) {
  int err;
  ctx = nullptr;
  this->filepath = filepath;
  
  if ((err = avformat_open_input(&ctx, filepath.c_str(), nullptr, nullptr)) != 0) {
    throw std::runtime_error(error_string(err));
  }

  if ((err = avformat_find_stream_info(ctx, nullptr)) < 0) {
    throw std::runtime_error(error_string(err));
  }
}


VideoFile::~VideoFile() {
  avformat_close_input(&ctx);
  avformat_free_context(ctx);
}


void VideoFile::dump_info() {
  av_dump_format(ctx, 0, filepath.c_str(), 0);
}

AVCodecContext* VideoFile::find_surround_sound() {
  for (int i = 0; i < ctx->nb_streams; i++) {
    AVCodecParameters* codec = ctx->streams[i]->codecpar;

    if (codec->codec_type == AVMEDIA_TYPE_AUDIO) {
      switch (codec->channel_layout) {
        case AV_CH_LAYOUT_5POINT1_BACK: // 5.1 with rear speakers
          break;
        case AV_CH_LAYOUT_5POINT1: // 5.1 with side speakers
          std::cout << "found em" << std::endl;
          break;
      }
    }
  }
}
