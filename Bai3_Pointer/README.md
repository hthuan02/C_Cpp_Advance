                              # BÀI 4: POINTER

## 1. Pointer(Con trỏ)

### 1.1 Khái niệm
   Là 1 biến dùng để lưu địa chỉ của 1 biến, 1 hàm. Con trỏ không lưu giá trị mà nó lưu địa chỉ bộ nhớ nơi biến khác đang sử dụng.

### 1.2 Khởi tạo con trỏ

```int a = 10;
   int * ptr = &a;  
```
   ```ptr``` là một con trỏ, trỏ đến 1 biến kiểu dữ liệu ```int```. Dấu ```*``` để chỉ ```ptr``` là 1 con trỏ.
   ```ptr``` lưu địa chỉ của ```a``` và trỏ tới địa chỉ ```a```.
   
### 1.3 Truy xuất giá trị con trỏ

```int a = 10;
   int * ptr = &a;
   printf("Dia chi: %p\n", &a); // In ra địa chỉ của biến a
   printf("Dia chi: %p\n", ptr); // In ra giá trị của con trỏ ptr
   printf("Gia tri tai dia chi: %d\n", *ptr); // In ra giá trị a = 10
```

### 1.4 Mảng với con trỏ

Cho 1 mảng:
``` int arr[] = { 2, 3, 5, 7, 8 };
    int * ptr = arr;
    printf("Dia chi phan tu 1: %p\n", ptr) // Xuất 2
    printf("Dia chi phan tu 2: %p\n", ptr+1) // Xuất 3
    printf("Dia chi phan tu 3: %p\n", ptr+2) // Xuất 5

    printf("Gia tri phan tu 1: %d\n", *ptr) // Xuất 2
    printf("Gia tri phan tu 2: %d\n", *(ptr+1) // Xuất 3
    printf("Gia tri phan tu 3: %d\n", *(ptr+2) // Xuất 5   
```
### 1.5 Kích thước con trỏ

## 2. Phân loại con trỏ

### 2.1 Void Pointer
   Đây là con trỏ có thể trỏ đến bất kỳ vị trí nào, không quan tâm đến kiểu dữ liệu (char, int double,...đều trỏ được).
   - Ưu điểm: Tại địa chỉ trỏ đến có thể đọc thay đổi giá trị tại địa chỉ mình muốn thay đổi.

```void *ptr;  //Khai bao con tro Void
```
### 2.2 Function Pointer
   Biến giữ địa chỉ của hàm, mỗi thời điểm chỉ trỏ 1 hàm.
   
```void (*func_ptr)(int, int);  // Khai bao con tro Func
```
**So sánh Void & Function Pointer**
- Code VD1: Tổng, hiệu, tích, thương.
```#include<stdio.h>
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

int main(){
  int a = 10, b = 5;
  void (*ptr) (int, int);
  ptr = tong;
  ptr(a,b);

  ptr = hieu;
  ptr(a,b);

  ptr = tich;
  ptr(a,b);

  ptr = thuong;
  ptr(a,b);
```
   
### 2.3 Pointer to Constant(Con trỏ hằng)
   Trỏ tới hằng số, đây là số không đổi. Chỉ có thể đọc chứ **không đổi**  
   
### 2.4 Constant Pointer(Hằng con trỏ)
   Chỉ trỏ đến 1 địa chỉ duy nhất.
   
### 2.5 NULL Pointer
   Con trỏ trống, chưa có biến giá trị.
   
### 2.6 Pointer to Pointer
   Con trỏ trong con trỏ( con trỏ cấp 2, 3, 4,...).

















   
