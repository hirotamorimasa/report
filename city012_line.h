#include <stdio.h>

#define FRAME 150
#define STRING 30       //city0xx_001.txt~city0xx_100.txt
#define DATA_SET 100   //データセット100個分

int city012_line(char fname[])                                     
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

void city012_line_processing(char city012[][STRING], int line_data[DATA_SET])
{
	for(int i = 0; i < DATA_SET; i++)
		line_data[i] = city012_line(city012[i]);
}

void city012_File_Line(int line_data[DATA_SET])
{
        char city012[][STRING] = {
        	"./sub.city012/city012_001.txt", "./sub.city012/city012_002.txt", "./sub.city012/city012_003.txt",
                "./sub.city012/city012_004.txt", "./sub.city012/city012_005.txt", "./sub.city012/city012_006.txt",
                "./sub.city012/city012_007.txt", "./sub.city012/city012_008.txt", "./sub.city012/city012_009.txt",
                "./sub.city012/city012_010.txt", "./sub.city012/city012_011.txt", "./sub.city012/city012_012.txt",
                "./sub.city012/city012_013.txt", "./sub.city012/city012_014.txt", "./sub.city012/city012_015.txt",
                "./sub.city012/city012_016.txt", "./sub.city012/city012_017.txt", "./sub.city012/city012_018.txt",
                "./sub.city012/city012_019.txt", "./sub.city012/city012_020.txt", "./sub.city012/city012_021.txt",
                "./sub.city012/city012_022.txt", "./sub.city012/city012_023.txt", "./sub.city012/city012_024.txt",
                "./sub.city012/city012_025.txt", "./sub.city012/city012_026.txt", "./sub.city012/city012_027.txt",
                "./sub.city012/city012_028.txt", "./sub.city012/city012_029.txt", "./sub.city012/city012_030.txt",
                "./sub.city012/city012_031.txt", "./sub.city012/city012_032.txt", "./sub.city012/city012_033.txt",
                "./sub.city012/city012_034.txt", "./sub.city012/city012_035.txt", "./sub.city012/city012_036.txt",
                "./sub.city012/city012_037.txt", "./sub.city012/city012_038.txt", "./sub.city012/city012_039.txt",
                "./sub.city012/city012_040.txt", "./sub.city012/city012_041.txt", "./sub.city012/city012_042.txt",
                "./sub.city012/city012_043.txt", "./sub.city012/city012_044.txt", "./sub.city012/city012_045.txt",
                "./sub.city012/city012_046.txt", "./sub.city012/city012_047.txt", "./sub.city012/city012_048.txt",
                "./sub.city012/city012_049.txt", "./sub.city012/city012_050.txt", "./sub.city012/city012_051.txt",
                "./sub.city012/city012_052.txt", "./sub.city012/city012_053.txt", "./sub.city012/city012_054.txt",
                "./sub.city012/city012_055.txt", "./sub.city012/city012_056.txt", "./sub.city012/city012_057.txt",
                "./sub.city012/city012_058.txt", "./sub.city012/city012_059.txt", "./sub.city012/city012_060.txt",
                "./sub.city012/city012_061.txt", "./sub.city012/city012_062.txt", "./sub.city012/city012_063.txt",
                "./sub.city012/city012_064.txt", "./sub.city012/city012_065.txt", "./sub.city012/city012_066.txt",
                "./sub.city012/city012_067.txt", "./sub.city012/city012_068.txt", "./sub.city012/city012_069.txt",
                "./sub.city012/city012_070.txt", "./sub.city012/city012_071.txt", "./sub.city012/city012_072.txt",
                "./sub.city012/city012_073.txt", "./sub.city012/city012_074.txt", "./sub.city012/city012_075.txt",
                "./sub.city012/city012_076.txt", "./sub.city012/city012_077.txt", "./sub.city012/city012_078.txt",
                "./sub.city012/city012_079.txt", "./sub.city012/city012_080.txt", "./sub.city012/city012_081.txt",
                "./sub.city012/city012_082.txt", "./sub.city012/city012_083.txt", "./sub.city012/city012_084.txt",
                "./sub.city012/city012_085.txt", "./sub.city012/city012_086.txt", "./sub.city012/city012_087.txt",
                "./sub.city012/city012_088.txt", "./sub.city012/city012_089.txt", "./sub.city012/city012_090.txt",
                "./sub.city012/city012_091.txt", "./sub.city012/city012_092.txt", "./sub.city012/city012_093.txt",
                "./sub.city012/city012_094.txt", "./sub.city012/city012_095.txt", "./sub.city012/city012_096.txt",
                "./sub.city012/city012_097.txt", "./sub.city012/city012_098.txt", "./sub.city012/city012_099.txt",
                "./sub.city012/city012_100.txt"
		 };
	city012_line_processing(city012, line_data);
	return;
}


