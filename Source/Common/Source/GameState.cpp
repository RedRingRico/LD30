#include <GameState.hpp>

namespace LD
{
	GameState::~GameState( )
	{
	}

	LD_BOOL GameState::IsRunning( ) const
	{
		return m_Running;
	}
}

