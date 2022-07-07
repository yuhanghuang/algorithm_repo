#include<stdio.h>
#include<string.h>
int main()
{
    char string[65535];
    int set[26];
    for (int i = 0; i < 26; i++)
    {
        /* code */
        set[i] = 0;
    }
    scanf("%s",string);
    for(int i =0;i<strlen(string);i++)
    {   
        set[string[i]-97]++;
    }
    int count =0;
    for(int i =0;i<26;i++)
    {
        if(set[i]!=0){
            count++;
        }
    }
    //  printf("总个数为%d",count);
    // printf("%d",set[0]);
     int temp[100][100],temp2[100][100];
     memset(temp,0,sizeof(temp));
     memset(temp2,0,sizeof(temp2));
    char str22[10]="qaaawert";
    int str11[26];
    memset(str11,0,sizeof(str11));
    count_char(str22,str11);
    // printf("%d",str11[0]);
    char dest[65535];
    int first =1;
    int appear = 0;
     for(int i =0;i<strlen(string)-1;i++)
     {
         for (int j = i+1; j < strlen(string); j++)
         {
             /* code */
             int strin[26],temps;
             strncpy(dest,&string[i],j-i+1);
             //printf("%s\n",dest);
             count_char(dest,strin);
             //printf("%d %d %d\n",strin['a'-97],strin['s'-97],strin['d'-97]);
             //printf("%d到%d的字符个数是%d\n",i,j,count_number(strin,temps));
             
             if(count_number(strin,temps)==count)
             {
                if(first>=1)
                {
                    appear = j-i+1;
                    first--;
                }
                temp2[i][j]=j-i+1;
                //printf("找到了%d到%d",i,j);
                
             }
             memset(dest,'\0',sizeof(dest));
             memset(strin,0,sizeof(strin));
             temps = 0;
             temp[i][j]=count_number(strin,temps);
             
         }
        
     }
    int  min = appear;
    for(int i =0;i<99;i++)
    {
        for (int  j = i+1; j < 100; j++)
        {
            /* code */
            if(temp2[i][j]<=min&&temp2[i][j]!=0)
            {
                min = temp2[i][j];
            }
        }
        
    }
    //printf("------%d\n",min);
    int flag =1;
    for (int i = 0; i < 99&&flag; i++)
    {
        /* code */
        for (int j = 0; j < 100; j++)
        {
            /* code */
            if(temp2[i][j]==min)
            {
                // printf("*****find it%d %d",i,j-i+1);
                printf("(%d,%d)",i,j-i+1);
                flag--;
                break;
            }
        }
        
    }
    



     

}

void count_char(char * str1,int * str2)
{
    for (int i = 0; i < strlen(str1); i++)
    {
        /* code */
        str2[str1[i]-97]++;
    }
    
}

int count_number(int * str,int tempdd)
{
    for (int i = 0; i < 26; i++)
    {
        /* code */
        if(str[i]!=0)
        {
            tempdd++;
        }
    }
    return tempdd;
    
}