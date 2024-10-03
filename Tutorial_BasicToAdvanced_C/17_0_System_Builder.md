# System Builder

Usually start with **cmake**.
Should use **meson** now.

## So sánh Ninja và Make: Hai công cụ xây dựng khác biệt

**Ninja** và **Make** là hai công cụ xây dựng phổ biến được sử dụng để **tự động hóa quá trình biên dịch** và **liên kết các dự án phần mềm**. Mặc dù cùng phục vụ mục đích chung, nhưng hai công cụ này có những đặc điểm và cách tiếp cận khác nhau.

### Ninja: Tốc độ và hiệu suất

* **Thiết kế tối ưu cho tốc độ:** Ninja được thiết kế đặc biệt để tối ưu hóa tốc độ xây dựng, đặc biệt là trong các dự án lớn và phức tạp. Nó sử dụng một đồ thị acyclic để biểu diễn các phụ thuộc giữa các file và thực hiện các phép tính tối ưu hóa để xác định những file cần được biên dịch lại.
* **Đơn giản và hiệu quả:** Cú pháp của Ninja khá đơn giản, tập trung vào việc mô tả các phụ thuộc giữa các file. Điều này giúp cho việc viết các file `ninja` trở nên dễ dàng và ít lỗi hơn.
* **Tích hợp tốt với các công cụ khác:** Ninja có thể dễ dàng tích hợp với các công cụ xây dựng khác như CMake, Meson, và nhiều công cụ khác.

### Make: Linh hoạt và tùy biến

* **Linh hoạt:** Make cung cấp một ngôn ngữ kịch bản mạnh mẽ, cho phép bạn thực hiện các tác vụ phức tạp và tùy biến quy trình xây dựng theo nhiều cách khác nhau.
* **Cổ điển và phổ biến:** Make là một công cụ rất lâu đời và được sử dụng rộng rãi, có rất nhiều tài liệu và cộng đồng hỗ trợ.
* **Cú pháp phức tạp:** Cú pháp của Make có thể khá phức tạp và khó đọc, đặc biệt đối với những người mới bắt đầu.

### Bảng so sánh chi tiết

| Tính năng | Ninja | Make |
|---|---|---|
| **Tốc độ** | Rất nhanh | Tương đối chậm hơn |
| **Đơn giản** | Rất đơn giản | Phức tạp hơn |
| **Linh hoạt** | Tương đối thấp | Rất cao |
| **Cú pháp** | Đơn giản, dễ đọc | Phức tạp, khó đọc hơn |
| **Tích hợp** | Tốt với các công cụ khác | Tốt, nhưng có thể cần thêm cấu hình |

### Khi nào nên sử dụng công cụ nào?

* **Ninja:**
    * Các dự án lớn và phức tạp, yêu cầu thời gian xây dựng nhanh.
    * Các dự án sử dụng các công cụ xây dựng khác như CMake, Meson.
    * Các dự án cần một công cụ xây dựng đơn giản và hiệu quả.
* **Make:**
    * Các dự án nhỏ và vừa.
    * Các dự án yêu cầu một mức độ tùy biến cao.
    * Các dự án đã sử dụng Make từ trước và có nhiều quy trình tùy chỉnh.

## Compare 3 tools: cmake, ninja, meson

Table 1: 

| Tính năng | Ninja | Make | Meson |
|---|---|---|---|
| **Mục tiêu** | Tối ưu tốc độ, đơn giản | Linh hoạt, tùy biến | Hiện đại, mạnh mẽ, dễ sử dụng |
| **Cú pháp** | Đơn giản, dễ đọc | Phức tạp | Đơn giản, rõ ràng, hướng đối tượng |
| **Linh hoạt** | Trung bình | Cao | Rất cao |
| **Tích hợp** | Tốt với các công cụ khác | Tốt, nhưng cần cấu hình | Rất tốt, hỗ trợ nhiều nền tảng và ngôn ngữ |
| **Ngôn ngữ cấu hình** | Ninja file (JSON-like) | Makefile (Ngôn ngữ kịch bản) | Meson (Ngôn ngữ cấu hình mạnh mẽ) |
| **Tính năng nổi bật** | Tốc độ, đơn giản | Linh hoạt, tùy biến | Hiện đại, mạnh mẽ, tự động hóa |
| **Cộng đồng** | Đang phát triển nhanh | Lớn, lâu đời | Đang phát triển mạnh |
| **Sử dụng** | Thường được sử dụng làm backend cho các công cụ xây dựng khác | Được sử dụng rộng rãi trong nhiều dự án | Được sử dụng ngày càng phổ biến, đặc biệt trong các dự án lớn |

Table 2:

| Công cụ | File cấu hình | Ngôn ngữ cấu hình | Tính năng nổi bật |
|---|---|---|---|
| Make | Makefile | Ngôn ngữ kịch bản | Linh hoạt, tùy biến cao |
| Ninja | build.ninja | JSON-like | Tốc độ, đơn giản |
| Meson | meson.build | Ngôn ngữ cấu hình mạnh mẽ | Hiện đại, dễ sử dụng, tích hợp tốt |

### Giải thích thêm về Meson

* **Meson** là một công cụ xây dựng hiện đại, được thiết kế để thay thế cho Make. Nó cung cấp một ngôn ngữ cấu hình mạnh mẽ và dễ đọc, cho phép bạn mô tả các dự án một cách rõ ràng và ngắn gọn.
* **Tính năng nổi bật:**
    * **Tự động hóa:** Meson có thể tự động phát hiện các thay đổi trong code và chỉ biên dịch những phần cần thiết, giúp tiết kiệm thời gian.
    * **Hỗ trợ nhiều nền tảng:** Meson hỗ trợ xây dựng trên nhiều nền tảng khác nhau, bao gồm Linux, Windows, macOS và các hệ thống nhúng.
    * **Hỗ trợ nhiều ngôn ngữ:** Meson hỗ trợ nhiều ngôn ngữ lập trình khác nhau, bao gồm C/C++, Rust, Python, và nhiều ngôn ngữ khác.
    * **Tích hợp với các công cụ khác:** Meson có thể dễ dàng tích hợp với các công cụ khác như Ninja, CMake, và các công cụ quản lý gói.

### Khi nào nên chọn công cụ nào?

* **Ninja:** Khi bạn cần một công cụ xây dựng nhanh và đơn giản, đặc biệt là cho các dự án lớn và phức tạp.
* **Make:** Khi bạn cần một công cụ linh hoạt và tùy biến cao, và bạn đã quen với cú pháp Makefile.
* **Meson:** Khi bạn muốn một công cụ hiện đại, mạnh mẽ, dễ sử dụng và có khả năng tự động hóa cao.

## CMake basic use

More detail in [here](../Simple_CAndCMake_Example/README.md) or [here](../Tutorial_CMake/README.md)

Eg about `CMakeLists.txt`:

```cpp
cmake_minimum_required(VERSION 3.0)

project(MyProject)

set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(SOURCES "${SRC_DIR}/main.cpp" "${SRC_DIR}/file1.cpp" "${SRC_DIR}/file2.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
```

```bash
mkdir build
cd build
cmake ..
make
```

...continue...

## Ninja basic use

...continue...

## Meson basic use

...continue...
