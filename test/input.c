#include<stdio.h>
int main() {
    // int N = 0;
    // int first[10],second[10],third[10];
	// scanf("%d", &N);
	// for (int i = 1; i <= N; i++)
	// {
	// 	scanf("%d %d %d", &first[i], &second[i], &third[i]);
	// 	printf("%d %d %d\n", first[i], second[i], third[i]);
	// }

    char str1[10][10];//定义二维数组，保存多个字符串
    int num;
    scanf("%d",&num);
    int i = 0;
    while (num--)
    {
        scanf("%s", &str1[i]);
        i++;
    }



}