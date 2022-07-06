//
//  lab4_loadfile.cpp
//  experiment4
//
//  Created by lulin on 2022/5/23.
//

#include "lab4_loadfile.hpp"

int linkcmp(const void *a, const void *b)//qsort的cmp要int型函数，sort才是bool型
{
    LINKLIST** p1 = (LINKLIST **)a;
    LINKLIST** p2 = (LINKLIST **)b;
    return (*p1)->item3 - (*p2)->item3;//要用二级指针，因为实参是地址，是将地址排序
}
void Link_qsort(LINKLIST * head, int number)
{
    double start = clock();//计时
    LINKLIST **copy = new LINKLIST *[number];
    //用new分配number个指针数组并返回二级指针，保存的是链表结点地址,对结点地址排序
    //也可：copy = (LINKLIST **)malloc(number*sizeof(LINKLIST *));
    copy[0] = head;
    for(int i = 1; i < number; i++)
    {
        copy[i] = (copy[i-1])->next;
    }
    qsort(copy, number, sizeof(LINKLIST *), linkcmp);
    for(int i = 0; i < number; i++)
    {
        printf("%d %d %d\n", copy[i]->item1, copy[i]->item2, copy[i]->item3);
    }
    delete[] copy;
    double end = clock();
    printf("qsort排序链表用时：%lf秒\n", (double)(end - start)/1000);
}
void Link_double(LINKLIST *head, int number)//这里head没有数据
{
    double start = clock();
    LINKLIST *p1,*p2,*tail;
    int flag = 0;
    tail = NULL;
  while(head->next->next != tail)
  {
      flag = 0;
      p1 = head;
      p2 = head->next;
      while(p2->next != tail)
      {
          if((p2->item3) > (p2->next->item3))
          {
              
              p1->next = p2->next;
              p2->next = p2->next->next;
              p1->next->next = p2;
              p2 = p1->next;
          }
          p2 = p2->next;
          p1 = p1->next;
      }
      tail = p2;
  }
    LINKLIST *t = head->next;
    for(int i = 0; i < number; i++)
    {
        printf("%d %d %d\n", t->item1, t->item2, t->item3);
        t = t->next;
    }
    double end = clock();
    printf("冒泡链表排序耗时：%lf秒\n", (double)(end - start)/1000);
}
void LinkStore(char *filename, int flag)
{
    LINKLIST *node, *head;
    head = (LINKLIST *)malloc(sizeof(LINKLIST));
    node = (LINKLIST *)malloc(sizeof(LINKLIST));
    head->next = node;
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL)
    {printf("数据记录文件无法打开");exit(0);}
    int number;
    fscanf(fp, "%d\n", &number);//第一个数据是生成的条数
    for(int i = 0; i < number; i++)//将数据存入链表
    {
        if(0 == i)
        fscanf(fp, "%d,%d,%d\n", &head->item1, &head->item2, &head->item3);
        else
       {
        fscanf(fp, "%d,%d,%d\n", &node->item1, &node->item2, &node->item3);
        if(i < (number-1))
         {
            node->next = (LINKLIST *)malloc(sizeof(LINKLIST));
            node = node->next;
         }
        else
            node->next = NULL;
       }
    }
    LINKLIST *t = head;
    printf("链表不排序存储的数据如下：\n");
    for(int i = 0; i < number; i++)
    {
        printf("%d %d %d\n", t->item1, t->item2, t->item3);
        t = t->next;
    }
    if(flag)//若需要排序
    {
        printf("链表qsort排序结果如下，以第三个元素升序排:\n");
        Link_qsort(head, number);
        printf("链表冒泡排序结果如下，以第三个元素升序排:\n");
        LINKLIST *head_0;//不放数据
        head_0 = (LINKLIST *)malloc(sizeof(LINKLIST));
        head_0->next = head;
        Link_double(head_0, number);
    }
}

int Structcmp(const void *a, const void *b)
{
    int p1 = ((STRUCT* )a)->item3;
    int p2 = ((STRUCT* )b)->item3;
    return p1 - p2;
}
void Struct_qsort(STRUCT *stru, int number)
{
    double start = clock();//计时
    qsort(stru, number, sizeof(STRUCT), Structcmp);
    for(int i = 0; i < number; i++)
    {
        printf("%d %d %d\n", stru[i].item1, stru[i].item2, stru[i].item3);
    }
    double end = clock();
    printf("qsort结构体排序用时：%lf秒\n", (double)(end - start) / 1000);
}
void StructStore(char *filename, int flag)
{
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL)
    {printf("数据记录文件无法打开");exit(0);}
    int number;
    fscanf(fp, "%d\n", &number);//第一个数据是生成的条数
    STRUCT *stru = NULL;
    stru = (STRUCT *)malloc(number * sizeof(STRUCT));
    for(int i = 0; i < number; i++)
    {
       fscanf(fp, "%d,%d,%d\n", &stru[i].item1, &stru[i].item2, &stru[i].item3);
    }
    printf("结构体不排序存储的数据如下:\n");
    for(int i = 0; i < number; i++)
    {
        printf("%d %d %d\n", stru[i].item1, stru[i].item2, stru[i].item3);
    }
    if(flag)
    {
        printf("结构体排序后结果如下，以第三个元素升序排:\n");
        Struct_qsort(stru, number);
    }
}

int Matrixcmp(const void *a, const void *b)
{
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;
    return *(p1 + 2) - *(p2 + 2);
}

void Matrix_qsort(int **matrix, int number)
{
    double start = clock();
    qsort(matrix, number, sizeof(matrix[0]), Matrixcmp);
    qsort(matrix, number, sizeof(matrix[0]), Matrixcmp);
    for(int i = 0; i < number; i++)
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    double end = clock();
    printf("qsort二维数组排序用时:%lf秒\n", (double)(end - start) / 1000);
}
void MatrixStore(char *filename, int flag)
{
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL)
    {printf("数据记录文件无法打开");exit(0);}
    int number;
    fscanf(fp, "%d\n", &number);//第一个数据是生成的条数
    int **matrix;
    matrix = (int** )malloc(number * sizeof(int *));
    for(int i = 0; i < number; i++)
        *(matrix + i) = (int *)malloc(3*sizeof(int));
    for(int i = 0; i < number; i++)
        fscanf(fp, "%d,%d,%d\n", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
    printf("二维数组不排序存储数据如下:\n");
    for(int i = 0; i < number; i++)
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    if(flag)
    {
        printf("二维数组排序后结果如下，以每行第三个元素升序排:\n");
        Matrix_qsort(matrix, number);
    }
    for(int i = 0; i < number; i++)
        free(*(matrix + i));
    free(matrix);
             
}

int PointArrycmp(const void *a, const void *b)
{
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;
    return *(p1 + 2) - *(p2 + 2);
}
void PointArry_qsort(int *pa[], int number)
{
    qsort(pa, number, sizeof(pa[0]), PointArrycmp);
    for(int i = 0; i < number; i++)
        printf("%d %d %d\n", *pa[i], *(pa[i]+1), *(pa[i]+2));
}
void PointArryStore(char *filename, int flag)
{
    FILE *fp;
    if((fp = fopen(filename, "r")) == NULL)
    {printf("数据记录文件无法打开");exit(0);}
    int number;
    fscanf(fp, "%d\n", &number);//第一个数据是生成的条数
    int *pa[number];
    for(int i = 0; i < number; i++)
        pa[i] = new int [3];
    for(int i = 0; i < number; i++)
        fscanf(fp, "%d,%d,%d\n", pa[i], (pa[i]+1), (pa[i]+2));
    printf("二位数组不排序存储数据如下:\n");
    for(int i = 0; i < number; i++)
        printf("%d %d %d\n", *pa[i], *(pa[i]+1), *(pa[i]+2));
    if(flag)
    {
        printf("排序后结果如下，以第三个元素升序排\n");
        PointArry_qsort(pa, number);
    }
    
}
