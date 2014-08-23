#ifndef __LD_RENDERER_HPP__
#define __LD_RENDERER_HPP__

#include <DataTypes.hpp>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

namespace LD
{
	typedef struct __tagRENDER_PARAMETERS
	{
		LD_SINT32	X;
		LD_SINT32	Y;
		LD_UINT32	Width;
		LD_UINT32	Height;
	}RENDER_PARAMETERS;

	class Renderer
	{
	public:
		Renderer( );
		~Renderer( );

		LD_UINT32 Initialise( const RENDER_PARAMETERS &p_Parameters );
		
		LD_UINT32 BeginScene( );
		void EndScene( );

		void HandleWindowEvents( );

		void SetClearColour( LD_FLOAT32 p_Red, LD_FLOAT32 p_Green,
			LD_FLOAT32 p_Blue );

		LD_BOOL IsRunning( ) const;

	private:
		SDL_GLContext	m_GLContext;
		SDL_Window		*m_pWindow;
		LD_BOOL			m_Running;
	};
}

#endif // __LD_RENDERER_HPP__

