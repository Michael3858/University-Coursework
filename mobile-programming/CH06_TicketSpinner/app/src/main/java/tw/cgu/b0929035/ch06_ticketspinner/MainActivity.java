package tw.cgu.b0929035.ch06_ticketspinner;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView txv;
    Spinner cinema, time;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txv = (TextView) findViewById(R.id.txv);
        cinema = (Spinner) findViewById(R.id.cinema);
        time = (Spinner) findViewById(R.id.time);
    }

    public void order(View v){
        String[] cinemas = getResources().getStringArray(R.array.cinemas);
        String[] times = getResources().getStringArray(R.array.time);
        int index1 = cinema.getSelectedItemPosition();
        int index2 = time.getSelectedItemPosition();
        txv.setText("訂" + cinemas[index1] + times[index2] + "的票");
    }
}