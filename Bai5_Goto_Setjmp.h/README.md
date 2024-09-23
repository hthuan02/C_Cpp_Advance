# BÀI 5: GOTO - SETJMP.H

## 1. GOTO
>Cho phép đoạn code nhảy đến label(nhãn) mà mình chỉ , label có để đặt bất cứ vị trí nào trong cùng 1 hàm.

- _VD1: Tạo Menu sử dụng lệnh Goto_
   
```
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

```
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
      if (i == 2 && j == 3){
         printf("break while \n");
         break; //Thoat duoc For cua while       
      }
   } 
```



















  


