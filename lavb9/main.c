#pragma warning(disable : 4996)
#pragma warning(disable :4703)
#include <stdio.h>
#define MAXLINE 1024
#define Location_data "C:\\Users\\����\\source\\repos\\lavb9\\Test.txt"
#define Location_res  "C:\\Users\\����\\source\\repos\\lavb9\\Result.txt"
int main(int argc, char *argv[]) //��������� �������� ������� ���������
{

	int N = 0;
///	int cnt_last = 0;
	int flag = 1;//������ ������������
	int cnt_sim = 0;
	//int cnt_wo = 0;// ������� ����
	//int max_cnt = 0;//����� ���� � ����� ������� ������
	//int n_str = 0;//����� ������ � ������� ���������� ����� ����
	//int rgt = 0;//����� ������ ������
	//int cnt = 0;
	int razd = 0;



	FILE *fpin;//��� ���������� ���������� �� �����
	FILE *fpout;//��� ������ ���������� �� �����

	char line[MAXLINE];//��������� ������
	char *ptr;//��������� �� ������
//	char prev_ptr = "";
	int c = 0;

	printf("Enter N\n"); // ���� N
	scanf("%i\n", &N);

	if (Location_data != "")
	{
		fpin = fopen(Location_data, "rt"); //�������� ����� ��� ������ 
	}
	else fpin = fopen(argv[1], "rt");
	if (fpin == NULL)//���� �� ������� ������� ���� ��� �� ������
	{
		printf("�������� �� �� ����� ����� ����� � �������.\n ��� ����� ������� ����� ������� �������� ��� ������ ����� � ��������� � ������ ���������. \n Location_data - ��������� ���������� ����� ����� � �������. \n Location_res - ��������� ���������� ����� ����� ��� ������ �����. \n ����� ������ ������� ���������: \n Windows: ��������� ������� ��������� ���� exe ������ ������ � ����� ������ � ���� ����������� ������� ���������.\n ������: 9 Laba it.exe Location_data Location_res \n MAC OS: ���������� ������� Cmd � <  �����  ������ ���������� ������� Location_data, ������  Location_res \n");
		return 0;
	}

	if (Location_res != "")
	{
		fpout = fopen(Location_res, "w");//�������� ����� ��� ������
	}
	else fpout = fopen(argv[2], "w");

	if (fpout == NULL)//���� �� ������� ������� ���� ��� �� ������
	{
		printf("�������� �� �� ����� ����� ����� ��� ������.\n ��� ����� ������� ����� ������� �������� ��� ������ ����� � ��������� � ������ ���������. \n Location_data - ��������� ���������� ����� ����� � �������. \n Location_res - ��������� ���������� ����� ����� ��� ������ �����. \n ����� ������ ������� ���������: \n Windows: ��������� ������� ��������� ���� exe ������ ������ � ����� ������ � ���� ����������� ������� ���������.\n ������: 9 Laba it.exe Location_data Location_res \n MAC OS: ���������� ������� Cmd � <  �����  ������ ���������� ������� Location_data, ������  Location_res\n");
		return 0;
	}

	while (!feof(fpin)) //����� �����
	{
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break;

		while (*ptr != "\0") //(*ptr != '\n') && (*(ptr + 1) == '\0') && (*ptr != '\0') || (*ptr != '\0'))
		{
			if (cnt_sim == 0)
			{
				while ((*ptr != ' ') && (*ptr != '\n'))
				{
					cnt_sim++;
					*ptr++;
				}
				if (cnt_sim >= N)
				{
					ptr = line;
					*ptr = '\0';
					cnt_sim = 0;
					break;
				}
				ptr = line;
				cnt_sim = 0;

			}
			cnt_sim++;

			if (*ptr == ' ')
			{
				razd = cnt_sim; //razd - �����������

			}
			if (cnt_sim == N)
			{
				*(ptr + razd - cnt_sim) = '\0';
				cnt_sim = 0;
				fprintf(fpout, "\n");
				break;
			}
			*ptr++;

		}
		fputs(line, fpout);
		cnt_sim = 0;


		/*while (cnt_sim <= N || *ptr != "\n")
		{
			fputc(*ptr, fpout);

			if (cnt_sim == N)
			{
				cnt_sim = 0;
				fputc(*ptr, fpout);
				fputc('\n', fpout);
			}
			cnt_sim++;
			ptr++;
		}*/

		//if ((*ptr == ' ' || *ptr == '.' || *ptr == ',' || *ptr == '\n' || *(ptr + 1) == '\0'))//����������� ����� ������� � ��������
		//{
		//	cnt_last = cnt_sim;
		//	(flag == 0) ? (cnt_wo++) : (cnt_wo = cnt_wo);//��������� �����
		//	//cnt++;//������� ����� ����
		//	flag = 1;//������������� �����������

		//	((*ptr != '\n') && (*(ptr + 1) == '\0') && (*ptr != '\0')) ? (cnt_last++) : (cnt_last = cnt_last);
		//}
		//else flag = 0;//���������� �����

		//prev_ptr = *ptr;
		//ptr++;//��������� ������ ������
		//if (cnt_sim == N)
		//	break;
		//else cnt_sim++;

	}
	//fputs(line, fpout); // ������ ������

	//  n_str++;//������� �����
	/*printf("%i\n%i\n%i\n", cnt_wo, cnt_sim, cnt_last);
	printf("%s\n", line);*/


	/*for (int i = 0; i < cnt_last; i++)
	{
		printf("%c", line[i]);
		fprintf(fpout, "%c", line[i]);
	}*/

	/*fprintf(fpout, "\n");
	cnt_last = 0;
	cnt_wo = 0;
	cnt_sim = 0;*/




	fprintf(fpout, "\n\nN = %d", N);
	fclose(fpin);
	fclose(fpout);
}


