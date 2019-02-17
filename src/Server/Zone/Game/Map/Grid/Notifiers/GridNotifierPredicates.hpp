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

#ifndef HORIZON_ZONE_GAME_MAP_GRIDNOTIFIERPREDICATES_HPP
#define HORIZON_ZONE_GAME_MAP_GRIDNOTIFIERPREDICATES_HPP

#include "Server/Zone/Game/Entities/Entity.hpp"

class GUIDCheckPredicate
{
public:
	GUIDCheckPredicate(uint32_t guid) : _guid(guid) { }
	bool operator()(std::weak_ptr<Horizon::Zone::Game::Entity> entity)
	{
		return !entity.expired() && (entity.lock()->get_guid() == _guid);
	}

private:
	uint32_t _guid;
};

#endif /* GRIDNOTIFIERPREDICATES_HPP */