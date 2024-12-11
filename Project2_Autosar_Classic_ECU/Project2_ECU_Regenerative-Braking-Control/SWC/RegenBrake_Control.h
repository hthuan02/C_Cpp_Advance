/****************************************************************************
 * @file    RegenBrake_Control.h
 * @brief   Khai báo các hàm và cấu trúc đến điều khiển tôc độ động cơ
 * @details File này cung cấp giao diện cho việc quản lý phanh tái sinh, bao
 *          gồm hai hàm là: khởi tạo và cập nhật
 * @version 1.0
 * @date    2024-12-2
 * @author  Huỳnh Minh Thuận 
 ****************************************************************************/
#ifndef REGENBRAKE_CONTROL_H
#define REGENBRAKE_CONTROL_H

#define EFFICIENCY_REGEN 0.85           // Hiệu suất phanh tái sinh (85%)
#define JOULES_TO_KWH 1.0f / 3600000.0f // Chuyển đổi đơn vị từ Joules sang kWh

#define SPEED_THRESHOLD 10.0f           // Ngưỡng tốc độ phanh tái sinh (dưới ngưỡng không hoạt động)
#define BRAKE_COEFFICIENT 0.5           // Hệ số phanh tái sinh

#define MAX_BATTERY_TEMP 50             // Nhiệt độ tối da khi nạp pin

#define EFFICIENCY_BATTERY 0.90         // Hiệu suất nạp pin (90%)

// Khai báo các hàm chính cho Torque Control
void RegenBrakeControl_Init(void);   // Hàm khởi tạo hệ thống điều khiển phanh tái sinh
void RegenBrakeControl_Update(void); // Hàm cập nhật hệ thống điều khiển phanh tái sinh

#endif // REGENBRAKE_CONTROL_H
