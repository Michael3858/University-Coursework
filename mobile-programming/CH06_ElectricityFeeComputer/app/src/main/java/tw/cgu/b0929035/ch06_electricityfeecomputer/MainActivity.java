package tw.cgu.b0929035.ch06_electricityfeecomputer;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener, TextWatcher {

    EditText edt1, edt2, edt3;
    TextView result;
    Spinner spinner;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edt1 = (EditText) findViewById(R.id.edt1);
        edt1.addTextChangedListener(this);
        edt2 = (EditText) findViewById(R.id.edt2);
        edt2.addTextChangedListener(this);
        edt3 = (EditText) findViewById(R.id.edt3);
        edt3.addTextChangedListener(this);
        result = (TextView) findViewById(R.id.result);
        spinner = (Spinner) findViewById(R.id.spinner);
        spinner.setOnItemSelectedListener(this);
    }

    @Override
    public void beforeTextChanged(CharSequence s, int start, int count, int after) {

    }

    @Override
    public void onTextChanged(CharSequence s, int start, int before, int count) {

    }

    @Override
    public void afterTextChanged(Editable s) {
        String e1 = edt1.getText().toString();
        String e2 = edt2.getText().toString();
        String e3 = edt3.getText().toString();
        Double ans = 0.0;
        int pos = spinner.getSelectedItemPosition();
        if(e1.isEmpty() || e1.equals(".") || e2.isEmpty() || e2.equals(".") || e3.isEmpty() || e3.equals(".")){
            result.setText("請輸入完整資訊");
        }
        else{
            if(pos == 0){
                ans = 110 * Double.parseDouble(e1) * Double.parseDouble(e2) * Double.parseDouble(e3) / 1000 * 30;
            }
            else if(pos == 1){
                ans = 220 * Double.parseDouble(e1) * Double.parseDouble(e2) * Double.parseDouble(e3) / 1000 * 30;
            }
            result.setText("$" + String.format("%.1f", ans));
        }
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String e1 = edt1.getText().toString();
        String e2 = edt2.getText().toString();
        String e3 = edt3.getText().toString();
        Double ans = 0.0;
        int pos = spinner.getSelectedItemPosition();
        if(e1.isEmpty() || e1.equals(".") || e2.isEmpty() || e2.equals(".") || e3.isEmpty() || e3.equals(".")){
            result.setText("請輸入完整資訊");
        }
        else{
            if(pos == 0){
                ans = 110 * Double.parseDouble(e1) * Double.parseDouble(e2) * Double.parseDouble(e3) / 1000 * 30;
            }
            else if(pos == 1){
                ans = 220 * Double.parseDouble(e1) * Double.parseDouble(e2) * Double.parseDouble(e3) / 1000 * 30;
            }
            result.setText("$" + String.format("%.1f", ans));
        }
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}