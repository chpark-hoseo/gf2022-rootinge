#pragma once

class GameManager
{
public:
	static int MainWindow;
	
	static int m_stage;

	static int m_clear;

	static GameManager* Instance()
	{
		if (s_pInstance == 0)
			s_pInstance = new GameManager();
		return s_pInstance;
	}

private:

	static GameManager* s_pInstance;
};
typedef GameManager TheGameManager;