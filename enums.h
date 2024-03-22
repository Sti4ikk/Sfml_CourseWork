#pragma once

// ��������� �����������
enum class Post
{
	JUNIOR = 1,
	MIDDLE,
	SENIOR,
	TEAM_LEADER,
	PROJECT_MANAGER,
	DIRECTOR_OF_DEPARTMENT,
	DEPUTY_GENERAL_DIRECTOR,
	GENERAL_DIRECTOR,
};

enum AuthOrRegistr
{
	AUTH = 1,
	REGISTER,
};

enum Main_Menu
{
	EDITING_MODE = 1,
	PROCESSING_MODE,
	SETTINGS,
	EXIT,
};

enum EditingMode
{
	CHECKING = 1,
	ADDING,
	EDITING,
	DELETING,
	E_BACK,
};


enum ProcessingMode
{
	SEARCH = 1,
	SORTING,
	INDIVIDUAL_TASK,
	P_BACK,
};


enum Settings
{
	LANGUAGE = 1,
	S_LEAVE_FROM_ACCOUNT,
	S_BACK,
};