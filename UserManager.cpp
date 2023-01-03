/**
 * @author: wuyiccc
 * @date: 2023-01-03 22:30
 */

#include "UserManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/ret_value.h"

int UserManager::Start() {
  set_cur_user_id(10001);
  set_user_count(0);
  // TODO(wuyiccc);
  // read users from db
  // read cur_user_id from db
  return SUCCESS;
}

int UserManager::Proc() { return SUCCESS; }

int UserManager::Restart() { return SUCCESS; }

int UserManager::Shutdown() { return SUCCESS; }

UserInfo* UserManager::GetUser(int user_id) {
  for (int i = 0; i < user_count_; i++) {
    if (users_[i].user_id() == user_id) {
      return &users_[i];
    }
  }
  return NULL;
}

int UserManager::CheckExists(int user_id) {
  for (int i = 0; i < user_count_; i++) {
    if (users_[i].user_id() == user_id) {
      return USER_EXIST;
    }
  }
  return USER_NOT_EXIST;
}

int UserManager::CreateUser(const char* user_name, const char* password,
                            int from, int reg_time) {
  for (int i = 0; i < user_count_; i++) {
    if (strcmp(users_[i].user_name(), user_name) == 0) {
      return USER_EXIST;
    }
  }
  if (user_count_ < 10239) {
    users_[user_count_].set_user_id(cur_user_id());
    users_[user_count_].set_user_name(user_name);
    users_[user_count_].set_password(password);
    users_[user_count_].set_from(from);
    users_[user_count_].set_reg_time(reg_time);
    users_[user_count_].set_db_flag(FLAG_INSERT);
    user_count_++;
  }
  // TODO(wuyiccc):
  set_cur_user_id(cur_user_id() + 1);
  // TODO(wuyicc): save user
  return SUCCESS;
}

int UserManager::DeleteUser(int user_id) {
  for (int i = 0; i < user_count_; i++) {
    if (users_[i].user_id() == user_id) {
      users_[i].set_db_flag(FLAG_DELETE);
      return SUCCESS;
    }
  }
  return USER_NOT_EXIST;
}

int UserManager::SaveUser() { return 0; }

int UserManager::LoginCheck(const char* user_name, char* password) {
  for (int i = 0; i < user_count_; i++) {
    if (strcmp(users_[i].user_name(), user_name) == 0) {
      if (strcmp(users_[i].password(), password) == 0) {
        return SUCCESS;
      } else {
        return WRONG_PASSWORD;
      }
    }
  }
  return USER_NOT_EXIST;
}

int UserManager::Userlogout(int user_id, int time_now) {
  for (int i = 0; i < user_count_; i++) {
    if (users_[i].user_id() == user_id) {
      users_[i].set_logout_time(time_now);
      users_[i].set_db_flag(FLAG_UPDATE);
      return SUCCESS;
    }
  }
  return USER_NOT_EXIST;
}

int UserManager::GetUserByUserName(const char* user_name) { return 0; }

int UserManager::UpdateUserLoginTime(int user_id, int time_now) {
  UserInfo *user = GetUser(user_id);
  if (user == NULL) {
    return USER_NOT_EXIST;
  }
  user->set_logout_time(time_now);
  user->set_db_flag(FLAG_UPDATE);
  return SUCCESS;
}

int UserManager::UpdateUserLogoutTime(int user_id, int time_now) { return 0; }

int UserManager::UpdateUserFreshTime(int user_id, int time_now) { return 0; }
