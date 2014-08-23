#ifndef __LD_GAMESTATE_HPP__
#define __LD_GAMESTATE_HPP__

#include <DataTypes.hpp>

namespace LD
{
	class GameState
	{
	public:
		virtual ~GameState( );

		virtual LD_UINT32 Enter( ) = 0;
		virtual LD_UINT32 Exit( ) = 0;

		virtual void Update( const LD_UINT64 p_DeltaTime ) = 0;
		virtual void Render( ) = 0;

		virtual LD_SCHAR8 *GetName( ) = 0;

		LD_BOOL IsRunning( ) const;

	protected:
		LD_BOOL	m_Running;
	};
}

#endif // __LD_GAMESTATE_HPP__

