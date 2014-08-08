#ifndef __AVS_PROXY_ROOM__
#define __AVS_PROXY_ROOM__

#include <vector>
#include <map>

#include "Com.h"
#include "RoomUser.h"
#include "Termination.h"

using std::map;
using std::vector;

typedef map<pj_int64_t, RoomUser *> user_map_t;
class Room /* same as AVS */
{
public:
	pj_status_t Link();
	pj_status_t Unlink();

	pj_status_t AddUser(pj_int64_t, pj_uint32_t, pj_uint32_t);
	pj_status_t AddUser(pj_int64_t);
	pj_status_t ModUser(pj_int64_t, pj_uint32_t, pj_uint32_t);
	pj_status_t DelUser(pj_int64_t);
	RoomUser *  GetUser(pj_int64_t);
	void        OnRxRtp(pj_int64_t, pj_uint8_t, const vector<pj_uint8_t> &);

private:
	room_id_t  room_id_;
	user_map_t online_users_;    // 此房间的所有上麦用户信息
};

#endif
