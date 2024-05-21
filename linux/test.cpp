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
  }

  {
    std::cout << "get_relay_board_count(void); " << std::endl;
    int cnt = get_relay_board_count();
    std::cout << "ret = " << ret << std::endl;

    auto boards = get_relay_boards();
    for (size_t i = 0; i < cnt; i++) {
      std::cout << "path : " << boards[i].path
                << "type : " << (int)(boards[i].module_type)
                << "relay_cnt : " << boards[i].relay_count
                << "serial : " << boards[i].serial
                << "state : " << boards[i].state << std::endl;
    }

    std::cout << "operate_relay(const char *path,unsigned char relay, unsigned "
                 "char state,int debug);  "
              << std::endl;
    auto temp = &boards[0];
    ret = operate_relay(temp->path, 1, CMD_OFF, 1);
    sleep(5);
     ret = operate_relay(temp->path, 1, CMD_ON, 1);
    sleep(2);
  }

  shutdown();
}