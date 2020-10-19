#include "CurlWrapper.h"

namespace krul::http::curl {
  CurlWrapper::CurlWrapper() {
    curl_global_init(CURL_GLOBAL_ALL);
  }

  CurlWrapper::~CurlWrapper() {
    curl_global_cleanup();
  }

  CurlWrapper::unique_session_ptr CurlWrapper::createSession() const {
    return {curl_easy_init(), curl_easy_cleanup};
  }
} // namespace krul::http::curl