package tw.cgu.b0929035.afinal;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity implements AdapterView.OnItemClickListener {

    TextView showOrder, showHereOrGo;
    ListView ForhereOrTogo;
    String HereOrGo = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        showOrder = findViewById(R.id.showOrder);
        showHereOrGo = findViewById(R.id.showHereOrGo);
        ForhereOrTogo = findViewById(R.id.ForhereOrTogo);
        ForhereOrTogo.setOnItemClickListener(this);
        Intent intent = getIntent();
        String s = intent.getStringExtra("已點");
        showOrder.setText(s);
        if (s.equals("")) {
            showOrder.setText("妳沒點東西");
        }
    }

    public void checkTotal(View v)      //回點餐頁查看total
    {
        if (showHereOrGo.getText().toString().equals("")) {
            setResult(RESULT_CANCELED);
        } else {
            Intent intent2 = new Intent();
            intent2.putExtra("方式", HereOrGo);
            setResult(RESULT_OK, intent2);
        }
        finish();
    }

    @Override
    public void onItemClick(AdapterView<?> adapterView, View view, int pos, long id)    //選擇內用外帶方式
    {
        if (pos == 0) {
            HereOrGo = "內用";
            showHereOrGo.setText("你選擇內用");
        } else if (pos == 1) {
            HereOrGo = "外帶";
            showHereOrGo.setText("你選擇外帶");
        }
    }
}
