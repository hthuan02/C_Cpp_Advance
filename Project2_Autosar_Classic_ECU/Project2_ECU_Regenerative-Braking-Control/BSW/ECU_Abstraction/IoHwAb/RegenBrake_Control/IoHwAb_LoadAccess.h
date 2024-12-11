#ifndef IOHWAB_LOADACCESS_H
#define IOHWAB_LOADACCESS_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tốc độ
typedef struct {
    uint8_t LoadAccess_Channel;   // Kênh ADC để đọc giá trị từ cảm biến tốc độ
    uint16_t LoadAccess_MaxValue; // Giá trị tốc độ tối đa mà cảm biến có thể đọc (km/h)
} LoadAccess_ConfigType;

// Prototype cho hàm khởi tạo cảm biến tải trọng
Std_ReturnType IoHwAb_LoadAccess_Init(const LoadAccess_ConfigType* ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến tải trọng
Std_ReturnType IoHwAb_LoadAccess_Read(float* LoadAccessValue);

#endif /* IOHWAB_LOADACCESS_H */
