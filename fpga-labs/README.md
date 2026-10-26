# FPGA 實驗

大學 FPGA 課的實驗與專題，使用 Quartus 和 Verilog，也保留 Lab1 的電路圖與波形輸入。

期中專題是[雙人骰子遊戲](midterm%20project/midterm.v)，包含擲骰、保留本回合分數、輪流操作，以及七段顯示器與勝利 LED。

## 作業內容

| 資料夾 | 在做什麼 |
|---|---|
| [Lab1](Lab1) | 用電路圖練習組合／循序邏輯，附波形輸入。 |
| [Lab2](Lab2) | 多工器，以及 blocking／nonblocking 指派的循序邏輯練習。 |
| [Lab3](Lab3) | 按鍵除彈跳與 LED 開關控制。 |
| [Lab4](Lab4) | 按鍵觸發後，將開關輸入保存並顯示在 LED。 |
| [Lab5](Lab5) | 七段顯示器計數器，包含正倒數、暫停與速度切換。 |
| [Lab6](Lab6) | 算術／邏輯運算與結果顯示。 |
| [Lab7](Lab7) | 暫存器、功能單元與資料路徑練習。 |
| [midterm project](midterm%20project) | 雙人骰子遊戲：擲到 1 換人，選擇 Hold 可保存回合得分，先達 100 分者獲勝。 |
| [final](final) | 接續 Lab7 的指令控制與資料路徑整合稿，仍有待補齊的部分。 |

## 程式導覽

- `.v`：Verilog 原始碼；`debounce.v` 是按鍵除彈跳模組。
- `.qpf`、`.qsf`：Quartus 專案、晶片型號與腳位設定。
- `Lab1/*.bdf`：電路圖；`*.vwf` 是對應的波形輸入。
- `Lab7/lab7r.v`、`lab7f.v`、`lab7.v`：暫存器、功能單元和資料路徑。

## 開發環境

專案設定記錄為 Quartus Prime Lite 20.1.1，依作業分別使用 Cyclone V 或 Cyclone IV E 晶片；實際型號與腳位以各資料夾的 `.qsf` 為準。

`final/final.v` 是尚未完成的整合練習，部分控制訊號與資料路徑連接仍需補齊。
