#include <stdio.h>
#include <stdlib.h>
#include "./sub.city012/city012.h"
#include "./sub.city022/city022.h"

#define FRAME 100
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分


int main(void)
{
	double city012_data[DATA_SET][FRAME][DIMENSION];
	double city022_data[DATA_SET][FRAME][DIMENSION];

	double city012_data1300[DATA_SET][NUMBER];
	double city022_data1300[DATA_SET][NUMBER];

	city012_main(city012_data, city012_data1300);
	city022_main(city022_data, city022_data1300);
	return 0;
}
