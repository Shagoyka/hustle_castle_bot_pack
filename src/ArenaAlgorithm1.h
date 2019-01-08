#pragma once

#include "pch.h"
#include "IArenaAlgorithm.h"


class ArenaAlgorithm1 : public IArenaAlgorithm
{
public:
	virtual int FindOpponent(const PowerData &data, int phase) override;

	// ��� ������ ����: ���� ������ ����� - ���� ������� �� ������. ���� ������ ���� - ���� ����� ������.
	// ���� ������� �������� ����  ��� ������ � ���� ����� ����� �� ������� ����
	// ��� ������ ������� ��������, ��� ����� �������� ���������� �� ����� ������ ��������.
	// ���� �����������, ������� �� ����� ������� 45 �����.
	//

private:
	int FindMe(const PowerData &data);

	// �������� ������� �������� �����������.
	int GetWeakMeanPower(const std::vector<ArenaPowerInfo> &opps);

	// ������ ���� ����������� �� ���������� ��������
	std::vector<ArenaPowerInfo> GetAll(const PowerData &data);

	// ������ ������ ����������� ���� ����, ������� �� ����� ������� ������� ������, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetBelowWeakCannot(const PowerData &data, int count = 0);

	// ������ ������ ����������� ���� ����, ������� �� ����� ������� ������� ������, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetAboveWeakCannot(const PowerData &data, int count = 0);

	// ������ ������ ����������� ���� ����, ������� ����� ����� ���� �� ���� ����.
	std::vector<ArenaPowerInfo> GetAboveWeakCan(const PowerData &data);

	// ������ ������ ����������� ���� ����, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetBelowWeak(const PowerData &data);

	// ������ ������ ����������� ���� ����, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetAboveWeak(const PowerData &data);

	// ������ ���� ������ �����������, ������� ����� ����� �� ������ ������.
	std::vector<ArenaPowerInfo> GetWeak(const PowerData &data);

	// ���������� ������ ����������� ����
	int CountWeatAbove(const PowerData &data, int pos);

	int FindAdaptivePos(const std::vector<ArenaPowerInfo> &opps, bool &reserve_choise);
	
	void IgnoreMeanPower(const PowerData &data, std::vector<ArenaPowerInfo> &power, int count);
};

