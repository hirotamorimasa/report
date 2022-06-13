#include <stdio.h>

#define FRAME 150
#define DATA_SET 100
#define STRING 30       //city0xx_001.txt~city0xx_100.txt

int city021_line(char fname[])                                     
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

void city021_line_processing(char city021[][STRING], int line_data[DATA_SET])
{
        for(int i = 0; i < DATA_SET; i++)
                line_data[i] = city021_line(city021[i]);
}

void city021_File_Line(int line_data[DATA_SET])
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
	city021_line_processing(city021, line_data);
	return;
}

