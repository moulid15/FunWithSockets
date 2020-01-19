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
  struct sockaddr_rc server={0};
  char *message = "server time baby";
  char server_reply[1024];
  char *Mac = "AC:ED:5C:B4:3D:5D";

  //Create socket
  // while(1){
  socket_desc = socket(AF_BLUETOOTH , SOCK_STREAM , BTPROTO_RFCOMM);
  if (socket_desc == -1)
  {
    printf("Could not create socket");
  }

  server.rc_family = AF_BLUETOOTH;
  server.rc_channel = (uint8_t)1;
  str2ba(Mac,&server.rc_bdaddr);


  //Connect to remote server


  // puts("Connected\n");
  if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
  {

    puts("connect error1");
    return 1;
  }
  //recieve some data
      // bzero( message, strlen(message)+1);
      // memset(message ,0 , 1024);
     // // bzero( server_reply, 1024);
     // fgets(message,strlen(message)+1,stdin);
    // write(socket_desc, message , strlen(message)+1);
    // puts("sent");
    // if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0)
   // {
   //
    //  puts("connect error1");
    //  return 1;
   // }
   read(socket_desc, &server_reply , 1040);
    if(recv(socket_desc, &server_reply , 2000 , 0)<0){
      return 1;
    }else{
    puts("Reply received\n");
    puts(server_reply);
  //   memset(server_reply ,0 , 2000);
  // 	sleep(3);
  //
  }
// }


puts("Done");
close(socket_desc);
  return 0;
}
