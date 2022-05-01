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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20161012
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20161012


#include "Default.hpp"



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
		ADD_HPKT(0x0967, 36, CZ_ACK_STORE_PASSWORD);
		ADD_HPKT(0x0819, 26, CZ_ADD_FRIENDS);
		ADD_HPKT(0x08a0, 5, CZ_CHANGE_DIRECTION);
		ADD_HPKT(0x095c, 5, CZ_COMMAND_MER);
		ADD_HPKT(0x086d, 19, CZ_ENTER);
		ADD_HPKT(0x085b, 4, CZ_GANGSI_RANK);
		ADD_HPKT(0x0364, -1, CZ_ITEMLISTWIN_RES);
		ADD_HPKT(0x0868, 6, CZ_ITEM_PICKUP);
		ADD_HPKT(0x0362, 6, CZ_ITEM_THROW);
		ADD_HPKT(0x094f, 8, CZ_JOIN_BATTLE_FIELD);
		ADD_HPKT(0x0893, 8, CZ_MOVE_ITEM_FROM_BODY_TO_STORE);
		ADD_HPKT(0x0944, 8, CZ_MOVE_ITEM_FROM_STORE_TO_BODY);
		ADD_HPKT(0x0943, 18, CZ_PARTY_BOOKING_REQ_REGISTER);
		ADD_HPKT(0x0369, 26, CZ_PARTY_JOIN_REQ);
		ADD_HPKT(0x0936, 6, CZ_REQNAME);
		ADD_HPKT(0x092d, 6, CZ_REQNAME_BYGID);
		ADD_HPKT(0x0863, 7, CZ_REQUEST_ACT);
		ADD_HPKT(0x0966, 5, CZ_REQUEST_MOVE);
		ADD_HPKT(0x0365, 6, CZ_REQUEST_TIME);
		ADD_HPKT(0x0937, 6, CZ_REQ_CLICK_TO_BUYING_STORE);
		ADD_HPKT(0x085e, 2, CZ_REQ_CLOSE_BUYING_STORE);
		ADD_HPKT(0x07ec, -1, CZ_REQ_OPEN_BUYING_STORE);
		ADD_HPKT(0x0939, -1, CZ_REQ_TRADE_BUYING_STORE);
		ADD_HPKT(0x0875, -1, CZ_SEARCH_STORE_INFO);
		ADD_HPKT(0x023b, 2, CZ_SEARCH_STORE_INFO_NEXT_PAGE);
		ADD_HPKT(0x0872, 12, CZ_SSILIST_ITEM_CLICK);
		ADD_HPKT(0x0962, 10, CZ_USE_SKILL);
		ADD_HPKT(0x0880, 10, CZ_USE_SKILL_TOGROUND);
		ADD_HPKT(0x0951, 90, CZ_USE_SKILL_TOGROUND_WITHTALKBOX);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20161012 */