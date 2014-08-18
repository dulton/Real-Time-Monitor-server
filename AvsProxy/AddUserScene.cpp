#include "AddUserScene.h"

AddUserParameter::AddUserParameter(const pj_uint8_t *storage, pj_uint16_t storage_len)
	: UdpParameter(storage, storage_len)
{
	pj_ntoh_assign(storage, storage_len, user_id_);
}

void AddUserScene::Maintain(UdpParameter *parameter, RoomMgr *mgr)
{
	RETURN_IF_FAIL( parameter != nullptr && mgr != nullptr );

	AddUserParameter *param = reinterpret_cast<AddUserParameter *>(parameter);

	/*room->OnAddUser(param->user_id_);*/
}
