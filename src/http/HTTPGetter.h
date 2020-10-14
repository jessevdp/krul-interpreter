#pragma once

#include <memory>
#include <string>
#include <exception>

namespace krul::http {

  /**
   * Simple data object for HTTP responses.
   */
  class HTTPResponse {
  private:
    std::string _url;
    long _response_code;
    std::string _response_body;

  public:
    HTTPResponse(const std::string& url, long response_code, const std::string& response_body);
    std::string url();
    long response_code();
    std::string response_body();
  };

  /**
   * Simple custom exception to indicate errors in HTTP request.
   */
  class HTTPException : public std::exception {
  private:
    std::string _message;
    long _response_code;

  public:
    HTTPException(long response_code, std::string message);
    const char* what() const noexcept override;
  };

  /**
   * Interface for HTTP simple HTTP client that can perform GET requests.
   */
  class HTTPGetter {
  public:
    HTTPGetter() = default;
    virtual ~HTTPGetter() = default;

    /**
     * Configure the base_url. This value will be prepended to future requests urls.
     * @param base_url
     */
    virtual void set_base_url(std::string base_url) = 0;

    /**
     * Perform an HTTP GET request to the given URL. If a base_url is configured, it is prepended to the given url.
     * @param url
     * @throws HTTPException
     * @return HTTPResponse
     */
    virtual std::unique_ptr<HTTPResponse> get(std::string url) const = 0;
  };
}
