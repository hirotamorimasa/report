#define FRAME 80
#define DIMENSION 15
#define STRING 30       //city0xx_001.txt~city0xx_100.txt
#define NUMBER 916      //city011_001.txt~city011_100.txt
#define DATA_SET 100   //データセット100個分

int city022_file_line(char fname[])                                     
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

void city022_file_print(char city022[][STRING], double data[DATA_SET][FRAME][DIMENSION])
{
	int line;
	for(int i = 0; i < DATA_SET; i++){
		line = city022_file_line(city022[i]);
		for(int j = 0; j < line; j++)
			for(int k = 0; k < DIMENSION; k++)
				printf("data[%d][%d][%d]:%lf\n", i+1, j+1, k+1, data[i][j][k]);
		printf("\n\n");
	}
}

//一次元配列でデータを読み込む
void city022_file_read(char city022[][STRING], double data[DATA_SET][NUMBER])
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
		line = city022_file_line(city022[i]);
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
void city022_file_processing(char city022[][STRING], double data[DATA_SET][FRAME][DIMENSION], double data915[DATA_SET][NUMBER])
{
	int count = 0;
	int line;
	for(int i = 0; i < DATA_SET; i++)
	{
		line = city022_file_line(city022[i]);
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
                "./sub.city022/city022_001.txt", "./sub.city022/city022_002.txt", "./sub.city022/city022_003.txt",
                "./sub.city022/city022_004.txt", "./sub.city022/city022_005.txt", "./sub.city022/city022_006.txt",
                "./sub.city022/city022_007.txt", "./sub.city022/city022_008.txt", "./sub.city022/city022_009.txt",
                "./sub.city022/city022_010.txt", "./sub.city022/city022_011.txt", "./sub.city022/city022_012.txt",
                "./sub.city022/city022_013.txt", "./sub.city022/city022_014.txt", "./sub.city022/city022_015.txt",
                "./sub.city022/city022_016.txt", "./sub.city022/city022_017.txt", "./sub.city022/city022_018.txt",
                "./sub.city022/city022_019.txt", "./sub.city022/city022_020.txt", "./sub.city022/city022_021.txt",
                "./sub.city022/city022_022.txt", "./sub.city022/city022_023.txt", "./sub.city022/city022_024.txt",
                "./sub.city022/city022_025.txt", "./sub.city022/city022_026.txt", "./sub.city022/city022_027.txt",
                "./sub.city022/city022_028.txt", "./sub.city022/city022_029.txt", "./sub.city022/city022_030.txt",
                "./sub.city022/city022_031.txt", "./sub.city022/city022_032.txt", "./sub.city022/city022_033.txt",
                "./sub.city022/city022_034.txt", "./sub.city022/city022_035.txt", "./sub.city022/city022_036.txt",
                "./sub.city022/city022_037.txt", "./sub.city022/city022_038.txt", "./sub.city022/city022_039.txt",
                "./sub.city022/city022_040.txt", "./sub.city022/city022_041.txt", "./sub.city022/city022_042.txt",
                "./sub.city022/city022_043.txt", "./sub.city022/city022_044.txt", "./sub.city022/city022_045.txt",
                "./sub.city022/city022_046.txt", "./sub.city022/city022_047.txt", "./sub.city022/city022_048.txt",
                "./sub.city022/city022_049.txt", "./sub.city022/city022_050.txt", "./sub.city022/city022_051.txt",
                "./sub.city022/city022_052.txt", "./sub.city022/city022_053.txt", "./sub.city022/city022_054.txt",
                "./sub.city022/city022_055.txt", "./sub.city022/city022_056.txt", "./sub.city022/city022_057.txt",
                "./sub.city022/city022_058.txt", "./sub.city022/city022_059.txt", "./sub.city022/city022_060.txt",
                "./sub.city022/city022_061.txt", "./sub.city022/city022_062.txt", "./sub.city022/city022_063.txt",
                "./sub.city022/city022_064.txt", "./sub.city022/city022_065.txt", "./sub.city022/city022_066.txt",
                "./sub.city022/city022_067.txt", "./sub.city022/city022_068.txt", "./sub.city022/city022_069.txt",
                "./sub.city022/city022_070.txt", "./sub.city022/city022_071.txt", "./sub.city022/city022_072.txt",
                "./sub.city022/city022_073.txt", "./sub.city022/city022_074.txt", "./sub.city022/city022_075.txt",
                "./sub.city022/city022_076.txt", "./sub.city022/city022_077.txt", "./sub.city022/city022_078.txt",
                "./sub.city022/city022_079.txt", "./sub.city022/city022_080.txt", "./sub.city022/city022_081.txt",
                "./sub.city022/city022_082.txt", "./sub.city022/city022_083.txt", "./sub.city022/city022_084.txt",
                "./sub.city022/city022_085.txt", "./sub.city022/city022_086.txt", "./sub.city022/city022_087.txt",
                "./sub.city022/city022_088.txt", "./sub.city022/city022_089.txt", "./sub.city022/city022_090.txt",
                "./sub.city022/city022_091.txt", "./sub.city022/city022_092.txt", "./sub.city022/city022_093.txt",
                "./sub.city022/city022_094.txt", "./sub.city022/city022_095.txt", "./sub.city022/city022_096.txt",
                "./sub.city022/city022_097.txt", "./sub.city022/city022_098.txt", "./sub.city022/city022_099.txt",
                "./sub.city022/city022_100.txt"                            
		};
	city022_file_read(city022, data_915);
	city022_file_processing(city022, data, data_915);
	city022_file_print(city022, data);
	return;
}















