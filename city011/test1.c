#include <stdio.h>

#define FRAME 64
#define DIMENSION 15

double Squre(int x, int count)
{
	double squre = 1.0;
	double trans;
	trans = (double)x;

	for(int i = 1; i < count; i++)
		squre *= 10.0;
	return(trans * squre);
}

double Float_Squre(int x, int count)
{
	double squre = 1.0;
	double trans;
	trans = (double)x;

	for(int i = 0; i < count; i++)
		squre /= 10.0;
	return (trans * squre);
}

double Trans(int str[100], int count)
{
	double total = 0.0;

	for(int i = 0; i < count; i++)
		total += Squre(str[i], count - 1);
	return total;
}

double Float_Trans(int str[100], int count)
{
	int i = 0, point = 0;
	double total = 0.0;
	for(i; i < count; i++)
	{
		if(str[i] == 46)
		{
			point = i;
			break;
		}
	}
	//整数部
	for(int j = 0; j < point; j++)
	{
		total += Squre(str[j], point - j);
	}
	point++;
	
	//少数部
	for(int j = 0; j < count - i; j++)
	{
		total += Float_Squre(str[point++], j+1);
	}
	return total;
}

void file_input(int str[100], double data[FRAME][DIMENSION])
{
	int ch;
	FILE *fp;
	int i = 0, count = 0;	//カウントする変数
	char fname[] = "test.txt";
	int frame = 0, dimension = 0;
	 
	//ファイルの文字を１文字ずつ読み込みながら数値化する.
		fp = fopen(fname, "r");
		if(fp == NULL)
			printf("%s file don't open.\n", fname);
		else
		{
			while((ch = fgetc(fp)) != EOF)
			{
				str[i++] = ch;
			}
		}
		fclose(fp);
		for(int j = 0; str[j] != 0; j++)
			printf("%3d\t", str[j]);
		putchar('\n');
		return;
}

int main(void)
{
	int str[100];
	double data[FRAME][DIMENSION];
	file_input(str, data);

	return 0;
}


