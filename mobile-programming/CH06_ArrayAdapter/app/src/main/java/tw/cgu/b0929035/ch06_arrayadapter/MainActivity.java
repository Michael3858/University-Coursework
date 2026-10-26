package tw.cgu.b0929035.ch06_arrayadapter;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    Spinner drink, temp;
    TextView txv;
    String[] tempSet1 = {"冰", "去冰", "溫"};
    String[] tempSet2 = {"冰", "去冰"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txv = (TextView) findViewById(R.id.order);
        temp = (Spinner) findViewById(R.id.temp);
        drink = (Spinner) findViewById(R.id.drink);

        drink.setOnItemSelectedListener(this);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String[] tempSet;
        if(position == 3){
            tempSet = tempSet2;
        }
        else{
            tempSet = tempSet1;
        }
        ArrayAdapter<String> tempAd = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, tempSet);
        tempAd.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        temp.setAdapter(tempAd);
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }

    public void showOrder(View v){
        String msg = drink.getSelectedItem() + ", " + temp.getSelectedItem();
        txv.setText(msg);
    }
}