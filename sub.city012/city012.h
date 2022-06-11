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

void file_print(char city012[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = file_line(city012[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void file_read(char city012[][STRING], double data[DATA_SET][NUMBER])
{
	FILE *fp;
	int count = 0;
	int result;
	int frame = 0, dimension = 0;	//frame:61行  dimension:15要素(列)
	int line;

	for(int i = 0; i < DATA_SET; i++)
	{
		fp = fopen(city012[i], "r");
		if(fp == NULL)
		{
			printf("%s file don't  open.\n", city012[i]);
			return;
		}
		line = file_line(city012[i]);
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
void file_processing(char city012[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = file_line(city012[i]);
		for(int j = 0; j < line; j++)
		{
			for(int k = 0; k < DIMENSION; k++)
				data[i][j][k] = data915[i][count++];
		}
	count = 0;
	}
}

void city012_main(void)
{
	double data[DATA_SET][FRAME][DIMENSION];	//ファイルのデータを格納
	double data_915[DATA_SET][NUMBER];
	 char city012[][STRING] = {
                 "city012_001.txt", "city012_002.txt", "city012_003.txt",
                 "city012_004.txt", "city012_005.txt", "city012_006.txt",
                 "city012_007.txt", "city012_008.txt", "city012_009.txt",
                 "city012_010.txt", "city012_011.txt", "city012_012.txt",
                 "city012_013.txt", "city012_014.txt", "city012_015.txt",
                 "city012_016.txt", "city012_017.txt", "city012_018.txt",
                 "city012_019.txt", "city012_020.txt", "city012_021.txt",
                 "city012_022.txt", "city012_023.txt", "city012_024.txt",
                 "city012_025.txt", "city012_026.txt", "city012_027.txt",
                 "city012_028.txt", "city012_029.txt", "city012_030.txt",
                 "city012_031.txt", "city012_032.txt", "city012_033.txt",
                 "city012_034.txt", "city012_035.txt", "city012_036.txt",
                 "city012_037.txt", "city012_038.txt", "city012_039.txt",
                 "city012_040.txt", "city012_041.txt", "city012_042.txt",
                 "city012_043.txt", "city012_044.txt", "city012_045.txt",
                 "city012_046.txt", "city012_047.txt", "city012_048.txt",
                 "city012_049.txt", "city012_050.txt", "city012_051.txt",
                 "city012_052.txt", "city012_053.txt", "city012_054.txt",
                 "city012_055.txt", "city012_056.txt", "city012_057.txt",
                 "city012_058.txt", "city012_059.txt", "city012_060.txt",
                 "city012_061.txt", "city012_062.txt", "city012_063.txt",
                 "city012_064.txt", "city012_065.txt", "city012_066.txt",
                 "city012_067.txt", "city012_068.txt", "city012_069.txt",
                 "city012_070.txt", "city012_071.txt", "city012_072.txt",
                 "city012_073.txt", "city012_074.txt", "city012_075.txt",
                 "city012_076.txt", "city012_077.txt", "city012_078.txt",
                 "city012_079.txt", "city012_080.txt", "city012_081.txt",
                 "city012_082.txt", "city012_083.txt", "city012_084.txt",
                 "city012_085.txt", "city012_086.txt", "city012_087.txt",
                 "city012_088.txt", "city012_089.txt", "city012_090.txt",
                 "city012_091.txt", "city012_092.txt", "city012_093.txt",
                 "city012_094.txt", "city012_095.txt", "city012_096.txt",
                 "city012_097.txt", "city012_098.txt", "city012_099.txt",
                 "city012_100.txt"
                 };

	file_read(city012, data_915);
	file_processing(city012, data, data_915);
	file_print(city012, data);
	return;
}















