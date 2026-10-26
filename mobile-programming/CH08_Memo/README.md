# 備忘清單與編輯畫面

行動裝置程式設計課程練習。點選備忘以 Intent 傳值到編輯畫面，長按可清空清單項目。

## 程式導覽

| 檔案 | 內容 |
|---|---|
| [Edit.java](app/src/main/java/tw/cgu/b0929035/ch08_memo/Edit.java) | 備忘編輯畫面。 |
| [MainActivity.java](app/src/main/java/tw/cgu/b0929035/ch08_memo/MainActivity.java) | 主要畫面與事件處理。 |
| [activity_edit.xml](app/src/main/res/layout/activity_edit.xml) | 畫面配置。 |
| [activity_main.xml](app/src/main/res/layout/activity_main.xml) | 畫面配置。 |

`Edit.onSave()` 目前僅關閉編輯畫面，沒有把修改內容回傳清單；完整的結果回傳練習放在 `CH08_Memo2`。

## 開發環境

Java 8 語法、Android Gradle Plugin 7.2.1、Gradle 7.3.3，compile／target SDK 32，最低 SDK 26。使用 Android Studio 開啟本資料夾。
