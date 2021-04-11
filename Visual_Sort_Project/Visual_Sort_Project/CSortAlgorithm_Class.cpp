#include "CSortAlgorithm_Class.h"
#include <iostream>
#include <Windows.h>
#include "Buffer.h"
#include "Enum.h"

CSortAlgorithm_Class::CSortAlgorithm_Class(int num, int* ptr)
	: m_pDelay(ptr)
{
	Initialize(num);
}

CSortAlgorithm_Class::~CSortAlgorithm_Class()
{
	Release();
}

void CSortAlgorithm_Class::Initialize(int num)
{
	Release();
	vec.clear();
	int max = 0;
	m_iSize = num;
	m_iRecent = new bool[num];
	for (int i = 0; i < num; i++)
	{
		vec.push_back(i + 1);
		m_iRecent[i] = false;

		if (max < i + 1)
			max = i + 1;
	}

	while (max > 0)
	{
		max = max / 10;
		m_MaxLength += 1;
	}
	RandomSwap_Array();
}

void CSortAlgorithm_Class::Release()
{
	delete[] m_iRecent;
}



void CSortAlgorithm_Class::Show_Array()
{
	/* 흰색   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);  */ 
	/* 초록색 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);  */ 
	/* 빨간색 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);  */ 
	for (int i = 0; i < (int)(vec.size()); i++)
	{
		for (int g = 0; g < vec[i]; g++)
		{
			drawToBackBuffer(g, i);
		}
	}
	render(m_iRecent, m_iSelect, m_iSize);
	Sleep(*m_pDelay);
}

void CSortAlgorithm_Class::Sort_Bubble()
{
	Clearbuff();
	for (int i = (int)(vec.size()) - 1; i >= 0; --i)
	{
		m_iSelect = i + 1;
		for (int g = 0; g < i; ++g)
		{
			Swap(g, g + 1);
			Recent(2, g);
			Recent(2, g + 1);

			Show_Array();
		}
	}
	Show_Array();
}

void CSortAlgorithm_Class::Sort_Selection()
{
	Clearbuff();
	for (int i = 0; i < (int)(vec.size()) - 1; i++)
	{
		int Min = INT_MAX;
		int MinA = 0;
		int Max = INT_MIN;
		int MaxA = 0;
		m_iSelect = i - 1;
		for (int g = i + 1; g < (int)(vec.size()); g++)
		{
			Recent(2, g);
			if (Min > vec[g])
			{
				MinA = g;
				Min = vec[g];
			}
			else if (Max < vec[g])
			{
				MaxA = g;
				Max = vec[g];
			}
			Show_Array();
		}
		Swap(i, MinA);
		/*if(enum_SortingType == eSortType::Ascending)
		{
			Swap(i, MinA);
		}*/
		/*else
		{
			Swap(i, MaxA);
		}*/
	}
	Show_Array();
}

void CSortAlgorithm_Class::Sort_Quick()
{
	Clearbuff();
	Sort_Quick(vec, 0, ((int)vec.size() - 1));
	Show_Array();
}

void CSortAlgorithm_Class::Sort_Quick(std::vector<int>& arr, int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[(start + end) / 2];
	int l = start;
	int r = end;

	while (l <= r)
	{
		Show_Array();
		while (arr[l] < pivot) ++l;
		while (arr[r] > pivot) --r;

		if (l <= r)
		{
			Recent(10,l);
			Recent(10,r);
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++;
			r--;
		}
	}

	Sort_Quick(arr, start, r);
	Sort_Quick(arr, l, end);
}

void CSortAlgorithm_Class::Sort_Merge()
{
	Clearbuff();
	Sort_Merge(vec, 0, ((int)vec.size() - 1));
}

void CSortAlgorithm_Class::Sort_Merge(std::vector<int>& arr, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		Sort_Merge(arr, left, mid);
		Sort_Merge(arr, mid + 1, right);

		Sort_Merge(arr, left, mid, right);
	}
	Show_Array();
}

void CSortAlgorithm_Class::Sort_Merge(std::vector<int>& arr, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

	int* sortArr = new int[right + 1];
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		++sIdx;
	}

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}
	else
	{
		for (int i = fIdx; i <= mid; i++, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}
	Recent(right - left + 1, mid);

	for (int i = left; i <= right; i++)
	{
		arr[i] = sortArr[i];
	}
	Show_Array();
	delete[] sortArr;
}

void CSortAlgorithm_Class::Sort_Radix_LSD()
{
	Clearbuff();
	std::queue<int> buckets[10]; // 십진수 정렬
	int bi = 0;
	int di = 0;
	int pos = 0;
	int divfac = 1;
	int radix;


	for (int i = 0; i < m_MaxLength; i++)
	{
		for (int j = 0; j < (int)vec.size(); j++)
		{
			radix = (vec[j] / divfac) % 10;

			buckets[radix].push(vec[j]);
		}

		for (int k = 0, di = 0; k < 10; k++)
		{
			Show_Array();
			while (!buckets[k].empty())
			{
				vec[di++] = buckets[k].front();
				Recent(10, buckets[k].front());
				buckets[k].pop();
			}
		}
		divfac *= 10;
	}
	Show_Array();
}

void CSortAlgorithm_Class::Swap( int i, int j)
{
	if (vec[i] > vec[j])
	{
		int temp = vec[i];
		vec[i] = vec[j];
		vec[j] = temp;
	}
}

void CSortAlgorithm_Class::RandomSwap_Array()
{
	int dd = 0;
	int ee = 0;
	int temp = 0;
	for (int i = 0; i < ((int)(vec.size()) * 100); i++)
	{
		dd = rand() % (int)(vec.size());
		ee = rand() % (int)(vec.size());
		if (dd == ee)
			continue;
		temp = vec[dd];
		dd;
		ee;
		vec[dd] = vec[ee];
		vec[ee] = temp;
	}
}

void CSortAlgorithm_Class::Recent(int maxCount, int i)
{
	if (maxCount > 4)
	{
		if(m_Qrecent.size() >= maxCount)
		{
			m_iRecent[m_Qrecent.front()] = false;
			m_Qrecent.pop();
		}
	}
	else
	{
		while (m_Qrecent.size() >= maxCount)
		{
			m_iRecent[m_Qrecent.front()] = false;
			m_Qrecent.pop();
		}
	}
	
	m_iRecent[i] = true;
	m_Qrecent.push(i);
}

void CSortAlgorithm_Class::Recent_Clear()
{
	for (int i = 0; i < m_iSize; i++)
	{
		m_iRecent[i] = false;
	}
}
