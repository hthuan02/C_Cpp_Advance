/****************************************************************************
 * @file    RegenBrake_Control.c
 * @brief   Định nghĩa các hàm quản lý phanh tái sinh
 * @details File này chứ các hàm quản lý phanh tái sinh bao gồm
 * @version 1.0
 * @date    2024-12-2
 * @author  Huỳnh Minh Thuận 
 ****************************************************************************/
#include "Rte_RegenBrake_Control.h"   // Bao gồm interface của RTE cho Torque Control
#include "RegenBrake_Control.h"
#include <stdio.h>                    // Thư viện cho printf
#include <stdbool.h>
#include <stdlib.h>

void RegenBrakeControl_Init(void) {
    Std_ReturnType status;

    printf("--------------- Khởi tạo hệ thống Torque Control... ---------------\n");
    // Khởi tạo cảm biến tốc độ
    status = Rte_Call_RpSpeedAccess_Init();
    if (status == E_OK) {
        printf("Cảm biến tốc độ đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến tốc độ.\n");
        return;
    }

    // Khởi tạo cảm biến tải trọng
    status = Rte_Call_RpLoadAccess_Init();
    if (status == E_OK) {
        printf("Cảm biến tải trọng đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến tải trọng.\n");
        return;
    }

    // Khởi tạo bộ điều khiển phanh tái sinh
    // status = Rte_Call_PpRegenBraking_Init();
    // if (status == E_OK) {
    //     printf("Bộ điều khiển phanh tái sinh tạo thành công.\n");
    // } else {
    //     printf("Lỗi khi khởi tạo bộ điều khiển phanh tái sinh.\n");
    //     return;
    // }

    // Khởi tạo cảm biến trạng thái pin
    status = Rte_Call_RpBatterySOC_Init();
    if (status == E_OK) {
        printf("Cảm biến trạng thái pin khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến trạng thái pin.\n");
        return;
    }

    // Khởi tạo cảm biến góc nghiêng
    status = Rte_Call_RpInclinationSensor_Init();
    if (status == E_OK) {
        printf("Cảm biến góc nghiêng khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến góc nghiêng.\n");
        return;
    }


    printf("=============== Hệ thống Regenerative Braking đã sẵn sàng! ===============\n");
}

// Hàm cập nhật quản lý phanh tái sinh 
void RegenBrakeControl_Update(void) {
    float current_speed = 0.0f;
    float current_load = 0.0f;
    float kinetic_current = 0.0f;
    float regen_power = 0.0f;
    float regenbrake_force = 0.0f;
    float battery_soc = 0.0f;
    float battery_temp = 0.0f;
    bool accelerator_released = (rand() % 2 == 0); // Biến trạng thái bàn đạp ga nhả
    bool brake_pressed = (rand() % 2 == 0);        // Biến trạng thái nhấn phanh
    bool regenbrake_active = false;                // Biến trạng thái phanh tái sinh
    
    // Đọc dữ liệu từ cảm biến tốc độ
    if (Rte_Read_RpSpeedAccess_Speed(&current_speed) == E_OK) {
        printf("Tốc độ xe hiện tại: %.2f km/h\n", current_speed);
    } else {
        printf("Lỗi khi đọc cảm biến tốc độ!\n");
    }

    // Đọc dữ liệu từ cảm biến tải trọng
    if (Rte_Read_RpLoadAccess_Load(&current_load) == E_OK) {
        printf("Tải trọng hiện tại: %.2f kg\n", current_load);
    } else {
        printf("Lỗi khi đọc cảm biến tải trọng!\n");
    }

    // Tính toán động nặng
    kinetic_current = 0.5f * current_load * current_speed * current_speed;

    // Tính toán điện năng nạp vào Pin (hiệu suát là 85%)
    regen_power = kinetic_current * EFFICIENCY_REGEN;

    // In ra các giá trị 
    printf("- Động năng hiện tại: %.2f J\n", kinetic_current);                            // Động nặng
    printf("- Điện năng nạp vào Pin (Hiệu suất: \u03B7 = 85%%): %.2f J\n", regen_power);  // Điện năng nạp vào pin
    printf("- Chuyển đổi sang kWh: %.2f kWh\n", regen_power * JOULES_TO_KWH);             // Chuyển điện năng từ J sang kWh

    // Kiểm tra nếu bàn đạp ga được nhả ra hoặc phanh được nhấn và tốc độ đủ lớn 
    if ((accelerator_released || brake_pressed) && current_speed > SPEED_THRESHOLD) {
        regenbrake_force = (current_speed - SPEED_THRESHOLD) * BRAKE_COEFFICIENT;
        regenbrake_active = true;
        printf("- Kích hoạt phanh tái sinh: %.2f N\n", regenbrake_force);
    } else {
        regenbrake_force = 0.0f;
        regenbrake_active = false; 
        printf("%s\n", current_speed <= SPEED_THRESHOLD ? "- Không có phanh tái sinh vì tốc độ quá thấp." :
                                                          "- Không có phanh tái sinh vì không nhả ga hoặc không nhấn phanh.");
    }

    // Chuyển độ C sang độ F
    // float Celsius_To_Fahrenheit = (battery_temp * 9.0f / 5.0f) +32.0f;

    // Đọc dữ liệu từ cảm biến trạng thái pin
    // if (Rte_Read_RpBatterySOC_BatterySOC(&battery_soc, &battery_temp) == E_OK) {
    //     printf("- Trạng thái Pin hiện tại: %.0f%%\n", battery_soc);
    //     printf("- Nhiệt độ Pin hiện tại: %.2f\u00b0C (%.2f\u00b0F)\n",battery_temp, Celsius_To_Fahrenheit);
    // } else {
    //     printf("Lỗi khi đọc trạng thái pin!\n");
    // }

    if (Rte_Read_RpBatterySOC_BatterySOC(&battery_soc, &battery_temp) == E_OK) {
        if (battery_temp < MAX_BATTERY_TEMP) {
            if(regenbrake_active == true){
                printf("Nhiệt độ Pin ổn định có lực phanh tái sinh. Tiến thành tái nạp...\n");
            } else {
            printf("Không thể tái nạp, vì không có lực tái sinh\n");
            }
            return;
        } else {
            printf("Nhiệt độ Pin quá cao! Tạm dừng tái nạp.\n");
            return;
        }
    }

}