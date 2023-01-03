/**
 * @author: wuyiccc
 * @date: 2023-01-03 22:15
 */

#ifndef _PHOTOINFO_H
#define _PHOTOINFO_H
#include "common/macro.h"

/**
 * 最近一次发送的消息存储实体
 */
class PhotoInfo {
  GETSETVAR(int, user_id)
  // 最近一个人发送的消息
  GETSETVAR(int, last_pusher)
};
#endif
