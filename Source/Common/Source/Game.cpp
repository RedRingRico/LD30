#include <Game.hpp>
#include <GameStateManager.hpp>
#include <GameplayGameState.hpp>
#include <Renderer.hpp>
#include <Memory.hpp>
#include <iostream>

namespace LD
{
	Game::Game( ) :
		m_Running( LD_FALSE ),
		m_pRenderer( LD_NULL )
	{
	}

	Game::~Game( )
	{
	}

	LD_UINT32 Game::Initialise( )
	{
		LD_BOOL Error = LD_FALSE;
		std::cout << "Initialising" << std::endl;

		m_pRenderer = new Renderer( );

		RENDER_PARAMETERS RenderParameters;
		RenderParameters.X = 100;
		RenderParameters.Y = 100;
		RenderParameters.Width = 1280;
		RenderParameters.Height = 720;

		if( m_pRenderer->Initialise( RenderParameters ) != LD_OK )
		{
			std::cout << "Fail" << std::endl;
			return LD_FAIL;
		}

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

		GameStateManager::GetInstance( ).SetRenderer( m_pRenderer );
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

