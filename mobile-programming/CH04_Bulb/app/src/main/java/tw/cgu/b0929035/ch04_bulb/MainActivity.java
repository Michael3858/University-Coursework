package tw.cgu.b0929035.ch04_bulb;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    ConstraintLayout background;
    TextView txv1, txv2, txv3, txv4;
    Button btn1, btn2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        background = findViewById(R.id.background);
        txv1 = findViewById(R.id.txv1);
        txv2 = findViewById(R.id.txv2);
        txv3 = findViewById(R.id.txv3);
        txv4 = findViewById(R.id.txv4);
        btn1 = findViewById(R.id.btn1);
        btn2 = findViewById(R.id.btn2);

        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                background.setBackgroundColor(Color.parseColor("#FFFFFF"));
                txv1.setVisibility(View.VISIBLE);
                txv2.setVisibility(View.INVISIBLE);
                txv3.setVisibility(View.INVISIBLE);
                txv4.setVisibility(View.INVISIBLE);
                btn1.setText("");
                btn2.setText("關燈");
            }
        });
        btn1.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                txv1.setVisibility(View.INVISIBLE);
                txv2.setVisibility(View.INVISIBLE);
                txv4.setVisibility(View.INVISIBLE);
                Random x = new Random();
                int r1 = x.nextInt(256);
                int g1 = x.nextInt(256);
                int b1 = x.nextInt(256);
                background.setBackgroundColor(Color.rgb(r1, g1, b1));
                int r2 = x.nextInt(256);
                while(r2 == r1){
                    r2 = x.nextInt(256);
                }
                int g2 = x.nextInt(256);
                while(g2 == g1){
                    g2 = x.nextInt(256);
                }
                int b2 = x.nextInt(256);
                while(b2 == b1){
                    b2 = x.nextInt(256);
                }
                txv3.setTextColor(Color.rgb(r2, g2, b2));
                txv3.setVisibility(View.VISIBLE);
                return true;
            }
        });
        btn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                background.setBackgroundColor(Color.parseColor("#000000"));
                txv2.setVisibility(View.VISIBLE);
                txv1.setVisibility(View.INVISIBLE);
                txv3.setVisibility(View.INVISIBLE);
                txv4.setVisibility(View.INVISIBLE);
                btn2.setText("");
                btn1.setText("開燈");
            }
        });
        btn2.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                background.setBackgroundColor(Color.parseColor("#000000"));
                txv4.setVisibility(View.VISIBLE);
                txv1.setVisibility(View.INVISIBLE);
                txv2.setVisibility(View.INVISIBLE);
                txv3.setVisibility(View.INVISIBLE);
                return true;
            }
        });
    }
}