To install **DCMTK** on Arch Linux and place it in `/Data/Libs/CPP_ExtendLibs`, follow these steps:

### 1. Install Dependencies
First, install the required dependencies using `pacman`:
```bash
sudo pacman -S cmake gcc libpng libxml2 zlib
```

### 2. Clone and Build DCMTK
Clone the DCMTK repository:
```bash
git clone https://github.com/DCMTK/dcmtk.git
cd dcmtk
```

Create a build directory:
```bash
mkdir build && cd build
```

Run `CMake` with the custom install prefix:
```bash
cmake -DCMAKE_INSTALL_PREFIX=/Data/Libs/CPP_ExtendLibs ..
# -- Build files have been written to: /home/harito/Clone/dcmtk/build
make
# ...
# [100%] Building CXX object dcmapps/apps/CMakeFiles/dcm2img.dir/dcm2img.cc.o
# [100%] Linking CXX executable ../../bin/dcm2img
# [100%] Built target dcm2img
sudo make install
```

### 3. Verify Installation
To ensure the library is properly installed, run:
```bash
ls /Data/Libs/CPP_ExtendLibs
```

### 4. Example C++ Code
Here's an example of a simple program that links against DCMTK:
```cpp
// dicom_reader.cpp
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <iostream>

int main() {
    // Load DICOM file
    const char *filename = "example.dcm";
    DcmFileFormat fileFormat;
    OFCondition status = fileFormat.loadFile(filename);
    
    if (status.good()) {
        // Print Metadata
        std::cout << "DICOM Metadata:" << std::endl;
        fileFormat.getDataset()->print(std::cout);
        
        // Load Image
        DicomImage image(filename);
        if (image.getStatus() == EIS_Normal) {
            // Check if the image is monochrome or color
            if (image.isMonochrome()) {
                std::cout << "Monochrome image loaded" << std::endl;
            } else {
                std::cout << "Color image loaded" << std::endl;
            }
            // Display image information
            std::cout << "Image width: " << image.getWidth() << std::endl;
            std::cout << "Image height: " << image.getHeight() << std::endl;

            // Convert to grayscale for simplicity (can be extended for color images)
            image.writeBMP("output.bmp", 0, 0);
            std::cout << "Image written to output.bmp" << std::endl;
        } else {
            std::cerr << "Error: Cannot load image!" << std::endl;
        }
    } else {
        std::cerr << "Error: Cannot read DICOM file!" << std::endl;
    }

    return 0;
}
```

### 5. Compile Example with Custom Path
Compile the code with the installed DCMTK:
```bash
g++ -o dicom_reader dicom_reader.cpp -I/Data/Libs/CPP_ExtendLibs/include -L/Data/Libs/CPP_ExtendLibs/lib -ldcmdata -ldcmimgle -lofstd
```

This example demonstrates setting up and compiling a program that uses DCMTK, pointing CMake to the installation path `/Data/Libs/CPP_ExtendLibs`.

P/s: Install log4cplus first

#### Step 1: Ensure **log4cplus** is Installed
First, make sure that **log4cplus** is installed on your system. If it’s not installed, you can usually install it via your package manager or by compiling from source. For Arch Linux, you can install it using:

```bash
sudo pacman -S log4cplus
```

#### Step 2: Locate the Library
After installation, confirm the location of the **log4cplus** library. It is typically found in `/usr/lib` or `/usr/local/lib`. You can check for it using:

```bash
find /usr/lib /usr/local/lib -name "liblog4cplus.*"
```

#### Step 3: Update the Compile Command
Once you confirm the installation and location, ensure your compile command includes the correct library path. If it's in a non-standard location, you might need to add that path to your compilation command:

```bash
g++ -o dicom_reader dicom_reader.cpp -I/Data/Libs/CPP_ExtendLibs/include -L/Data/Libs/CPP_ExtendLibs/lib -L/usr/local/lib -ldcmdata -ldcmimgle -lofstd -llog4cplus
```
*Replace `/usr/local/lib` with the path where **log4cplus** is located if it differs.*

#### Step 4: Check `PKG_CONFIG_PATH`
If you are using **pkg-config** to manage library paths, ensure that **PKG_CONFIG_PATH** includes the path to **log4cplus**:

```bash
export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
```

#### Step 5: Update CMakeLists.txt
If you also want to resolve the issue in your **CMakeLists.txt**, you can add a check to find **log4cplus**:

```cmake
find_package(log4cplus REQUIRED)

include_directories(${log4cplus_INCLUDE_DIRS})
target_link_libraries(dicom_reader dcmdata dcmimgle ofstd ${log4cplus_LIBRARIES})
```

#### Step 6: Recompile
Try recompiling your program with the updated commands, both for **g++** and **CMake**. If you continue to have issues, ensure that your library paths are correctly set in your environment.

### 6. Compile Example with CMake

To use **CMake** to build your project with DCMTK installed in `/Data/Libs/CPP_ExtendLibs`, follow these steps:

#### 1. Create a `CMakeLists.txt` file:
```cmake
cmake_minimum_required(VERSION 3.10)
project(DICOMExample)

# Add the path to DCMTK libraries and headers
set(DCMTK_DIR /Data/Libs/CPP_ExtendLibs)

include_directories(${DCMTK_DIR}/include)
link_directories(${DCMTK_DIR}/lib)

add_executable(dicom_example example.cpp)

# Link DCMTK libraries
target_link_libraries(dicom_example dcmdata dcmimgle)
```

#### 2. Build the Project:
```bash
mkdir build
cd build
cmake ..
make
```

This setup allows CMake to use the DCMTK libraries installed at your custom path.