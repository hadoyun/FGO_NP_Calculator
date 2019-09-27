#pragma once
#include <iostream>
#include <vector>

#include "CServantNpCal.h"


using namespace std;

//버스터 대군 보구
constexpr float g_buster[]{ 3.0f, 4.0f, 4.5f, 4.75f, 5.0f };
//버스터 대군 보구 강화퀘 클리어 후 
constexpr float g_Enbuster[]{ 4.0f, 5.0f, 5.5f, 5.75f, 6.0f };

//아츠 대군 보구
constexpr float g_Arts[]{ 4.5f, 6.0f, 6.75f, 7.125f, 7.5f };
//아츠 대군 보구 강화퀘 클리어 후
constexpr float g_EnArts[]{ 6.0f, 7.5f, 8.25f, 8.625f, 9.0f };

//퀵 대군 보구
constexpr float g_Quick[]{ 6.0f, 8.0f, 9.0f, 9.5f, 10.0f };
//퀵 대군 보구 강화퀘 클리어 후
constexpr float g_EnQuick[]{ 8.0f, 10.0f, 11.0f, 11.5f, 12.0f };

//상대 서번트 클래스에 따른 대미지 상승률
constexpr float g_ClassCoef[]{ 0.5f, 1.0f, 1.5f, 2.0f };

//서번트 클래스에 따른 대미지 보정 
constexpr float g_ClassHiddenCoef[]{ 0.9f, 0.95f, 1.0f, 1.05f, 1.1f };


constexpr const char* g_Servant_class[]{ "세이버", "아처", "랜서", "라이더", "캐스터",
										"어쌔신", "버서커", "룰러", "어벤저", "문캔서"
										"얼터에고", "포리너" };

constexpr const char* g_Servant_hidden[]{ "천", "지", "인", "별" };

constexpr const	char* g_conversion_card_type[]{ "버스터", "아츠", "퀵" };