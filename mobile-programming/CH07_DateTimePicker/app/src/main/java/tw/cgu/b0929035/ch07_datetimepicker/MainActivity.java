package tw.cgu.b0929035.ch07_datetimepicker;

import androidx.appcompat.app.AppCompatActivity;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.DatePicker;
import android.widget.TextView;
import android.widget.TimePicker;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity implements View.OnClickListener, DatePickerDialog.OnDateSetListener, TimePickerDialog.OnTimeSetListener {

    Calendar c = Calendar.getInstance();
    TextView txDate, txTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txDate = (TextView) findViewById(R.id.txv1);
        txTime = (TextView) findViewById(R.id.txv2);
        txDate.setOnClickListener(this);
        txTime.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        if(v == txDate){
            new DatePickerDialog(this, this, c.get(Calendar.YEAR), c.get(Calendar.MONTH), c.get(Calendar.DAY_OF_MONTH)).show();
        }
        else if(v == txTime){
            new TimePickerDialog(this, this, c.get(Calendar.HOUR_OF_DAY), c.get(Calendar.MINUTE), true).show();
        }
    }

    @Override
    public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
        txDate.setText("您設定的日期為\n" + year + "年" + (month + 1) + "月" + dayOfMonth + "日");
        txDate.setTextColor(Color.parseColor("#0000FF"));
    }

    @Override
    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
        txTime.setText("您設定的時間為\n" + hourOfDay + "點" + minute + "分");
        txTime.setTextColor(Color.parseColor("#0000FF"));
    }
}