#pragma warning(disable : 4996)
#include <stdio.h>
#define MAXLINE 1024
#define YES 1
#define NO 0

int main(void)
{
	// указатели на структуру типа FILE для
	// входной и выходного файлов
	FILE *fpin;
	FILE *fpout;

	char line[MAXLINE]; // текущая строка
	char *ptr;
	char *in_ptr;

	int cnt = 0;

	// открыть файл для чтения
	fpin = fopen("test\\test.txt", "w");
	if (fpin == NULL)

		return; // ошибка при открытии файла
	   // открыть файл для записи
	fpout = fopen("test\\result.txt", "wt");
	if (fpout == NULL)

		return; // ошибка при открытии файла
	fprintf(fpin, "Скопировать содержимое текстового файла, ограничив длину строки N символами.Слова, не помещающиеся в строку заданной длины, не копировать.");



	int N = 0;
	flag = 0;
	scanf();


	while (!feof(fpin))// цикл до конца файла
	{
		// чтение строки
		ptr = fgets(line, MAXLINE, fpin);
		if (ptr == NULL)
			break; // файл исчерпан
		while (*ptr != '\0') // цикл до конца строки
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
		fputs(line, fpout); // запись строки
	}
	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл

	return 0;
}