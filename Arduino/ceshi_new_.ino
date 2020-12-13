//本程序存在一些不稳定性，也可能是硬件存在一些不稳定性，有时可以正常操作，有时会显示一长串的错误信息。

#include <Wire.h>
#include "SSD1306Wire.h"
#include "images.h"
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>                
#include <Time.h>
#include <Timezone.h>
#include "NTP.h"

int json_state;//天气返回编码
int json_state2;//温度返回值
String json_temp;

int sensor = 13;        //定义红外引脚

const char* WiFiID ="cqq";         // WiFi账号
const char* WiFiPW = "20010713";        // WiFi密码

// 北京时间时区
#define STD_TIMEZONE_OFFSET +8    // Standard Time offset (-7 is mountain time)

TimeChangeRule mySTD = {"", First,  Sun, Jan, 0, STD_TIMEZONE_OFFSET * 60};
Timezone myTZ(mySTD, mySTD);

WiFiClient client;                       //创建一个网络对象

String key = "SvMSTt17bMoJqefy6";   //心知天气的秘钥
String weizhi = "beijing";        //我的地址，北京


const char OneNetServer[] = "api.heclouds.com";
const char APIKEY[] = "kgP2rOrGwpry=RCfufSHPUfA9l0=";    // 段雨辰的API KEY
int32_t DeviceId = 651255819;                             // 段雨辰的设备ID
char DataStreams[] = "JTTr3Nzw";                // 数据流名称   //先前读取单个数据流时使用，后批量读取时未使用。
const size_t MAX_CONTENT_SIZE =2048 ;                  // 最大内容长度    用来控制能读到的json数据的长度
const unsigned long HTTP_TIMEOUT = 2100;                // 超时时间

int stream1;                           //用于存放返回数据流的数值
const int tcpPort = 80;

//液晶部分
SSD1306Wire display(0x3c, 5, 4);   //SDA SCL
typedef void (*Demo)(void);


struct time1                 //用来存储事件的开始时间等内容
{
  String starthour;
  String startmin;
  String startmonth;
  String startday;
  String startyear;
  String endhour;
  String endmin;
  String endday;
  String endmonth;
  String startequence;
  String assignment;
};
time1 a[2];                  //由于不知名的原因，当读取过多的数据时，会导致显示一长串乱码或者显示解析错误等，所以只能设置为两个。


struct UserData 
{   int errno_val;                // 错误返回值
    char error[32];               // 错误返回信息
    int recived_val;             // 接收数据值 
    char udate_at[32];            // 最后更新时间及日期
};

//跳过 HTTP 头，使我们在响应正文的开头
bool skipResponseHeaders() 
{   char endOfHeaders[] = "\r\n\r\n";
    client.setTimeout(HTTP_TIMEOUT);
    bool ok = client.find(endOfHeaders);
    if (!ok) 
    {Serial.println("No response or invalid response!");} //未响应
    return ok;
}

//从HTTP服务器响应中读取正文
void readReponseContent(char* content, size_t maxSize) 
{   //  size_t length = client.peekBytes(content, maxSize);
    size_t length = client.readBytes(content, maxSize);
    delay(20);
    Serial.println(length);
    Serial.println("Get the data from Internet!"); //获取到数据
    content[length] = 0;
    Serial.println(content);
    Serial.println("Read Over!");
}
// 解析数据存储到传入的结构体中     ,json的解析方式从ArduinoJson Assistant上获得
bool parseUserData_test(char* content, struct UserData* userData) 
{
    
    const size_t capacity = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(3) + 6*JSON_OBJECT_SIZE(5) + 2*JSON_OBJECT_SIZE(6) + 720;
    DynamicJsonBuffer jsonBuffer(capacity);
    
    JsonObject& root = jsonBuffer.parseObject(content);
    if (!root.success()) 
    {
      Serial.println("JSON parsing failed!");
      return false;
    }
    int errno = root["errno"]; // 0

    JsonArray& data = root["data"];
    
    JsonObject& data_0 = data[0];
    JsonObject& data_0_current_value = data_0["current_value"];
    JsonObject& data_0_current_value_start = data_0_current_value["start"];
    String data_0_current_value_start_shour = data_0_current_value_start["shour"]; // 19
    String data_0_current_value_start_smin = data_0_current_value_start["smin"]; // 1
    String data_0_current_value_start_smonth = data_0_current_value_start["smonth"]; // 12
    String data_0_current_value_start_sday = data_0_current_value_start["sday"]; // 12
    String data_0_current_value_sequence = data_0_current_value["sequence"]; // 202012121901
    JsonObject& data_0_current_value_finish = data_0_current_value["finish"];
    String data_0_current_value_finish_ehour = data_0_current_value_finish["ehour"]; // 19
    String data_0_current_value_finish_emin = data_0_current_value_finish["emin"]; // 1
    const char* data_0_current_value_assignment = data_0_current_value["assignment"]; // "赛博朋克赛尔号"
    
    JsonObject& data_1 = data[1];
    JsonObject& data_1_current_value = data_1["current_value"];
    JsonObject& data_1_current_value_start = data_1_current_value["start"];
    String data_1_current_value_start_shour = data_1_current_value_start["shour"]; // 19
    String data_1_current_value_start_smin = data_1_current_value_start["smin"]; // 1
    String data_1_current_value_start_smonth = data_1_current_value_start["smonth"]; // 12
    String data_1_current_value_start_sday = data_1_current_value_start["sday"]; // 12
    String data_1_current_value_sequence = data_1_current_value["sequence"]; // 202012121901
    JsonObject& data_1_current_value_finish = data_1_current_value["finish"];
    String data_1_current_value_finish_ehour = data_1_current_value_finish["ehour"]; // 19
    String data_1_current_value_finish_emin = data_1_current_value_finish["emin"]; // 1
    const char* data_1_current_value_assignment = data_1_current_value["assignment"]; // "赛博朋克4399"
    
    
    
    // 复制需要的信息到userData结构体中
    
      a[0].starthour=data_0_current_value_start_shour;
      a[0].startmin=data_0_current_value_start_smin; // 1
      a[0].startmonth=data_0_current_value_start_smonth; // 12
      a[0].startday=data_0_current_value_start_sday; // 12
      a[0].startequence=data_0_current_value_sequence; // 202012121901
      a[0].endhour=data_0_current_value_finish_ehour; // 19
      a[0].endmin=data_0_current_value_finish_emin; // 1
      a[0].assignment=data_0_current_value_assignment; // "赛博朋克赛尔号"
      a[1].starthour=data_1_current_value_start_shour;
      a[1].startmin=data_1_current_value_start_smin; // 1
      a[1].startmonth=data_1_current_value_start_smonth; // 12
      a[1].startday=data_1_current_value_start_sday; // 12
      a[1].startequence=data_1_current_value_sequence; // 202012121901
      a[1].endhour=data_1_current_value_finish_ehour; // 19
      a[1].endmin=data_1_current_value_finish_emin; // 1
      a[1].assignment=data_1_current_value_assignment; // "赛博朋克赛尔号"
      
    
    
    userData->errno_val = root["errno"];
    strcpy(userData->error, root["error"]);
    // 成功返回0 
    if ( userData->errno_val == 0 ) 
    {
      userData->recived_val = root["data"]["datastreams"][0]["datapoints"][0]["value"];
      strcpy(userData->udate_at, root["data"]["datastreams"][0]["datapoints"][0]["at"]);
      Serial.print("Recived Value : ");
      Serial.print(userData->recived_val);
      Serial.print("\t The last update time : ");
      Serial.println(userData->udate_at);
    }
    Serial.print("errno : ");
    Serial.print(userData->errno_val);
    Serial.print("\t error : ");
    Serial.println(userData->error);
  
    return true;
}
//
// 读取数据
//
int readData(int DeviceId, char dataStream[])
{
    // 创建发送请求的URL
    String url = "/devices/";
    url += String(DeviceId);
    //url += "/datapoints?datastream_id=";
    //url += dataStream;
    url+="/datastreams";

    // 创建发送指令
    String send_data = String("GET ") + url + " HTTP/1.1\r\n" +
                     "api-key:" + APIKEY + "\r\n" +
                     "Host:" + OneNetServer + "\r\n" +
                     "Connection: close\r\n\r\n";
    // 发送指令
    client.print(send_data);
    // 调试模式串口打印发送的指令
    unsigned long timeout = millis();
    while (client.available() == 0) 
    {
      if (millis() - timeout > 5000) 
      {
        Serial.println(">>> Client Timeout !");
        client.stop();
        break;
      }      
    }

    if (skipResponseHeaders())  
    { char response[MAX_CONTENT_SIZE];
      readReponseContent(response, sizeof(response));   // 从服务器读取信息后解析
      UserData userData_LEDstatus;
      if (parseUserData_test(response, &userData_LEDstatus)) 
      { Serial.println("Data parse OK!");
        return userData_LEDstatus.recived_val;
      }
    }
     
 }
 void paixuxianshi()
 {  int t;
    for(int i=0;i<1;i++)
    {
      if(a[i].startequence<a[i+1].startequence)
        t=i;
    }
    String line1=a[t].startmonth+"/"+a[t].startday;                      //将几个数据拼接成一个后再进行显示
    String line2=a[t].starthour+":"+a[t].startmin+"~"+a[t].endhour+":"+a[t].endmin;
    String line3=a[t].assignment;
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_24);  
    display.drawString(1, 1, line1);     //按行显示
    display.drawString(1, 20, line2);
    display.drawString(1, 40, line3);
    display.display();
 }
//以上是读取onenet数据的函数
//以下是读取天气信息的函数

/*====================================画天气图标函数===============================*/
void drawzhongyu() 
{display.drawXbm(drawposition, 0, WiFi_Logo_width, WiFi_Logo_height, zhongyu);}
void drawdayu() 
{display.drawXbm(drawposition, 0, WiFi_Logo_width, WiFi_Logo_height, dayu);}
void drawxiaoyu() 
{display.drawXbm(drawposition, 0, WiFi_Logo_width, WiFi_Logo_height, xiaoyu);}
void drawqingtian() 
{display.drawXbm(drawposition, 0, WiFi_Logo_width, WiFi_Logo_height, qingtian);}
void drawduoyun() 
{display.drawXbm(drawposition, 0, WiFi_Logo_width, WiFi_Logo_height, duoyun);}
void drawzhu()
{display.drawXbm(32, 0, 64, 64, WiFi_Logo_bits);}
void drawseconds_iconclear() 
{display.drawXbm(0, 40, 24, 24, icon_clear);}
Demo demos[] = {drawqingtian, drawduoyun, drawxiaoyu, drawzhongyu, drawdayu, drawzhu, drawseconds_iconclear}; //6

/*==============================================画图部分结束，接下来是数据处理部分=====================*/




/*====================================连接WIFI函数===============================*/
void wifi_start_connect()              
{
  WiFi.mode(WIFI_STA);                 //设置esp8266 工作模式
  Serial.println("Connecting to ");    //写几句提示
  Serial.println(WiFiID);
  WiFi.begin(WiFiID, WiFiPW);         //连接wifi
  WiFi.setAutoConnect(true);
  while (WiFi.status() != WL_CONNECTED) //这个函数是wifi连接状态，返回wifi链接状态
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected IP is");
  Serial.println(WiFi.localIP());
}
/*====================================连接WIFI函数结束===============================*/



/*====================================解析天气数据函数===============================*/
void parseUserData(String content)   
  {
    const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(6) + 210;
    DynamicJsonBuffer jsonBuffer(capacity);
    JsonObject& root = jsonBuffer.parseObject(content);
    JsonObject& results_0 = root["results"][0];
    JsonObject& results_0_now = results_0["now"];
    //const char* results_0_now_text = results_0_now["text"];  // 天气情况
    int results_0_now_code = results_0_now["code"];  //天气情况识别码
    const char* results_0_now_temperature = results_0_now["temperature"];//气温
    
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_24);
    
    json_temp = results_0_now_temperature;   
    json_state = results_0_now_code;
    
  }

/*====================================解析天气数据函数结束===============================*/




/*====================================调用api函数===============================*/

void apicmd()
{ if (client.connect("api.seniverse.com", 80) == 1)    //服务连接
  {
    client.print("GET /v3/weather/now.json?key=");
    client.print(key);
    client.print("&location=");
    client.print(weizhi);
    client.print("&language=zh-Hans&unit=c HTTP/1.1\r\n");

    client.print("Host:api.seniverse.com\r\n");
    client.print("Accept-Language:zh-cn\r\n");
    client.print("Connection:close\r\n\r\n");                 //向心知天气的服务器发送请求。

    if (client.find("\r\n\r\n") == 1)                         //跳过返回的json数据头，
    { String json_from_server = client.readStringUntil('\n'); //读取返回的JSON数据
      Serial.println(json_from_server);                      //打印json数据
      parseUserData(json_from_server);                       //调用josn解析函数，并传参
    }
  }
  else
  { Serial.println("服务器连接失败");
    delay(5000);
  }
  client.stop();                                            //关闭HTTP

}

/*====================================调用api函数===============================*/



String days;            //用于存储当前时间
String months;
String minutes;
String hours; 

String Middle_minutes;
String Middle_hours;


/*====================================时间获取函数===============================*/

void updateDisplay(void) 
{
  TimeChangeRule *tcr;        // Pointer to the time change rule
  time_t utc = now();         // Read the current UTC time from the NTP provider
  time_t localTime = myTZ.toLocal(utc, &tcr);    // Convert to local time taking DST into consideration

  // Map time to pixel positions
  //int weekdays =   weekday(localTime);
  days    =  (String) day(localTime);
  months  = (String) month(localTime);
 // String years   = (String) year(localTime);
 // String seconds = (String) second(localTime);
  minutes = (String) minute(localTime);
  hours   = (String) hour(localTime); 

  if (Middle_minutes != minutes)
  {
    Serial.println("调用天气");
    apicmd();
    Middle_minutes = minutes;
  }
}
/*====================================时间获取函数结束===============================*/



/*====================================天气内容显示函数===============================*/

void aaaa()
{
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_24);  
  display.drawString(75, 40, json_temp);
  display.drawString(100, 40, "°C");

  display.drawString(10, 5, hours);
  display.drawString(38, 3, ":");
  display.drawString(45, 5, minutes);
  
  ////判断返回输出图标
  if (json_state == 0){demos[0]();}
  else if (json_state > 0  && json_state < 4){demos[0]();}
  else if (json_state > 3  && json_state < 10){demos[1]();}
  else if (json_state > 9  && json_state < 14){demos[2]();}
  else if (json_state == 14){demos[3]();}
  else if (json_state > 14  && json_state < 19){demos[4]();}
  
  display.drawString(0, 40, months);
  display.drawString(27, 40, "/");
  display.drawString(33, 40, days);
  display.display();
}

/*====================================天气内容显示函数结束===============================*/


void setup() {
  
  Serial.begin(115200);  
  display.init();
  display.flipScreenVertically();//反向显示
  display.clear();
  demos[5]();
  display.display();
   
  initNTP(WiFiID, WiFiPW);
 
 
  client.setTimeout(5000);//设置服务器连接超时时间
  pinMode (sensor,INPUT);

}
time_t previousSecond = 0;
void loop() {
  
    if (timeStatus() != timeNotSet)              //判断当前时间（分钟）是否改变，若改变，重新发送请求，否则不执行
    { if (second() != previousSecond) {
        previousSecond = second();
        updateDisplay();
        }
    }
    stream1=readData(DeviceId, DataStreams);     //向onenet请求数据
    Serial.println("closing connection");

    
    Serial.print(digitalRead(sensor));
    if (digitalRead(sensor)==1)        //根据红外传感器的数据控制显示天气或是事件安排
      aaaa();
    else
      paixuxianshi();
      
    delay(3000);       //延时，因为在前期测试时发现当手移开之后，红外传感器仍旧返回“1”,观察后发现若接入OLED 屏幕后才会出现这种情况，且其数据返回的形式与按键未消抖时相似，便引入delay，已达到“消抖”的目的
}
