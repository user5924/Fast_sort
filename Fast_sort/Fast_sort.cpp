// Fast_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

char cmp_int(int arg1, int arg2)
{
	if (arg1 > arg2)
		return 1;
	if (arg1 < arg2)
		return -1;
	return 0;
}

template <typename X>
class Sorting
{
public:
	
	char compare(float arg1, float arg2)
	{
		if (arg1 > arg2)
			return 1;
		if (arg1 < arg2)
			return -1;
		return 0;
	}

	char compare(char * arg1, char * arg2)
	{
		return strcmp(arg1, arg2);
	}

	void fast_sort(X* data, int st, int fn, char compare(X, X))
	{
		int mid = partition(data, st, fn, compare);
		int max = mid - 1;
		int min = mid + 1;

		if (max > st)
			fast_sort(data, st, max, compare);

		if (min < fn)
			fast_sort(data, min, fn, compare);
	}

	void see_data(X* data, int st, int fn)
	{
		for (int i = st; i <= fn; i += 1)
			cout << data[i] << "   ";
	}
private:

	int partition(X *data, int st, int fn, char compare(X ,X))
	{
		int mid = (st + fn) / 2;
		swap(data[mid], data[fn]);
		int i1 = st, i2;
		i2 = fn - 1;

		while (i1 <= i2)
		{
			if (compare(data[i1], data[fn]) < 0)
				i1 += 1;
			else if (compare(data[i2], data[fn]) >= 0)
				i2 -= 1;
			else
			{
				swap(data[i1], data[i2]);
				i1 += 1;
				i2 -= 1;
			}
		}

		i2 += 1;
		swap(data[i2], data[fn]);
		return i2;
	}

};


int main()
{
	Sorting<int> test;
	srand(time(NULL));
	int size = 600;
	int max = size - 1;
	int min = 0;
	int* arr;
	arr = new int[size];

	for (int i = 0; i < size; i += 1)
		arr[i] = rand() % 100;

	test.fast_sort(arr, min, max, cmp_int);
	test.see_data(arr, min, max);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
