#include <iostream>
#include <GitVersion.hpp>
#include <Game.hpp>

int main( int p_Argc, char **p_ppArgv )
{
	std::cout << "Red Ring Rico's Ludum Dare #30 Competition Entry" <<
		std::endl;
	std::cout << "Version information" << std::endl;
	std::cout << "\tBuild:  " << GIT_BUILD_VERSION << std::endl;
	std::cout << "\tHash:   " << GIT_COMMITHASH << std::endl;
	std::cout << "\tBranch: " << GIT_BRANCH << std::endl;
	std::cout << "\tTag:    " << GIT_TAG_NAME << std::endl;

	LD::Game TheGame;

	if( TheGame.Initialise( ) != LD_OK )
	{
		return LD_FAIL;
	}

	return TheGame.Execute( );
}

