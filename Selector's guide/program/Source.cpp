##define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;

struct BioManual {
	int num;
	char type[30];
	char name[30];
	char author[50];
	char parents[60];
	char productivity[25];
	char fruit[200];
	char frostResist[25];
	char resist[50];
	int avaibility;
}*arr = NULL;

void Start(const char* path);

void Menu();

void ShowData();

void InputData();

void SortData();

void SubSort(int i, int itmp);

void SearchData();

void ChangeData();

void DeleteData();

void SaveData(const char* path);

int main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	Start("D:\\Univ\\OsnovyP\\pract\\program\\program\\practice.bin");
	Menu();
	return 0;
}

void Start(const char* path)
{
	FILE* f;
	f = fopen(path, "rb");
	if (f == NULL)
	{
		printf("***Попередні записи відсутні***\n"); system("pause");
	}
	else
	{
		fseek(f, 0, SEEK_END);
		size = ftell(f) / sizeof(BioManual);
		rewind(f);
		arr = (BioManual*)malloc(size * sizeof(BioManual));
		fread(arr, sizeof(BioManual), size, f);
		fclose(f);
	}
}

void Menu()
{
	int task = 0;
	do {
		system("cls");
		printf("\t***Меню***\n Введіть, яку дію потрібно виконати:\n 1) Показати записи\n 2) Додати запис\n 3) Сортувати записи\n");
		printf(" 4) Здійснити пошук за параметрами\n 5) Редагувати запис\n 6) Видалити запис\n 7) Зберегти всі зміни\n 8) Завершити (БЕЗ ЗБЕРЕЖЕННЯ)\n"); scanf(" %d", &task);
		switch (task) {
		case 1: ShowData(); break;
		case 2: InputData(); break;
		case 3: SortData(); break;
		case 4: SearchData(); break;
		case 5: ChangeData(); break;
		case 6: DeleteData(); break;
		case 7: SaveData("D:\\Univ\\OsnovyP\\pract\\program\\program\\practice.bin"); break;
		case 8: system("cls"); break;
		default: printf("\t***Неправильно введено, спробуйте ще***\n\n"); system("pause");
		}
	} while (task != 8);
}

void ShowData()
{
	system("cls");
	int countShow = 0, firstNum = 0, secondNum = 0, thirdNum = 0;
	printf("\t***Відобразити все - 1***\n\t***Відобразити за параметрами - 2***\n"); scanf("%d", &countShow);
	switch (countShow)
	{
	case 1: system("cls");
		for (int i = 0; i < size; i++)
		{
			printf_s("------------------------------\n№%2d|\tВид рослини: %s|\tНазва сорту: %s", arr[i].num, arr[i].type, arr[i].name);
			printf_s("\n Автор: %s|\tБатьківські сорти: %s", arr[i].author, arr[i].parents);
			printf_s("\n Врожайність: %s|\tХарактеристики плодів: %s", arr[i].productivity, arr[i].fruit);
			printf_s("\n Морозостійкість: %s|\tСтійкість до шкідників і хвороб: %s", arr[i].frostResist, arr[i].resist);
			printf_s("\n Наявність(кількость): %d\n", arr[i].avaibility);
		} break;
	case 2: system("cls");
		printf("\n\t***Введіть номери потрібних вам параметрів***\n 1) Вид рослини\n 2) Назва сорту\n 3) Автор\n");
		printf(" 4) Батьківські сорти\n 5) Врожайність\n 6) Характеристики плодів\n 7) Морозостійкість\n");
		printf(" 8) Стійкість до шкідників і хвороб\n 9) Наявність(кількость)\n");
		printf("Перший параметр: "); scanf("%d", &firstNum);
		printf("Другий параметр: "); scanf("%d", &secondNum);
		printf("Третій параметр: "); scanf("%d", &thirdNum);
		system("cls");

		for (int i = 0; i < size; i++)
		{
			printf("\n№%2d|\t", arr[i].num);
			if (firstNum == 1 || secondNum == 1 || thirdNum == 1) printf("Вид рослини: %s|\t", arr[i].type);
			if (firstNum == 2 || secondNum == 2 || thirdNum == 2) printf("Назва сорту: %s|\t", arr[i].name);
			if (firstNum == 3 || secondNum == 3 || thirdNum == 3) printf("Автор: %s|\t", arr[i].author);
			if (firstNum == 4 || secondNum == 4 || thirdNum == 4) printf("Батьківські сорти: %s|\t", arr[i].parents);
			if (firstNum == 5 || secondNum == 5 || thirdNum == 5) printf("Врожайність: %s|\t", arr[i].productivity);
			if (firstNum == 6 || secondNum == 6 || thirdNum == 6) printf("Характеристики плодів: %s|\t", arr[i].fruit);
			if (firstNum == 7 || secondNum == 7 || thirdNum == 7) printf("Морозостійкість: %s|\t", arr[i].frostResist);
			if (firstNum == 8 || secondNum == 8 || thirdNum == 8) printf("Стійкість до шкідників і хвороб: %s|\t", arr[i].resist);
			if (firstNum == 9 || secondNum == 9 || thirdNum == 9) printf("Наявність(кількость): %d", arr[i].avaibility);
		} printf("\n");
	} system("pause");
}

void InputData()
{
	int resume;
	do
	{
		system("cls");
		arr = (BioManual*)realloc(arr, (size + 1) * sizeof(BioManual));
		arr[size].num = size + 1;
		gets_s(arr[size].name);
		printf_s("№%d", arr[size].num);
		printf_s(" Вид рослини: "); gets_s(arr[size].type);
		printf_s(" Назва сорту: "); gets_s(arr[size].name);
		printf_s(" Автор: "); gets_s(arr[size].author);
		printf_s(" Батьківські сорти: "); gets_s(arr[size].parents);
		printf_s(" Врожайність: "); gets_s(arr[size].productivity);
		printf_s(" Характеристики плодів: "); gets_s(arr[size].fruit);
		printf_s(" Морозостійкість: "); gets_s(arr[size].frostResist);
		printf_s(" Стійкість до шкідників і хвороб: "); gets_s(arr[size].resist);
		printf_s(" Наявність(кількость): "); scanf("%d", &arr[size].avaibility);
		system("cls");
		printf_s("\t***Для продовження введіть - 1***\n\t***Для завершення - 0***\n"); scanf("%d", &resume);
		size++;
	} while (resume != 0);
}

void SortData()
{
	system("cls");
	int sortTask = 0, sortName = 0, sortType = 0, itmp = 0;
	printf("\t***Для сортування за видом рослини - 1***\n\t***Для сортування за назвою сорту - 2***\n"); scanf("%d", &sortTask);
	switch (sortTask)
	{
	case 1: system("cls");
		printf("\t***Сортування за алфавітом в порядку зростання - 1***\n\t***Сортування за алфавітом в порядку спадання - 2***\n");
		scanf("%d", &sortType);
		switch (sortType)
		{
		case 1: system("cls");
			for (int i = 0; i < size - 1; i++)
			{
				itmp = i;
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(arr[j].type, arr[itmp].type) < 0) itmp = j;
					SubSort(i, itmp);
				}
			} break;
		case 2: system("cls");
			for (int i = 0; i < size - 1; i++)
			{
				itmp = i;
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(arr[j].type, arr[itmp].type) > 0) itmp = j;
					SubSort(i, itmp);
				}
			}
		} break;
	case 2: system("cls");
		printf("\t***Сортування за алфавітом в порядку зростання - 1***\n\t***Сортування за алфавітом в порядку спадання - 2***\n");
		scanf("%d", &sortName);
		switch (sortName)
		{
		case 1: system("cls");
			for (int i = 0; i < size - 1; i++)
			{
				itmp = i;
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(arr[j].name, arr[itmp].name) < 0)  itmp = j;
					SubSort(i, itmp);
				}
			}break;
		case 2: system("cls");
			for (int i = 0; i < size - 1; i++)
			{
				itmp = i;
				for (int j = i + 1; j < size; j++)
				{
					if (strcmp(arr[j].name, arr[itmp].name) > 0) itmp = j;
					SubSort(i, itmp);
				}
			}
		}
	}
}

void SubSort(int i, int itmp)
{
	BioManual a;
	a = arr[i];
	arr[i] = arr[itmp];
	arr[itmp] = a;
	arr[i].num = i + 1;
	arr[itmp].num = itmp + 1;
}

void SearchData()
{
	system("cls");
	char type[30], resist[30], fruit[200];
	int num = 0;
	gets_s(type);
	printf_s("\nВведiть вид рослини: "); gets_s(type);
	printf_s("\nВведiть характеристики плодів: "); gets_s(fruit);
	printf_s("\nВведiть рівень стійкості до шкідників і хвороб: "); gets_s(resist);
	for (int i = 0; i < size; i++)
	{
		if (strstr(type, arr[i].type) && strstr(resist, arr[i].resist) && strstr(fruit, arr[i].fruit))
		{
			printf_s("\n------------------------------------------\n");
			printf_s("\n№%d|\tВид рослини: %s|\tНазва сорту: %s", arr[i].num, arr[i].type, arr[i].name);
			printf_s("\n Автор: %s|\tБатьківські сорти: %s", arr[i].author, arr[i].parents);
			printf_s("\n Врожайність: %s|\tХарактеристики плодів: %s", arr[i].productivity, arr[i].fruit);
			printf_s("\n Морозостійкість: %s|\tСтійкість до шкідників і хвороб: %s", arr[i].frostResist, arr[i].resist);
			printf_s("\n Наявність(кількость): %d\n", arr[i].avaibility); num++;
		}
	} if (num == 0) printf("\n***Збігів не знайдено***\n");
	system("pause");
}

void ChangeData()
{
	int changer = 0;
	system("cls");
	ShowData();
	printf_s("\n\n\t***Введіть номер потрібного для зміни запису***\n"); scanf_s("%d", &changer);
	changer--;
	if (changer > size || changer < 0) {
		printf("\n***Неправильно введено***\n"); system("pause");
	}
	else {
		printf_s("------------\n№%d|\tВид рослини: %s\tНазва сорту: %s", arr[changer].num, arr[changer].type, arr[changer].name);
		printf_s("\n Автор: %s|\tБатьківські сорти: %s", arr[changer].author, arr[changer].parents);
		printf_s("\n Врожайність: %s|\tХарактеристики плодів: %s", arr[changer].productivity, arr[changer].fruit);
		printf_s("\n Морозостійкість: %s|\tСтійкість до шкідників і хвороб: %s", arr[changer].frostResist, arr[changer].resist);
		printf_s("\n Наявність(кількость): %d\n", arr[changer].avaibility);
		printf_s("\n\t***Введіть нові дані****\n");
		printf_s("№%d", arr[changer].num);
		gets_s(arr[size].type);
		printf_s(" Вид рослини: "); gets_s(arr[changer].type);
		printf_s(" Назва сорту: "); gets_s(arr[changer].name);
		printf_s(" Автор: "); gets_s(arr[changer].author);
		printf_s(" Батьківські сорти: "); gets_s(arr[changer].parents);
		printf_s(" Врожайність: "); gets_s(arr[changer].productivity);
		printf_s(" Характеристики плодів: "); gets_s(arr[changer].fruit);
		printf_s(" Морозостійкість: "); gets_s(arr[changer].frostResist);
		printf_s(" Стійкість до шкідників і хвороб: "); gets_s(arr[changer].resist);
		printf_s(" Наявність(кількость): "); scanf_s("%d", &arr[changer].avaibility);
		printf_s("\n\t***Введено нові дані****\n");
		system("pause");
	}
}

void DeleteData()
{
	int deleter = 0, confirm = 0;
	system("cls");
	ShowData();
	printf_s("\n\n\t***Введіть номер потрібного для видалення запису***\n"); scanf("%d", &deleter);
	deleter--;
	if (deleter > size || deleter < 0) {
		printf("\n***Неправильно введено***\n"); system("pause");
	}
	else {
		printf_s("------------\n№%d|\tВид рослини: %s\tНазва сорту: %s", arr[deleter].num, arr[deleter].type, arr[deleter].name);
		printf_s("\n Автор: %s|\tБатьківські сорти: %s", arr[deleter].author, arr[deleter].parents);
		printf_s("\n Врожайність: %s|\tХарактеристики плодів: %s", arr[deleter].productivity, arr[deleter].fruit);
		printf_s("\n Морозостійкість: %s|\tСтійкість до шкідників і хвороб: %s", arr[deleter].frostResist, arr[deleter].resist);
		printf_s("\n Наявність(кількость): %d\n", arr[deleter].avaibility);
		printf_s("\t***Підтвердити - 1***\n\t***Відмінити - 0***\n"); scanf("%d", &confirm);
		if (confirm == 1) {
			for (int i = deleter; i < size - 1; i++)
				arr[i] = arr[i + 1];
			size--; printf_s("\n\t***Видалено***\n"); system("pause");
		}
		else { printf_s("\n\t***Відмінено***\n"); system("pause"); }
	}
}

void SaveData(const char* path)
{
	system("cls");
	FILE* f = fopen(path, "wb");
	for (int i = 0; i < size; i++)
		fwrite(&arr[i], sizeof(BioManual), 1, f);
	fclose(f);
	printf("***Збережено***\n"); system("pause");
}

