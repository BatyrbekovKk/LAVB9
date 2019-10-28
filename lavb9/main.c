#pragma warning(disable : 4996)
#pragma warning(disable :4703)
#include <stdio.h>
#define MAXLINE 1024
#define Location_data "C:\\Users\\Коля\\source\\repos\\lavb9\\Test.txt"
#define Location_res  "C:\\Users\\Коля\\source\\repos\\lavb9\\Result.txt"
int main(int argc, char *argv[]) //программа получает входные аргументы
{

	int N = 0;
	int cnt_last = 0;
	int flag = 0;//повтор разделителей
	int cnt_sim = 0;
	int cnt_wo = 0;// счётчик слов
	int max_cnt = 0;//число слов в самой длинной строке
	int n_str = 0;//номер строки в которой определили число слов
	int rgt = 0;//номер нужной строки
	


	FILE *fpin;//для считывания информации из файла
	FILE *fpout;//для записи информации из файла
	
	char line[MAXLINE];//считанная строка
	char *ptr;//указатель на строку
	char *prev_ptr;
	int c = 0;
	
	if (Location_data != "")
	{
		fpin = fopen(Location_data, "rt"); //открытие файла для чтения
	}
	else fpin = fopen(argv[1], "rt");
	if (fpin == NULL)//если не удалось открыть файл или он пустой
	{
		printf("Возможно Вы не ввели адрес файла с данными.\n Это можно сделать через входные аргменты или задать адрес в константы в начале программы. \n Location_data - константа содержащая адрес файла с данными. \n Location_res - константа содержащая адрес файла для вывода строк. \n Чтобы внести входные аргументы: \n Windows: открываем консоль запускаем файл exe нашего проека и через пробел к нему прописываем входные параметры.\n Пример: 9 Laba it.exe Location_data Location_res \n MAC OS: Комбинация клавишь Cmd и <  затем  первым параметром вводить Location_data, вторым  Location_res \n");
		return 0;
	}
	// printf("Введите N - число символоыв в строке \n");
	N = 12;
	//  scanf("%i\n", &N);
	while (!feof(fpin)) //конец файла
	{
		ptr = fgets(line, MAXLINE, fpin);//?? //считывание строки
		if (ptr == NULL) //если "нет" строки
			break;
		
		//*ptr == '\0' ? (c = *ptr) : (c = c);
		
		while ( ( (prev_ptr != '\n')&&(ptr == '\0')) || (ptr != '\0')) //конец строки
		{
			//*ptr == '\0' ? (c = 1) : (c = 0);

			if ((*ptr == ' ' || *ptr == '.' || *ptr == ',' || *ptr == '\n' || *ptr == '\0'))//разделители между словами и строками
			{
				cnt_last = cnt_sim;
				(flag == 0) ? (cnt_wo++) : (cnt_wo = cnt_wo);//увеличить колво
				//cnt++;//счетчик колва слов
				flag = 1;//повторяющийся разделитель
			}
			else flag = 0;//начинается слово
			prev_ptr = *ptr;
			ptr++;//следующий символ строки
			if (cnt_sim == N)
				break;
			else cnt_sim++;
		}
		//  n_str++;//счетчик строк
		printf("%i\n%i\n%i\n", cnt_wo, cnt_sim, cnt_last);
		printf("%s\n", line);

		if (Location_res != "")
		{
			fpout = fopen(Location_res, "at");//открытие файла для записи
		}
		else fpout = fopen(argv[2], "at");
		if (fpout == NULL)//если не удалось открыть файл или он пустой
		{
			printf("Возможно Вы не ввели адрес файла для вывода.\n Это можно сделать через входные аргменты или задать адрес в константы в начале программы. \n Location_data - константа содержащая адрес файла с данными. \n Location_res - константа содержащая адрес файла для вывода строк. \n Чтобы внести входные аргументы: \n Windows: открываем консоль запускаем файл exe нашего проека и через пробел к нему прописываем входные параметры.\n Пример: 9 Laba it.exe Location_data Location_res \n MAC OS: Комбинация клавишь Cmd и <  затем  первым параметром вводить Location_data, вторым  Location_res\n");
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

		 
	}
	 
	fclose(fpin);
	fclose(fpout);
}


