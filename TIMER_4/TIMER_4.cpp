// TIMER_4.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


class printer
{
	boost::asio::deadline_timer timer_;
	int count_;

public:
	printer(boost::asio::io_service& io)
		: timer_(io, boost::posix_time::seconds(1)), count_(0)
	{
		timer_.async_wait(boost::bind(&printer::print, this));
	}

	~printer()
	{
		std::cout << "Final count is " << count_ << "\n";
	}

	void print()
	{
		if (count_ < 5)
		{
			std::cout << count_ << "\n";
			++count_;

			timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
			timer_.async_wait(boost::bind(&printer::print, this));
		}
	}
};

int main()
{
	boost::asio::io_service io;
	printer p(io);
	io.run();

    return 0;
}

