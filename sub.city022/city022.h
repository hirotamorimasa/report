#include <stdio.h>
#include <stdlib.h>

#define FRAME 80
#define DIMENSION 15
#define STRING 16	//city0xx_001.txt~city0xx_100.txt
#define NUMBER 916	//city011_001.txt~city011_100.txt
#define DATA_SET 100   //データセット100個分

int file_line(char fname[])
{
	int ch;
	FILE *fp;
	int line = 0;
	int count = 0;

	fp = fopen(fname, "r");
	while((ch = fgetc(fp)) != EOF)
		if(ch == 10)
			count++;
	fclose(fp);
	return count;
}

void file_print(char city022[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = file_line(city022[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void file_read(char city022[][STRING], double data[DATA_SET][NUMBER])
{
	FILE *fp;
	int count = 0;
	int result;
	int frame = 0, dimension = 0;	//frame:61行  dimension:15要素(列)
	int line;

	for(int i = 0; i < DATA_SET; i++)
	{
		fp = fopen(city022[i], "r");
		if(fp == NULL)
		{
			printf("%s file don't  open.\n", city022[i]);
			return;
		}
		line = file_line(city022[i]);
		for(int j = 0; j < DIMENSION * line; j++)
		{
			result = fscanf(fp, "%lf", &data[i][count]);
			if(result == EOF)	break;
			count++;
		}
		count = 0;
	}
	fclose(fp);
	return;
}

//二次元配列に変換する
void file_processing(char city022[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = file_line(city022[i]);
		for(int j = 0; j < line; j++)
		{
			for(int k = 0; k < DIMENSION; k++)
				data[i][j][k] = data915[i][count++];
		}
	count = 0;
	}
}

void city022_main(void)
{
	double data[DATA_SET][FRAME][DIMENSION];	//ファイルのデータを格納
	double data_915[DATA_SET][NUMBER];
	    char city022[][STRING] = {                                          
                 "city022_001.txt", "city022_002.txt", "city022_003.txt",
                 "city022_004.txt", "city022_005.txt", "city022_006.txt",
                 "city022_007.txt", "city022_008.txt", "city022_009.txt",
                 "city022_010.txt", "city022_011.txt", "city022_012.txt",
                 "city022_013.txt", "city022_014.txt", "city022_015.txt",
                 "city022_016.txt", "city022_017.txt", "city022_018.txt",
                 "city022_019.txt", "city022_020.txt", "city022_021.txt",
                 "city022_022.txt", "city022_023.txt", "city022_024.txt",
                 "city022_025.txt", "city022_026.txt", "city022_027.txt",
                 "city022_028.txt", "city022_029.txt", "city022_030.txt",
                 "city022_031.txt", "city022_032.txt", "city022_033.txt",
                 "city022_034.txt", "city022_035.txt", "city022_036.txt",
                 "city022_037.txt", "city022_038.txt", "city022_039.txt",
                 "city022_040.txt", "city022_041.txt", "city022_042.txt",
                 "city022_043.txt", "city022_044.txt", "city022_045.txt",
                 "city022_046.txt", "city022_047.txt", "city022_048.txt",
                 "city022_049.txt", "city022_050.txt", "city022_051.txt",
                 "city022_052.txt", "city022_053.txt", "city022_054.txt",
                 "city022_055.txt", "city022_056.txt", "city022_057.txt",
                 "city022_058.txt", "city022_059.txt", "city022_060.txt",
                 "city022_061.txt", "city022_062.txt", "city022_063.txt",
                 "city022_064.txt", "city022_065.txt", "city022_066.txt",
                 "city022_067.txt", "city022_068.txt", "city022_069.txt",
                 "city022_070.txt", "city022_071.txt", "city022_072.txt",
                 "city022_073.txt", "city022_074.txt", "city022_075.txt",
                 "city022_076.txt", "city022_077.txt", "city022_078.txt",
                 "city022_079.txt", "city022_080.txt", "city022_081.txt",
                 "city022_082.txt", "city022_083.txt", "city022_084.txt",
                 "city022_085.txt", "city022_086.txt", "city022_087.txt",
                 "city022_088.txt", "city022_089.txt", "city022_090.txt",
                 "city022_091.txt", "city022_092.txt", "city022_093.txt",
                 "city022_094.txt", "city022_095.txt", "city022_096.txt",
                 "city022_097.txt", "city022_098.txt", "city022_099.txt",
                 "city022_100.txt"
		 };

	file_read(city022, data_915);
	file_processing(city022, data, data_915);
	file_print(city022, data);
	return;
}















