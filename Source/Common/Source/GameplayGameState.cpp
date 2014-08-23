#include <GameplayGameState.hpp>
#include <GameStateManager.hpp>
#include <Renderer.hpp>
#include <iostream>

namespace LD
{
	GameplayGameState::GameplayGameState( ) :
		m_Tick( 0U )
	{
		m_Running = LD_FALSE;
	}

	GameplayGameState::~GameplayGameState( )
	{
	}

	LD_UINT32 GameplayGameState::Enter( )
	{
		std::cout << "Entering gameplay" << std::endl;
		m_Running = LD_TRUE;

		GameStateManager::GetInstance( ).GetRenderer( )->SetClearColour( 1.0f,
			0.0f, 0.0f );

		return LD_OK;
	}

	LD_UINT32 GameplayGameState::Exit( )
	{
		std::cout << "Exiting gameplay" << std::endl;
		return LD_OK;
	}

	void GameplayGameState::Update( const LD_UINT64 p_DeltaTime )
	{
	}

	void GameplayGameState::Render( )
	{
	}

	LD_SCHAR8 *GameplayGameState::GetName( )
	{
		return "Gameplay";
	}
}

