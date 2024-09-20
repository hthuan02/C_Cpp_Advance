# BÀI 4: POINTER

## Pointer(Con trỏ)

### 1. Khái niệm
   Là 1 biến dùng để lưu địa chỉ của 1 biến, 1 hàm. Con trỏ không lưu giá trị mà nó lưu địa chỉ bộ nhớ nơi biến khác đang sử dụng.

### 2. Khởi tạo con trỏ

```int a = 10;
   int * ptr = &a;  
```
   ```ptr``` là một con trỏ, trỏ đến 1 biến kiểu dữ liệu ```int```. Dấu ```*``` để chỉ ```ptr``` là 1 con trỏ.
   ```ptr``` lưu địa chỉ của ```a``` và trỏ tới địa chỉ ```a```.
   
### 3. Truy xuất giá trị con trỏ

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

##  Phân loại con trỏ

### 2.1 Void Pointer
   K
### 2.2 Function Pointer

### 2.3 Pointer to Constant(Con trỏ hằng)

### 2.4 Constant Pointer

### 2.5 NULL Pointer

### 2.6 Pointer to Pointer


















   
