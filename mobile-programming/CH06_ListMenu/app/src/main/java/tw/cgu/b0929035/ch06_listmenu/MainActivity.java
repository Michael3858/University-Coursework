package tw.cgu.b0929035.ch06_listmenu;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemClickListener {

    ListView lv;
    TextView msgTxv;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lv = (ListView) findViewById(R.id.lv);
        lv.setOnItemClickListener(this);
    }

    ArrayList<String> selected = new ArrayList<>();

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        TextView txv = (TextView) view;
        String item = txv.getText().toString();
        if(selected.contains(item)){
            selected.remove(item);
        }
        else{
            selected.add(item);
        }
        String msg;
        if(selected.size() > 0){
            msg = "你夾了:";
            for(String str:selected){
                msg += " " + str;
            }
        }
        else{
            msg = "請選擇!";
        }
        msgTxv = (TextView) findViewById(R.id.msgTxv);
        msgTxv.setText(msg);
    }
}