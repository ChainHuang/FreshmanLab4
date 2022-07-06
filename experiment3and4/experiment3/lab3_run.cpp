//
//  lab3_run.cpp
//  experiment3and4
//
//  Created by lulin on 2022/5/16.
//

#include "lab3_run.hpp"

int run(int argc,const char *argv[],CONF* datas)//判断输入参数合法性
{
 int t;
    int number = 0,choice=1;
 char filename[MAX_STR_LEN];
    
 switch (argc)
 {
     case 1://自动模式
     {//{}别忘了！
             srand((int)(time(0)));
             number = rand() % (datas->recordcount1-datas->recordcount2+1) + datas->recordcount2;
            //[recordcount2,recordcount1]
             strcpy(filename, datas->filename);
            FILE *fp = NULL;
            CreateFile(filename, datas, &fp);
            int *str = NULL;
            UseMatrixToStore(number, str, fp, datas);
      
                                            break;
     }
 case 3:if ((t = isdigit(*argv[1])) == 0)
         {
            printf("输入的第一个命令行参数不是整数，程序结束！\n");
            return 0;
         }
        else
        {
            char ch[20];
            strcpy(ch, argv[2]);
            if(CheckFilename(ch) == 0)
             {
              printf("输入的第二个参数不是合法文件名或合法路径名，程序结束！\n");
              return 0;
             }
            number = atoi(argv[1]);
            strcpy(filename, argv[2]);
            FILE *fp = NULL;
            CreateFile(filename, datas, &fp);
            int *str = NULL;
            UseMatrixToStore(number, str, fp, datas);
        }                                  break;
 default:printf("命令行参数个数错误，程序结束！\n");
                                           return 0;
 }
    
  return 0;
}

