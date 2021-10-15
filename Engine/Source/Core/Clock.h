#pragma once

#include <cstdint>

namespace slate
{
	/// <summary>
	/// The class interfacing with the system clock
	/// </summary>
	class Clock
	{
	public:
		/// Returns elapsed time in ticks since base time
		inline uint64_t now() const { return counter() - baseCount_; }

		/// Returns current value of the counter
		uint64_t counter() const;
		
		/// Returns the counter frequency in counts per second
		inline uint32_t frequency() const { return frequency_; }
		/// Returns the counter value at initialization time
		inline uint64_t baseCount() const { return baseCount_; }
		
	private:
#if defined(SLATE_PLATFORM_WINDOWS)
		bool hasPerfCounter_ = false;
#endif
		bool hasMonotonicClock_ = false;

		/// Counter frequency in counts per second
		uint32_t frequency_;
		/// Counter value at initialization time
		uint64_t baseCount_;

		/// Private constructor
		Clock();

		friend Clock &clock();
	};

	/// Meyer's Singleton
	extern Clock &clock();
}