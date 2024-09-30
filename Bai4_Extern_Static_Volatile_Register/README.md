# BÀI 4: EXTERN - STATIC - VOLATILE - REGISTER

- Đây là các từ khóa đi kèm khi khai báo các biến "đặc biệt".

## 1. Extern

> Giúp file trong cùng 1 folder chia sẻ các biến, hàm với nhau.
>
> Các biến chỉ khai báo, không được khởi tạo.
>
> Khai báo biến cấp độ cao nhất - toàn cục.

**Ưu điểm quan trọng:** Tiết kiệm được bộ nhớ.

- Muốn sử dụng lại các biến đã khai báo trong file trước đó. Theo thông thường ta phải khai báo `#include"file.h"` hoặc `#define_FILE1_H`, đối với xử lý nhiều file thì việc khai báo cho file main.c sẽ tốn rất nhiều bộ nhớ.
-  Vì vậy, để chia sẻ tài nguyên các biến các hàm trong nhiều file cùng 1 folder, chúng ta có thể dùng extern.

_VD1:_ Ta có 3 file
     
          file1.c

          file2.c

          main.c 

➡️ Để sử dụng các biến của 1 và 2, ta khai báo `extern int a;` hoặc `extern int b;`.

## 2. Static

### 2.1 Satic - local variables

> Giới hạn đối tượng trong phạm vi hàm sử dụng.
>
> Cấp thoát địa chỉ tồn tại xuyên suốt chương trình.
>
>
> Static cục bộ không thể thay đổi giá trị bên ngoài, nếu muốn thay đổi thì sử dụng con trỏ.

_VD2: Static biến cục bộ_

```
     #include<stdio.h>
     void count(){
          int a=5;
          a++;
          printf("Gia tri: %d\n",a);
     }

     int main(int argc, char const *argv[]){
          count(); //6
          count(); //6
          count(); //6
          count(); //6
     }
```
- Hàm `count` dù được gọi bao nhiêu lần vẫn in ra giá trị là 6. Vì biến `a` được khai báo là 1 biến cục bộ trong hàm `count()`
- Sau khi hàm `count` đầu tiền hoàn thành, `a` sẽ bị hủy giá trị (cấp thoát địa chỉ) và các giá trị tiếp theo vẫn = 6. 
- Nếu ở thêm biến `static` cục bộ vào `int a=5;` là `static int a=5;` thì giá trị `a` mới có thể tăng dần lên 7, 8,... theo số lần gọi hàm `count`.
- Có thể dùng con trỏ để thay đổi giá trị 
```
     #include<stdio.h>

     int *ptr = NULL;
     void count(){
          static int a=5;
          ptr = &a;
          a++;
          printf("Gia tri: %d\n",a);
     }

     int main(int argc, char const *argv[]){
          count(); //6
          count(); //7
          count(); //8
          *ptr = 99;
          count(); //100
     }
```

### 2.2 Satic - global variables
>
> Giới hạn phạm vị sử dụng trong 1 file (tránh việc khai báo trùng tên biến và hàm giữa các file). 
>
> Những biến nào được khai báo static toàn cục thì chỉ được sử dụng trong đúng file đó, không thể liên kết file.
>
> Không thể dùng con trỏ để thay đổi giá trị.

**- Ưu điểm:** Sử dụng static toàn cục để ẩn ở quá trình trung gian tính ra kết quả. Như tính delta trong phương trình bậc 2.

### 2.3 Satic - class (hướng đối tượng trong C++), học sau

## 3. Volatile

**Biên volatile là gì?** Nếu khai báo biến mà biến này không sử dụng, thì biến này mặc dù vẫn còn ở chương trình nhưng nó đã bị xóa khỏi bộ nhớ chương trình nhằm để làm giảm bộ nhớ.

➡️ Biến volatile giúp khắc phục tình trạng đó.

>
> Dùng trong code cho MCU, ép buộc 1 biến truy cập đến địa chỉ và nó không bị xóa khỏi bộ nhớ khi biến đó k được sử dụng.
>

```
     // Dùng trong code VDK

     #include "stm32f4xx.h"
     volatile unit8_t var = 0;

```

**Ứng dụng:** Đọc giá trị cảm biến nhiệt độ nhiệt độ, ví dụ có 10 giá trị 30 độ C giống nhau, thì có nguy cơ biến CB nhiệt độ bị xóa khỏi bộ nhớ. Vì vậy, sử dụng biến Volatile đảm bảo cảm biến nhận đúng giá trị không bị cấp thoát, hạn chế sai số.

## 4. Register

![](https://github.com/hthuan02/C_Cpp_Advance/blob/main/Bai4_Extern_Static_Volatile_Register/register.png)

Khi thực thi 1 chương trình sẽ trải qua 4 giai đoạn:

**(1):** Lưu trữ từ trong bộ nhớ RAM, thực hiện tính toán.

**(2):** Thao tác tính toán các giá trị.

**(3):** Tính xong thì lưu giá trị trong thanh ghi.

**(4):** Lấy giá trị trong thanh ghi trả về biến trong RAM, kết quả = 6.


**- Ứng dụng của biến register:** (ít ứng dụng)
     - Khai báo biến register, bỏ qua 2 giai đoạn (1) và (4). Giúp giảm thời gian chạy và tăng hiệu suất làm việt của chương trình (Lấy giá trị từ thanh ghi và trả kết quả về thanh ghi).
     - Chỉ sử dụng cho biến cục bộ.







