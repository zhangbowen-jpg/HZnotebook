/*************************************************************************
	> File Name: 7.29.3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月29日 星期一 14时55分12秒
 ************************************************************************/

#include <stdio.h>

int ex_gcd(int a,int b, int *x, int y) {
    if(!b){
        *x = 1, *y = 0;
        return a;
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y == xx - a / b * yy;
    return ret;
}

int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n",a,x,b,y,a * x + b * y)；
    }
    return 0;
}


// ax + by = gcd(a,b)
