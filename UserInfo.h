/**
 * @author: wuyiccc
 * @date: 2023-01-03 19:26
 */

#ifndef _USERINFO_H
#define _USERINFO_H

#include <string.h>

#include "common/macro.h"

/**
 * 用户存储实体
 */
class UserInfo {
 public:
 private:
  GETSETVAR(int, user_id)
  GETSETSTR(256, user_name)
  GETSETSTR(256, nick_name)
  GETSETVAR(int, reg_time)
  // 渠道来源
  GETSETVAR(int, from)
  GETSETVAR(int, login_time)
  // 最近一次登录时间
  GETSETVAR(int, last_login_time)
  // 上次刷新时间
  GETSETVAR(int, fresh_time)
  GETSETSTR(256, password);
  // 登出时间
  GETSETVAR(int, logout_time);
  // 最近一次与数据库交互时间
  GETSETVAR(int, db_flag);
};

#endif
