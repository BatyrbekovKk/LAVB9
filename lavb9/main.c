#pragma warning(disable : 4996)
#pragma warning(disable :4703)
#include <stdio.h>
#define MAXLINE 1024
#define Location_data "C:\\Users\\����\\source\\repos\\lavb9\\Test.txt"
#define Location_res  "C:\\Users\\����\\source\\repos\\lavb9\\Result.txt"
int main(int argc, char *argv[]) //��������� �������� ������� ���������
{

	int N;
	int cnt_last = 0;
	int flag = 0;//������ ������������
	int cnt_sim = 0; //��������� ����. �����
	int cnt_wo = 0;// ������� ����
	int max_cnt = 0;//����� ���� � ����� ������� ������
	int n_str = 0;//����� ������ � ������� ���������� ����� ����
	int rgt = 0;//����� ������ ������
	char line[MAXLINE];//��������� ������
	char *ptr;//��������� �� ������
	//char prev_ptr = "";
	int c = 0;

	FILE *fpin;//��� ���������� ���������� �� �����
	FILE *fpout;//��� ������ ���������� �� �����
	
	if (Location_data != "")
	{
		fpin = fopen(Location_data, "r"); //�������� ����� ��� ������ 
	}
	else fpin = fopen(argv[1], "r");
	if (fpin == NULL)//���� �� ������� ������� ���� ��� �� ������
	{
		printf("�������� �� �� ����� ����� ����� � �������.\n ��� ����� ������� ����� ������� �������� ��� ������ ����� � ��������� � ������ ���������. \n Location_data - ��������� ���������� ����� ����� � �������. \n Location_res - ��������� ���������� ����� ����� ��� ������ �����. \n ����� ������ ������� ���������: \n Windows: ��������� ������� ��������� ���� exe ������ ������ � ����� ������ � ���� ����������� ������� ���������.\n ������: 9 Laba it.exe Location_data Location_res \n MAC OS: ���������� ������� Cmd � <  �����  ������ ���������� ������� Location_data, ������  Location_res \n");
		return 0;
	}
	if (Location_res != "")
	{
		fpout = fopen(Location_res, "at");//�������� ����� ��� ������
	}
	else fpout = fopen(argv[2], "at");

	if (fpout == NULL)//���� �� ������� ������� ���� ��� �� ������
	{
		printf("�������� �� �� ����� ����� ����� ��� ������.\n ��� ����� ������� ����� ������� �������� ��� ������ ����� � ��������� � ������ ���������. \n Location_data - ��������� ���������� ����� ����� � �������. \n Location_res - ��������� ���������� ����� ����� ��� ������ �����. \n ����� ������ ������� ���������: \n Windows: ��������� ������� ��������� ���� exe ������ ������ � ����� ������ � ���� ����������� ������� ���������.\n ������: 9 Laba it.exe Location_data Location_res \n MAC OS: ���������� ������� Cmd � <  �����  ������ ���������� ������� Location_data, ������  Location_res\n");
		return 0;
	}



    printf("enter N\n");
	scanf("%i\n", &N);

	while (!feof(fpin)) //����� �����
	{
		ptr = fgets(line, MAXLINE, fpin);//?? //���������� ������
		if (ptr == NULL) //���� "���" ������
			break;
		
		//*ptr == '\0' ? (c = *ptr) : (c = c);
		
		while (cnt_sim <= N || *ptr != "\n") // (*ptr != '\n')&&(*(ptr + 1) == '\0') && (*ptr != '\0') || (*ptr!='\0') )
		{
			//*ptr == '\0' ? (c = 1) : (c = 0);

			if (cnt_sim == N)
			{
				fputc(*ptr, fpout);
				fputc('\n', fpout);
			}
			cnt_sim++;

			ptr++;//��������� ������ ������
			
				  /*if ((*ptr == ' ' || *ptr == '.' || *ptr == ',' || *ptr == '\n' || *(ptr+1) == '\0'))//����������� ����� ������� � ��������
			{
				cnt_last = cnt_sim;
				(flag == 0) ? (cnt_wo++) : (cnt_wo = cnt_wo);//��������� �����
				flag = 1;//������������� �����������

				((*ptr != '\n') && (*(ptr + 1) == '\0') && (*ptr != '\0')) ? (cnt_last++) : (cnt_last = cnt_last); // 
			}
			else flag = 0;//���������� �����*/

			

			//prev_ptr = *ptr;
			

			/*if (cnt_sim == N)
				break;
			else cnt_sim++;*/
		}
		cnt_sim = 0 ;
		//fputc(*ptr, fpout);

		fputs(line, fpout);
		//  n_str++;//������� �����
		//printf("\n%i\n%i\n%i\n", cnt_wo, cnt_sim, cnt_last);
		//printf("%s\n", line);
		/*
		if (Location_res != "")
		{
			fpout = fopen(Location_res, "at");//�������� ����� ��� ������
		}
		else fpout = fopen(argv[2], "at");

		if (fpout == NULL)//���� �� ������� ������� ���� ��� �� ������
		{
			printf("�������� �� �� ����� ����� ����� ��� ������.\n ��� ����� ������� ����� ������� �������� ��� ������ ����� � ��������� � ������ ���������. \n Location_data - ��������� ���������� ����� ����� � �������. \n Location_res - ��������� ���������� ����� ����� ��� ������ �����. \n ����� ������ ������� ���������: \n Windows: ��������� ������� ��������� ���� exe ������ ������ � ����� ������ � ���� ����������� ������� ���������.\n ������: 9 Laba it.exe Location_data Location_res \n MAC OS: ���������� ������� Cmd � <  �����  ������ ���������� ������� Location_data, ������  Location_res\n");
			return 0;
		}
		for (int i = 0; i < cnt_last; i++)
		{
			printf("%c", line[i]);
			fprintf(fpout, "%c", line[i]);
		}
		fprintf(fpout, "\n");
		cnt_last = 0;
		cnt_wo = 0;
		cnt_sim = 0;
		*/

		 
	}
	 
	fclose(fpin);
	fclose(fpout);
}


