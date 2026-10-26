package tw.cgu.b0929035.ch08_multiactivity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
    }
    public void go3(View v){
        Intent intent = new Intent(this, ThirdActivity.class);
        startActivity(intent);
    }
    public void go4(View v){
        Intent intent = new Intent(this, FourthActivity.class);
        startActivity(intent);
    }
    public void back(View v){
        finish();
    }
}