#include "http/HTTPGetter.h"
#include "http/CurlHTTPGetter.h"

#include <iostream>
#include <memory>

using namespace krul::http;

void get(const HTTPGetter& http, const std::string& url) {
  auto response = http.get(url);

  std::cout << "GET " << response->url() << " (" << response->code() << ")" << std::endl;
  std::cout << std::endl;
  std::cout << response->body();
  std::cout << std::endl;
}

int main() {
  std::unique_ptr<HTTPGetter> http = std::make_unique<CurlHTTPGetter>("https://www.swiftcoder.nl/cpp1/");
  get(*http, "start.txt");
  get(*http, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.txt");
}
