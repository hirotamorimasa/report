#include <stdio.h>

#define FRAME 150
#define DATA_SET 100
#define STRING 30

int city011_line(char fname[])
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

void city011_line_processing(char city011[][STRING], int line_data[DATA_SET])
{
	for(int i = 0; i < DATA_SET; i++)
		line_data[i] = city011_line(city011[i]);
}

void city011_File_Line(int line_data[DATA_SET])
{
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
	city011_line_processing(city011, line_data);
	return;
}

