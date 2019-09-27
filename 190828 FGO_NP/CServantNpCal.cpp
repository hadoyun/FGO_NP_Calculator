#include "CServantNpCal.h"

using namespace std;

#define Counter(my_class, enemy_class) if (m_servant_class == my_class) { if (m_enemy_class == enemy_class) {m_is_normal_count = true;}};
#define Advent(my_class, enemy_class) if (m_servant_class == my_class) { if (m_enemy_class == enemy_class) {m_is_advent = true;}};


//ATK * ���� ���(0.23) * ī�� ������ ��� * ���� ����* Ŭ���� ���* Ŭ���� ��* ���� ��* ����(0.9~1.1)
void CServantNpCal::NpDamage()
{
	m_np_damage = static_cast<int>(m_atk * 0.23 * NpTypeCoef() * NpLevelCoef() * HiddenTypeCoef() * EnemyTypeCoef());
}

//���� NP ������ * 0.9 ~ 1.1;
void CServantNpCal::NpLDamage()
{
	m_np_law_r_damage = static_cast<int>(m_np_damage * 0.9);
}

void CServantNpCal::NpHDamage()
{
	m_np_height_r_damage = static_cast<int>(m_np_damage * 1.1);
}

//���� ī�� ������ ���� ����� ����
float CServantNpCal::NpTypeCoef()
{
	switch (m_np_type)
	{
	case e_card_type::Buster:
		return 1.5f;
		break;
	case e_card_type::Arts:
		return 1.0f;
		break;
	case e_card_type::Quick:
		return 0.5f;
		break;
	default:
		return 1.0f;
		break;
	}
}

//���� ������ ���� ����� ����
float CServantNpCal::NpLevelCoef()
{
	switch (m_np_type)
	{
	case e_card_type::Buster:

		if (m_enhance != true)
		{
			return g_buster[m_np_level - 1];
		}
		else if(m_enhance)
		{
			return g_Enbuster[m_np_level - 1];
		}
		break;

	case e_card_type::Arts:

		if (m_enhance != true)
		{
			return g_Arts[m_np_level - 1];
		}
		else if (m_enhance)
		{
			return g_EnArts[m_np_level - 1];
		}
		break;

	case e_card_type::Quick:

		if (m_enhance != true)
		{
			return g_Quick[m_np_level - 1];
		}
		else if (m_enhance)
		{
			return g_EnQuick[m_np_level - 1];
		}
		break;
	default:
		return 1.0f;
		break;
	}
};


//����Ʈ ���� �Ӽ��� ���� ����� ����
/*
float CServantNpCal::HiddenTypeCoef()
{
	switch (m_enemy_hidden_type)
	{
	case e_hidden_type::õ:
		switch (m_hidden_type)
		{
		case e_hidden_type::õ:
			return 1.0f;
			break;
		case e_hidden_type::��:
			return 0.9f;
			break;
		case e_hidden_type::��:
			return 1.1f;
			break;
		case e_hidden_type::��:
			return 1.0f;
			break;
		default:
			break;
		}
		break;
	case e_hidden_type::��:
		switch (m_hidden_type)
		{
		case e_hidden_type::õ:
			return 0.9f;
			break;
		case e_hidden_type::��:
			return 1.0f;
			break;
		case e_hidden_type::��:
			return 1.1f;
			break;
		case e_hidden_type::��:
			return 1.0f;
			break;
		default:
			break;
		}
		break;
	case e_hidden_type::��:
		switch (m_hidden_type)
		{
		case e_hidden_type::õ:
			return 1.1f;
			break;
		case e_hidden_type::��:
			return 0.9f;
			break;
		case e_hidden_type::��:
			return 1.0;
			break;
		case e_hidden_type::��:
			return 1.0f;
			break;
		default:
			break;
		}
		break;
	case e_hidden_type::��:
		return 1.0f;
		break;
	default:
		break;
	}
}*/

float CServantNpCal::HiddenTypeCoef()
{
	if (m_is_hidden_count == true)
	{
		return 1.1f;
	}
}



//Ŭ���� �� ����
/*float CServantNpCal::EnemyTypeCoef()
{
	if (m_is_count == true)
	{
		return g_ClassCoef[0];
	}
	else if (m_is_advent == true)
	{
		return g_ClassCoef[3];
	}
	else if (m_is_spe == true)
	{
		return g_ClassCoef[2];
	}
	else
	{
		return g_ClassCoef[1];
	}
}



//0.5�� ������� ���� ����Ʈ ��ǥ
void CServantNpCal::CounterType()
{
	//3��� 
	Counter(e_servant_class::���̹�, e_servant_class::��ó);
	Counter(e_servant_class::��ó, e_servant_class::����);
	Counter(e_servant_class::����, e_servant_class::���̹�);
	//4����(����Ŀ ����)
	Counter(e_servant_class::���̴�, e_servant_class::��ؽ�);
	Counter(e_servant_class::��ؽ�, e_servant_class::ĳ����);
	Counter(e_servant_class::ĳ����, e_servant_class::��ؽ�);
	//����Ʈ��
	Counter(e_servant_class::��ĵ��, e_servant_class::�귯);
	Counter(e_servant_class::���, e_servant_class::��ĵ��);
	Counter(e_servant_class::�귯, e_servant_class::��ĵ��);
	Counter(e_servant_class::������, e_servant_class::���Ϳ���);
}

//2�� ������� ���� ����Ʈ ��ǥ
void CServantNpCal::AdventType()
{
	//3���
	Advent(e_servant_class::���̹�, e_servant_class::����);
	Advent(e_servant_class::��ó, e_servant_class::���̹�);
	Advent(e_servant_class::����, e_servant_class::��ó);
	//4����(����Ŀ ����)
	Advent(e_servant_class::���̴�, e_servant_class::ĳ����);
	Advent(e_servant_class::��ؽ�, e_servant_class::���̴�);
	Advent(e_servant_class::ĳ����, e_servant_class::��ؽ�);
	//����Ʈ��
	Advent(e_servant_class::��ĵ��, e_servant_class::���);
	Advent(e_servant_class::���, e_servant_class::�귯);
	Advent(e_servant_class::�귯, e_servant_class::���);

	Advent(e_servant_class::���Ϳ���, e_servant_class::������);
}

//�ټ����� ���̵��� �ִ� Ŭ���� ��ǥ
void CServantNpCal::SpeType()
{
	//�Ǵ��� �����ʸ� ������ ����Ʈ Ÿ��
	int ServentType = 11;
	//int AlteragoAdvents = 3;


	for (int i = 0; i < ServentType; ++i)
	{
		Advent(e_servant_class::����Ŀ, static_cast<e_servant_class>(i));
	}
	for (int i = 0; i < 4; ++i)
	{
		Advent(e_servant_class::���Ϳ���, static_cast<e_servant_class>(i+3));
	}
}
*/

//����Ʈ Ŭ���� ���� g_ClassCoef[]{ 0.9f, 0.95f, 1.0f, 1.05f, 1.1f };
float CServantNpCal::ClassCoef()
{
	if ((m_servant_class == e_servant_class::��ؽ�) || (m_servant_class == e_servant_class::ĳ����))
	{
		return g_ClassHiddenCoef[0];
	}
	else if (m_servant_class == e_servant_class::��ó)
	{
		return g_ClassHiddenCoef[1];
	}
	else if ((((m_servant_class == e_servant_class::���̹�) || (m_servant_class == e_servant_class::���̴�)
		|| (m_servant_class == e_servant_class::��ĵ��) || (m_servant_class == e_servant_class::���Ϳ���)
		|| (m_servant_class == e_servant_class::������))))
	{
		return g_ClassHiddenCoef[2];
	}
	else if (m_servant_class == e_servant_class::����)
	{
		return g_ClassHiddenCoef[3];
	}
	else if (((m_servant_class == e_servant_class::����Ŀ)||(m_servant_class == e_servant_class::�귯))
		||(m_servant_class == e_servant_class::���))
	{
		return g_ClassHiddenCoef[3];
	}
	return 1.0;
}

float CServantNpCal::EnemyTypeCoef()
{
	if (m_is_special_count == true)
	{
		return 1.5f;
	}
	else if (m_is_normal_count == true)
	{
		return 2.0f;
	}
	else if (m_is_normal_count != true)
	{
		return 1.0f;
	}
}



void CServantNpCal::Display()
{
	cout << "����Ʈ ���ݷ�: " << m_atk << endl;
	cout << "����Ʈ Ŭ����: " << ClassName() << endl;
	cout << "���� ī�� ����: " << static_cast<char>(m_np_type) << endl;

	//cout << "Enemy Ŭ����" << m_enemy_class << " �϶�" << endl;
	cout << "����Ʈ ���� ����ġ(����) :" << static_cast<int>(m_np_law_r_damage) << endl;
	cout << "����Ʈ ���� �ִ�ġ(����) :" << static_cast<int>(m_np_height_r_damage) << endl;

	cout << "���� ����Ʈ ������ ��� ������� " << static_cast<int>(m_np_damage) << "�Դϴ�. " << endl;
}


const char* CServantNpCal::ClassName()
{
	switch (m_servant_class)
	{
	case e_servant_class::���̹�:
		return g_Servant_class[0];
		break;
	case e_servant_class::��ó:
		return g_Servant_class[1];
		break;
	case e_servant_class::����:
		return g_Servant_class[2];
		break;
	case e_servant_class::���̴�:
		return g_Servant_class[3];
		break;
	case e_servant_class::ĳ����:
		return g_Servant_class[4];
		break;
	case e_servant_class::��ؽ�:
		return g_Servant_class[5];
		break;
	case e_servant_class::����Ŀ:
		return g_Servant_class[6];
		break;
	case e_servant_class::�귯:
		return g_Servant_class[7];
		break;
	case e_servant_class::���:
		return g_Servant_class[8];
		break;
	case e_servant_class::��ĵ��:
		return g_Servant_class[9];
		break;
	case e_servant_class::���Ϳ���:
		return g_Servant_class[10];
		break;
	case e_servant_class::������:
		return g_Servant_class[11];
		break;
	default:
		break;
	}
}