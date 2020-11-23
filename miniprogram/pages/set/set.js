// pages/set/set.js
wx.cloud.init({
  env:'holo-3g2pxzglcd69d8b2',
});
const db = wx.cloud.database();
var mday = [31,28,31,30,31,30,31,31,30,31,30,31];

Page({
  /**
   * 页面的初始数据
   */
  data: {
    arrangements:{   
      actform:"",
      assignment:"",
      start: {    //起始事件时间  年 月 日 时 分
      syear:2020,
      smonth: 11,
      sday: 20,
      shour: 12,
      smin: 32, 
      },
      finish: {     //结束事件时间
      eyear:2020,
      emonth: 11,
      eday:20,
      ehour: 20,
      ehour: 17,
      emin: 16,
      },
  },
    hid: true,    //form组件是否显示
    hid1: false,
    hid2: true,
    change: false,  //
    times: 0,
   
    option:'开始时间',
    
    activity: [      //活动的类型
      { value: "learn" , checked: false },
      { value: "学习" , checked: false },
      { value: "吃饭" , checked: false },
      { value: '游戏' , checked: false },
      { value: '锻炼' , checked: false },
      { value: '读书' , checked: false },
      { value: '外出' , checked: false }
    ]

  },

  actform: function(e) {        //设置活动的类型
    let items = this.data.activity;
    console.log(e.detail);
    for(let i = 0; i < items.length; i++)
    {
      items[i].checked = items[i].value === e.detail.value;
    }
    this.setData({
      ['arrangements.actform']: e.detail.value
    })
  },


  OneNet_Post:function(){     //将数据上传至OneNet
    var that=this
    let deviceid = "651255819"
    let apikey = "kgP2rOrGwpry=RCfufSHPUfA9l0="
    let data={
     "datastreams": [
      {"id":"arrangements","datapoints":[{"value": this.data.arrangements}]},
        /*{"id":"actform","datapoints":[{"value": this.data.actform}]},
        {"id":"starttime","datapoints":[{"value":this.data.start}]},
        {"id":"finishtime","datapoints":[{"value":this.data.finish}]},
        {"id":"affair","datapoints":[{"value": this.data.assignment}]},*/
      ]}
    wx.request({      
      url: "https://api.heclouds.com/devices/" + deviceid + "/datapoints",
      method:'POST',
      header:{
        "content-type": 'application/json',
        "api-key": apikey
      },
      data:JSON.stringify(data),
      success(res){
        console.log("更新数据成功",res)
      },
      fail: function(res){
        wx.showToast({ title: '系统错误' })
      },
      complete:function(res){
        wx.hideLoading()
      }
    })
  },
  upload: function(e){          //上传至数据库
    db.collection('assignments').add({
      data:{
        description: "日程安排",
        actform: this.data.arrangements.actform,
        tags:[
          "cloud",
          "database",
        ],
        sdate: {
          detail: "起始时间",
          date:this.data.arrangements.start,
      },
        edate: {
          detail: "终止时间",
          date:this.data.arrangements.finish,
        },
        assignment: this.data.arrangements.assignment,
          }
    })
    wx.showToast({
      title: '上传成功!',
      icon: 'success'
    })
  },
  setstate: function(e) {    //设置起始或结束的时间
    if(e.detail.value){
      this.setData({
        option: '结束时间',
        hid2: false,
        hid1:true,
      })
    }
    else{
      this.setData({
        option: '开始时间',
        hid1: false,
        hid2: true,
      })
    }
  },
  Init: function(e) {     //显示设置  时间
    this.setData({
      times: this.data.times + 1,
      hid: ((this.data.times % 2 != 0) ? true: false)
    })
    
  },
  /**
   * 生命周期函数--监听页面加载
   */
   changeday: function(e) {   //设置天数
    if(!this.data.hid1)
    {
    this.setData({
    ['arrangements.start.sday']: e.detail.value
    })
    } else {
      this.setData({
        ['arrangements.finish.eday']: e.detail.value
        })
    }
   },
   changehour: function(e) {  //设置小时
    if(!this.data.hid1)
    {
    this.setData({
    ['arrangements.start.shour']: e.detail.value
    })
    } else {
      this.setData({
        ['arrangements.finish.ehour']: e.detail.value
        })
    }
   },
   changemin: function(e) {  // 设置分钟
    if(!this.data.hid1)
    {
    this.setData({
    ['arrangements.start.smin']: e.detail.value
    })
    } else {
      this.setData({
        ['arrangements.finish.emin']: e.detail.value
        })
    }
   },
   actdetail: function(e) {   //事件的细节描述
    this.setData({
      ['arrangements.assignment']: e.detail.value
    })
    console.log(e.detail.value)
   },


  onLoad: function (options) {      //获取当前时间，并设置起始和终止时间的初始化数据
      const date = new Date();
      const year = date.getFullYear();
      const month = date.getMonth() + 1;
      const day = date.getDate();
      const hour = date.getHours();
      const minute = date.getMinutes();
      const second = date.getSeconds();
      if( year % 400 == 0){
        mday[1] = 29;
      } else if( (year % 100 != 0) && (year % 4 == 0))
      {
        mday[1] = 29;
      }
      this.setData({      
        ['arrangements.start.syear']: year,
        ['arrangements.start.smonth']: month,
        ['arrangements.start.sday']: day,
        ['arrangements.start.shour']: hour,
        ['arrangements.start.smin']: minute,
        ['arrangements.finish.eyear']: year,
        ['arrangements.finish.emonth']: month,
        ['arrangements.finish.eday']: day,
        ['arrangements.finish.ehour']: hour,
        ['arrangements.finish.emin']: minute,
      })
      console.log(this.data.arrangements);
      
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})