/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2019 Horizon Dev Team.
 *
 * Base Author - Sagun Khosla <sagunxp@gmail.com>
 *
 * Under a proprietary license this file is not for use
 * or viewing without permission.
 **************************************************/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "Sol2Test"

#include <boost/test/unit_test.hpp>

#include <sol.hpp>
#include <cstring>
#include <fstream>


BOOST_AUTO_TEST_CASE(Sol2Test)
{
	sol::state lua;
	lua.open_libraries(sol::lib::base, sol::lib::coroutine);
	lua.script(R"(
			   abc = 123;
			   function loop()
			       local counter = 0;
				   while counter < 30
				   do
					   coroutine.yield(counter);
					   counter = counter + 1;
				   end
				   return counter
			   end
			   )");

	sol::coroutine cr = lua["loop"];
	sol::object abc = lua["abc"];

	std::cout << "abc:" << abc.as<uint32_t>() << std::endl;

	for (int counter = 0; // start from 0
		 counter < 50 && cr; // we want 10 values, and we only want to run if the coroutine "cr" is valid
		 // Alternative: counter < 10 && cr.valid()
		 ++counter) {
		// Call the coroutine, does the computation and then suspends
		int value = cr();
		std::cout << value << std::endl;
	}

	while(true);
}
