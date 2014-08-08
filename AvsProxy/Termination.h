#ifndef __AVS_PROXY_TERMINATION__
#define __AVS_PROXY_TERMINATION__

#include "Com.h"

class Termination
{
public:
	Termination(const pj_str_t &, pj_sock_t);
	~Termination();

	inline pj_str_t GetIp() const { return ip_; }

	void OnLogin(pj_uint16_t);
	void OnLogout(pj_uint16_t);
	void OnLink();
	void OnUnlink();

	pj_str_t       ip_;
	struct event  *tcp_ev_;
	pj_sock_t      tcp_socket_;                     // 客户端套接字
	pj_uint16_t    unique_id_;                      // 客户端ID
	pj_uint8_t     media_mask_;                     // 此客户端关注的媒体类型
	pj_bool_t      active_;                         // 在线状态
	pj_uint8_t     tcp_storage_[MAX_STORAGE_SIZE];  // TCP缓存
	pj_uint16_t    tcp_storage_offset_;             // TCP缓存偏移地址
};

#endif
