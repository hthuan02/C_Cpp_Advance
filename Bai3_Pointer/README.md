# BÀI 4: POINTER

- Con trỏ là 1 biến dùng để lưu địa chỉ của 1 biến, 1 hàm
- Con trỏ không lưu giá trị mà nó lưu địa chỉ bộ nhớ nơi biến khác đang sử dụng.

## I. Các loại con trỏ

### 1. Regular Pointer(Con trỏ với biến)
```
    int a = 10;
    int * ptr = &a;

    //Truy xuat con tro
    printf("Dia chi: %p\n", &a); // dia chi cua a
    printf("Dia chi: %p\n", ptr); // dia chi ma ptr tro den 
    printf("Gia tri tai dia chi: %d\n", *ptr); // a = 10
```

### 2. Array Pointer(Con trỏ mảng)

```
    int arr[] = { 2, 3, 5, 7, 8 };
    int * ptr = arr;

    printf("Dia chi phan tu 1: %p\n", ptr) //2
    printf("Dia chi phan tu 2: %p\n", ptr+1) //3
    printf("Dia chi phan tu 3: %p\n", ptr+2) //5

    printf("Gia tri phan tu 1: %d\n", *ptr) 
    printf("Gia tri phan tu 2: %d\n", *(ptr+1)) 
    printf("Gia tri phan tu 3: %d\n", *(ptr+2))

```

### 3. Void Pointer
   >Có thể trỏ đến bất kỳ kiểu dữ liệu nào (char, int, float, double,...), nhưng không thể được sử dụng trực tiếp để gọi hàm.
   - Ưu điểm: Tại địa chỉ trỏ đến có thể đọc thay đổi giá trị tại địa chỉ mình muốn thay đổi.

```
    void * ptr; //Khai bao con tro Void
```
- _VD1: Xuất giá trị ._

```
    #include <stdio.h>

    void Value(void*ptr) {
       printf("A = %d\n", *(int*)(ptr)); //Ep kieu du lieu int
    }

    int main() {
        int a = 10;
        Value(&a);
        return 0;
    }
```

### 4. Function Pointer
>Có thể trỏ đến các hàm có kiểu dữ liệu cụ thể, giúp gọi hàm thông qua con trỏ.

>Đây là biến giữ địa chỉ của hàm, mỗi thời điểm chỉ trỏ 1 hàm.
   
```
   void (*func_ptr)(int, int);  // Khai bao con tro 
```

- _VD2: Tổng, hiệu, tích, thương._

```
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


   
### 5. Pointer to Constant(Con trỏ hằng)
   Trỏ tới hằng số, đây là số không đổi. Chỉ có thể đọc chứ **không đổi**  
   
### 6. Constant Pointer(Hằng con trỏ)
   Chỉ trỏ đến 1 địa chỉ duy nhất.
   
### 7. NULL Pointer
>Con trỏ trống, không trỏ đến vùng nhớ nào.
>Khai báo nhưng chưa sử dụng liền.

**Chú ý:** 
- Khi khai báo con trỏ mà chưa sử dụng thì dùng con trỏ NULL(sẽ không bị **random** giá trị vào địa chỉ rác hoặc trùng lặp địa ).
- Khởi tạo và kết thúc phải gán NULL.

```
    int *ptr = NULL;
```
   
### 2.6 Pointer to Pointer(Con trỏ đến con trỏ)
>Là con trỏ mà có thể trỏ đến địa chỉ của các con trỏ khác, có nhiều cấp độ con trỏ (con trỏ cấp 2, 3,...).

`
int a = 10;
int *ptr = &a;
int **ptr = &ptr;
`
















   
