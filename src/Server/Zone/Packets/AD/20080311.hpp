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

#ifndef HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080311
#define HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080311


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
		ADD_HPKT(0x00e6, 16, CZ_ACK_EXCHANGE_ITEM);
		ADD_HPKT(0x0208, 6, CZ_ACK_REQ_ADD_FRIENDS);
		ADD_HPKT(0x00c5, 9, CZ_ACK_SELECT_DEALTYPE);
		ADD_HPKT(0x00e8, 6, CZ_ADD_EXCHANGE_ITEM);
		ADD_HPKT(0x0202, 33, CZ_ADD_FRIENDS);
		ADD_HPKT(0x0218, 14, CZ_ALCHEMIST_RANK);
		ADD_HPKT(0x0172, 3, CZ_ALLY_GUILD);
		ADD_HPKT(0x0217, 26, CZ_BLACKSMITH_RANK);
		ADD_HPKT(0x0099, 66, CZ_BROADCAST);
		ADD_HPKT(0x00ed, -1, CZ_CANCEL_EXCHANGE_ITEM);
		ADD_HPKT(0x0118, 282, CZ_CANCEL_LOCKON);
		ADD_HPKT(0x019d, 4, CZ_CHANGE_EFFECTSTATE);
		ADD_HPKT(0x0102, 2, CZ_CHANGE_GROUPEXPOPTION);
		ADD_HPKT(0x00b8, 16, CZ_CHOOSE_MENU);
		ADD_HPKT(0x01ed, 5, CZ_CHOPOKGI);
		ADD_HPKT(0x0146, 10, CZ_CLOSE_DIALOG);
		ADD_HPKT(0x022d, -1, CZ_COMMAND_MER);
		ADD_HPKT(0x01a1, 53, CZ_COMMAND_PET);
		ADD_HPKT(0x00eb, 12, CZ_CONCLUDE_EXCHANGE_ITEM);
		ADD_HPKT(0x0090, 2, CZ_CONTACTNPC);
		ADD_HPKT(0x00d5, 2, CZ_CREATE_CHATROOM);
		ADD_HPKT(0x0203, 60, CZ_DELETE_FRIENDS);
		ADD_HPKT(0x00ce, 10, CZ_DISCONNECT_ALL_CHARACTER);
		ADD_HPKT(0x00cc, 14, CZ_DISCONNECT_CHARACTER);
		ADD_HPKT(0x01e7, 55, CZ_DORIDORI);
		ADD_HPKT(0x00ef, -1, CZ_EXEC_EXCHANGE_ITEM);
		ADD_HPKT(0x00e3, 2, CZ_EXIT_ROOM);
		ADD_HPKT(0x017e, 31, CZ_GUILD_CHAT);
		ADD_HPKT(0x016e, 4, CZ_GUILD_NOTICE);
		ADD_HPKT(0x01d5, 13, CZ_INPUT_EDITDLGSTR);
		ADD_HPKT(0x013f, 282, CZ_ITEM_CREATE);
		ADD_HPKT(0x00ff, 3, CZ_JOIN_GROUP);
		ADD_HPKT(0x016b, 22, CZ_JOIN_GUILD);
		ADD_HPKT(0x0237, 54, CZ_KILLER_RANK);
		ADD_HPKT(0x019c, 8, CZ_LOCALBROADCAST);
		ADD_HPKT(0x00f9, 114, CZ_MAKE_GROUP);
		ADD_HPKT(0x01e8, 6, CZ_MAKE_GROUP2);
		ADD_HPKT(0x0140, 3, CZ_MOVETO_MAP);
		ADD_HPKT(0x0126, 7, CZ_MOVE_ITEM_FROM_BODY_TO_CART);
		ADD_HPKT(0x0127, 5, CZ_MOVE_ITEM_FROM_CART_TO_BODY);
		ADD_HPKT(0x0128, 58, CZ_MOVE_ITEM_FROM_STORE_TO_CART);
		ADD_HPKT(0x007d, -1, CZ_NOTIFY_ACTORINIT);
		ADD_HPKT(0x00c8, 14, CZ_PC_PURCHASE_ITEMLIST);
		ADD_HPKT(0x0134, 26, CZ_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_HPKT(0x00c9, 6, CZ_PC_SELL_ITEMLIST);
		ADD_HPKT(0x01bc, 9, CZ_RECALL);
		ADD_HPKT(0x01bd, 6, CZ_RECALL_GID);
		ADD_HPKT(0x0161, 30, CZ_REG_CHANGE_GUILD_POSITIONINFO);
		ADD_HPKT(0x011d, 3, CZ_REMEMBER_WARPPOINT);
		ADD_HPKT(0x01ba, -1, CZ_REMOVE_AID);
		ADD_HPKT(0x018e, -1, CZ_REQMAKINGITEM);
		ADD_HPKT(0x0233, -1, CZ_REQUEST_ACTNPC);
		ADD_HPKT(0x0108, 4, CZ_REQUEST_CHAT_PARTY);
		ADD_HPKT(0x0232, 5, CZ_REQUEST_MOVENPC);
		ADD_HPKT(0x0234, 43, CZ_REQUEST_MOVETOOWNER);
		ADD_HPKT(0x0170, 4, CZ_REQ_ALLY_GUILD);
		ADD_HPKT(0x015b, 4, CZ_REQ_BAN_GUILD);
		ADD_HPKT(0x0130, -1, CZ_REQ_BUY_FROMMC);
		ADD_HPKT(0x0155, -1, CZ_REQ_CHANGE_MEMBERPOS);
		ADD_HPKT(0x012e, 14, CZ_REQ_CLOSESTORE);
		ADD_HPKT(0x018a, -1, CZ_REQ_DISCONNECT);
		ADD_HPKT(0x00d9, 6, CZ_REQ_ENTER_ROOM);
		ADD_HPKT(0x00e4, 54, CZ_REQ_EXCHANGE_ITEM);
		ADD_HPKT(0x0103, 8, CZ_REQ_EXPEL_GROUP_MEMBER);
		ADD_HPKT(0x00e2, -1, CZ_REQ_EXPEL_MEMBER);
		ADD_HPKT(0x0149, 6, CZ_REQ_GIVE_MANNER_POINT);
		ADD_HPKT(0x014d, 9, CZ_REQ_GUILD_MENUINTERFACE);
		ADD_HPKT(0x017c, -1, CZ_REQ_ITEMCOMPOSITION);
		ADD_HPKT(0x017a, 6, CZ_REQ_ITEMCOMPOSITION_LIST);
		ADD_HPKT(0x0178, 11, CZ_REQ_ITEMIDENTIFY);
		ADD_HPKT(0x01fd, 39, CZ_REQ_ITEMREPAIR);
		ADD_HPKT(0x00fc, 24, CZ_REQ_JOIN_GROUP);
		ADD_HPKT(0x0168, 10, CZ_REQ_JOIN_GUILD);
		ADD_HPKT(0x0100, 3, CZ_REQ_LEAVE_GROUP);
		ADD_HPKT(0x0159, 39, CZ_REQ_LEAVE_GUILD);
		ADD_HPKT(0x0165, 102, CZ_REQ_MAKE_GUILD);
		ADD_HPKT(0x01ae, 26, CZ_REQ_MAKINGARROW);
		ADD_HPKT(0x00b9, 29, CZ_REQ_NEXT_SCRIPT);
		ADD_HPKT(0x01b2, -1, CZ_REQ_OPENSTORE2);
		ADD_HPKT(0x00e0, 2, CZ_REQ_ROLE_CHANGE);
		ADD_HPKT(0x00ab, 14, CZ_REQ_TAKEOFF_EQUIP);
		ADD_HPKT(0x00c1, 16, CZ_REQ_USER_COUNT);
		ADD_HPKT(0x00a9, -1, CZ_REQ_WEAR_EQUIP);
		ADD_HPKT(0x00d3, 14, CZ_REQ_WHISPER_LIST);
		ADD_HPKT(0x00b2, 5, CZ_RESTART);
		ADD_HPKT(0x01a7, 6, CZ_SELECT_PETEGG);
		ADD_HPKT(0x011b, -1, CZ_SELECT_WARPPOINT);
		ADD_HPKT(0x00cf, 6, CZ_SETTING_WHISPER_PC);
		ADD_HPKT(0x00d0, 10, CZ_SETTING_WHISPER_STATE);
		ADD_HPKT(0x01bb, 4, CZ_SHIFT);
		ADD_HPKT(0x0225, 29, CZ_TAEKWON_RANK);
		ADD_HPKT(0x019f, -1, CZ_TRYCAPTURE_MONSTER);
		ADD_HPKT(0x0112, -1, CZ_UPGRADE_SKILLLEVEL);
		ADD_HPKT(0x0096, 10, CZ_WHISPER);
		ADD_TPKT(0x0073, 6, ZC_ACCEPT_ENTER);
		ADD_TPKT(0x0083, 21, ZC_ACCEPT_QUIT);
		ADD_TPKT(0x012c, 14, ZC_ACK_ADDITEM_TO_CART);
		ADD_TPKT(0x00ea, 10, ZC_ACK_ADD_EXCHANGE_ITEM);
		ADD_TPKT(0x015c, 30, ZC_ACK_BAN_GUILD);
		ADD_TPKT(0x00d6, 8, ZC_ACK_CREATE_CHATROOM);
		ADD_TPKT(0x015e, 6, ZC_ACK_DISORGANIZE_GUILD_RESULT);
		ADD_TPKT(0x01f5, 30, ZC_ACK_EXCHANGE_ITEM2);
		ADD_TPKT(0x017d, 34, ZC_ACK_ITEMCOMPOSITION);
		ADD_TPKT(0x0179, 2, ZC_ACK_ITEMIDENTIFY);
		ADD_TPKT(0x0188, -1, ZC_ACK_ITEMREFINING);
		ADD_TPKT(0x01fe, 18, ZC_ACK_ITEMREPAIR);
		ADD_TPKT(0x015a, 27, ZC_ACK_LEAVE_GUILD);
		ADD_TPKT(0x0274, 67, ZC_ACK_MAIL_RETURN);
		ADD_TPKT(0x00fa, -1, ZC_ACK_MAKE_GROUP);
		ADD_TPKT(0x011e, 6, ZC_ACK_REMEMBER_WARPPOINT);
		ADD_TPKT(0x018f, 11, ZC_ACK_REQMAKINGITEM);
		ADD_TPKT(0x0095, 59, ZC_ACK_REQNAME);
		ADD_TPKT(0x0195, 15, ZC_ACK_REQNAMEALL);
		ADD_TPKT(0x0194, 8, ZC_ACK_REQNAME_BYGID);
		ADD_TPKT(0x018b, 7, ZC_ACK_REQ_DISCONNECT);
		ADD_TPKT(0x00fd, 3, ZC_ACK_REQ_JOIN_GROUP);
		ADD_TPKT(0x0169, 3, ZC_ACK_REQ_JOIN_GUILD);
		ADD_TPKT(0x0110, 4, ZC_ACK_TOUSESKILL);
		ADD_TPKT(0x0098, 60, ZC_ACK_WHISPER);
		ADD_TPKT(0x013b, 23, ZC_ACTION_FAILURE);
		ADD_TPKT(0x0209, 10, ZC_ADD_FRIENDS_LIST);
		ADD_TPKT(0x0124, 4, ZC_ADD_ITEM_TO_CART);
		ADD_TPKT(0x01c5, 10, ZC_ADD_ITEM_TO_CART2);
		ADD_TPKT(0x00f4, 2, ZC_ADD_ITEM_TO_STORE);
		ADD_TPKT(0x01c4, 2, ZC_ADD_ITEM_TO_STORE2);
		ADD_TPKT(0x0104, 15, ZC_ADD_MEMBER_TO_GROUP);
		ADD_TPKT(0x01e9, 2, ZC_ADD_MEMBER_TO_GROUP2);
		ADD_TPKT(0x0111, 6, ZC_ADD_SKILL);
		ADD_TPKT(0x021c, 6, ZC_ALCHEMIST_POINT);
		ADD_TPKT(0x021a, 8, ZC_ALCHEMIST_RANK);
		ADD_TPKT(0x0139, 31, ZC_ATTACK_FAILURE_FOR_DISTANCE);
		ADD_TPKT(0x013a, 6, ZC_ATTACK_RANGE);
		ADD_TPKT(0x0147, 6, ZC_AUTORUN_SKILL);
		ADD_TPKT(0x01cd, 6, ZC_AUTOSPELLLIST);
		ADD_TPKT(0x0163, 8, ZC_BAN_LIST);
		ADD_TPKT(0x021b, 15, ZC_BLACKSMITH_POINT);
		ADD_TPKT(0x0219, 6, ZC_BLACKSMITH_RANK);
		ADD_TPKT(0x009a, 57, ZC_BROADCAST);
		ADD_TPKT(0x01c3, 58, ZC_BROADCAST2);
		ADD_TPKT(0x00ee, 11, ZC_CANCEL_EXCHANGE_ITEM);
		ADD_TPKT(0x0122, 7, ZC_CART_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0297, 2, ZC_CART_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x0123, 5, ZC_CART_NORMAL_ITEMLIST);
		ADD_TPKT(0x0230, 3, ZC_CHANGESTATE_MER);
		ADD_TPKT(0x01a4, -1, ZC_CHANGESTATE_PET);
		ADD_TPKT(0x009c, -1, ZC_CHANGE_DIRECTION);
		ADD_TPKT(0x00b6, -1, ZC_CLOSE_DIALOG);
		ADD_TPKT(0x00f8, 12, ZC_CLOSE_STORE);
		ADD_TPKT(0x01d2, 19, ZC_COMBODELAY);
		ADD_TPKT(0x0144, 6, ZC_COMPASS);
		ADD_TPKT(0x00ec, 20, ZC_CONCLUDE_EXCHANGE_ITEM);
		ADD_TPKT(0x01ea, 6, ZC_CONGRATULATION);
		ADD_TPKT(0x0141, 9, ZC_COUPLESTATUS);
		ADD_TPKT(0x0137, 86, ZC_DELETEITEM_FROM_MCSTORE);
		ADD_TPKT(0x020a, 6, ZC_DELETE_FRIENDS);
		ADD_TPKT(0x0125, -1, ZC_DELETE_ITEM_FROM_CART);
		ADD_TPKT(0x00f6, 7, ZC_DELETE_ITEM_FROM_STORE);
		ADD_TPKT(0x0105, 3, ZC_DELETE_MEMBER_FROM_GROUP);
		ADD_TPKT(0x00d8, 2, ZC_DESTROY_ROOM);
		ADD_TPKT(0x01cf, 23, ZC_DEVOTIONLIST);
		ADD_TPKT(0x0132, -1, ZC_DISAPPEAR_ENTRY);
		ADD_TPKT(0x01b9, 3, ZC_DISPEL);
		ADD_TPKT(0x00db, 6, ZC_ENTER_ROOM);
		ADD_TPKT(0x00a4, 6, ZC_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0295, 4, ZC_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x013c, 6, ZC_EQUIP_ARROW);
		ADD_TPKT(0x00f0, 3, ZC_EXEC_EXCHANGE_ITEM);
		ADD_TPKT(0x01a3, 32, ZC_FEED_PET);
		ADD_TPKT(0x0201, 11, ZC_FRIENDS_LIST);
		ADD_TPKT(0x0206, -1, ZC_FRIENDS_STATE);
		ADD_TPKT(0x0227, 7, ZC_GAME_GUARD);
		ADD_TPKT(0x0101, 97, ZC_GROUPINFO_CHANGE);
		ADD_TPKT(0x00fb, 2, ZC_GROUP_LIST);
		ADD_TPKT(0x017f, 35, ZC_GUILD_CHAT);
		ADD_TPKT(0x01b6, 3, ZC_GUILD_INFO2);
		ADD_TPKT(0x016f, 182, ZC_GUILD_NOTICE);
		ADD_TPKT(0x0162, 6, ZC_GUILD_SKILLINFO);
		ADD_TPKT(0x0235, 44, ZC_HOSKILLINFO_LIST);
		ADD_TPKT(0x0239, 8, ZC_HOSKILLINFO_UPDATE);
		ADD_TPKT(0x017b, 3, ZC_ITEMCOMPOSITION_LIST);
		ADD_TPKT(0x0177, 27, ZC_ITEMIDENTIFY_LIST);
		ADD_TPKT(0x00a1, 6, ZC_ITEM_DISAPPEAR);
		ADD_TPKT(0x009d, 13, ZC_ITEM_ENTRY);
		ADD_TPKT(0x009e, -1, ZC_ITEM_FALL_ENTRY);
		ADD_TPKT(0x00a0, 28, ZC_ITEM_PICKUP_ACK);
		ADD_TPKT(0x029a, 8, ZC_ITEM_PICKUP_ACK2);
		ADD_TPKT(0x00af, 26, ZC_ITEM_THROW_ACK);
		ADD_TPKT(0x0238, 27, ZC_KILLER_RANK);
		ADD_TPKT(0x00b1, 2, ZC_LONGPAR_CHANGE);
		ADD_TPKT(0x018d, 8, ZC_MAKABLEITEMLIST);
		ADD_TPKT(0x01ad, -1, ZC_MAKINGARROW_LIST);
		ADD_TPKT(0x0154, 7, ZC_MEMBERMGR_INFO);
		ADD_TPKT(0x00dd, 10, ZC_MEMBER_EXIT);
		ADD_TPKT(0x00dc, 6, ZC_MEMBER_NEWENTRY);
		ADD_TPKT(0x00b7, 42, ZC_MENU_LIST);
		ADD_TPKT(0x0196, -1, ZC_MSG_STATE_CHANGE);
		ADD_TPKT(0x010c, 282, ZC_MVP);
		ADD_TPKT(0x010a, 4, ZC_MVP_GETTING_ITEM);
		ADD_TPKT(0x010b, 3, ZC_MVP_GETTING_SPECIAL_EXP);
		ADD_TPKT(0x014c, 17, ZC_MYGUILD_BASIC_INFO);
		ADD_TPKT(0x00a3, 65, ZC_NORMAL_ITEMLIST);
		ADD_TPKT(0x01ee, -1, ZC_NORMAL_ITEMLIST2);
		ADD_TPKT(0x02e1, -1, ZC_NOTIFY_ACT2);
		ADD_TPKT(0x007a, 5, ZC_NOTIFY_ACTENTRY);
		ADD_TPKT(0x0121, 2, ZC_NOTIFY_CARTITEM_COUNTINFO);
		ADD_TPKT(0x008d, 7, ZC_NOTIFY_CHAT);
		ADD_TPKT(0x0109, 10, ZC_NOTIFY_CHAT_PARTY);
		ADD_TPKT(0x019b, 6, ZC_NOTIFY_EFFECT);
		ADD_TPKT(0x0117, 11, ZC_NOTIFY_GROUNDSKILL);
		ADD_TPKT(0x0106, 26, ZC_NOTIFY_HP_TO_GROUPM);
		ADD_TPKT(0x0075, 30, ZC_NOTIFY_INITCHAR);
		ADD_TPKT(0x0189, 4, ZC_NOTIFY_MAPINFO);
		ADD_TPKT(0x0199, 17, ZC_NOTIFY_MAPPROPERTY);
		ADD_TPKT(0x01d6, 5, ZC_NOTIFY_MAPPROPERTY2);
		ADD_TPKT(0x0086, 14, ZC_NOTIFY_MOVE);
		ADD_TPKT(0x007b, 186, ZC_NOTIFY_MOVEENTRY);
		ADD_TPKT(0x01da, 79, ZC_NOTIFY_MOVEENTRY2);
		ADD_TPKT(0x02ec, 12, ZC_NOTIFY_MOVEENTRY4);
		ADD_TPKT(0x0079, 8, ZC_NOTIFY_NEWENTRY);
		ADD_TPKT(0x01d9, 28, ZC_NOTIFY_NEWENTRY2);
		ADD_TPKT(0x022b, 10, ZC_NOTIFY_NEWENTRY3);
		ADD_TPKT(0x008e, 7, ZC_NOTIFY_PLAYERCHAT);
		ADD_TPKT(0x0087, 26, ZC_NOTIFY_PLAYERMOVE);
		ADD_TPKT(0x01eb, -1, ZC_NOTIFY_POSITION_TO_GUILDM);
		ADD_TPKT(0x019a, 30, ZC_NOTIFY_RANKING);
		ADD_TPKT(0x0114, -1, ZC_NOTIFY_SKILL);
		ADD_TPKT(0x01de, -1, ZC_NOTIFY_SKILL2);
		ADD_TPKT(0x0078, 53, ZC_NOTIFY_STANDENTRY);
		ADD_TPKT(0x01d8, 2, ZC_NOTIFY_STANDENTRY2);
		ADD_TPKT(0x022a, 10, ZC_NOTIFY_STANDENTRY3);
		ADD_TPKT(0x02ee, 81, ZC_NOTIFY_STANDENTRY4);
		ADD_TPKT(0x007c, -1, ZC_NOTIFY_STANDENTRY_NPC);
		ADD_TPKT(0x00f2, 26, ZC_NOTIFY_STOREITEM_COUNTINFO);
		ADD_TPKT(0x007f, 10, ZC_NOTIFY_TIME);
		ADD_TPKT(0x0077, 30, ZC_NOTIFY_UPDATEPLAYER);
		ADD_TPKT(0x0080, -1, ZC_NOTIFY_VANISH);
		ADD_TPKT(0x0093, 11, ZC_NPCACK_ENABLE);
		ADD_TPKT(0x0091, 8, ZC_NPCACK_MAPMOVE);
		ADD_TPKT(0x0092, 10, ZC_NPCACK_SERVERMOVE);
		ADD_TPKT(0x01b0, 2, ZC_NPCSPRITE_CHANGE);
		ADD_TPKT(0x012d, 30, ZC_OPENSTORE);
		ADD_TPKT(0x0142, 30, ZC_OPEN_EDITDLG);
		ADD_TPKT(0x01d4, 6, ZC_OPEN_EDITDLGSTR);
		ADD_TPKT(0x00b0, 10, ZC_PAR_CHANGE);
		ADD_TPKT(0x01ab, -1, ZC_PAR_CHANGE_USER);
		ADD_TPKT(0x0287, 18, ZC_PC_CASH_POINT_ITEMLIST);
		ADD_TPKT(0x00c6, -1, ZC_PC_PURCHASE_ITEMLIST);
		ADD_TPKT(0x0133, -1, ZC_PC_PURCHASE_ITEMLIST_FROMMC);
		ADD_TPKT(0x0136, 30, ZC_PC_PURCHASE_MYITEMLIST);
		ADD_TPKT(0x00ca, 3, ZC_PC_PURCHASE_RESULT);
		ADD_TPKT(0x0135, 2, ZC_PC_PURCHASE_RESULT_FROMMC);
		ADD_TPKT(0x00c7, 90, ZC_PC_SELL_ITEMLIST);
		ADD_TPKT(0x01a6, 2, ZC_PETEGG_LIST);
		ADD_TPKT(0x01aa, 9, ZC_PET_ACT);
		ADD_TPKT(0x0166, -1, ZC_POSITION_ID_NAME_INFO);
		ADD_TPKT(0x022e, 5, ZC_PROPERTY_HOMUN);
		ADD_TPKT(0x01a2, 4, ZC_PROPERTY_PET);
		ADD_TPKT(0x013d, 6, ZC_RECOVERY);
		ADD_TPKT(0x00da, 8, ZC_REFUSE_ENTER_ROOM);
		ADD_TPKT(0x01fc, -1, ZC_REPAIRITEMLIST);
		ADD_TPKT(0x0207, -1, ZC_REQ_ADD_FRIENDS);
		ADD_TPKT(0x0171, 3, ZC_REQ_ALLY_GUILD);
		ADD_TPKT(0x00e5, 10, ZC_REQ_EXCHANGE_ITEM);
		ADD_TPKT(0x01f4, 7, ZC_REQ_EXCHANGE_ITEM2);
		ADD_TPKT(0x00fe, 4, ZC_REQ_JOIN_GROUP);
		ADD_TPKT(0x016a, 32, ZC_REQ_JOIN_GUILD);
		ADD_TPKT(0x023a, 10, ZC_REQ_STORE_PASSWORD);
		ADD_TPKT(0x00aa, 11, ZC_REQ_WEAR_EQUIP_ACK);
		ADD_TPKT(0x00b3, -1, ZC_RESTART_ACK);
		ADD_TPKT(0x0167, 7, ZC_RESULT_MAKE_GUILD);
		ADD_TPKT(0x023c, 21, ZC_RESULT_STORE_PASSWORD);
		ADD_TPKT(0x0148, 54, ZC_RESURRECTION);
		ADD_TPKT(0x00e1, 2, ZC_ROLE_CHANGE);
		ADD_TPKT(0x00d7, 67, ZC_ROOM_NEWENTRY);
		ADD_TPKT(0x00b4, 36, ZC_SAY_DIALOG);
		ADD_TPKT(0x00d2, 30, ZC_SETTING_WHISPER_STATE);
		ADD_TPKT(0x01b3, -1, ZC_SHOW_IMAGE2);
		ADD_TPKT(0x010f, 2, ZC_SKILLINFO_LIST);
		ADD_TPKT(0x010e, 71, ZC_SKILLINFO_UPDATE);
		ADD_TPKT(0x0120, 5, ZC_SKILL_DISAPPEAR);
		ADD_TPKT(0x011f, 60, ZC_SKILL_ENTRY);
		ADD_TPKT(0x01ac, 6, ZC_SKILL_UPDATE);
		ADD_TPKT(0x00c3, 68, ZC_SPRITE_CHANGE);
		ADD_TPKT(0x01d7, 28, ZC_SPRITE_CHANGE2);
		ADD_TPKT(0x020e, 6, ZC_STARSKILL);
		ADD_TPKT(0x0119, 8, ZC_STATE_CHANGE);
		ADD_TPKT(0x0229, 22, ZC_STATE_CHANGE3);
		ADD_TPKT(0x00be, 11, ZC_STATUS_CHANGE);
		ADD_TPKT(0x00bc, 2, ZC_STATUS_CHANGE_ACK);
		ADD_TPKT(0x0088, -1, ZC_STOPMOVE);
		ADD_TPKT(0x0131, -1, ZC_STORE_ENTRY);
		ADD_TPKT(0x00a6, 26, ZC_STORE_EQUIPMENT_ITEMLIST);
		ADD_TPKT(0x0296, 29, ZC_STORE_EQUIPMENT_ITEMLIST2);
		ADD_TPKT(0x00a5, 282, ZC_STORE_NORMAL_ITEMLIST);
		ADD_TPKT(0x01f0, 4, ZC_STORE_NORMAL_ITEMLIST2);
		ADD_TPKT(0x0224, 20, ZC_TAEKWON_POINT);
		ADD_TPKT(0x0226, 22, ZC_TAEKWON_RANK);
		ADD_TPKT(0x01a0, -1, ZC_TRYCAPTURE_MONSTER);
		ADD_TPKT(0x016d, 22, ZC_UPDATE_CHARSTAT);
		ADD_TPKT(0x01f2, 28, ZC_UPDATE_CHARSTAT2);
		ADD_TPKT(0x016c, 4, ZC_UPDATE_GDID);
		ADD_TPKT(0x00c2, 4, ZC_USER_COUNT);
		ADD_TPKT(0x013e, 2, ZC_USESKILL_ACK);
		ADD_TPKT(0x00a8, 6, ZC_USE_ITEM_ACK);
		ADD_TPKT(0x01c8, 4, ZC_USE_ITEM_ACK2);
		ADD_TPKT(0x011a, 6, ZC_USE_SKILL);
		ADD_TPKT(0x00b5, 6, ZC_WAIT_DIALOG);
		ADD_TPKT(0x011c, 3, ZC_WARPLIST);
		ADD_TPKT(0x0097, 33, ZC_WHISPER);
#undef ADD_TPKT
#undef ADD_HPKT
	}

	~ClientPacketLengthTable() { }

};
}
}
#endif /* HORIZON_ZONE_CLIENT_PACKET_LENGTH_TABLE_20080311 */