from machine import Pin, SoftI2C
import time

# 初始化 I2C
i2c = SoftI2C(scl=Pin(5), sda=Pin(4))

# 等待设备初始化（如果需要）
time.sleep(1)  # 等待 1 秒

# 扫描 I2C 设备
devices = i2c.scan()

if devices:
    print('I2C devices found:', devices)
else:
    print('No I2C devices found')
