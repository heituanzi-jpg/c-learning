# Week 05 验收卷（函数与指针初识）

> 规矩：题 1 闭卷；题 2、3 用自己的话，答在本文件下方或发我都行。
> 全过 → 解锁 Week06（数组与字符串）。

## 题 1 · 实操：温度转换函数版

在 `temp_f.c`（本目录，已建好）写：`double to_celsius(double f)` 把华氏度算成摄氏度返回（公式 W02 的 `C = (F - 32) * 5 / 9`），main 里 scanf 收华氏度、调用、打印（保留 2 位小数）。

自检数据：`100` → `37.78`；`32` → `0.00`；`-40` → `-40.00`（华氏摄氏的秘密交点，边界三问之"特殊值"）。

## 题 2 · 大白话

① 为什么 `change(a)` 改不动 `a`，而 `scanf("%d", &age)` 能改动 `age`？（从"复印件"和"门牌号上门"两个词说，不许抄书）
② `return` 的两个作用是什么？"屏幕上看到了"和"程序手里拿到了"有什么区别？

### 我的回答

我先没有看代码凭借记忆进行回答，首先是因为change()函数是void只能接受不能返回 作用域局限 根本没法return 改了作用域内部的值 而指针则是直接根据地址改写对应的值 
首先是返回函数中的值 另一个忘记了
就是上面的第一个 有的改变仅仅是打印出了相关的值 而没有对储存的值进行修改

## 题 3 · 找茬（5 个错误：3 个本周坑 + 2 个老坑复考）

```c
#include <stdio.h>

int add(int a, int b); {
    int sum = a + b;
}

void set_to_99(int x) {
    x = 99;
}

int main() {
    int total = add(3, 5);
    printf("3+5 = %d\n", total);
    int score = 60;
    set_to_99(score);
    printf("score = %d\n", score);
    int age;
    scanf("%d", age);
    double height, weight;
    double bmi = weight / (height * height);
    printf("BMI = %f\n", bmi);
    return 0;
}
```

找出、改正、跑通，至少挑 2 条记进 mistakes.md。

### 我找到的 5 个错误

1.(){}中间不能加；
2.在main函数里第一个调用函数打印 忽视了add函数里面没有return sum值
3.main函数里面第二次调用函数 void不能返回值 如果要输出 首先是printf直接调用打印且函数内部也有printf能够打印 其次是直接调用函数时输入相关的&对应的值 然后在函数内部用定义指针并直接对main函数内的该值位置进行修改
4.scnf 没有加对应的解地址符
5.最后算bmi的没有定义相关的值 每次height以及weight随机出一个值进行计算
