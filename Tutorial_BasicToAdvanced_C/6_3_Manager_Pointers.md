# Manager Pointers

## Use `new` and `delete` for raw pointers

* `new`, `delete`: for single object. Eg:

```cpp
int* ptr = new int; // Dynamically allocates an int on the heap
*ptr = 42; // Assigns the value 42 to the allocated int

delete ptr; // Deallocates the memory assigned to ptr
```

* `new[]`, `delete[]`: for a list of objects. Eg:

```cpp
int n = 10;
int* arr = new int[n]; // Dynamically allocates an array of 10 integers on the heap

// Set some values in the array
for (int i = 0; i < n; i++) {
  arr[i] = i;
}

delete[] arr; // Deallocates the memory assigned to the array: a list of 10 interger object
```

## Avoid memory leak

Note: Forgetting deallocate a object can make memory leaks

To avoid memory leaks, you should always ensure that memory is deallocated before a pointer goes out of scope or is reassigned.

Some ways to achieve this include using the C++ **smart pointers (std::unique_ptr, std::shared_ptr), RAII (Resource Acquisition Is Initialization) techniques**, and containers from the **C++ standard library that manage memory allocation internally** (e.g., std::vector, std::string).

## Smart pointers - easier way to control memory leaks

* `std::unique_ptr`:
  * managing single objects or arrays,
  * only one `unique_ptr` is allowed to own an object at a time,
  * ownership can be transferred or moved, but it cannot be shared or copied.
  * When the `unique_ptr` goes out of scope, it automatically deletes the object it owns.
  * Detail about how to **create**, **transfer owner**, **delete** [here](https://roadmap.sh/cpp) in Pointers and References for Smart Pointers/unique_ptr

* `std::shared_ptr`:
  * allows **multiple pointers** to share ownership of **a dynamically allocated object**,
  * **object will be automatically deallocated** only when the **last shared_ptr** that points to it **is destroyed**
  * Simple example to know more about `shared_ptr`

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Constructor is called." << std::endl; }
    ~MyClass() { std::cout << "Destructor is called." << std::endl; }
};

int main() {
    // create a shared pointer to manage the MyClass object
    std::shared_ptr<MyClass> ptr1(new MyClass());
    
    {
        // create another shared pointer and initialize it with the previously created pointer
        std::shared_ptr<MyClass> ptr2 = ptr1;

        std::cout << "Inside the inner scope." << std::endl;
        // both pointers share the same object, and the reference counter has been increased to 2
    }

    std::cout << "Outside the inner scope." << std::endl;
    // leaving the inner scope will destroy ptr2, and the reference counter is decremented to 1
    
    // the main function returns, ptr1 goes out of scope, and the reference counter becomes 0
    // this causes the MyClass object to be deleted and the destructor is called
}
```

* `std::weak_ptr`:
  * adds a level of **indirection** and safety to a **raw pointer**,
  * mainly used to **break reference cycles in cases where two objects have shared pointers to each other**,
  * or when you **need a non-owning reference to an object** that is **managed by a shared_ptr**.
  * **does not increase the ownership reference count** of the object it points to, which is a key difference between weak_ptr and shared_ptr.
  * To use a **weak_ptr**, you must **convert it to a shared_ptr using the lock() function**, which tries to **create a new shared_ptr that shares ownership of the object**. If successful, the object’s reference count is increased and you can use the returned shared_ptr to safely access the object.

## Detail about `weak_ptr`

**Weak_ptr là gì?**

Trong C++, `weak_ptr` là một loại con trỏ đặc biệt, được sử dụng để tham chiếu đến một đối tượng được quản lý bởi một `shared_ptr`. Không giống như `shared_ptr`, `weak_ptr` không tăng tham chiếu đến đối tượng mà nó trỏ tới. Điều này có nghĩa là `weak_ptr` không trực tiếp ngăn đối tượng bị hủy khi không còn `shared_ptr` nào trỏ đến nó.

**Tại sao cần weak_ptr?**

* **Tránh vòng tròn tham chiếu:** Khi nhiều đối tượng tham chiếu lẫn nhau qua `shared_ptr`, có thể dẫn đến tình trạng vòng tròn tham chiếu, khiến các đối tượng không thể bị giải phóng khỏi bộ nhớ, gây rò rỉ bộ nhớ. `weak_ptr` giúp phá vỡ vòng tròn này bằng cách cung cấp một cách để tham chiếu đến một đối tượng mà không tăng tham chiếu của nó.
* **Quản lý vòng đời đối tượng:** `weak_ptr` cho phép bạn kiểm tra xem đối tượng mà nó trỏ tới còn tồn tại hay không trước khi truy cập vào nó. Điều này giúp tránh các lỗi truy cập vào đối tượng đã bị hủy.

**Cách sử dụng weak_ptr:**

1. **Tạo weak_ptr:** Bạn có thể tạo một `weak_ptr` từ một `shared_ptr` hiện có.
2. **Kiểm tra tính hợp lệ:** Sử dụng hàm `expired()` để kiểm tra xem đối tượng mà `weak_ptr` trỏ tới còn tồn tại hay không.
3. **Truy cập đối tượng:** Nếu đối tượng vẫn còn tồn tại, bạn có thể sử dụng hàm `lock()` để lấy một `shared_ptr` tạm thời và truy cập vào đối tượng.

**Ví dụ:**

```c++
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "Constructor\n"; }
    ~MyClass() { std::cout << "Destructor\n"; }
};

int main() {
    std::shared_ptr<MyClass> shared_ptr(new MyClass);
    std::weak_ptr<MyClass> weak_ptr(shared_ptr);

    // Kiểm tra xem đối tượng còn tồn tại hay không
    if (!weak_ptr.expired()) {
        // Lấy một shared_ptr tạm thời và sử dụng nó
        std::shared_ptr<MyClass> tmp = weak_ptr.lock();
        // Sử dụng tmp để truy cập vào đối tượng
    }
}
```

**Tóm lại:**

`weak_ptr` là một công cụ hữu ích trong C++ để quản lý vòng đời của các đối tượng và tránh rò rỉ bộ nhớ. Nó cung cấp một cách an toàn để tham chiếu đến các đối tượng được quản lý bởi `shared_ptr` mà không làm tăng tham chiếu của chúng.

**Khi nào nên sử dụng weak_ptr?**

* Khi bạn cần tham chiếu đến một đối tượng nhưng không muốn sở hữu nó.
* Khi bạn muốn phá vỡ vòng tròn tham chiếu.
* Khi bạn cần kiểm tra xem một đối tượng còn tồn tại hay không trước khi truy cập vào nó.

**Lưu ý:**

* `weak_ptr` không cung cấp quyền sở hữu đối tượng.
* `weak_ptr` có thể trở nên hết hạn (expired) nếu đối tượng mà nó trỏ tới bị hủy.
* Luôn kiểm tra tính hợp lệ của `weak_ptr` trước khi sử dụng nó.
