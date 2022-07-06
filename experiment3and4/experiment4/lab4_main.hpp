//
//  lab4.hpp
//  experiment4
//
//  Created by lulin on 2022/5/16.
//

#ifndef lab4_main_h
#define lab4_main_h
#include <cstdio>
#include <stdlib.h>
#include "lab4_datas.hpp"
void Modification(int line);
void read(CONF *datas);
void Call(int mode, CONF *datas);
void LinkStore(char *filename, int flag);
void StructStore(char *filename, int flag);
void MatrixStore(char *filename, int flag);
void PointArryStore(char *filename, int flag);
#endif /* lab4_main_h */
