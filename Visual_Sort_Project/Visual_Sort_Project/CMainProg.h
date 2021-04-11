#pragma once

#ifndef __MAINPROG_H__
#define __MAINPROG_H__
#include "CSortAlgorithm_Class.h"
#include "Enum.h"
class CMainProg
{
public:
	CMainProg(int num);
	~CMainProg();

public:
	void MainMenu();
	void MenuText();


private:
	int SelectNumber();


private:
	int	m_iSize;
	int m_iDelay;
	CSortAlgorithm_Class SortClass;
};

#endif // !__MAINPROG_H__