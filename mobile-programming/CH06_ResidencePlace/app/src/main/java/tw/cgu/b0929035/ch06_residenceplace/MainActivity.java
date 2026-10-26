package tw.cgu.b0929035.ch06_residenceplace;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    Spinner area, place;
    TextView result;
    String[] p1 = {"宜蘭", "基隆", "台北", "桃園", "新竹", "苗栗"};
    String[] p2 = {"台中", "彰化", "南投"};
    String[] p3 = {"高雄", "嘉義", "台南", "屏東"};
    String[] p4 = {"花蓮", "台東"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        area = (Spinner) findViewById(R.id.area);
        place = (Spinner) findViewById(R.id.place);
        result = (TextView) findViewById(R.id.result);

        area.setOnItemSelectedListener(this);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String[] p = new String[0];
        if(position == 0){
            p = p1;
        }
        else if(position == 1){
            p = p2;
        }
        else if(position == 2){
            p = p3;
        }
        else if(position == 3){
            p = p4;
        }
        ArrayAdapter<String> placeAd = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, p);
        placeAd.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        place.setAdapter(placeAd);
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }

    public void showResult(View v){
        String msg = "您住在" + area.getSelectedItem() + "的" + place.getSelectedItem();
        result.setText(msg);
    }
}