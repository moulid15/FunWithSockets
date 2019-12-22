	//strlen
#include <signal.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <sys/types.h>
#include <time.h>
int main(int argc , char *argv[])
{
	int socket_desc;
	struct sockaddr_in server;
	char *message , server_reply[2000];

	//Create socket
  while(1){
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}

	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(9002);

	//Connect to remote server


	// puts("Connected\n");
  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
  {

    puts("connect error1");
  }
	//Send some data

    if(recv(socket_desc, &server_reply , 2000 , 0)<0){
      return 1;
    }else{
    puts("Reply received\n");
  	puts(server_reply);
    memset(server_reply ,0 , 2000);
    sleep(3);

	}
}

puts("recv failed");
puts("connect error");

	return 0;
}
