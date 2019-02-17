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

#ifndef HORIZON_CHAR_RAGEXE_PACKET_HC_REFUSE_ENTER_HPP
#define HORIZON_CHAR_RAGEXE_PACKET_HC_REFUSE_ENTER_HPP


#include "Server/Char/Packets/Ragexe/Packets.hpp"

#include "Server/Common/PacketBuffer.hpp"


namespace Horizon
{
namespace Char
{
namespace Ragexe
{
struct PACKET_HC_REFUSE_ENTER : public Packet
{
	PACKET_HC_REFUSE_ENTER(uint16_t packet_id = HC_REFUSE_ENTER) : Packet(packet_id) { }

	virtual PacketBuffer serialize()
	{
		PacketBuffer buf(HC_REFUSE_ENTER);
		buf << (uint8_t) error;
		return buf;
	}

	virtual void deserialize(PacketBuffer &/*buf*/) { }

	virtual PACKET_HC_REFUSE_ENTER & operator << (PacketBuffer &right)
	{
		deserialize(right);
		return *this;
	}

	virtual PacketBuffer operator >> (PacketBuffer &right)
	{
		return right = serialize();
	}

	/* Size: 3 bytes */
	character_connect_errors error;
};
}
}
}

#endif /* HORIZON_CHAR_RAGEXE_PACKET_HC_REFUSE_ENTER_HPP */