# How to create a `shared library` write by C\C++ with CMake

## Thư viện chia sẻ (Shared Library) trong C/C++ và CMake

### Thư viện chia sẻ là gì?

Thư viện chia sẻ ([shared library](https://manthang.wordpress.com/2010/12/04/quan-ly-cac-shared-library-trong-linux/)), còn được gọi là dynamic library, là **một tập tin chứa các hàm và biến** có thể được **nhiều chương trình khác nhau sử dụng đồng thời**.

**Ưu điểm:**

* **Tiết kiệm bộ nhớ:** Nhiều chương trình có thể cùng sử dụng một bản sao duy nhất của thư viện.
* **Cập nhật dễ dàng:** Chỉ cần cập nhật thư viện một lần, tất cả các chương trình sử dụng nó sẽ được hưởng lợi.
* **Tái sử dụng cao:** Các hàm trong thư viện có thể được sử dụng bởi nhiều dự án khác nhau.

### Tạo thư viện chia sẻ bằng C/C++ và CMake

**CMake** là một công cụ tự động hóa quá trình xây dựng phần mềm, rất hữu ích trong việc tạo các thư viện chia sẻ. Dưới đây là các bước cơ bản:

1. **Tạo cấu trúc dự án:**
   * Tạo một thư mục mới cho dự án của bạn.
   * Tạo các file nguồn (.cpp) và file header (.h) chứa các hàm và biến bạn muốn đưa vào thư viện.
   * Tạo file `CMakeLists.txt` tại gốc thư mục dự án.

2. **Viết file CMakeLists.txt:**

   * **Chỉ định phiên bản CMake tối thiểu:**

     ```cmake
     cmake_minimum_required(VERSION 3.10)
     ```

   * **Đặt tên cho dự án:**

     ```cmake
     project(my_shared_library)
     ```

   * **Tạo thư viện:**

     ```cmake
     add_library(my_library SHARED src/my_function.cpp)
     ```

     * `my_library`: Tên thư viện
     * `SHARED`: Chỉ định tạo thư viện chia sẻ (here is the main difference with static library)
     * `src/my_function.cpp`: File nguồn chứa các hàm của thư viện

   * **Ví dụ CMakeLists.txt hoàn chỉnh:**

    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(my_shared_library)

    add_library(my_library SHARED src/my_function.cpp)
    ```

3. **Xây dựng thư viện:**

   * Mở terminal, điều hướng đến thư mục dự án.
   * Chạy lệnh `cmake .` để tạo các file cấu hình.
   * Chạy lệnh `make` để xây dựng thư viện.

4. **Sử dụng thư viện:**

   * **Liên kết thư viện:** Trong dự án sử dụng thư viện, bạn cần **liên kết thư viện này vào quá trình biên dịch**.
   * **Tìm đường dẫn:** CMake sẽ tự động tìm đường dẫn đến thư viện nếu cấu hình đúng.
   * **Sử dụng hàm:** Include file header của thư viện và gọi các hàm như bình thường.

### Điểm cần lưu ý

* **Platform-specific:** Cách tạo và sử dụng thư viện chia sẻ có thể khác nhau giữa các hệ điều hành (Windows, Linux, macOS).
* **Tên thư viện:** Tên thư viện có thể ảnh hưởng đến cách liên kết và tìm kiếm thư viện.
* **Đường dẫn:** Đảm bảo đường dẫn đến thư viện được cấu hình đúng trong dự án sử dụng.
* **Phụ thuộc:** Nếu thư viện của bạn phụ thuộc vào các thư viện khác, bạn cần cấu hình CMake để liên kết các thư viện đó.
* **Versioning:** Quản lý phiên bản của thư viện để tránh xung đột khi sử dụng nhiều phiên bản khác nhau.

**Tài liệu tham khảo:**

* **CMake documentation:** [https://cmake.org/documentation/](https://cmake.org/documentation/)
* **Viblo:** [https://viblo.asia/p/cmake-add-thu-vien-dinh-nghia-thu-vien-OeVKBq6E5kW](https://viblo.asia/p/cmake-add-thu-vien-dinh-nghia-thu-vien-OeVKBq6E5kW)

**Lưu ý:** Đây là một giới thiệu ngắn gọn. Để hiểu sâu hơn và áp dụng vào các dự án thực tế, bạn nên tham khảo thêm các tài liệu và ví dụ cụ thể.

---

Here is the example:

Make the Student project become a shared lib (but install it in .../libs - not for system lib for security and sustainable)

**Step 1**. Init the project with code:

```bash
cp -r ../2*/src/ ./
rm ./src/mainapp.cpp # as has no function when build the app
cp -r ../2*/include/ ./
cp ../2*/CMakeLists.txt ./
```

**Step 2**. Note in `CMakeLists.txt`:

Here is 3 new command for it:

```bash
add_library(testStudent SHARED ${SOURCES})
# Creates a shared library named "testStudent" using the same source files.

set(CMAKE_BUILD_TYPE Release)
# Sets the build type to "Release" for optimized builds.

install(TARGETS testStudent DESTINATION ./usr/lib)
# Installs the "testStudent" target (both executable and shared library) to the specified destination.
```

Here (the `testStudent` program is a dynamic program $\to$ means that it contains the link to libs its use - not code of libs $\to$ save memory on disk and memory on RAM) set `SHARED` in command `add_library`.

The `set` & `install` command are set builder, what name to call program after build & where it be save on disk.

In this example, I save it in `./usr/lib` - not `/usr/lib` or `/lib`, ... as this only a demo.

**Step 3**. Make in `build` folder:

```bash
# stay in build folder
pwd && cmake .. && make
# the libtestStudent.so will be create in build - current path
# and this is the target file to create
```

**Step 4**. See the result:

```bash
# in path project_name/build/
ldd libtestStudent.so 
    linux-vdso.so.1 (0x00007a188dd5f000)
    libstdc++.so.6 => /usr/lib/libstdc++.so.6 (0x00007a188da00000)
    libm.so.6 => /usr/lib/libm.so.6 (0x00007a188d911000)
    libgcc_s.so.1 => /usr/lib/libgcc_s.so.1 (0x00007a188dd01000)
    libc.so.6 => /usr/lib/libc.so.6 (0x00007a188d720000)
    /usr/lib64/ld-linux-x86-64.so.2 (0x00007a188dd61000)
```
