# MATLAB 課程練習

大學 MATLAB 課程練習，包含迴圈、矩陣操作與數值方法。

## 程式導覽

| 檔案 | 在做什麼 |
|---|---|
| [EX1.m](EX1.m) | 從 initial 開始，累加 N 個連續整數。 |
| [HW1.m](HW1.m) | 從 initial 開始，連乘 N 個連續整數。 |
| [ForLoop.m](ForLoop.m) | 迴圈、矩陣、Hilbert 矩陣與階乘的基本練習。 |
| [fixedpoint.m](fixedpoint.m) | 反覆代入 x = 2 sin(x)，進行固定點迭代。 |
| [newton.m](newton.m) | 用牛頓法求 x − 2 sin(x) = 0 的根。 |
| [simponmethod.m](simponmethod.m) | 用 Simpson 公式近似 0 到 1/2 的 1/(1+x²) 積分。 |
| [fourier.m](fourier.m) | 累加傅立葉級數項並繪圖。 |

## 開發環境

MATLAB；`fourier.m` 使用 `syms`，需要 Symbolic Math Toolbox。原本的版本沒有留下紀錄。

## 執行說明

`fixedpoint` 和 `newton` 固定迭代 100 次，沒有設定誤差停止條件。`simponmethod(n)` 的 n 應為正偶數，程式未檢查輸入。`fourier.m` 使用 `ezplot` 繪圖。
