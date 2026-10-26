package tw.cgu.b0929035.ch05_temperatureconversion;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements RadioGroup.OnCheckedChangeListener, TextWatcher {

    RadioGroup group;
    EditText et;
    TextView degF, degC;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        group = findViewById(R.id.group);
        group.setOnCheckedChangeListener(this);

        et = findViewById(R.id.et);
        et.addTextChangedListener(this);

        degF = findViewById(R.id.degF);
        degC = findViewById(R.id.degC);
    }

    @Override
    public void beforeTextChanged(CharSequence s, int start, int count, int after) {

    }

    @Override
    public void onTextChanged(CharSequence s, int start, int before, int count) {

    }

    @Override
    public void afterTextChanged(Editable s) {
        calc();
    }

    @Override
    public void onCheckedChanged(RadioGroup group, int checkedId) {
        calc();
    }

    protected void calc(){
        double val, f, c;
        String s = et.getText().toString();
        try{
            val = Double.parseDouble(s);
        }
        catch (Exception e){
            val = 0;
        }
        if(group.getCheckedRadioButtonId() == R.id.rb1){
            f = val;
            c = (f - 32) * 5 / 9;
        }
        else{
            c = val;
            f = c * 9 / 5 + 32;
        }
        degF.setText(String.format("%.1f", f) + getResources().getString(R.string.charF));
        degC.setText(String.format("%.1f", c) + getResources().getString(R.string.charC));
    }

}