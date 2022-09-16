#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
#define PORT 9100
#define MAXLINE 1024 

struct dns {
	char url[100];
	char ip[20];
}arr[5];


int main() {
	
	int s_fd,len,n,flag = 0,i;
	char buffer[1024] = {0};
	struct sockaddr_in sadr,cadr;
	s_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (s_fd < 0) {
		printf("socket error");
		return -1;
	}
	memset(&sadr,0,sizeof(sadr));
	memset(&cadr,0,sizeof(cadr));

	sadr.sin_family = AF_INET;
	sadr.sin_port = htons(PORT);
	sadr.sin_addr.s_addr = INADDR_ANY;

	if(bind(s_fd,(const struct sockaddr*)&sadr,sizeof(sadr)) < 0) {
		printf("bind error");
		return -1;
	}

	len = sizeof(cadr);
	strcpy(arr[0].url,"www.google.com");
	strcpy(arr[0].ip,"142.250.182.110");
	strcpy(arr[1].url,"www.youtube.com");
	strcpy(arr[1].ip,"142.250.195.206");
	strcpy(arr[2].url,"www.yahoo.com");
	strcpy(arr[2].ip,"74.6.231.21");
	strcpy(arr[3].url,"www.bing.com");
	strcpy(arr[3].ip,"204.79.197.200");
	strcpy(arr[4].url,"www.gmail.com");
	strcpy(arr[4].ip,"216.58.196.165");
	strcpy(arr[5].ip,"Not Found");
	

	n = recvfrom(s_fd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cadr, &len); 
    buffer[n] = '\0'; 
    printf("Client : %s\n", buffer);

    FILE *f = fopen("dns.txt","r");
    int i = 1;

    if (f==NULL){
        printf("File not found");
        exit(EXIT_FAILURE);
    }

    while()

	for(i =0; i<5;i++) {
		if(strcmp(buffer, arr[i].url) == 0){
			flag = 1;
			break;
		}
	} 
    	sendto(s_fd, (const char *)arr[i].ip, strlen(arr[i].ip),MSG_CONFIRM, (const struct sockaddr *) &cadr, len); 
        close(s_fd);
    	return 0; 

}