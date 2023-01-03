/**
 * @author: wuyiccc
 * @date: 2023-01-03 22:16
 */

#ifndef _MESSAGEINFO_H
#define _MESSAGEINFO_H

#include <string.h>

#include "common/macro.h"

/**
 * 消息存储实体
 */
class MessageInfo {
  GETSETVAR(int, user_id)
  GETSETVAR(int, message_id)
  GETSETVAR(int, publish_time)
  GETSETSTR(1024, content)
};
#endif
