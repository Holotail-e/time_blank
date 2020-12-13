// pages/one/one.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    temp1:1,
    temp2:2,
  },

  /**
   * 生命周期函数--监听页面加载
   */

  OneNet_Get: function(){
    var that=this
    let deviceid = "651255819"
    let apikey = "kgP2rOrGwpry=RCfufSHPUfA9l0="
    wx.request({
      url: "https://api.heclouds.com/devices/" + deviceid + "/datastreams",
      method:'GET',
      header:{
        "content-type": 'application/x-www-form-urlencoded',
        "api-key": apikey
      },
      success(res){
        console.log(res)
        if(res.statusCode === 200){
          that.setData({
            temp1: res.data.data[0].current_value,
            temp2: res.data.data[1].current_value,
          })
        }
      },
      fail: function(res){
        wx.showToast({ title: '系统错误' })
      },
      complete:function(res){
        wx.hideLoading()
      }
    })
  },

  OneNet_Post:function(){
    var that=this
    let deviceid = "651255819"
    let apikey = "kgP2rOrGwpry=RCfufSHPUfA9l0="
    let data={
      "datastreams": [
        {"id": "temp1","datapoints":[{"value": that.data.temp1}]},
        {"id": "temp2","datapoints":[{"value": that.data.temp1-1}]},
      ]
    }
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