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
 * Base Author - Sagun Khosla. (sagunxp@gmail.com)
 *
 * Under a proprietary license this file is not for use
 * or viewing without permission.
 **************************************************/

#include "PacketHandlerRagexe20180704.hpp"

using namespace Horizon::Auth;
PacketHandlerRagexe20180704::PacketHandlerRagexe20180704(std::shared_ptr<AuthSocket> socket)
: PacketHandlerRagexe20171213(socket)
{
	initialize_handlers();
}

PacketHandlerRagexe20180704::~PacketHandlerRagexe20180704()
{
	//
}

void PacketHandlerRagexe20180704::initialize_handlers()
{
	PacketHandler::initialize_handlers();

#define HANDLER_FUNC(packet) add_packet_handler(Ragexe20180704::packets::packet, boost::bind(&PacketHandlerRagexe20180704::Handle_ ## packet, this, boost::placeholders::_1));
#undef HANDLER_FUNC
}