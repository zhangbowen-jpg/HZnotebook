ping 192.168.xx.xxx 检测本机与被连接网络是否联通

sshpi 远端连接数梅派 sshpi zhangbowen@pi6(或zhangbowen@192.168.1.45)

: set paste 设置粘贴模式

mv sshpi.sh sshpi （重命名）

chmod a+x sshpi  文件授权

echo 打印变量

cp 复制文件命令 cp+文件名+路径

sudo!!  赋予超级管理员权限

修改host配置文件 位置： cd/etc

sudo !! vim host       host存储的是ip与主机的对应关系

ssh 连接的实际是ip地址

scppi zhangbowen@pi6:/tmp/Typora.tar.gz .

从主机上拷贝文件，并重命名

