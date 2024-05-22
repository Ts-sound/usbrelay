#include <unistd.h>

#include <iostream>

#include "libusbrelay.h"

int main() {
  //
  int ret = 0;

  {
    std::cout << "int enumerate_relay_boards(const char *product,int verbose, "
                 "int debug);"
              << std::endl;
    ret = enumerate_relay_boards("", 1, 1);
    std::cout << "ret = " << ret << std::endl;
    std::cout << "---------------------------------" << std::endl;
  }

  {
    std::cout << "get_relay_board_count(void); " << std::endl;
    int cnt = get_relay_board_count();
    std::cout << "cnt = " << cnt << std::endl;
    std::cout << "---------------------------------" << std::endl;

    auto boards = get_relay_boards();
    for (size_t i = 0; i < cnt; i++) {
      std::cout << "\t path : " << boards[i].path
                << "\t type : " << (int)(boards[i].module_type)
                << "\t relay_cnt : " << (int)boards[i].relay_count
                << "\t serial : " <<(char*) &(boards[i].serial)
                << "\t state : " <<  (int)boards[i].state << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    if (cnt < 1) {
      shutdown();
      return 0;
    }

    std::cout << "operate_relay(const char *path,unsigned char relay, unsigned "
                 "char state,int debug);  "
              << std::endl;
    auto temp = &boards[0];
    ret = operate_relay(temp->path, 1, CMD_OFF, 1);
    sleep(5);
    ret = operate_relay(temp->path, 1, CMD_ON, 1);
    sleep(2);

    for (size_t i = 0; i < temp->relay_count; i++) {
      ret = operate_relay(temp->path, i + 1, CMD_ON, 1);
      sleep(4);
      ret = operate_relay(temp->path, i + 1, CMD_OFF, 1);
      sleep(4);
    }
  }

  shutdown();
}