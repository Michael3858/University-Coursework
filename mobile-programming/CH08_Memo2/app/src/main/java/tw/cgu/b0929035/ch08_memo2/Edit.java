package tw.cgu.b0929035.ch08_memo2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class Edit extends AppCompatActivity {

    TextView txv;
    EditText edt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit);

        Intent intent = getIntent();
        String s = intent.getStringExtra("備忘");
        txv = (TextView) findViewById(R.id.txv);
        txv.setText(s.substring(0, 2));
        edt = (EditText) findViewById(R.id.edt);
        if(s.length() > 3){
            edt.setText(s.substring(3));
        }
    }
    public void onCancel(View v){
        setResult(RESULT_CANCELED);
        finish();
    }
    public void onSave(View v){
        Intent intent2 = new Intent();
        intent2.putExtra("備忘", txv.getText().toString() + " " + edt.getText().toString());
        setResult(RESULT_OK, intent2);
        finish();
    }
}