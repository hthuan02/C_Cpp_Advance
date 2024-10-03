# STACK & HEAP SEGMENT

<img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/Bai8_Memory-layout/images/stack_heap.png" alt="Memory Layout" width="220"/>

## So sánh giống và khác nhau:

### Giống nhau:

1. **Lưu trữ dữ liệu**: Đều dùng để lưu trữ dữ liệu.
2. **Nhiều kiểu dữ liệu**: Có thể lưu trữ nhiều kiểu dữ liệu.
3. **Nằm trong RAM**: Nằm trong bộ nhớ RAM khi chương trình chạy.
4. **Ảnh hưởng đến hiệu suất**: Cách quản lý bộ nhớ trong cả Stack và Heap có thể ảnh hưởng đến hiệu suất chương trình.
5. **Có thể bị tràn bộ nhớ**: Stack overflow và Heap overflow đều có thể xảy ra nếu không quản lý đúng cách.

### Khác nhau:

- Lập bảng so sánh

| **Tiêu chí**              | **Stack**                                                                 | **Heap**                                                          |
|---------------------------|---------------------------------------------------------------------------|-------------------------------------------------------------------|
| **Mục đích**              | Lưu biến cục bộ, tham số hàm.                                              | Lưu trữ vùng nhớ cấp phát động như: malloc(), calloc(), realloc().                                   |
| **Quản lý**               | Tự động (hệ điều hành).                                                   | Thủ công (lập trình viên).                                        |
| **Tốc độ**                | Nhanh.                                                                    | Chậm hơn Stack.                                                   |
| **Giải phóng**            | Tự động khi hàm kết thúc.                                                 | Sử dụng hàm `free()` hoặc `delete`.                                 |
| **Tràn bộ nhớ**           | Stack overflow khi dùng quá nhiều bộ nhớ.                                 | Heap overflow khi không giải phóng hoặc cấp phát quá lớn.         |
| **Kích thước**            | Cố định (nhỏ hơn).                                                        | Linh hoạt (lớn hơn).                                              |
| **Thời điểm cấp phát**    | Lúc biên dịch.                                                            | Lúc chạy chương trình.                                            |
| **Rò rỉ bộ nhớ**          | Không xảy ra.                                                             | Có thể xảy ra nếu không giải phóng.                               |

### Stack overflow & Heap overflow

- **Stack overflow**: Do bộ nhớ Stack cố định, nếu sử dụng quá nhiều sẽ gây tràn bộ nhớ (Stack overflow), ví dụ như khởi tạo quá nhiều biến cục bộ hoặc đệ quy vô hạn.

_VD1: Gọi hàm mà không có điều kiện dừng_

```
    int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
    }
```

- **Heap overflow**:
    - Nếu không giải phóng bộ nhớ, bằng hàm `free()` hoặc `delete` sẽ gây tràn bộ nhớ (Heap overflow).
    - Khởi tạo vùng nhớ quá lớn mà Heap không đủ cũng sẽ gây lỗi.

_VD2: Khởi tạo vùng nhớ quá lớn_

```
    int *A = (int *)malloc(18446744073709551615);
```
  
