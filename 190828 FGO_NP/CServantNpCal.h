#pragma once
#include "Header.h"

/*struct Servent
{
	Servent() {};
	~Servent() {};


};*/

//ī�� Ÿ��
enum class e_card_type
{
	Buster = 0,
	Arts,
	Quick,
};

//����Ʈ �Ӽ�
enum class e_servant_class
{
	���̹� = 0,
	��ó,
	����,
	���̴�,
	ĳ����,
	��ؽ�,
	����Ŀ,
	�귯,
	���,
	��ĵ��,
	���Ϳ���,
	������,
};

//����Ʈ ���� �Ӽ�
enum class e_hidden_type
{
	õ = 0,
	��,
	��,
	��,
};



class CServantNpCal
{
public:
	CServantNpCal() {};
	CServantNpCal(int _atk, e_servant_class _class, e_hidden_type _hidden_type, int _np_level, bool _enhance,
		e_card_type _card_type, bool _is_normal_count, bool _is_hidden_count, bool _is_special_count)

		: m_atk(static_cast<float>(_atk)), m_servant_class(_class), m_hidden_type(_hidden_type),
		m_np_level(_np_level), m_enhance(_enhance), m_np_type(_card_type)

	{
		if (_is_normal_count == true)
		{
			m_is_normal_count = true;
		}
		if (_is_hidden_count == true)
		{
			m_is_hidden_count = true;
		}
		if (_is_special_count == true)
		{
			m_is_special_count == true;
		}
	};
	~CServantNpCal() {};


public:
	void NpDamage();

	void NpLDamage();
	void NpHDamage();
	void Display();

	float EnemyTypeCoef();
	float HiddenTypeCoef();


public:
	float GetAtk() { return m_atk; };

public:
	float NpTypeCoef();
	float NpLevelCoef();
	float ClassCoef();
	/*
	void CounterType();
	void AdventType();
	void SpeType();
	*/

	const char* ClassName();

//�Ű����� / �� ���� �Ӽ�
public:
	/*
	e_hidden_type	m_enemy_hidden_type{};
	*/
	e_hidden_type	m_hidden_type{};

public:
	e_servant_class ServantClass() { return m_servant_class; };
	e_card_type		NpType(){ return m_np_type; };

private:
	int				m_np_level{ 1 };

	float			m_atk{ 0 };

	bool			m_enhance{ false };

	int				m_np_damage{};
	int				m_np_law_r_damage{};
	int				m_np_height_r_damage{};

	e_servant_class	m_servant_class{};
	e_servant_class	m_enemy_class{};
	e_card_type		m_np_type{};
	/*
	bool			m_is_count{ false };
	bool			m_is_advent{ false };
	bool			m_is_spe{ false };
	*/
	bool			m_is_normal_count{ false };
	bool			m_is_hidden_count{ false };
	bool			m_is_special_count{ false };
};