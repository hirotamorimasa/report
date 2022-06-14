#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "./sub.city011/city011.h"
#include "./sub.city022/city022.h"
#include "./city011_line.h"
#include "./city022_line.h"

#define FRAME 150
#define DIMENSION 15
#define STRING 30	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500	//city011_001.txt~city011_100.txt
#define DATA_SET 100	//データセット100個分

//局所間の距離を計算
void dp_processing(int city011_line_data[DATA_SET], int city022_line_data[DATA_SET], double dp[DATA_SET][DATA_SET], double city011_data[DATA_SET][FRAME][DIMENSION], double city022_data[DATA_SET][FRAME][DIMENSION])
{
        int line;
        //city011のファイルを100個分ソート
        for(int city_011 = 0; city_011 < DATA_SET; city_011++)
        {
                //city021のファイルを100個分ソート
                for(int city_022 = 0; city_022 < DATA_SET; city_022++)
                {
                        if(city011_line_data[city_011] < city022_line_data[city_022])
                                line = city022_line_data[city_022];
                        else
                                line = city011_line_data[city_011];

                        for(int i = 0; i < line; i++)
                                for(int k = 0; k < DIMENSION; k++)
                                        dp[city_011][city_022] += pow(city011_data[city_011][    i][k] - city022_data[city_022][i][k], 2.0);
                        
                        dp[city_011][city_022] = pow(dp[city_011][city_022], 0.5);
                }
        }
}

//最小値を計算
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
//ヒットしたファイルと照らし合わせる
void dp_minimum_print(int store[DATA_SET], double min[DATA_SET])
{
        for(int i = 0; i < DATA_SET; i++)
                printf("city011_%03d.txt---->city021_%03d.txt:%lf\n", i+1, store[i], min[i]);
}

//割合を計算
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
	double city011_data[DATA_SET][FRAME][DIMENSION];
	double city022_data[DATA_SET][FRAME][DIMENSION];

	double city011_data1300[DATA_SET][NUMBER];
	double city022_data1300[DATA_SET][NUMBER];
	
	int city011_line_data[DATA_SET];
	int city022_line_data[DATA_SET];

	double dp[DATA_SET][DATA_SET];
	double min[DATA_SET];
	int store[DATA_SET];
	
	city011_File_Line(city011_line_data);
	city022_File_Line(city022_line_data);

	city011_main(city011_data, city011_data1300);
	city022_main(city022_data, city022_data1300);

	dp_processing(city011_line_data, city022_line_data, dp, city011_data, city022_data);
	dp_minimum(store, min, dp);
//	dp_minimum_print(store, min);

	proportion(store);
	return 0;
}
