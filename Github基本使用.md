# Github基本使用

### github仓库创建

首先，创建一个文件夹，用来储存将上传到github上的文件

```bash
mkdir 197 

cd 197

mkdir Cpractice

cd Cpractice
```

然后输入 git 检查机器是否自带git

```bash
git init
```

创建一个本地git仓库在当前路径下。

### github的基本使用

将需要同步的文件写在仓库目录下。

```bash
git status 
```

查看当前代码仓库的状态，其中可能有未保存的改动。

可以根据提示进行保存改变。

```bash
git add <file>
```

在代码仓库中添加文件

```bash
git rm --cached <file>
```

删除仓库中已缓存的文件

```bash 
git commit -m "Init README"
```

向github账户中的库提交更改

“ ”中的内容为提交注释

```bash 
git log
```

查看最近的修改

```bash
git config --global user.name ""
```

登记本地库信息和要连接的账号“ ”

```bash
git config --global user.email ""
```

登记本地库信息和要链接账号的邮箱

