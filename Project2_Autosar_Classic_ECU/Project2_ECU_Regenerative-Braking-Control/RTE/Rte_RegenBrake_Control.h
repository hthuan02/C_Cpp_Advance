#ifndef RTE_REGENBRAKE_CONTROL_H
#define RTE_REGENBRAKE_CONTROL_H

#include "Std_Types.h"  // Bao gồm các kiểu dữ liệu tiêu chuẩn
#include <stddef.h>  // Định nghĩa NULL

// API để khởi tạo cảm biến tốc độ
Std_ReturnType Rte_Call_RpSpeedAccess_Init(void);

// API để khởi tạo cảm biến tải trọng
Std_ReturnType Rte_Call_RpLoadAccess_Init(void);

// API để khởi tạo bộ điều khiển phanh tái sinh
// Std_ReturnType Rte_Call_PpRegenBraking_Init(void);

// API để khởi tạo cảm biến đo trạng thái pin (SOC-Sate of charge)
Std_ReturnType Rte_Call_RpBatterySOC_Init(void);

// API để khởi tạo cảm biến góc nghiêng
Std_ReturnType Rte_Call_RpInclinationSensor_Init(void);

// API đọc dữ liệu từ cảm biến tốc độ
Std_ReturnType Rte_Read_RpSpeedAccess_Speed(float *Speed);

// API đọc dữ liệu từ cảm biến tải trọng
Std_ReturnType Rte_Read_RpLoadAccess_Load(float *Load);

// API đọc dữ liệu từ cảm biến đo trạng thái pin (SOC-Sate of charge)
Std_ReturnType Rte_Read_RpBatterySOC_BatterySOC(float *BatterySOC, float *BatteryTemp);


#endif /* RTE_TORQUECONTROL_H*/
