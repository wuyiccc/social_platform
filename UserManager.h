/**
 * @author: wuyiccc
 * @date: 2023-01-03 22:20
 */

#ifndef _USERMANAGER_H
#define _USERMANAGER_H
#include "UserInfo.h"
#include "common/macro.h"
class UserManager {
 private:
  UserInfo users_[1024];
  GETSETVAR(int, user_count);
  GETSETVAR(int, cur_user_id);

 public:
  int Start();
  int Proc();
  int Restart();
  int Shutdown();

 public:
  UserInfo *GetUser(int user_id);
  int CheckExists(int user_id);
  int CreateUser(const char *user_name, const char *password, int from,
                 int reg_time);
  int DeleteUser(int user_id);
  // TODO(wuyiccc): 后续实现mysql
  int SaveUser();
  int LoginCheck(const char *user_name, char *password);
  int Userlogout(int user_id, int time_now);
  int GetUserByUserName(const char *user_name);
  int UpdateUserLoginTime(int user_id, int time_now);
  int UpdateUserLogoutTime(int user_id, int time_now);
  int UpdateUserFreshTime(int user_id, int time_now);
};
#endif