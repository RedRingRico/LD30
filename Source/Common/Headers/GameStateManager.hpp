#ifndef __LD_GAMESTATEMANAGER_HPP__
#define __LD_GAMESTATEMANAGER_HPP__

#include <DataTypes.hpp>
#include <set>
#include <stack>

namespace LD
{
	class GameState;

	class GameStateManager
	{
	public:
		GameStateManager( );
		~GameStateManager( );

		LD_UINT32 RegisterState( GameState *p_pGameState );

		LD_UINT32 PushState( const LD_SCHAR8 *p_pStateName );
		LD_UINT32 PopState( );

		LD_UINT32 Execute( );

		void Quit( );

		LD_BOOL IsRunning( ) const;

		static GameStateManager &GetInstance( );

	private:
		LD_BOOL IsStateNameValid( const LD_SCHAR8 *p_pStateName,
			LD_MEMSIZE *p_pIndex ) const;

		typedef std::set< GameState * > GameStateRegistry;
		typedef std::stack< GameState * > GameStateStack;

		GameStateRegistry	m_GameStateRegistry;
		GameStateStack		m_GameStateStack;

		LD_BOOL	m_Running;
	};
}

#endif // __LD_GAMESTATEMANAGER_HPP__

