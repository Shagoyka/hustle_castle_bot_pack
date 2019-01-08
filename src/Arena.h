#pragma once

#include "pch.h"
#include "Applet.h"
#include "IArenaAlgorithm.h"



class Arena
{
public:
	Arena(Applet &app);

	bool IsValidPhase();

	bool IsValidOpponent(int val);

	void GetOpponentInfo(int val);

	int FindOpponent();

	void SetMyPowerScale(double val);

	void SetAlgorithm(int val);

private:
	Applet &mApplet;

	double mMyPowerScale = 1.0;
	PowerData mPowerData;

private:
	// ��� ������ ����: ���� ������ ����� - ���� ������� �� ������. ���� ������ ���� - ���� ����� ������.
	// ���� ������� �������� ����  ��� ������ � ���� ����� ����� �� ������� ����
	// ��� ������ ������� ��������, ��� ����� �������� ���������� �� ����� ������ ��������.
	// ���� �����������, ������� �� ����� ������� 45 �����.
	//

	PowerData GetScaledData();

	// �������� ����� ����.
	int GetPhase(const PowerData &data);
	int FindMe(const PowerData &data);
private:
	// ��� ������ �� ���:
	// �������� ���� �����������.
	// ���� ��������.
	// ��� ������ ����: ���� �������, ������� ����������, �������� ����������, ������ ��� ���������.
	std::unique_ptr<IArenaAlgorithm> mAlgorithm;


	struct PhaseLog
	{
		int my_pos = 0;
		int other_pos = 0;
		int other_power = 0;
		bool result = false;
	};

	struct ArenaLog
	{
		int my_power = 0;
		int scaled_power = 0;
		std::array<int, 15> other_power = {0};
		std::array<PhaseLog, 5> phase;
	};

	ArenaLog mArenaLog;
	std::ofstream mArenaLogFile;
public:
	void WriteLogPhase(bool result);
	void WriteLogArena(const PowerData &data, int phase);
	void WriteLogResult();

};

