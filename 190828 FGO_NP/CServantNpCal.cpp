#include "CServantNpCal.h"

using namespace std;

#define Counter(my_class, enemy_class) if (m_servant_class == my_class) { if (m_enemy_class == enemy_class) {m_is_normal_count = true;}};
#define Advent(my_class, enemy_class) if (m_servant_class == my_class) { if (m_enemy_class == enemy_class) {m_is_advent = true;}};


//ATK * 공격 계수(0.23) * 카드 데미지 계수 * 보구 배율* 클래스 계수* 클래스 상성* 히든 상성* 난수(0.9~1.1)
void CServantNpCal::NpDamage()
{
	m_np_damage = static_cast<int>(m_atk * 0.23 * NpTypeCoef() * NpLevelCoef() * HiddenTypeCoef() * EnemyTypeCoef());
}

//난수 NP 데미지 * 0.9 ~ 1.1;
void CServantNpCal::NpLDamage()
{
	m_np_law_r_damage = static_cast<int>(m_np_damage * 0.9);
}

void CServantNpCal::NpHDamage()
{
	m_np_height_r_damage = static_cast<int>(m_np_damage * 1.1);
}

//보구 카드 종류에 따른 대미지 보정
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

//보구 레벨에 따른 대미지 보정
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


//서번트 히든 속성에 따른 대미지 보정
/*
float CServantNpCal::HiddenTypeCoef()
{
	switch (m_enemy_hidden_type)
	{
	case e_hidden_type::천:
		switch (m_hidden_type)
		{
		case e_hidden_type::천:
			return 1.0f;
			break;
		case e_hidden_type::지:
			return 0.9f;
			break;
		case e_hidden_type::인:
			return 1.1f;
			break;
		case e_hidden_type::별:
			return 1.0f;
			break;
		default:
			break;
		}
		break;
	case e_hidden_type::지:
		switch (m_hidden_type)
		{
		case e_hidden_type::천:
			return 0.9f;
			break;
		case e_hidden_type::지:
			return 1.0f;
			break;
		case e_hidden_type::인:
			return 1.1f;
			break;
		case e_hidden_type::별:
			return 1.0f;
			break;
		default:
			break;
		}
		break;
	case e_hidden_type::인:
		switch (m_hidden_type)
		{
		case e_hidden_type::천:
			return 1.1f;
			break;
		case e_hidden_type::지:
			return 0.9f;
			break;
		case e_hidden_type::인:
			return 1.0;
			break;
		case e_hidden_type::별:
			return 1.0f;
			break;
		default:
			break;
		}
		break;
	case e_hidden_type::별:
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



//클래스 상성 보정
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



//0.5배 대미지가 들어가는 서번트 상성표
void CServantNpCal::CounterType()
{
	//3기사 
	Counter(e_servant_class::세이버, e_servant_class::아처);
	Counter(e_servant_class::아처, e_servant_class::랜서);
	Counter(e_servant_class::랜서, e_servant_class::세이버);
	//4술사(버서커 제외)
	Counter(e_servant_class::라이더, e_servant_class::어쌔신);
	Counter(e_servant_class::어쌔신, e_servant_class::캐스터);
	Counter(e_servant_class::캐스터, e_servant_class::어쌔신);
	//엑스트라
	Counter(e_servant_class::문캔서, e_servant_class::룰러);
	Counter(e_servant_class::어벤저, e_servant_class::문캔서);
	Counter(e_servant_class::룰러, e_servant_class::문캔서);
	Counter(e_servant_class::포리너, e_servant_class::얼터에고);
}

//2배 대미지가 들어가는 서번트 상성표
void CServantNpCal::AdventType()
{
	//3기사
	Advent(e_servant_class::세이버, e_servant_class::랜서);
	Advent(e_servant_class::아처, e_servant_class::세이버);
	Advent(e_servant_class::랜서, e_servant_class::아처);
	//4술사(버서커 제외)
	Advent(e_servant_class::라이더, e_servant_class::캐스터);
	Advent(e_servant_class::어쌔신, e_servant_class::라이더);
	Advent(e_servant_class::캐스터, e_servant_class::어쌔신);
	//엑스트라
	Advent(e_servant_class::문캔서, e_servant_class::어벤저);
	Advent(e_servant_class::어벤저, e_servant_class::룰러);
	Advent(e_servant_class::룰러, e_servant_class::어벤저);

	Advent(e_servant_class::얼터에고, e_servant_class::포리너);
}

//다수에게 상성이득이 있는 클래스 상성표
void CServantNpCal::SpeType()
{
	//실더와 포리너를 제외한 서번트 타입
	int ServentType = 11;
	//int AlteragoAdvents = 3;


	for (int i = 0; i < ServentType; ++i)
	{
		Advent(e_servant_class::버서커, static_cast<e_servant_class>(i));
	}
	for (int i = 0; i < 4; ++i)
	{
		Advent(e_servant_class::얼터에고, static_cast<e_servant_class>(i+3));
	}
}
*/

//서번트 클래스 보정 g_ClassCoef[]{ 0.9f, 0.95f, 1.0f, 1.05f, 1.1f };
float CServantNpCal::ClassCoef()
{
	if ((m_servant_class == e_servant_class::어쌔신) || (m_servant_class == e_servant_class::캐스터))
	{
		return g_ClassHiddenCoef[0];
	}
	else if (m_servant_class == e_servant_class::아처)
	{
		return g_ClassHiddenCoef[1];
	}
	else if ((((m_servant_class == e_servant_class::세이버) || (m_servant_class == e_servant_class::라이더)
		|| (m_servant_class == e_servant_class::문캔서) || (m_servant_class == e_servant_class::얼터에고)
		|| (m_servant_class == e_servant_class::포리너))))
	{
		return g_ClassHiddenCoef[2];
	}
	else if (m_servant_class == e_servant_class::랜서)
	{
		return g_ClassHiddenCoef[3];
	}
	else if (((m_servant_class == e_servant_class::버서커)||(m_servant_class == e_servant_class::룰러))
		||(m_servant_class == e_servant_class::어벤저))
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
	cout << "서번트 공격력: " << m_atk << endl;
	cout << "서번트 클래스: " << ClassName() << endl;
	cout << "보구 카드 종류: " << static_cast<char>(m_np_type) << endl;

	//cout << "Enemy 클래스" << m_enemy_class << " 일때" << endl;
	cout << "서번트 보구 최저치(난수) :" << static_cast<int>(m_np_law_r_damage) << endl;
	cout << "서번트 보구 최대치(난수) :" << static_cast<int>(m_np_height_r_damage) << endl;

	cout << "따라서 서번트 보구의 평균 대미지는 " << static_cast<int>(m_np_damage) << "입니다. " << endl;
}


const char* CServantNpCal::ClassName()
{
	switch (m_servant_class)
	{
	case e_servant_class::세이버:
		return g_Servant_class[0];
		break;
	case e_servant_class::아처:
		return g_Servant_class[1];
		break;
	case e_servant_class::랜서:
		return g_Servant_class[2];
		break;
	case e_servant_class::라이더:
		return g_Servant_class[3];
		break;
	case e_servant_class::캐스터:
		return g_Servant_class[4];
		break;
	case e_servant_class::어쌔신:
		return g_Servant_class[5];
		break;
	case e_servant_class::버서커:
		return g_Servant_class[6];
		break;
	case e_servant_class::룰러:
		return g_Servant_class[7];
		break;
	case e_servant_class::어벤저:
		return g_Servant_class[8];
		break;
	case e_servant_class::문캔서:
		return g_Servant_class[9];
		break;
	case e_servant_class::얼터에고:
		return g_Servant_class[10];
		break;
	case e_servant_class::포리너:
		return g_Servant_class[11];
		break;
	default:
		break;
	}
}