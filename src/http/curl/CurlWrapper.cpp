#include "CurlWrapper.h"

namespace krul::http::curl {
  CurlWrapper::CurlWrapper() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
  }

  CurlWrapper::~CurlWrapper() {
    curl_global_cleanup();
  }

  std::unique_ptr<CURL, void (*)(CURL*)> CurlWrapper::createSession() const {
    return {curl_easy_init(), curl_easy_cleanup};
  }
} // namespace krul::http::curl