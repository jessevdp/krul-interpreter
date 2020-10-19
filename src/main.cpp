#include "http/curl/CurlHTTPGetter.h"
#include "http/http.h"

#include <iostream>
#include <memory>

using namespace krul::http;

void log_response(const HTTPResponse& response, bool show_body = true) {
  std::cout << "GET " << response.url() << " (" << response.code() << ")" << std::endl;
  std::cout << std::endl;
  if (show_body) {
    std::cout << response.body();
    std::cout << std::endl;
  }
}

void get(const HTTPGetter& http, const std::string& url) {
  try {
    auto response = http.get(url);
    log_response(*response);
  } catch (const HTTPException& httpException) {
    std::cout << "ERROR" << std::endl;
    log_response(httpException, false);
  }
}

int main() {
  std::unique_ptr<HTTPGetter> http = std::make_unique<CurlHTTPGetter>("https://www.swiftcoder.nl/cpp1/");
  get(*http, "bogus.txt");
  get(*http, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.txt");
}
