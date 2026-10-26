package tw.cgu.b0929035.ch03_confirmidpw;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    EditText name, sub, phonenum, pw;
    TextView result;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        name = (EditText) findViewById(R.id.name);
        sub = (EditText) findViewById(R.id.sub);
        phonenum = (EditText) findViewById(R.id.phonenum);
        pw = (EditText) findViewById(R.id.pw);
        result = (TextView) findViewById(R.id.result);
    }
    public void onclick(View v){
        if(pw.getText().toString().equals("demo-pass")){
            result.setText(sub.getText().toString() + "的" + name.getText().toString() + "手機是\n" + phonenum.getText().toString());
        }
        else{
            result.setText("密碼錯誤");
        }
    }
}