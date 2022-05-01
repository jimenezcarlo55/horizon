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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080304
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080304


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
		ADD_HPKT(0x00e6, -1, CZ_ACK_EXCHANGE_ITEM);
		ADD_HPKT(0x00c5, 67, CZ_ACK_SELECT_DEALTYPE);
		ADD_HPKT(0x00e8, 9, CZ_ADD_EXCHANGE_ITEM);
		ADD_HPKT(0x0202, 2, CZ_ADD_FRIENDS);
		ADD_HPKT(0x0218, 15, CZ_ALCHEMIST_RANK);
		ADD_HPKT(0x0172, 30, CZ_ALLY_GUILD);
		ADD_HPKT(0x0217, 9, CZ_BLACKSMITH_RANK);
		ADD_HPKT(0x0099, 4, CZ_BROADCAST);
		ADD_HPKT(0x00ed, 26, CZ_CANCEL_EXCHANGE_ITEM);
		ADD_HPKT(0x0118, 34, CZ_CANCEL_LOCKON);
		ADD_HPKT(0x00de, 24, CZ_CHANGE_CHATROOM);
		ADD_HPKT(0x019d, 2, CZ_CHANGE_EFFECTSTATE);
		ADD_HPKT(0x0102, 3, CZ_CHANGE_GROUPEXPOPTION);
		ADD_HPKT(0x00b8, 6, CZ_CHOOSE_MENU);
		ADD_HPKT(0x01ed, -1, CZ_CHOPOKGI);
		ADD_HPKT(0x0146, 5, CZ_CLOSE_DIALOG);
		ADD_HPKT(0x022d, 6, CZ_COMMAND_MER);
		ADD_HPKT(0x01a1, 42, CZ_COMMAND_PET);
		ADD_HPKT(0x00eb, 6, CZ_CONCLUDE_EXCHANGE_ITEM);
		ADD_HPKT(0x0090, 6, CZ_CONTACTNPC);
		ADD_HPKT(0x00d5, 10, CZ_CREATE_CHATROOM);
		ADD_HPKT(0x0203, -1, CZ_DELETE_FRIENDS);
		ADD_HPKT(0x00ce, 2, CZ_DISCONNECT_ALL_CHARACTER);
		ADD_HPKT(0x00cc, 6, CZ_DISCONNECT_CHARACTER);
		ADD_HPKT(0x01e7, 6, CZ_DORIDORI);
		ADD_HPKT(0x00ef, 6, CZ_EXEC_EXCHANGE_ITEM);
		ADD_HPKT(0x00e3, 8, CZ_EXIT_ROOM);
		ADD_HPKT(0x017e, -1, CZ_GUILD_CHAT);
		ADD_HPKT(0x016e, 26, CZ_GUILD_NOTICE);
		ADD_HPKT(0x0143, 282, CZ_INPUT_EDITDLG);
		ADD_HPKT(0x01d5, -1, CZ_INPUT_EDITDLGSTR);
		ADD_HPKT(0x013f, 11, CZ_ITEM_CREATE);
		ADD_HPKT(0x00ff, 6, CZ_JOIN_GROUP);
		ADD_HPKT(0x016b, 10, CZ_JOIN_GUILD);
		ADD_HPKT(0x0237, 23, CZ_KILLER_RANK);
		ADD_HPKT(0x019c, 9, CZ_LOCALBROADCAST);
		ADD_HPKT(0x00f9, 19, CZ_MAKE_GROUP);
		ADD_HPKT(0x01e8, 26, CZ_MAKE_GROUP2);
		ADD_HPKT(0x0140, 8, CZ_MOVETO_MAP);
		ADD_HPKT(0x0126, 4, CZ_MOVE_ITEM_FROM_BODY_TO_CART);
		ADD_HPKT(0x0127, -1, CZ_MOVE_ITEM_FROM_CART_TO_BODY);
		ADD_HPKT(0x0128, 5, CZ_MOVE_ITEM_FROM_STORE_TO_CART);
		ADD_HPKT(0x007d, -1, CZ_NOTIFY_ACTORINIT);
		ADD_HPKT(0x00c8, 86, CZ_PC_PURCHASE_ITEMLIST);
		ADD_HPKT(0x0134, 4, CZ_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_HPKT(0x00c9, 27, CZ_PC_SELL_ITEMLIST);
		ADD_HPKT(0x01bc, 3, CZ_RECALL);
		ADD_HPKT(0x01bd, 3, CZ_RECALL_GID);
		ADD_HPKT(0x0161, 58, CZ_REG_CHANGE_GUILD_POSITIONINFO);
		ADD_HPKT(0x011d, 8, CZ_REMEMBER_WARPPOINT);
		ADD_HPKT(0x01ba, 3, CZ_REMOVE_AID);
		ADD_HPKT(0x018e, 7, CZ_REQMAKINGITEM);
		ADD_HPKT(0x0233, 2, CZ_REQUEST_ACTNPC);
		ADD_HPKT(0x0108, 4, CZ_REQUEST_CHAT_PARTY);
		ADD_HPKT(0x0232, 3, CZ_REQUEST_MOVENPC);
		ADD_HPKT(0x0234, 6, CZ_REQUEST_MOVETOOWNER);
		ADD_HPKT(0x0170, -1, CZ_REQ_ALLY_GUILD);
		ADD_HPKT(0x015b, 2, CZ_REQ_BAN_GUILD);
		ADD_HPKT(0x0130, -1, CZ_REQ_BUY_FROMMC);
		ADD_HPKT(0x012a, 6, CZ_REQ_CARTOFF);
		ADD_HPKT(0x0155, 54, CZ_REQ_CHANGE_MEMBERPOS);
		ADD_HPKT(0x012e, 10, CZ_REQ_CLOSESTORE);
		ADD_HPKT(0x018a, 11, CZ_REQ_DISCONNECT);
		ADD_HPKT(0x00bf, 3, CZ_REQ_EMOTION);
		ADD_HPKT(0x00d9, 66, CZ_REQ_ENTER_ROOM);
		ADD_HPKT(0x00e4, 2, CZ_REQ_EXCHANGE_ITEM);
		ADD_HPKT(0x0103, 6, CZ_REQ_EXPEL_GROUP_MEMBER);
		ADD_HPKT(0x00e2, 13, CZ_REQ_EXPEL_MEMBER);
		ADD_HPKT(0x0149, 15, CZ_REQ_GIVE_MANNER_POINT);
		ADD_HPKT(0x014f, 10, CZ_REQ_GUILD_MENU);
		ADD_HPKT(0x014d, 6, CZ_REQ_GUILD_MENUINTERFACE);
		ADD_HPKT(0x017a, 10, CZ_REQ_ITEMCOMPOSITION_LIST);
		ADD_HPKT(0x0178, 7, CZ_REQ_ITEMIDENTIFY);
		ADD_HPKT(0x01fd, 2, CZ_REQ_ITEMREPAIR);
		ADD_HPKT(0x00fc, -1, CZ_REQ_JOIN_GROUP);
		ADD_HPKT(0x0168, 9, CZ_REQ_JOIN_GUILD);
		ADD_HPKT(0x0100, 2, CZ_REQ_LEAVE_GROUP);
		ADD_HPKT(0x0159, -1, CZ_REQ_LEAVE_GUILD);
		ADD_HPKT(0x0165, -1, CZ_REQ_MAKE_GUILD);
		ADD_HPKT(0x01ae, -1, CZ_REQ_MAKINGARROW);
		ADD_HPKT(0x00b9, 44, CZ_REQ_NEXT_SCRIPT);
		ADD_HPKT(0x01b2, 6, CZ_REQ_OPENSTORE2);
		ADD_HPKT(0x00e0, 8, CZ_REQ_ROLE_CHANGE);
		ADD_HPKT(0x00c1, 28, CZ_REQ_USER_COUNT);
		ADD_HPKT(0x00a9, 35, CZ_REQ_WEAR_EQUIP);
		ADD_HPKT(0x00d3, 23, CZ_REQ_WHISPER_LIST);
		ADD_HPKT(0x00b2, 2, CZ_RESTART);
		ADD_HPKT(0x01ce, 3, CZ_SELECTAUTOSPELL);
		ADD_HPKT(0x01a7, -1, CZ_SELECT_PETEGG);
		ADD_HPKT(0x011b, 8, CZ_SELECT_WARPPOINT);
		ADD_HPKT(0x00cf, 60, CZ_SETTING_WHISPER_PC);
		ADD_HPKT(0x00d0, -1, CZ_SETTING_WHISPER_STATE);
		ADD_HPKT(0x01bb, -1, CZ_SHIFT);
		ADD_HPKT(0x00bb, 3, CZ_STATUS_CHANGE);
		ADD_HPKT(0x0225, -1, CZ_TAEKWON_RANK);
		ADD_HPKT(0x019f, 11, CZ_TRYCAPTURE_MONSTER);
		ADD_HPKT(0x0096, 4, CZ_WHISPER);
		ADD_TPKT(0x0073, 26, ZC_ACCEPT_ENTER);
		ADD_TPKT(0x0083, 32, ZC_ACCEPT_QUIT);
		ADD_TPKT(0x012c, 39, ZC_ACK_ADDITEM_TO_CART);
		ADD_TPKT(0x015c, 30, ZC_ACK_BAN_GUILD);
		ADD_TPKT(0x00d6, -1, ZC_ACK_CREATE_CHATROOM);
		ADD_TPKT(0x015e, 3, ZC_ACK_DISORGANIZE_GUILD_RESULT);
		ADD_TPKT(0x00e7, 4, ZC_ACK_EXCHANGE_ITEM);
		ADD_TPKT(0x01f5, 2, ZC_ACK_EXCHANGE_ITEM2);
		ADD_TPKT(0x017d, -1, ZC_ACK_ITEMCOMPOSITION);
		ADD_TPKT(0x0179, 12, ZC_ACK_ITEMIDENTIFY);
		ADD_TPKT(0x0188, 26, ZC_ACK_ITEMREFINING);
		ADD_TPKT(0x01fe, 114, ZC_ACK_ITEMREPAIR);
		ADD_TPKT(0x015a, 14, ZC_ACK_LEAVE_GUILD);
		ADD_TPKT(0x0274, 2, ZC_ACK_MAIL_RETURN);
		ADD_TPKT(0x00fa, 10, ZC_ACK_MAKE_GROUP);
		ADD_TPKT(0x011e, 16, ZC_ACK_REMEMBER_WARPPOINT);
		ADD_TPKT(0x018f, 65, ZC_ACK_REQMAKINGITEM);
		ADD_TPKT(0x0095, 10, ZC_ACK_REQNAME);
		ADD_TPKT(0x0195, 6, ZC_ACK_REQNAMEALL);
		ADD_TPKT(0x0194, -1, ZC_ACK_REQNAME_BYGID);
		ADD_TPKT(0x018b, -1, ZC_ACK_REQ_DISCONNECT);
		ADD_TPKT(0x00fd, 7, ZC_ACK_REQ_JOIN_GROUP);
		ADD_TPKT(0x0169, 81, ZC_ACK_REQ_JOIN_GUILD);
		ADD_TPKT(0x0110, 29, ZC_ACK_TOUSESKILL);
		ADD_TPKT(0x0098, 6, ZC_ACK_WHISPER);
		ADD_TPKT(0x013b, 26, ZC_ACTION_FAILURE);
		ADD_TPKT(0x00e9, 28, ZC_ADD_EXCHANGE_ITEM);
		ADD_TPKT(0x0209, 22, ZC_ADD_FRIENDS_LIST);
		ADD_TPKT(0x0124, 8, ZC_ADD_ITEM_TO_CART);
		ADD_TPKT(0x01c5, 6, ZC_ADD_ITEM_TO_CART2);
		ADD_TPKT(0x00f4, -1, ZC_ADD_ITEM_TO_STORE);
		ADD_TPKT(0x01c4, 2, ZC_ADD_ITEM_TO_STORE2);
		ADD_TPKT(0x0104, 2, ZC_ADD_MEMBER_TO_GROUP);
		ADD_TPKT(0x01e9, -1, ZC_ADD_MEMBER_TO_GROUP2);
		ADD_TPKT(0x0111, 3, ZC_ADD_SKILL);
		ADD_TPKT(0x021c, 5, ZC_ALCHEMIST_POINT);
		ADD_TPKT(0x021a, 6, ZC_ALCHEMIST_RANK);
		ADD_TPKT(0x0139, 3, ZC_ATTACK_FAILURE_FOR_DISTANCE);
		ADD_TPKT(0x013a, 5, ZC_ATTACK_RANGE);
		ADD_TPKT(0x0147, 22, ZC_AUTORUN_SKILL);
		ADD_TPKT(0x01cd, 3, ZC_AUTOSPELLLIST);
		ADD_TPKT(0x0163, 21, ZC_BAN_LIST);
		ADD_TPKT(0x021b, 30, ZC_BLACKSMITH_POINT);
		ADD_TPKT(0x0219, 6, ZC_BLACKSMITH_RANK);
		ADD_TPKT(0x009a, -1, ZC_BROADCAST);
		ADD_TPKT(0x01c3, 26, ZC_BROADCAST2);
		ADD_TPKT(0x00ee, 4, ZC_CANCEL_EXCHANGE_ITEM);
		ADD_TPKT(0x0122, 30, ZC_CART_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0297, 97, ZC_CART_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x0123, 8, ZC_CART_NORMAL_ITEMLIST);
		ADD_TPKT(0x01ef, 6, ZC_CART_NORMAL_ITEMLIST2);
		ADD_TPKT(0x0230, 282, ZC_CHANGESTATE_MER);
		ADD_TPKT(0x01a4, 6, ZC_CHANGESTATE_PET);
		ADD_TPKT(0x00df, 53, ZC_CHANGE_CHATROOM);
		ADD_TPKT(0x009c, 6, ZC_CHANGE_DIRECTION);
		ADD_TPKT(0x00b6, 6, ZC_CLOSE_DIALOG);
		ADD_TPKT(0x00f8, 5, ZC_CLOSE_STORE);
		ADD_TPKT(0x01d2, 4, ZC_COMBODELAY);
		ADD_TPKT(0x0144, 79, ZC_COMPASS);
		ADD_TPKT(0x00ec, 28, ZC_CONCLUDE_EXCHANGE_ITEM);
		ADD_TPKT(0x01ea, 8, ZC_CONGRATULATION);
		ADD_TPKT(0x0141, -1, ZC_COUPLESTATUS);
		ADD_TPKT(0x0137, 2, ZC_DELETEITEM_FROM_MCSTORE);
		ADD_TPKT(0x020a, 7, ZC_DELETE_FRIENDS);
		ADD_TPKT(0x0125, 17, ZC_DELETE_ITEM_FROM_CART);
		ADD_TPKT(0x0105, 102, ZC_DELETE_MEMBER_FROM_GROUP);
		ADD_TPKT(0x00d8, 10, ZC_DESTROY_ROOM);
		ADD_TPKT(0x01cf, 8, ZC_DEVOTIONLIST);
		ADD_TPKT(0x0132, 14, ZC_DISAPPEAR_ENTRY);
		ADD_TPKT(0x01b9, 26, ZC_DISPEL);
		ADD_TPKT(0x00c0, 2, ZC_EMOTION);
		ADD_TPKT(0x00db, -1, ZC_ENTER_ROOM);
		ADD_TPKT(0x00a4, 27, ZC_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0295, 30, ZC_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x013c, 12, ZC_EQUIP_ARROW);
		ADD_TPKT(0x00f0, -1, ZC_EXEC_EXCHANGE_ITEM);
		ADD_TPKT(0x022f, 4, ZC_FEED_MER);
		ADD_TPKT(0x01a3, 10, ZC_FEED_PET);
		ADD_TPKT(0x0206, 6, ZC_FRIENDS_STATE);
		ADD_TPKT(0x0227, -1, ZC_GAME_GUARD);
		ADD_TPKT(0x0101, 11, ZC_GROUPINFO_CHANGE);
		ADD_TPKT(0x00fb, 54, ZC_GROUP_LIST);
		ADD_TPKT(0x017f, 4, ZC_GUILD_CHAT);
		ADD_TPKT(0x01b6, 6, ZC_GUILD_INFO2);
		ADD_TPKT(0x016f, 17, ZC_GUILD_NOTICE);
		ADD_TPKT(0x0162, 27, ZC_GUILD_SKILLINFO);
		ADD_TPKT(0x0235, 6, ZC_HOSKILLINFO_LIST);
		ADD_TPKT(0x0239, 10, ZC_HOSKILLINFO_UPDATE);
		ADD_TPKT(0x017b, 3, ZC_ITEMCOMPOSITION_LIST);
		ADD_TPKT(0x0177, -1, ZC_ITEMIDENTIFY_LIST);
		ADD_TPKT(0x00a1, 7, ZC_ITEM_DISAPPEAR);
		ADD_TPKT(0x009d, 6, ZC_ITEM_ENTRY);
		ADD_TPKT(0x009e, 36, ZC_ITEM_FALL_ENTRY);
		ADD_TPKT(0x00a0, -1, ZC_ITEM_PICKUP_ACK);
		ADD_TPKT(0x029a, 30, ZC_ITEM_PICKUP_ACK2);
		ADD_TPKT(0x02d4, 29, ZC_ITEM_PICKUP_ACK3);
		ADD_TPKT(0x00af, 6, ZC_ITEM_THROW_ACK);
		ADD_TPKT(0x0238, 20, ZC_KILLER_RANK);
		ADD_TPKT(0x00b1, 8, ZC_LONGPAR_CHANGE);
		ADD_TPKT(0x018d, 32, ZC_MAKABLEITEMLIST);
		ADD_TPKT(0x01ad, 2, ZC_MAKINGARROW_LIST);
		ADD_TPKT(0x00dd, 14, ZC_MEMBER_EXIT);
		ADD_TPKT(0x00dc, 11, ZC_MEMBER_NEWENTRY);
		ADD_TPKT(0x00b7, 2, ZC_MENU_LIST);
		ADD_TPKT(0x018c, 8, ZC_MONSTER_INFO);
		ADD_TPKT(0x0196, -1, ZC_MSG_STATE_CHANGE);
		ADD_TPKT(0x010c, 4, ZC_MVP);
		ADD_TPKT(0x010a, -1, ZC_MVP_GETTING_ITEM);
		ADD_TPKT(0x010b, -1, ZC_MVP_GETTING_SPECIAL_EXP);
		ADD_TPKT(0x00a3, 2, ZC_NORMAL_ITEMLIST);
		ADD_TPKT(0x01ee, 57, ZC_NORMAL_ITEMLIST2);
		ADD_TPKT(0x008a, 5, ZC_NOTIFY_ACT);
		ADD_TPKT(0x007a, 4, ZC_NOTIFY_ACTENTRY);
		ADD_TPKT(0x0121, 6, ZC_NOTIFY_CARTITEM_COUNTINFO);
		ADD_TPKT(0x008d, 3, ZC_NOTIFY_CHAT);
		ADD_TPKT(0x0109, 33, ZC_NOTIFY_CHAT_PARTY);
		ADD_TPKT(0x019b, 39, ZC_NOTIFY_EFFECT);
		ADD_TPKT(0x0117, 282, ZC_NOTIFY_GROUNDSKILL);
		ADD_TPKT(0x0106, 6, ZC_NOTIFY_HP_TO_GROUPM);
		ADD_TPKT(0x0075, 11, ZC_NOTIFY_INITCHAR);
		ADD_TPKT(0x0189, 60, ZC_NOTIFY_MAPINFO);
		ADD_TPKT(0x0199, 4, ZC_NOTIFY_MAPPROPERTY);
		ADD_TPKT(0x01d6, 2, ZC_NOTIFY_MAPPROPERTY2);
		ADD_TPKT(0x0086, 4, ZC_NOTIFY_MOVE);
		ADD_TPKT(0x007b, 56, ZC_NOTIFY_MOVEENTRY);
		ADD_TPKT(0x01da, -1, ZC_NOTIFY_MOVEENTRY2);
		ADD_TPKT(0x022c, 6, ZC_NOTIFY_MOVEENTRY3);
		ADD_TPKT(0x0079, 6, ZC_NOTIFY_NEWENTRY);
		ADD_TPKT(0x01d9, 10, ZC_NOTIFY_NEWENTRY2);
		ADD_TPKT(0x008e, 12, ZC_NOTIFY_PLAYERCHAT);
		ADD_TPKT(0x0087, 4, ZC_NOTIFY_PLAYERMOVE);
		ADD_TPKT(0x0107, 21, ZC_NOTIFY_POSITION_TO_GROUPM);
		ADD_TPKT(0x01eb, 7, ZC_NOTIFY_POSITION_TO_GUILDM);
		ADD_TPKT(0x019a, 8, ZC_NOTIFY_RANKING);
		ADD_TPKT(0x0114, 8, ZC_NOTIFY_SKILL);
		ADD_TPKT(0x01de, 8, ZC_NOTIFY_SKILL2);
		ADD_TPKT(0x0078, 3, ZC_NOTIFY_STANDENTRY);
		ADD_TPKT(0x01d8, 7, ZC_NOTIFY_STANDENTRY2);
		ADD_TPKT(0x022a, 14, ZC_NOTIFY_STANDENTRY3);
		ADD_TPKT(0x007c, -1, ZC_NOTIFY_STANDENTRY_NPC);
		ADD_TPKT(0x00f2, 5, ZC_NOTIFY_STOREITEM_COUNTINFO);
		ADD_TPKT(0x007f, -1, ZC_NOTIFY_TIME);
		ADD_TPKT(0x0077, 54, ZC_NOTIFY_UPDATEPLAYER);
		ADD_TPKT(0x0080, -1, ZC_NOTIFY_VANISH);
		ADD_TPKT(0x0093, 2, ZC_NPCACK_ENABLE);
		ADD_TPKT(0x0092, 10, ZC_NPCACK_SERVERMOVE);
		ADD_TPKT(0x01b0, 7, ZC_NPCSPRITE_CHANGE);
		ADD_TPKT(0x012d, 16, ZC_OPENSTORE);
		ADD_TPKT(0x0142, 31, ZC_OPEN_EDITDLG);
		ADD_TPKT(0x01d4, 6, ZC_OPEN_EDITDLGSTR);
		ADD_TPKT(0x00b0, 7, ZC_PAR_CHANGE);
		ADD_TPKT(0x01ab, 68, ZC_PAR_CHANGE_USER);
		ADD_TPKT(0x0287, 4, ZC_PC_CASH_POINT_ITEMLIST);
		ADD_TPKT(0x00c6, 53, ZC_PC_PURCHASE_ITEMLIST);
		ADD_TPKT(0x0133, -1, ZC_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_TPKT(0x0136, 26, ZC_PC_PURCHASE_MYITEMLIST);
		ADD_TPKT(0x00ca, 20, ZC_PC_PURCHASE_RESULT);
		ADD_TPKT(0x0135, -1, ZC_PC_PURCHASE_RESULT_FROMMC);
		ADD_TPKT(0x00c7, -1, ZC_PC_SELL_ITEMLIST);
		ADD_TPKT(0x01a6, 9, ZC_PETEGG_LIST);
		ADD_TPKT(0x01aa, 18, ZC_PET_ACT);
		ADD_TPKT(0x0166, -1, ZC_POSITION_ID_NAME_INFO);
		ADD_TPKT(0x0160, 29, ZC_POSITION_INFO);
		ADD_TPKT(0x022e, 22, ZC_PROPERTY_HOMUN);
		ADD_TPKT(0x01a2, 6, ZC_PROPERTY_PET);
		ADD_TPKT(0x013d, 43, ZC_RECOVERY);
		ADD_TPKT(0x00da, 2, ZC_REFUSE_ENTER_ROOM);
		ADD_TPKT(0x01fc, -1, ZC_REPAIRITEMLIST);
		ADD_TPKT(0x0207, -1, ZC_REQ_ADD_FRIENDS);
		ADD_TPKT(0x0171, 10, ZC_REQ_ALLY_GUILD);
		ADD_TPKT(0x00e5, 14, ZC_REQ_EXCHANGE_ITEM);
		ADD_TPKT(0x01f4, 3, ZC_REQ_EXCHANGE_ITEM2);
		ADD_TPKT(0x00fe, 30, ZC_REQ_JOIN_GROUP);
		ADD_TPKT(0x016a, 6, ZC_REQ_JOIN_GUILD);
		ADD_TPKT(0x023a, 8, ZC_REQ_STORE_PASSWORD);
		ADD_TPKT(0x00ac, 14, ZC_REQ_TAKEOFF_EQUIP_ACK);
		ADD_TPKT(0x00aa, 14, ZC_REQ_WEAR_EQUIP_ACK);
		ADD_TPKT(0x00b3, 16, ZC_RESTART_ACK);
		ADD_TPKT(0x023c, 30, ZC_RESULT_STORE_PASSWORD);
		ADD_TPKT(0x0148, 10, ZC_RESURRECTION);
		ADD_TPKT(0x00d7, 14, ZC_ROOM_NEWENTRY);
		ADD_TPKT(0x00b4, -1, ZC_SAY_DIALOG);
		ADD_TPKT(0x00c4, 3, ZC_SELECT_DEALTYPE);
		ADD_TPKT(0x00d1, 3, ZC_SETTING_WHISPER_PC);
		ADD_TPKT(0x00d2, 6, ZC_SETTING_WHISPER_STATE);
		ADD_TPKT(0x01b3, 32, ZC_SHOW_IMAGE2);
		ADD_TPKT(0x010f, 30, ZC_SKILLINFO_LIST);
		ADD_TPKT(0x010e, 282, ZC_SKILLINFO_UPDATE);
		ADD_TPKT(0x0120, 5, ZC_SKILL_DISAPPEAR);
		ADD_TPKT(0x011f, -1, ZC_SKILL_ENTRY);
		ADD_TPKT(0x01c9, 8, ZC_SKILL_ENTRY2);
		ADD_TPKT(0x01ac, 90, ZC_SKILL_UPDATE);
		ADD_TPKT(0x01d0, 18, ZC_SPIRITS);
		ADD_TPKT(0x01e1, -1, ZC_SPIRITS2);
		ADD_TPKT(0x00c3, 30, ZC_SPRITE_CHANGE);
		ADD_TPKT(0x01d7, 15, ZC_SPRITE_CHANGE2);
		ADD_TPKT(0x020e, 4, ZC_STARSKILL);
		ADD_TPKT(0x0119, 10, ZC_STATE_CHANGE);
		ADD_TPKT(0x0229, 10, ZC_STATE_CHANGE3);
		ADD_TPKT(0x00bd, -1, ZC_STATUS);
		ADD_TPKT(0x00be, 186, ZC_STATUS_CHANGE);
		ADD_TPKT(0x0088, 6, ZC_STOPMOVE);
		ADD_TPKT(0x0131, 4, ZC_STORE_ENTRY);
		ADD_TPKT(0x00a6, -1, ZC_STORE_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0296, 58, ZC_STORE_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x00a5, 6, ZC_STORE_NORMAL_ITEMLIST);
		ADD_TPKT(0x01f0, 10, ZC_STORE_NORMAL_ITEMLIST2);
		ADD_TPKT(0x0224, 22, ZC_TAEKWON_POINT);
		ADD_TPKT(0x0226, 31, ZC_TAEKWON_RANK);
		ADD_TPKT(0x01a0, -1, ZC_TRYCAPTURE_MONSTER);
		ADD_TPKT(0x016d, 11, ZC_UPDATE_CHARSTAT);
		ADD_TPKT(0x01f2, 28, ZC_UPDATE_CHARSTAT2);
		ADD_TPKT(0x016c, 10, ZC_UPDATE_GDID);
		ADD_TPKT(0x00c2, -1, ZC_USER_COUNT);
		ADD_TPKT(0x013e, 5, ZC_USESKILL_ACK);
		ADD_TPKT(0x00a8, 2, ZC_USE_ITEM_ACK);
		ADD_TPKT(0x01c8, 2, ZC_USE_ITEM_ACK2);
		ADD_TPKT(0x011a, 2, ZC_USE_SKILL);
		ADD_TPKT(0x00b5, 182, ZC_WAIT_DIALOG);
		ADD_TPKT(0x011c, 11, ZC_WARPLIST);
		ADD_TPKT(0x0097, -1, ZC_WHISPER);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080304 */