#include "Header.h"
#include <Windows.h>
#include <conio.h>

#define BOOLEN_CONVERSERSION(a,b) if (a == 0) b == true; else a == false;

//TODO .. FGO ����Ʈ �Է� / FGO ����(������ ����)�� Ȯ��

int main()
{
	

		cout << "FGO �뱺 ���� ����� ����!" << endl;

		//�Է��ؾ��ϴ� ����Ʈ �Ķ���� �ʱ�ȭ �� ����
		int atk{};
		cout << "����Ʈ ���ݷ��� �Է����ּ���.";
		
		int servant_class{};
		cout << "����Ʈ Ŭ������ �Է����ּ���. ���ڷ� �Է����ּ���." << endl;
		cout << "0. ���̹�, 1. ��ó, 2. ����, 3. ���̴�, 4. ĳ����, 5. ��ؽ�, 6. ����Ŀ,";
		cout <<	". �귯, 8. ���, 9. ��ĵ��, 10. ���Ϳ���, 11 ������,";
		
		int servant_hidden{};
		cout << "����Ʈ ���� �Ӽ��� ���ڷ� �Է����ּ���. 0 = õ �� ��  3 =��";
		
		int np_level{};
		cout << "����Ʈ ���� ������ �Է����ּ���.";
		

		int enhance{};
		bool is_enhance{ false };
		cout << "����Ʈ ��ȭ ���θ� ���ڷ� �Է����ּ���. 0 = ��ȭ ���� 1 = ��ȭ��";
		
		BOOLEN_CONVERSERSION(enhance, is_enhance);

		int np_type{};
		cout << "����Ʈ ���� Ÿ���� �������ּ���. 0 = ������, 1 = ����, 2 = ��";

		
		int hidden{};
		cout << "����Ʈ�� ���� �Ӽ��� ���̶�� 0 �ƴ϶�� 1�� �Է����ּ���.";
		bool is_hidden{false};
		BOOLEN_CONVERSERSION(hidden, is_hidden);

		int counter{};
		cout << "��� ����Ʈ�� �� �Է�, 0. ����Ʈ ";
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