#include <string>
#include <vector>
#include "enums.h"
#include <string>
#include "structs.h"
#include <Windows.h>

int checkDataOfUser(std::vector<Authentication>& authentication, std::string login, std::string password)
{
	// проверка правильности для вывода сообщение об ошибке
	bool check = false;

	for (int i = 0; i < authentication.size(); i++)
	{
		if (login == authentication.at(i).login and password == authentication.at(i).password)
			return 1;
	}
	if (!check)
		return 0;
}

void openUrl(const std::string& url)
{
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}