#include <Renderer.hpp>
#include <iostream>

namespace LD
{
	Renderer::Renderer( ) :
		m_GLContext( LD_NULL ),
		m_pWindow( LD_NULL ),
		m_Running( LD_FALSE )
	{
	}

	Renderer::~Renderer( )
	{
		SDL_DestroyWindow( m_pWindow );
	}

	LD_UINT32 Renderer::Initialise( const RENDER_PARAMETERS &p_Parameters )
	{
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 2 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE );
		
		m_pWindow = SDL_CreateWindow( "Red Ring Rico's Ludum Dare #30 Entry",
			p_Parameters.X, p_Parameters.Y,
			p_Parameters.Width, p_Parameters.Height,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );

		if( m_pWindow == LD_NULL )
		{
			std::cout << "Failed to create the window" << std::endl;
			return LD_FAIL;
		}

		m_GLContext = SDL_GL_CreateContext( m_pWindow );

		if( m_GLContext == LD_NULL )
		{
			std::cout << "Failed to create the OpenGL context" << std::endl;
			return LD_FAIL;
		}

		glewExperimental = GL_TRUE;

		GLenum GLEWError = glewInit( );
		
		if( GLEWError != GLEW_OK )
		{
			std::cout << "Failed to initialise GLEW" << std::endl;
			return LD_FAIL;
		}

		if( SDL_GL_SetSwapInterval( 1 ) < 0 )
		{
			std::cout << "Unable to set V-Sync" << std::endl;
		}

		glClearColor( 0.0f, 1.0f, 0.0f, 1.0f );

		m_Running = LD_TRUE;

		return LD_OK;
	}

	LD_UINT32 Renderer::BeginScene( )
	{
		glClear( GL_COLOR_BUFFER_BIT );

		return LD_OK;
	}

	void Renderer::EndScene( )
	{
		SDL_GL_SwapWindow( m_pWindow );
	}

	void Renderer::HandleWindowEvents( )
	{
		SDL_Event Event;

		while( SDL_PollEvent( &Event ) != 0 )
		{
			switch( Event.type )
			{
				case SDL_QUIT:
				{
					m_Running = LD_FALSE;
					break;
				}
			}
		}
	}

	void Renderer::SetClearColour( LD_FLOAT32 p_Red, LD_FLOAT32 p_Green,
		LD_FLOAT32 p_Blue )
	{
		glClearColor( p_Red, p_Green, p_Blue, 1.0f );
	}

	LD_BOOL Renderer::IsRunning( ) const
	{
		return m_Running;
	}
}

