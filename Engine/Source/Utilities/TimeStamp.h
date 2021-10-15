#pragma once 

#include <cstdint>
#include "common_defines.h"

namespace slate 
{
	/// A class representing a point in time or a duration
	class SLATE_EXPORT TimeStamp
	{
	public:
		TimeStamp();

		/// Returns a new time stamp initialized now
		inline static TimeStamp now() { return TimeStamp(); }

		bool operator>(const TimeStamp& other) const;
		bool operator<(const TimeStamp& other) const;
		TimeStamp& operator+=(const TimeStamp& other);
		TimeStamp& operator-=(const TimeStamp& other);
		TimeStamp operator+(const TimeStamp& other) const;
		TimeStamp operator-(const TimeStamp& other) const;

		/// Returns a new time stamp with the time elapsed since this one
		TimeStamp timeSince() const;

		/// Returns the time elapsed since the timestamp, as seconds in a `float` number
		float secondsSince() const;
		/// Returns the time elapsed since the timestamp, as seconds in a `double` number
		double secondsDoubleSince() const;

		/// Returns the time elapsed since the timestamp, as milliseconds in a `float` number
		float millisecondsSince() const;
		/// Returns the time elapsed since the timestamp, as milliseconds in a `double` number
		double millisecondsDoubleSince() const;

		/// Returns the time elapsed since the timestamp, as microseconds in a `float` number
		float microsecondsSince() const;
		/// Returns the time elapsed since the timestamp, as microseconds in a `double` number
		double microsecondsDoubleSince() const;

		/// Returns the time elapsed since the timestamp, as seconds in a `nanoseconds` number
		float nanosecondsSince() const;
		/// Returns the time elapsed since the timestamp, as seconds in a `nanoseconds` number
		double nanosecondsDoubleSince() const;

		inline uint64_t ticks() const { return counter_ ; }

		/// Returns the timestamp counter value as seconds in a `float` number
		float seconds() const;
		/// Returns the timestamp counter value as seconds in a `double` number
		double secondsDouble() const;

		/// Returns the timestamp counter value as milliseconds in a `float` number
		float milliseconds() const;
		/// Returns the timestamp counter value as milliseconds in a `double` number
		double millisecondsDouble() const;

		/// Returns the timestamp counter value as microseconds in a `float` number
		float microseconds() const;
		/// Returns the timestamp counter value as microseconds in a `double` number
		double microsecondsDouble() const;

		/// Returns the timestamp counter value as nanoseconds in a `float` number
		float nanoseconds() const;
		/// Returns the timestamp counter value as nanoseconds in a `double` number
		double nanosecondsDouble() const;

	private:
		uint64_t counter_;

		explicit TimeStamp(uint64_t counter)
			: counter_(counter) {}
	};
}

