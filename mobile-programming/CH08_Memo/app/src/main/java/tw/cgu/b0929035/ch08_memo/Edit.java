package tw.cgu.b0929035.ch08_memo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class Edit extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit);

        Intent intent = getIntent();
        int no = intent.getIntExtra("編號", 0);
        String s = intent.getStringExtra("備忘");
        TextView txv = (TextView) findViewById(R.id.txv);
        txv.setText(no + ".");
        EditText edt = (EditText) findViewById(R.id.edt);
        if(s.length() > 3){
            edt.setText(s.substring(3));
        }
    }

    public void onCancel(View v){
        finish();
    }
    public void onSave(View v){
        finish();
    }
}