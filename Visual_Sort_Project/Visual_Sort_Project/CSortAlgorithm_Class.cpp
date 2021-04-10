#include "CSortAlgorithm_Class.h"
#include <iostream>
#include <Windows.h>

CSortAlgorithm_Class::CSortAlgorithm_Class(int num)
{
	Initialize(num);
}

CSortAlgorithm_Class::~CSortAlgorithm_Class()
{
	Release();
}

void CSortAlgorithm_Class::Initialize(int num)
{
	vec = new std::vector<int>;
	m_iRecent = new bool[num];
	for (int i = 0; i < num; i++)
	{
		vec->push_back(i + 1);
		m_iRecent[i] = false;
	}
	RandomSwap_Array();
}

void CSortAlgorithm_Class::Release()
{
	delete[] m_iRecent;
	delete vec;
}

void CSortAlgorithm_Class::Menu()
{
	while (true)
	{
		MenuText();
		switch (SelectNumber())
		{
		case 1:
			Sort_Bubble();
			system("pause");
			break;
		case 2:
			Sort_Selection();
			system("pause");
		case 5:
			enum_SortType = enum_SortType == eSortType::Ascending ? eSortType::Descending : eSortType::Ascending;
			break;
		case 6:
			return;
		default:
			std::cin.clear();
			continue;
		}
	}
	
}

void CSortAlgorithm_Class::MenuText()
{
	system("cls");
	std::cout << "        ※ 정렬 프로그램 ※" << std::endl;
	std::cout << "1. Bubble Sort " << std::endl;

	std::cout << "2. Selection Sort " << std::endl;

	std::cout << "3. 없어 Sort " << std::endl;

	std::cout << "4. 없어 Sort " << std::endl;

	std::cout << "4. 없어 Sort " << std::endl;

	std::cout << "5. 정렬 방식 변경 [현재 : ";
	if (enum_SortType == eSortType::Ascending)
		std::cout << "오름차순 ]" << std::endl;
	else
		std::cout << "내림차순 ]" << std::endl;

	std::cout << "6. 프로그램 종료 " << std::endl;
}


void CSortAlgorithm_Class::Show_Array()
{
	system("cls");
	/* 흰색   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);  */ 
	/* 초록색 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);  */ 
	/* 빨간색 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);  */ 
	for (int i = 0; i < (vec->size()); i++)
	{
		if (i == m_iSelect)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		}
		else if (m_iRecent[i])
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		for (int g = 0; g < (*vec)[i]; g++)
		{
			std::cout << "■";
		}
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(10);
}

void CSortAlgorithm_Class::Sort_Bubble()
{
	for (int i = (vec->size()) - 1; i >= 0; --i)
	{
		for (int g = 0; g < i; ++g)
		{
			Swap(g, g + 1);
			if (!m_Qrecent.empty())
			{
				m_iRecent[m_Qrecent.front()] = false;
				m_Qrecent.pop();
				m_iRecent[m_Qrecent.front()] = false;
				m_Qrecent.pop();
			}
			m_iRecent[g] = true;
			m_iRecent[g + 1] = true;
			m_Qrecent.push(g);
			m_Qrecent.push(g + 1);

			Show_Array();
		}
	}
}

void CSortAlgorithm_Class::Sort_Selection()
{
	for (int i = 0; i < (vec->size()) - 1; i++)
	{
		int Min = INT_MAX;
		int MinA = 0;
		int Max = INT_MIN;
		int MaxA = 0;
		m_iSelect = i - 1;
		for (int g = i + 1; g < (vec->size()); g++)
		{
			if (!m_Qrecent.empty())
			{
				m_iRecent[m_Qrecent.front()] = false;
				m_Qrecent.pop();
			}
			m_iRecent[g] = true;
			m_Qrecent.push(g);
			if (enum_SortType == eSortType::Ascending && Min > (*vec)[g])
			{
				MinA = g;
				Min = (*vec)[g];
			}
			else if (enum_SortType == eSortType::Descending && Max < (*vec)[g])
			{
				MaxA = g;
				Max = (*vec)[g];
			}
			Show_Array();
		}
		if(enum_SortType == eSortType::Ascending)
		{
			Swap(i, MinA);
		}
		else
		{
			Swap(i, MaxA);
		}
	}
}

void CSortAlgorithm_Class::Sort_Quick()
{
}

void CSortAlgorithm_Class::Sort_Merge()
{
}

void CSortAlgorithm_Class::Sort_Radix_LSD()
{
}

void CSortAlgorithm_Class::Swap( int i, int j)
{
	if (enum_SortType == eSortType::Ascending)
	{
		if ((*vec)[i] > (*vec)[j])
		{
			int temp = (*vec)[i];
			(*vec)[i] = (*vec)[j];
			(*vec)[j] = temp;
		}
	}
	else if(enum_SortType == eSortType::Descending)
	{
		if ((*vec)[i] < (*vec)[j])
		{
			int temp = (*vec)[i];
			(*vec)[i] = (*vec)[j];
			(*vec)[j] = temp;
		}
	}
}

int CSortAlgorithm_Class::SelectNumber()
{
	int iSelect = 0;
	std::cin >> iSelect;
	return iSelect;
}

void CSortAlgorithm_Class::RandomSwap_Array()
{
	int a;
	int b;
	int temp;
	for (int i = 0; i < (vec->size()) * 100; i++)
	{
		a = rand() % (vec->size());
		b = rand() % (vec->size());
		if (a == b)
			continue;
		std::cout << "a : " << a << ", b : " << b << std::endl;
		temp = (*vec)[a];
		(*vec)[a] = (*vec)[b];
		(*vec)[b] = temp;
	}
}
