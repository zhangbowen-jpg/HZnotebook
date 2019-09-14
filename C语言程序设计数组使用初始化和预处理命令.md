## 数组的使用与初始化

```c
int a[100] = {1,2,3};//前三个位置赋值
int a[100] = {0};//全部赋零
```

应用 ： 素数筛

注：数组是展开的函数，函数是压缩的数组

一个是计算资源，一个是存储资源

函数和数组的本质都是映射

```c
#include<stdio.h>
#define MAX_N 1000
/* int prime[MAX_N + 5];
 
void init_prime() {
	prime[0] = prime[1] = 1;
	for(int i = 2; i * i <= MAX_N; j += i) {
		if(prime[i]) continue;
		for(int j = i * i; j <= MAX_N; j += i) {
			prime[j] = 1;
		}
	}
	return ;
}
*/
int prime(int x) {
	if(x <= 1) return 1;
	for(int i = 2; i * i <= x; i++) {
	if(x % i) continue;
	return 1;
	}
	return 0;
}
int main() {
	init_prime();
	int x;
	while(~scanf("%d", &x)) {
		printf("%s\n", prime(x) ? "NO" : "Yes");
	}
	return 0;
}

```

## 二分查找

```c
int binary_search(int *arr, int x, int n) {
    int l = 0, r = n - 1, mid;
    while(l <= r) { // while(head + 3 <= tail) ,中间一定会留出三个值，这样不论哪种二分查找情况，都不会错
        mid = (l + r) >> 1;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
/*  for(int i = head; i <= tail; i++) {
		if(arr[i] == max) return i;
}
*/
    return -1;
}
```

扩展：求解单调函数

```c
#include<stdio.h>

int f(int x) {
    return x * x;
}//函数当成数组使

int binary_search(int (*arr)(int), int x, int n) {
    int head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if(arr(mid) == x) return mid;
        if(arr(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
	int y;
    while(~scanf("%d",&y)) {
        int x = binary_search(f, y, 100);
        printf("%d * %d = %d\n", x, x, y);
    }
    return 0;
}
//实现查找一个数是否是平方，是谁的平方。
```

## 预处理命令-宏定义

注意：

1.宏定义只是简单的代码替换；

2.宏定义只占一行。

```c
//宏定义
//定义符号常量
#define PI 3.1415926
#define MAX_N 10000
//定义傻瓜表达式
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define S(a,b) a * b
//定义代码段
#define P(a) { \
	printf("%d\n",a);\
}
```

### 预处理命令 - 预定义的宏

``` C
_DATE_  //返回编译时得日期 Mmm dd yyyy
_TIME_  //返回编译时的时间 hh：mm：ss
_LINE_  //返回宏的行数
_FILE_  //返回宏的文件名
_func_  //返回所在函数的名字(非标准)
_FUNC_  //返回所在函数的名字(非标准)
_PRETTY_FUNCTION_  //更详细的函数信息（非标准）
```

注：

1.预定义的宏只返回编译时的状态

2.非标准表示在不同环境下不能执行。

### 预处理命令-条件式编译

``` C
#ifdef DEBUG 		//是否定义了DEBUG宏，如果定义了，就成立
#ifndef DEBUG 		//是否没定义DEBUG宏
#if MAX_N == 5 		// 宏 MAX_N 是否等于5 例如判断环境中版本号
#elif MAX_N == 4 	//否则宏MAX_N 是否等于4
#else
#endif				//必须以endif结束预处理命令。
```

条件式编译 - 根据不同的环境下决定编译那一段代码

### 预处理阶段

C源码 -> 1.预处理阶段 (将所有预处理命令处理)-> 编译源码 -> 对象文件（.o文件） ->  链接对象文件 - > 可执行程序 

```c
#include<stdio.h>
#define MAX(a,b) {\
	__typeof(a) _a = (a);\
	__typeof(b) _b = (b);\
	_a > _b ? _a : _b;\
}
#ifdef DEBUG //如果存在DEBUG这个宏，则替换P(a) 
#define P(a) {\
	printf("[%s : %d] %s = %d\n", __func__, __LINE__, #a, a);\
}
#else //否则P(a),为空 
#define P(a)
#endif

int main() {
	int a = 7;
	printf("%d\n",MAX(2,3));
	printf("%d\n",5 + MAX(2,3));
	printf("%d\n",MAX(2,MAX(3,4)));
	printf("%d\n",MAX(2, 3 > 4 ? 3 : 4));
	printf("%d\n",MAX(a++, 6));
	printf("%d\n",a);
	P(MAX(2,3));
	P(5 + MAX(2,3));
	P(MAX(2,MAX(3,4)));
	P(MAX(2,3 > 4 ? 3 : 4));
	P(MAX(a++, 6));
	P(a);
	return 0;
}

```

```c
g++ -E 文件名
//显示处理掉所有预处理命令后的代码，观察处理后代码，理解其实际进行了的操作。
```

### 实现一个打印日志的函数

实现一个打印LOG的函数，

```c
#include<stdio.h>

#ifndef DEBUG 

#define log(frm, args...) {\
	printf("[%s : %d]", __func__, __LINE__);\
	printf(frm,##args);\
	printf("\n");\
} 
//args... ->可变参数列表 //##表示连接内容，可以为空了  

#else
#define log(frm,args...)
#endif

#define contact(a,b) a##b

int main() {
	int a = 7;
	int abcdef = 19;
	log("%d", a);
	log("hello,world"); //如果变参函数为空，程序会报错 
	log("%d", abcdef);
	contact(abc, def) = 21;
	//abcdef = 21
	log("%d", abcdef);
	return 0;
}
```

