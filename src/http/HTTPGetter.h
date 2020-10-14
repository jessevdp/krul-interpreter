#pragma once

#include <exception>
#include <memory>
#include <string>

namespace krul::http {

  /**
   * Simple data object for HTTP responses.
   */
  class HTTPResponse {
  private:
    std::string _url;
    long _code;
    std::string _body;

  public:
    HTTPResponse(const std::string& url, long response_code, const std::string& response_body);
    std::string url() const;
    long code() const;
    std::string body() const;
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
    long response_code() const noexcept;
    const char* what() const noexcept override;
  };

  /**
   * Interface for HTTP simple HTTP client that can perform GET requests.
   */
  class HTTPGetter {
  public:
    HTTPGetter() = default;
    virtual ~HTTPGetter() noexcept = default;

    /**
     * Configure the base_url. This value will be prepended to future requests urls.
     * @param base_url
     */
    virtual void set_base_url(const std::string& base_url) = 0;

    /**
     * Perform an HTTP GET request to the given URL. If a base_url is configured, it is prepended to the given url.
     * @param url
     * @throws HTTPException
     * @return HTTPResponse
     */
    virtual std::unique_ptr<HTTPResponse> get(const std::string& url) const = 0;
  };

} // namespace krul::http
