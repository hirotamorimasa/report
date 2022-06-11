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

void file_print(char city021[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = file_line(city021[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void file_read(char city021[][STRING], double data[DATA_SET][NUMBER])
{
	FILE *fp;
	int count = 0;
	int result;
	int frame = 0, dimension = 0;	//frame:61行  dimension:15要素(列)
	int line;

	for(int i = 0; i < DATA_SET; i++)
	{
		fp = fopen(city021[i], "r");
		if(fp == NULL)
		{
			printf("%s file don't  open.\n", city021[i]);
			return;
		}
		line = file_line(city021[i]);
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
void file_processing(char city021[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = file_line(city021[i]);
		for(int j = 0; j < line; j++)
		{
			for(int k = 0; k < DIMENSION; k++)
				data[i][j][k] = data915[i][count++];
		}
	count = 0;
	}
}

void city021_main(void)
{
	double data[DATA_SET][FRAME][DIMENSION];	//ファイルのデータを格納
	double data_915[DATA_SET][NUMBER];
	char city021[][STRING] = {
                 "city021_001.txt", "city021_002.txt", "city021_003.txt",
                 "city021_004.txt", "city021_005.txt", "city021_006.txt",
                 "city021_007.txt", "city021_008.txt", "city021_009.txt",
                 "city021_010.txt", "city021_011.txt", "city021_012.txt",
                 "city021_013.txt", "city021_014.txt", "city021_015.txt",
                 "city021_016.txt", "city021_017.txt", "city021_018.txt",
                 "city021_019.txt", "city021_020.txt", "city021_021.txt",
                 "city021_022.txt", "city021_023.txt", "city021_024.txt",
                 "city021_025.txt", "city021_026.txt", "city021_027.txt",
                 "city021_028.txt", "city021_029.txt", "city021_030.txt",
                 "city021_031.txt", "city021_032.txt", "city021_033.txt",
                 "city021_034.txt", "city021_035.txt", "city021_036.txt",
                 "city021_037.txt", "city021_038.txt", "city021_039.txt",
                 "city021_040.txt", "city021_041.txt", "city021_042.txt",
                 "city021_043.txt", "city021_044.txt", "city021_045.txt",
                 "city021_046.txt", "city021_047.txt", "city021_048.txt",
                 "city021_049.txt", "city021_050.txt", "city021_051.txt",
                 "city021_052.txt", "city021_053.txt", "city021_054.txt",
                 "city021_055.txt", "city021_056.txt", "city021_057.txt",
                 "city021_058.txt", "city021_059.txt", "city021_060.txt",
                 "city021_061.txt", "city021_062.txt", "city021_063.txt",
                 "city021_064.txt", "city021_065.txt", "city021_066.txt",
                 "city021_067.txt", "city021_068.txt", "city021_069.txt",
                 "city021_070.txt", "city021_071.txt", "city021_072.txt",
                 "city021_073.txt", "city021_074.txt", "city021_075.txt",
                 "city021_076.txt", "city021_077.txt", "city021_078.txt",
                 "city021_079.txt", "city021_080.txt", "city021_081.txt",
                 "city021_082.txt", "city021_083.txt", "city021_084.txt",
                 "city021_085.txt", "city021_086.txt", "city021_087.txt",
                 "city021_088.txt", "city021_089.txt", "city021_090.txt",
                 "city021_091.txt", "city021_092.txt", "city021_093.txt",
                 "city021_094.txt", "city021_095.txt", "city021_096.txt",
                 "city021_097.txt", "city021_098.txt", "city021_099.txt",
                 "city021_100.txt"
                 };

	file_read(city021, data_915);
	file_processing(city021, data, data_915);
	file_print(city021, data);
	return;
}















