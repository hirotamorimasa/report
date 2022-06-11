#include <stdio.h>
#include <stdlib.h>

#define FRAME 80
#define DIMENSION 15
#define STRING 30       //city0xx_001.txt~city0xx_100.txt
#define NUMBER 916      //city011_001.txt~city011_100.txt
#define DATA_SET 100   //データセット100個分

int city011_file_line(char fname[])                                     
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

void city011_file_print(char city011[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = city011_file_line(city011[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void city011_file_read(char city011[][STRING], double data[DATA_SET][NUMBER])
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
		line = city011_file_line(city011[i]);
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
void city011_file_processing(char city011[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = city011_file_line(city011[i]);
		for(int j = 0; j < line; j++)
		{
			for(int k = 0; k < DIMENSION; k++)
				data[i][j][k] = data915[i][count++];
		}
	count = 0;
	}
}

void city011_main(void)
{
	double data[DATA_SET][FRAME][DIMENSION];	//ファイルのデータを格納
	double data_915[DATA_SET][NUMBER];
	char city011[][STRING] = {
		"./sub.city011/city011_001.txt", "./sub.city011/city011_002.txt", "./sub.city011/city011_003.txt",
		"./sub.city011/city011_004.txt", "./sub.city011/city011_005.txt", "./sub.city011/city011_006.txt",
		"./sub.city011/city011_007.txt", "./sub.city011/city011_008.txt", "./sub.city011/city011_009.txt",
		"./sub.city011/city011_010.txt", "./sub.city011/city011_011.txt", "./sub.city011/city011_012.txt",
		"./sub.city011/city011_013.txt", "./sub.city011/city011_014.txt", "./sub.city011/city011_015.txt",
		"./sub.city011/city011_016.txt", "./sub.city011/city011_017.txt", "./sub.city011/city011_018.txt",
		"./sub.city011/city011_019.txt", "./sub.city011/city011_020.txt", "./sub.city011/city011_021.txt",
		"./sub.city011/city011_022.txt", "./sub.city011/city011_023.txt", "./sub.city011/city011_024.txt",
		"./sub.city011/city011_025.txt", "./sub.city011/city011_026.txt", "./sub.city011/city011_027.txt",
		"./sub.city011/city011_028.txt", "./sub.city011/city011_029.txt", "./sub.city011/city011_030.txt",
		"./sub.city011/city011_031.txt", "./sub.city011/city011_032.txt", "./sub.city011/city011_033.txt",
		"./sub.city011/city011_034.txt", "./sub.city011/city011_035.txt", "./sub.city011/city011_036.txt",
		"./sub.city011/city011_037.txt", "./sub.city011/city011_038.txt", "./sub.city011/city011_039.txt",
		"./sub.city011/city011_040.txt", "./sub.city011/city011_041.txt", "./sub.city011/city011_042.txt",
		"./sub.city011/city011_043.txt", "./sub.city011/city011_044.txt", "./sub.city011/city011_045.txt",
		"./sub.city011/city011_046.txt", "./sub.city011/city011_047.txt", "./sub.city011/city011_048.txt",
		"./sub.city011/city011_049.txt", "./sub.city011/city011_050.txt", "./sub.city011/city011_051.txt",
		"./sub.city011/city011_052.txt", "./sub.city011/city011_053.txt", "./sub.city011/city011_054.txt",
		"./sub.city011/city011_055.txt", "./sub.city011/city011_056.txt", "./sub.city011/city011_057.txt",
		"./sub.city011/city011_058.txt", "./sub.city011/city011_059.txt", "./sub.city011/city011_060.txt",
		"./sub.city011/city011_061.txt", "./sub.city011/city011_062.txt", "./sub.city011/city011_063.txt",
		"./sub.city011/city011_064.txt", "./sub.city011/city011_065.txt", "./sub.city011/city011_066.txt",
		"./sub.city011/city011_067.txt", "./sub.city011/city011_068.txt", "./sub.city011/city011_069.txt",
		"./sub.city011/city011_070.txt", "./sub.city011/city011_071.txt", "./sub.city011/city011_072.txt",
		"./sub.city011/city011_073.txt", "./sub.city011/city011_074.txt", "./sub.city011/city011_075.txt",
		"./sub.city011/city011_076.txt", "./sub.city011/city011_077.txt", "./sub.city011/city011_078.txt",
		"./sub.city011/city011_079.txt", "./sub.city011/city011_080.txt", "./sub.city011/city011_081.txt",
		"./sub.city011/city011_082.txt", "./sub.city011/city011_083.txt", "./sub.city011/city011_084.txt",
		"./sub.city011/city011_085.txt", "./sub.city011/city011_086.txt", "./sub.city011/city011_087.txt",
		"./sub.city011/city011_088.txt", "./sub.city011/city011_089.txt", "./sub.city011/city011_090.txt",
		"./sub.city011/city011_091.txt", "./sub.city011/city011_092.txt", "./sub.city011/city011_093.txt",
		"./sub.city011/city011_094.txt", "./sub.city011/city011_095.txt", "./sub.city011/city011_096.txt",
		"./sub.city011/city011_097.txt", "./sub.city011/city011_098.txt", "./sub.city011/city011_099.txt",
		"./sub.city011/city011_100.txt"
	};
	city011_file_read(city011, data_915);
	city011_file_processing(city011, data, data_915);
	city011_file_print(city011, data);
	return;
}















