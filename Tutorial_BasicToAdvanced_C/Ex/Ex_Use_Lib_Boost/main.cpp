#include <iostream>
#include <boost/filesystem.hpp>
// boost currently does not install in the system, 
// so we need to use the full path to the include
// or simple: install it with the command:
// sudo apt-get install libboost-all-dev
// sudo pacman -S boost
// sudo dnf install boost-devel
// sudo zypper install boost-devel
// sudo emerge dev-libs/boost
// sudo pkg_add boost
// sudo pkg install boost
// sudo port install boost
// sudo brew install boost
// ... or use the package manager of your system
// now it done

// you can complied with the command:
// // g++ main.cpp -o main -lboost_filesystem -lboost_system
// g++ main.cpp -o main -L/usr/local/lib -lboost_filesystem

int main() {
    boost::filesystem::path path("main.cpp");
  
    if (boost::filesystem::exists(path)) {
        std::cout << "Path: " << path << " exists!" << std::endl;
      
        if (boost::filesystem::is_directory(path)) {
            std::cout << "Path: " << path << " is a directory." << std::endl;
        } else if (boost::filesystem::is_regular_file(path)) {
            std::cout << "Path: " << path << " is a regular file." << std::endl;
        }
    } else {
        std::cout << "Path: " << path << " does not exist!" << std::endl;
    }

    return 0;
}