#include "KrulProgram.h"
#include "http/curl/CurlHTTPGetter.h"
#include "http/http.h"

#include "interpreter/exception/InterpretingException.h"
#include "parser/exception/ParsingException.h"

#include <iostream>
#include <memory>

using namespace krul;
using namespace krul::http;
using namespace krul::http::curl;

using namespace krul::parser::exception;
using namespace krul::interpreter::exception;

void log_response(const HTTPResponse& response, bool show_body = false) {
  std::cout << "GET " << response.url() << " (" << response.code() << ")" << std::endl;
  if (show_body) {
    std::cout << std::endl;
    std::cout << response.body();
  }
}

int main() {
  std::unique_ptr<HTTPGetter> http = std::make_unique<CurlHTTPGetter>("https://www.swiftcoder.nl/cpp1/");

  try {
    std::string message;
    std::string filename {"start.txt"};
    bool found_end = false;

    while (!found_end) {
      auto response = http->get(filename);
      log_response(*response);

      std::cout << "Parsing '" << response->url() << "'..." << std::endl;
      auto program = std::make_unique<KrulProgram>(response->body());
      std::cout << "Parsing complete" << std::endl;

      std::cout << "Executing '" << response->url() << "'..." << std::endl;
      auto result = program->execute();
      std::cout << "Executing complete" << std::endl;

      found_end = result.is_end_of_search();

      if (found_end) message = result.return_value();
      else {
        filename = result.return_value();
        std::cout << "Result: '" << filename << "'" << std::endl;
      }

      std::cout << std::endl;
    }

    std::cout << "Found the hidden message! It reads:" << std::endl;
    std::cout << "\"" << message << "\"" << std::endl;

    return 0;
  } catch (const HTTPException& http_exception) {
    log_response(http_exception, true);
  } catch (const InterpretingException& e) {
    std::cout << e.what() << std::endl;
  } catch (const ParsingException& e) {
    std::cout << e.what() << std::endl;
  }

  return 1;
}