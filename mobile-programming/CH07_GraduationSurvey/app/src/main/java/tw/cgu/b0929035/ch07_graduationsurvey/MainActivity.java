package tw.cgu.b0929035.ch07_graduationsurvey;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements DialogInterface.OnClickListener {

    ImageView iv;
    TextView tv;
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        iv = (ImageView) findViewById(R.id.iv);
        tv = (TextView) findViewById(R.id.tv);
        btn = (Button) findViewById(R.id.btn);
        AlertDialog.Builder builder= new AlertDialog.Builder(this)
                .setMessage("你打算念研究所嗎?")
                .setCancelable(false)
                .setIcon(android.R.drawable.ic_menu_edit)
                .setTitle("畢業問卷調查")
                .setPositiveButton("打算", this)
                .setNegativeButton("不打算", this)
                .setNeutralButton("考慮中", this);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                builder.show();
            }
        });
    }

    @Override
    public void onClick(DialogInterface dialog, int which) {
        if(which == DialogInterface.BUTTON_POSITIVE){
            iv.setImageResource(R.drawable.leon);
            iv.setVisibility(View.VISIBLE);
            tv.setText("長庚五年一貫便宜又快速！");
            tv.setTextColor(Color.parseColor("#0000CC"));
            btn.setText("再問一遍");
        }
        else if(which == DialogInterface.BUTTON_NEGATIVE){
            iv.setImageResource(R.drawable.angrybird);
            iv.setVisibility(View.VISIBLE);
            tv.setText("可以慢慢找工作了！");
            tv.setTextColor(Color.parseColor("#FF0000"));
            btn.setText("再問一遍");
        }
        else if(which == DialogInterface.BUTTON_NEUTRAL){
            iv.setImageResource(R.drawable.elephant);
            iv.setVisibility(View.VISIBLE);
            tv.setText("祝你有個好的決定");
            tv.setTextColor(Color.parseColor("#00FF00"));
            btn.setText("再問一遍");
        }
    }
}