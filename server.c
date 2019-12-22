#include <signal.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <sys/types.h>

int main(int argc, char const *argv[]) {
  int sock1;
  struct sockaddr_in server;
  char *message[3] = {"hmX10000000","yooo", "connection type beat"};
  int	connfd;
  int n;
  sock1 = socket(AF_INET,SOCK_STREAM,0);
  if(sock1 < 0){
    perror("can't create socket");
  }

  server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(9002);
  bind(sock1, (struct sockaddr*)&server,sizeof(server));

  listen(sock1,30);

for(int i = 0; i<3;i++){
    connfd = accept(sock1, NULL, NULL);
    send(connfd,message[i],strlen(message[i])+1,0);
}
    close(sock1);

  return 0;
}
