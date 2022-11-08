#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MC_PORT 5435
#define BUF_SIZE 64000

//structure of song info
struct song_info
{
	  char song_name[ 50 ];
	  uint16_t remaining_time_in_sec;
	  char next_song_name[ 50 ];
};

int main(int argc, char * argv[])
{
	  int s; // socket descriptor 
	  struct sockaddr_in sin; // socket struct 
	  char buf[BUF_SIZE];
	  int len;
	  socklen_t sin_len;
	  sin_len = sizeof(sin);
	  
	  // Multicast specific 
	  char *mcast_addr; // multicast address 
	  char * video[5]; 
	  
	  //Array of video names
	  video[0] = "vid1.mp4";
	  
	  	  if (argc==2) 
	  {
		 	mcast_addr = argv[1];
	  }
	  else 
	  {
			 fprintf(stderr, "usage: sender multicast_address\n");
			 exit(1);
	  }
	  
	  if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) 	//Create socket
	  {
			 perror("server UDP: socket");
			 exit(1);
  	  }
  
	  // build address data structure 
	  memset((char *)&sin, 0, sizeof(sin));
	  sin.sin_family = AF_INET;
	  sin.sin_addr.s_addr = inet_addr(mcast_addr);
	  sin.sin_port = htons(MC_PORT);

	  printf("Connected in first station\n\n ");
	  memset(buf, 0, sizeof(buf));
	  
	  FILE *fp=NULL;	
	  int i;
	  while(1)
	  {
		  	len=strlen(video[0]);
		  	int x=sendto(s,video[0],len,0,(struct sockaddr*)&sin,sin_len); 
	  }
	  return 0;
}