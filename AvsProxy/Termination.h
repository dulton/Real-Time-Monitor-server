#ifndef __AVS_PROXY_TERMINATION__
#define __AVS_PROXY_TERMINATION__

#include "ClientStructs.h"
#include "Com.h"

class Termination
{
public:
	Termination(const pj_str_t &, pj_sock_t);
	~Termination();

	inline pj_str_t GetIp() const { return ip_; }
	inline pj_uint16_t GetMediaPort() const { return media_port_; }

	void OnLogin(pj_uint16_t, pj_uint16_t);
	void OnLogout(pj_uint16_t);
	void OnLink();
	void OnUnlink();
	void OnKeepAlive(pj_uint16_t, pj_uint16_t);

	pj_str_t       ip_;
	pj_uint16_t    media_port_;
	struct event  *tcp_ev_;
	pj_sock_t      tcp_socket_;                     // �ͻ����׽���
	pj_uint16_t    client_id_;                      // �ͻ���ID
	pj_uint8_t     media_mask_;                     // �˿ͻ��˹�ע��ý������
	pj_bool_t      active_;                         // ����״̬
	pj_uint8_t     tcp_storage_[MAX_STORAGE_SIZE];  // TCP����
	pj_uint16_t    tcp_storage_offset_;             // TCP����ƫ�Ƶ�ַ
};

#endif
