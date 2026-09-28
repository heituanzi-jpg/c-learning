# Week 07 验收卷（Git 与 GitHub）

> 全过 → 解锁 Week08：🏆 毕业项目周（命令行计算器）。

## 题 1 · 实操

- 仓库公开链接：`https://github.com/heituanzi-jpg/c-learning` ✅（已达成）
- 本地 `git log --oneline` 终端记录（≥3 条，含本周）：

wow@kaizen:~/code/c-learning$ git log --oneline
a2a357a (HEAD -> main, origin/main) 给bmi.c添加文件说明注释
ca83750 补充 week01-06 全部 .c 源代码
21939b0 Week01-06 全部学习代码与笔记归档
4dcbb05 第一周:与之前胡乱尝试的不同

## 题 2 · 大白话

① `git add` 和 `git commit` 的区别？（用"拍照"说，不许抄书）
② `.gitignore` 是干嘛的？为什么编译出来的可执行文件不该传上 GitHub？（至少两个理由）

### 我的回答

1. git add 是在改完文件第一个输入的 将git status里面的红的字改成绿的字 类似是放到暂存区里 commit对此次行为改进的代码进行一个解释说明
2. 类似是一个在我的文件夹到github上面中间加的一个筛选器 筛选掉了需要去掉 不用上传的文件
；
(1) 冗余 别人电脑上面完全可以再自己编译一遍

## 题 3 · 找茬（这段操作记录有 5 处错误）

```bash
cd ~/code
git init
git add week01/hello.c
git commit
git remote add origin git@github.com:heituanzi-jpg/c-learning.git
git push origin master
# （想把编译产物 hello 也传上去，直接 git add hello）
```

### 我找到的 5 处错误

1.没有c-learning
2.commit没有说明吧
3.remote之前都没有ssh连接
4.
5.

> 提示：这段记录里有 3 个错是你这周【亲手踩过】的——认出来就是最大的收获。
