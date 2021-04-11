#pragma once

#ifndef __SORTALGORITHM_H__
#define __SORTALGORITHM_H__

#include <vector>
#include <queue>
#include "Enum.h"

class CSortAlgorithm_Class
{
	friend class CMainProg;
public:
	explicit CSortAlgorithm_Class(int num);
	~CSortAlgorithm_Class();


public:
	void Initialize(int num);
	void Release();
public:
	/* Sort 출력 */
	void Show_Array();
	/* BubbleSort 정렬*/
	void Sort_Bubble();
	void Sort_Selection();
	void Sort_Quick();
	void Sort_Quick(std::vector<int>& arr, int start, int end);
	void Sort_Merge();
	void Sort_Merge(std::vector<int>& arr, int left, int right);
	void Sort_Merge(std::vector<int>& arr, int left, int mid, int right);
	void Sort_Radix_LSD();

private:
	/* 정렬 조건에 따라 Swap */
	void Swap(int i, int j);
	void RandomSwap_Array();

private:
	std::vector<int>* vec;
	std::queue<int> m_Qrecent;
	bool*			m_iRecent;
	int				m_iSelect = INT_MAX;
	int				m_MaxLength = 0;
};

#endif // !__SORTALGORITHM_H__