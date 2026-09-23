using System; using UnityEngine; using GoF2Remake.Flight;
public static class Sim { public static void Main(){
  string[] names={"Betty","Betty+Pulsed Plasma","handling 60"}; float[] hs={120f,120f,60f}; float[] ags={0f,130f,0f};
  for(int k=0;k<3;k++){ string name=names[k]; float h=hs[k], ag=ags[k];
   var m=new GoF2FlightModel(); m.Configure(new FlightStats{handling=h,agility=ag,boostSpeed=60,boostDurationMs=3000,boostRechargeMs=8000});
   float t=0, yawDeg=0; float tMax=-1;
   for(int i=0;i<60;i++){ var r=m.Step(new Vector2(1,0),16.67f,new Vector3(0,1,0),new Vector3(1,0,0)); yawDeg+=r.yawDeg; t+=16.67f; if(tMax<0 && Math.Abs(m.YawRate)>=Math.Abs((int)(750*m.Handling)/63)-0.01) tMax=t; }
   float stopT=0; while(Math.Abs(m.YawRate)>0.001f){ m.Step(new Vector2(0,0),16.67f,new Vector3(0,1,0),new Vector3(1,0,0)); stopT+=16.67f; }
   Console.WriteLine($"{name}: H={m.Handling:F1} maxTurn={m.MaxTurnRateDegPerSec:F1} deg/s, reach max in {tMax:F0} ms, yawed {yawDeg:F1} deg in 1s, stop after release {stopT:F0} ms");
  }
  var b=new GoF2FlightModel(); b.Configure(new FlightStats{handling=120,boostSpeed=60,boostDurationMs=3000,boostRechargeMs=8000});
  b.Boost(); float d=0; for(int i=0;i<200;i++){ var r=b.Step(new Vector2(0,0),16.67f,new Vector3(0,1,0),new Vector3(1,0,0)); d+=r.forwardUnits; if(i%30==0) Console.WriteLine($"t={i*16.67:F0}ms boosting={b.IsBoosting} speed={b.CurrentSpeed} vis={b.BoostVisualPercent:F2} ready={b.BoostReady} recharge={b.BoostRechargePercent:F2}"); }
}}
