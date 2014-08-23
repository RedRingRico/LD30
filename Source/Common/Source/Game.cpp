#include <Game.hpp>
#include <iostream>

namespace LD
{
	Game::Game( )
	{
	}

	Game::~Game( )
	{
	}

	LD_UINT32 Game::Initialise( )
	{
		std::cout << "Initialising" << std::endl;
		return LD_OK;
	}

	LD_UINT32 Game::Execute( )
	{
		while( 1 )
		{
			std::cout << "Looping" << std::endl;
		}
		return LD_OK;
	}
}

