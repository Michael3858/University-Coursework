package tw.cgu.b0929035.ch05_buytickets;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView txv;
    Button btn;
    RadioGroup group;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txv = findViewById(R.id.txv);
        btn = findViewById(R.id.btn);
        group = findViewById(R.id.group);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(group.getCheckedRadioButtonId() == R.id.rb1){
                    txv.setText("買全票");
                }
                else if(group.getCheckedRadioButtonId() == R.id.rb2){
                    txv.setText("買半票");
                }
                else if(group.getCheckedRadioButtonId() == R.id.rb3){
                    txv.setText("買敬老票");
                }
            }
        });
    }
}