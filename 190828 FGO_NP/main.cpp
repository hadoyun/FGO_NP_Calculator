#include "Header.h"
#include <Windows.h>
#include <conio.h>

#define BOOLEN_CONVERSERSION(a,b) if (a == 0) b == true; else a == false;

//TODO .. FGO 서번트 입력 / FGO 보구(레벨에 따른)딜 확인

int main()
{
	

		cout << "FGO 대군 보구 대미지 계산기!" << endl;

		//입력해야하는 서번트 파라메터 초기화 및 선언
		int atk{};
		cout << "서번트 공격력을 입력해주세요.";
		
		int servant_class{};
		cout << "서번트 클래스를 입력해주세요. 숫자로 입력해주세요." << endl;
		cout << "0. 세이버, 1. 아처, 2. 랜서, 3. 라이더, 4. 캐스터, 5. 어쌔신, 6. 버서커,";
		cout <<	". 룰러, 8. 어벤저, 9. 문캔서, 10. 얼터에고, 11 포리너,";
		
		int servant_hidden{};
		cout << "서번트 히든 속성을 숫자로 입력해주세요. 0 = 천 지 인  3 =별";
		
		int np_level{};
		cout << "서번트 보구 레벨을 입력해주세요.";
		

		int enhance{};
		bool is_enhance{ false };
		cout << "서번트 강화 여부를 숫자로 입력해주세요. 0 = 강화 안함 1 = 강화함";
		
		BOOLEN_CONVERSERSION(enhance, is_enhance);

		int np_type{};
		cout << "서번트 보구 타입을 설정해주세요. 0 = 버스터, 1 = 아츠, 2 = 퀵";

		
		int hidden{};
		cout << "서번트의 히든 속성이 상성이라면 0 아니라면 1을 입력해주세요.";
		bool is_hidden{false};
		BOOLEN_CONVERSERSION(hidden, is_hidden);

		int counter{};
		cout << "상대 서번트가 상성 입력, 0. 서번트 ";
		bool is_counter{ false };
		BOOLEN_CONVERSERSION(counter, is_counter);

		

		CServantNpCal my_servant
		{
			CServantNpCal(atk, static_cast<e_servant_class>(servant_class), static_cast<e_hidden_type>(servant_hidden)
			, np_level, is_enhance, static_cast<e_card_type>(np_type), is_hidden, is_counter, is_special_count)
		};


		my_servant.NpDamage();

		my_servant.NpHDamage();
		my_servant.NpLDamage();

		my_servant.Display();

	int a = 0;

	return 0;
}