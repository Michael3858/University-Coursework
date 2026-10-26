package tw.cgu.b0929035.ch05_buysweetpotatoes;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements RadioGroup.OnCheckedChangeListener, TextWatcher {

    RadioGroup group1, group2;
    EditText et1, et2;
    TextView txv1, txv2, txv3, txv4, txv5;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        group1 = findViewById(R.id.group1);
        group1.setOnCheckedChangeListener(this);
        group2 = findViewById(R.id.group2);
        group2.setOnCheckedChangeListener(this);
        et1 = findViewById(R.id.et1);
        et1.addTextChangedListener(this);
        et2 = findViewById(R.id.et2);
        et2.addTextChangedListener(this);
        txv1 = findViewById(R.id.txv1);
        txv2 = findViewById(R.id.txv2);
        txv3 = findViewById(R.id.txv3);
        txv4 = findViewById(R.id.txv4);
        txv5 = findViewById(R.id.txv5);
    }

    @Override
    public void beforeTextChanged(CharSequence s, int start, int count, int after) {

    }

    @Override
    public void onTextChanged(CharSequence s, int start, int before, int count) {

    }

    @Override
    public void afterTextChanged(Editable s) {
        calc();
    }

    @Override
    public void onCheckedChanged(RadioGroup group, int checkedId) {
        calc();
    }

    protected void calc(){
        double val1, val2, n1, n2, n3, n4;
        String s1 = et1.getText().toString();
        String s2 = et2.getText().toString();
        try{
            val1 = Double.parseDouble(s1);
            val2 = Double.parseDouble(s2);
        }
        catch (Exception e){
            val1 = 0;
            val2 = 0;
        }
        if(group1.getCheckedRadioButtonId() == R.id.rb1_1){
            n1 = val1;
            n2 = val1 / 0.6;
            if(s1.equals("")){
                txv5.setText("請輸入重量");
            }
            else if(s2.equals("")){
                txv5.setText("請輸入單價");
            }
            else{
                txv1.setText("每斤價錢:" + String.format("%.1f", n1));
                txv2.setText("每公斤價錢:" + String.format("%.1f", n2));
                if(group2.getCheckedRadioButtonId() == R.id.rb2_1){
                    n3 = val2;
                    n4 = val2 * 0.6;
                    if(s1.equals("")){
                        txv5.setText("請輸入單價");
                    }
                    else if(s2.equals("")){
                        txv5.setText("請輸入重量");
                    }
                    else{
                        txv3.setText(String.format("%.1f", n3) + "斤");
                        txv4.setText(String.format("%.1f", n4) + "公斤");
                        txv5.setText("總共" + String.format("%.1f", (n1 * n3)) + "元");
                    }
                }
                else if(group2.getCheckedRadioButtonId() == R.id.rb2_2) {
                    n3 = val2 / 0.6;
                    n4 = val2;
                    if(s1.equals("")){
                        txv5.setText("請輸入單價");
                    }
                    else if(s2.equals("")){
                        txv5.setText("請輸入重量");
                    }
                    else{
                        txv3.setText(String.format("%.1f", n3) + "斤");
                        txv4.setText(String.format("%.1f", n4) + "公斤");
                        txv5.setText("總共" + String.format("%.1f", (n2 * n4)) + "元");
                    }
                }
            }
        }
        else if(group1.getCheckedRadioButtonId() == R.id.rb1_2){
            n1 = val1 * 0.6;
            n2 = val1;
            if(s1.equals("")){
                txv5.setText("請輸入單價");
            }
            else if(s2.equals("")){
                txv5.setText("請輸入重量");
            }
            else{
                txv1.setText("每斤價錢:" + String.format("%.1f", n1));
                txv2.setText("每公斤價錢:" + String.format("%.1f", n2));
                if(group2.getCheckedRadioButtonId() == R.id.rb2_1){
                    n3 = val2;
                    n4 = val2 * 0.6;
                    if(s1.equals("")){
                        txv5.setText("請輸入單價");
                    }
                    else if(s2.equals("")){
                        txv5.setText("請輸入重量");
                    }
                    else{
                        txv3.setText(String.format("%.1f", n3) + "斤");
                        txv4.setText(String.format("%.1f", n4) + "公斤");
                        txv5.setText("總共" + String.format("%.1f", (n1 * n3)) + "元");
                    }
                }
                else if(group2.getCheckedRadioButtonId() == R.id.rb2_2) {
                    n3 = val2 / 0.6;
                    n4 = val2;
                    if(s1.equals("")){
                        txv5.setText("請輸入單價");
                    }
                    else if(s2.equals("")){
                        txv5.setText("請輸入重量");
                    }
                    else{
                        txv3.setText(String.format("%.1f", n3) + "斤");
                        txv4.setText(String.format("%.1f", n4) + "公斤");
                        txv5.setText("總共" + String.format("%.1f", (n2 * n4)) + "元");
                    }
                }
            }
        }
    }
}