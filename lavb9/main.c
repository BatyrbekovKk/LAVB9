#pragma warning(disable : 4996)
#include <stdio.h>
#define MAXLINE 1024
#define YES 1
#define NO 0

int main(void)
{
	// ��������� �� ��������� ���� FILE ���
	// ������� � ��������� ������
	FILE *fpin;
	FILE *fpout;

	char line[MAXLINE]; // ������� ������
	char *ptr;
	char *in_ptr;

	int cnt = 0;

	// ������� ���� ��� ������
	fpin = fopen("test\\test.txt", "w");
	if (fpin == NULL)

		return; // ������ ��� �������� �����
	   // ������� ���� ��� ������
	fpout = fopen("test\\result.txt", "wt");
	if (fpout == NULL)

		return; // ������ ��� �������� �����
	fprintf(fpin, "����������� ���������� ���������� �����, ��������� ����� ������ N ���������.�����, �� ������������ � ������ �������� �����, �� ����������.");



	int N = 0;
	flag = 0;
	scanf();


	while (!feof(fpin))// ���� �� ����� �����
	{
		// ������ ������
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break; // ���� ��������
		while (*ptr != '\0') // ���� �� ����� ������
		{
			



			if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0' || c == '?' || c == '!' || c == ';' || c == ':' ||
				c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"')
			{
				cnt = 0;
				*ptr++ = *in_ptr++;
				flag = 1;

			}
			else
			{

				if (flag == NO)
				{
					flag = YES;
					ptr = in_ptr;
				}
				cnt++;
			}








		}
		fputs(line, fpout); // ������ ������
	}
	fclose(fpin); // ������� ������� ����
	fclose(fpout); // ������� �������� ����

	return 0;
}