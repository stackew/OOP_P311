#pragma once

#include "Reservoir.h"

enum Actions
{
	ADD_RESERVOIR = 1,
	DELETE_RESERVOIR,
	PRINT_RESERVOIRS_INFO,
	COMPARE_RESERVOIRS,
	SAVE_INFO_TO_FILE,
	SAVE_INFO_TO_BIN_FILE,
	EXIT
};

enum AddMethods
{
	BY_HAND = 1,
	COPY
};

void AddReservoir(std::vector<Reservoir>& reservoirs);

void CompareReservoirs(const std::vector<Reservoir>& reservoirs);

void CopyMethod(std::vector<Reservoir>& reservoirs);

void DeleteReservoir(std::vector<Reservoir>& reservoirs);

void PrintReservoirsInfo(const std::vector<Reservoir>& reservoirs);

void Program();

void SaveInfoToBinFile(const std::vector<Reservoir>& reservoirs);

void SaveInfoToFile(const std::vector<Reservoir>& reservoirs);

void ShowMenu();

void SwitchCase(std::vector<Reservoir>& reservoirs, Actions& action);