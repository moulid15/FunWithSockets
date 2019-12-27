	//strlen
#include <signal.h>
#include <unistd.h>
#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <sys/types.h>
#include <time.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc , char *argv[])
{

	int socket_desc;
	int ret;
	struct sockaddr_rc server={0};
	char *message , server_reply[2000];
	char *Mac = "AC:ED:5C:B4:3D:5D";
	//Create socket


	socket_desc = socket(AF_BLUETOOTH , SOCK_STREAM , BTPROTO_RFCOMM);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}

	server.rc_family = AF_BLUETOOTH;
	server.rc_channel = (uint8_t)1;
	str2ba(Mac,&server.rc_bdaddr);
	printf("yess....\n");

	//Connect to remote server


	// puts("Connected\n");
  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
  {

    puts("connect error1\n");
		return 1;

  }
	// printf("get out connect\n" );
	//Send some data
		// connect(socket_desc , (struct sockaddr *)&server , sizeof(server));

while(1){
		// memset(server_reply ,0 , 2000);
		puts("again");
    if((ret=(recv(socket_desc, server_reply , 2000,0 )))==0){
      return 1;
    }else if(ret < 0){
			puts("yes");
			close(socket_desc);
			return 2;
		}else{
    puts("Reply received\n");
  	puts(server_reply);
		puts("print this");
		socket_desc = socket(AF_BLUETOOTH , SOCK_STREAM , BTPROTO_RFCOMM);
		if (socket_desc == -1)
		{
			printf("Could not create socket");
		}

		server.rc_family = AF_BLUETOOTH;
		server.rc_channel = (uint8_t)1;
		str2ba(Mac,&server.rc_bdaddr);
		// sleep(3);
	}
	connect(socket_desc , (struct sockaddr *)&server , sizeof(server));
		memset(server_reply ,0 , 2000);
		puts("memset");
	}
// 		if(recv(socket_desc, server_reply , 2000,0 )<0){
// 			puts("nothing");
//       return 1;
//     }else{
//     puts("Reply received\n");
//   	puts(server_reply);
//
//
//
// 	// }
// 	// puts("connect error");
// }

puts("recv failed");

// close(socket_desc);
	return 0;
}
