package tw.cgu.b0929035.ch08_memo2;

import androidx.activity.result.ActivityResultCallback;
import androidx.activity.result.contract.ActivityResultContract;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemClickListener, AdapterView.OnItemLongClickListener {

    String[] aMemo = {"1. 按一下可以編輯備忘", "2. 長按可以清除備忘", "3. ", "4. ", "5. ", "6. "};
    ListView lv;
    ArrayAdapter<String> aa;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        lv = (ListView) findViewById(R.id.lv);
        aa = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, aMemo);
        lv.setAdapter(aa);
        lv.setOnItemClickListener(this);
        lv.setOnItemLongClickListener(this);
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        Intent intent = new Intent(this, Edit.class);
        intent.putExtra("備忘", aMemo[position]);
        startActivityForResult(intent, position);
    }

    @Override
    public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
        aMemo[position] = (position + 1) + ".";
        aa.notifyDataSetChanged();
        return true;
    }

    protected void onActivityResult(int requestCode, int resultCode, Intent it) {
        super.onActivityResult(requestCode, resultCode, it);
        if(resultCode == RESULT_OK){
            aMemo[requestCode] = it.getStringExtra("備忘");
            aa.notifyDataSetChanged();
        }
    }
}