# Exception Handling

## Use default tool

* allows the program to **continue running or exit gracefully** when encountering errors **instead of crashing** abruptly
* keywords:
  * try: Defines **a block of code** that should **be monitored for exceptions**.

  ```cpp
  try {
    // code that might throw an exception
  }
  ```

  * catch: Specifies the **type of exception** to be caught and the block of code that shall be executed when that exception occurs.

  ```cpp
  catch (int e) {
    // handle exception of type int
  }
  catch (char e) {
    // handle exception of type char
  }
  catch (...) {
    // handle any other exception
  }
  ```
  
  * throw: **Throws an exception** that will be caught and handled by the appropriate catch block.

  ```cpp
  try {
    int num1 = 10, num2 = 0;
    if (num2 == 0) {
      throw "Division by zero not allowed!";
    } else {
      int result = num1 / num2;
      std::cout << "Result: " << result << std::endl;
    }
  }
  catch (const char* e) {
    std::cout << "Error: " << e << std::endl;
  }
  ```
  
  * noexcept: Specifies a function that doesn’t throw exceptions or terminates the program if an exception is thrown within its scope.

* Simple example:

```cpp
#include <iostream>

int divide(int a, int b) {
    if (b == 0) {
        // use throw to define the error could happen
        throw "Division by zero!";
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    // start try a block of code that could make a exception
    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const char* msg) {
        // catch message of error (defined when throw)
        std::cerr << "Error: " << msg << std::endl;
        // cerr: means character error
    }

    return 0;
}
```

## Use library tool: Standard Exceptions

```cpp
#include <stdexcept>
```

Some main function this class of library can do:

* std::exception: Base class for **all standard exceptions**.
* std::logic_error: Represents **errors** which can be **detected statically by the program**.
* std::runtime_error: Represents **errors occurring during the execution** of a program.
* Eg:

```cpp
#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        // throw a error when run execution
        throw std::runtime_error("Division by zero!");
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two numbers for division: ";
    std::cin >> num1 >> num2;

    try {
        int result = divide(num1, num2);
        std::cout << "The result is: " << result << std::endl;
    } catch (const std::exception& e) {
        // catch the exception e
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

## Compare default tool with lib tool

### Cách xử lý ngoại lệ mặc định (sử dụng `throw` và `catch`)

* **Ưu điểm:**:

    * **Linh hoạt:** Cho phép bạn tùy chỉnh cách thức báo cáo và xử lý lỗi một cách linh hoạt nhất.
    * **Dễ hiểu:** Cú pháp đơn giản, dễ nắm bắt và sử dụng.
    * **Kiểm soát hoàn toàn:** Bạn có thể tự định nghĩa các loại ngoại lệ và cách xử lý chúng.

* **Nhược điểm:**
    * **Thiếu thống nhất:** Nếu không có quy ước chung, các phần khác nhau của chương trình có thể sử dụng các cách báo cáo lỗi khác nhau, gây khó khăn trong việc bảo trì.
    * **Dễ xảy ra lỗi:** Việc tự định nghĩa các loại ngoại lệ có thể dẫn đến việc bỏ sót các trường hợp lỗi và gây ra các lỗi khó phát hiện.

### Cách xử lý ngoại lệ sử dụng thư viện tiêu chuẩn (sử dụng `stdexcept`)

* **Ưu điểm:**
    * **Tiêu chuẩn hóa:** Cung cấp **một bộ các lớp ngoại lệ tiêu chuẩn**, giúp cho **code trở nên rõ ràng hơn và dễ bảo trì**.
    * **Hiểu rõ:** Các lớp ngoại lệ trong thư viện tiêu chuẩn đã được thiết kế kỹ lưỡng và được sử dụng rộng rãi, giúp cho việc xử lý lỗi trở nên dễ dàng hơn.
    * **Tính kế thừa:** Các lớp ngoại lệ trong thư viện tiêu chuẩn có thể được kế thừa để tạo ra các loại ngoại lệ tùy chỉnh, giúp tận dụng được các tính năng có sẵn.
  
* **Nhược điểm:**
    * **Ít linh hoạt:** Có thể không đáp ứng được tất cả các yêu cầu tùy chỉnh của một số ứng dụng.
    * **Cần học thêm:** Để sử dụng hiệu quả thư viện tiêu chuẩn, bạn cần hiểu rõ về các lớp ngoại lệ và cách chúng hoạt động.

### Bảng so sánh chi tiết

| Tính năng | Cách xử lý mặc định | Sử dụng thư viện tiêu chuẩn |
|---|---|---|
| **Linh hoạt** | Rất cao | Tương đối thấp |
| **Dễ hiểu** | Dễ | Dễ hơn khi đã quen |
| **Tiêu chuẩn hóa** | Thấp | Cao |
| **Tùy chỉnh** | Cao | Trung bình |
| **Hiệu suất** | Có thể tùy biến | Thường tối ưu hơn |

### Khi nào nên sử dụng cách nào?

* **Sử dụng cách xử lý mặc định:**
    * Khi bạn cần một mức độ kiểm soát cao hơn đối với cách thức báo cáo và xử lý lỗi.
    * Khi bạn cần tạo ra các loại ngoại lệ tùy chỉnh phức tạp.
* **Sử dụng thư viện tiêu chuẩn:**
    * Khi bạn muốn có một cách tiếp cận thống nhất và dễ hiểu để xử lý lỗi.
    * Khi bạn muốn tận dụng các lợi ích của các lớp ngoại lệ được định nghĩa sẵn.
    * Khi bạn muốn viết code có thể dễ dàng được đọc và bảo trì bởi các lập trình viên khác.

**Kết luận:**

Cả hai cách xử lý ngoại lệ đều có ưu và nhược điểm riêng. Việc lựa chọn cách nào phụ thuộc vào yêu cầu cụ thể của từng dự án. Trong nhiều trường hợp, việc kết hợp cả hai cách là một giải pháp tốt.

**Ví dụ:** Bạn có thể sử dụng các lớp ngoại lệ tiêu chuẩn để báo cáo các lỗi chung, và tự định nghĩa các lớp ngoại lệ tùy chỉnh để xử lý các trường hợp lỗi đặc biệt của ứng dụng của bạn.

**Lưu ý:**

* **Luôn nhớ xử lý ngoại lệ:** Việc không xử lý ngoại lệ có thể dẫn đến chương trình bị crash hoặc hoạt động không đúng.
* **Chọn loại ngoại lệ phù hợp:** Chọn loại ngoại lệ phù hợp để mô tả chính xác lỗi xảy ra.
* **Xử lý ngoại lệ một cách hiệu quả:** Đảm bảo rằng các khối `catch` của bạn xử lý lỗi một cách chính xác và không gây ra các lỗi mới.
