#ifndef _FILE_HPP
#define _FILE_HPP

#include <string>

extern "C" {
  #include <libavformat/avformat.h>
}

class VideoFile {
  private:
    AVFormatContext *ctx;
    std::string filepath;

  public:
    VideoFile() = delete;
    VideoFile(std::string& filepath);
    ~VideoFile();

    void dump_info();
    AVCodecContext* find_surround_sound();
};

#endif
