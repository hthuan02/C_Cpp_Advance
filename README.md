# Phần I: C & Algorithm
---

<details>
  <summary><h3>Bài 1: Compiler - Marco</h3></summary>
    
IDE gồm:
- editor: phần mềm soạn thảo
- Complier: gcc cho C ,g++ cho C++

## I. Quá trình Compiler
Gồm 4 bước chính:
    - Tiền xử lý (Preprocessor)
    - Compiler
    - Asembler
    - Linker
### 1. Tiền xử lý
(chuyển file.c, file.h thành file.i)

> Copy toàn bộ mã nguồn vào file main
>
> Xóa cmt
>
> Nếu sử dụng macro #define thì bị thay thế, còn lại giữ nguyên

`gcc -E main.c -o main`

### 2. Complier
(chuyển file.i thành file.s)

> Tạo ra file hợp ngữ
>
> Thao tác trên RAM mượt mà hơn

### 3. Assembler
(chuyển file.s thành file.o)

> Source code chuyển thành các đoạn mã 0 1(ngôn ngữ máy)
>
> Nếu code trên VDK thì chương trình lưu vào bộ nhớ Flash

### 4. Linker
(Liên kết các file.o, build lại thành file.exe)

## II. Marcro

> Trong giai đoạn 1 tiền xử lý của quá trình Compiler thì có cacs macro hỗ trợ xử lý
>
> Marco là từ chỉ thông tin được xử lý ở quá trình tiền xử lý (preprocessor).

### 1. Macro chỉ thị bao hàm tệp

- #include< >: Tìm kiếm trong thư mục cài đặt

- #include" ": Tìm kiếm trong thư mục hiện tại

### 2. Macro chỉ thị định nghĩa

- #define: Định nghĩa 1 đối tượng(biến, hàm, mảng)

- #undef: Xóa bỏ định nghĩa #define

**Trong macro #define có 3 toán tử**

- ##: Gộp(nhóm) các chuỗi

- #: Chuyển kí tự --> chuỗi

- Variadic: Cho phép 1 hàm có thể nhận số lượng tham số truyền vào không xác định.


### 3. Macro chỉ thị biên dịch có điều kiện

- #ifdef, #ifndef: Kiểm tra xem 1 macro có định nghĩa hay chưa

    - #ifdef: Nếu đã định nghĩa -->> thực thi chương trình
 
    - #ifndef: Nếu chưa định nghĩa -->> thì định nghĩa --> thực thi

- #if, #else, #elif: đây là các macro kiểm tra điều kiện giống (if-else-else if)

## SỬ DỤNG MACRO VÀ FUNCTION CÓ GÌ KHÁC NHAU? 

- Function: Không cấp phát bộ nhớ, vì có bộ nhớ riêng, tốc độ châm, đầu tiên lưu vào stack --> lấy vào địa

- Macro: Tốn bộ nhớ chương trình, để khởi tạo và lưu lại, tốc độ nhanh hơn--> bộ đếm chương trình tuần tự

</details>


<details>
  <summary><h3>Bài 3: Pointer</h3></summary>

- Con trỏ là 1 biến, thay vì lưu giá trị thì dùng để lưu địa chỉ của 1 đối tượng(biến, hàm, mảng,...). 
- Con trỏ không lưu giá trị mà nó lưu địa chỉ bộ nhớ nơi biến khác đang sử dụng.

## 1. Kích thước của Con trỏ
- Phụ thuộc vào kiến trúc của máy tinh và trình biên dịch(IDE).

- Trên MCU phụ thuộc vào Vi xử lý
_VD:_  STM32/32bit ---> 4byte

       STM8/8bit ----> 1byte
## 2. Regular Pointer(Con trỏ với biến)
```c
    int a = 10;
    int * ptr = &a;

    //Truy xuat con tro
    printf("Dia chi: %p\n", &a); // dia chi cua a
    printf("Dia chi: %p\n", ptr); // dia chi ma ptr tro den 
    printf("Gia tri tai dia chi: %d\n", *ptr); // a = 10
```

## 3. Array Pointer(Con trỏ mảng)

```c
    int arr[] = { 2, 3, 5, 7, 8 };
    int * ptr = arr;

    printf("Dia chi phan tu 1: %p\n", ptr) //2
    printf("Dia chi phan tu 2: %p\n", ptr+1) //3
    printf("Dia chi phan tu 3: %p\n", ptr+2) //5

    printf("Gia tri phan tu 1: %d\n", *ptr) 
    printf("Gia tri phan tu 2: %d\n", *(ptr+1)) 
    printf("Gia tri phan tu 3: %d\n", *(ptr+2))

```

## 4. Void Pointer
   > Là 1 biến, có thể trỏ đến bất kỳ địa chỉ có kiểu dữ liệu nào cũng được, nó không quan tâm các kiểu dữ liệu như (char, int, float, double,...).

   - Ưu điểm: Tại địa chỉ trỏ đến có thể đọc và thay đổi giá trị, với điều kiện phải ép kiểu con trỏ void.

```c
    void * ptr; //Khai bao con tro Void
```
- _VD1: Xuất giá trị kiểu int, char._

```c
    #include <stdio.h>

    int main{int argc, char const *argv[]){
        void *ptr;

        int a = 10;
        ptr = &a;
        printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int*)(ptr));
 
        char c = 'C';
        ptr = &c;
        printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char*)(ptr));
    }
```

## 5. Function Pointer
> Là 1 biến, có thể trỏ đến địa chỉ của 1 hàm có kiểu dữ liệu cụ thể.
>
>Đây là biến giữ địa chỉ của hàm, mỗi thời điểm chỉ trỏ 1 hàm.

- Thông thường sử dụng theo 2 cách:
    - Là tham số truyền vào của 1 hàm.
    - Lưu trữ địa chỉ của 1 hàm. 

```c
   void (*func_ptr)(int, int);  // Khai bao con tro
```

- _VD2: Tổng, hiệu, tích, thương._

```c
    #include<stdio.h>

    void tong(int a, int b){
        printf("%d + %d = %d\n",a ,b, a + b); 
    }
    void hieu(int a, int b){
        printf("%d - %d = %d\n",a ,b, a - b); 
    }
    void tich(int a, int b){
        printf("%d * %d = %d\n",a ,b, a * b); 
    }
    void thuong(int a, int b){
        printf("%d / %d = %d\n",a ,b, a / b);
    }

    int main(int argc, char *argv[]) {
    int a = 10, b = 5;

    //Khai bao mang con tro Ham
    void (*cal[])(int, int) = {tong, hieu, tich, thuong};
    for (int i = 0; i < 4; i++) {
       cal[i](a, b);
    }
```

## 6. Pointer to Constant(Con trỏ hằng)

> Khi trỏ đến 1 địa chỉ, không thể thay đổi đc giá trị tại địa chỉ đó (chỉ có thể đọc và không thể thay đổi).
>
> Có thể trỏ đến nhiều địa chỉ khác nhau.

```c
    int const *ptr_const;
    const int *ptr_const;
```

- _VD3:_
```c
    #include<stdio.h>

    int a = 10;
    int b = 3; //Khai bao ptr_const cua b duoc.
    const int *ptr_const = &a;

    int main(int argc, char const *argv[])
    {
        printf("%p\n", ptr_const);
        printf("%d\n", *ptr_const); //ptr_const = 10
    
        // *ptr_const = 5;
        // Dong nay sai, chi co the thay doi gia tri tai a.
        // VD: a = 15 -> *ptr_const =

        a = 15;
        printf("%p\n", ptr_const);
        printf("%d\n", *ptr_const); //ptr_const = 15
```
## 7. Constant Pointer(Hằng con trỏ)

> Tại địa chỉ trỏ đến không thể thay đổi được địa chỉ, còn giá trị có thể thay đổi được.
>
> Chỉ trỏ đến 1 địa chỉ cố đinh, khi đã trỏ đến 1 địa chỉ rồi thì không thể trỏ đến địa chỉ khác được nữa.

```c
    int *const const_ptr = &value;
```

- _VD4:_

```c
    #include<stdio.h>

    int a = 10;
    int b = 3; // Khong khai bao duoc const_ptr cua b!!!
    int *const const_ptr = &a;

    int main(int argc, char const *argv[])
    {
        printf("%p\n", const_ptr);
        printf("%d\n", *const_ptr); //ptr_const = 10
    
        *const_ptr = 15; // hay doi gia tri tai con tro luon.
        printf("%p\n", ptr_const);
        printf("%d\n", *ptr_const); //ptr_const = 15
```


### Bảng so sánh Con Trỏ Hằng VS Hằng Con trỏ

| Khác nhau | Con trỏ hằng | Hằng con trỏ |
| :---: | --- | ---: |
| 1 |Có thể trỏ đến nhiều địa chỉ khác | Chỉ trỏ đến 1 địa chỉ duy nhất |
| 2 |Chỉ có thể đọc, không thể thay đổi giá trị(giá trị chỉ được thay đổi tại biến)| Có thể thay đổi giá trị |

   
## 8. NULL Pointer
>Con trỏ trống, không trỏ đến vùng nhớ nào.
>
>Khai báo nhưng chưa sử dụng liền.

**Lưu ý:** 
- Khi khai báo con trỏ mà chưa sử dụng thì dùng con trỏ NULL sẽ không bị **random** giá trị vào địa chỉ rác hoặc trùng lặp địa .
- Khởi tạo và kết thúc phải gán NULL.

```c
    int *ptr = NULL;
```
   
## 9. Pointer to Pointer(Con trỏ đến con trỏ)
>Là con trỏ mà có thể trỏ đến địa chỉ của các con trỏ khác, có nhiều cấp độ con trỏ (con trỏ cấp 2, 3,...).

```c
    int a = 10;
    int *ptr = &a;
    int **ptr = &ptr;
```
**Lưu ý:** 
- Được sử dụng trong kiểu dữ liệu Json, cấu trúc dữ liệu list.
- Đối với con trỏ cấp 2 là lưu địa chỉ của con trỏ cấp 1, chứ không phải lưu địa chỉ mà con trỏ đang trỏ đến.             

</details>


<details>
  <summary><h3>Bài 4: Extern - Static - Volatile - Register</h3></summary> 

- Đây là các từ khóa đi kèm khi khai báo các biến "đặc biệt".

## 1. Extern

> Cho phép những file trong cùng 1 thư mục chia sẻ tài nguyên với nhau (biến, hàm, mảng).
>
> Các biến chỉ khai báo, không được khởi tạo.
>
> Khai báo biến cấp độ cao nhất - toàn cục.

**Ưu điểm quan trọng:** Tiết kiệm được bộ nhớ.

- Muốn sử dụng lại các biến đã khai báo trong file trước đó. Theo thông thường ta phải khai báo `#include"file.h"` hoặc `#define_FILE1_H`, đối với xử lý nhiều file thì việc khai báo cho file main.c sẽ tốn rất nhiều bộ nhớ.

_VD1:_ Ta có 3 file
     
          file1.c

          file2.c

          main.c 

➡️ Để sử dụng các biến của 1 và 2, ta khai báo `extern int a;` hoặc `extern int b;`.

## 2. Static

### 2.1 Satic - local variables(bss & data)

> Được sử dụng, giới hạn phạm vi trong 1 hàm. 
>
> Giữ lại giá trị sau những lần gọi hàm, địa chỉ tổn tại trong suốt chương trình.
>
> Static cục bộ không thể thay đổi giá trị bên ngoài, nếu muốn thay đổi thì sử dụng con trỏ.

_VD2: Static biến cục bộ_

```c
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
```c
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

> Giới hạn phạm vị sử dụng trong 1 file, không thể liên kết file (các file khác không dùng Extern để gọi ra được). 
>
> Không thể dùng con trỏ để thay đổi giá trị.

**- Ưu điểm:** Sử dụng static toàn cục để ẩn ở quá trình trung gian tính ra kết quả. Như tính delta trong phương trình bậc 2.

### 2.3 Satic - class (hướng đối tượng trong C++), học sau

## 3. Volatile

**Biến volatile là gì?** Khai báo biến mà biến này không sử dụng, tránh bị complier tối ưu hóa xóa cái biến này đi.

> Dùng trong code cho MCU, ép buộc 1 biến truy cập đến địa chỉ và nó không bị xóa khỏi bộ nhớ khi biến đó k được sử dụng.

```c
     // Dùng trong code VDK

     #include "stm32f4xx.h"
     volatile unit8_t var = 0;

```

**Ứng dụng:** Đọc giá trị cảm biến nhiệt độ nhiệt độ, ví dụ có 10 giá trị 30 độ C giống nhau, thì có nguy cơ biến CB nhiệt độ bị xóa khỏi bộ nhớ. Vì vậy, sử dụng biến Volatile đảm bảo cảm biến nhận đúng giá trị không bị cấp thoát, hạn chế sai số.

## 4. Register

![](https://github.com/hthuan02/C_Cpp_Advance/blob/main/C_Advance/Bai4_Extern_Static_Volatile_Register/img/register.png)

Khi thực thi 1 chương trình sẽ trải qua 4 giai đoạn:

**(1):** Lưu trữ từ trong bộ nhớ RAM, thực hiện tính toán.

**(2):** Thao tác tính toán các giá trị.

**(3):** Tính xong thì lưu giá trị trong thanh ghi.

**(4):** Lấy giá trị trong thanh ghi trả về biến trong RAM, kết quả = 6.


**Ứng dụng của biến register:**

- Khai báo biến register, thì chương trình chỉ thực hiện tính toán và lưu giá trị trên thanh ghi( bị lượt bỏ 2 bước đầu-cuối: Lưu trữ trên RAM và trả kqua từ thanh ghi lên RAM). Giúp rút ngắn thời gian chạy và tăng hiệu suất làm việc của chương trình.
     
- Chỉ sử dụng cho biến cục bộ.

</details>

<details>
  <summary><h3> Bài 5: Goto - setjmp.h</h3></summary>

## I. Goto
>Cho phép đoạn code nhảy đến label(nhãn) mà mình chỉ , label có để đặt bất cứ vị trí nào trong cùng 1 hàm.

- _VD1: Tạo Menu sử dụng lệnh Goto_
   
```c
  #include<stdio.h>

  int main(int argc, char const *argv[])
  {
    int option;
    menu1:
    do{
      printf("Menu1\n");
      printf("1: Tao ra menu thu ....\n");
      printf("2....\n");
      printf("3....\n");
      printf("%d....\n",option);
    } while(option != 1);

  switch (option){
    case 1:
      printf("Menu2\n");
      printf("0: Quay lai Menu 1\n");
      printf("1: Ket thuc chuong trinh\n");
      printf("2....\n");
      scanf("%d",&option);
      break;
    
      switch (option){
        case 0:
          /* goto <label> */
          goto menu1;
        case 1:
          goto thoatchuongtrinh;
        case 2:
          break;
        }
        break;

        case 2:
          /* code */
        break;

      case 3:
        /* code */
      break;

      default:
        break;         
    }
    thoatchuongtrinh:
    return 0;
  }
```

   - Chương trình chạy tuần tự từ Menu1 đến Menu2. Nhưng ở Menu2 có 2 Option:
      - `case 0:`: Dùng lệnh `goto menu1;` và đặt lệnh `menu1:` ở đầu Menu1, chương trình sẽ trở về Menu1.
      - `case 1`: Lệnh `goto thoatchuongtrinh;` và đặt lệnh `thoatchuongtrinh:` ở cuối, chỉ định chương trình thoát ra khỏi switch để kết thúc chương trình.
  
## Nhược điểm của Goto:
-  Vì chương trình không chạy tuần tự, nên code khó đọc, khó quản lý và bảo trì.
-  Khó debug, vì khó xác định được vị trí gây lỗi.

## Ưu điểm:

### 1. Thoát khỏi nhiều cấp độ vòng lặp
   
>Đối chương trình nhiều cấp độ vòng lặp, mình muốn thoát ra thì phải xét điều kiện và break để thoát chương trình, sẽ phức tạp.

_- VD2:_
   
```c
   int i,j;

   while(1){
      for(i=1; i<5; i++ ){
         for(j=1; j<5; j++ ){
            if (i == 2 && j == 3){
               printf("break for j\n");
               break; //Chi thoat duoc For cua j 
            }
         if (i == 2 && j == 3){
               printf("break for i\n");
               break; //Thoat duoc For cua i 
            }
         }
      }
      if (i == 2 && j == 3){
         printf("break while \n");
         break; //Thoat duoc For cua while       
      }
   } 
```
- Sử dụng `goto` để thoát chương trình nhanh hơn.

```c
   int i,j;

   while(1){
      for(i=1; i<5; i++ ){
         for(j=1; j<5; j++ ){
               if (i == 2 && j == 3){
               printf("Thoat chuong trinh\n");
               goto thoat; //1 lenh goto, thoat duoc 3 vong lap
         }
      }
   thoat: 
   return 0;
   }
```
### ỨNG DỤNG
 Dùng trong Led ma trận, kết hợp với thuật toán quét led.

## II. Thư viện <setjmp.h>
> Cho phép chương trình có thể nhảy từ nhãn đặt trong hàm này sang nhãn đặt trong hàm khác thông qua setjmp và longjmp.
>
> Thư viện setjmp.h bao gồm 2 hàm setjmp và longjmp.
>
> Xử lý ngoại lệ 

### 1. Hàm setjmp
```c
   int setjmp(jmp_buf);
```

- Khi gọi `setjmp` lần đầu, thì mặc định trả về 0.

### 2. Hàm longjmp
```c
   longjmp(jmp_buf, int value);
```

- Khi gọi `longjmp` thì luồng của chương trình sẽ nhảy về `setjmp`. Sau đó, gán giá trị của `int value` vào giá trị mới của `setjmp`

_- VD3:_


### 3. Xử lý ngoại lệ(TRY, CATCH, THROW)

</details>


<details>
  <summary><h3>Bài 7: Struct & Union</h3></summary>

## 1. Struct

> Struct là 1 dạng kiểu dữ liệu, cho phép người dùng tự định nghĩa. Nhóm các kiểu dữ liệu như: int, char, double,... lại thành kiểu dữ liệu mới. 
>
> Kích thước của Struct = Tổng các kích thước dữ liệu + padding 


```c
    #include <stdio.h>
    #include <stdint.h> // Thư viện để sử dụng uint32_t, uint8_t, uint16_t

    struct Data {
      int a;
      double b;
      char c;
    };

    struct Data data1, data2, data3;

```

hoặc:
```c
    typedef struct Data{
      int a;
      double b;
      char c;
    } Data;

    Data *data1, data2, data3;

```

- Trong hàm `main.c` thì `data.a = 0;`
- Đối với con trỏ `*ptr` thì `data ->a = 0;`

_VD1:_

```c
    #include <stdio.h>
    #include <stdint.h> // Thư viện để sử dụng uint32_t, uint8_t, uint16_t

    typedef struct {
      uint32_t var1;
      uint8_t var2;
      uint16_t var3;
    } data; // Tên kiểu dữ liệu là data

    int main(int argc, char const *argv[]) {
      printf(" Size of data: %d\n");
      data data;

      printf("Address of var1: %p\n", &data.var1);
      printf("Address of var2: %p\n", &data.var2);
      printf("Address of var3: %p\n", &data.var3);

      return 0;
    }
```
## Data alignment & padding

- Data alignment: Là việc canh chỉnh, sắp xếp dữ liệu được sắp xếp dữ liệu vào đúng kích thước của CPU (gồm 2 byte, 4 byte, 8 byte,..). Đảm bảo hiệu suất hoạt động của bộ nhớ, dễ dàng truy cập và xử lý nhanh hơn.

- Padding(đệm vào): Khi canh chỉnh, sắp xếp bộ nhớ còn dư ra 1 vài byte trên tổng số ổ đĩa thì đó là padding.

```c
    //double(8byte): Chia het 8, 0x00 0x08 0x10 0x18,..
    //int, int32_t, uint32_t(4byte): 0x00 0x04 0x08 0x0C...
    //float, init16_t, uint16_t(2byte): 0x00 0x02 0x04 0x06...
    //padding
```
➡️ Kích thước của Struct = tổng các kiểu dữ liệu + padding
  
**_VD2: Tìm kích thước struct VD1_**

```c
    typedef struct {
      uint32_t var1; //Chia hết cho 8 (4byte) 
      uint8_t var2; //1byte
      uint16_t var3; //2byte
    } data;
```
- Giải thích: Ưu tiên kích thước dữ liệu lớn nhất làm chuẩn (4byte).
    - var1 (4byte)

    - var2 (1byte) + var3 (2byte) = 3 byte (dư 1 byte) -> 1 padding

    - Tổng = 8

**_VD3: Tìm kích thước_**

```c
      uint8_t var1[9]; //1byte 
      uint64_t var2[3]; //8byte
      uint16_t var3[10]; //2byte
      uint32_t var4[2]; //4byte

```

- Giải thích:
    - Kích thước lớn nhất là 8 byte.
    
    - var1: 8byte(làm chuẩn) + (1byte lẻ + 7padding) = 16  
    
    - var2: 8byte *3 = 24
    
    - var3: 8byte *2 + (4byte lẻ + 4padding) = 24
    
    - var4: 8byte
    
    - Tổng kích thước = 72 byte

### Ứng dụng của Struct: 
    
- Json
- Cấu trúc dữ liệu list
- Giao thức trong MCU, mỗi thông số đều có cấu hình khác nhau -> Dùng Struct để gom các thông số về.

## 2. Union

>
> Giống với struct, đây là kiểu dữ liệu người dùng tự định nghĩa bằng cách nhóm các kiểu dữ liệu lại.
>
> Union sử dụng chung vùng nhớ, các thành phần đều chung địa chỉ -> Giá trị này thay đổi thì những giá trị khác sẽ thay đổi.
>
> Kích thước Union = Tổng member có kích thước lớn nhất + padding.

**_VD4: Kiểm tra kích thước của Union_**
```c    
#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t var1; // 1byte
    uint32_t var2; // 4 byte
    uint16_t var3; // 2 byte

    // Union sẽ lấy kiểu dữ liệu có kích thước lớn nhất 24 byte
} frame;

int main(int argc, char const *argv[])
{

    printf("Size = %d\n", sizeof(frame)); //Kích thước lớn nhất 4byte
    frame data;

    data.var1 = 5;
    data.var2 = 6;
    data.var3 = 7;
    //Vì dữ liệu kiểu Union-> SD chung vùng nhớ
    //Lấy data sau cùng
    printf("Var1 = %d\n", data.var1);   //7
    printf("Var2 = %d\n", data.var2);   //7
    printf("Var3 = %d\n", data.var3);   //7
    return 0;
}
```

**Trường hợp đặc biệt của VD4:**

```c
    int main(int argc, char const *argv[])
    {
    
        printf("Size = %d\n", sizeof(frame));
        frame data;

        data.var2 = 4294967294;

        printf("Var1 = %d\n", data.var1); //254   
        printf("Var2 = %u\n", data.var2); //4294967294
        printf("Var3 = %d\n", data.var3); //65534
        return 0;
    }
```

- Giải thích:
    - Vì `data.var2 = 4294967294;` chuyển sang binary = 11111111 11111111 11111111 11111110
    
    - Địa chỉ bắt đầu, 0x01 lưu byte thấp nhất.
  
        | 0x01 | 0x02 | 0x03|0x04|
        | :---: | --- | ---: | ---: |
        | 11111110 | 11111111 | 11111111 | 11111111 |
        | 254 | 65535 | 65535 | 65535 |

    -  var1: 1byte = 254 (0x01)
  
    -  var2: 4byte = 4294967294 (4 ô địa chỉ)

    -  var3: 2byte = 65534 (0x01+0x02)

</details>

<details>
  <summary><h3>Bài 8: Memory Layout</h3></summary>

- Memory Layout: Là sự tổ chức và sắp xếp các vùng nhớ (chứa mã lệnh, biến, và dữ liệu) trong bộ nhớ RAM khi chương trình thực thi.  

- Gồm có 5 phân vùng bộ nhớ, theo thứ tự từ trên xuống:

    <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/C_Advance/Bai8_Memory-layout/img/memorylayout.png" alt="Memory Layout" width="500"/>

## 1. Text segment

> Chỉ có quyền đọc, không thể ghi(chỉnh sửa).
>
> lưu các giá trị const, char *ptr.

_- VD1:_
```c
    int const a = 10;

    int main(int argc, char const *argv[])
    {
        /*Code*/
        return 0;
    }
```
và:

```c
    char *str = "hello word";

    int main(int argc, char const *agrv[])
    {
        printf("String: %s\n", *str);
        return 0;
    } 
```
- Cả 2 chương trình trên chỉ có thể đọc (Read Only), không thể thay đổi giá trị.

## 2. Initialized Data (DS)
(Khởi tạo dữ liệu)

> Gồm các biến toàn cục, giá trị khác 0.
>
> Biến Static (global + local) khác 0.
> 
> Có thể đọc và ghi giá trị (Read + Write).

_VD2:_

```c
    #include <stdio.h>

    int a = 5;
    static int b = 6; // Lưu ở data (Static global)
    void *ptr = &b;   // Data

    void test()
    {
        static int c = 7; // Static local
    }

    int main(int argc, char const *ptr[])
    {
        a = 15;
        b = 16;
        printf("a=%d\n", a);
        printf("b=%d\n", b);
        return 0;
    }
```
- Trong chương trình trên, có thể đọc và thay đổi giá trị a b. Nếu muốn thay đổi giá trị c, thì phải dùng *ptr.

## 3. Unintialized Data (Bss)
(Dữ liệu không được khởi tạo)

> Biến toàn cục giá trị = 0 hoặc NULL(không gán giá trị).
>
> Static(global + local) =0.

_VD3:_

```c
    #include <stdio.h>

    typedef struct
    {
        int x;
        int y;
    } Point_data;

    Point_data p1 = {5, 7}; // data
    Point_data p2;          // bss

    int a = 0; // bss
    int b = 5; // data

    static int m = 0; // bss
    static int n;     // bss

    void test()
    {
        static int c = 0; // bss
        static int d;     // bss
    }

    int main(int argc, char const *argv[])
    {
        /*code*/
        return 0;
    }
```
## 4. Stack segment

> Chứa biến cục bộ (trừ static cục bộ).
>
> Có thể đọc và ghi.
>
> Sau khi kết thúc 1 lần gọi hàm  địa chỉ của biến cục bộ bị thu hồi LIFO(Last In - First Out) 

_VD4:_

```c
    #include <stdio.h>

    int total(int a, int b)
    {
        int c; //stack
        c = a + b;
        return c;
    }
    
    int main(int argc, char const *argv[])
    {
        printf("a+b = %d\n", total(5, 6));
        return 0;
    }
```
➡️➡️➡️ Để đọc và ghi dữ liệu ở biến cục bộ, phân vùng stack thì dùng `*ptr`.

_VD5:_

```c
    #include <stdio.h>

    int *ptr = NULL;
    void test()
    {
        const int a = 10; // stack -> cục bộ
        ptr = &a;
    }

    int main(int argc, char const *argv[])
    {
        test();
        *ptr = 20;
        printf("a= %d\n", *ptr); // a=20, thay đổi được giá trị nhưng WARNING!!
        return 0;
    }
```

## 5. Heap segment

> Dùng để cấp phát động bộ nhớ.
>
> Đi kèm với các hàm như: malloc(), calloc(), realloc(), free().
>
> Khai báo thư viện `#include<stdlib.h>`.

**Cấp phát động là gì?**
- Ví dụ khai báo 1 mảng có 12 kí tự `char array[12]`, nhập tên từ bàn phím vào mảng này
    - Nếu kí tự nhập vào > 12: xảy ra hiện tượng tràn bộ nhớ.

    - Nếu kí tự nhập vào < 12: xảy ra hiện tượng lãng phí bộ nhớ.

--> Trong ngôn ngữ C, sinh ra khái niệm cấp phát động để tối ưu bộ nhớ. Tránh việc tràn hoặc lãng phí bộ nhớ.

# HEAP SEGMENT (Cấp phát động)

**Lưu ý:**
- Khai báo thư viện khi bắt đầu chương trình: `#include<stdlib.h>`
- Giải phóng bộ nhớ đã cấp phát khi kết thúc chương trình: `free(ptr)`
  
## I. Các hàm cấp phát động

### 1. Hàm Malloc()

> `malloc`: Cấp phát bộ nhớ động, không khởi tạo giá trị.
>
> Giá trị của hàm trả về là 1 `*void`, cần ép kiểu dữ liệu.
>
> Giá trị trong ô nhớ được cấp phát là 1 giá trị random(giá trị rác).

```
   ptr = (cast_type*)malloc(byte_size);
```

- `ptr`: Con trở lưu trữ ô nhớ đầu tiên của vùng nhớ cấp phát.
- `cast_type`: Kiểu con trỏ muốn ép kiểu sang.
- `byte_size`: Kích thước byte cần cấp phát.

_VD1:_

```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char const *argv[])
    {
        // Cấp phát vùng nhớ mảng 100 phần tử int
        // sizeof(int) = 4
        int *a = (int *)malloc(100 * sizeof(int)); // 400

        // Cấp phát vùng nhớ mảng 1000 phần tử char
        // sizeof(char) = 1
        char *c = (char *)malloc(1000 * sizeof(char)); //1000
        return 0;
    }
```
- Trường hợp không cấp phát đủ vùng nhớ, thì `malloc()` sẽ trả về con trỏ NULL.

_VD2:_
```c
    #include <stdio.h>
    #include <stdlib.h>

    int main(int argc, char const *argv[])
    {
        int n = 10;
        int *a = (int *)malloc(n * sizeof(int)); //vùng nhớ 40 byte
        if (a == NULL)
        {
            printf("Cap phat khong thanh cong !\n");
        }
        else
        {
            int i = 0;
            printf("Cap phat thanh cong !\n");
            for (i = 0; i < n; i++)
            {
                a[i] = 28 + i; // *(a + i) = 28 cũng được
            }
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]); // 28 29 ... 37
            }
            free(a); // Hàm giải phóng vùng nhớ
            printf("\nGiai phong thanh cong !\n"); 
        }
        return 0;
    }

```
- Giải thích:

/*
ban đầu  int = 0

0    1    2    3....9

28 29 30 31...37

40 (byte cấp phát malloc) - 10 byte(sử dụng) = (dư) 30 byte 

--> Nhưng vì sử dụng hàm malloc(Cấp phát động).

--> Nên không xảy ra hiện tượng lãng phí bộ nhớ khi dư 30 byte.
*/

### 2. Hàm Calloc()

> Hàm cấp phát bộ nhớ động tương tự `malloc`, `calloc` có khởi tạo tất cả vùng bộ nhớ về giá trị 0.
>
```c
    ptr = (cast_type*) calloc(n, element_size)
```
- `ptr`: Con trỏ đầu tiên của vùng nhớ được cấp phát.

- `cast_type*`: Kiểu con trỏ muốn ép kiểu.

- `n`: Số lượng phần tử muốn cấp phát.
- `element_size`: Kích thước 1 phần tử(byte).

_VD3:_
```c
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        int n = 10;
        int *a = (int *)calloc(n, sizeof(int));
        if (a == NULL)
        {
            printf("Cap phat khong thanh cong !\n");
        }
        else
        {
            int i = 0;
            printf("Cap phat thanh cong !\n");
            printf("Mang ban dau : ");

            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            for (i = 0; i < n; i++)
            {
                a[i] = 28 + i; // *(a + i) = 28 cũng được
            }
            printf("\nMang sau khi thay doi : ");
            for (i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
            free(a); // Hàm giải phóng vùng nhớ
            printf("\nGiai phong thanh cong !\n"); 
        }
        return 0;
    } 
```

**Giải thích:**
- Cách thức hoạt động của `calloc()` tương tự `malloc`, nhưng 10 giá trị ban đầu
của mảng là 0:  0  0  0  0  0  0  0  0  0  0  0

- Mảng  sau khi thay đổi là: 28 29 30   ...   37

### 3. Hàm Realloc()

> Là hàm cấp phát lại, có thay đổi kích thước của vùng nhớ đã cấp phát trước đó.

```c
    ptr = (cast_type*)realloc(ptr,new_size)
```

- `ptr`: Con trỏ đến vùng nhớ đã được cấp phát trước đó.

- `new_size`: Kích thước mới của bộ nhớ cần thay đổi.

_VD4:_

```c
    //Cấp phát mảng 10 phần tử, kích thước 40byte 
    int *array = (int *) malloc(10 * sizeof(int));

    //Thay đổi, tăng kích thước mảng lên 20 phần từ, 80byte
    array = (int *) realloc(array, 10 * sizeof(int));  

    free(array); //Giải phóng bộ nhớ
```

## III. So sánh malloc, calloc và realloc

| Đặc điểm               | `malloc`                                       | `calloc`                                         | `realloc`                                      |
|-----------------------|------------------------------------------------|-------------------------------------------------|------------------------------------------------|
| **Công dụng**         | Cấp phát bộ nhớ động, không khởi tạo giá trị                           | Cấp phát bộ nhớ động và khởi tạo về 0          | Thay đổi kích thước vùng nhớ đã được cấp phát |
| **Cú pháp**           | `void* malloc(byte_size);`                  | `void* calloc(n, element_size);`     | `void* realloc(void *ptr, new_size);`     |
| **Tham số**           | Một tham số (kích thước bộ nhớ cần cấp phát)  | Hai tham số (số phần tử và kích thước mỗi phần tử) | Hai tham số (con trỏ đến vùng nhớ cũ và kích thước mới) |
| **Giá trị khởi tạo**  | Không khởi tạo, dữ liệu là rác                 | Khởi tạo tất cả phần tử về 0                     | Không khởi tạo, dữ liệu giữ nguyên (có thể mất dữ liệu mới nếu mở rộng) |
| **Kích thước**        | Cấp phát bộ nhớ theo kích thước được chỉ định  | Cấp phát bộ nhớ cho số phần tử × kích thước phần tử | Cấp phát hoặc thu nhỏ bộ nhớ theo kích thước mới |
| **Trả về**            | Con trỏ đến vùng nhớ đã cấp phát hoặc `NULL`  | Con trỏ đến vùng nhớ đã cấp phát hoặc `NULL`   | Con trỏ đến vùng nhớ đã thay đổi hoặc `NULL`  |

- Kết thúc chường trình phải có hàm `free(ptr)`: Để thu hồi, reset lại vùng nhớ.


# STACK & HEAP SEGMENT

<img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/C_Advance/Bai8_Memory-layout/img/stack_heap.png" alt="Memory Layout" width="220"/>

## So sánh giống và khác nhau:

### 1. Giống nhau:

1. **Lưu trữ dữ liệu**: Đều dùng để lưu trữ dữ liệu.
2. **Nhiều kiểu dữ liệu**: Có thể lưu trữ nhiều kiểu dữ liệu.
3. **Nằm trong RAM**: Nằm trong bộ nhớ RAM khi chương trình chạy.
4. **Ảnh hưởng đến hiệu suất**: Cách quản lý bộ nhớ trong cả Stack và Heap có thể ảnh hưởng đến hiệu suất chương trình.
5. **Có thể bị tràn bộ nhớ**: Stack overflow và Heap overflow đều có thể xảy ra nếu không quản lý đúng cách.

### 2. Khác nhau:

- Lập bảng so sánh

| **Tiêu chí**              | **Stack**                                                                 | **Heap**                                                          |
|---------------------------|---------------------------------------------------------------------------|-------------------------------------------------------------------|
| **Lưu trữ**              | Lưu biến cục bộ, tham số hàm.                                              | Lưu trữ vùng nhớ cấp phát động như: malloc(), calloc(), realloc().                                   |                                      |
| **Tốc độ**                | Nhanh.                                                                    | Chậm hơn Stack.                                                   |
| **Giải phóng**            | Tự động khi hàm kết thúc.                                                 | Sử dụng hàm `free()` hoặc `delete`.                                 |
| **Tràn bộ nhớ**           | Stack overflow khi dùng quá nhiều bộ nhớ.                                 | Heap overflow khi không giải phóng hoặc cấp phát quá lớn.         |
| **Kích thước**            | Cố định (nhỏ hơn).                                                        | Linh hoạt (lớn hơn).                                              |
| **Thời điểm cấp phát**    | Lúc biên dịch.                                                            | Lúc chạy chương trình.                                            |
| **Rò rỉ bộ nhớ**          | Không xảy ra.                                                             | Có thể xảy ra nếu không giải phóng.                               |

### 3. Stack overflow & Heap overflow

- **Stack overflow**: Do bộ nhớ Stack cố định, nếu sử dụng quá nhiều sẽ gây tràn bộ nhớ (Stack overflow), ví dụ như khởi tạo quá nhiều biến cục bộ hoặc đệ quy vô hạn.

_VD1: Gọi hàm mà không có điều kiện dừng_

```c
    int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
    }
```

- **Heap overflow**:
    - Nếu không giải phóng bộ nhớ, bằng hàm `free()` hoặc `delete` sẽ gây tràn bộ nhớ (Heap overflow).
    - Khởi tạo vùng nhớ quá lớn mà Heap không đủ cũng sẽ gây lỗi.

_VD2: Khởi tạo vùng nhớ quá lớn_

```c
    int *A = (int *)malloc(18446744073709551615);
```

</details>

<details>
  <summary><h3>Bài 10: Liked list</h3></summary> 

- Liked list (danh sách liên kết): Là cấu trúc dữ liệu gồm chuổi các node(nút) liên kết với nhau, mỗi node gồm 2 thành phần: Data và con trỏ (*Next).

  _VD0:_ Cho mảng `int array[] = {2,7,4,5,3};`

- Dùng Malloc:
  
        // Malloc(); //Lưu trữ 5 phần tử * sizeof(int)= (20byte)

        // Free():

        // Thêm - Thu hồi phần tử bằng cách thủ công, nhưng đối với array[10000] thì không thể làm thủ công được.

  ➡️➡️➡️➡️➡️
- Liked list: Tạo 5 node

    <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/C_Advance/Bai10_Linked-List/liked_list.png" alt="Memory Layout" width="800"/>

    - Trong danh sách liên kết này có thể thêm hoặc thu hồi tùy ý các phần tử.
 
    - Liked LIST còn có thể sử dụng ở quy mô lớn hơn như array[10000].
 
    - Các hàm sử dụng của danh sách dữ liệu LIST:

    ```
        node *createNode(int value); //Tạo 1 node mới, có giá trị value và trả về con trỏ node
        void push_back(node** array, int value); //Thêm 1 node mới có giá trị value vào cuối danh sách 
        void push_front(node **array, int value); //Thêm 1 node có giá trị value đầu danh sách
        void pop_back(node **array); //Xóa node cuối danh sách 
        void pop_front(node **array); //Xóa node đầu danh sách 
        int front(node *array); //Lấy giá trị của node đầu tiên
        int back(node *array); //Lấy giá trị của node cuối cùng
        void insert(node **array, int value, int pos); //Thêm 1 node vào một vị trí bất kỳ(int pos là vị trí)
        void delete_list(node **array, int pos); //Xóa 1 node ở vị trí bất kỳ
        int size(node *array); //Lấy kích thước node của danh sách
        int get(node *array, int pos); //Lấy giá trị của node(tại pos) của danh sách

        bool empty(node *array); // kiem tra list co rong hay khong
        //Không có hàm kiểm tra đầy, vì nó k quan tâm đến số lượng
    ```
    **Ứng dụng: Liked List giúp quản lý danh sách tốt hơn mảng.**
  
</details>

<details>
  <summary><h3>Bài 11: Stack - Queue</h3></summary> 

## I. Stack
(Last in - First Out) --> Ngăn xếp

- Phần vào sau cùng thì lấy ra tước tiên và ngược lại.

- Gồm 3 thao tác:

      - push: Thêm phần tử vào ở đỉnh stack(top++)
  
      - pop: Xóa 1 phần tử đỉnh stack(top--)
  
      - top: giá trị phần tử của đỉnh (Maxtop = size -1)


## II. Queue
(First in - First out) --> Hàng đợi 

- Phần tử vào đầu thì ra đầu, vào cuối thì ra cuối

- Gổm 3 thao tác:

      - enqueue: Thêm phần tử cuối hàng đợi (rear++)
  
      - dequeue: Lấy(loại bỏ) phần tử đầu hàng đợi (front++)

      - front: Lấy giá trị phẩn tử đầu hàng đợi

      - rear: Lấy giá trị phần tủ cuối hàng đợi

Ngoài ra, nếu rỗng:

- Max_front = Max_rear = size -1 

- enqueue = -1

- dequeue = -1

### 1. Linear Queue (hàng đợi tuyến tính)

> Các phần tử được sắp xếp theo thứ tự tuyến tính, tức là mỗi phần tử đứng sau phần tử khác trong một hàng dọc.

### 2. Circular Queue (hàng đợi vòng tròn)

> Phần tử cuối cùng của hàng đợi được kết nối với phần tử đầu tiên, tạo thành một vòng tròn.

</details>

<details>
  <summary><h3>Bài 12: Binary Search</h3></summary>

## 1. Binary Search
(Thuật toán tìm kiếm nhị phân)

_VD:_

```c
    int arr[]= {13,11,15,30,18,16,21,25,20}
```
**Tìm ID: 25** (Dùng thuật toán tìm kiếm tuyến tính-LinearSearch)

- Tìm ID duyệt từng phần tử

- So sánh từng phần tử với số 25

**Nhược điểm:** Đối với mảng lớn thì số lần lặp lại tìm kiếm nhiều lần: tốn bộ nhớ, tốn thời gian. 

  ===>>>Để khắc phục thì dùng Binary Search

</details>

# Phần II: C++
---
<details>
  <summary><h3>Bài 13: Class</h3></summary>

## 1. Định nghĩa
Kiểu dữ liệu người dùng tự định nghĩa (tương tự struct & union).

```cpp
    class SinhVien{

    };
```

- không khai báo typedef cho class
 
## 2. Phạm vi truy cập

- Phục vụ tính chất hướng đối tượng(biến, hàm, mảng)
- Private  ->> Tính đóng gói
- Protected ->> Tính kế thừa
- Public ->> tính trừu tượng 

### 2.1 Class public

Phạm vi Public: Khi khai báo 1 object từ bên ngoài thì có thể tự do truy cập, thay đổi và đọc những thành phần bên trong phạm vi public (property, method).

Có 2 cách khai báo method(hàm)

- Cách 1: Khai báo method và nội dung của method trong Class

```cpp
#include <iostream>

using namespace std;

// Bên trong class không gọi là biến, hàm, mảng
class HinhChuNhat
{
public:
    double chieuDai;  // property: thuộc tính (biến/mảng)
    double chieuRong; // property: thuộc tính
    void DienTich()
    { 
        // method: phương thức (hàm)
        cout << "Dien tich = " << chieuDai * chieuRong;
    }
};

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn; // object: đối tượng(hcn là đối tượng thuộc class HinhChuNhat)
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```

- Cách 2: Khai báo method trong Class, nội dung để ở ngoài.

```cpp
#include <iostream>

using namespace std;

// Bên trong class không gọi là biến, hàm, mảng
class HinhChuNhat
{
public:
    double chieuDai;  // property
    double chieuRong; // property
    void DienTich(); // method
};

void HinhChuNhat::DienTich() // :: là toán tử truy cập 
{
    cout << "Dien tich = " << chieuDai * chieuRong << endl;
}

int main(int argc, char const *argv[])
{
    HinhChuNhat.hcn; // object
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```

#### Lưu ý: 
- Tương tự với struct & union, biến thì có địa chỉ. Khi khai báo 1 object thì Complier sẽ cấp địa chỉ để lưu những thành phần bên trong nó 

```cpp
int main(int argc, char const *argv[])
{
    HinhChuNhat.hcn; // object // 0xc0
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```

- Sau đó, object vào bên trong Class cấp địa chỉ cho các property, từ property đầu tiên. 

```c
class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0xc7: 8byte
    double chieuRong; // property // 0xc8 - 0xcf
    void DienTich(); // method
};
```

### 2.2 Constructor
(Trong class có 1 method đặc biệt là Constructor, giúp khởi tạo giá trị cho property từ trong Class)

> Là method trùng tên với tên class.
>
> Được khai báo trong 3 phạm vi (public, private, protected).
>
> **Tự động khởi chạy** khi khai báo 1 object: Có 4 cách khai báo constructor.

- Cách 1: Truy cập vào property từ bên ngoài.

```cpp
int main(int argc, char const *argv[])
{
    HinhChuNhat.hcn; // object  
    hcn.chieuDai = 10;
    hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
```
- Cách 2,3,4 Contructor

```cpp
    class HinhChuNhat{
        public:
            double chieuDai; 
            double chieuRong; 
            void DienTich();

            //Cách 2: Constructor không có tham số truyền vào
            // HinhChuNhat(){
            //     chieuDai = 20;
            //     chieuRong = 30;
            // }

            //Cách 3: Constructor có tham số truyền vào, không có tham số mặc định
            // HinhChuNhat(int dai, int rong){
            //     chieuDai = dai;
            //     chieuRong = rong;
            // }

           // Cách 4: Viết kiểu khác của cách 3, có tham số mặc định 
           HinhChuNhat(int dai = 5, int rong = 10): chieuDai(dai), chieuRong(rong){
                DienTich();
           }
    }; 

    void HinhChuNhat::Dientich(){
        cout << "Dien tich = " << chieuDai * chieuRong <<endl;
    }

    int main()
    {
        HinhChuNhat hcn(15,10); // object //150
        HinhCHuNhat hcn1; // Ghi đè lên 150, là 50
        // hcn.chieuDai = 10;
        // hcn.chieuRong = 20;  
        // hcn.DienTich();
        return 0;
    }
```
### 2.3 Destructor

> Cùng là method có tên trùng với tên Class, nhưng có thêm dấu `~` ở trước.
>
> Có thể nằm ở bất kỳ phạm vi nào (public, private, protected).
>
> Tự động khởi chạy khi tạo ra 1 object.

- Chạy Constructor trước, Destructor thực hiện cuối sau khi thực hiện các thao tác khác xong hết.

- Thu hồi lại object.

**Ứng dụng**:

- Cấp phát động cho 1 con trỏ.

- Khi sử dụng xong con trỏ, thay vì gán NULL. Mình có thể tự động thu hồi vùng nhớ bằng hàm Destructor.

_VD: Cách thức hoạt động của Constructor vs Destructor_

->> Hoạt động theo kiểu Stack(Last In-First Out)

### 2.4 Static trong Class

#### Static property

```cpp


#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7  object1 // 0x00 - 0x07   object2
    double chieuRong; // property // 0xc8 - 0xcf         // 0x08 - 0x0f
    // int var;       // property // 0xd0 - 0xd3         // 0x10 - 0x13

    /* Static
     * - Địa chỉ của biến static sẽ tồn tại xuyên suốt chương trình.
     * - Để sử dụng thì phải cấp phát địa chỉ thông qua truy cập từ class.
     * - Tất cả object khác vùng địa chỉ sẽ được sử dụng chung biến var.
     */
    static int var; // property // 0xa0 - 0xa3 (chung cho cả 2object)
};

int HinhChuNhat::var; // Truy cập từ trong class, không cần object. Để cấp phát địa chỉ dùng chung biến var

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1;
    HinhChuNhat hcn2;

    cout << "Address of var: " << &hcn1.var << endl; // &: C++ là tham chiếu
    cout << "Address of var: " << &hcn2.var << endl;
    return 0;
}
```

#### Static method

- Giống với static property, đều thuộc chung class -> Không cần khai báo object để gọi nó ra. Gọi trực tiếp bằng tên của Class.

- Static method chỉ gọi ra được property đi kèm với Static, không thể gọi property khác.


```cpp

#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7     // 0x00 - 0x07   object2
    double chieuRong; // property // 0xc8 - 0xcf    // 0x08 - 0x0f
    static int var;   // property // 0xa0 - 0xa3

    static void display()
    {
        cout << "This is static method" << endl;
        var = 20;
    }
};

int HinhChuNhat::var;

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1;
    HinhChuNhat hcn2;

    HinhChuNhat::display();
    return 0;
}
```

#### Lưu ý:

- Cả 2 đều truy cập từ trong Class, không cần truy cập object.

- **static property**: Truy cập vào bên trong  Class, để cấp phát địa chỉ tồn tại xuyên suốt chương trình. Tất cả object khai báo ra sẽ dùng chung địa chỉ này.

- **static method**: Chỉ làm việc được với static property.


</details>

<details>
  <summary><h3>Bài 14: OOP</h3></summary>

#### Phạm vi truy cập:

> **Public**: method, property bên trong và object bên ngoài có thể truy cập.
>
> **Protected**:  
>    - Object bên ngoài không thể truy cập method, property (giống private).
>    - Class con kế thừa có thể truy cập(trong nội bộ class concon).
>
> **Private**: 
>    - Class con kế thừa không thể truy cập (chỉ có phạm vi trong nội bộ class chacha: method, property trong nội bộ class mới truy cập được)

<details>
  <summary><h3>Part 1: Encapsulation - Tính đóng gói</h3></summary>
  
> Đóng gói Là ẩn đi các property "mật" khỏi người dùng.
>
> Là khai báo property trong phạm vi private. Các object bên ngoài không thể gọi ra được.
>
> Khi muốn đọc hoặc ghi có property này, thì truy cập gián tiếp thông qua method phạm vi public.

## Phạm vi private:

- Chỉ có giá trị trong nội bộ class (chỉ những method bên trong mới truy cập được property của private).

- Object không thể truy cập tới.

_VD: Khắc phục việc truyền 1 chuỗi vào object, không kiểm tra được cái chuỗi này có hợp lệ hay không._

```cpp
#include <iostream>

using namespace std;

class SinhVien
{
public:
    string ten;
    string id;
    int age;

    SinhVien(string ten, string id, int age) : ten(ten), id(id), age(age)
    {
    }
    void display()
    {
        cout << "Tên: " << ten << endl;
        cout << "ID: " << id << endl;
        cout << "Age: " << age << endl;
    }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1("Huỳnh Minh Thuận123@", "hthuan02", 22);
    sv1.display();
    return 0;
}
```

->> Chuỗi `Ten` truyền vào ở object `sv1` không hợp lệ.

### Lưu ý:

- Khi viết thêm method để kiểm tra chuỗi thì không khởi tạo thông qua Constructor mà tạo method khác như: `setter method`, `getter method`.

_Khắc phục VD1:_

```cpp
#include <iostream>

using namespace std;

class SinhVien
{
private:
    string name;
    int id;
    int age;

public:
    SinhVien()
    {
        static int ID = 0;
        ID++;
        id = ID;

        /* - ID truy cập vào id phạm vi private bên trong Constructor SinhVien
         * - static propety: khi gọi object ra thì tự động khởi tạo ID cho SinhVien,
         * ID tự động tăng lên, tránh việc trùng lặp ID.
         */
    }

    // setter method: dùng khởi tạo giá trị cho property
    void setName(string newName)
    {
        // kiểm tra chuỗi truyền vào
        // có ký tự đặc biệt, số -> yêu cầu người dùng nhập lại
        name = newName;
    }

    // setter method
    void setAge(int age)
    {
        // kiểm tra số nhập vào
        age = age;
    }

    // getter method: đặt/trả dữ liệu về
    string getName()
    {
        return name;
    }

    // getter method
    int getAge()
    {
        return age;
    }

    // getter method
    int getID()
    {
        return id;
    }

    void display()
    {
        cout << "Tên: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Age: " << getAge() << endl;
    }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1, sv2;
    sv1.setName("Thuan");
    sv1.display();

    sv2.setName("Tuan");
    sv2.display();
    return 0;
}
```

</details>

<details>
  <summary><h3>Part 2: Abstraction - Tính trừu tượng</h3></summary>

(Static đi với 1 hàm, thì giới hạn trong nội bộ 1 file. Những file bên ngoài không thể gọi ra được kể cả dùng `Extern`. Gọi là quá trình tạo ra kết quả, VD: Tính delta pt bậc 2).

> Tính trừu tượng là ẩn đi quá trình xử lý logic, quá trình tính toán, thuật toán (**method** thuật toán xử lý để tạo ra kết quả) -> private .

_VD: Giải phương trình bậc 2_

```cpp
class GiaiPhuongTrinh {
    private:	// a,b,c,x1,x2,delta: Tính đóng gói
        double a;
        double b;
        double c;
        double x1;
        double x2;
        double delta;

        // Tính trừu tượng: quả trình tính delta sẽ bị ẩn đi
        void tinhNghiem(){	
            delta = b*b - 4*a*c;
            if (delta < 0){
                delta = -1;
            }
            else if (delta == 0){
                x1 = x2 = -b/ (2*a);
            }
            else if (delta > 0){
                x1 = (-b + sqrt(delta))/(2*a);
                x2 = (-b - sqrt(delta))/(2*a);
            }
        }
       
    public:
        void enterNumber(double num_a, double num_b, double num_c);
        void printResult();
};
```
- Quá trình tạo ra kết quả (tính delta) người dùng không thể truy cập. Chỉ được phép: Truyền vào tham số cho method cần tính và in ra kết quả.

```cpp
int main()
{
  GiaiPhuongTrinh phuongtrinh1;
  phuongtrinh1.enterNumber(1,5,4);
  phuongtrinh1.printResult();
  return 0;
}
```

</details>

<details>
  <summary><h3>Part 3: Inheritance - Tính kế thừa</h3></summary>

> Kế thừa là khả năng sử dụng lại các property, method class khác.
>
> Có 3 kiểu kế thừa: public, protected, private. 
>
> Có 2 cách dùng: ghi đè (Override) hoặc sử dụng lại. 

## 1. Kế thừa public
(Giữ nguyên)

- Các thành viên của Class cha phạm vi public, protected sẽ giữ nguyên phạm vi kế thừa khi sang class con. 

- Thành viên phạm vi private thì class con không thể kế thừa.

_VD1: (Code minh họa Complier chạy)_

```cpp
class DoiTuong {
    private:
        string a;
    
    protected:
        int b;

    public:
        string ten;
        int id;
};

class SinhVien : public DoiTuong{
    protected:
        int b;
    public:
        string ten;
        int id;

    public:
        string chuyenNganh;
};
```

### Đặc điểm của kế thừa:

- Có thể ghi đè lên method của class mà nó kế thừa gọi là **Override**.

_VD2:_

```cpp
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{ 
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        // method display được ghi đè
        void display(){ // override: ghi đè
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};

class HocSinh : public DoiTuong{
    protected:
        string lop;
   
    public:
        void setLop(string _lop){
            lop = _lop;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "lop: " << lop << endl;
        }
};

class GiaoVien : public DoiTuong{
    protected:
        string chuyenMon;

    public:
        void setChuyenMon(string _mon){
            chuyenMon = _mon;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen mon: " << chuyenMon << endl;
        }
};
```
- Để phân biệt được 3 method `display()` cùng tên với nhau, thì dựa vào object mà nó tạo ra  

```cpp
int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");
    sv1.display();

    cout << endl;

    HocSinh hs1;
    hs1.setName("Tuan");
    hs1.setLop("12A1");
    hs1.display();

    cout << endl;

    GiaoVien gv1;
    gv1.setName("Hoang");
    gv1.setChuyenMon("Toan");
    gv1.display();
    return 0;
}
```
## 2. Kế thừa protected
(Thay đổi)

- Tất cả các thành viên của Class cha phạm vi public, protected sẽ chuyển protected ở Class con khi kế thừa.

#### Đặc điểm:

- Thành viên của Class cha phạm vi `private` thì class con không thể kế thừa.

- (Giống kế thừa Private): Object bên ngoài không thể truy cập property, method bên trong nó. 

->> Chỉ có thể truy cập thông qua class con kế thừa nó. 

- (Khác kế thừa Private): Class con khi kế thừa có thể sử dụng thành viên trong phạm vi protected.

_VD3: (Code minh họa Complier chạy)_

Ở phạm vi protected, khi tạo object thuộc `class SinhVien` không thể truy cập method, property được.

_VD3:_

```cpp
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : protected DoiTuong{
    protected:
        string ten;
        int id;
    protected:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
   
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};
```
## 3. Kế thừa private

- Giống với protected, các thành viên kế thừa thì chuyển về private hết.

_VD4:(Code minh họa Complier chạy)_

- Object của `class SinhVien` không thể truy cập được các thành viên.

- Nếu có class con kế thừa `class SinhVien` thì không thể sử dụng các thành viên kế thừa lại được nữa. Vì các thành viên của nó phạm vi private. 

_VD4:_

```cpp
class DoiTuong{
    protected:
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : private DoiTuong{

    private:
        string ten;
        int id;

    private:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }

    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display(){ // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl;
        }
};
```

## 4. Đa kế thừa
 
- Class con có thể kế thừa từ nhiều class cha, phạm vi thì tương tự.

```cpp
class SinhVien : public DoiTuong, protected HocSinh, private SinhVien{
}
```
 
_VD5:_
 
**Cách 1: Truy cập object method trung gian qua class**

```cpp
#include <iostream>

using namespace std;

class A {
    public:
        A(){ cout << "Constructor A\n"; } // tự động khởi chạy, khi khai báo object

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : public A {
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C {
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    d.hienThiD();
    d.hienThiB();
    d.hienThiC();
    // d.hienThiA(); // ERROR!!! 
    
    /* 
     * - Vì method hienthiA bị lặp 2 lần.
     * - Complier không rõ phải gọi method hienthiA ở class nào.
     */

    // Gọi method của class A trung gian qua B và C
    d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B
    d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    return 0;
}
```
## 5. Kế thừa ảo

> Kế thừa ảo, là kiểu kế thừa có thêm từ khóa `virtual`. 
>
> Tránh việc xuất hiện nhiều phiên bản, nhiều method giống nhau trong class cuối cùng. Các phiên bản sẽ được gộp lại thành 1 bản sao duy nhất (đây là diamond problem).

**Diamond Problem**: 

```cpp
      A
     / \
    B   C
     \ /
      D
```
 
Ta có, 4 class: Class A, B, C, D

- Class B,C: cùng kể thừa class A

- Class D: Đa kế thừa của class B,C

-->> Nếu không dùng kế thừa ảo, class D sẽ nhận 2 bản sao của class A (từ class B,C). Dẫn đến complier không biết truy cập thành viên nào.

_VD5:_

**Cách 2: Sử dụng kế thừa ảo (virtual)**

```cpp
#include <iostream>

using namespace std;

class A {
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : virtual public A {
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : virtual public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C {
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;

    d.hienThiD();
    d.hienThiB();
    d.hienThiC();

    // 2 phiên bản hienthiA đã được gộp lại, class D gọi ra chỉ 1 bản sao duy nhất
    d.hienThiA();

    return 0;
}
```
</details>

<details>
  <summary><h3>Part 4: Polymorphism - Tính đa hình</h3></summary>

> Tính đa hình là có "nhiều dạng" và nó xảy ra khi có nhiều class có liên quan với nhau thông qua tính kế thừa.
>
> Tính đa hình chia thành 2 loại:

- Đa hình tại thời điểm biên dịch (**Compile-time Polymorphism**).

- Đa hình tại thời điểm chạy (**Run-time Polymorphism**).
    
    - Liên quan đến ghi đè và hàm ảo (**Virtual Function**) ->> Liên quan đến tính kế thừa ảo.

    <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/Cpp_Advance/Bai14_OOP/Polymorphism/polymorphism_runtime.png" alt="Memory Layout" width="500"/>

  
</details>

</details>

    
<details>
  <summary><h3>Bài 15: Virtual Function</h3></summary>

## I. Đa hình Run-time

- Đa hình run-time xảy ra khi việc quyết định method nào (phiên bản của class cha hay của class con) sẽ được gọi ra ngay tại thời điểm chạy chương trình.

- Đa hình runtiime này thực hiện bằng cách sử dụng hàm ảo (virtual function) ở class cha và ghi đè lên hàm ảo ở class con.

- Ưu điểm là giúp chương trình linh hoạt hơn, cho phép việc mở rộng chức năng mà không cần sửa đổi mã nguồn hiện tại.
  
## II. Virtual Function & Override

### 1. Hàm ảo (Virtual Function)

> Hàm ảo là một hàm (method) trong class cha được khai báo với từ khóa `virtual`.

**Sự khác nhau: Tính đa hình & Tính kế thừa**

- Tính kế thừa là method, property đang thuộc class nào, thì object gọi ra method trong class đó.

- Tính đa hình (run-time) thì dựa vào đối tượng đang trỏ đến.

(Vì trong thời điểm chạy, object mới xác định gọi method của class nào). 

#### method bình thường -> ghi đè -> tính kế thừa
#### method ảo (virtual) -> ghi đè -> tính đa hình (run-time)

### 2. Ghi đè lên hàm ảo (Override)

- Override tính kế thừa: dựa vào object của class . (Ghi đè trên method thường).

- Override tính đa hình: dựa vào con trỏ đang trỏ đến object. (Ghi đè trên method của hàm ảo).

_VD1:_
```cpp
#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
        string ten;
        int id;

    public:
        DoiTuong(){  
            static int ID = 1;
            id = ID;
            ID++;
        }

        void setName(string _ten){
            // check chuỗi nhập vào
            ten = _ten;
        }

        virtual void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }
};

class SinhVien : public DoiTuong{
    protected:
        string chuyenNganh;

    public:
        void setChuyenNganh(string _nganh){
            chuyenNganh = _nganh;
        }

        void display() overrride { // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl; // Ghi đè (Override)
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1;
    sv1.setName("Trung");
    sv1.setChuyenNganh("TDH");
    // sv1.display();

    cout << endl;

    // Tạo 1 object(1 ptr *dt1) thuộc class DoiTuong
    DoiTuong *dt1 = &sv1; 
    dt1->display(); // In ra method class SinhVien
    return 0;
}
```

- Mặc dù object `*dt1` trỏ đến địa chỉ `sv1` của `class SinhVien`. Nhưng vẫn in ra method `display` của `class DoiTuong`.

- Để khắc phục, in ra đúng method `display` mà object đã trỏ đến thì dùng tính đa hình (run-time).
    
    - Thêm từ khóa `virtual` ở method của class cha.

    ```cpp
        virtual void display(){
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
        }    
    
    ```

    - Thêm từ khóa `override` ngay sau method của class con để ghi đè.
    
    ```cpp
        void display() overrride { // override
            cout << "ten: " << ten << endl;
            cout << "id: " << id << endl;
            cout << "chuyen nganh: " << chuyenNganh << endl; // Ghi đè (Override)
        }
    ```

## III. Pure Virtual Function

> Hàm ảo thuần túy là hàm ảo (virtual) nhưng không có nội dung nào.

```cpp
    // Pure virtual
    virtual void display() = 0; // phải gán =0, tránh warning
```

#### Chú ý quan trọng:

- Class có ít nhất 1 hàm ảo thuần túy (pure virtual function) bên trong thì được gọi là **class trừu tượng**.

```c
// class trừu tượng
class DoiTuong {
    public:
        // Pure virtual
        virtual void display() = 0;
};
```

- Class trừu tượng, không thể tạo object theo kiểu bình thường được. 

_(Vì object sẽ truy cập đến method và property trong class, mà hàm ảo thuần túy thì không biết rõ nội dung bên trong nó là gì.)_

```cpp
int main(int argc, char const *argv[]) {
    DoiTuong dt3; // ERROR!!!
}
```

- Để object truy cập được thì sử dụng con trỏ.

_(Vì con trỏ sẽ trỏ đến 1 object khác và object đó sẽ có nội dung đầy đủ chứ không phải là hàm ảo thuần túy.)_

```cpp

int main(int argc, char const *argv[])
{
    // Tạo 1 object: Là 1 ptr thuộc class DoiTuong, trỏ đến địa chỉ class SinhVien
    DoiTuong *dt1 = &sv1; 
    dt1->display();

    dt1 = &hs1;
    dt1->display();

    dt1 = &gv1;
    dt1->display();
    
    // DoiTuong dt3; // ERROR!!!
    return 0;    
}
```



</details>
























  



















   
