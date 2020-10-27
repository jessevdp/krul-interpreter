#pragma once

#include <curl/curl.h>
#include <memory>

namespace krul::http::curl {

  class CurlWrapper {
  public:
    CurlWrapper();
    ~CurlWrapper();

    [[nodiscard]] std::unique_ptr<CURL, void (*)(CURL*)> createSession() const;

    // Remove copy and move
    CurlWrapper(const CurlWrapper&) = delete;
    CurlWrapper& operator=(const CurlWrapper&) = delete;
    CurlWrapper(const CurlWrapper&&) = delete;
    CurlWrapper& operator=(const CurlWrapper&&) = delete;
  };
} // namespace krul::http::curl
