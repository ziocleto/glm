///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2013 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glm/core/setup.hpp
/// @date 2006-11-13 / 2013-03-30
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#ifndef GLM_SETUP_INCLUDED
#define GLM_SETUP_INCLUDED

#include <cassert>

///////////////////////////////////////////////////////////////////////////////////////////////////
// Version

#define GLM_VERSION					200
#define GLM_VERSION_MAJOR			2
#define GLM_VERSION_MINOR			0
#define GLM_VERSION_PATCH			0
#define GLM_VERSION_REVISION		0

///////////////////////////////////////////////////////////////////////////////////////////////////
// Platform

#define GLM_PLATFORM_UNKNOWN		0x00000000
#define GLM_PLATFORM_WINDOWS		0x00010000
#define GLM_PLATFORM_LINUX			0x00020000
#define GLM_PLATFORM_APPLE			0x00040000
//#define GLM_PLATFORM_IOS			0x00080000
#define GLM_PLATFORM_ANDROID		0x00100000
#define GLM_PLATFORM_CHROME_NACL	0x00200000
#define GLM_PLATFORM_UNIX			0x00400000
#define GLM_PLATFORM_QNXNTO			0x00800000

#ifdef GLM_FORCE_PLATFORM_UNKNOWN
#	define GLM_PLATFORM GLM_PLATFORM_UNKNOWN
#elif defined(__QNXNTO__)
#	define GLM_PLATFORM GLM_PLATFORM_QNXNTO
#elif defined(__APPLE__)
#	define GLM_PLATFORM GLM_PLATFORM_APPLE
#elif defined(_WIN32)
#	define GLM_PLATFORM GLM_PLATFORM_WINDOWS
#elif defined(__native_client__)
#	define GLM_PLATFORM GLM_PLATFORM_CHROME_NACL
#elif defined(__ANDROID__)
#	define GLM_PLATFORM GLM_PLATFORM_ANDROID
#elif defined(__linux)
#	define GLM_PLATFORM GLM_PLATFORM_LINUX
#elif defined(__unix)
#	define GLM_PLATFORM GLM_PLATFORM_UNIX
#else
#	define GLM_PLATFORM GLM_PLATFORM_UNKNOWN
#endif//

// Report platform detection
#if(defined(GLM_MESSAGES) && !defined(GLM_MESSAGE_PLATFORM_DISPLAYED))
#	define GLM_MESSAGE_PLATFORM_DISPLAYED
#	if(GLM_PLATFORM & GLM_PLATFORM_WINDOWS)
#		pragma message("GLM: Windows platform detected")
//#	elif(GLM_PLATFORM & GLM_PLATFORM_IOS)
//#		pragma message("GLM: iOS platform detected")
#	elif(GLM_PLATFORM & GLM_PLATFORM_APPLE)
#		pragma message("GLM: Apple platform detected")
#	elif(GLM_PLATFORM & GLM_PLATFORM_LINUX)
#		pragma message("GLM: Linux platform detected")
#	elif(GLM_PLATFORM & GLM_PLATFORM_UNIX)
#		pragma message("GLM: UNIX platform detected")
#	elif(GLM_PLATFORM & GLM_PLATFORM_ANDROID)
#		pragma message("GLM: Android platform detected")
#	elif(GLM_PLATFORM & GLM_PLATFORM_CHROME_NACL)
#		pragma message("GLM: Chrone Native Client detected")
#	elif(GLM_PLATFORM & GLM_PLATFORM_UNKNOWN)
#		pragma message("GLM: platform unknown")
#	else
#		pragma message("GLM: platform not detected")
#	endif
#endif//GLM_MESSAGE

///////////////////////////////////////////////////////////////////////////////////////////////////
// Compiler

// Build model
#define GLM_MODEL_32				0x00000010
#define GLM_MODEL_64				0x00000020

// CUDA
#elif defined(__CUDACC__)
#	define GLM_COMPILER GLM_COMPILER_CUDA
/*
#	if CUDA_VERSION < 3000
#		error "GLM requires CUDA 3.0 or higher"
#	elif CUDA_VERSION == 3000
#		define GLM_COMPILER GLM_COMPILER_CUDA30	
#	elif CUDA_VERSION == 3010
#		define GLM_COMPILER GLM_COMPILER_CUDA31	
#	elif CUDA_VERSION == 3020
#		define GLM_COMPILER GLM_COMPILER_CUDA32	
#	elif CUDA_VERSION == 4000
#		define GLM_COMPILER GLM_COMPILER_CUDA40	
#	elif CUDA_VERSION == 4010
#		define GLM_COMPILER GLM_COMPILER_CUDA41	
#	elif CUDA_VERSION == 4020
#		define GLM_COMPILER GLM_COMPILER_CUDA42
#	else
#		define GLM_COMPILER GLM_COMPILER_CUDA
#	endif
*/

/////////////////
// Platform 

// User defines: GLM_FORCE_PURE GLM_FORCE_SSE2 GLM_FORCE_AVX

#define GLM_ARCH_PURE		0x0000
#define GLM_ARCH_SSE2		0x0001
#define GLM_ARCH_SSE3		0x0002// | GLM_ARCH_SSE2
#define GLM_ARCH_SSE4		0x0004// | GLM_ARCH_SSE3 | GLM_ARCH_SSE2
#define GLM_ARCH_AVX		0x0008// | GLM_ARCH_SSE4 | GLM_ARCH_SSE3 | GLM_ARCH_SSE2
#define GLM_ARCH_AVX2		0x0010// | GLM_ARCH_AVX | GLM_ARCH_SSE4 | GLM_ARCH_SSE3 | GLM_ARCH_SSE2

#if(defined(GLM_FORCE_PURE))
#	define GLM_ARCH GLM_ARCH_PURE
#elif(defined(GLM_FORCE_AVX2))
#	define GLM_ARCH (GLM_ARCH_AVX2 | GLM_ARCH_AVX | GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#elif(defined(GLM_FORCE_AVX))
#	define GLM_ARCH (GLM_ARCH_AVX | GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#elif(defined(GLM_FORCE_SSE4))
#	define GLM_ARCH (GLM_ARCH_SSE4 | GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#elif(defined(GLM_FORCE_SSE3))
#	define GLM_ARCH (GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#elif(defined(GLM_FORCE_SSE2))
#	define GLM_ARCH (GLM_ARCH_SSE2)
#elif((GLM_COMPILER & GLM_COMPILER_VC) && (defined(_M_IX86) || defined(_M_X64)))
#	if(defined(_M_CEE_PURE))
#		define GLM_ARCH GLM_ARCH_PURE
/* TODO: Explore auto detection of instruction set support
#	elif(defined(_M_IX86_FP))
#		if(_M_IX86_FP >= 3)
#			define GLM_ARCH (GLM_ARCH_AVX | GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#		elif(_M_IX86_FP >= 2)
#			define GLM_ARCH (GLM_ARCH_SSE2)
#		else
#			define GLM_ARCH GLM_ARCH_PURE
#		endif
*/
#	elif(GLM_COMPILER >= GLM_COMPILER_VC2012)
#		define GLM_ARCH (GLM_ARCH_AVX | GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#	elif(GLM_COMPILER >= GLM_COMPILER_VC2010)
#		if(_MSC_FULL_VER >= 160031118) //160031118: VC2010 SP1 beta full version
#			define GLM_ARCH (GLM_ARCH_AVX | GLM_ARCH_SSE3 | GLM_ARCH_SSE2)//GLM_ARCH_AVX (Require SP1)
#		else
#			define GLM_ARCH (GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#		endif
#	elif(GLM_COMPILER >= GLM_COMPILER_VC2008) 
#		define GLM_ARCH (GLM_ARCH_SSE3 | GLM_ARCH_SSE2)
#	elif(GLM_COMPILER >= GLM_COMPILER_VC2005)
#		define GLM_ARCH GLM_ARCH_SSE2
#	else
#		define GLM_ARCH GLM_ARCH_PURE
#	endif
#elif((GLM_PLATFORM & GLM_PLATFORM_APPLE) && (GLM_COMPILER & GLM_COMPILER_GCC))
#	define GLM_ARCH GLM_ARCH_PURE
#elif(((GLM_COMPILER & GLM_COMPILER_GCC) && (defined(__i386__) || defined(__x86_64__))) || (GLM_COMPILER & GLM_COMPILER_LLVM_GCC))
#	define GLM_ARCH (GLM_ARCH_PURE \
| (defined(__AVX2__) ? GLM_ARCH_AVX2 : 0) \
| (defined(__AVX__) ? GLM_ARCH_AVX : 0) \
| (defined(__SSE4__) ? GLM_ARCH_SSE4 : 0) \
| (defined(__SSE3__) ? GLM_ARCH_SSE3 : 0) \
| (defined(__SSE2__) ? GLM_ARCH_SSE2 : 0))
#else
#	define GLM_ARCH GLM_ARCH_PURE
#endif

// With MinGW-W64, including intrinsic headers before intrin.h will produce some errors. The problem is
// that windows.h (and maybe other headers) will silently include intrin.h, which of course causes problems.
// To fix, we just explicitly include intrin.h here.
#if defined(__MINGW32__) && (GLM_ARCH != GLM_ARCH_PURE)
#	include <intrin.h>
#endif

//#if(GLM_ARCH != GLM_ARCH_PURE)
#if(GLM_ARCH & GLM_ARCH_AVX2)
#	include <immintrin.h>
#endif//GLM_ARCH
#if(GLM_ARCH & GLM_ARCH_AVX)
#	include <immintrin.h>
#endif//GLM_ARCH
#if(GLM_ARCH & GLM_ARCH_SSE4)
#	include <smmintrin.h>
#endif//GLM_ARCH
#if(GLM_ARCH & GLM_ARCH_SSE3)
#	include <pmmintrin.h>
#endif//GLM_ARCH
#if(GLM_ARCH & GLM_ARCH_SSE2)
#	include <emmintrin.h>
#endif//GLM_ARCH
//#endif//(GLM_ARCH != GLM_ARCH_PURE)

#if(defined(GLM_MESSAGES) && !defined(GLM_MESSAGE_ARCH_DISPLAYED))
#	define GLM_MESSAGE_ARCH_DISPLAYED
#	if(GLM_ARCH == GLM_ARCH_PURE)
#		pragma message("GLM: Platform independent")
#	elif(GLM_ARCH & GLM_ARCH_SSE2)
#		pragma message("GLM: SSE2 instruction set")
#	elif(GLM_ARCH & GLM_ARCH_SSE3)
#		pragma message("GLM: SSE3 instruction set")
#	elif(GLM_ARCH & GLM_ARCH_SSE4)
#		pragma message("GLM: SSE4 instruction set")
#	elif(GLM_ARCH & GLM_ARCH_AVX)
#		pragma message("GLM: AVX instruction set")
#	elif(GLM_ARCH & GLM_ARCH_AVX2)
#		pragma message("GLM: AVX2 instruction set")
#	endif//GLM_ARCH
#endif//GLM_MESSAGE

///////////////////////////////////////////////////////////////////////////////////////////////////
// Radians

//#define GLM_FORCE_RADIANS

///////////////////////////////////////////////////////////////////////////////////////////////////
// Qualifiers 

// User defines: GLM_FORCE_INLINE GLM_FORCE_CUDA

#if(defined(GLM_FORCE_CUDA) || (GLM_COMPILER & GLM_COMPILER_CUDA))
#	define GLM_CUDA_FUNC_DEF __device__ __host__ 
#	define GLM_CUDA_FUNC_DECL __device__ __host__ 
#else
#	define GLM_CUDA_FUNC_DEF
#	define GLM_CUDA_FUNC_DECL
#endif

#if GLM_COMPILER & GLM_COMPILER_GCC
#	define GLM_VAR_USED __attribute__ ((unused))
#else
#	define GLM_VAR_USED
#endif

#if(defined(GLM_FORCE_INLINE))
#	if((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_COMPILER >= GLM_COMPILER_VC2005))
#		define GLM_INLINE __forceinline
#	elif((GLM_COMPILER & GLM_COMPILER_GCC) && (GLM_COMPILER >= GLM_COMPILER_GCC34))
#		define GLM_INLINE __attribute__((always_inline))
#	elif(GLM_COMPILER & GLM_COMPILER_CLANG)
#		define GLM_INLINE __attribute__((always_inline))
#	else
#		define GLM_INLINE inline
#	endif//GLM_COMPILER
#else
#	define GLM_INLINE inline
#endif//defined(GLM_FORCE_INLINE)

#define GLM_FUNC_DECL GLM_CUDA_FUNC_DECL
#define GLM_FUNC_QUALIFIER GLM_CUDA_FUNC_DEF GLM_INLINE

///////////////////////////////////////////////////////////////////////////////////////////////////
// Qualifiers

#if((GLM_COMPILER & GLM_COMPILER_VC) && (GLM_COMPILER >= GLM_COMPILER_VC2005))
#	define GLM_DEPRECATED __declspec(deprecated)
#	define GLM_ALIGN(x) __declspec(align(x))
#	define GLM_ALIGNED_STRUCT(x) __declspec(align(x)) struct
#	define GLM_RESTRICT __declspec(restrict)
#	define GLM_RESTRICT_VAR __restrict
#	define GLM_CONSTEXPR
#elif(GLM_COMPILER & GLM_COMPILER_INTEL)
#	define GLM_DEPRECATED
#	define GLM_ALIGN(x) __declspec(align(x))
#	define GLM_ALIGNED_STRUCT(x) __declspec(align(x)) struct
#	define GLM_RESTRICT
#	define GLM_RESTRICT_VAR __restrict
#	define GLM_CONSTEXPR
#elif(((GLM_COMPILER & (GLM_COMPILER_GCC | GLM_COMPILER_LLVM_GCC)) && (GLM_COMPILER >= GLM_COMPILER_GCC31)) || (GLM_COMPILER & GLM_COMPILER_CLANG))
#	define GLM_DEPRECATED __attribute__((__deprecated__))
#	define GLM_ALIGN(x) __attribute__((aligned(x)))
#	define GLM_ALIGNED_STRUCT(x) struct __attribute__((aligned(x)))
#	if(GLM_COMPILER >= GLM_COMPILER_GCC33)
#		define GLM_RESTRICT __restrict__
#		define GLM_RESTRICT_VAR __restrict__
#	else
#		define GLM_RESTRICT
#		define GLM_RESTRICT_VAR
#	endif
#	define GLM_RESTRICT __restrict__
#	define GLM_RESTRICT_VAR __restrict__
#	if((GLM_COMPILER >= GLM_COMPILER_GCC47) && ((GLM_LANG & GLM_LANG_CXX0X) == GLM_LANG_CXX0X))
#		define GLM_CONSTEXPR constexpr
#	else
#		define GLM_CONSTEXPR
#	endif
#else
#	define GLM_DEPRECATED
#	define GLM_ALIGN
#	define GLM_ALIGNED_STRUCT(x)
#	define GLM_RESTRICT
#	define GLM_RESTRICT_VAR
#	define GLM_CONSTEXPR
#endif//GLM_COMPILER

#endif//GLM_SETUP_INCLUDED
