#include <stdio.h>
#include <stdlib.h>

#define FRAME 80
#define DIMENSION 15
#define STRING 30       //city0xx_001.txt~city0xx_100.txt
#define NUMBER 1500      //city011_001.txt~city011_100.txt
#define DATA_SET 100   //データセット100個分

int city021_file_line(char fname[])                                     
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

void city021_file_print(char city021[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = city021_file_line(city021[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void city021_file_read(char city021[][STRING], double data[DATA_SET][NUMBER])
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
		line = city021_file_line(city021[i]);
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
void city021_file_processing(char city021[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = city021_file_line(city021[i]);
		for(int j = 0; j < line; j++)
		{
			for(int k = 0; k < DIMENSION; k++)
				data[i][j][k] = data915[i][count++];
		}
	count = 0;
	}
}

void city021_main(double city021_data[DATA_SET][FRAME][DIMENSION], double city021_data1300[DATA_SET][NUMBER])
{
	char city021[][STRING] = {
                "./sub.city021/city021_001.txt", "./sub.city021/city021_002.txt", "./sub.city021/city021_003.txt",
                "./sub.city021/city021_004.txt", "./sub.city021/city021_005.txt", "./sub.city021/city021_006.txt",
                "./sub.city021/city021_007.txt", "./sub.city021/city021_008.txt", "./sub.city021/city021_009.txt",
                "./sub.city021/city021_010.txt", "./sub.city021/city021_011.txt", "./sub.city021/city021_012.txt",
                "./sub.city021/city021_013.txt", "./sub.city021/city021_014.txt", "./sub.city021/city021_015.txt",
                "./sub.city021/city021_016.txt", "./sub.city021/city021_017.txt", "./sub.city021/city021_018.txt",
                "./sub.city021/city021_019.txt", "./sub.city021/city021_020.txt", "./sub.city021/city021_021.txt",
                "./sub.city021/city021_022.txt", "./sub.city021/city021_023.txt", "./sub.city021/city021_024.txt",
                "./sub.city021/city021_025.txt", "./sub.city021/city021_026.txt", "./sub.city021/city021_027.txt",
                "./sub.city021/city021_028.txt", "./sub.city021/city021_029.txt", "./sub.city021/city021_030.txt",
                "./sub.city021/city021_031.txt", "./sub.city021/city021_032.txt", "./sub.city021/city021_033.txt",
                "./sub.city021/city021_034.txt", "./sub.city021/city021_035.txt", "./sub.city021/city021_036.txt",
                "./sub.city021/city021_037.txt", "./sub.city021/city021_038.txt", "./sub.city021/city021_039.txt",
                "./sub.city021/city021_040.txt", "./sub.city021/city021_041.txt", "./sub.city021/city021_042.txt",
                "./sub.city021/city021_043.txt", "./sub.city021/city021_044.txt", "./sub.city021/city021_045.txt",
                "./sub.city021/city021_046.txt", "./sub.city021/city021_047.txt", "./sub.city021/city021_048.txt",
                "./sub.city021/city021_049.txt", "./sub.city021/city021_050.txt", "./sub.city021/city021_051.txt",
                "./sub.city021/city021_052.txt", "./sub.city021/city021_053.txt", "./sub.city021/city021_054.txt",
                "./sub.city021/city021_055.txt", "./sub.city021/city021_056.txt", "./sub.city021/city021_057.txt",
                "./sub.city021/city021_058.txt", "./sub.city021/city021_059.txt", "./sub.city021/city021_060.txt",
                "./sub.city021/city021_061.txt", "./sub.city021/city021_062.txt", "./sub.city021/city021_063.txt",
                "./sub.city021/city021_064.txt", "./sub.city021/city021_065.txt", "./sub.city021/city021_066.txt",
                "./sub.city021/city021_067.txt", "./sub.city021/city021_068.txt", "./sub.city021/city021_069.txt",
                "./sub.city021/city021_070.txt", "./sub.city021/city021_071.txt", "./sub.city021/city021_072.txt",
                "./sub.city021/city021_073.txt", "./sub.city021/city021_074.txt", "./sub.city021/city021_075.txt",
                "./sub.city021/city021_076.txt", "./sub.city021/city021_077.txt", "./sub.city021/city021_078.txt",
                "./sub.city021/city021_079.txt", "./sub.city021/city021_080.txt", "./sub.city021/city021_081.txt",
                "./sub.city021/city021_082.txt", "./sub.city021/city021_083.txt", "./sub.city021/city021_084.txt",
                "./sub.city021/city021_085.txt", "./sub.city021/city021_086.txt", "./sub.city021/city021_087.txt",
                "./sub.city021/city021_088.txt", "./sub.city021/city021_089.txt", "./sub.city021/city021_090.txt",
                "./sub.city021/city021_091.txt", "./sub.city021/city021_092.txt", "./sub.city021/city021_093.txt",
                "./sub.city021/city021_094.txt", "./sub.city021/city021_095.txt", "./sub.city021/city021_096.txt",
                "./sub.city021/city021_097.txt", "./sub.city021/city021_098.txt", "./sub.city021/city021_099.txt",
                "./sub.city021/city021_100.txt"
                 };

	city021_file_read(city021, city021_data1300);
	city021_file_processing(city021, city021_data, city021_data1300);
	city021_file_print(city021, city021_data);
	return;
}















