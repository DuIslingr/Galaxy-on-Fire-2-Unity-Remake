using System;
namespace UnityEngine {
  public class Object {}
  public class Component : Object { public Transform transform; public T GetComponent<T>() => default; }
  public class Behaviour : Component {}
  public class MonoBehaviour : Behaviour {}
  public class TextAsset : Object { public string text; }
  public class Camera : Behaviour { public float fieldOfView; }
  public static class Resources { public static T Load<T>(string p) where T: Object => null; }
  public static class Debug { public static void LogWarning(object o){} }
  public static class Application { public static bool isPlaying; }
  public static class Time { public static float deltaTime; }
  public enum KeyCode { E, Q, Space, R }
  public enum Space { Self, World }
  public static class Input { public static float GetAxis(string s)=>0; public static bool GetKey(KeyCode k)=>false; public static bool GetKeyDown(KeyCode k)=>false; }
  public class Transform : Component { public Vector3 position, forward, right, up; public Quaternion rotation, localRotation;
    public void Rotate(float x,float y,float z,Space s){} public Vector3 TransformPoint(Vector3 v)=>v; }
  public struct Vector2 { public float x,y; public Vector2(float a,float b){x=a;y=b;} public static Vector2 ClampMagnitude(Vector2 v,float m)=>v; }
  public struct Vector3 { public float x,y,z; public Vector3(float a,float b,float c){x=a;y=b;z=c;} public static Vector3 zero; public static Vector3 up;
    public Vector3 normalized => this; public static Vector3 ProjectOnPlane(Vector3 a,Vector3 b)=>a; public static float Dot(Vector3 a,Vector3 b)=>0;
    public static Vector3 Lerp(Vector3 a,Vector3 b,float t)=>a; public static Vector3 operator*(Vector3 a,float f)=>a; public static Vector3 operator+(Vector3 a,Vector3 b)=>a; public static Vector3 operator-(Vector3 a,Vector3 b)=>a; }
  public struct Quaternion { public static Quaternion Euler(float x,float y,float z)=>default; public static Quaternion LookRotation(Vector3 f,Vector3 u)=>default; public static Quaternion Slerp(Quaternion a,Quaternion b,float t)=>a; }
  public static class Mathf { public const float PI=3.14159265f, Rad2Deg=57.29578f;
    public static float Abs(float f)=>Math.Abs(f); public static float Sign(float f)=>f>=0?1:-1; public static float Min(float a,float b)=>Math.Min(a,b); public static float Max(float a,float b)=>Math.Max(a,b);
    public static float Clamp01(float f)=>Math.Max(0,Math.Min(1,f)); public static float MoveTowards(float c,float t,float d)=>Math.Abs(t-c)<=d?t:c+Math.Sign(t-c)*d;
    public static int RoundToInt(float f)=>(int)Math.Round(f); public static float Exp(float f)=>(float)Math.Exp(f); public static float Lerp(float a,float b,float t)=>a+(b-a)*t; }
  public class TooltipAttribute : Attribute { public TooltipAttribute(string s){} }
  public class HeaderAttribute : Attribute { public HeaderAttribute(string s){} }
  public class RangeAttribute : Attribute { public RangeAttribute(float a,float b){} }
  public class DisallowMultipleComponent : Attribute {}
}
namespace Newtonsoft.Json { public static class JsonConvert { public static T DeserializeObject<T>(string s)=>default; } }
