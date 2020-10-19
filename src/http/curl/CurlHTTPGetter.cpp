#include "CurlHTTPGetter.h"

#include <utility>

static size_t writeFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
  data->append(( char* )ptr, size * nmemb);
  return size * nmemb;
}

namespace krul::http::curl {

  CurlHTTPGetter::CurlHTTPGetter() : CurlHTTPGetter("") {
  }

  CurlHTTPGetter::CurlHTTPGetter(std::string base_url) : _base_url {std::move(base_url)} {
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

    auto session = _curl.createSession();
    curl_easy_setopt(session.get(), CURLOPT_URL, full_url.c_str());
    curl_easy_setopt(session.get(), CURLOPT_WRITEFUNCTION, writeFunction);
    curl_easy_setopt(session.get(), CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(session.get(), CURLOPT_FAILONERROR, 1L);

    CURLcode curl_status = curl_easy_perform(session.get());

    curl_easy_getinfo(session.get(), CURLINFO_RESPONSE_CODE, &response_code);

    auto response = std::make_unique<HTTPResponse>(full_url, response_code, response_string);

    if (curl_status != CURLE_OK) throw HTTPException(*response);

    return response;
  }

} // namespace krul::http::curl
