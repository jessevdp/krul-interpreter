#include "http.h"

#include <utility>

namespace krul::http {

  HTTPException::HTTPException(const std::string& url, long response_code, const std::string& response_body,
                               std::string message)
      : HTTPResponse(url, response_code, response_body), _message {std::move(message)} {
  }

  HTTPException::HTTPException(const HTTPResponse& response, std::string message)
      : HTTPResponse(response), _message {std::move(message)} {
  }

  const char* HTTPException::what() const noexcept {
    return _message.c_str();
  }

} // namespace krul::http