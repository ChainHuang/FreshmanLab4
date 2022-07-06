//
//  lab3_fun.cpp
//  experiment3and4
//
//  Created by lulin on 2022/5/16.
//

#include "lab3_fun.hpp"

void CreateFile(char* filename, CONF* datas, FILE**fp)
//void()创建文件，要双重指针！！！！！
{
    //如果filename是文件名,那么就用默认路径
    if(strstr(filename, "/") == NULL)
    {
        if(access(datas->filesavepath, F_OK) != 0)//如果默认目录不存在就创建
       {
        char cm[20];
        sprintf(cm,"mkdir %s",datas->filesavepath);
        system(cm);
       }
        strcat(datas->filesavepath, "/");
        strcat(datas->filesavepath, filename);
        if((*fp = fopen(datas->filesavepath, "w")) == NULL)
        {printf("创建文件失败！");exit(0);}
    }
    else//若filename是相对路径
    {
       
        strcpy(datas->filesavepath, "/Users/lulin");
        strcat(datas->filesavepath, filename);
        if((*fp = fopen(datas->filesavepath, "w")) == NULL)
        { printf("创建文件失败！");exit(0);}
    }
}
        
void UseMatrixToStore(int number, int *str, FILE *fp, CONF* datas)
//用二维数组存储并将数据写入文件
{
        //动态内存分配二维数组
    str = (int *)malloc(number*3*sizeof(int));
    int x, i, j;
    srand((int)time(0));
    fprintf(fp, "%d\n", number);
    for (i = 1; i <= number; i++)
      for (j = 1; j <= 3; j++)
     {
        if(3 == j)
        {
            x = rand() % (datas->maxvalue2 - datas->minvalue2 + 1) + datas->minvalue2;//[min,max]
            fprintf(fp, "%d\n", x);
            *(str+3*i+j) = x;
        }
        else if(2 == j || 1 == j)
        {
            x = rand() % (datas->maxvalue1 - datas->minvalue1 + 1) + datas->minvalue1;
            fprintf(fp, "%d,", x);
            *(str+3*i+j) = x;
        }
     }
  if (fclose(fp))//若返回1则关闭文件失败
 {
  printf("file cannot be closed!\n");
  exit(0);
 }
  for (i = 1; i <= number; i++)
    for (j = 1; j <= 3; j++)
     if (j == 3)
         printf("%d\n", *(str+3*i+j) );
     else
         printf("%d,", *(str+3*i+j) );
  free(str);
}

void UseStructToStore(int number, DATAITEM *str, FILE *fp, CONF* datas)
//用结构体数组存储并将数据写入文件
{
    str = (DATAITEM *)malloc(number*sizeof(DATAITEM));
    int x, i, j;//将生成的随机数存入结构体数组里
    srand((int)time(0));
    fprintf(fp, "%d\n", number);
    for (i = 1; i <= number; i++)
      for (j = 1; j <= 3; j++)
     {
        if(3 == j)
         {
            x = rand() % (datas->maxvalue2 - datas->minvalue2 + 1) + datas->minvalue2;//[min,max]
             str[i*3].item3 = x;
            fprintf(fp, "%d\n", x);
         }
        else if(1 == j)
          {   x = rand() % (datas->maxvalue1 - datas->minvalue1 + 1) + datas->minvalue1;
             str[i*3].item1 = x;
             fprintf(fp, "%d,", x);
             
          }
             else if(2 == j)
             {
                 x = rand() % (datas->maxvalue1 - datas->minvalue1 + 1) + datas->minvalue1;
                 str[i*3].item2 = x;
                 fprintf(fp, "%d,", x);
             }
     }
      
    if (fclose(fp))//若返回1则关闭文件失败
   {
    printf("file cannot be closed!\n");
    exit(0);
   }
    for (i = 1; i <= number; i++)
      for (j = 1; j <= 3; j++)
       {
          if (3 == j)
           printf("item3:%d\n", str[i*3].item3);
       else if(1 == j)
           printf("item1:%d,", str[i*3].item1);
           else
               printf("item2:%d,", str[i*3].item2);
       }
    free(str);
    
}

int CheckFilename(char file[])
{
    int flag=1;
    if(strstr(file, ":") != NULL)
        flag = 0;
    if(strstr(file, "*") != NULL)
        flag = 0;
    if(strstr(file, "<") != NULL)
        flag = 0;
    if(strstr(file, ">") != NULL)
        flag = 0;
    if(strstr(file, "?") != NULL)
        flag = 0 ;
    if(strstr(file, "\"") != NULL)
        flag = 0;
    if(strstr(file, "|") != NULL)
        flag = 0;
    if(strstr(file, ".txt") ==NULL )//没找到
        flag = 0;
    return flag;
        
}

