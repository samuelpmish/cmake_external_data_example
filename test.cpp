#include <iostream>
#include <filesystem>

int main(int argc, char ** argv) {
  std::cout << "checking if file " << argv[1] << " has the appropriate size ... ";
  auto size = std::filesystem::file_size(argv[1]);
  if (size != 64000) {
    std::cout << "test failed" << std::endl;
  } else {
    std::cout << "test passed" << std::endl;
  }
}
