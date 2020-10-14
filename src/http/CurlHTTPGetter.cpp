#include "CurlHTTPGetter.h"

#include <utility>

static size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
  data->append(( char* )ptr, size * nmemb);
  return size * nmemb;
}

namespace krul::http {

  CurlHTTPGetter::CurlHTTPGetter() : CurlHTTPGetter("") {
  }

  CurlHTTPGetter::CurlHTTPGetter(std::string base_url) : _base_url {std::move(base_url)} {
    curl_global_init(CURL_GLOBAL_ALL);
  }

  CurlHTTPGetter::~CurlHTTPGetter() noexcept {
    curl_global_cleanup();
  }

  void CurlHTTPGetter::set_base_url(const std::string& base_url) {
    _base_url = base_url;
  }

  std::string CurlHTTPGetter::prepend_url(const std::string& url) const {
    return _base_url + url;
  }

  std::unique_ptr<HTTPResponse> CurlHTTPGetter::get(const std::string& url) const {
    std::string response_string;
    long response_code;
    auto full_url = prepend_url(url);

    std::unique_ptr<CURL, void(*)(CURL*)> curl {curl_easy_init(), curl_easy_cleanup};
    curl_easy_setopt(curl.get(), CURLOPT_URL, full_url.c_str());
    curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &response_string);

    curl_easy_perform(curl.get());

    curl_easy_getinfo(curl.get(), CURLINFO_RESPONSE_CODE, &response_code);

    return std::make_unique<HTTPResponse>(full_url, response_code, response_string);
  }

} // namespace krul::http
