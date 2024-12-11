#ifndef IOHWAB_BATTERYSOC_H
#define IOHWAB_BATTERYSOC_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tốc độ
typedef struct {
    uint8_t  BatterySOC_Channel;   // Kênh ADC để đọc giá trị từ cảm biến trạng thái pin
    uint16_t BatterySOC_MaxValue;  // Giá trị trạng thái pin tối đa mà cảm biến có thể đọc (100%)
    uint16_t BatteryTemp_MaxValue; // Giá trị nhiệt độ tối đa của pin mà cảm biến đọc được (60độ C)
} BatterySOC_ConfigType;

// Prototype cho hàm khởi tạo cảm biến trạng thái pin
Std_ReturnType IoHwAb_BatterySOC_Init(const BatterySOC_ConfigType *ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến trạng thái pin
Std_ReturnType IoHwAb_BatterySOC_Read(float *BatterySOCValue, float *BatteryTempValue);

#endif /* IOHWAB_BATTERYSOC_H */
