package net.fishlabs.gof2hdallandroid2012;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.view.WindowManager;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class AccelerometerManager {
    private static int deviceRotation = 0;
    private static int interval = 1000;
    private static AccelerometerListener listener = null;
    private static boolean running = false;
    private static Sensor sensor = null;
    private static SensorEventListener sensorEventListener = new SensorEventListener() { // from class: net.fishlabs.gof2hdallandroid2012.AccelerometerManager.1
        private float force = 0.0f;
        private long lastShake = 0;
        private long lastUpdate = 0;
        private float lastX = 0.0f;
        private float lastY = 0.0f;
        private float lastZ = 0.0f;
        private long now = 0;
        private long timeDiff = 0;
        private float x = 0.0f;
        private float y = 0.0f;
        private float z = 0.0f;

        @Override // android.hardware.SensorEventListener
        public void onAccuracyChanged(Sensor sensor2, int i) {
        }

        @Override // android.hardware.SensorEventListener
        public void onSensorChanged(SensorEvent sensorEvent) {
            this.now = sensorEvent.timestamp;
            this.x = sensorEvent.values[0];
            this.y = sensorEvent.values[1];
            this.z = sensorEvent.values[2];
            int[] iArr = {-1, 2, 2, 1, 1, -2, -2, -1};
            int[] iArr2 = {-1, 1, 1, 1, 1, -1, -1, -1};
            float[] fArr = {this.x, this.y, this.z};
            int i = AccelerometerManager.deviceRotation * 2;
            float f = iArr2[i] * fArr[Math.abs(iArr[i]) - 1];
            int i2 = i + 1;
            float f2 = iArr2[i2] * fArr[Math.abs(iArr[i2]) - 1];
            this.x = f;
            this.y = f2;
            if (this.lastUpdate == 0) {
                this.lastUpdate = this.now;
                this.lastShake = this.now;
                this.lastX = this.x;
                this.lastY = this.y;
                this.lastZ = this.z;
            } else {
                this.timeDiff = this.now - this.lastUpdate;
                if (this.timeDiff > 0) {
                    this.force = Math.abs(((((this.x + this.y) + this.z) - this.lastX) - this.lastY) - this.lastZ) / this.timeDiff;
                    if (this.force > AccelerometerManager.threshold) {
                        if (this.now - this.lastShake >= AccelerometerManager.interval) {
                            AccelerometerManager.listener.onShake(this.force);
                        }
                        this.lastShake = this.now;
                    }
                    this.lastX = this.x;
                    this.lastY = this.y;
                    this.lastZ = this.z;
                    this.lastUpdate = this.now;
                }
            }
            this.x /= 10.0f;
            this.y /= 10.0f;
            this.z /= 10.0f;
            AccelerometerManager.listener.onAccelerationChanged(this.x, this.y, this.z);
        }
    };
    private static SensorManager sensorManager = null;
    private static Boolean supported = null;
    private static float threshold = 0.2f;

    public static void configure(int i, int i2) {
        threshold = i;
        interval = i2;
    }

    public static boolean isListening() {
        return running;
    }

    public static boolean isSupported() {
        if (supported == null) {
            if (GOF2HD2012.getGOFContext() != null) {
                sensorManager = (SensorManager) GOF2HD2012.getGOFContext().getSystemService("sensor");
                supported = new Boolean(sensorManager.getSensorList(1).size() > 0);
            } else {
                supported = Boolean.FALSE;
            }
        }
        return supported.booleanValue();
    }

    public static void startListening(AccelerometerListener accelerometerListener) {
        sensorManager = (SensorManager) GOF2HD2012.getGOFContext().getSystemService("sensor");
        List<Sensor> sensorList = sensorManager.getSensorList(1);
        if (sensorList.size() > 0) {
            deviceRotation = ((WindowManager) GOF2HD2012.getGOFContext().getSystemService("window")).getDefaultDisplay().getRotation();
            sensor = sensorList.get(0);
            running = sensorManager.registerListener(sensorEventListener, sensor, 1);
            listener = accelerometerListener;
        }
    }

    public static void startListening(AccelerometerListener accelerometerListener, int i, int i2) {
        configure(i, i2);
        startListening(accelerometerListener);
    }

    public static void stopListening() {
        running = false;
        try {
            if (sensorManager == null || sensorEventListener == null) {
                return;
            }
            sensorManager.unregisterListener(sensorEventListener);
        } catch (Exception unused) {
        }
    }
}
