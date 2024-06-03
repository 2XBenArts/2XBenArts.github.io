#include <iostream>
#include <string>
using namespace web;
using namespace std;
using namespace http::client;

int main() {
  // Create a simple web server that listens on port 8080
  // and responds to GET requests with a simple HTML page.

  // Include the necessary libraries
  #include <cpprest/http_listener.h>
  #include <cpprest/json.h>

  // Create a web server listener
  web::http::experimental::listener listener(L"http://localhost:8080");

  // Handle GET requests
  listener.support(web::http::methods::GET, [](web::http::http_request request) {
    // Create a JSON object to hold the response data
    web::json::value response;
    response["message"] = web::json::value::string("Hello, world!");

    // Send the response
    request.reply(web::http::status_codes::OK, response);
  });

  // Start the web server
  listener.open().wait();

  // Keep the server running until the user presses Enter
  cout << "Press Enter to exit." << endl;
  cin.get();

  // Close the web server
  listener.close().wait();

  return 0;
}