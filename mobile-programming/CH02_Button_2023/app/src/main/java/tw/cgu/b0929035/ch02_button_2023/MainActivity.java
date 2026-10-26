package tw.cgu.b0929035.ch02_button_2023;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    int size = 30;
    public void smaller(View v) {
        TextView Txv = (TextView) findViewById(R.id.txv);
        if(size > 15){
            Txv.setTextSize(--size);
        }
    }
    public void bigger(View v) {
        TextView Txv = (TextView) findViewById(R.id.txv);
        Txv.setTextSize(++size);
    }
}