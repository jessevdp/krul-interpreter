#pragma once

#include "CurlWrapper.h"
#include "http/http.h"

#include <curl/curl.h>
#include <memory>
#include <string>

namespace krul::http::curl {

  class CurlHTTPGetter : public HTTPGetter {
  private:
    std::string _base_url;
    CurlWrapper _curl;

  public:
    /**
     * Create an CurlHTTPGetter instance without an empty base_url.
     */
    CurlHTTPGetter();

    /**
     * Create an CurlHTTPGetter instance using the given base_url.
     * @param base_url
     */
    explicit CurlHTTPGetter(std::string base_url);

    void set_base_url(const std::string& base_url) override;
    [[nodiscard]] std::unique_ptr<HTTPResponse> get(const std::string& url) const override;

  private:
    [[nodiscard]] std::string prepend_url(const std::string& url) const;
  };

} // namespace krul::http::curl
