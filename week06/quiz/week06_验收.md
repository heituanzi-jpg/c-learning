# Week 06 验收卷（数组与字符串）

> 规矩：题 1 闭卷；题 2、3 用自己的话，答在本文件下方或发我都行。
> 全过 → 解锁 Week07（Git 与 GitHub——你的代码要上网了）。

## 题 1 · 实操：反转机

在 `reverse.c`（本目录，已建好）写：scanf 收 5 个整数进数组，**倒序**打印。

自检数据：`1 2 3 4 5` → `5 4 3 2 1`；`7 7 7 7 7` → `7 7 7 7 7`（全相同的边界，反转不该崩）。

## 题 2 · 大白话

① scanf 读 int 要写 `&age`，读字符串却写 `scanf("%s", name)` 不加 `&`——为什么？（用"门牌号"说，不许抄书）
② `sizeof(a) / sizeof(a[0])` 在 main 里能算出格子数，进了函数为什么就失灵？那该怎么办？

### 我的回答
1. 字符串也是一个数组 name记录的是该数组第一位的地址 而且字符串后面又\0可以截停
2. 因为传递值 只传了地址 


## 题 3 · 找茬（5 个错误：3 个本周坑 + 2 个老坑复考）

```c
#include <stdio.h>

int get_avg(int arr[], int n) {
    int sum;
    for (int i = 1; i <= n; i++) {
        sum = sum + arr[i];
    }
    return sum / n;
}

int main() {
    char name[4] = "kay gu";
    int scores[3] = {70, 82, 90};
    printf("平均分: %d\n", get_avg(scores, 3));
    printf("最高分: %d\n", scores[3]);
    return 0;
}
```

找出、改正、跑通，至少挑 2 条记进 mistakes.md。

### 我找到的 5 个错误

1. main函数字符串长度 char name[7] 空格加上\0;
2. 在函数中sum应=0，现在sum一开始有垃圾值
3. for循环初始化起点在0
4. 最高分没有定义函数 
5. 
