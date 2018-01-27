//
// Created by SagunKho on 27/01/2018.
//

#ifndef HORIZON_AUTH_PACKETHANDLER20171113_HPP
#define HORIZON_AUTH_PACKETHANDLER20171113_HPP

#include "Server/Common/Horizon.hpp"
#include "Server/Auth/PacketHandler/PacketHandler.hpp"

struct PACKET_CA_LOGIN_OTP_20171113;

namespace Horizon
{
namespace Auth
{
class PacketHandler20171113 : public PacketHandler
{
public:
	explicit PacketHandler20171113(std::shared_ptr<AuthSession> session);
	~PacketHandler20171113() override;

	void Handle_CA_LOGIN_OTP(PacketBuffer &packet) override;
	void InitializeHandlers() override;
};
}
}

/**
 * Overloaded Packet Definitions
 */
#pragma pack(push, 1)
/**
 * Packet structure for CA_LOGIN_OTP.
 */
struct PACKET_CA_LOGIN_OTP_20171113 : public PACKET_CA_LOGIN_OTP
{
	PACKET_CA_LOGIN_OTP_20171113() : PACKET_CA_LOGIN_OTP() { }

	uint32 devFlags{};      ///< flags including dev flag
	char login[25]{};       ///< Username
	char password[32]{};    ///< Password encrypted by rijndael
	char flagsStr[5]{};     ///< Unknown flags. Normally string: G000
};

#pragma pack(pop)

#endif //HORIZON_AUTH_PACKETHANDLER20171113_HPP