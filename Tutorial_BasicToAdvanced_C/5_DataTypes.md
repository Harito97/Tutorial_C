# Data Types

## Simple Types

(fundamental data types)

* Int: int (4 bytes), short int, long int, long long int
* Float: float (4 bytes), double (8 bytes)
* Char: char (1 byte)
* Bool: bool (1 byte)

## Derived Data Types

(derived from fundamental data types)

### Arrays

**store multiple values** of the s**ame data type** in consecutive memory locations

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
// data_type var_name[num_element] = {list of element};
```

### Pointers

store the **memory address** of a variable

```cpp
int num = 42;
int* pNum = &num;
// pNum: pointer_num (int*) to num variable (&num) 
```

### References

an alternative way to **share memory locations between variables**, allowing you to create an alias for another variable

```cpp
int num = 42;
int& numRef = num;
// numRef: ref to num variable (int&)
```

## User-Defined Data Types

(structures, classes, and unions)

### Structures (struct)

Structures are used to **store different data types under a single variable** and **accessibility of member** variables and methods are **public**.

```cpp
struct Person {
    std::string name;
    int age;
    float height;
};

Person p1 = {"John Doe", 30, 5.9};
```

### Classes (class)

Classes are **similar to structures, but the accessibility of the member** data and function are governed by **access specifiers**. By default access to members of a class is private.

### Unions (union)

Unions are used to **store different data types** in the **same memory location**.

```cpp
union Data {
    int num;
    char letter;
    float decimal;
};

Data myData;
myData.num = 42;
```

## Static Typing

The data type of a variable is determined at compile time, before the program is executed. This means that a **variable can only be used with data of a specific type**, and the compiler ensures that the operations performed with the variable are compatible with its type.

If we use convert for example:

```cpp
int num = 65
float e = 3.27
char c = 'B'

// then if
c = num
num = e
// c will be 'A' - that corresponding ASCII code
// num will be 3 - as num is a integer
```

## Dynamic Typing

C++ also provides concepts to have certain level of dynamic typing, which means **determining the data types of variables at runtime**.

Here is 2 ways to do that:

### `void*` Pointers

* generic pointer that can **point to objects of any data type**
* use to **store a reference to any type of object** without knowing the specific type of the object

Example:

```cpp
#include <iostream>

int main() {
    int x = 42;
    float y = 3.14f;
    std::string z = "Hello, world!";

    void* void_ptr;

    void_ptr = &x;
    std::cout << "int value: " << *(static_cast<int*>(void_ptr)) << std::endl;

    void_ptr = &y;
    std::cout << "float value: " << *(static_cast<float*>(void_ptr)) << std::endl;

    void_ptr = &z;
    std::cout << "string value: " << *(static_cast<std::string*>(void_ptr)) << std::endl;

    return 0;
}
```

### `std::any` (C++17)

* a generalized type-safe container for single values of any type
* means that it stores bits $\to$ value of any data type (convert bit to show in data type form)

Example:

```cpp
#include <iostream>
#include <any>

int main() {
    std::any any_value;

    any_value = 42;
    std::cout << "int value: " << std::any_cast<int>(any_value) << std::endl;

    any_value = 3.14;
    std::cout << "double value: " << std::any_cast<double>(any_value) << std::endl;

    any_value = std::string("Hello, world!");
    std::cout << "string value: " << std::any_cast<std::string>(any_value) << std::endl;

    return 0;
}
```

Keep in mind that both **void* pointers** and **std::any** have performance implications due to the additional type checking and casting that take place during runtime (**mean that slower**). They should be used carefully and only when absolutely necessary.

### Run-Time Type Identification (RTTI)

**obtain the type information of an object during program execution**. This can be useful when using dynamic typing, where the type of an object can change at runtime.

There are **two main mechanisms** for RTTI in C++:

* typeid operator
* dynamic_cast operator

#### typeid operator

**returns a reference** to an object of type `std::type_info`, which **contains information about the type of the object**. The header file <typeinfo> should be included to use typeid.

```cpp
include <typeinfo>
```

Example to use:

```cpp
#include <iostream>
#include <typeinfo>

class Base { virtual void dummy() {} };
class Derived : public Base { /* ... */ };

int main() {
    Base* base_ptr = new Derived;

    // Using typeid to get the type of the object
    std::cout << "Type: " << typeid(*base_ptr).name() << '\n';

    delete base_ptr;
    return 0;
}
```

#### dynamic_cast operator

`dynamic_cast` is a type-casting operator that performs a **runtime type check** and **safely downcasts a base pointer or reference to a derived pointer or reference**. It returns null or throws a bad_cast exception (if casting references) when the casting fails.

Example:

```cpp
#include <iostream>

class Base { virtual void dummy() {} };
class Derived1 : public Base { /* ... */ };
class Derived2 : public Base { /* ... */ };

int main() {
    Base* base_ptr = new Derived1;

    // Using dynamic_cast to safely downcast the pointer
    Derived1* derived1_ptr = dynamic_cast<Derived1*>(base_ptr);
    if (derived1_ptr) {
        std::cout << "Downcast to Derived1 successful\n";
    }
    else {
        std::cout << "Downcast to Derived1 failed\n";
    }

    Derived2* derived2_ptr = dynamic_cast<Derived2*>(base_ptr);
    if (derived2_ptr) {
        std::cout << "Downcast to Derived2 successful\n";
    }
    else {
        std::cout << "Downcast to Derived2 failed\n";
    }

    delete base_ptr;
    return 0;
}
```

## Explain why only need to delete `base_ptr` - object

* **Một đối tượng, nhiều con trỏ:** Trong đoạn mã, mặc dù chúng ta có nhiều con trỏ (`base_ptr`, `derived1_ptr`, `derived2_ptr`) nhưng chúng đều trỏ đến **cùng một đối tượng** được cấp phát động ở dòng `Base* base_ptr = new Derived1;`.
* **`delete` chỉ giải phóng một lần:** Khi chúng ta gọi `delete base_ptr;`, chúng ta chỉ yêu cầu hệ thống giải phóng **đúng một lần** vùng nhớ mà đối tượng đó đang chiếm giữ. Việc giải phóng này sẽ làm cho tất cả các con trỏ đang trỏ đến đối tượng đó trở thành **con trỏ rỗng (dangling pointer)**.
* **Không có đối tượng nào bị "mất"**: Các biến `derived1_ptr` và `derived2_ptr` vẫn tồn tại trong bộ nhớ, nhưng chúng không còn hợp lệ nữa vì đối tượng mà chúng đang trỏ đến đã bị xóa. Nếu chúng ta cố gắng truy cập vào các biến này sau khi xóa, chương trình sẽ gặp lỗi.

**Tại sao không cần xóa các biến khác?**

* **Các biến khác không quản lý bộ nhớ:** Các biến `derived1_ptr` và `derived2_ptr` chỉ là các con trỏ, chúng không quản lý bộ nhớ trực tiếp. Chúng chỉ lưu trữ địa chỉ của một đối tượng.
* **Xóa một lần là đủ:** Việc xóa đối tượng gốc một lần là đủ để giải phóng toàn bộ bộ nhớ mà đối tượng đó chiếm giữ.

**Vì sao không nên xóa nhiều lần?**

* **Lỗi nghiêm trọng:** Việc gọi `delete` nhiều lần trên cùng một con trỏ sẽ dẫn đến hành vi không xác định và có thể gây ra lỗi nghiêm trọng trong chương trình, chẳng hạn như lỗi segmentation fault.

**Tóm lại:**

Trong ví dụ trên, chỉ cần xóa `base_ptr` là đủ để giải phóng bộ nhớ được cấp phát cho đối tượng. Việc xóa các biến con trỏ khác là không cần thiết và có thể gây ra lỗi.

**Lưu ý:**

* **Quy tắc vàng:** Một đối tượng chỉ nên được xóa một lần.
* **Smart pointer:** Để quản lý bộ nhớ một cách an toàn hơn, bạn có thể sử dụng các smart pointer như `unique_ptr`, `shared_ptr`. Các smart pointer sẽ tự động giải phóng bộ nhớ khi chúng không còn được sử dụng nữa, giúp tránh các lỗi rò rỉ bộ nhớ.

**Ví dụ sử dụng smart pointer:**

```c++
#include <memory>

int main() {
    std::unique_ptr<Derived1> base_ptr = std::make_unique<Derived1>();
    // ...
    // Khi base_ptr hết phạm vi, bộ nhớ sẽ tự động được giải phóng
}
```

## What happened when program return 0

**Sau khi `return 0;`, các con trỏ trong chương trình C++ sẽ như thế nào?**

Câu hỏi này rất hay và đi sâu vào cơ chế hoạt động của chương trình C++. Để trả lời chính xác, chúng ta cần hiểu rõ về:

* **Vùng nhớ stack:** Đây là nơi lưu trữ các **biến cục bộ, tham số hàm, địa chỉ trả về**, v.v. Khi hàm kết thúc, các biến trên stack sẽ bị giải phóng tự động.
* **Vùng nhớ heap:** Đây là nơi cấp phát động các khối nhớ lớn hơn, như các **đối tượng** được tạo bằng `new`. Việc **giải phóng bộ nhớ heap phải được thực hiện thủ công** bằng `delete`.
* **Hàm `main`:** Là điểm bắt đầu và kết thúc của chương trình. Khi `main` kết thúc, chương trình cũng kết thúc.

**Trả lời:**

* **Các con trỏ trên stack:** Khi `return 0;` được gọi, hàm `main` kết thúc và tất cả các biến cục bộ trên stack, bao gồm cả các con trỏ, sẽ bị giải phóng.
* **Các con trỏ trỏ đến vùng nhớ heap:** Nếu bạn **chưa giải phóng bộ nhớ heap** bằng `delete` trước khi `return 0;`, thì sẽ **xảy ra lỗi rò rỉ bộ nhớ**. Các vùng nhớ này sẽ không được giải phóng và **chương trình sẽ chiếm dụng một lượng bộ nhớ không cần thiết**.

**Ví dụ:**

```c++
#include <iostream>

int main() {
    int *ptr = new int;
    *ptr = 10;

    // Nếu không có dòng delete sau đây, sẽ xảy ra rò rỉ bộ nhớ
    delete ptr;

    return 0;
}
```

Trong ví dụ trên:

* `ptr` là một con trỏ trên stack.
* `new int` cấp phát một vùng nhớ trên heap và `ptr` trỏ đến vùng nhớ đó.
* Nếu không có dòng `delete ptr;`, khi `main` kết thúc, `ptr` sẽ bị giải phóng, nhưng vùng nhớ trên heap mà nó đang trỏ tới vẫn còn tồn tại, gây ra rò rỉ bộ nhớ.

**Kết luận:**

* **Các con trỏ trên stack** sẽ tự động bị giải phóng khi hàm kết thúc.
* **Các con trỏ trỏ đến vùng nhớ heap** phải được giải phóng thủ công bằng `delete` để tránh rò rỉ bộ nhớ.
* **Luôn đảm bảo giải phóng bộ nhớ heap một cách đúng đắn** để chương trình hoạt động ổn định và hiệu quả.

**Lưu ý:**

* **Smart pointer:** Để quản lý bộ nhớ heap một cách an toàn hơn, bạn nên sử dụng smart pointer như `unique_ptr` hoặc `shared_ptr`. Các smart pointer sẽ tự động giải phóng bộ nhớ khi chúng không còn được sử dụng nữa.
* **RAII (Resource Acquisition Is Initialization):** Đây là một kỹ thuật quản lý tài nguyên hiệu quả trong C++. Ý tưởng chính là liên kết việc cấp phát tài nguyên (như bộ nhớ) với vòng đời của một đối tượng. Khi đối tượng bị hủy, tài nguyên cũng sẽ được giải phóng tự động.

**Tóm lại:**

Việc hiểu rõ về cách thức hoạt động của bộ nhớ trong C++ và cách quản lý các con trỏ là rất quan trọng để viết các chương trình C++ an toàn và hiệu quả. Luôn nhớ giải phóng bộ nhớ heap một cách đúng đắn để tránh rò rỉ bộ nhớ và các vấn đề khác.
