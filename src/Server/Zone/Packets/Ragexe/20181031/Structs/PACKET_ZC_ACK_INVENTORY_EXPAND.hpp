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

#ifndef HORIZON_ZONE_RAGEXE_20181031_PACKET_ZC_ACK_INVENTORY_EXPAND_HPP
#define HORIZON_ZONE_RAGEXE_20181031_PACKET_ZC_ACK_INVENTORY_EXPAND_HPP

#include "Server/Zone/Packets/Ragexe/20181031/PacketsRagexe20181031.hpp"
#include "Server/Zone/Packets/Ragexe/Structs/PACKET_ZC_ACK_INVENTORY_EXPAND.hpp"

#include "Server/Common/PacketBuffer.hpp"


namespace Horizon
{
namespace Zone
{
namespace Ragexe20181031
{
struct PACKET_ZC_ACK_INVENTORY_EXPAND : public Horizon::Zone::Ragexe::PACKET_ZC_ACK_INVENTORY_EXPAND
{
	PACKET_ZC_ACK_INVENTORY_EXPAND(uint16_t packet_id = ZC_ACK_INVENTORY_EXPAND) : Horizon::Zone::Ragexe::PACKET_ZC_ACK_INVENTORY_EXPAND(packet_id) { }

	/* Size: 7 bytes */
};
}
}
}

#endif /* HORIZON_ZONE_RAGEXE_20181031_PACKET_ZC_ACK_INVENTORY_EXPAND_HPP */