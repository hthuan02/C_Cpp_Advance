# BÀI 7: STRUCT & UNION

## 1. Struct

> Struct là 1 dạng kiểu dữ liệu, cho phép người dùng tự định nghĩa. Nhóm các kiểu dữ liệu như: int, char, double,... lại thành kiểu dữ liệu mới. 
>
> Kích thước của Struct = Tổng các kích thước dữ liệu + padding 


```
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
```
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

```
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

```
    //double(8byte): Chia het 8, 0x00 0x08 0x10 0x18,..
    //int, int32_t, uint32_t(4byte): 0x00 0x04 0x08 0x0C...
    //float, init16_t, uint16_t(2byte): 0x00 0x02 0x04 0x06...
    //padding
```
➡️ Kích thước của Struct = tổng các kiểu dữ liệu + padding
  
**_VD2: Tìm kích thước struct VD1_**

```
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

```
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
```    
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

```
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








