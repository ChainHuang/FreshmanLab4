//
//  lab4.cpp
//  experiment4
//
//  Created by lulin on 2022/5/16.
//

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>//access()
#include <sys/stat.h>
void run(int argc, char *argv[]);
int Self_Check();

int main(int argc, char *argv[])
{
    if(Self_Check())
     run(argc, argv);
     return 0;
 }


int Self_Check()
{
    int flag = 1;
    FILE *fp;
    if ((fp = fopen("conf.ini.txt", "r")) == NULL)
    {
        printf("配置文件打不开");
        flag = 0;
        fclose(fp);
    }
    else
    {
        char filesavepath[50];
      fscanf(fp, "%s", filesavepath);
      if(access(filesavepath, 0) != 0)
      {
        if(mkdir(filesavepath ,0777) != 0)//若创建文件夹失败
            flag = 0;
        printf("默认生成路径不存在");
      }
     fclose(fp);
    }
    if(access("/Users/lulin/Library/Developer/Xcode/DerivedData/experiment3and4-czdekmnztgbinpggrkzwudafaofb/Build/Products/Debug/experiment3and4", 0) !=0)
     {
         printf("实验三可执行文件不存在");
         flag = 0;
     }
    if(!flag)
        return 0;
    else
        return 1;
}
