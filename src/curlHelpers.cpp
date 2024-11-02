#include <curlHelpers.hpp>

/* Callback function used by libcurl to append
received data into a user-defined buffer */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}