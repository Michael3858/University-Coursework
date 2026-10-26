package tw.cgu.b0929035.ch03_colorchange;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    LinearLayout background;
    TextView tv1, tv2, tv3;
    EditText et1, et2, et3;
    Button btn1, btn2, btn3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        background = findViewById(R.id.background);
        tv1 = findViewById(R.id.tv1);
        tv2 = findViewById(R.id.tv2);
        tv3 = findViewById(R.id.tv3);
        et1 = findViewById(R.id.et1);
        et2 = findViewById(R.id.et2);
        et3 = findViewById(R.id.et3);
        btn1 = findViewById(R.id.btn1);
        btn2 = findViewById(R.id.btn2);
        btn3 = findViewById(R.id.btn3);
        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                tv1.setTextColor(Color.rgb(Integer.parseInt(et1.getText().toString()), Integer.parseInt(et2.getText().toString()), Integer.parseInt(et3.getText().toString())));
                tv2.setTextColor(Color.rgb(Integer.parseInt(et1.getText().toString()), Integer.parseInt(et2.getText().toString()), Integer.parseInt(et3.getText().toString())));
                tv3.setTextColor(Color.rgb(Integer.parseInt(et1.getText().toString()), Integer.parseInt(et2.getText().toString()), Integer.parseInt(et3.getText().toString())));
            }
        });
        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                background.setBackgroundColor(Color.rgb(Integer.parseInt(et1.getText().toString()), Integer.parseInt(et2.getText().toString()), Integer.parseInt(et3.getText().toString())));
            }
        });
        btn3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Random x = new Random();
                int r = x.nextInt(256);
                tv1.setTextColor(Color.rgb(r, 0, 0));
                int g = x.nextInt(256);
                tv2.setTextColor(Color.rgb(0, g, 0));
                int b = x.nextInt(256);
                tv3.setTextColor(Color.rgb(0, 0, b));
                background.setBackgroundColor(Color.rgb(r, g, b));
            }
        });
    }
}