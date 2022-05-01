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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080903
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080903


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
		ADD_HPKT(0x00e6, 8, CZ_ACK_EXCHANGE_ITEM);
		ADD_HPKT(0x00e8, -1, CZ_ADD_EXCHANGE_ITEM);
		ADD_HPKT(0x0202, 9, CZ_ADD_FRIENDS);
		ADD_HPKT(0x0217, -1, CZ_BLACKSMITH_RANK);
		ADD_HPKT(0x0099, -1, CZ_BROADCAST);
		ADD_HPKT(0x0118, 54, CZ_CANCEL_LOCKON);
		ADD_HPKT(0x00de, -1, CZ_CHANGE_CHATROOM);
		ADD_HPKT(0x0361, 8, CZ_CHANGE_DIRECTION2);
		ADD_HPKT(0x019d, -1, CZ_CHANGE_EFFECTSTATE);
		ADD_HPKT(0x01ed, -1, CZ_CHOPOKGI);
		ADD_HPKT(0x00eb, 4, CZ_CONCLUDE_EXCHANGE_ITEM);
		ADD_HPKT(0x0203, 11, CZ_DELETE_FRIENDS);
		ADD_HPKT(0x00ce, 53, CZ_DISCONNECT_ALL_CHARACTER);
		ADD_HPKT(0x00cc, -1, CZ_DISCONNECT_CHARACTER);
		ADD_HPKT(0x01e7, 6, CZ_DORIDORI);
		ADD_HPKT(0x00ef, 10, CZ_EXEC_EXCHANGE_ITEM);
		ADD_HPKT(0x017e, 32, CZ_GUILD_CHAT);
		ADD_HPKT(0x016e, 3, CZ_GUILD_NOTICE);
		ADD_HPKT(0x0143, 5, CZ_INPUT_EDITDLG);
		ADD_HPKT(0x01d5, 29, CZ_INPUT_EDITDLGSTR);
		ADD_HPKT(0x02f3, 21, CZ_IRMAIL_SEND);
		ADD_HPKT(0x0362, -1, CZ_ITEM_PICKUP2);
		ADD_HPKT(0x0363, 26, CZ_ITEM_THROW2);
		ADD_HPKT(0x019c, -1, CZ_LOCALBROADCAST);
		ADD_HPKT(0x0140, 10, CZ_MOVETO_MAP);
		ADD_HPKT(0x0364, 182, CZ_MOVE_ITEM_FROM_BODY_TO_STORE2);
		ADD_HPKT(0x0129, 3, CZ_MOVE_ITEM_FROM_CART_TO_STORE);
		ADD_HPKT(0x0365, 7, CZ_MOVE_ITEM_FROM_STORE_TO_BODY2);
		ADD_HPKT(0x0128, -1, CZ_MOVE_ITEM_FROM_STORE_TO_CART);
		ADD_HPKT(0x007d, 57, CZ_NOTIFY_ACTORINIT);
		ADD_HPKT(0x00c8, -1, CZ_PC_PURCHASE_ITEMLIST);
		ADD_HPKT(0x0134, 282, CZ_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_HPKT(0x00c9, -1, CZ_PC_SELL_ITEMLIST);
		ADD_HPKT(0x01bc, 55, CZ_RECALL);
		ADD_HPKT(0x0161, 7, CZ_REG_CHANGE_GUILD_POSITIONINFO);
		ADD_HPKT(0x01ba, 9, CZ_REMOVE_AID);
		ADD_HPKT(0x0368, 43, CZ_REQNAME2);
		ADD_HPKT(0x0369, 33, CZ_REQNAME_BYGID2);
		ADD_HPKT(0x0233, 2, CZ_REQUEST_ACTNPC);
		ADD_HPKT(0x0232, 6, CZ_REQUEST_MOVENPC);
		ADD_HPKT(0x0234, 3, CZ_REQUEST_MOVETOOWNER);
		ADD_HPKT(0x0360, 28, CZ_REQUEST_TIME2);
		ADD_HPKT(0x0170, 3, CZ_REQ_ALLY_GUILD);
		ADD_HPKT(0x015b, -1, CZ_REQ_BAN_GUILD);
		ADD_HPKT(0x012e, 6, CZ_REQ_CLOSESTORE);
		ADD_HPKT(0x0103, 5, CZ_REQ_EXPEL_GROUP_MEMBER);
		ADD_HPKT(0x00e2, 11, CZ_REQ_EXPEL_MEMBER);
		ADD_HPKT(0x0149, 7, CZ_REQ_GIVE_MANNER_POINT);
		ADD_HPKT(0x014f, -1, CZ_REQ_GUILD_MENU);
		ADD_HPKT(0x014d, 3, CZ_REQ_GUILD_MENUINTERFACE);
		ADD_HPKT(0x017c, 4, CZ_REQ_ITEMCOMPOSITION);
		ADD_HPKT(0x01fd, -1, CZ_REQ_ITEMREPAIR);
		ADD_HPKT(0x0159, -1, CZ_REQ_LEAVE_GUILD);
		ADD_HPKT(0x0165, -1, CZ_REQ_MAKE_GUILD);
		ADD_HPKT(0x01b2, 11, CZ_REQ_OPENSTORE2);
		ADD_HPKT(0x00e0, -1, CZ_REQ_ROLE_CHANGE);
		ADD_HPKT(0x00ab, 67, CZ_REQ_TAKEOFF_EQUIP);
		ADD_HPKT(0x00c1, -1, CZ_REQ_USER_COUNT);
		ADD_HPKT(0x00b2, -1, CZ_RESTART);
		ADD_HPKT(0x01ce, 30, CZ_SELECTAUTOSPELL);
		ADD_HPKT(0x01a7, 5, CZ_SELECT_PETEGG);
		ADD_HPKT(0x011b, -1, CZ_SELECT_WARPPOINT);
		ADD_HPKT(0x00d0, -1, CZ_SETTING_WHISPER_STATE);
		ADD_HPKT(0x01bb, 7, CZ_SHIFT);
		ADD_HPKT(0x00bb, -1, CZ_STATUS_CHANGE);
		ADD_HPKT(0x019f, -1, CZ_TRYCAPTURE_MONSTER);
		ADD_HPKT(0x0112, 10, CZ_UPGRADE_SKILLLEVEL);
		ADD_HPKT(0x0366, 4, CZ_USE_SKILL_TOGROUND2);
		ADD_HPKT(0x0096, 60, CZ_WHISPER);
		ADD_TPKT(0x0083, 10, ZC_ACCEPT_QUIT);
		ADD_TPKT(0x012c, -1, ZC_ACK_ADDITEM_TO_CART);
		ADD_TPKT(0x015c, -1, ZC_ACK_BAN_GUILD);
		ADD_TPKT(0x00d6, -1, ZC_ACK_CREATE_CHATROOM);
		ADD_TPKT(0x015e, 24, ZC_ACK_DISORGANIZE_GUILD_RESULT);
		ADD_TPKT(0x01f5, 4, ZC_ACK_EXCHANGE_ITEM2);
		ADD_TPKT(0x017d, 4, ZC_ACK_ITEMCOMPOSITION);
		ADD_TPKT(0x0179, -1, ZC_ACK_ITEMIDENTIFY);
		ADD_TPKT(0x0188, 6, ZC_ACK_ITEMREFINING);
		ADD_TPKT(0x01fe, 8, ZC_ACK_ITEMREPAIR);
		ADD_TPKT(0x0274, 35, ZC_ACK_MAIL_RETURN);
		ADD_TPKT(0x0095, -1, ZC_ACK_REQNAME);
		ADD_TPKT(0x0195, 14, ZC_ACK_REQNAMEALL);
		ADD_TPKT(0x018b, -1, ZC_ACK_REQ_DISCONNECT);
		ADD_TPKT(0x00fd, 86, ZC_ACK_REQ_JOIN_GROUP);
		ADD_TPKT(0x0110, 6, ZC_ACK_TOUSESKILL);
		ADD_TPKT(0x00e9, -1, ZC_ADD_EXCHANGE_ITEM);
		ADD_TPKT(0x0124, 10, ZC_ADD_ITEM_TO_CART);
		ADD_TPKT(0x00f4, 15, ZC_ADD_ITEM_TO_STORE);
		ADD_TPKT(0x01c4, 11, ZC_ADD_ITEM_TO_STORE2);
		ADD_TPKT(0x0104, 6, ZC_ADD_MEMBER_TO_GROUP);
		ADD_TPKT(0x01e9, 9, ZC_ADD_MEMBER_TO_GROUP2);
		ADD_TPKT(0x0111, -1, ZC_ADD_SKILL);
		ADD_TPKT(0x0139, -1, ZC_ATTACK_FAILURE_FOR_DISTANCE);
		ADD_TPKT(0x013a, -1, ZC_ATTACK_RANGE);
		ADD_TPKT(0x0147, 26, ZC_AUTORUN_SKILL);
		ADD_TPKT(0x01cd, 2, ZC_AUTOSPELLLIST);
		ADD_TPKT(0x0163, 20, ZC_BAN_LIST);
		ADD_TPKT(0x021b, -1, ZC_BLACKSMITH_POINT);
		ADD_TPKT(0x0219, 8, ZC_BLACKSMITH_RANK);
		ADD_TPKT(0x009a, 30, ZC_BROADCAST);
		ADD_TPKT(0x01c3, 59, ZC_BROADCAST2);
		ADD_TPKT(0x00ee, 8, ZC_CANCEL_EXCHANGE_ITEM);
		ADD_TPKT(0x0122, -1, ZC_CART_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0297, 6, ZC_CART_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x0123, 19, ZC_CART_NORMAL_ITEMLIST);
		ADD_TPKT(0x0230, -1, ZC_CHANGESTATE_MER);
		ADD_TPKT(0x00df, -1, ZC_CHANGE_CHATROOM);
		ADD_TPKT(0x009c, 2, ZC_CHANGE_DIRECTION);
		ADD_TPKT(0x00b6, -1, ZC_CLOSE_DIALOG);
		ADD_TPKT(0x00f8, 3, ZC_CLOSE_STORE);
		ADD_TPKT(0x01d2, 4, ZC_COMBODELAY);
		ADD_TPKT(0x0144, 2, ZC_COMPASS);
		ADD_TPKT(0x00ec, 60, ZC_CONCLUDE_EXCHANGE_ITEM);
		ADD_TPKT(0x0141, 10, ZC_COUPLESTATUS);
		ADD_TPKT(0x0137, 29, ZC_DELETEITEM_FROM_MCSTORE);
		ADD_TPKT(0x020a, -1, ZC_DELETE_FRIENDS);
		ADD_TPKT(0x0125, -1, ZC_DELETE_ITEM_FROM_CART);
		ADD_TPKT(0x00f6, -1, ZC_DELETE_ITEM_FROM_STORE);
		ADD_TPKT(0x0105, 7, ZC_DELETE_MEMBER_FROM_GROUP);
		ADD_TPKT(0x00d8, 7, ZC_DESTROY_ROOM);
		ADD_TPKT(0x01cf, -1, ZC_DEVOTIONLIST);
		ADD_TPKT(0x00a4, -1, ZC_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0295, 2, ZC_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x013c, 2, ZC_EQUIP_ARROW);
		ADD_TPKT(0x00f0, -1, ZC_EXEC_EXCHANGE_ITEM);
		ADD_TPKT(0x01a3, -1, ZC_FEED_PET);
		ADD_TPKT(0x0206, 65, ZC_FRIENDS_STATE);
		ADD_TPKT(0x0227, -1, ZC_GAME_GUARD);
		ADD_TPKT(0x00fb, 67, ZC_GROUP_LIST);
		ADD_TPKT(0x017f, 10, ZC_GUILD_CHAT);
		ADD_TPKT(0x016f, -1, ZC_GUILD_NOTICE);
		ADD_TPKT(0x0235, -1, ZC_HOSKILLINFO_LIST);
		ADD_TPKT(0x0239, -1, ZC_HOSKILLINFO_UPDATE);
		ADD_TPKT(0x02f5, 3, ZC_IRMAIL_NOTIFY);
		ADD_TPKT(0x0177, 7, ZC_ITEMIDENTIFY_LIST);
		ADD_TPKT(0x00a1, -1, ZC_ITEM_DISAPPEAR);
		ADD_TPKT(0x00a0, -1, ZC_ITEM_PICKUP_ACK);
		ADD_TPKT(0x0238, -1, ZC_KILLER_RANK);
		ADD_TPKT(0x00b1, 39, ZC_LONGPAR_CHANGE);
		ADD_TPKT(0x018d, 8, ZC_MAKABLEITEMLIST);
		ADD_TPKT(0x0154, -1, ZC_MEMBERMGR_INFO);
		ADD_TPKT(0x00dd, 4, ZC_MEMBER_EXIT);
		ADD_TPKT(0x00dc, -1, ZC_MEMBER_NEWENTRY);
		ADD_TPKT(0x00b7, -1, ZC_MENU_LIST);
		ADD_TPKT(0x018c, 2, ZC_MONSTER_INFO);
		ADD_TPKT(0x0196, 4, ZC_MSG_STATE_CHANGE);
		ADD_TPKT(0x010a, 7, ZC_MVP_GETTING_ITEM);
		ADD_TPKT(0x014c, 8, ZC_MYGUILD_BASIC_INFO);
		ADD_TPKT(0x00a3, 60, ZC_NORMAL_ITEMLIST);
		ADD_TPKT(0x01ee, -1, ZC_NORMAL_ITEMLIST2);
		ADD_TPKT(0x02e1, 5, ZC_NOTIFY_ACT2);
		ADD_TPKT(0x007a, -1, ZC_NOTIFY_ACTENTRY);
		ADD_TPKT(0x0121, 13, ZC_NOTIFY_CARTITEM_COUNTINFO);
		ADD_TPKT(0x008d, 14, ZC_NOTIFY_CHAT);
		ADD_TPKT(0x0109, 81, ZC_NOTIFY_CHAT_PARTY);
		ADD_TPKT(0x019b, -1, ZC_NOTIFY_EFFECT);
		ADD_TPKT(0x0117, 2, ZC_NOTIFY_GROUNDSKILL);
		ADD_TPKT(0x0189, -1, ZC_NOTIFY_MAPINFO);
		ADD_TPKT(0x0199, -1, ZC_NOTIFY_MAPPROPERTY);
		ADD_TPKT(0x01d6, 58, ZC_NOTIFY_MAPPROPERTY2);
		ADD_TPKT(0x0086, -1, ZC_NOTIFY_MOVE);
		ADD_TPKT(0x01da, -1, ZC_NOTIFY_MOVEENTRY2);
		ADD_TPKT(0x022c, 6, ZC_NOTIFY_MOVEENTRY3);
		ADD_TPKT(0x02ec, -1, ZC_NOTIFY_MOVEENTRY4);
		ADD_TPKT(0x01d9, 2, ZC_NOTIFY_NEWENTRY2);
		ADD_TPKT(0x02ed, 15, ZC_NOTIFY_NEWENTRY4);
		ADD_TPKT(0x008e, 2, ZC_NOTIFY_PLAYERCHAT);
		ADD_TPKT(0x0087, 8, ZC_NOTIFY_PLAYERMOVE);
		ADD_TPKT(0x0107, 5, ZC_NOTIFY_POSITION_TO_GROUPM);
		ADD_TPKT(0x01eb, 16, ZC_NOTIFY_POSITION_TO_GUILDM);
		ADD_TPKT(0x019a, -1, ZC_NOTIFY_RANKING);
		ADD_TPKT(0x022a, 26, ZC_NOTIFY_STANDENTRY3);
		ADD_TPKT(0x02ee, 2, ZC_NOTIFY_STANDENTRY4);
		ADD_TPKT(0x007c, -1, ZC_NOTIFY_STANDENTRY_NPC);
		ADD_TPKT(0x00f2, 8, ZC_NOTIFY_STOREITEM_COUNTINFO);
		ADD_TPKT(0x007f, -1, ZC_NOTIFY_TIME);
		ADD_TPKT(0x0077, -1, ZC_NOTIFY_UPDATEPLAYER);
		ADD_TPKT(0x0080, 22, ZC_NOTIFY_VANISH);
		ADD_TPKT(0x0091, 10, ZC_NPCACK_MAPMOVE);
		ADD_TPKT(0x012d, 11, ZC_OPENSTORE);
		ADD_TPKT(0x0133, 6, ZC_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_TPKT(0x0136, 10, ZC_PC_PURCHASE_MYITEMLIST);
		ADD_TPKT(0x00ca, -1, ZC_PC_PURCHASE_RESULT);
		ADD_TPKT(0x0135, 22, ZC_PC_PURCHASE_RESULT_FROMMC);
		ADD_TPKT(0x00c7, 6, ZC_PC_SELL_ITEMLIST);
		ADD_TPKT(0x0160, -1, ZC_POSITION_INFO);
		ADD_TPKT(0x022e, 30, ZC_PROPERTY_HOMUN);
		ADD_TPKT(0x01a2, 21, ZC_PROPERTY_PET);
		ADD_TPKT(0x013d, 2, ZC_RECOVERY);
		ADD_TPKT(0x01fc, 27, ZC_REPAIRITEMLIST);
		ADD_TPKT(0x0207, 54, ZC_REQ_ADD_FRIENDS);
		ADD_TPKT(0x0171, 10, ZC_REQ_ALLY_GUILD);
		ADD_TPKT(0x01f4, 14, ZC_REQ_EXCHANGE_ITEM2);
		ADD_TPKT(0x023a, 3, ZC_REQ_STORE_PASSWORD);
		ADD_TPKT(0x00ac, -1, ZC_REQ_TAKEOFF_EQUIP_ACK);
		ADD_TPKT(0x00aa, -1, ZC_REQ_WEAR_EQUIP_ACK);
		ADD_TPKT(0x023c, 10, ZC_RESULT_STORE_PASSWORD);
		ADD_TPKT(0x00e1, 23, ZC_ROLE_CHANGE);
		ADD_TPKT(0x00d7, -1, ZC_ROOM_NEWENTRY);
		ADD_TPKT(0x00d2, -1, ZC_SETTING_WHISPER_STATE);
		ADD_TPKT(0x0120, -1, ZC_SKILL_DISAPPEAR);
		ADD_TPKT(0x011f, 10, ZC_SKILL_ENTRY);
		ADD_TPKT(0x01c9, -1, ZC_SKILL_ENTRY2);
		ADD_TPKT(0x00c3, 22, ZC_SPRITE_CHANGE);
		ADD_TPKT(0x01d7, 102, ZC_SPRITE_CHANGE2);
		ADD_TPKT(0x020e, 30, ZC_STARSKILL);
		ADD_TPKT(0x0119, 30, ZC_STATE_CHANGE);
		ADD_TPKT(0x0229, 10, ZC_STATE_CHANGE3);
		ADD_TPKT(0x00bd, 26, ZC_STATUS);
		ADD_TPKT(0x00be, -1, ZC_STATUS_CHANGE);
		ADD_TPKT(0x00bc, 6, ZC_STATUS_CHANGE_ACK);
		ADD_TPKT(0x0088, 15, ZC_STOPMOVE);
		ADD_TPKT(0x0131, 97, ZC_STORE_ENTRY);
		ADD_TPKT(0x00a6, 6, ZC_STORE_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x01f0, -1, ZC_STORE_NORMAL_ITEMLIST2);
		ADD_TPKT(0x0224, -1, ZC_TAEKWON_POINT);
		ADD_TPKT(0x0226, -1, ZC_TAEKWON_RANK);
		ADD_TPKT(0x01a0, 282, ZC_TRYCAPTURE_MONSTER);
		ADD_TPKT(0x01f2, -1, ZC_UPDATE_CHARSTAT2);
		ADD_TPKT(0x016c, 26, ZC_UPDATE_GDID);
		ADD_TPKT(0x00c2, 26, ZC_USER_COUNT);
		ADD_TPKT(0x01c8, 8, ZC_USE_ITEM_ACK2);
		ADD_TPKT(0x011a, -1, ZC_USE_SKILL);
		ADD_TPKT(0x00b5, 3, ZC_WAIT_DIALOG);
		ADD_TPKT(0x011c, 66, ZC_WARPLIST);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080903 */