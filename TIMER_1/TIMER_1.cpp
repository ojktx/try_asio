// TIMER_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

	t.wait(); // t가 생성된 이후 5초 후 죽는다, == 리턴됨

	std::cout << "Hello, world!\n";

    return 0;
}

