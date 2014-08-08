#ifndef __AVS_PROXY_PARAMETER__
#define __AVS_PROXY_PARAMETER__

#include "Com.h"

class TcpParameter
{
public:
	TcpParameter(const pj_uint8_t *&storage, pj_uint16_t &storage_len)
	{
		pj_ntoh_assign(storage, storage_len, length_);
		pj_ntoh_assign(storage, storage_len, type_);
		pj_ntoh_assign(storage, storage_len, proxy_id_);
		pj_ntoh_assign(storage, storage_len, client_id_);
	}

	pj_uint16_t length_;
	pj_uint16_t type_;
	pj_uint16_t proxy_id_;
	pj_uint16_t client_id_;
};

class UdpParameter
{
public:
	UdpParameter(const pj_uint8_t *&storage, pj_uint16_t &storage_len)
	{
		pj_ntoh_assign(storage, storage_len, avs_request_type_);
		pj_ntoh_assign(storage, storage_len, proxy_id_);
		pj_ntoh_assign(storage, storage_len, room_id_);
	}

	pj_uint16_t avs_request_type_;
	pj_uint16_t proxy_id_;
	pj_int32_t  room_id_;
};

#endif
