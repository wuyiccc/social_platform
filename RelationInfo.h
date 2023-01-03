/**
 * @author: wuyiccc
 * @date: 2023-01-03 20:36
 */

#ifndef _RELATIONINFO_H
#define _RELATIONINFO_H
#include <string.h>

#include "common/macro.h"
/**
 * 关系存储实体
 */
class RelationInfo {
 private:
  GETSETVAR(int, user_id)
  // 好友人数
  GETSETVAR(int, friend_count)
  // 好友列表
  int friend_list_[10240];
  // 黑名单人数
  GETSETVAR(int, black_count)
  // 黑名单列表
  int black_list_[10240];

 public:
  // 检查好友是否存在
  int CheckFriend(int other_id);
  // 检查是否存在黑名单中
  int CheckBlack(int other_id);
  int AddFriend(int other_id);
  int AddBlack(int other_id);
  int DeleteFriend(int other_id);
  int DeleteBlack(int other_id);
  // 通过下标获取用户
  int GetFriendByIndex(int index);
  int GetBlackByIndex(int index);
};
#endif
