#include "http.h"

#include <utility>

namespace krul::http {

  HTTPResponse::HTTPResponse(std::string url, long response_code, std::string response_body)
      : _url {std::move(url)}, _code {response_code}, _body {std::move(response_body)} {
  }

  std::string HTTPResponse::url() const {
    return _url;
  }

  long HTTPResponse::code() const {
    return _code;
  }

  std::string HTTPResponse::body() const {
    return _body;
  }

} // namespace krul::http
