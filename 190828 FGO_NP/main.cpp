#include "Header.h"
#include <Windows.h>
#include <conio.h>

#define CONVERSERSION(a,b) if (a == "yes"){b = true;}else if (a == "no") { b = false; };

//TODO .. FGO 서번트 입력 / FGO 보구(레벨에 따른)딜 확인

int main()
{
		cout << "FGO 대군 보구 대미지 계산기!" << endl;

		//입력해야하는 서번트 파라메터 초기화 및 선언
		int atk{};
		string servant_class{};
		string servant_hidden{};
		int np_level{};
		string enhance{};
		string np_type{};
		string hidden{};
		string count{};
		string special_count{};

		cout << "서번트 공격력을 입력해주세요." << endl;
		cin >> atk;
		cout << "서번트 클래스를 입력해주세요." << endl;
		cin >> servant_class;
		cout << "서번트 히든 속성을 입력해주세요." << endl;
		cin >> servant_hidden;
		cout << "서번트 보구 레벨을 입력해주세요." << endl;
		cin >> np_level;
		cout << "서번트 강화 여부를 입력해주세요. yes / no" << endl;
		cin >> enhance;
		cout << "서번트 보구 종류를 입력해주세요. ex) 버스터, 아츠, 퀵" << endl;
		cin >> np_type;
		cout << "상대 서번트의 클래스와 상성입니까? yes / no" << endl;
		cin >> count;
		cout << "클래스가 버서커나 혹은 얼터에고 상성입니까? yes / no" << endl;
		cin >> special_count;


		bool is_enhance{ false };
		CONVERSERSION(enhance, is_enhance);

		bool is_hidden{ false };
		CONVERSERSION(hidden, is_hidden);

		bool is_count{ false };
		CONVERSERSION(count, is_count);

		bool is_special_count{ false };
		CONVERSERSION(special_count, is_special_count);

		int conversion_class{};

		for (int i = 0; i < 11; ++i)
		{
			if (servant_class == g_Servant_class[i])
			{
				conversion_class = i;
			}
		}

		int conversion_hidden{};

		for (int i = 0; i < 4; ++i)
		{
			if (servant_hidden == g_Servant_hidden[i])
			{
				conversion_class = i;
			}
		}

		int conversion_card_type{};

		for (int i = 0; i < 3; ++i)
		{
			if (np_type == g_conversion_card_type[i])
			{
				conversion_card_type = i;
			}
		}


		CServantNpCal my_servant
		{
			CServantNpCal(atk, static_cast<e_servant_class>(conversion_class - 1 ), static_cast<e_hidden_type>(conversion_hidden -1)
			, np_level, is_enhance, static_cast<e_card_type>(conversion_card_type - 1), is_hidden, is_count, is_special_count)
		};


		my_servant.NpDamage();

		my_servant.NpHDamage();
		my_servant.NpLDamage();

		my_servant.Display();

	int a = 0;

	return 0;
}