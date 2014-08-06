#ifndef __AVS_PROXY_TERMINATION__
#define __AVS_PROXY_TERMINATION__

#include "Com.h"

class Termination
{
public:
	Termination(pj_sock_t);
	~Termination();

	void OnLogin(uint16_t, int32_t);
	void OnLogout(uint16_t);
	void OnLink();
	void OnUnlink();

	pj_sockaddr_t *udp_addr_;
	struct event  *tcp_ev_;
	pj_sock_t      tcp_socket_;                     // �ͻ����׽���
	pj_uint16_t    unique_id_;                      // �ͻ���ID
	pj_int32_t     media_port_;                     // �ͻ���ý��˿�
	pj_uint8_t     media_mask_;                     // �˿ͻ��˹�ע��ý������
	pj_bool_t      active_;                         // ����״̬
	pj_uint8_t     tcp_storage_[MAX_STORAGE_SIZE];  // TCP����
	pj_uint16_t    tcp_storage_offset_;             // TCP����ƫ�Ƶ�ַ
};

#endif
