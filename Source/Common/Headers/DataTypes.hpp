// Only GCC is being considered for the build, any 64-bit or 32-bit differences
// will also be handled in this one header
#ifndef __LD_DATATYPES_HPP__
#define __LD_DATATYPES_HPP__

#include <stdint.h>
#include <cstddef>

typedef char			LD_SCHAR8;
typedef unsigned char	LD_UCHAR8;
typedef int32_t			LD_SINT32;
typedef uint32_t		LD_UINT32;
typedef int64_t			LD_SINT64;
typedef uint64_t		LD_UINT64;
typedef float			LD_FLOAT32;
typedef double			LD_FLOAT64;

typedef size_t			LD_MEMSIZE;
typedef LD_UCHAR8		LD_BYTE;
typedef LD_UINT32		LD_BOOL;

#define	LD_NULL nullptr

const LD_UINT32 LD_OK	= 0x00000000;
const LD_UINT32 LD_FAIL	= 0x7FFFFFFF;

const LD_BOOL LD_TRUE	= 1;
const LD_BOOL LD_FALSE	= 0;

#endif

