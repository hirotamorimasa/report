#include <stdio.h>
#include <stdlib.h>
#include "./sub.city012/city012.h"
#include "./sub.city021/city021.h"

#define FRAME 100
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分

//void dp_processing(double dp[FRAME][DIMENSION], double city)

int main(void)
{
	double city012_data[DATA_SET][FRAME][DIMENSION];
	double city021_data[DATA_SET][FRAME][DIMENSION];

	double city012_data1300[DATA_SET][NUMBER];
	double city021_data1300[DATA_SET][NUMBER];

//	double dp[FRAME][DIMENSION];

	city012_main(city012_data, city012_data1300);
	city021_main(city021_data, city021_data1300);
	return 0;
}

