#pragma once

#ifndef __SORTALGORITHM_H__
#define __SORTALGORITHM_H__

#include <vector>
#include <queue>

enum class eSortType
{
	Ascending,
	Descending
};


class CSortAlgorithm_Class
{
public:
	explicit CSortAlgorithm_Class(int num);
	~CSortAlgorithm_Class();


public:
	void Initialize(int num);
	void Release();
public:
	void Menu();
	void MenuText();
	/* Sort 출력 */
	void Show_Array();
	/* BubbleSort 정렬*/
	void Sort_Bubble();
	void Sort_Selection();
	void Sort_Quick();
	void Sort_Merge();
	void Sort_Radix_LSD();

private:
	/* 정렬 조건에 따라 Swap */
	void Swap(int i, int j);
	int SelectNumber();
	void RandomSwap_Array();

private:
	std::vector<int>* vec;
	eSortType		enum_SortType;
	std::queue<int> m_Qrecent;
	bool*			m_iRecent;
	int				m_iSelect = INT_MAX;
};

#endif // !__SORTALGORITHM_H__