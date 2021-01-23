/***************************************************
 *       _   _            _                        *
 *      | | | |          (_)                       *
 *      | |_| | ___  _ __ _ _______  _ __          *
 *      |  _  |/ _ \| '__| |_  / _ \| '_  \        *
 *      | | | | (_) | |  | |/ / (_) | | | |        *
 *      \_| |_/\___/|_|  |_/___\___/|_| |_|        *
 ***************************************************
 * This file is part of Horizon (c).
 * Copyright (c) 2020- Horizon Dev Team.
 *
 * Base Author - Sagun Khosla. (sagunxp@gmail.com)
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 **************************************************/

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20161228
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20161228

#include "Core/Multithreading/LockedLookupTable.hpp"

#include "Default.hpp"

#include <utility>

namespace Horizon
{
namespace Zone
{
/**
 * @brief Client Packet Length Table object that stores
 * the packet length of each packet of this client version.
 * Packets with IDs already existent in the database are over-written.
 * The data is stored in a thread-safe lookup table.
 * RAII techinque ensures that the table is populated on instantiation.
 */
class ClientPacketLengthTable : public PacketLengthTable
{
public:
	ClientPacketLengthTable(std::shared_ptr<ZoneSession> s)
	: PacketLengthTable(s)
	{
#define ADD_HPKT(i, j, k) _hpacket_length_table.insert(i, std::make_pair(j, std::make_shared<k>(s)))
#define ADD_TPKT(i, j, k) _tpacket_length_table.insert(i, std::make_pair(j, std::make_shared<k>(s)))
		ADD_HPKT(0x08ad, 36, CZ_ACK_STORE_PASSWORD);
		ADD_HPKT(0x091c, 26, CZ_ADD_FRIENDS);
		ADD_HPKT(0x0871, 5, CZ_CHANGE_DIRECTION);
		ADD_HPKT(0x085e, 5, CZ_COMMAND_MER);
		ADD_HPKT(0x086d, 19, CZ_ENTER);
		ADD_HPKT(0x0938, 4, CZ_GANGSI_RANK);
		ADD_HPKT(0x0889, -1, CZ_ITEMLISTWIN_RES);
		ADD_HPKT(0x086c, 6, CZ_ITEM_PICKUP);
		ADD_HPKT(0x0893, 6, CZ_ITEM_THROW);
		ADD_HPKT(0x0935, 8, CZ_JOIN_BATTLE_FIELD);
		ADD_HPKT(0x089f, 8, CZ_MOVE_ITEM_FROM_BODY_TO_STORE);
		ADD_HPKT(0x08ab, 8, CZ_MOVE_ITEM_FROM_STORE_TO_BODY);
		ADD_HPKT(0x08a5, 18, CZ_PARTY_BOOKING_REQ_REGISTER);
		ADD_HPKT(0x0934, 26, CZ_PARTY_JOIN_REQ);
		ADD_HPKT(0x085a, 6, CZ_REQNAME);
		ADD_HPKT(0x08ac, 6, CZ_REQNAME_BYGID);
		ADD_HPKT(0x093d, 7, CZ_REQUEST_ACT);
		ADD_HPKT(0x0886, 5, CZ_REQUEST_MOVE);
		ADD_HPKT(0x0944, 6, CZ_REQUEST_TIME);
		ADD_HPKT(0x08a3, 6, CZ_REQ_CLICK_TO_BUYING_STORE);
		ADD_HPKT(0x0875, 2, CZ_REQ_CLOSE_BUYING_STORE);
		ADD_HPKT(0x086a, -1, CZ_REQ_OPEN_BUYING_STORE);
		ADD_HPKT(0x0362, -1, CZ_REQ_TRADE_BUYING_STORE);
		ADD_HPKT(0x0870, -1, CZ_SEARCH_STORE_INFO);
		ADD_HPKT(0x092c, 2, CZ_SEARCH_STORE_INFO_NEXT_PAGE);
		ADD_HPKT(0x087f, 12, CZ_SSILIST_ITEM_CLICK);
		ADD_HPKT(0x08a2, 10, CZ_USE_SKILL);
		ADD_HPKT(0x0929, 10, CZ_USE_SKILL_TOGROUND);
		ADD_HPKT(0x0865, 90, CZ_USE_SKILL_TOGROUND_WITHTALKBOX);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20161228 */