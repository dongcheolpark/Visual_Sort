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
			std::cout << "���ϴ� �迭 ũ�⸦ �Է����ּ��� : ";
			int iSizeSelect = SelectNumber();
			m_iSize = iSizeSelect;
			SortClass.Initialize(iSizeSelect);
			break;
		}
		case 10:
		{

			std::cout << "���ϴ� �����̸� �Է����ּ��� (1000 = 1��) : ";
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
	std::cout << "����������������������������������������������������������������������������������������������������������������������������" << std::endl;
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
	std::cout << "	9. �迭 ũ�� ���� [���� ũ�� : " << m_iSize << "]" << std::endl << std::endl;
	std::cout << "	10. ���� ������ ���� [���� ������ : " << m_iDelay << "ms]" << std::endl << std::endl;
	if(!g_bColorCheck)
		std::cout << "	0. �� ���� �ѱ� (���� : ����) " << std::endl << "	[���� : �� ������ �Ѹ� �� ���涧���� �ӵ��� 7�� �̻� ��������]" << std::endl << std::endl;
	else
		std::cout << "	0. �� ���� ���� (���� : ����) " << std::endl << "	[���� : �� ������ �Ѹ� �� ���涧���� �ӵ��� 7�� �̻� ��������]" << std::endl << std::endl;
	std::cout << "����������������������������������������������������������������������������������������������������������������������������" << std::endl;
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