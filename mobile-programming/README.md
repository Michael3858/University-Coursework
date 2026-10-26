# 行動裝置程式設計

大學行動裝置程式設計課的章節練習與期末作業，使用 Java 與 XML 練習 Android 畫面、事件處理、選單及 Activity 之間的資料傳遞。

## 專案內容

| 專案 | 內容 |
|---|---|
| [CH01_Hello_2023](CH01_Hello_2023/README.md) | 使用 TextView 顯示 Hello World，練習 Activity 與基本版面配置。 |
| [CH02_Button_2023](CH02_Button_2023/README.md) | 透過按鈕放大或縮小文字，練習 XML 的 onClick 事件。 |
| [CH02_EditText_2023](CH02_EditText_2023/README.md) | 讀取姓名輸入欄，顯示問候文字，並保留文字大小調整按鈕。 |
| [CH03_ColorChange](CH03_ColorChange/README.md) | 輸入 RGB 數值調整文字或背景，也可隨機產生配色。 |
| [CH03_ConfirmIDPW](CH03_ConfirmIDPW/README.md) | 讀取姓名、系級與電話，通過教學用固定密碼比對後顯示資料。 |
| [CH03_RandomColor](CH03_RandomColor/README.md) | 隨機產生 RGB 數值，顯示各色數字並改變文字及背景色。 |
| [CH03_Setting_Text_BackgroundColors](CH03_Setting_Text_BackgroundColors/README.md) | 將姓、名與電話串成結果文字，文字與背景色由 XML 版面設定。 |
| [CH04_Bulb](CH04_Bulb/README.md) | 以背景色與文字模擬開關燈，按一下或長按會切換不同顯示狀態。 |
| [CH04_EasyToUseCounter](CH04_EasyToUseCounter/README.md) | 按一下加 1、長按按鈕加 2，長按數值可歸零。 |
| [CH04_Massager](CH04_Massager/README.md) | 按下文字啟動最長 5 秒的震動，放開時停止。 |
| [CH04_MobileNeon](CH04_MobileNeon/README.md) | 觸控拖曳時隨機改變字色與背景並震動，放開後還原畫面。 |
| [CH05_BuySweetPotatoes](CH05_BuySweetPotatoes/README.md) | 用 RadioGroup 選擇斤或公斤，搭配 TextWatcher 即時換算單價、重量與總價。 |
| [CH05_buyTickets](CH05_buyTickets/README.md) | 用 RadioGroup 選擇全票、半票或敬老票，按下按鈕後顯示所選票種。 |
| [CH05_FoodMenu](CH05_FoodMenu/README.md) | 用 CheckBox 勾選餐點，顯示對應圖片與已選清單，練習勾選事件。 |
| [CH05_FoodMenuEvent](CH05_FoodMenuEvent/README.md) | 用 CheckBox 累積餐點清單，另以勾選控制結果文字大小。 |
| [CH05_temperatureConversion](CH05_temperatureConversion/README.md) | 用 RadioGroup 切換輸入單位，透過 TextWatcher 即時顯示攝氏與華氏結果。 |
| [CH06_ArrayAdapter](CH06_ArrayAdapter/README.md) | 依飲料選項切換溫度清單，使用 ArrayAdapter 更新第二個 Spinner。 |
| [CH06_ElectricityFeeComputer](CH06_ElectricityFeeComputer/README.md) | 選擇 110 或 220 伏特，輸入電流、每日使用時數與每度電費，估算 30 天費用。 |
| [CH06_EnergyCalculator](CH06_EnergyCalculator/README.md) | 選擇運動項目，依內建消耗率、體重與時間計算熱量，練習 Spinner 與數值輸入。 |
| [CH06_ListMenu](CH06_ListMenu/README.md) | 點選清單項目加入或移除餐點，將目前選擇顯示在文字區。 |
| [CH06_ResidencePlace](CH06_ResidencePlace/README.md) | 選擇北中南東區域後更新縣市 Spinner，再顯示居住地選擇。 |
| [CH06_TicketSpinner](CH06_TicketSpinner/README.md) | 透過兩個 Spinner 選擇影城與時間，顯示訂票文字。 |
| [CH07_BrainTeaser](CH07_BrainTeaser/README.md) | 使用 ArrayAdapter 建立題目清單，點選後以 Toast 顯示答案。 |
| [CH07_BrainTeaser2](CH07_BrainTeaser2/README.md) | 點選題目後更新同一個 Toast 的答案，練習 ListView 與訊息重用。 |
| [CH07_DateTimePicker](CH07_DateTimePicker/README.md) | 使用 DatePickerDialog 與 TimePickerDialog 選擇日期時間，並更新文字與顏色。 |
| [CH07_GraduationSurvey](CH07_GraduationSurvey/README.md) | 用 AlertDialog 的三種按鈕回應升學問卷，切換圖片、文字與顏色。 |
| [CH08_Memo](CH08_Memo/README.md) | 點選備忘以 Intent 傳值到編輯畫面，長按可清空清單項目。 |
| [CH08_Memo2](CH08_Memo2/README.md) | 以 Intent 傳送備忘，透過 Activity 結果回傳更新清單，長按可清空項目。 |
| [CH08_MultiActivity](CH08_MultiActivity/README.md) | 使用 Intent 開啟第二、第三與第四個畫面，透過 finish() 返回。 |
| [final](final/README.md) | 整合連動選單、確認對話框與兩個 Activity，模擬飲料點餐與購物車。 |

## 開發環境

Android Studio、Java 8 語法、Android Gradle Plugin 7.2.1、Gradle 7.3.3；compile／target SDK 32，最低 SDK 26。

各資料夾是獨立的 Android Studio 專案，請開啟對應的專案資料夾。每份 README 列有主要程式與畫面檔案。

`final` 為飲料點餐與購物車作業，包含溫度選擇、總價與內用／外帶選項。
