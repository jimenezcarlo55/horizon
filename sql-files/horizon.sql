#           _   _            _
#          | | | |          (_)
#          | |_| | ___  _ __ _ _______  _ __
#          |  _  |/ _ \| '__| |_  / _ \| '_ \
#          | | | | (_) | |  | |/ / (_) | | | |
#          \_| |_/\___/|_|  |_/___\___/|_| |_|
#
# This file is part of Horizon (c).
# Copyright (c) 2018 Horizon Dev Team.
#
# Base Author - Sxyz (sagunxp@gmail.com)
#
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this library.  If not, see <http://www.gnu.org/licenses/>.
#########################################################

CREATE TABLE `game_accounts` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(23) NOT NULL DEFAULT '',
  `hash` varchar(128) NOT NULL DEFAULT '',
  `salt` varchar(16) NOT NULL DEFAULT '',
  `gender` enum('M','F','NA') NOT NULL DEFAULT 'M',
  `email` varchar(39) NOT NULL DEFAULT '',
  `group_id` tinyint(3) NOT NULL DEFAULT 0,
  `state` int(11) unsigned NOT NULL DEFAULT 0,
  `unban_time` int(11) unsigned NOT NULL DEFAULT 0,
  `expiration_time` int(11) unsigned NOT NULL DEFAULT 0,
  `login_count` mediumint(9) unsigned NOT NULL DEFAULT 0,
  `last_login` datetime DEFAULT NULL,
  `last_ip` varchar(100) NOT NULL DEFAULT '',
  `birth_date` date DEFAULT NULL,
  `character_slots` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `pincode` varchar(4) NOT NULL DEFAULT '',
  `pincode_expiry` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `name` (`username`),
  KEY `id` (`id`),
  KEY `email` (`email`),
  KEY `last_ip` (`last_ip`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `characters` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `account_id` int(11) unsigned NOT NULL DEFAULT 0,
  `slot` tinyint(1) NOT NULL DEFAULT 0,
  `name` varchar(30) NOT NULL DEFAULT '',
  `online` tinyint(2) NOT NULL DEFAULT 0,
  `gender` enum('M','F','U') NOT NULL DEFAULT 'U',
  `deleted_at` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name_key` (`name`),
  CONSTRAINT FOREIGN KEY (account_id) REFERENCES game_accounts(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_access_data` (
  `id` int(11) unsigned NOT NULL,
  `unban_time` int(11) unsigned NOT NULL DEFAULT 0,
  `delete_date` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_misc_data` (
  `id` int(11) unsigned NOT NULL,
  `rename_count` tinyint(2) unsigned NOT NULL DEFAULT 0,
  `unique_item_counter` bigint(20) unsigned NOT NULL DEFAULT 0,
  `hotkey_row_index` tinyint(1) unsigned NOT NULL DEFAULT 0,
  `change_slot_count` tinyint(2) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_ui_settings` (
  `id` int(11) unsigned NOT NULL,
  `font` tinyint(1) unsigned NOT NULL DEFAULT 0,
  `show_equip` tinyint(1) unsigned NOT NULL DEFAULT 0,
  `allow_party` tinyint(1) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_family_data` (
  `id` int(11) unsigned NOT NULL,
  `partner_aid` int(11) unsigned NOT NULL DEFAULT 0,
  `father_aid` int(11) unsigned NOT NULL DEFAULT 0,
  `mother_aid` int(11) unsigned NOT NULL DEFAULT 0,
  `child_aid` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_group_data` (
  `id` int(11) unsigned NOT NULL,
  `party_id` int(11) unsigned NOT NULL DEFAULT 0,
  `guild_id` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_companion_data` (
  `id` int(11) unsigned NOT NULL,
  `pet_id` int(11) unsigned NOT NULL DEFAULT 0,
  `homun_id` int(11) unsigned NOT NULL DEFAULT 0,
  `elemental_id` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_status_data` (
  `id` int(11) unsigned NOT NULL,
  `job_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  `base_level` smallint(6) unsigned NOT NULL DEFAULT 1,
  `job_level` smallint(6) unsigned NOT NULL DEFAULT 1,
  `base_experience` bigint(20) unsigned NOT NULL DEFAULT 0,
  `job_experience` bigint(20) unsigned NOT NULL DEFAULT 0,
  `zeny` int(11) unsigned NOT NULL DEFAULT 0,
  `strength` smallint(6) unsigned NOT NULL DEFAULT 0,
  `agility` smallint(6) unsigned NOT NULL DEFAULT 0,
  `vitality` smallint(6) unsigned NOT NULL DEFAULT 0,
  `intelligence` smallint(6) unsigned NOT NULL DEFAULT 0,
  `dexterity` smallint(6) unsigned NOT NULL DEFAULT 0,
  `luck` smallint(6) unsigned NOT NULL DEFAULT 0,
  `maximum_hp` int(11) unsigned NOT NULL DEFAULT 0,
  `hp` int(11) unsigned NOT NULL DEFAULT 0,
  `maximum_sp` int(11) unsigned NOT NULL DEFAULT 0,
  `sp` int(11) unsigned NOT NULL DEFAULT 0,
  `status_points` int(11) unsigned NOT NULL DEFAULT 0,
  `skill_points` int(11) unsigned NOT NULL DEFAULT 0,
  `body_state` int(11) unsigned NOT NULL DEFAULT 0,
  `virtue` tinyint(3) NOT NULL DEFAULT 0,
  `honor` int(11) unsigned NOT NULL DEFAULT 0,
  `manner` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_view_data` (
  `id` int(11) unsigned NOT NULL,
  `hair_style_id` tinyint(4) unsigned NOT NULL DEFAULT 0,
  `hair_color_id` smallint(5) unsigned NOT NULL DEFAULT 0,
  `cloth_color_id` smallint(5) unsigned NOT NULL DEFAULT 0,
  `body_id` smallint(5) unsigned NOT NULL DEFAULT 0,
  `weapon_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  `shield_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  `head_top_view_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  `head_mid_view_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  `head_bottom_view_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  `robe_view_id` smallint(6) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `character_position_data` (
  `id` int(11) unsigned NOT NULL,
  `current_map` varchar(11) NOT NULL DEFAULT 'new_1-1',
  `current_x` smallint(4) unsigned NOT NULL DEFAULT 53,
  `current_y` smallint(4) unsigned NOT NULL DEFAULT 111,
  `saved_map` varchar(11) NOT NULL DEFAULT 'new_1-1',
  `saved_x` smallint(4) unsigned NOT NULL DEFAULT 53,
  `saved_y` smallint(4) unsigned NOT NULL DEFAULT 111,
  PRIMARY KEY (`id`),
  CONSTRAINT FOREIGN KEY (id) REFERENCES characters(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

CREATE TABLE `session_data` (
  `auth_code` int(11) unsigned NOT NULL,
  `game_account_id` int(11) unsigned NOT NULL,
  `client_version` int(11) unsigned NOT NULL DEFAULT '0',
  `client_type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `character_slots` int(11) unsigned NOT NULL DEFAULT '0',
  `group_id` int(11) unsigned NOT NULL DEFAULT '0',
  `connect_time` int(11) unsigned NOT NULL DEFAULT '0',
  `current_server` enum('AUTH','CHAR','ZONE') NOT NULL,
  PRIMARY KEY (`auth_code`),
  KEY `game_account_id` (`game_account_id`),
  CONSTRAINT FOREIGN KEY (game_account_id) REFERENCES game_accounts(id)
) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;
