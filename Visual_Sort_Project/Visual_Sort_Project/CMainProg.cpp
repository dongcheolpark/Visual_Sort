#include "CMainProg.h"
#include "Enum.h"
#include <iostream>
#include "Buffer.h"

CMainProg::CMainProg(int num)
	: SortClass(num), m_iSize(num)
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
		case (int)eSorts::Bubble:
			system("cls");
			SortClass.Sort_Bubble();
			system("pause");
			break;

		case (int)eSorts::Selection:
			system("cls");
			SortClass.Sort_Selection();
			system("pause");
			break;

		case (int)eSorts::Quick:
			system("cls");
			SortClass.Sort_Quick();
			system("pause");
			break;

		case (int)eSorts::Merge:
			system("cls");
			SortClass.Sort_Merge();
			system("pause");
			break;

		case (int)eSorts::Radix_LSD:
			system("cls");
			SortClass.Sort_Radix_LSD();
			system("pause");
			break;

		/*case (int)eSorts::Change_Sort_Option:
			enum_SortType = enum_SortType == eSortType::Ascending ? eSortType::Descending : eSortType::Ascending;
			break;*/

		case (int)eSorts::End:
			return;
		case 9:
		{
			std::cout << "���ϴ� �迭 ũ�⸦ �Է����ּ��� : ";
			int iSizeSelect = SelectNumber();
			m_iSize = iSizeSelect;
			SortClass.Initialize(iSizeSelect);
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
	std::cout << "����������������������������������������������������������������������" << std::endl;
	std::cout << "        �� ���� ���α׷� ��" << std::endl << std::endl;
	std::cout << "	1. Bubble Sort " << std::endl << std::endl;
	std::cout << "	2. Selection Sort " << std::endl << std::endl;
	std::cout << "	3. Quick Sort " << std::endl << std::endl;
	std::cout << "	4. Merge Sort " << std::endl << std::endl;
	std::cout << "	5. Radix LSD Sort " << std::endl << std::endl;
	/*std::cout << "6. ���� ��� ���� [���� : ";

	if (enum_SortType == eSortType::Ascending)
		std::cout << "�������� ]" << std::endl;
	else
		std::cout << "�������� ]" << std::endl;*/

	std::cout << "	7. ���α׷� ���� " << std::endl << std::endl;
	std::cout << "	9. �迭 ũ�� ���� (���� ũ�� : " << m_iSize << ")" << std::endl << std::endl;
	std::cout << "����������������������������������������������������������������������" << std::endl;
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