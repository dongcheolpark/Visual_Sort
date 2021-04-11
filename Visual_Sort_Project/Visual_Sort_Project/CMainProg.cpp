#include "CMainProg.h"
#include "Enum.h"
#include <iostream>
#include "Buffer.h"

bool g_bColorCheck = FALSE;

CMainProg::CMainProg(int num)
	: SortClass(num, &m_iDelay), m_iSize(num), m_iDelay(10)
{
}

CMainProg::~CMainProg()
{
}

void CMainProg::MainMenu()
{
	while (true)
	{
		system("cls");
		MenuText();
		SortClass.RandomSwap_Array();

		switch (SelectNumber())
		{
		case 0:
			g_bColorCheck = !g_bColorCheck;
			break;
		case (int)eSorts::Bubble:
			system("cls");
			SortClass.Sort_Bubble();
			SortClass.Recent_Clear();
			system("pause");
			break;

		case (int)eSorts::Selection:
			system("cls");
			SortClass.Sort_Selection();
			SortClass.Recent_Clear();
			system("pause");
			break;

		case (int)eSorts::Quick:
			system("cls");
			SortClass.Sort_Quick();
			SortClass.Recent_Clear();
			system("pause");
			break;

		case (int)eSorts::Merge:
			system("cls");
			SortClass.Sort_Merge();
			SortClass.Recent_Clear();
			system("pause");
			break;

		case (int)eSorts::Radix_LSD:
			system("cls");
			SortClass.Sort_Radix_LSD();
			SortClass.Recent_Clear();
			system("pause");
			break;

		/*case (int)eSorts::Change_Sort_Option:
			enum_SortType = enum_SortType == eSortType::Ascending ? eSortType::Descending : eSortType::Ascending;
			break;*/

		case (int)eSorts::End:
			return;
		case 9:
		{
			std::cout << "원하는 배열 크기를 입력해주세요 : ";
			int iSizeSelect = SelectNumber();
			m_iSize = iSizeSelect;
			SortClass.Initialize(iSizeSelect);
			break;
		}
		case 10:
		{

			std::cout << "원하는 딜레이를 입력해주세요 (1000 = 1초) : ";
			int iSizeSelect = SelectNumber();
			m_iDelay = iSizeSelect;
			break;
		}
		default:
			continue;
		}
	}
}

void CMainProg::MenuText()
{
	system("cls");
	std::cout << "┌────────────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "        ※ 정렬 프로그램 ※" << std::endl << std::endl;
	std::cout << "	1. Bubble Sort " << std::endl << std::endl;
	std::cout << "	2. Selection Sort " << std::endl << std::endl;
	std::cout << "	3. Quick Sort " << std::endl << std::endl;
	std::cout << "	4. Merge Sort " << std::endl << std::endl;
	std::cout << "	5. Radix LSD Sort " << std::endl << std::endl;
	/*std::cout << "6. 정렬 방식 변경 [현재 : ";

	if (enum_SortType == eSortType::Ascending)
		std::cout << "오름차순 ]" << std::endl;
	else
		std::cout << "내림차순 ]" << std::endl;*/

	std::cout << "	7. 프로그램 종료 " << std::endl << std::endl;
	std::cout << "	9. 배열 크기 변경 [현재 크기 : " << m_iSize << "]" << std::endl << std::endl;
	std::cout << "	10. 연산 딜레이 변경 [현재 딜레이 : " << m_iDelay << "ms]" << std::endl << std::endl;
	if(!g_bColorCheck)
		std::cout << "	0. 색 구분 켜기 (현재 : 꺼짐) " << std::endl << "	[주의 : 색 구분을 켜면 색 변경때문에 속도가 7배 이상 느려진다]" << std::endl << std::endl;
	else
		std::cout << "	0. 색 구분 끄기 (현재 : 켜짐) " << std::endl << "	[주의 : 색 구분을 켜면 색 변경때문에 속도가 7배 이상 느려진다]" << std::endl << std::endl;
	std::cout << "└────────────────────────────────────────────────────────────┘" << std::endl;
}

int CMainProg::SelectNumber()
{
	int iSelect = 0;
	std::cin >> iSelect;
	/*SortClass.enum_SortingType = enum_SortType;*/
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		return 64;
	}
	return iSelect;
}