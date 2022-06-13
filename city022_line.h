#include <stdio.h>

#define FRAME 150
#define STRING 30       //city0xx_001.txt~city0xx_100.txt
#define DATA_SET 100   //データセット100個分

int city022_line(char fname[]) 
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

void city022_line_processing(char city022[][STRING], int line_data[DATA_SET])
{
	for(int i = 0; i < DATA_SET; i++)
		line_data[i] = city022_line(city022[i]);
}

void city022_File_Line(int line_data[DATA_SET])
{
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
	city022_line_processing(city022, line_data);
	return;
}


