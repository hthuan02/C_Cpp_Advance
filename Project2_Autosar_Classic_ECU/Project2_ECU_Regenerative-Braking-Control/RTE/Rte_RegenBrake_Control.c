#include "Rte_RegenBrake_Control.h"
#include "IoHwAb_SpeedAccess.h"
#include "IoHwAb_LoadAccess.h"
#include "IoHwAb_BatterySOC.h"
#include "IoHwAb_InclinationSensor.h"
// #include "IoHwAb_RegenBraking.h"
#include "Std_Types.h"

// API khởi tạo cảm biến tốc độ
Std_ReturnType Rte_Call_RpSpeedAccess_Init(void) {
    // Cấu hình cho cảm biến tốc độ
    SpeedAccess_ConfigType speedAccessConfig = {
        .SpeedAccess_Channel = 0,        // Kênh ADC cho cảm biến tốc độ
        .SpeedAccess_MaxValue = 200      // Tốc độ tối đa giả lập (200 km/h)
    };
    return IoHwAb_SpeedAccess_Init(&speedAccessConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tốc độ
}

// API khởi tạo cảm biến tải trọng
Std_ReturnType Rte_Call_RpLoadAccess_Init(void) {
    // Cấu hình cho cảm biến tải trọng
    LoadAccess_ConfigType loadAccessConfig = {
        .LoadAccess_Channel = 1,         // Kênh ADC cho cảm biến tải trọng
        .LoadAccess_MaxValue = 1000      // Tải trọng tối đa giả lập (1000kg)
    };
    return IoHwAb_LoadAccess_Init(&loadAccessConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tải trọng
}

// Std_ReturnType Rte_Call_PpRegenBraking_Init(void){
//     RegenBraking_ConfigType regenBrakingConfig = {
//         .RegenBraking_Channel = 2, // Kênh ADC cho cảm biến tốc độ
//         // .RegenBraking_MaxValue = 5
//     };
//     return IoHwAb_RegenBraking_Init(&regenBrakingConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tốc độ
// }


// API khởi tạo cảm biến đo trạng tái pin (Sate of charge)
Std_ReturnType Rte_Call_RpBatterySOC_Init(void) {
    // Cấu hình cho cảm biến đo trạng thái pin
    BatterySOC_ConfigType batterySOCConfig = {
        .BatterySOC_Channel = 2,        // Kênh ADC cho cảm biến tốc độ
        .BatterySOC_MaxValue = 100,     // Trạng thái pin tối đa 100%
        .BatteryTemp_MaxValue = 60
    };
    return IoHwAb_BatterySOC_Init(&batterySOCConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến SOC
}

// API khởi tạo cảm biến góc nghiêng
Std_ReturnType Rte_Call_RpInclinationSensor_Init(void){
    InclinationSensor_ConfigType inclinationConfig = {
        .InclinationSensor_Channel = 3, // Kênh ADC cho cảm biến tốc độ
        .InclinationSensor_MaxValue = 45
    };
    return IoHwAb_InclinationSensor_Init(&inclinationConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tốc độ
}

// API đọc dữ liệu cảm biến tốc độ
Std_ReturnType Rte_Read_RpSpeedAccess_Speed(float *Speed) {
    if (Speed == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_SpeedAccess_Read(Speed);
}

// API đọc dữ liệu từ cảm biến tải trọng
Std_ReturnType Rte_Read_RpLoadAccess_Load(float *Load) {
    if (Load == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_LoadAccess_Read(Load);
}

// API đọc dữ liệu từ cảm biến trạng thái pin (SOC-Sate of charge)
Std_ReturnType Rte_Read_RpBatterySOC_BatterySOC(float *BatterySOC, float *BatteryTemp) {
    if (BatterySOC == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_BatterySOC_Read(BatterySOC, BatteryTemp);
}

// API ghi dữ liệu lực phanh tái sinh tới bộ điều khiển phanh tái sinh
// Std_ReturnType Rte_Read_PpRegenBraking_BrakeForce(float *BrakeForce) {
//     if (BrakeForce == NULL) {
//         return E_NOT_OK;
//     }
//     return IoHwAb_RegenBraking_Read(BrakeForce);
// }
