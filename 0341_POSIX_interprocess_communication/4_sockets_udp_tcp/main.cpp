/*
sys/sockets.h

https://www.youtube.com/watch?v=C7CpfL1p6y0
bind together (
socket -> info about internet protocols,
socket_address ->addressing information , ip adress, port number (it is specialized for diffrent protocoles)
socket_addr length
)

sockets are for communictation between computers
-one socket per port
-one app listen usually one port
-do not keep ports open
we can treat sockets like a files: send::recv (network comm)->  write::read (like pipe comm)

we can have faster udp or slower tcp

udp - user data protocole - only propagate, and do not focus on cheking if reciver got data,
      not suitable for larger ammounts of data because of packets' ordering ( content might be misplaced)
wild west - simpler then tcp - it doesnt have state machine below - just send and forget
ssize_t sendTo (int socket, const void *message, 
                size_t msg_length, int flags, 
                const struct sockaddr *dest_addr, 
                socketlen_t dest_len)
ssize_t recvfrom


tcp - slower but more accurate, it check if data was recived correctly, eventualy sent it again
    msg are ordered, connection-oriented but more latency - www base on it
    morec complex then udp: we need to established connection and kernel confirm packet transfer

for client - to send data
    int connect  
for server - listen data and send back
    listen
    accept - if it return new socket - mean you connected with some client
to activly talk client-server
    ssize_t send
    ssize_t recv
to close - to send fin (half-close- we send fin(that is our last package, 
    shutdown
but client sending for me data, and after that he send fin, ans respons about our fin)
to close complitly
    close



INADDR_ANY - used to communicate on single system (like here) and we dont care about adress(port)
*/

#include "local_server_client_udp.h"

int main()
{
    process_creator();
    return 0;
}