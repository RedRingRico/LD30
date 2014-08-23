#ifndef __LD_MEMORY_HPP__
#define __LD_MEMORY_HPP__

#include <DataTypes.hpp>

namespace LD
{
#define SafeDelete( p ) \
	{ if( p ) { delete p; p = LD_NULL; } }
}

#endif // __LD_MEMORY_HPP__

