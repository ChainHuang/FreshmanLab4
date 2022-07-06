//
//  lab4_conf.cpp
//  experiment4
//
//  Created by lulin on 2022/5/16.
//

#include "lab4_conf.hpp"
void Modification(int line)//修改配置文件指定行的内容
{
    CONF datas;  
    read(&datas);
    switch(line)
    {
        case 1:
        {
            printf("当前默认文件名是:%s\n", datas.filesavepath);
            printf("请输入新的默认文件生成路径：\n");
            scanf("\n%s", datas.filesavepath);
            datas.filesavepath[strlen(datas.filesavepath)] = '\0';
            break;
        }
        case 2:
        {
            printf("当前默认文件名是:%s\n", datas.filename);
            printf("请输入新的默认文件名:\n");
            scanf("\n%s", datas.filename);
            datas.filename[strlen(datas.filename)] = '\0';
            break;
        }
        case 3:
        {
            printf("当前默认数据生成条数是:%d\n", datas.number);
            printf("请输入新的默认数据生成条数：\n");
            scanf("\n%d", &datas.number);
            break;
        }
        case 4:
        {
            printf("当前第1，2个元素的下限是:%d,请注意上限要大于它,除非你接下来选择修改下限\n",datas.minvalue1);
            printf("请输入新的第1,2个元素的上限:\n");
            scanf("\n%d", &datas.maxvalue1);
            break;
        }
        case 5:
        {
            printf("当前第1，2个元素的上限是:%d,请注意下限要小于它,除非你接下来选择修改上限\n",datas.maxvalue1);
            printf("请输入新的第1，2个元素的下限:\n");
            scanf("\n%d", &datas.minvalue1);
            break;
        }
        case 6:
        {
            printf("当前第3个元素的下限是:%d,请注意上限要大于它,除非你接下来选择修改下限\n",datas.minvalue2);
            printf("请输入新的第3个元素的上限:\n");
            scanf("\n%d", &datas.maxvalue2);
            break;
        }
        case 7:
        {
            printf("当前第3个元素的上限是:%d,请注意下限要小于它,除非你接下来选择修改上限\n",datas.maxvalue2);
            printf("请输入新的第3个元素的下限:\n");
            scanf("\n%d", &datas.minvalue2);
            break;
        }
        case 8:
        {
            printf("当前生成记录条数的下限是:%d\n", datas.recordcount2);
            printf("请输入新的生成记录条数的上限:\n");
            scanf("\n%d", &datas.recordcount1);
            break;
        }
        case 9:
        {
            printf("当前生成记录条数的上限是:%d\n", datas.recordcount1);
            printf("请输入新的生成记录条数的下限:\n");
            scanf("\n%d", &datas.recordcount2);
            break;
        }
        case 10:
        {
            printf("请输入新的默认模式（1是自动模式，2是交互模式）:\n");
            scanf("\n%d", &datas.mode);
            break;
        }
    }
    FILE *fp;
    if ((fp = fopen("conf.ini.txt", "w")) == NULL)
    { printf("打不开配置文件"); exit(0);}
    else
        fprintf(fp, "%s\n", datas.filesavepath);
        fprintf(fp, "%s\n", datas.filename);
        fprintf(fp, "%d\n", datas.maxvalue1);
        fprintf(fp, "%d\n", datas.minvalue1);
        fprintf(fp, "%d\n", datas.maxvalue2);
        fprintf(fp, "%d\n", datas.minvalue2);
        fprintf(fp, "%d\n", datas.recordcount1);
        fprintf(fp, "%d\n", datas.recordcount2);
        fprintf(fp, "%d\n", datas.mode);
    if(fclose(fp))//无法成功关闭返回1
    {
        printf("file cannot be closed!\n");
        exit(0);
    }
    
}

