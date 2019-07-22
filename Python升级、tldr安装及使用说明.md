# Python升级、tldr安装及使用说明

### 一、安装python3

1. 输入命令：

```bash
sudo apt-get install python3
```

安装python3

2. 输入命令：

```bash
which python
```

查看下载的python所在路径

3. 输入命令：

```bash
python -V
```

查看当前python版本

### 二、建立链接

1. 输入命令：

```bash
sudo ln -s /usr/bin/python3.7 /usr/bin/python
```

修改/usr/bin/python链接的路径

2. 安装pip包：

输入命令：

```bash
sudo apt-get install python3-pip
```

如果太久没有更新软件，报错，输入命令

```bash
sudo apt-get update
```

接着，输入命令：

```bash
pip3 list
```

打开python包管理工具

如果pip版本过低，键入命令：

```bash
pip install --upgrade pip
```

更新pip包管理工具（有必要）

如果查看pip3 -V时报错，键入：

```bash
sudo vim /usr/bin/pip3
```

将文件中pip 更改为pip._internal 保存并退出

### 三、安装tldr及使用说明

在命令行键入：

```bash
pip install tldr
```

安装tldr

安装之后在联网条件下可以使用以下代码来查看man 手册中相关命令：

```bash
tldr xxx --xxx为你要查看的命令
```

将会输出与该命令相关的所有命令以及其解释。