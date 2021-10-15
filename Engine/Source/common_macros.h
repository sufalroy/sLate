#pragma once

#include <cstdlib> // for abort()

#ifdef SLATE_DEBUG
	#define SLATE_ASSERT_BREAK
#endif

#ifdef __GNUC__
	#define FUNCTION __PRETTY_FUNCTION__
#elif _MSC_VER
	#define FUNCTION __FUNCTION__
#else
	#define FUNCTION __func__
#endif

#ifdef SLATE_ASSERT_BREAK
	#ifdef _MSC_VER
		#define BREAK() __debugbreak()
	#else
		#ifndef __has_builtin
			#define __has_builtin(x) 0
		#endif

		#if __has_builtin(__builtin_trap)
			#define BREAK() __builtin_trap()
		#else
			#define BREAK() ::abort()
		#endif
	#endif
#else
	#define BREAK() ::exit(EXIT_FAILURE)
#endif

// Fatal assert macros
#define FATAL_ASSERT_MSG_X(x, fmt, ...) \
	do \
	{ \
		if(!(x)) \
		{ \
			LOGF_X(fmt, ##__VA_ARGS__); \
			BREAK(); \
		} \
	} while (false)

#define FATAL_ASSERT_MSG(x, fmt) \
	do \
	{ \
		if(!(x)) \
		{ \
			LOGF(fmt); \
			BREAK(); \
		} \
 	} while(false)

#define FATAL_ASSERT(x) \
	do \
	{ \
		if(!(x)) \
		{ \
			LOGF("FATAL_ASSERT(" #x ")"); \
			BREAK(); \
		} \
	} while(false)

// Fatal macros
#define FATAL_MSG_X(fmt, ...) \
	do \
	{ \
		LOGF_X(fmt, ##__VA_ARGS__); \
		BREAK(); \
	} while(false)

#define FATAL_MSG(fmt) \
	do \
	{ \
		LOGF(fmt); \
		BREAK(); \
	} while(false)

#define FATAL() \
	do \
	{ \
		BREAK(); \
	} while (false)

// Non-fatal assert macros
#ifdef SLATE_ASSERT_BREAK 
	#define ASSERT_MSG_X(x, fmt, ...) \
		do \
		{ \
			if(!(x)) \
			{ \
				LOGE_X(fmt, ##__VA_ARGS__); \
				BREAK(); \
			} \
		} while(false)

	#define ASSERT_MSG(x, fmt) \
		do \
		{ \
			if(!(x)) \
			{ \
				LOGE(fmt); \
				BREAK(); \
			} \
		} while(false)

	#define ASSERT(x) \
		do \
		{ \
			if(!(x)) \
			{ \
				LOGE("ASSERT(" #x ")"); \
				BREAK(); \
			} \
		} while(false)
#else
	#define ASSERT_MSG_X(x, fmt, ...) \
		do \
		{ \
			(void)sizeof(x); \
		} while (false)
	#define ASSERT_MSG(x, fmt) \
		do \
		{ \
			(void)sizeof(x); \
		} while (false)
	#define ASSERT(x) \
		do \
		{ \
			(void)sizeof(x); \
		} while (false)
#endif