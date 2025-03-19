//app.js
var mqtt = require("/utils/mqtt.js")    //引入mqtt文件




function randomString(len) { 
  len = len || 32;
  var $chars = 'ABCDEFGHJKMNPQRSTWXYZabcdefhijkmnprstwxyz2345678';
  var maxPos = $chars.length;
  var pwd = '';
  for (let i = 0; i < len; i++) {
    pwd += $chars.charAt(Math.floor(Math.random() * maxPos));
  }
  return pwd;
}
//连接配置
const options = {
  connectTimeout: 4000,  //超时时间
  clientId: randomString(30),  //随机生成ID
  username: '',  //用户名
  password: '',  //密码
}


App({
  onLaunch: function () {
    let that = this
    var client = mqtt.connect('1.82.150.64:8081', options) //你自己的域名
    client.on('connect', (e) => {
      console.log('成功连接服务器!')
    })
    client.subscribe('esp8266', {
      qos: 0
    }, function (err) {
      if (!err) {
        console.log("订阅成功:esp8266")
      }
    })
    client.on('message', function (topic, message, packet) {
      that.globalData.mqttData = packet.payload.toString()
    })

    this.globalData = {}
  }
})
