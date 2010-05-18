#ifndef RDESTL_COMMON_H
#define RDESTL_COMMON_H

#ifndef RDESTL_STANDALONE
#	define RDESTL_STANDALONE	1
#endif

#if RDESTL_STANDALONE
#  ifdef _MSC_VER
#	include <cassert>
#	include <cstring>
#  else
#   include <assert.h>
#   include <cstdlib>
#   include <cstring>
#  endif
#	define RDE_ASSERT		assert
// @note; __forceinline for MSVC!
#	define RDE_FORCEINLINE	inline
#	ifdef _DEBUG
#		undef RDE_DEBUG
#		define RDE_DEBUG	1
#	endif
	namespace rde 
	{ 
		// # Meh. MSVC doesnt seem to have <stdint.h>
		// @todo	Fixes to make this portable.
		typedef unsigned char		uint8;
		typedef unsigned short		uint16;
		typedef signed long			int32;
		typedef unsigned long		uint32;
        #ifdef _MSC_VER
		typedef unsigned __int64	uint64;
        #else
        typedef unsigned long long	uint64;
        #endif
		namespace Sys 
		{
			RDE_FORCEINLINE void MemCpy(void* to, const void* from, size_t bytes)
			{
				memcpy(to, from, bytes);
			}
			RDE_FORCEINLINE void MemMove(void* to, const void* from, size_t bytes)
			{
				memmove(to, from, bytes);
			}
			RDE_FORCEINLINE void MemSet(void* buf, unsigned char value, size_t bytes)
			{
				memset(buf, value, bytes);
			}
		} // sys
	}
#else
#	include "core/RdeAssert.h"
#	include "core/System.h"
#endif

namespace rde
{
enum e_noinitialize
{
	noinitialize
};
}

#endif // #ifndef RDESTL_H