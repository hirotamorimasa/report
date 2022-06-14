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
	int line;
	for(int city_012 = 0; city_012 < DATA_SET; city_012++)
	{
		for(int city_022 = 0; city_022 < DATA_SET; city_022++)
		{
			if(city012_line_data[city_012] > city022_line_data[city_022])
				line = city012_line_data[city_012];
			else
				line = city022_line_data[city_022];

			for(int i = 0; i < line; i++)
				for(int k = 0; k < DIMENSION; k++)
					dp[city_012][city_022] += pow(city012_data[city_012][i][k] - city022_data[city_022][i][k], 2.0);
		dp[city_012][city_022] = pow(dp[city_012][city_022], 0.5);
		}
	}
}

void dp_minimum(int store[DATA_SET], double min[DATA_SET], double dp[DATA_SET][DATA_SET])
{
        for(int i = 0; i < DATA_SET; i++)
        {
                for(int j = 0; j < DATA_SET; j++)
                {
                        //最初は0番目を格納
                        if(j == 0)
                                min[i] = dp[i][j];
                        //0~99番までの最小値を探す
                        else
                        {
                                if(min[i] >= dp[i][j])
                                {
                                        min[i] = dp[i][j];
                                        store[i] = j + 1;
                                }
                        }
                }
        }
}

void dp_minimum_print(int store[DATA_SET], double min[DATA_SET])                                 
{
        for(int i = 0; i < DATA_SET; i++)
                printf("city011_%03d.txt---->city021_%03d.txt:%lf\n", i+1, store[i], min[i]);
}

void proportion(int store[DATA_SET])
{
	int ratio = 0;
	for(int i = 0; i < DATA_SET; i++)
		if((i+1) == store[i])
			ratio++;
	printf("ratio=%lf\n", (double)ratio / 100.0);
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
	double min[DATA_SET];
	int store[DATA_SET];

	city012_File_Line(city012_line_data);
	city022_File_Line(city022_line_data);

	city012_main(city012_data, city012_data1300);
	city022_main(city022_data, city022_data1300);

	dp_processing(city012_line_data, city022_line_data, dp, city012_data, city022_data);
	dp_minimum(store, min, dp);
//	dp_minimum_print(store, min);

	proportion(store);
	return 0;
}

