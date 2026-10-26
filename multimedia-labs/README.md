# 多媒體資訊概論

大學多媒體課的兩份作業，一份用 C++ 產生 WAV 聲音，另一份用 Python 做影像處理。

## 作業內容

| 作業 | 在做什麼 | 程式 |
| --- | --- | --- |
| HW1 | 輸入聲音頻率、取樣頻率和秒數，用餘弦波產生單聲道 WAV 檔 | [HW1.cpp](HW1/HW1.cpp) |
| HW2－1 | 把 256 個色階畫成漸層色條 | [requirement1.ipynb](HW2/requirement1.ipynb) |
| HW2－2 | 用 Sobel 取出水平與垂直邊緣，再合成邊緣圖與假色圖 | [requirement2.ipynb](HW2/requirement2.ipynb) |
| HW2－3 | 將圖片轉成灰階，做 CLAHE 對比增強，再畫假色圖與直方圖 | [requirement3.ipynb](HW2/requirement3.ipynb) |

HW1 的兩個選項分別產生 `Mywav1.wav` 和 `Mywav2.wav`；第二個選項另外對取樣時間做離散化。[HW1/examples](HW1/examples) 提供 WAV 輸出範例，對應的輸入參數未記錄。

HW2 的 `hw2.jpg`、`hw2_2.jpg` 是輸入圖片，[examples](HW2/examples) 提供影像處理結果。

| 原圖 | Sobel 邊緣 |
| --- | --- |
| ![HW2 輸入圖片](HW2/hw2.jpg) | ![Sobel 邊緣結果](HW2/examples/requirement2/Sobel.jpg) |

## 開發環境

- HW1：C++。程式使用變動長度陣列，需支援此擴充的編譯器，或再調整陣列寫法。
- HW2：Jupyter Notebook、NumPy、Matplotlib、OpenCV、Pillow。

## 執行說明

Notebook 請在 `HW2` 資料夾內執行，圖片讀寫使用相對路徑，輸出也會寫入該資料夾。`requirement3` 的 CLAHE `tileGridSize` 設為 `(1000, 1000)`。
