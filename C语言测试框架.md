## C语言测试框架

### gtest

​	gtest是基于一种基于C++的单元测试框架。

何谓单元测试：

​	对于过程进行测试的检测框架，例如C语言中的函数。java中的类。

为什么要对函数测试：

​	一方面检测函数是否正确，另一方面检测函数的功能是否完备。

### gtest系列之TEST宏

```shell
TEST(test_case_name, test_name)
```

这里给出的宏，其实就是指一组测试用例。

**什么是测试用例**：

​	可以将测试用例理解成本质为一组测试行为

先下载安装gtest：

```shell
git clone https://github.com/google/googletest
```

再cd 到googletest路径下

### 重新了解make命令

​    为了方便开发，我们使用一个make命令，他可以读取Makefile文件，并且根据Makefile中的规则描述将源文件生成为可执行的程序文件。

​	最基本的Makefile中包含了一系列规则。每条规则前都要有一个制表符\t

```c
目标：依赖1 依赖2 ...
    命令
    
例如：
main: array.o main.o
	gcc -o main array.o main.o
main.o: main.c array.h
	gcc -c -o main.o main.c
array.o: array.c array.h
	gcc -c -o array.o array.c
	
```

这条规则生成目标对象文件.o，他依赖于array.c和array.h。当我们使用命令 `make array.o`时，根据规则，如果没有array.o或两个文件比对象文件新，则执行语句。

注意：需要将以上三个文件保存在一条目录下。

当makefile中存在多条规则时，可以在make命令后添加需要生成目标的名称。

很多时候，当你需要将.o后缀的对象文件和可执行程序删除，那么可以写一条clean规则，例如:

```c
clean:
	rm -f array.o main.o main
```

rm表示删除文件，-f表示强制，但是光一条命令不行，如果clean文件已经存在，那么命令就不会执行了。

那么可以通过以下代码来使得我们使用make命令时，即使clean已经存在的情况下仍然有效。

```c
.PHONY: clean
clean:
	rm -f array.o main.o main
```

我们回来:

```shell
cmake CMakeLists.txt
```

使用上面的命令来生成静态链接库，所谓的静态链接库就是对用到的定义进行打包生成的文件，而在.h文件中存放的是声明。

所以一般第三方提供程序时就是提供一个静态链接库和一个头文件（一个声明，一个定义）

`libgtest.a`就是整个框架的静态链接库

这里使用include文件夹中的gtest作为用例，将其移至项目文件夹下，然后在project文件夹下新建源文件cpp，引用头文件

`#include <gtest/gtest.h>`这就是调用项目的静态链接库

### 宏定义TEST

在TEST的定义中，我们将使用EXPECT_EQ（a，b）来使用测试用例，来判断程序中函数的功能及正确性。

在使用之前需要给g++添加静态链接库路径。

```shell
g++ -L 路径 源文件名（你要写的，不是头文件）链接库
g++ -L ./lib main.cpp -lgtest
//这个lgtest 实际上找的是libgtest.a文件
```

```C
#ifndef _TEST_H
#define _TEST_H

#define TEST(a, b) void a##b() //字符串链接a和b
#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "True" : "False");
//实现EXPECT_EQ功能

int RUN_ALL_TESTS() {
    
    RETURN 0;
}

#endif
//test.h
```

