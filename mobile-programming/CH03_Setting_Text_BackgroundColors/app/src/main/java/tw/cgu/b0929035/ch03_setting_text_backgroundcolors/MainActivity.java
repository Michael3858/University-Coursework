package tw.cgu.b0929035.ch03_setting_text_backgroundcolors;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    EditText name1, name2, phonenum;
    TextView result;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        name1 = (EditText) findViewById(R.id.name1);
        name2 = (EditText) findViewById(R.id.name2);
        phonenum = (EditText) findViewById(R.id.phonenum);
        result = (TextView) findViewById(R.id.result);
    }
    public void onclick(View v){
        result.setText(name1.getText().toString() + name2.getText().toString() + "的電話是\n" + phonenum.getText().toString());
    }
}