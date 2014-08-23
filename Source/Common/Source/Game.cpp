#include <Game.hpp>
#include <GameStateManager.hpp>
#include <GameplayGameState.hpp>
#include <Memory.hpp>
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
		LD_BOOL Error = LD_FALSE;
		std::cout << "Initialising" << std::endl;
		if( Error )
		{
			std::cout << "Fail" << std::endl;
			return LD_FAIL;
		}
		
		std::cout << "OK" << std::endl;

		return LD_OK;
	}

	LD_UINT32 Game::Execute( )
	{
		m_Running = LD_TRUE;

		GameplayGameState *pGameplay = new GameplayGameState( );

		GameStateManager::GetInstance( ).RegisterState( pGameplay );

		GameStateManager::GetInstance( ).PushState( "Gameplay" );

		while( m_Running )
		{
			if( GameStateManager::GetInstance( ).Execute( ) == LD_FAIL )
			{
				break;
			}
			m_Running = GameStateManager::GetInstance( ).IsRunning( );
		}

		SafeDelete( pGameplay );

		return LD_OK;
	}
}

