package tw.cgu.b0929035.ch04_mobileneon;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Vibrator;
import android.view.MotionEvent;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    TextView txv;
    ConstraintLayout background;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txv = (TextView) findViewById(R.id.txv);
        background = (ConstraintLayout) findViewById(R.id.background);
    }

    @Override
    public boolean onTouchEvent(MotionEvent e){
        Vibrator vb = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
        if(e.getAction() == MotionEvent.ACTION_DOWN){
            vb.vibrate(new long[]{0, 100, 1000, 100}, 2);
            txv.setText("七彩霓虹燈\n震動中");
            txv.setTextSize(50);
        }
        else if(e.getAction() == MotionEvent.ACTION_MOVE){
            vb.vibrate(new long[]{0, 100, 1000, 100}, 2);
            txv.setText("七彩霓虹燈\n震動中");
            txv.setTextSize(50);
            Random x = new Random();
            int r1 = x.nextInt(256);
            int g1 = x.nextInt(256);
            int b1 = x.nextInt(256);
            txv.setTextColor(Color.rgb(r1, g1, b1));
            int r2 = x.nextInt(256);
            int g2 = x.nextInt(256);
            int b2 = x.nextInt(256);
            background.setBackgroundColor(Color.rgb(r2, g2, b2));
        }
        else if(e.getAction() == MotionEvent.ACTION_UP){
            txv.setText("動霓虹");
            txv.setTextSize(40);
            txv.setTextColor(Color.parseColor("#FFFFFF"));
            background.setBackgroundColor(Color.parseColor("#000000"));
            vb.cancel();
        }
        return true;
    }
}