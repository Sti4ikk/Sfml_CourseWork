#include <string>
#include <vector>
#include "enums.h"
#include <string>
#include "structs.h"

int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password)
{
	// �������� ������������ ��� ������ ��������� �� ������
	bool check = false;

	for (int i = 0; i < authentication.size(); i++)
	{
		if (login == authentication.at(i).login and password == authentication.at(i).password)
			return 1;
	}
	if (!check)
		return 0;
}