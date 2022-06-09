#include <stdio.h>
#include <stdlib.h>

#define FRAME 64
#define DIMENSION 15
#define F 4	//city011~city014
#define NUMBER 100	//city011_001.txt~city011_100.txt


void data_file1(double fname[F][NUMBER])
{
	fname[0][] = {
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
}

void data_file2(double fname[NUMBER])
{
	fname[1][] = {
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
}


void data_file3(double fname[NUMBER])
{
	fname[2][] = {
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
}

void data_file4(double fname[NUMBER])
{
	fname[3][] = {
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
}


void file_input(double data[NUMBER])
	FILE *fp;
	
	fp = fopen(fname, "r");
	if(fp = NULL)
		printf("%s file don't open.\n", fname);
	while((ch = fgetc(fp)) != EOF)
	{

	}
}

int main(void)
{
	double data100[F][NUMBER];
	double data[FRAME][DIMENSION];
	
	data_file1(data100);
	data_file2(data100);
	data_file3(data100);
	data_file4(data100);

	return 0;
}















