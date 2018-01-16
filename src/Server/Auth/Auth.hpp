//
//  main.h
//  Horizon
//
//  Created by Sagun Khosla on 11/6/17.
//  Copyright © 2017 Horizon. All rights reserved.
//

#ifndef main_hpp
#define main_hpp

#include "AuthSession.hpp"
#include "AuthHandle.h"

#include "Core/Database/MySqlConnection.h"
#include "Logging/Logger.hpp"
#include "Server/Server.hpp"

#include <string>

enum HashingMethods
{
	PASS_HASH_NONE   = 0,
	PASS_HASH_MD5    = 1,
	PASS_HASH_BCRYPT = 2
};

class AuthMain : public Server
{
public:
	AuthMain();
	~AuthMain();

	static AuthMain *getInstance()
	{
		static AuthMain instance;
		return &instance;
	}

	void PrintHeader();

	bool ReadConfig();

	struct network_configuration &getNetConf() { return netconf; }

	/* Auth Configuration Retrieval Methods */
	std::string getConfigFileName() { return auth_file_name; }
	HashingMethods getHashMethod() { return pass_hash_method; }
	std::string getDateFormat() { return date_format; }
	uint32_t getClientVersion() { return client_version; }
	bool isLoggingEnabled() { return log.enabled; }
	uint32_t maxLoginFailures() { return log.login_max_tries; }
	time_t getLoginFailBanTime() { return log.login_fail_ban_time; }
	time_t getLoginFailCheckTime() { return log.login_fail_check_time; }
	uint8_t getMinimumUsernameLength() { return credentials.min_username_length; }
	uint8_t getMaximumUsernameLength() { return credentials.max_username_length; }
	uint8_t getMinimumPasswordLength() { return credentials.min_password_length; }
	uint8_t getMaximumPasswordLength() { return credentials.max_password_length; }

	// Database
	void setDBHost(std::string &host) { database_conf.host = host; }
	void setDBUsername(std::string &username) { database_conf.username = username; }
	void setDBPassword(std::string &password) { database_conf.password = password; }
	void setDBDatabase(std::string &database) { database_conf.database = database; }

	std::string &getDBHost() { return database_conf.host; }
	std::string &getDBUsername() { return database_conf.username; }
	std::string &getDBPassword() { return database_conf.password; }
	std::string &getDBDatabase() { return database_conf.database; }

	void setTestRun() { minimal = true; }
	bool isTestRun() { return minimal; }

	boost::shared_ptr<MySQLConnection> MySQLBorrow()
	{
		return mysql_pool->borrow();
	}

	void MySQLUnborrow(boost::shared_ptr<MySQLConnection> conn)
	{
		mysql_pool->unborrow(conn);
	}

protected:
	/* Auth Configuration */
	struct network_configuration netconf;                            ///< Network Configuration information.
	std::string auth_file_name;                                      ///< Auth Configuration File name.
	enum HashingMethods pass_hash_method = PASS_HASH_NONE;           ///< Password Hashing Method.
	std::string date_format = "%Y-%m-%d %H:%M:%S";                   ///< Date format sent to clients.
	uint32_t client_version = 0;                                     ///< Client version to check. (0 = disabled)

	struct {
		bool enabled = true;                                         ///< Login logging is enabled.
		uint32_t login_max_tries = 3;                                ///< Max login tries.
		time_t login_fail_ban_time = 300;                            ///< 5 Minutes ban time
		time_t login_fail_check_time = 60;                           ///< Save fail information for 1 minute.
	} log;

	struct {
		uint8_t min_username_length =  4;                                 ///< Min Username Length Limit
		uint8_t max_username_length = 32;                                 ///< Max Username Length Limit
		uint8_t min_password_length =  4;                                 ///< Min Password Length Limit
		uint8_t max_password_length = 32;                                 ///< Max Password Length Limit
	} credentials;

	struct {
		std::string host, username, password;
		std::string database;
	} database_conf;

	std::vector<std::string> dns_blacklist;
	boost::shared_ptr<MySQLConnectionFactory> mysql_connection_factory;
	boost::shared_ptr<ConnectionPool<MySQLConnection>> mysql_pool;

	bool minimal;                                                     ///< Specified for test runs.
};

#define AuthServer AuthMain::getInstance()

#endif /* main_hpp */
