package tw.cgu.b0929035.ch08_multiactivity;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void in(View v) {
        Intent intent = new Intent(this, SecondActivity.class);
        startActivity(intent);
    }
    public void bye(View v){
        finish();
    }
}