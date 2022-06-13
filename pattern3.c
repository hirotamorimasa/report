#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./sub.city011/city011.h"
#include "./sub.city012/city012.h"
#include "./city011_line.h"
#include "./city012_line.h"

#define FRAME 150
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分

void dp_processing(int city011_line_data[DATA_SET], int city012_line_data[DATA_SET], double dp[DATA_SET][DATA_SET], double city011_data[DATA_SET][FRAME][DIMENSION], double city012_data[DATA_SET][FRAME][DIMENSION])
{
	int city_011, city_012;
	for(city_011 = 0; city_011 < DATA_SET; city_011++)
	{
		for(city_012 = 0; city_012 < DATA_SET; city_012++)
		{
			int line_011 = city011_line_data[city_011];
			int line_012 = city012_line_data[city_012];
			for(int i = 0; i < line_011; i++)
				for(int j = 0; j < line_012; j++)
					for(int k = 0; k < DIMENSION; k++)
						dp[city_011][city_012] += pow(city011_data[city_011][i][k] - city012_data[city_012][j][k], 2.0);
		}
		dp[city_011][city_012] = pow(dp[city_011][city_012], 0.5);
	}
}

void dp_print(double dp[DATA_SET][DATA_SET])
{
	for(int i = 0; i < DATA_SET; i++)
		for(int j = 0; j < DATA_SET; j++)
			printf("dp[%d][%d]:%lf\n", i+1, j+1, dp[i][j]);
}

int main(void)
{
	double city011_data[DATA_SET][FRAME][DIMENSION];
	double city012_data[DATA_SET][FRAME][DIMENSION];

	double city011_data1300[DATA_SET][NUMBER];
	double city012_data1300[DATA_SET][NUMBER];

	int city011_line_data[DATA_SET];
	int city012_line_data[DATA_SET];

	double dp[DATA_SET][DATA_SET];

	city011_File_Line(city011_line_data);
	city012_File_Line(city012_line_data);

	city011_main(city011_data, city011_data1300);
	city012_main(city012_data, city012_data1300);
	
	dp_processing(city011_line_data, city012_line_data, dp, city011_data, city012_data);
	dp_print(dp);
	return 0;
}

