extern "C" {
  #include <AL/al.h> // openal
  #include <AL/alc.h>

  #include <libavcodec/avcodec.h> // ffmpeg
  #include <libavformat/avformat.h>
  #include <libavutil/avutil.h>
}

#include "file.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {
  if (argc != 2) {
    std::cout << "no mp4 file specified or too many arguments" << std::endl;
    return 1;
  }
  std::string video_filename = argv[1];

  // register all compiled muxers, demuxers, and protocols (avformat)
  av_register_all();

  VideoFile f = VideoFile(video_filename);
  f.dump_info();

  std::cout << "----------" << std::endl;
  f.find_surround_sound();
}

