# 平行程式設計作業

大學平行程式設計課的兩次作業。PA1 練習多個程序交換訊息，PA2 把計算 π 的工作分給多個執行緒，觀察不同寫法與工作量的執行時間。

## 程式導覽

| 檔案 | 在做什麼 |
|---|---|
| [PPD_PA1_B0929035_1.c](PA1/PPD_PA1_B0929035_1.c) | 使用 `MPI_Send`、`MPI_Recv`，由 Rank 0 發送訊息，其他程序回覆。 |
| [PPD_PA1_B0929035_2.c](PA1/PPD_PA1_B0929035_2.c) | 改用 `MPI_Isend`、`MPI_Irecv`；每次呼叫後接著 `MPI_Wait` 等待完成。 |
| [PPD_PA1_B0929035_3.c](PA1/PPD_PA1_B0929035_3.c) | 使用 `MPI_Scatter` 分發訊息，再用 `MPI_Gather` 收集回覆。 |
| [PPD_PA2_B0929035_1.c](PA2/PPD_PA2_B0929035_1.c) | 四個執行緒各自加總，最後透過 `critical` 合併，估算 π。 |
| [PPD_PA2_B0929035_2.c](PA2/PPD_PA2_B0929035_2.c) | 使用 `parallel for`，每次迴圈在 `critical` 中累加。 |
| [PPD_PA2_B0929035_3.c](PA2/PPD_PA2_B0929035_3.c) | 保留的另一份 `parallel for`／`critical` 版本，內容與第 2 支相近。 |
| [PPD_PA2_B0929035_4.c](PA2/PPD_PA2_B0929035_4.c) | 使用 `reduction`，比較不同執行緒數與計算步數，將結果寫入文字檔。 |

## 開發環境

C、MPI 與 OpenMP。PA2 使用 `getrusage`、`sys/resource.h`，需要支援這些介面的環境，例如 Linux。

## 執行說明

PA1 以 5 個程序為設定：前兩支會檢查數量，第 3 支也只有 5 份分發資料。PA2 第 4 支輸出的 `speedup_results.txt` 記錄執行緒數與耗時，加速比需另行計算。
