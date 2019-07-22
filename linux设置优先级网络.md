# linux设置优先级网络

更改文件设置：

打开终端输入

```bash
sudo vim /etc/network/interfaces
sudo vim /etc/wpa_supplicant/wpa_supplicant.conf
```

```bash
#/etc/network/interfaces
auto wlp3s0
allow-hotplug wlp3s0
iface wlp3s0 inet dhcp
    pre-up wpa_supplicant -Dwext -i wlp3s0 -c /etc/wpa_supplicant/wpa_supplicant.conf -B
```

#### ***注意：这里的wlp3s0代表自己的设备配置***

可以通过命令

```bash
ifconfig 
```

查看本机ip地址等属性。

```bash
#/etc/wpa_supplicant/wpa_supplicant.conf
country=CN
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
network={
	ssid="HaiZei_Tech"
	psk="HaiZei731."
	scan_ssid=1
	priority=3
}
```

配置自己本地的网络设置，network表示链接的网络

修改之后保存并退出。

## 使配置生效

终端键入

```bash
service NetworkManager stop
service networking restart
```

第一条命令表示关闭NetworkManager服务（wifi界面化设置）

第二条命令表示重新启动networking配置

## 进行校验

终端键入

```bash
ping 8.8.8.8
ping www.baidu.com
```

分别连接到8.8.8.8和百度

[8.8.8.8](https://www.baidu.com/s?wd=8.8.8.8&tn=SE_PcZhidaonwhc_ngpagmjz&rsv_dl=gh_pc_zhidao)是GOOGLE公司提供的DNS，该地址是全球通用的，相对来说，更适合国外以及访问国外网站的用户使用。

如果两条链接成功，说明配置成功。

# 网络设置恢复

删除/etc/network/interfaces中添加的代码并关闭networking

```bash
sudo systemctl disable networking.service
```

```bash
service networking stop
```

开启NetworkManager

```bash
service NetworkManager start
```

然后重新启动系统。

