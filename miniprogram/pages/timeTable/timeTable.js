Page({
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
  editcase: false,
  edittimes: 0,
  hid:true,
  times:0,
  clas:{},
  },


  OneNet_Get: function(){
    var that=this
    let deviceid = "651255819"
    let apikey = "kgP2rOrGwpry=RCfufSHPUfA9l0="
    wx.request({
      url: `https://api.heclouds.com/devices/${deviceid}/datapoints?datastream_id=arrangements&limit=20`,
      //url: "https://api.heclouds.com/devices/" + deviceid + "/datastreams",
      method:'GET',
      header:{
        "content-type": 'application/json',//'application/x-www-form-urlencoded',
        "api-key": apikey
      },
      success(res){
        console.log(res)
        if(res.statusCode === 200){
          const responce = res.data;
          console.log(responce.data.datastreams[0].datapoints[0]);
          
          //that.setData({
            //  res.data
            /*['arrangements.actform']: res.data.data[0].current_value.actform,
            ['arrangements.assignment']: res.data.data[0].current_value.assignment,
            ['arrangements.start.syear']: res.data.data[0].current_value.start.syear,
            ['arrangements.start.smonth']: res.data.data[0].current_value.start.smonth,
            ['arrangements.start.sday']: res.data.data[0].current_value.start.sday,
            ['arrangements.start.shour']: res.data.data[0].current_value.start.shour,
            ['arrangements.start.smin']: res.data.data[0].current_value.start.smin,
            ['arrangements.finish.syear']: res.data.data[0].current_value.finish.eyear,
            ['arrangements.finish.smonth']: res.data.data[0].current_value.finish.emonth,
            ['arrangements.finish.sday']: res.data.data[0].current_value.finish.eday,
            ['arrangements.finish.shour']: res.data.data[0].current_value.finish.ehour,
            ['arrangements.finish.smin']: res.data.data[0].current_value.finish.emin,
          })
        }*/
      //})
    }
    
      },
      fail: function(res){
        wx.showToast({ title: '系统错误' })
      },
      complete:function(res){
        wx.hideLoading()
      }
    })
    this.data.times += 1;
    if(this.data.times % 2 == 0 ){
      this.setData({
        hid: true
      })
    } else {
      this.setData({
        hid: false
      })
    }
  },

  OneNet_Delete:function(){     //将数据上传至OneNet
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
edit: function() {      //编辑日程完成或未完成情况
  this.data.edittimes += 1;
  if(this.data.edittimes % 2 == 1)
  {
    this.setData({
      editcase:true
    })
  }
  else{
    this.setData({
      editcase: false
    })
  }
},
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

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