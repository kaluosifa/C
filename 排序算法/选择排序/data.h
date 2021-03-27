#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
 * 功能：向data.txt文件写入size个随机long型数
 */
void CreateData(long size);

/*
 * 功能：从data.txt文件获取size个数据存入arr数组中
 */
void GetData(long arr[], long size);

#endif