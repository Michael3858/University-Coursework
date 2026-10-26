package tw.cgu.b0929035.ch03_randomcolor;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    Button btn;
    TextView red, green, blue;
    LinearLayout color;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void change(View v){
        btn = findViewById(R.id.btn);
        red = findViewById(R.id.red);
        green = findViewById(R.id.green);
        blue = findViewById(R.id.blue);
        color = findViewById(R.id.color);
        Random x = new Random();
        int r = x.nextInt(256);
        red.setText("紅：" + r);
        red.setTextColor(Color.rgb(r, 0, 0));
        int g = x.nextInt(256);
        green.setText("綠：" + g);
        green.setTextColor(Color.rgb(0, g, 0));
        int b = x.nextInt(256);
        blue.setText("藍：" + b);
        blue.setTextColor(Color.rgb(0, 0, b));
        color.setBackgroundColor(Color.rgb(r, g, b));
    }
}