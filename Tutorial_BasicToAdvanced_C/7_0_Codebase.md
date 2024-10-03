# Codebase

## Main idea

* Namespaces
* Include Guards
* Header and Source Files

## Namespaces (Không gian tên)

* **Là gì:** Namespace là một cách để tổ chức code, **tránh xung đột tên** giữa các biến, hàm, lớp... trong các đoạn code khác nhau.
* **Tại sao cần:** Khi dự án lớn lên, việc quản lý các tên biến, hàm trở nên phức tạp. Namespace giúp chúng ta tạo ra các vùng chứa riêng biệt cho các thực thể này.
* **Ví dụ:**

  ```c++
  namespace MyNamespace {
      int x = 10;
      void myFunction() {
          // ...
      }
  }
  ```

  Ở đây, `x` và `myFunction` thuộc về namespace `MyNamespace`.

## Include Guards (Bảo vệ bao gồm)

* **Là gì:** Include guard là một cơ chế để **ngăn một file header bị include nhiều lần trong một file source**.
* **Tại sao cần:** Nếu một file header bị include nhiều lần, các khai báo trong đó sẽ bị lặp lại, gây ra **lỗi biên dịch**.
* **Cách hoạt động:** Sử dụng các macro để kiểm tra xem một file header đã được include chưa. Nếu chưa, các khai báo trong file sẽ được xử lý.
* **Ví dụ:**
  
  ```c++
  // file .h
  #ifndef MYHEADER_H
  #define MYHEADER_H

  // Nội dung của file header

  #endif // MYHEADER_H
  ```

## Header và Source Files (File header và file nguồn)

* **Header file (.h):** Chứa các **khai báo của lớp, hàm, cấu trúc**, v.v... mà các file khác có thể sử dụng.
* **Source file (.cpp):** Chứa **định nghĩa của các hàm, biến** được **khai báo trong header file**.
* **Tại sao tách biệt:**
  * **Tái sử dụng code:** Các header file có thể được include vào nhiều file source khác nhau.
  * **Tổ chức code:** Tách riêng phần khai báo và phần định nghĩa giúp code dễ đọc, dễ bảo trì.
  * **Tăng tốc biên dịch:** Khi thay đổi một header file, chỉ cần biên dịch lại các file source liên quan, thay vì toàn bộ dự án.

**Mối quan hệ giữa các khái niệm:**

* **Namespace và header:** Chúng ta có thể đặt các khai báo trong một namespace bên trong một header file.
* **Include guard và header:** Include guard được đặt ở đầu mỗi header file để ngăn việc include trùng lặp.

**Tóm tắt:**

* **Namespace:** Tổ chức code, tránh xung đột tên.
* **Include guard:** Ngăn chặn include trùng lặp.
* **Header và source file:** Tách biệt khai báo và định nghĩa, tăng tính tái sử dụng và dễ bảo trì.

**Ví dụ minh họa:**

```c++
// header.h
#ifndef MYHEADER_H
#define MYHEADER_H

namespace MyNamespace {
    class MyClass {
    public:
        void myFunction();
    };
}

#endif // MYHEADER_H

// source.cpp
#include "header.h"

using namespace MyNamespace;

int main() {
    MyClass obj;
    obj.myFunction();
    return 0;
}
```

Trong ví dụ trên:

* `header.h` chứa khai báo của lớp `MyClass` trong namespace `MyNamespace`.
* `source.cpp` include `header.h` để sử dụng lớp `MyClass`.

## Some other idea

* **Forward declaration:** Khai báo trước một function or class mà chưa cần biết chi tiết định nghĩa.
* **Inline function:** Hàm nội tuyến, giúp tăng tốc độ thực thi.
* **Template:** Mẫu lập trình, tạo ra các hàm hoặc lớp có thể hoạt động với nhiều kiểu dữ liệu khác nhau.
