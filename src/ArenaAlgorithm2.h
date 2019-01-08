#pragma once

#include "pch.h"
#include "IArenaAlgorithm.h"


class ArenaAlgorithm2 : public IArenaAlgorithm
{
public:
	virtual int FindOpponent(const PowerData &data, int phase) override;


private:
	// ���� 1 � ���� 2. ������� ����� ������ ���� ����.


	int FindMe(const PowerData &data);



	// ������ ������ ����������� ���� ����, ������� ����� ����� ���� �� ���� ����.
	std::vector<ArenaPowerInfo> GetAboveWeakCan(const PowerData &data);

	// ������ ������ ����������� ���� ����, ������� �� ����� ����� ���� �� ���� ����.
	std::vector<ArenaPowerInfo> GetAboveWeakCannot(const PowerData &data);

	// ������ ������ ����������� ���� ����, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetAboveWeak(const PowerData &data);

	// ���������� ������ ����������� ����
	int CountWeatAbove(const PowerData &data, int pos);

	// ������ ������ ����������� ���� ����, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetBelowWeak(const PowerData &data);

	// ���� ���, ��� ���� ���� � �� ����� ����� 2 �����.
	std::vector<ArenaPowerInfo> GetPhase3(PowerData data);

	// �������� ���� ���� ����� �����.
	std::vector<ArenaPowerInfo> GetAll(const PowerData &data);

	// ������ ���� ������ �����������, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetWeak(const PowerData &data);
};

