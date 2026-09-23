package com.setting;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Intent;
import android.graphics.PorterDuff;
import android.graphics.drawable.LayerDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.TextView;

/* JADX INFO: loaded from: classes.dex */
public class Gof2Setting extends Activity {
    public static TextView screenscale_text;

    @Override // android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setRequestedOrientation(0);
        setting.DB(this);
        setting.DB().load();
        LinearLayout linearLayout = new LinearLayout(this);
        linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -1));
        linearLayout.setOrientation(1);
        linearLayout.setGravity(17);
        linearLayout.setBackgroundResource(getResources().getIdentifier("settings_bg", "drawable", getPackageName()));
        TextView textView = new TextView(this);
        screenscale_text = textView;
        textView.setText("Screen Scale: " + ((int) (setting.DB().screenscale * 100.0f)) + " %");
        textView.setTextColor(-985613);
        textView.setGravity(17);
        screenscale_text.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        SeekBar screenscale = new SeekBar(this);
        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(-1, -2);
        layoutParams.setMargins(96, 0, 96, 0);
        screenscale.setLayoutParams(layoutParams);
        screenscale.setMax(100);
        screenscale.setProgress(((int) (setting.DB().screenscale * 100.0f)) - 50);
        screenscale.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() { // from class: com.setting.Gof2Setting.1
            int progressChangedValue = 0;

            @Override // android.widget.SeekBar.OnSeekBarChangeListener
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int progress2 = progress + 50;
                this.progressChangedValue = progress2;
                setting.DB().screenscale = progress2 / 100.0f;
                Gof2Setting.screenscale_text.setText("Screen Scale: " + ((int) (setting.DB().screenscale * 100.0f)) + " %");
            }

            @Override // android.widget.SeekBar.OnSeekBarChangeListener
            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            @Override // android.widget.SeekBar.OnSeekBarChangeListener
            public void onStopTrackingTouch(SeekBar seekBar) {
            }
        });
        PorterDuff.Mode mode = PorterDuff.Mode.SRC_IN;
        LayerDrawable layerDrawable = (LayerDrawable) screenscale.getProgressDrawable();
        layerDrawable.findDrawableByLayerId(android.R.id.background).setColorFilter(-1, mode);
        layerDrawable.findDrawableByLayerId(android.R.id.progress).setColorFilter(-11887745, mode);
        screenscale.getThumb().setColorFilter(-38091, mode);
        Button save = new Button(this);
        save.setLayoutParams(new LinearLayout.LayoutParams(-2, -2));
        save.setText("Save and start the game");
        save.setBackgroundColor(-870960342);
        save.setTextColor(-985613);
        save.setOnClickListener(new View.OnClickListener() { // from class: com.setting.Gof2Setting.4
            @Override // android.view.View.OnClickListener
            public void onClick(View v) {
                setting.DB().save();
                Intent intent = new Intent();
                intent.setComponent(new ComponentName(net.fishlabs.gof2hdallandroid2012.BuildConfig.APPLICATION_ID, "net.fishlabs.gof2hdallandroid2012.DownloaderActivity"));
                Gof2Setting.this.startActivity(intent);
            }
        });
        linearLayout.addView(screenscale_text);
        linearLayout.addView(screenscale);
        linearLayout.addView(save);
        setContentView(linearLayout);
    }
}
