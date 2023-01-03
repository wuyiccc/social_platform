/**
 * @author: wuyiccc
 * @date: 2023-01-03 20:50
 */

#include "RelationInfo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/ret_value.h"

int RelationInfo::CheckFriend(int other_id) {
  for (int i = 0; i < friend_count_; i++) {
    if (friend_list_[i] == other_id) {
      return SUCCESS;
    }
  }
  return NOT_FRIEND;
}

int RelationInfo::CheckBlack(int other_id) { return SUCCESS; }

int RelationInfo::AddFriend(int other_id) {
  if ((CheckFriend(other_id)) == SUCCESS) {
    return ALREADY_FRIEND;
  }

  if (friend_count_ < 10239) {
    friend_list_[friend_count_] = other_id;
    friend_count_++;
  } else {
    return FRIEND_TO_MUCH;
  }
  return SUCCESS;
}

int RelationInfo::AddBlack(int other_id) { return SUCCESS; }

int RelationInfo::DeleteFriend(int other_id) {
  if ((CheckFriend(other_id)) == SUCCESS) {
    for (int i = 0; i < friend_count_; i++) {
      if (friend_list_[i] == other_id) {
        friend_list_[i] == -1;
        for (int j = i; j < friend_count_ - 1; j++) {
          friend_list_[j] = friend_list_[j + 1];
        }
      }
    }
    friend_count_--;
  } else {
    return NOT_FRIEND;
  }
  return SUCCESS;
}

int RelationInfo::DeleteBlack(int other_id) { return SUCCESS; }

int RelationInfo::GetFriendByIndex(int index) {
  if (index < 0 || index > friend_count_) {
    return FRIEND_INDEX_WRONG;
  }
  return friend_list_[index];
}

int RelationInfo::GetBlackByIndex(int index) { return SUCCESS; }
