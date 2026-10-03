# Servo-based 7-segment display (STM32F303K8)

A physical seven-segment display in which every segment is opened or closed by its own servo motor. An STM32F303K8 microcontroller drives the seven servos with PWM and counts through the digits 0 to 9, setting each servo to the pattern of the current digit.

## How it works

- **Seven PWM outputs** from two timers: TIM2 channels 1 to 4 (PA5, PA1, PA2, PA3) and TIM3 channels 1 to 3 (PA6, PA4, PB0). Both timers run at 50 Hz (prescaler 63, period 19999 on a 64 MHz timer clock, so one tick is 1 µs).
- **Two positions per servo:** `setServoAngleO` (open) writes the compare value 2000 and `setServoAngleC` (close) writes 1000, i.e. 2 ms and 1 ms pulses. Despite the names, they select two fixed pulse widths, not arbitrary angles.
- **Digit patterns:** `ct % 10` selects one of ten hard-coded open/close combinations in the main loop (`Core/Src/main.c`).
- **Servo to segment mapping** (inferred from the ten digit patterns, standard segment names a to g):

| Segment | a | b | c | d | e | f | g |
|---|---|---|---|---|---|---|---|
| Servo | TIM2 CH2 | TIM2 CH3 | TIM2 CH4 | TIM3 CH2 | TIM2 CH1 | TIM3 CH1 | TIM3 CH3 |

- **Controls:** three digital inputs choose how the counter advances.

| PA8 | PB3 | Mode |
|---|---|---|
| low | low | hold: the digit does not change |
| high | low | manual: each rising edge on PA0 (50 ms delay for debouncing) adds 1 |
| low | high | automatic: adds 1 about once per second |
| high | high | the previously selected mode stays active |

- **Clock:** internal oscillator with the PLL ×16, 64 MHz.

## Project

STM32CubeMX / STM32CubeIDE project (firmware package STM32Cube FW_F3 V1.11.5). The vendor `Drivers/` folder (CMSIS and HAL, with their license files) is included on purpose: in `Core/Src/main.c` the main-loop body sits **outside** the protected `USER CODE` blocks, so regenerating the code from the `.ioc` file would overwrite it. If you regenerate, do it in a copy.

## Limitations

- Only the digits 0 to 9 (`ct % 10`); the counter itself keeps growing.
- The loop uses blocking `HAL_Delay` calls (up to one second in the automatic mode), so the mode inputs and the button are only sampled once per pass through the loop.
- The wiring, the servo mounting and the mechanics of the segments are not documented here.
- No license is specified for the hand-written code; the vendor files keep their own licenses.

## Türkçe özet

Her segmenti ayrı bir servo motorun açıp kapattığı fiziksel bir yedi segmentli ekran. STM32F303K8, yedi servoyu PWM ile sürer ve 0-9 rakamlarını sayarak her rakamın desenini servolara uygular. PA8 ve PB3 girişleri sayma kipini (bekle / PA0 düğmesiyle elle / yaklaşık saniyede bir otomatik) seçer. Ana döngü kodu CubeMX'in korumalı `USER CODE` bölgelerinin dışında olduğu için `Drivers/` klasörü depoya dahil edilmiştir; kodu `.ioc`'dan yeniden üretecekseniz bir kopya üzerinde yapın.
