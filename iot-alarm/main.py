# Private connection settings are optional and stay outside version control.
try:
    import config
except ImportError:
    config = None

ssid = getattr(config, "WIFI_SSID", "")
pw = getattr(config, "WIFI_PASSWORD", "")
line_notify_token = getattr(config, "LINE_NOTIFY_TOKEN", "")
line_notify_api = 'https://notify-api.line.me/api/notify'
i2c_addr       = 0x27  # LCD I2C 位址
detected_cm    = 50    # 偵測距離 (公分)
detected_delay = 10    # 偵測後等待多久才能再度觸發 (秒)
# --------------------------------------------------
import network, utime, gc
from machine import Pin, SoftI2C, Timer
from esp8266_i2c_lcd import I2cLcd
from hcsr04 import HCSR04

gc.enable()
led = Pin(2, Pin.OUT, value=1)
lcd = I2cLcd(SoftI2C(scl=Pin(5), sda=Pin(4)), i2c_addr, 2, 16)
sensor = HCSR04(trigger_pin=14, echo_pin=12)

def lcd_show(text, clear=True):
    if clear:
        lcd.clear()
    lcd.move_to(0, 0)
    lcd.putstr(text)

wifi = None
if ssid:
    lcd_show('Connecting to\n  WiFi...')
    wifi = network.WLAN(network.STA_IF)
    wifi.active(True)
    wifi.connect(ssid, pw)
    while not wifi.isconnected():
        pass
lcd_show('')

countdown = 0

def send_line_notify(message):
    # Historical LINE Notify integration; disabled when no token is configured.
    if not line_notify_token or wifi is None or not wifi.isconnected():
        return
    headers = {
        "Authorization": "Bearer " + line_notify_token,
        "Content-Type": "application/x-www-form-urlencoded"
    }
    data = 'message={}'.format(message)
    try:
        import urequests
        response = urequests.post(line_notify_api, headers=headers, data=data)
        response.close()
    except Exception as e:
        print('Error sending LINE notification:', e)

def detecter(timer):
    global countdown
    distance = sum([sensor.distance_cm() for _ in range(10)]) / 10
    lcd_show('Distance:\n  {:3.2f} cm'.format(distance), clear=False)
    detected = True if 2 <= distance <= detected_cm else False
    if detected and countdown == 0:
        led.value(0)
        lcd_show('Movement\n  detected')
        countdown = int(detected_delay / 0.5)
        message = 'Intruder detected! Distance: {:3.2f} cm'.format(distance)
        send_line_notify(message)
    if countdown > 0:
        countdown -= 1
    else:
        led.value(1)

timer_detect = Timer(-1)
timer_detect.init(mode=Timer.PERIODIC, period=500, callback=detecter)
