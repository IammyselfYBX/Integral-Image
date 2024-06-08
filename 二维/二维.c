/*
 * @name: 积分图像
 * @description: 随机给出二维随机数放到二维数组(mxn)中，
 *               然后再给出一个小的矩阵区域(axb, a<m, b<n)，
 *               求出矩阵中以每个节点x_i开始向下向后的axb矩阵的平均值。
 *               -----------------------------------------------
 *               a00 a01 a02 a03 a04 a05 a06 a07 a08 a09 
 *               a10 ⭕  a12 a13 a14 a15 a16 a17 a18 a19  
 *               a20 a21 a22 a23 a24 a25 a26 a27 a28 a29 
 *               a30 a31 a32 a33 a34 a35 a36 a37 a38 a39 
 *               比方说，以⭕为起点，计算出以⭕开始向下向后的2x3矩形中的平均值。
 *               就是 (a11+a12+a13+a21+a22+a23)/6 
 *               -----------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void initialize_matrix(double **original_matrix, long m, long n); // 初始化矩阵，全部赋值为0
void print_matrix(double **original_matrix, long m, long n);      // 打印矩阵
void input_matrix(double **original_matrix, long m, long n);      // 输入矩阵
void compute_sum_matrix(double **original_matrix, double **sum_matrix, long m, long n); // 计算矩阵的和                                                                

int main(int argc, char *argv[])
{
    long m, n; // 矩阵的行数和列数
    printf("请输入矩阵的行数和列数(中间用' '隔开): ");
    scanf("%ld %ld", &m, &n);
    // 矩阵的动态分配:存储随机变量的
    double **original_matrix = (double **)malloc(m * sizeof(double *));
    for (long i = 0; i < m; i++)
        original_matrix[i] = (double *)malloc(n * sizeof(double));

    // 矩阵的动态分配:存储矩阵元素行列从0开始计算的和 A_{ij} = \sum_{k=0}^{i}\sum_{l=0}^{j}a_{kl}
    double **sum_matrix = (double **)malloc(m * sizeof(double *));
    for (long i = 0; i < m; i++)
        sum_matrix[i] = (double *)malloc(n * sizeof(double));

    // 矩阵初始化,赋值为0
    initialize_matrix(original_matrix, m, n);
    initialize_matrix(sum_matrix, m, n);
    //printf("初始化后的矩阵为：\n");
    //print_matrix(original_matrix, m, n);

    // 矩阵赋值
    input_matrix(original_matrix, m, n);
    // 先计算出sum_matrix
    compute_sum_matrix(original_matrix, sum_matrix, m, n);
    // 打印矩阵
    printf("原始矩阵为：\n");
    print_matrix(original_matrix, m, n);
    printf("计算后的矩阵为：\n");
    print_matrix(sum_matrix, m, n);

    // 开始计算小矩形的平均值
    printf("请输入小矩形的行数和列数(中间用' '隔开): ");
    long a, b; // 小矩形的行数和列数
    scanf("%ld %ld", &a, &b);
    printf("请输入要计算点的坐标x_i和y_i(中间用' '隔开): ");
    long x_i, y_i; // 要计算点的坐标
    scanf("%ld %ld", &x_i, &y_i);
    if(x_i < 0 || x_i > m || y_i < 0 || y_i > n){
        printf("输入的坐标超出矩阵边界！\n");
        return 0;
    }else if(x_i > m-a || y_i > n-b){
        printf("输入的坐标超出可以计算边界！\n"); //因为在行 n-b 开始就没办法再往后数b个数了
        return 0;
    }

    double result = 0;
    result = sum_matrix[x_i+a-2][y_i+b-2] - sum_matrix[x_i-2][y_i+b-2] - sum_matrix[x_i+a-2][y_i-2] + sum_matrix[x_i-2][y_i-2];
    printf("在点(%ld,%ld)处开始往后和往下的以长=%ld宽=%ld矩形中全部数字计算后的平均值结果为：%lf\n", x_i, y_i, b, a, result/(a*b));

    // 使用完一定要释放内存
    free(original_matrix);
    free(sum_matrix);

    return 0;
}

void compute_sum_matrix(double **original_matrix, double **sum_matrix, long m, long n)
{
    long i, j;
    
    // 先按照每列进行计算
    for(i=0; i<m; i++){
        sum_matrix[i][0] = original_matrix[i][0];
    }
    for(i =0; i<m; i++){
        for(j=1; j<n; j++){
            sum_matrix[i][j] = sum_matrix[i][j-1] + original_matrix[i][j];
        }
    }
    // 再按照每行进行计算
    for(j=0; j<n;j++){
        for(i=1; i<m; i++){
            sum_matrix[i][j] = sum_matrix[i-1][j] + sum_matrix[i][j];
        }
    }
}

void input_matrix(double **matrix, long m, long n)
{
    for(long i = 0; i < m; i++)
        for(long j = 0; j < n; j++){
            printf("请输入第%ld行第%ld列的元素：", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
}

void initialize_matrix(double **matrix, long m, long n)
{
    long i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            matrix[i][j] = 0;
}

void print_matrix(double **matrix, long m, long n)
{
    long i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("\t%lf", matrix[i][j]);
        printf("\n");
    }
}
