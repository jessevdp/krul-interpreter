#include "HTTPGetter.h"

namespace krul::http {

  HTTPResponse::HTTPResponse(const std::string& url, long response_code, const std::string& response_body)
      : _url {url}, _code {response_code}, _body {response_body} {
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
