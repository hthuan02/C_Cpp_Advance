#ifndef IOHWAB_SPEEDACCESS_H
#define IOHWAB_SPEEDACCESS_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tốc độ
typedef struct {
    uint8_t SpeedAccess_Channel;   // Kênh ADC để đọc giá trị từ cảm biến tốc độ
    uint16_t SpeedAccess_MaxValue; // Giá trị tốc độ tối đa mà cảm biến có thể đọc (km/h)
} SpeedAccess_ConfigType;

// Prototype cho hàm khởi tạo cảm biến tốc độ
Std_ReturnType IoHwAb_SpeedAccess_Init(const SpeedAccess_ConfigType* ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến tốc độ
Std_ReturnType IoHwAb_SpeedAccess_Read(float* SpeedAccessValue);

#endif /* IOHWAB_SPEEDACCESS_H */
