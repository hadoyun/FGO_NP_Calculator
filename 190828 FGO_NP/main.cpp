#include "Header.h"
#include <Windows.h>
#include <conio.h>

#define CONVERSERSION(a,b) if (a == "yes"){b = true;}else if (a == "no") { b = false; };

//TODO .. FGO ����Ʈ �Է� / FGO ����(������ ����)�� Ȯ��

int main()
{
		cout << "FGO �뱺 ���� ����� ����!" << endl;

		//�Է��ؾ��ϴ� ����Ʈ �Ķ���� �ʱ�ȭ �� ����
		int atk{};
		string servant_class{};
		string servant_hidden{};
		int np_level{};
		string enhance{};
		string np_type{};
		string hidden{};
		string count{};
		string special_count{};

		cout << "����Ʈ ���ݷ��� �Է����ּ���." << endl;
		cin >> atk;
		cout << "����Ʈ Ŭ������ �Է����ּ���." << endl;
		cin >> servant_class;
		cout << "����Ʈ ���� �Ӽ��� �Է����ּ���." << endl;
		cin >> servant_hidden;
		cout << "����Ʈ ���� ������ �Է����ּ���." << endl;
		cin >> np_level;
		cout << "����Ʈ ��ȭ ���θ� �Է����ּ���. yes / no" << endl;
		cin >> enhance;
		cout << "����Ʈ ���� ������ �Է����ּ���. ex) ������, ����, ��" << endl;
		cin >> np_type;
		cout << "��� ����Ʈ�� Ŭ������ ���Դϱ�? yes / no" << endl;
		cin >> count;
		cout << "Ŭ������ ����Ŀ�� Ȥ�� ���Ϳ��� ���Դϱ�? yes / no" << endl;
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