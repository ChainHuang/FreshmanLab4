//
//  main.cpp
//  experiment3and4
//
//  Created by lulin on 2022/5/16.
//

#include "lab3.hpp"

int main(int argc, const char *argv[])
{
 CONF datas;
 read(&datas);
 run(argc, argv, &datas);
 return 0;
}
void read(CONF* datas)//要用指针！！！
{
    FILE *fp;
    if ((fp = fopen("conf.ini.txt", "r")) == NULL)
        printf("Cannot open the data file!");
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
