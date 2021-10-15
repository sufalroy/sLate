#include "Precompiled.h"
#include "Clock.h"

#if defined(SLATE_PLATFORM_WINDOWS)
	#include <winsync.h>
	#include <profileapi.h>
#else
	#include <time.h> // for clock_gettime()
	#include <sys/time.h> // for gettimeofday()
#endif

namespace slate
{
	Clock &clock()
	{
		static Clock instance;
		return instance;
	}
	 
	Clock::Clock()
		: frequency_(0UL), baseCount_(0ULL)
	{
#if defined(SLATE_PLATFORM_WINDOWS)
		if(QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&frequency_)))
			hasPerfCounter_ = true;
		else
			frequency_ = 1000L;
#else
		struct timespec resolution;
		if(clock_getres(CLOCK_MONOTONIC, &resolution) == 0)
		{
			frequency_ = 1.0e9L;
			hasMonotonicClock_ = true;
		}
		else
			frequency_ = 1.0e6L;
#endif
		baseCount_ = counter();
	}

	uint64_t Clock::counter() const
	{
		uint64_t counter = 0LL;

#if defined(SLATE_PLATFORM_WINDOWS)
		if(hasPerfCounter_)
			QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER *>(&counter));
		else
			counter = GetTickCount64();
#else
		if(hasMonotonicClock_)
		{
			struct timespec now;
			clock_gettime(CLOCK_MONOTONIC, &now);
			counter = static_cast<uint64_t>(now.tv_sec) * frequency_ + static_cast<uint64_t>(now.tv_nsec);
		}
		else
		{
			struct timeval now;
			gettimeofday(&now, nullptr);
			counter = static_cast<uint64_t>(now.tv_sec) * frequency_ + static_cast<uint64_t>(now.tv_usec);
		}
#endif
		return counter;
	}
}
