// TIMER2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


void print(const boost::system::error_code& /*e*/)
{
	std::cout << "Hello, world!\n";
}

int main()
{
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

	t.async_wait(print);

	io.run();

	
    return 0;
}

