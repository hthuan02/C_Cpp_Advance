# HEAP SEGMENT (Cấp phát động)

**Lưu ý:**
- Khai báo thư viện khi bắt đầu chương trình: `#include<stdlib.h>`
- Giải phóng bộ nhớ đã cấp phát khi kết thúc: `free()`
  
## I. Các hàm cấp phát động

### 1. Hàm Malloc()

> `malloc`: Cấp phát bộ nhớ động vùng nhớ với kích thước, không khởi tạo giá trị.
>
> Giá trị của hàm trả về là 1 `*void`, cần ép kiểu dữ liệu.

```
   ptr = (cast_type*)malloc(byte_size);
```

    - `ptr`: Con trở lưu trữ ô nhớ đầu tiên của vùng nhớ cấp phát.
    - `cast_type`: Kiểu con trỏ muốn ép kiểu sang.
    - `byte_size`: Kích thước byte cần cấp phát.

_VD1:_

```
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
```
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
                printf("%d ", a[i]); // 27 28 29 ... 37
            }
            free(a);
        }
        return 0;
    }

```
- Giải thích:
/*
ban đầu  int = 0

0  1  2  3....9
28 29 30 31...37

40 (byte cấp phát malloc) - 10 byte(sử dụng) = (dư) 30 byte 

--> Nhưng vì sử dụng hàm malloc(Cấp phát động).
--> Nên không xảy ra hiện tượng lãng phí bộ nhớ khi dư 30 byte.
*/

### 2. Hàm Calloc()

### 3. Hàm Realloc()

## II. Hàm thu hồi Free()

## III. So sánh malloc, calloc và realloc
