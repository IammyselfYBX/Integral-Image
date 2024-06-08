#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("请输入一组随机数(用' '隔开): ");
    long a[100], length=0, x;
    do{
        scanf("%ld", &a[length]);
        length++;
    }while (getchar() != '\n');
    printf("%ld\n", length);
    for(long j =0; j < length; j++){
        printf("%ld ", a[j]);
    }
    printf("\n");
    
    printf("请输入是几个数之和: ");
    scanf("%ld", &x);
    long b[100];

    printf("输入完成！\n");
    // 计算从第j位开始的连续k位数之和
    for(long j =0; j < length; j++){
        b[j] = 0;
        if(j <= length - x){
            for(long k = 0; k < x; k++){
                b[j] += a[k+j];
            }
        }
        else{
            for(long k = 0; k < x; k++){
                b[j] += a[(k+j)%length];
            }
        }
    }
    printf("计算完成\n");

    // 打印结果
    for(long j =0; j < length; j++){
        printf("%ld ", b[j]);
    }
    printf("\n");

    return 0;
}
