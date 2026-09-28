/*旧代码
#include <stdio.h>
int main () {
    int n,average,count=0;
    double sum=0;
    average=sum/count;
    while (1) {scanf("n=%d",n);
        if (n=-1) {
            printf("一门都没输");
            break;
        }printf("共%d门,平均分%d.",count,average);}
 
    
}*/
//首先是哨兵模式的框架部分，直接将上述的代码复制过来。
/*看到题目最开始的想法 是最后面的自检数据 需要输入多个值 并从中间有一些空格
多个值是通过一个scanf 里面的多个占位符实现一个输入的吗 n放在最后又是如何进行一个检测的 我不理解
 
下面是一些问题 以及我对问题的回答
Q1租柜子 我的理解就是租变量
sum（double） count（int） n(int) average(double) 还有各门课的分是不是定义成i 然后做一个依次累加
在此处已经有一些坐牢的感觉 是复习以及每日投入时间 以及衔接的一个问题 这点是非常重要的 需要记录并向外部龙虾进行一个反馈 让他对于之后的日程以及节奏进行一个把控
Q2不知道 
到这个时候我才理解了题目的意思 以及那个负1是如何的 类似是一个数组 循环叠加 if检测到-1之后停止
可能要回顾一下 卡住了
到这一步 突然恍然大悟 哨兵模式不是说重复循环 而是在用户输入多个数时使用的一种方式
我的理解有失偏颇 等C语言结束之后再回看一下python 应该会好一点
由此可以得出Q1有四个变量 sum(double) count(int) score(int)包含检测的那个-1 average(double) 但是循环scanf能够收如此多的数并井井有条 我还是比较难以理解的
只要循环一圈就好了
这里是这样子的 我突然有一种终于有一点会C语言的感觉


/*
#include <stdio.h>
int main () {
    int count,score;
    double sum ,average;
    while(1){
        scanf("%lf",&score);
        if(score==-1){
            if(count==0){printf("一门都没输");}
            else if{
            printf("共%d门,平均分%f",count,average);
            break;}
        }
    }
        此处参考了kimicode的建议 但是整体依旧不是自己写出来的 依旧在熟练度上面有一些欠缺 是蛮大的问题
 int main() {
    // 第一段【循环外·前面】：租柜子，清零
    //   sum = 0, count = 0

    // 第二段【循环本身】：只管收数和记账
    //   while (1) {
    //       scanf 收一门
    //       if 是 -1 → break        ← 跳出的是"第二段"这一项
    //       否则 += 成绩, count++
    //   }                            ← break 后跳到这里，继续往下

    // 第三段【循环外·后面】：汇报结果
    //   if (count > 0) 打印"共X门，平均分Y"
    //   else 打印"一门都没输"
}
    */
#include <stdio.h>
int main(){
    //第一层，循环外
    int count,sum=0;
    //第二段：（循环本身）：只管收数和记账
    while (1){
        double score;
        scanf("%lf",&score);
        if (score==-1){
            break;
        }else{
            count=count+1;
            sum=sum+score;
        }

    }if(count>0){
        double average=0;
        average= sum/count ;
        printf("共%d门,平均分%1f",count,average);
    }else{
        printf("一门都没输");
    }
    
}