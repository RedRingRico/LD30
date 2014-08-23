// Only GCC is being considered for the build, any 64-bit or 32-bit differences
// will also be handled in this one header
#ifndef __LD_DATATYPES_HPP__
#define __LD_DATATYPES_HPP__

#include <stdint.h>

typedef int32_t		LD_SINT32;
typedef uint32_t	LD_UINT32;

const LD_UINT32 LD_OK	= 0x00000000;
const LD_UINT32 LD_FAIL	= 0x7FFFFFFF;

#endif

