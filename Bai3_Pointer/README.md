# POINTER

### 1. Pointer(Con trỏ):
   Là 1 biến dùng để lưu địa chỉ của 1 biến, 1 hàm. Con trỏ không lưu giá trị mà nó lưu địa chỉ bộ nhớ nơi biến khác đang sử dụng.

### Khởi tạo con trỏ

```int a = 10;
   int * ptr = &a;  
```
   ```ptr``` là một con trỏ, có thể trỏ đến 1 biến kiểu dữ liệu ```int```. Dấu ```*``` để chỉ ```ptr``` là 1 con trỏ.
   ```ptr``` lưu địa chỉ của ```a``` và trỏ tới địa chỉ ```a```.
   
### Truy xuất giá trị con trỏ

```int a = 10;
   int * ptr = &a;
   printf("Dia chi: %p\n", &a);
   printf("Dia chi: %p\n", ptr);
   printf("Gia tri tai dia chi: %d\n", *ptr);
  
```


   
