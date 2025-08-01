#pragma once

// Game info
#define MAX_PLAYERS					32
#define HLDS_APPID					10
#define HLDS_APPVERSION				"1.1.2.7/Stdio"

// Auth constants
#define STEAM_ID_LAN				0
#define STEAM_ID_PENDING			1
#define MAX_STEAMIDSALTLEN			64
#define MAX_AUTHKEY_LEN				128
#define MAX_HASHDATA_LEN			(4 + MAX_STEAMIDSALTLEN + MAX_AUTHKEY_LEN)
#define IPGEN_KEY					0xA95CE2B9

#define LOG_PREFIX					"[REUNION]: "

enum auth_key_kind {
	AK_STEAM,
	AK_VOLUMEID,
	AK_HDDSN,
	AK_FILEID,
	AK_SXEID,
	AK_OTHER,
	AK_MAX
};

enum client_auth_kind {
	CA_UNKNOWN = 0,
	CA_HLTV,
	CA_NO_STEAM_47,			// No auth data was provided by client
	CA_NO_STEAM_48,			// No auth data was provided by client
	CA_SETTI,				// Setti bot
	CA_STEAM,				// Authorized by steam
	CA_STEAM_PENDING,		// Authorized by steam, but ID is STEAM_ID_PENDING
	CA_STEAM_EMU,			// SteamEmu authorization (authorization by serial number of first HDD volume in the system)
	CA_OLD_REVEMU,			// Old RevEmu (authorization by serial number of first HDD volume in the system)
	CA_REVEMU,				// RevEmu (authorization by serial number of first HDD in the system)
	CA_STEAMCLIENT_2009,	// SteamClient (alias for revemu) (authorization by serial number of first HDD in the system)
	CA_REVEMU_2013,			// RevEmu (authorization by serial number of first HDD in the system)
	CA_AVSMP,				// Steam emulator, transmits steamid from Steam without any security/encryption, so it may be easily spoofed
	CA_SXEI,				// Authorization by sXe Injected anticheat ID.

	CA_MAX,
};

enum client_id_kind {
	CI_UNKNOWN = 0,
	CI_REAL_STEAM = 1, //Real STEAM_x:x:x
	CI_REAL_VALVE = 2, //Real VALVE_x:x:x
	CI_STEAM_BY_IP = 3, //STEAM_x:x:x generated by client's IP
	CI_VALVE_BY_IP = 4, //VALVE_x:x:x generated by client's IP
	CI_DEPRECATED = 5, //Client having this id kind will be kicked
	CI_RESERVED = 6,
	CI_HLTV = 7, //HLTV
	CI_STEAM_ID_LAN = 8,
	CI_STEAM_ID_PENDING = 9,
	CI_VALVE_ID_LAN = 10,
	CI_VALVE_ID_PENDING = 11,
	CI_STEAM_666_88_666 = 12,
	CI_MAX = 13,
};

enum reuinon_log_mode {
	rl_none = 0,
	rl_console = 1,
	rl_logfile = 2,
};

enum auth_version {
	av_dproto = 1,
	av_reunion2015 = 2,
	av_reunion2018 = 3,
	av_reunion2024 = 4
};

enum server_answer_type {
	sat_source = 0,
	sat_goldsource = 1,
	sat_hybrid = 2
};

struct client_id_gen_opts_t {
	client_id_kind id_kind;
	size_t prefix1;
	size_t prefix2;
};

enum ipv4_error
{
	ERROR_NO,
	ERROR_IPV4_DATA_OVERFLOW,
	ERROR_IPV4_NO_SYMBOL,
	ERROR_IPV4_INPUT_OVERFLOW,
	ERROR_IPV4_INVALID_SYMBOL,
	ERROR_IPV4_NOT_ENOUGH_INPUT
};

struct ipv4_t
{
	ipv4_t() :
		ip(0),
		port(0)
	{
	}

	ipv4_t(uint8_t (&_ip)[4], uint16_t _port) :
		ipByte{_ip[0], _ip[1], _ip[2], _ip[3]},
		port(_port)
	{
	}

	ipv4_t(uint32_t _ip, uint16_t _port) :
		ip(_ip),
		port(_port)
	{
	}

	union {
		uint32_t ip;
		uint8_t ipByte[4];
	};

	uint16_t port;
};

// Is the IP part of one of the reserved blocks?
inline bool IsReservedAdr(uint32_t ipaddr)
{
	union IPUnion {
		uint32_t ip;
		uint8_t ipByte[4];
	};

	IPUnion addr{};
	addr.ip = ipaddr;

	// IP is stored little endian; for an IP of w.x.y.z, ip[3] will be w, ip[2] will be x, etc
	if ((addr.ipByte[0] == 10) ||													// 10.x.x.x is reserved
		(addr.ipByte[0] == 127) ||													// 127.x.x.x
		(addr.ipByte[0] == 172 && addr.ipByte[1] >= 16 && addr.ipByte[1] <= 31) ||	// 172.16.x.x  - 172.31.x.x
		(addr.ipByte[0] == 192 && addr.ipByte[1] == 168))							// 192.168.x.x
	{
		return true;
	}

	return false;
}
