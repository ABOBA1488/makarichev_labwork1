#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
const int N = 10000;
using namespace std::chrono;
std::vector <int> array(N);
std::vector <int> additional(N);
int CounterForQuick = 0;
void FillArr();
void BubbleSort();
void QuickSort(int size);
void GnomSort();
int main() 
{
	std::ofstream fout("result.txt");
	FillArr();

	std::copy(array.begin(), array.end(), additional.begin());
	auto begin = steady_clock::now();
	GnomSort();
	auto end = steady_clock::now();
	std::cout << "Time for BubleSort - "<< duration_cast<nanoseconds>(end - begin).count() << std::endl;

	std::copy(additional.begin(), additional.end(), array.begin());
	begin = steady_clock::now();
	BubbleSort();
	end = steady_clock::now();
	std::cout << "Time for GnomSort - " << duration_cast<nanoseconds>(end - begin).count() << std::endl;

	std::copy(additional.begin(), additional.end(), array.begin());
	begin = steady_clock::now();
	QuickSort(array.size());
	end = steady_clock::now();
	std::cout << "Count for Quick Movement  - " << CounterForQuick << std::endl;
	std::cout << "Time for QuickSort - " << duration_cast<nanoseconds>(end - begin).count() << std::endl; 

	for (int i = 0; i < N; i++)
	{
		fout << array[i] << std::endl;
	}
}

void FillArr()
{
	std::ifstream fin("for_sort.txt");
	for (int i = 0; i < N; i++)
	{
		fin >> array[i];
	}
}

void BubbleSort()
{
	int CounterForBubble = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				CounterForBubble++;
			}
		}
	}
	std::cout << "Count for Bubble Movement  - " << CounterForBubble << std::endl;
}

void QuickSort(int size)
{
	//��������� � ������ � � ����� �������
	int i = 0;
	int j = size - 1;

	//����������� ������� �������
	int mid = array[size / 2];

	//����� ������
	do {
		//��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
		//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (array[i] < mid) {
			i++;
		}
		//� ������ ����� ���������� ��������, ������� ������ ������������
		while (array[j] > mid) {
			j--;
		}

		//������ �������� �������
		if (i <= j) {
			int tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			CounterForQuick++;
			i++;
			j--;
		}
	} while (i <= j);

	//����������� ������, ���� ��������, ��� �����������
	if (j > 0) {
		//"����� �����"
		QuickSort( j + 1);
	}
	if (i < size) {
		//"����� �����"
		QuickSort(size - i);
	}
	
	
}

void GnomSort()
{
	int CounterForGnom = 0;
	for (int i = 0; i < N-1;) 
	{
		if (array[i + 1] < array[i] )
		{
			std::swap(array[i + 1], array[i]);
			CounterForGnom++;
			if (i != 0)
			{
				i--;
			}
		}
		else { i++; }
	}
	std::cout << "Count for Gnom Movement  - " << CounterForGnom << std::endl;
	
}
