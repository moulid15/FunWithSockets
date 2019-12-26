#include <signal.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <sys/types.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc, char const *argv[]) {
  int sock1;
  struct sockaddr_rc server={ 0 }, server2 = { 0 };
  char message[1024];
  int	connfd;
  int n;

  socklen_t opt = sizeof(server2);
  sock1 = socket(AF_BLUETOOTH,SOCK_STREAM,BTPROTO_RFCOMM);
  if(sock1 < 0){
    perror("can't create socket");
  }

	server.rc_family = AF_BLUETOOTH;
	server.rc_channel = (uint8_t)1;
  server.rc_bdaddr = *BDADDR_ANY;
  bind(sock1, (struct sockaddr*)&server,sizeof(server));


  listen(sock1,1);
  while(1){
      memset(message,0,1024);
      connfd = accept(sock1, (struct sockaddr *)&server2, &opt);
      scanf("%[^\n]%*c", message);
      send(connfd,message,strlen(message)+1,0);
  }
    close(sock1);
    close(connfd);

  return 0;
}
