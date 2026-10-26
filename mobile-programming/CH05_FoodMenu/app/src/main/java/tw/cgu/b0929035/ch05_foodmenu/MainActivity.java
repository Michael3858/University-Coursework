package tw.cgu.b0929035.ch05_foodmenu;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity implements CompoundButton.OnCheckedChangeListener {

    ArrayList<CompoundButton> selected = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int[] chk_id = {R.id.chk1, R.id.chk2, R.id.chk3, R.id.chk4};
        for(int id:chk_id){
            ((CheckBox) findViewById(id)).setOnCheckedChangeListener(this);
        }
    }

    public void takeOrder(View v){
        String msg2 = "";
        for(CompoundButton chk:selected){
            msg2 += "\n" + chk.getText();
        }
        if(msg2.length() > 0){
            msg2 = "妳點購的餐點是:" + msg2;
        }
        else{
            msg2 = "請點餐!";
        }
        ((TextView) findViewById(R.id.showOrder)).setText(msg2);
    }

    int items = 0;
    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
        int visible;
        if(isChecked){
            items++;
            visible = View.VISIBLE;
            selected.add(buttonView);
        }
        else{
            items--;
            visible = View.GONE;
            selected.remove(buttonView);
        }
        switch (buttonView.getId()){
            case R.id.chk1:
                findViewById(R.id.output1).setVisibility(visible);
                break;
            case R.id.chk2:
                findViewById(R.id.output2).setVisibility(visible);
                break;
            case R.id.chk3:
                findViewById(R.id.output3).setVisibility(visible);
                break;
            case R.id.chk4:
                findViewById(R.id.output4).setVisibility(visible);
                break;
        }
        String msg;
        if(items > 0){
            msg = "妳點的餐如下:";
        }
        else{
            msg = "請點餐!";
        }
        ((TextView) findViewById(R.id.showOrder)).setText(msg);
    }
}