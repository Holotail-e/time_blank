//引入echarts文件
import * as echarts from '../../ec-canvas/echarts';
var GHEnvs = {}

function line_set(label, chart, xdata, ydata,) {
  xdata = [
    '06-02 4:00:00', '06-02 4:30:00', '06-02 5:00:00', '06-02 5:30:00', '06-02 6:00:00', '06-02 6:30:00',
    '06-02 7:00:00', '06-02 7:30:00', '06-02 8:00:00', '06-02 8:30:00', '06-02 9:00:00', '06-02 9:30:00',
    '06-02 10:00:00', '06-02 10:30:00', '06-02 11:00:00', '06-02 11:30:00', '06-02 12:00:00', '06-02 12:30:00',
    '06-02 13:00:00', '06-02 13:30:00', '06-02 14:00:00', '06-02 14:30:00', '06-02 15:00:00', '06-02 15:30:00',
    '06-02 16:00:00', '06-02 16:30:00', '06-02 17:00:00', '06-02 17:30:00', '06-02 18:00:00', '06-02 18:30:00',
    '06-02 19:00:00', '06-02 19:30:00', '06-02 20:00:00', '06-02 20:30:00', '06-02 21:00:00', '06-02 21:30:00',
    '06-02 22:00:00', '06-02 22:30:00', '06-02 23:00:00', '06-02 23:30:00', '06-03 00:00:00', '06-03 00:30:00',
    '06-03 1:00:00', '06-03 1:30:00', '06-03 2:00:00', '06-03 2:30:00', '06-03 3:00:00', '06-03 3:30:00',
  ]
  ydata.Temperature = [
    '15.32', '14.85', '14.31', '14.04', '14.24', '15.01', 
    '15.37', '16.75', '16.42', '16.78', '17.86', '18.96', 
    '19.88', '20.77', '22.39', '23.43', '24.32', '25.13', 
    '26.02', '26.84', '27.64', '28.32', '28.16', '27.76', 
    '27.37', '27.15', '26.98', '26.53', '25.81', '25.46', 
    '24.78', '24.11', '23.00', '21.19', '20.32', '19.96', 
    '18.37', '18.01', '18.12', '17.78', '17.65', '17.15', 
    '17.17', '17.67', '17.41', '17.23', '16.79', '16.88', 
  ]
  ydata.Humidity = [
    63.31, 65.14, 64.19, 66.81, 68.63, 70.69,
    74.61, 73.14, 72.18, 70.61, 71.13, 68.35,
    69.41, 67.97, 65.42, 62.62, 60.19, 59.41,
    61.61, 57.14, 54.18, 55.33, 57.16, 58.37,
    61.61, 65.14, 69.18, 70.11, 71.15, 73.51,
    74.84, 71.14, 75.18, 73.51, 72.11, 70.27,
    71.61, 72.14, 69.08, 68.53, 67.23, 70.61,
    72.43, 72.95, 69.11, 67.01, 66.43, 65.64
  ]
  ydata.CO2D = [
    24.064, 22.446, 23.048, 22.178, 20.110, 19.015,
    20.061, 19.046, 18.064, 17.088, 17.575, 18.016,
    18.843, 20.016, 22.061, 24.309, 26.108, 28.013,
    29.872, 31.215, 33.046, 34.931, 35.961, 38.040,
    40.817, 42.394, 46.010, 49.009, 52.018, 55.043,
    54.575, 53.713, 51.619, 49.513, 47.247, 44.049,
    41.046, 37.614, 34.991, 33.010, 32.019, 30.763,
    30.020, 29.278, 28.435, 27.713, 27.465, 25.894
  ]
  var xdatashow = {}
  var ydatashow = {}
  if(label == 1)          //24h
  {
    xdatashow = xdata;
    ydatashow = ydata
    //ydatashow = ydata;
  }
  else if(label == 2)     //12h
  {
    var len = xdata.length;
    xdatashow = xdata.slice(len-24, len);
    ydatashow.Temperature = ydata.Temperature.slice(len-24, len);
    ydatashow.Humidity = ydata.Humidity.slice(len-24, len);
    ydatashow.CO2D = ydata.CO2D.slice(len-24, len);
  }
  else if(label == 3)     //6h
  {
    var len = xdata.length;
    xdatashow = xdata.slice(len-12, len);
    ydatashow.Temperature = ydata.Temperature.slice(len-12, len);
    ydatashow.Humidity = ydata.Humidity.slice(len-12, len);
    ydatashow.CO2D = ydata.CO2D.slice(len-12, len);
  }
  var ilen = xdatashow.length - 2;
  var option = {
    title: {
      text: '番茄大棚环境数据曲线',
      left: 'center'
    },
    color: ["#37A2DA", "#67E0E3", "#9FE6B8"],
    grid: {
      containLabel: true
    },
    tooltip: {
      show: true,
      trigger: 'axis'
    },
    xAxis: {
      axisLabel: { 
        interval: ilen,  
     } ,
      type: 'category',
      boundaryGap: false,
      data: xdatashow
    },
    yAxis: {
      x: 'center',
      type: 'value',
      splitNumber:5,
      min: 0,
      max: 100,
      splitLine: {
        lineStyle: {
          type: 'dashed'
        }
      }
    },
    series: [{
      name: '温度/℃',
      type: 'line',
      smooth: true,
      data: ydatashow.Temperature
    }, {
      name: '相对湿度/%RH',
      type: 'line',
      smooth: 'true',
      data: ydatashow.Humidity
    }, {
      name: "CO2浓度/x10PPM",
      type: 'line',
      smooth: 'true',
      data: ydatashow.CO2D
    }]
  };
  chart.setOption(option);
}
Page({
  /**
   * 页面的初始数据
   */
  data: {
    ec: {
      lazyLoad: true
    },
    timer:'',
    TimeI: [     //选择查看温湿度等环境参数的时间间隔
      {value:"24h", checked: true},
      {value:"12h", checked: false},
      {value:"6h", checked: false}
    ],
    suggestion: "番茄大棚环境良好，",
    stage:"盛果期",
    envsT:"1",
    envsH:"",
    envsC:""
  },
  TimeIntervalSelect: function(e){
    let ops = this.data.TimeI;

    for(let i = 0; i < ops.length; i++)
    {
      ops[i].checked = ops[i].value === e.detail.value;
    }
    this.setData({
      TimeI: ops,
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    let stage = this.data.stage;
    if(stage == "盛果期" || stage == "开花期"){
      this.setData({
      envsT :"气温 20~25℃",
      envsH : "相对湿度 45~55%RH"    
    })
    }
    else if(stage == "幼苗期")
    {
      this.setData({
      envsT:"白天 20~25℃ 夜间 10~15℃",
      envsH:"相对湿度 60~65%RH"
    })
    }

    var _this = this;
    this.getOption();
    this.setData({                    //每隔10s刷新一次
      timer: setInterval(function () {
        _this.getOption();
    }, 10000),
      suggestion: "大棚环境："
    })
  },
  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {
    this.oneComponent = this.selectComponent('#mychart-dom-line');
    //this.oneComponent = this.selectComponent('#CharHumi');
  },
  onUnload: function () {
    clearInterval(this.data.timer)
},
  init_chart: function (label, xdata, ydata) {        //初始化第一个图表
    this.oneComponent.init((canvas, width, height, dpr) => {
        const chart = echarts.init(canvas, null, {
            width: width,
            height: height,
            devicePixelRatio: dpr // new
        });
        line_set(label, chart, xdata, ydata)
        this.chart = chart;
        return chart;
    });
},
getOption: function () {
  var blank=""
  var myDate = new Date();
  var year=myDate.getFullYear();
  var month=(myDate.getMonth() + 1 < 10 ? '0' + (myDate.getMonth() + 1) : myDate.getMonth() + 1);
  var date=(myDate.getDate()-1) < 10 ? '0' + (myDate.getDate() - 1) : (myDate.getDate() - 1);
  var hour=myDate.getHours() < 10 ? '0' + myDate.getHours() : myDate.getHours();
  var min=myDate.getMinutes() < 10 ? '0' + myDate.getMinutes() : myDate.getMinutes();
  var sec=myDate.getSeconds() < 10 ? '0' + myDate.getSeconds() : myDate.getSeconds();
  var myTime=blank.concat(year,"-",month,"-",date,"T",hour,":",min,":",sec);
  var _this = this;
  this.setData({
    suggestion: "大棚环境："
  })
  wx.request({
      url: 'https://api.heclouds.com/devices/952619347/datapoints?start='+myTime,   
      method: 'GET',
      header: {
          "Content-Type": "application/x-www-form-urlencoded",
          "api-key": 'Tw8eeoEgmTFMqn5854ONXK5nQL8='
      },
      data:{
      },
      //对数据进行处理并展示
      success:  (res)=> {
        _this.setData({      
          //将接口返回的数据data赋值给data
          data:res.data  
        })
        var i
        var Temperature=[]; //获取温度数据
        var Humidity = []; //获取湿度数据
        var CO2D = [] //获取二氧化碳数据
        var date=[];
        console.log(res)
        //var stage = ["盛果期", "幼苗期"]
        for (i = 0; i < res.data.data.datastreams[0].datapoints.length-4; i++) {
            Temperature[i]=res.data.data.datastreams[0].datapoints[i+4].value;
            Humidity[i] = res.data.data.datastreams[2].datapoints[i].value;
            CO2D[i] = res.data.data.datastreams[1].datapoints[i].value
            var timelen = res.data.data.datastreams[0].datapoints[i].at.length
            date[i]=res.data.data.datastreams[0].datapoints[i+4].at.slice(5,timelen-7);
         }
        if(Temperature[Temperature.length-1] < 15)
        {
          let suggestion = this.data.suggestion;
          suggsetion = suggestion + " 建议升高温度";
          this.setData({
            suggestion: suggestion
          })
        }

        if(Humidity[Humidity.length-1] > 70)
        {
          let suggestion = this.data.suggestion
          suggestion = suggestion + " 建议通风"
          this.setData({
            suggestion: suggestion
          })
        }
        let hmin = date[date.length - 1].slice(6,date[date.length - 1].length)
        let hour = hmin.slice(0,2)
        let minu = hmin.slice(3,5)
        if(CO2D[CO2D.length - 1] < 22 && hour < 18 && hour > 6)
        {
          let suggestion = this.data.suggestion + " 增加二氧化碳浓度";
          this.setData({
            suggestion: suggestion
          })
        }
        GHEnvs = {Temperature, Humidity, CO2D}
         if(this.data.TimeI[0].checked == true)
         {
            _this.init_chart(1, date, GHEnvs);          
         } 
         else if(this.data.TimeI[1].checked == true){
            _this.init_chart(2, date,GHEnvs);
         }
         else{
          _this.init_chart(3, date, GHEnvs);    
         }
      },
  })
}
})

