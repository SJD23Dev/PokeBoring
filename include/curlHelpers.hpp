#pragma once

#include <string>
#include <fstream>
#include <cstdlib>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
size_t WriteSpriteCallback(void* contents, size_t size, size_t nmemb, void* userp);