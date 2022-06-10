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

void file_print(char city011[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = file_line(city011[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void file_read(char city011[][STRING], double data[DATA_SET][NUMBER])
{
	FILE *fp;
	int count = 0;
	int result;
	int frame = 0, dimension = 0;	//frame:61行  dimension:15要素(列)
	int line;

	for(int i = 0; i < DATA_SET; i++)
	{
		fp = fopen(city011[i], "r");
		if(fp == NULL)
		{
			printf("%s file don't  open.\n", city011[i]);
			return;
		}
		line = file_line(city011[i]);
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
void file_processing(char city011[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = file_line(city011[i]);
		for(int j = 0; j < line; j++)
		{
			for(int k = 0; k < DIMENSION; k++)
				data[i][j][k] = data915[i][count++];
		}
	count = 0;
	}
}

int main(void)
{
	double data[DATA_SET][FRAME][DIMENSION];	//ファイルのデータを格納
	double data_915[DATA_SET][NUMBER];
	char city011[][STRING] = {
		"city011_001.txt", "city011_002.txt", "city011_003.txt",
		"city011_004.txt", "city011_005.txt", "city011_006.txt",
		"city011_007.txt", "city011_008.txt", "city011_009.txt",
		"city011_010.txt", "city011_011.txt", "city011_012.txt",
		"city011_013.txt", "city011_014.txt", "city011_015.txt",
		"city011_016.txt", "city011_017.txt", "city011_018.txt",
		"city011_019.txt", "city011_020.txt", "city011_021.txt",
		"city011_022.txt", "city011_023.txt", "city011_024.txt",
		"city011_025.txt", "city011_026.txt", "city011_027.txt",
		"city011_028.txt", "city011_029.txt", "city011_030.txt",
		"city011_031.txt", "city011_032.txt", "city011_033.txt",
		"city011_034.txt", "city011_035.txt", "city011_036.txt",
		"city011_037.txt", "city011_038.txt", "city011_039.txt",
		"city011_040.txt", "city011_041.txt", "city011_042.txt",
		"city011_043.txt", "city011_044.txt", "city011_045.txt",
		"city011_046.txt", "city011_047.txt", "city011_048.txt",
		"city011_049.txt", "city011_050.txt", "city011_051.txt",
		"city011_052.txt", "city011_053.txt", "city011_054.txt",
		"city011_055.txt", "city011_056.txt", "city011_057.txt",
		"city011_058.txt", "city011_059.txt", "city011_060.txt",
		"city011_061.txt", "city011_062.txt", "city011_063.txt",
		"city011_064.txt", "city011_065.txt", "city011_066.txt",
		"city011_067.txt", "city011_068.txt", "city011_069.txt",
		"city011_070.txt", "city011_071.txt", "city011_072.txt",
		"city011_073.txt", "city011_074.txt", "city011_075.txt",
		"city011_076.txt", "city011_077.txt", "city011_078.txt",
		"city011_079.txt", "city011_080.txt", "city011_081.txt",
		"city011_082.txt", "city011_083.txt", "city011_084.txt",
		"city011_085.txt", "city011_086.txt", "city011_087.txt",
		"city011_088.txt", "city011_089.txt", "city011_090.txt",
		"city011_091.txt", "city011_092.txt", "city011_093.txt",
		"city011_094.txt", "city011_095.txt", "city011_096.txt",
		"city011_097.txt", "city011_098.txt", "city011_099.txt",
		"city011_100.txt"
	};
	file_read(city011, data_915);
	file_processing(city011, data, data_915);
	file_print(city011, data);
return 0;
}















