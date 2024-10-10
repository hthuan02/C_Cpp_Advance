# Bài 1: Complier - Marco

IDE gồm:
- editor: phần mềm soạn thảo
- Complier: gcc cho C ,g++ cho C++

## 1. Complier
> Complier(trình biên dịch): Chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy 0 1 

## 2. Quá trình biên dịch của gcc?
Gồm 4 bước chính:
    - Tiền xử lý (Preprocessor)
    - Complier
    - Asembler
    - Linker








# BÀI 3: POINTER

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
- Đối với con trỏ cấp 2 là lưu địa chỉ của con trỏ cấp 1.             


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

```c
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


# BÀI 5: GOTO - SETJMP.H

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

# BÀI 7: STRUCT & UNION

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
> Kích thước Union sẽ lấy kiểu dữ liệu có kích thước lớn nhất.

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

# BÀI 8: MEMORY LAYOUT

- Memory Layout: Là sự tổ chức và sắp xếp các vùng nhớ (chứa mã lệnh, biến, và dữ liệu) trong bộ nhớ RAM khi chương trình thực thi.  

- Gồm có 5 phân vùng bộ nhớ, theo thứ tự từ trên xuống:

    <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/Bai8_Memory-layout/images/memorylayout.png" alt="Memory Layout" width="500"/>

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

> `malloc`: Là hàm Cấp phát bộ nhớ động vùng nhớ với kích thước, không khởi tạo giá trị.
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

<img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/Bai8_Memory-layout/images/stack_heap.png" alt="Memory Layout" width="220"/>

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
  

# BÀI 10: LIKED LIST

- Liked list (danh sách liên kết): Là cấu trúc dữ liệu gồm chuổi các node(nút) liên kết với nhau, mỗi node gồm 2 thành phần: Data và con trỏ (*Next).

  _VD0:_ Cho mảng `int array[] = {2,7,4,5,3};`

- Dùng Malloc:
  
        // Malloc(); //Lưu trữ 5 phần tử * sizeof(int)= (20byte)

        // Free():

        // Thêm - Thu hồi phần tử bằng cách thủ công, nhưng đối với array[10000] thì không thể làm thủ công được.

  ➡️➡️➡️➡️➡️
- Liked list: Tạo 5 node

    <img src="https://github.com/hthuan02/C_Cpp_Advance/blob/main/Bai10_Linked-List/liked_list.png" alt="Memory Layout" width="800"/>

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

# Các hàm thường sử dụng trong danh sách liên kết(Liked List)

## 1. Hàm thêm 1 node ở cuối LIST
```c
void push_back(Node **array, int value)
{
    Node *temp = createNode(value);

    if (*array == NULL)
    {
        temp = *array;
    }

    else
    {
        Node *p;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
```
## 2. Hàm xóa 1 node ở cuối LIST
```c
void pop_back(Node **array)
{
    Node *p = *array;
    Node *temp;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    free(p);

    int j;
    temp = *array;
    for (j = 0; j < i - 1; j++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
```
## 3. Hàm thêm 1 node ở đầu LIST
```c
void push_front(Node **array, int value)
{
    Node *new_node = createNode(value);

    new_node->next = *array;
    *array = new_node;
}
## 4. Hàm xóa 1 node ở đầu LIST
void pop_front(Node **array)
{
    if (*array == NULL)
    {
        return;
    }
    Node *temp = *array;
    *array = (*array)->next;
    free(temp);
}
```
## 5. Hàm thêm 1 node vị trí bất kỳ trong LIST
```c
void insert(Node **array, int value, int pos)
{
    Node *new_node = createNode(value);
    Node *p = *array;
    int index = 0;

    while (p->next != NULL && index != pos - 1)
    {
        p = p->next;
        index++;
    }

    if (index == pos - 1)
    {
        new_node->next = (p->next);
        p->next = new_node;
    }
}
```
## 6. Hàm xóa 1 node vị trí bất kỳ trong LIST
```c
void delete_list(Node **array, int pos)
{
    // Con trỏ tạm để thao tác với danh sách
    Node *p = *array;

    // Nếu danh sách trống thì không làm gì và thoát
    if (*array == NULL)
        return;

    // Xóa node đầu tiên (vị trí pos = 0)
    if (pos == 0)
    {
        *array = p->next;
        free(p);
        return;
    }

    // Duyệt qua danh sách để tìm node đứng trước vị trí cần xóa
    int i;
    for (i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next; // Tiến tới node tiếp theo
    }

    // Kiểm tra nếu vị trí cần xóa không hợp lệ (vượt quá chiều dài danh sách)
    if (p == NULL || p->next == NULL)
        return;

    // Tìm được node cần xóa
    Node *temp = p->next; // Node tại vị trí cần xóa
    p->next = temp->next; // Cập nhật liên kết để bỏ qua node cần xóa

    // Giải phóng bộ nhớ của node cần xóa
    free(temp);
}
```












    



























  



















   
