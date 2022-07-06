//
//  main.cpp
//  experiment4
//
//  Created by lulin on 2022/5/16.
//

#include "lab4_main.hpp"
void run(int argc, char *argv[])//各种菜单和函数
{
    int choice;
do{
        printf("黄秋焱的实验四程序:\n");
        printf("\
           6. 调用实验3生成数据记录文件，同时读取数据记录文件（二维数组方式存储）\n\
           7. 调用实验3生成数据记录文件，同时读取数据记录文件（结构体数组方式存储）\n\
           8. 调用实验3生成数据记录文件，同时读取数据记录文件（指针数组方式存储）\n\
           9. 调用实验3生成数据记录文件，同时读取数据记录文件（链表方式存储）\n\
           10. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（二维数组方式存储）\n\
           11.调用实验3生成数据记录文件，同时读取数据记录文件并排序（结构体数组方式存储）\n\
           12. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（指针数组方式存储）\n\
           13. 调用实验3生成数据记录文件，同时读取数据记录文件并排序（链表方式存储）\n\
           14. 重新设置配置参数值\n\
           0.结束\n");
    printf("请输入序号以选择功能：");
    scanf("%d", &choice);
    switch(choice)
    {
        case 6:
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            MatrixStore(datas.filename, 0);
            break;
        }
        case 7:
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            StructStore(datas.filename, 0);
            break;
        }
        case 8:
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            PointArryStore(datas.filename, 0);
            break;
        }
        case 9:
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            LinkStore(datas.filename, 0);//1表示要排序
            break;
        }
        case 10://二维数组存储并排序
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            MatrixStore(datas.filename, 1);
            break;
        }
        case 11://用结构体存储并排序
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            StructStore(datas.filename, 1);
            break;
        }
        case 12://用指针数组存储并排序
        {
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            PointArryStore(datas.filename, 1);
            break;
        }
        case 13://用链表存储并排序
        {
            
            CONF datas;
            read(&datas);
            Call(datas.mode, &datas);//调用外部函数，两种模式
            LinkStore(datas.filename, 1);//1表示要排序
            break;
        }
        case 14:
        {
            int line;
            do{
                printf("1.数据记录文件的默认存储目录\n\
                        2.存储数据记录文件的文件名信息\n\
                        3.生成的默认记录条数\n\
                        4.生成的数据记录三元组中第1、2个元素取值的上限\n\
                        5.生成的数据记录三元组中第1、2个元素取值的下限\n\
                        6.生成的数据记录三元组中第3个元素取值的上限\n\
                        7.生成的数据记录三元组中第3个元素取值的下限\n\
                        8.数据记录文件需要随机生成记录条数时条数值的上限\n\
                        9.数据记录文件需要随机生成记录条数时条数值的下限\n\
                        10.模式（1是自动模式，2是交互模式）\n\
                        0.结束\n");
                printf("请选择要修改的内容代表的序号：");
                scanf("%d", &line);
                if(line)
                    Modification(line);//修改
              }while(line);
            break;
         }
            
     }
 }while(choice);
        
   
}

void read(CONF* datas)//读取文件内容，要用指针！！！！
{
    FILE *fp;
    if ((fp = fopen("conf.ini.txt", "r")) == NULL)
    { printf("打不开配置文件"); exit(0);}
    else
    {    //从文件里读取一行,遇到空格回车EOF结束读取
        fscanf(fp, "%s\n", datas->filesavepath);
        fscanf(fp, "%s\n", datas->filename);
        fscanf(fp, "%d\n", &datas->maxvalue1);
        fscanf(fp, "%d\n", &datas->minvalue1);
        fscanf(fp, "%d\n", &datas->maxvalue2);
        fscanf(fp, "%d\n", &datas->minvalue2);
        fscanf(fp, "%d\n", &datas->recordcount1);
        fscanf(fp, "%d\n", &datas->recordcount2);
        fscanf(fp, "%d\n", &datas->mode);
    }
    if(fclose(fp))//无法成功关闭返回1
    {
        printf("file cannot be closed!\n");
        exit(0);
    }
}
