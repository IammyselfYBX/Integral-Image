/*
 * @Descripttion:计算一组随机数中几位之和
 * 1.手动输入一组随机数 放到a[] 数组中
 * 2.定义b[i]， b[i] =a[0]+...+ a[i]
 * 3.给出区间长度l 
 * 4.给出要求的节点位置 k
 * 5.打印结果 c[k] = b[k+l-1] - b[k-1]
 * */
#include <stdio.h>

int main(int argc, char *argv[])
{
    long a[100], b[100], c[100];
    long i, j, k, l, n, length=0;
    printf("请输入一组随机数，以回车结束: ");
    do{
        scanf("%ld", &a[length]);
        length++;
    }while (getchar() != '\n');
    printf("随机数的长度为:%ld\n", length);

    for (i = 0; i < length; i++)
    {
        b[i] = 0;
        for (j = 0; j <= i; j++)
        {
            b[i] += a[j];
        }
    }
    printf("请输入区间长度l:");
    scanf("%ld", &l);
    printf("请输入待求的节点位置k:");
    scanf("%ld", &k);
    c[k] = b[k+l-2] - b[k-2];
    printf("c[%ld] = %ld\n", k, c[k]);

    return 0;
}
