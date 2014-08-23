#include <GameStateManager.hpp>
#include <GameState.hpp>
#include <Renderer.hpp>
#include <iostream>
#include <cstring>

namespace LD
{
	GameStateManager::GameStateManager( ) :
		m_Running( LD_FALSE )
	{
	}

	GameStateManager::~GameStateManager( )
	{
		this->Quit( );
	}

	LD_UINT32 GameStateManager::RegisterState( GameState *p_pGameState )
	{
		if( p_pGameState == LD_NULL )
		{
			return LD_FAIL;
		}

		GameStateRegistry::const_iterator RegistryItr =
			m_GameStateRegistry.begin( );

		while( RegistryItr != m_GameStateRegistry.end( ) )
		{
			if( strncmp( ( *RegistryItr )->GetName( ),
				p_pGameState->GetName( ),
				strlen( p_pGameState->GetName( ) ) ) == 0 )
			{
				return LD_OK;
			}

			++RegistryItr;
		}

		m_GameStateRegistry.insert( p_pGameState );

		return LD_OK;
	}

	LD_UINT32 GameStateManager::PushState( const LD_SCHAR8 *p_pStateName )
	{
		LD_MEMSIZE Index;
		if( this->IsStateNameValid( p_pStateName, &Index ) == LD_FALSE )
		{
			return LD_FAIL;
		}

		GameStateRegistry::const_iterator RegistryItr =
			m_GameStateRegistry.begin( );

		for( LD_MEMSIZE i = 0; i < Index; ++i )
		{
			if( strncmp( ( *RegistryItr )->GetName( ), p_pStateName,
				strlen( p_pStateName ) ) == 0 )
			{
				break;
			}
			++RegistryItr;
		}

		m_GameStateStack.push( ( *RegistryItr ) );

		if( m_GameStateStack.top( )->Enter( ) != LD_OK )
		{
			std::cout << "Failed to enter state " << p_pStateName << std::endl;
			this->PopState( );
			return LD_FAIL;
		}

		m_Running = LD_TRUE;
		
		return LD_OK;
	}

	LD_UINT32 GameStateManager::PopState( )
	{
		if( m_GameStateStack.empty( ) )
		{
			return LD_FAIL;
		}

		m_GameStateStack.top( )->Exit( );
		m_GameStateStack.pop( );

		return LD_OK;
	}

	LD_UINT32 GameStateManager::Execute( )
	{
		if( m_GameStateStack.empty( ) )
		{
			return LD_FAIL;
		}

		m_pRenderer->HandleWindowEvents( );

		if( m_pRenderer->IsRunning( ) == LD_FALSE )
		{
			this->Quit( );
			return LD_OK;
		}

		m_GameStateStack.top( )->Update( 0ULL );

		m_pRenderer->BeginScene( );
		m_GameStateStack.top( )->Render( );
		m_pRenderer->EndScene( );

		if( m_GameStateStack.top( )->IsRunning( ) == LD_FALSE )
		{
			this->PopState( );
			return LD_OK;
		}

		return LD_OK;
	}

	void GameStateManager::Quit( )
	{
		while( !m_GameStateStack.empty( ) )
		{
			this->PopState( );
		}

		m_Running = LD_FALSE;
	}

	LD_BOOL GameStateManager::IsRunning( ) const
	{
		return m_Running;
	}

	LD_UINT32 GameStateManager::SetRenderer( Renderer *p_pRenderer )
	{
		m_pRenderer = p_pRenderer;
	}

	Renderer *GameStateManager::GetRenderer( )
	{
		return m_pRenderer;
	}

	GameStateManager &GameStateManager::GetInstance( )
	{
		static GameStateManager Instance;
		return Instance;
	}

	LD_BOOL GameStateManager::IsStateNameValid(
		const LD_SCHAR8 *p_pStateName, LD_MEMSIZE *p_pIndex ) const
	{
		if( p_pStateName == LD_NULL )
		{
			return LD_FALSE;
		}

		GameStateRegistry::const_iterator RegistryItr =
			m_GameStateRegistry.begin( );
		LD_MEMSIZE Index = 0;

		while( RegistryItr != m_GameStateRegistry.end( ) )
		{
			if( strncmp( ( *RegistryItr )->GetName( ), p_pStateName,
				strlen( p_pStateName ) ) == 0 )
			{
				if( p_pIndex != LD_NULL )
				{
					( *p_pIndex ) = Index;
				}
				return LD_TRUE;
			}
			++Index;
			++RegistryItr;
		}

		return LD_FALSE;
	}
}

