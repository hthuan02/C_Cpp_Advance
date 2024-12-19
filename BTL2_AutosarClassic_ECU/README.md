ECU: Task 2
---
# Regenerative Braking Control (Quản lý phanh tái sinh)

## I. Chức năng quản lý phanh tái sinh:
  **Chức năng phanh tái sinh** giúp thu hồi năng lượng từ quá trình phanh hoặc nhả ga, chuyển động năng thành điện năng để nạp lại vào pin, cải thiện hiệu suất và tăng quãng đường di chuyển.

## II. Nguyên lý hoạt động
### 1. Chuyển động năng thành điện năng
- Khi xe đang di chuyển, động cơ điện sử dụng điện năng từ pin để tạo ra mô-men xoắn, giúp xe tăng tốc. Tuy nhiên, khi người lái nhả bàn đạp ga hoặc nhấn phanh, ECU (Electronic Control Unit) sẽ kích hoạt chế độ phanh tái sinh.
- Ở chế độ này, động cơ điện thay vì tiêu thụ điện năng sẽ hoạt động như một máy phát điện. Lúc này, động cơ sẽ chuyển đổi động năng của xe (năng lượng do xe đang di chuyển) thành điện năng, và nạp lại vào pin để lưu trữ.

**Tiến hành thực hiện:**
- Tính giá trị của 2 cảm biến tốc độ và tải trọng.
- Sau khi có được m(kg) và v(km/h), tính động năng của xe
- Chuyển động năng sang điện năng nạp vào pin. 

### 2. Kích hoạt phanh tái sinh
Phanh tái sinh thường được kích hoạt trong hai trường hợp chính:
- Khi người lái nhả bàn đạp ga: Khi không còn tín hiệu đầu vào từ bàn đạp ga, hệ thống sẽ kích hoạt phanh tái sinh để thu hồi năng lượng.
- Khi người lái nhấn phanh: Khi phanh được nhấn, ECU có thể kích hoạt phanh tái sinh đồng thời với phanh cơ khí để giảm hao mòn và tăng hiệu quả.

**Cảm biến bàn đạp ga (SimulateAcceleratorPedalSignal)**:
- 1: Bàn đạp ga không còn được nhấn -> ECU sẽ kích hoạt phanh tái sinh, vì xe không còn nhận đầu vào tăng tốc từ bàn đạp ga nữa.

- 0: Bàn đạp ga đang được nhấn -> hệ thống sẽ không kích hoạt phanh tái sinh, vì xe đang còn tăng tốc, và không có lý do để thu hồi năng lượng.
  
**Cảm biến phanh (SimulateBrakePedalSignal)**:
- 1: Bàn đạp phanh đã được nhấn -> hệ thống có kích hoạt phanh tái sinh để giảm tốc độ và thu hồi năng lượng từ động năng của xe.

- 0: Đạp phanh không được nhấn -> hệ thống không kích hoạt phanh tái sinh, vì không có nhu cầu giảm tốc hoặc thu hồi năng lượng.
