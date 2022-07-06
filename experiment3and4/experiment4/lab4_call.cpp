//
//  lab4_call.cpp
//  experiment4
//
//  Created by lulin on 2022/5/16.
//

#include "lab4_call.hpp"

 void Call(int mode, CONF *datas)
{
   if(2 == mode)//交互模式
   {
       printf("请输入你想要的文件名或相对路径：");
       char filename[50];
       scanf("%s", filename);
       printf("请输入你想要生成的数据条数：");
       int num;
       scanf("%d", &num);
       char buffer[180];
       sprintf(buffer, "/Users/lulin/Library/Developer/Xcode/DerivedData/experiment3and4-czdekmnztgbinpggrkzwudafaofb/Build/Products/Debug/experiment3and4 %d %s", num, filename);
       system(buffer);
     //xcode生成的可执行文件路径查找：preference-location-derived data箭头-build-product-debug-拖到终端显示出可执行文件路径
       strcpy(datas->filename, filename);//为之后打开记录数据文件
       datas->filename[strlen(filename)] = '\0';
       datas->number = num;
   }
else system("/Users/lulin/Library/Developer/Xcode/DerivedData/experiment3and4-czdekmnztgbinpggrkzwudafaofb/Build/Products/Debug/experiment3and4");
//自动模式
}
