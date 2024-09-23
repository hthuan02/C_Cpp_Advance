# BÀI 4: EXTERN - STATIC - VOLATILE - REGISTER

- Đây là các từ khóa đi kèm khi khai báo các biến "đặc biệt".

## 1. EXTERN

> Giúp file trong cùng 1 folder chia sẻ các biến, hàm với nhau.
>
> Các biến chỉ khai báo, không được khởi tạo.
>
> Khai báo biến cấp độ cao nhất - toàn cục.

**Ưu điểm quan trọng:** Tiết kiệm được bộ nhớ.

    - Muốn sử dụng lại các biến đã khai báo trong file trước đó. Theo thông thường ta phải khai báo `#include"file.h"` hoặc `#define_FILE1_H`, đối với xử lý nhiều file thì việc khai báo cho file main.c sẽ tốn rất nhiều bộ nhớ.
    -  Vì vậy, để chia sẻ tài nguyên các biến các hàm trong nhiều file cùng 1 folder, chúng ta có thể dùng extern.
    
_Ví dụ:_ 
file1.c 
file2.c //2
main.c //3
➡️ Để sử dụng các biến của 1 và 2, ta khai báo `extern int a;` hoặc `extern int b;`
