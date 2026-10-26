# 期末作業 飲料點餐

行動裝置程式設計課程練習。整合連動選單、確認對話框與兩個 Activity，模擬飲料點餐與購物車。

## 程式導覽

| 檔案 | 內容 |
|---|---|
| [MainActivity.java](app/src/main/java/tw/cgu/b0929035/afinal/MainActivity.java) | 飲料、溫度選擇、加入購物車與總價。 |
| [MainActivity2.java](app/src/main/java/tw/cgu/b0929035/afinal/MainActivity2.java) | 已點餐品項、內用／外帶選擇與結果回傳。 |
| [activity_main.xml](app/src/main/res/layout/activity_main.xml) | 畫面配置。 |
| [activity_main2.xml](app/src/main/res/layout/activity_main2.xml) | 畫面配置。 |

可將飲料加入購物車，累積金額，再於第二個畫面選擇內用或外帶。清單與金額保存在 Activity 記憶體中，沒有串接資料庫或付款服務。

## 開發環境

Java 8 語法、Android Gradle Plugin 7.2.1、Gradle 7.3.3，compile／target SDK 32，最低 SDK 26。使用 Android Studio 開啟本資料夾。
