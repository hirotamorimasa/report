#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./sub.city011/city011.h"
#include "./sub.city021/city021.h"
#include "./city011_line.h"
#include "./city021_line.h"

#define FRAME 150
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分

void dp_processing(int city011_line_data[DATA_SET], int city021_line_data[DATA_SET], double dp[DATA_SET][DATA_SET], double city011_data[DATA_SET][FRAME][DIMENSION], double city021_data[DATA_SET][FRAME][DIMENSION])
{
	int city_011, city_021;
	
	//city011のファイルを100個分ソート
	for(city_011 = 0; city_011 < DATA_SET; city_011++)
	{
		//city021のファイルを100個分ソート
		for(city_021 = 0; city_021 < DATA_SET; city_021++)
		{
			int line_011 = city011_line_data[city_011];
			int line_021 = city021_line_data[city_021];
			for(int i = 0; i < line_011; i++)
				for(int j = 0; j < line_021; j++)
					for(int k = 0; k < DIMENSION; k++)
						dp[city_011][city_021] += pow(city011_data[city_011][i][k] - city021_data[city_021][j][k], 2.0);
		}
		dp[city_011][city_021] = pow(dp[city_011][city_021], 0.5);
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
	double city021_data[DATA_SET][FRAME][DIMENSION];

	double city011_data1300[DATA_SET][NUMBER];	
	double city021_data1300[DATA_SET][NUMBER];

	int city011_line_data[DATA_SET];	//行数を格納する
	int city021_line_data[DATA_SET];

	double dp[DATA_SET][DATA_SET];

	city011_File_Line(city011_line_data);
	city021_File_Line(city021_line_data);

	city011_main(city011_data, city011_data1300);
	city021_main(city021_data, city021_data1300);
	
	dp_processing(city011_line_data, city021_line_data, dp, city011_data, city021_data);
	dp_print(dp);
	return 0;
}

