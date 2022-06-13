#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./sub.city012/city012.h"
#include "./sub.city022/city022.h"
#include "./city012_line.h"
#include "./city022_line.h"

#define FRAME 150
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分

void dp_processing(int city012_line_data[DATA_SET], int city022_line_data[DATA_SET], double dp[DATA_SET][DATA_SET], double city012_data[DATA_SET][FRAME][DIMENSION], double city022_data[DATA_SET][FRAME][DIMENSION])
{
	int city_012, city_022;
	for(city_012 = 0; city_012 < DATA_SET; city_012++)
	{
		for(city_022 = 0; city_022 < DATA_SET; city_022++)
		{
			int line_012 = city012_line_data[city_012];
			int line_022 = city022_line_data[city_022];
			for(int i = 0; i < line_012; i++)
				for(int j = 0; j < line_022; j++)
					for(int k = 0; k < DIMENSION; k++)
						dp[city_012][city_022] += pow(city012_data[city_012][i][k] - city022_data[city_022][j][k], 2.0);
		}
		dp[city_012][city_022] = pow(dp[city_012][city_022], 0.5);
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
	double city012_data[DATA_SET][FRAME][DIMENSION];
	double city022_data[DATA_SET][FRAME][DIMENSION];

	double city012_data1300[DATA_SET][NUMBER];
	double city022_data1300[DATA_SET][NUMBER];
	
	int city012_line_data[DATA_SET];
	int city022_line_data[DATA_SET];

	double dp[DATA_SET][DATA_SET];

	city012_File_Line(city012_line_data);
	city022_File_Line(city022_line_data);

	city012_main(city012_data, city012_data1300);
	city022_main(city022_data, city022_data1300);

	dp_processing(city012_line_data, city022_line_data, dp, city012_data, city022_data);
	dp_print(dp);
	return 0;
}

