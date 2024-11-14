#include "curlHelpers.hpp"

/* Callback function used by libcurl to append
received data into a user-defined buffer */
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/* Callback function used by libcurl to append
recieved sprite data into a ofstream object */
size_t WriteSpriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    std::ofstream* stream = static_cast<std::ofstream*>(userp);
    size_t totalSize = size * nmemb;
    stream->write(static_cast<char*>(contents), totalSize);
    return totalSize;
}