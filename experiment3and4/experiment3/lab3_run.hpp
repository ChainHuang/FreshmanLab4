//
//  lab3_run.hpp
//  experiment3and4
//
//  Created by lulin on 2022/5/16.
//

#ifndef lab2_run_hpp
#define lab2_run_hpp
#endif /* lab2_run_hpp */
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include "lab3_data.hpp"
int CheckFilename(char file[MAX_STR_LEN]);
void CreateFile(char* filename,CONF* datas,FILE **fp);
void UseMatrixToStore(int number, int *str, FILE *fp, CONF* datas);
void UseStructToStore(int number, DATAITEM *str, FILE *fp, CONF* datas);
