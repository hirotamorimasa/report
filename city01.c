#include <stdio.h>
#include <stdlib.h>
#include "./sub.city011/city011.h"
#include "./sub.city012/city012.h"

#define FRAME 80
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分


int main(void)
{
	double city011_data[DATA_SET][FRAME][DIMENSION];
	double city012_data[DATA_SET][FRAME][DIMENSION];

	double city011_data1300[DATA_SET][NUMBER];
	double city012_data1300[DATA_SET][NUMBER];

	city011_main(city011_data, city011_data1300);
	city012_main(city012_data, city012_data1300);
	return 0;
}
