# 物聯網距離偵測裝置

大學物聯網課程專題，使用 ESP8266、HC-SR04 超音波感測器與 I2C LCD 顯示距離。物體進入設定範圍時，點亮 LED 並在 LCD 顯示警示。

## 專案內容

- 每 500 ms 進行一次偵測，取 10 次測距的平均值。
- 偵測範圍為 2–50 公分，觸發後等待 10 秒才能再次觸發。
- LCD 顯示距離與警示訊息，LED 低電位時亮起。

## 程式導覽

| 檔案 | 內容 |
|---|---|
| [main.py](main.py) | 測距、LCD 顯示、LED 控制與原有通知流程。 |
| [test.py](test.py) | 掃描 I2C 裝置，確認 LCD 位址。 |
| [config.example.py](config.example.py) | 不含私人資料的連線設定範本。 |
| [hcsr04.py](hcsr04.py) | HC-SR04 超音波感測器驅動。 |
| [esp8266_i2c_lcd.py](esp8266_i2c_lcd.py)、[lcd_api.py](lcd_api.py) | I2C LCD 驅動與顯示功能。 |

## 硬體與接線

以下為程式使用的 GPIO 編號。

| 元件 | 接腳／設定 |
|---|---|
| LED | GPIO 2 |
| LCD | SCL：GPIO 5、SDA：GPIO 4，I2C 位址 `0x27`，16×2 字元。 |
| HC-SR04 | Trigger：GPIO 14、Echo：GPIO 12。 |

## 開發環境

ESP8266、MicroPython。主程式與驅動檔放在開發板同一目錄；`urequests` 僅供原有通知函式使用。實際接線與驅動相容性仍需依開發板確認。

需要連線設定時，將 `config.example.py` 複製為 `config.py` 並填入自己的資料。`config.py` 已列入 `.gitignore`；未提供設定時，程式會跳過 Wi-Fi 與通知流程。

原作業使用的 LINE Notify 已於 2025 年 3 月 31 日停止服務，相關函式保留作為課程實作紀錄，預設不啟用通知。[官方公告](https://developers.line.biz/en/news/2025/04/01/line-notify/)

驅動程式的作者與授權列於 [licenses](licenses/README.md)。
