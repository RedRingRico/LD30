#ifndef __LD_GAME_HPP__
#define __LD_GAME_HPP__

#include <DataTypes.hpp>

namespace LD
{
	class Renderer;

	class Game
	{
	public:
		Game( );
		~Game( );

		LD_UINT32 Initialise( );
		LD_UINT32 Execute( );

	private:
		LD_BOOL		m_Running;
		Renderer	*m_pRenderer;
	};
}

#endif // __LD_GAME_HPP__

