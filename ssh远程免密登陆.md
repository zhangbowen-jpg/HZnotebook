# ssh远程免密登陆

![2019-07-17 14-36-38 的屏幕截图](/home/zhangbowen/图片/2019-07-17 14-36-38 的屏幕截图.png)

ssh-keygen 在主机A上生成密钥对

id_rsa.pub(rsa是一种加密模式)公钥

将这个文件拷贝到b主机的authorized_keys文件中

将ip地址和对应主机加到hosts文件中

私有配置文件一般都在家目录的隐藏文件中

共有配置文件一般在/home/etc

扩展：在终端中打出命令头时使用Tab键补全命令

如果没有反映说明写错了，多出一个空格表示命令写对了

显示家目录 echo: $HOME   以点开头的文件会被默认隐藏 ls无法查看

使用ls -a 查看所有文件

在家目录下的.ssh文件夹中添加密钥到authorized_keys文件中

cd ~/.ssh 

vim authorized_keys

添加check文件 并编译执行

gcc check.c -o check

./check

vimtutor 打开vim使用手册

