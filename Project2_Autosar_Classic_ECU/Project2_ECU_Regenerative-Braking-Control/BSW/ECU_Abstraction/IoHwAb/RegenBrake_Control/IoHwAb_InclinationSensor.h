#ifndef IOHWAB_INCLINATIONSENSOR_H
#define IOHWAB_INCLINATIONSENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tốc độ
typedef struct {
    uint8_t  InclinationSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến tốc độ
    uint16_t InclinationSensor_MaxValue; // Giá trị tốc độ tối đa mà cảm biến có thể đọc (km/h)
} InclinationSensor_ConfigType;

// Prototype cho hàm khởi tạo cảm biến tải trọng
Std_ReturnType IoHwAb_InclinationSensor_Init(const InclinationSensor_ConfigType* ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến tải trọng
Std_ReturnType IoHwAb_InclinationSensor_Read(float* InclinationValue);

#endif /* IOHWAB_INCLINATIONSENSOR_H */
