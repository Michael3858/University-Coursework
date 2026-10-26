# 備忘編輯結果回傳

行動裝置程式設計課程練習。以 Intent 傳送備忘，透過 Activity 結果回傳更新清單，長按可清空項目。

## 程式導覽

| 檔案 | 內容 |
|---|---|
| [Edit.java](app/src/main/java/tw/cgu/b0929035/ch08_memo2/Edit.java) | 備忘編輯畫面。 |
| [MainActivity.java](app/src/main/java/tw/cgu/b0929035/ch08_memo2/MainActivity.java) | 主要畫面與事件處理。 |
| [activity_edit.xml](app/src/main/res/layout/activity_edit.xml) | 畫面配置。 |
| [activity_main.xml](app/src/main/res/layout/activity_main.xml) | 畫面配置。 |

備忘資料保存在記憶體陣列，沒有另外寫入檔案或資料庫。

## 開發環境

Java 8 語法、Android Gradle Plugin 7.2.1、Gradle 7.3.3，compile／target SDK 32，最低 SDK 26。使用 Android Studio 開啟本資料夾。
