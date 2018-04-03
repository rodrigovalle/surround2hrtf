#include "util.hpp"

extern "C" {
  #include <libavutil/avutil.h>
}

std::string error_string(int err) {
  char errbuf[128];
  const char *errbuf_ptr = errbuf;

  if (av_strerror(err, errbuf, sizeof(errbuf)) < 0) {
    errbuf_ptr = strerror(AVUNERROR(err));
  }

  return errbuf_ptr;
}
