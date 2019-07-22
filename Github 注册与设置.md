# Github 注册与设置

### github注册与链接

首先，进入github官网进行注册帐号

然后添加本机的公钥到自己的github账号上

```bash
cd .ssh

cat id_rsa.pub
```

复制到github的公钥上

### github远程仓库设置

点击repositories中的new在网页中创建一个新仓库

选择仓库名以及仓库类型为公有

然后在本地创建一个与其同步的库

```bash
git init
git add xxxx
gitcommit -m ""
git remote add origin git@github.com:zhangbowen-jpg/xxxx.git
git oush -u origin master
```

### 注意：一定不要同时更改两端，否则会出错。



