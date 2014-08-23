#include <GameplayGameState.hpp>
#include <GameStateManager.hpp>
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

		return LD_OK;
	}

	LD_UINT32 GameplayGameState::Exit( )
	{
		return LD_OK;
	}

	void GameplayGameState::Update( const LD_UINT64 p_DeltaTime )
	{
		std::cout << "Tick: " << m_Tick << std::endl;
		++m_Tick;

		if( m_Tick > 10 )
		{
			m_Running = LD_FALSE;
		}
	}

	void GameplayGameState::Render( )
	{
	}

	LD_SCHAR8 *GameplayGameState::GetName( )
	{
		return "Gameplay";
	}
}

