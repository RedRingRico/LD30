#ifndef __LD_GAMEPLAYGAMESTATE_HPP__
#define __LD_GAMEPLAYGAMESTATE_HPP__

#include <GameState.hpp>

namespace LD
{
	class GameplayGameState : public GameState
	{
	public:
		GameplayGameState( );
		virtual ~GameplayGameState( );

		virtual LD_UINT32 Enter( );
		virtual LD_UINT32 Exit( );

		virtual void Update( const LD_UINT64 p_DeltaTime );
		virtual void Render( );

		virtual LD_SCHAR8 *GetName( );

	private:
		LD_UINT32	m_Tick;
	};
}

#endif // __LD_GAMEPLAYGAMESTATE_HPP__

