#include "TimeHelper.h"

#include <sstream>
#include "boost/date_time/local_time/local_time.hpp"
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/algorithm/string/replace.hpp>

namespace ops
{
	///Returns the current time as a number of milliseconds since Epoch 1970-01-01.
	__int64 TimeHelper::currentTimeMillis()
    {
		return getEpochTime();
    }
	///Sleeps the given number of milliseconds (millis).
	void TimeHelper::sleep(__int64 millis)
    {
		boost::xtime xt;
		boost::xtime_get(&xt, boost::TIME_UTC);
		
		
		int seconds = (int)(millis / 1000.0);
		xt.sec += seconds;
		int nanos = (int)(((millis/1000.0) - seconds) * 1000000000.0);
		xt.nsec += nanos;

		boost::thread::sleep(xt);
    }
	///Returns current system time as a string to be used as user output, file names etc...
	std::string TimeHelper::getTimeToString()
    {
     	//Get time with seconds resolution		 
		boost::posix_time::ptime p = boost::date_time::second_clock<boost::posix_time::ptime>::local_time();
		
		//Print the time to a string.
		std::stringstream ss;
		ss << p;
		std::string ret = ss.str();
		
		//Replace characters that are illegal in file names.
		boost::algorithm::replace_all(ret, ":", "-");

		return ret;
    }
	///Returns the current time as a number of milliseconds since Epoch 1970-01-01.
	__int64 TimeHelper::getEpochTime()
    {
		using namespace boost::gregorian; 
		using namespace boost::local_time;
		using namespace boost::posix_time;

    	boost::posix_time::ptime time_t_epoch(date(1970,1,1)); 
		boost::posix_time::ptime p = boost::date_time::microsec_clock<boost::posix_time::ptime>::local_time();
		
		time_duration diff = p - time_t_epoch;
		
		return diff.total_milliseconds();

    }






}