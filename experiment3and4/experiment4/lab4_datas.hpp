//
//  la4_data.hpp
//  experiment3and4
//
//  Created by lulin on 2022/5/16.
//

#define MAX_STR_LEN 50
typedef  struct  configinfo {
char  filesavepath[MAX_STR_LEN] ;         //用于存放数据记录文件的存储目录
char  filename[MAX_STR_LEN] ;              //用于存储数据记录文件的文件名信息
int  number;        //用于存放生成的记录条数
int  maxvalue1 ;           //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
int  minvalue1;         //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
int  maxvalue2 ;           //用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
int  minvalue2;         //用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
int  recordcount1;    //用于存放数据记录文件需要随机生成记录条数时条数值的上限
int  recordcount2;    //用于存放数据记录文件需要随机生成记录条数时条数值的下限
int mode;             //记录模式（1是自动模式，2是交互模式。
} CONF;
typedef struct Link_list
{
    int item1,item2,item3;
    Link_list* next;//不可用缩写的LINKLIST
}LINKLIST;
typedef struct
{
    int item1, item2, item3;
}STRUCT;
