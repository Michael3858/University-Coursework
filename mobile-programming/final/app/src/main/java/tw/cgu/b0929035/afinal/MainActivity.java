package tw.cgu.b0929035.afinal;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener, DialogInterface.OnClickListener {

    Spinner drink, temp;
    TextView showResult;
    String[] tempset1 = {"冰", "去冰", "溫", "熱"};
    String[] tempset2 = {"冰", "去冰"};
    String OrderedStuff = "";     //已點飲料
    int[] price = {70, 55, 60, 65, 40};   //飲料價位
    int total = 0;    //總價
    String HereOrGo = "您尚未選擇內用或外帶";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        temp = findViewById(R.id.temp);
        drink = findViewById(R.id.drink);
        drink.setOnItemSelectedListener(this);
        showResult = findViewById(R.id.showResult);
    }

    @Override
    public void onItemSelected(AdapterView<?> adapterView, View view, int pos, long id)
    //選單部分
    {
        String[] tempSet = new String[0];
        if (pos == 1 || pos == 2) {
            tempSet = tempset1;
        } else if (pos == 0 || pos == 3 || pos == 4) {
            tempSet = tempset2;
        }
        ArrayAdapter<String> ad = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, tempSet);
        ad.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        temp.setAdapter(ad);
    }

    @Override
    public void onNothingSelected(AdapterView<?> adapterView) {

    }

    public void Order(View v)       //order的onclick
    {
        String[] str = getResources().getStringArray(R.array.drink);
        int index1 = drink.getSelectedItemPosition();
        String[] tempSet = new String[0];
        if (index1 == 1 || index1 == 2) {
            tempSet = tempset1;
        } else if (index1 == 0 || index1 == 3 || index1 == 4) {
            tempSet = tempset2;
        }
        int index2 = temp.getSelectedItemPosition();
        AlertDialog.Builder bdr = new AlertDialog.Builder(this);
        bdr.setMessage("妳確定要點" + str[index1]  + "," + tempSet[index2] + "嗎?")
                .setTitle("請確認")
                .setIcon(android.R.drawable.ic_menu_edit)
                .setPositiveButton("確定", this)
                .setNegativeButton("取消", this)
                .show();
    }

    @Override
    public void onClick(DialogInterface dialogInterface, int btn)       //是否加入購物車
    {
        String[] str = getResources().getStringArray(R.array.drink);
        int index1 = drink.getSelectedItemPosition();
        String[] tempSet = new String[0];
        if (index1 == 1 || index1 == 2) {
            tempSet = tempset1;
        } else if (index1 == 0 || index1 == 3 || index1 == 4) {
            tempSet = tempset2;
        }
        int index2 = temp.getSelectedItemPosition();
        if (btn == Dialog.BUTTON_NEGATIVE) {
            Toast.makeText(this, "已取消", Toast.LENGTH_SHORT).show();
        } else if (btn == Dialog.BUTTON_POSITIVE) {
            total += price[index1];
            Toast.makeText(this, "已加入購物車", Toast.LENGTH_SHORT).show();
            showResult.setText("總價:" + total + "\n" + HereOrGo);
            OrderedStuff += str[index1]  + "," + tempSet[index2] + "\n";
        }
    }

    public void gocart(View v)      //檢視購物車
    {
        Intent intent = new Intent(this, MainActivity2.class);
        intent.putExtra("已點", OrderedStuff);
        startActivityForResult(intent, 1);
    }

    @SuppressLint("SuspiciousIndentation")
    protected void onActivityResult(int requestCode, int resultCode, Intent it) {   //顯示總價及內用外帶方式
        super.onActivityResult(requestCode, resultCode, it);
        if (resultCode == RESULT_OK) {
            HereOrGo = it.getStringExtra("方式");
            showResult.setText("總價:" + total + "\n" + HereOrGo);
        }
    }
}
