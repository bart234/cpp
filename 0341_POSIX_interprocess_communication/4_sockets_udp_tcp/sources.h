#include <array>
#include <iostream>

#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

constexpr auto PORT =       8072;
constexpr auto BUF_SIZE =   16;
