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

int main() {
	
	int s_fd,len,n;
	char buffer[1024] = {0};
	char hello[1024] = {0};
	printf("Enter DNS: ");
	scanf("%s",hello);
	struct sockaddr_in sadr;
	s_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (s_fd < 0) {
		printf("socket error");
		return -1;
	}
	memset(&sadr,0,sizeof(sadr));

	sadr.sin_family = AF_INET;
	sadr.sin_port = htons(PORT);
	sadr.sin_addr.s_addr = INADDR_ANY;	
	
    sendto(s_fd, (const char *)hello, strlen(hello),MSG_CONFIRM, (const struct sockaddr *) &sadr, sizeof(sadr)); 
        
	n = recvfrom(s_fd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &sadr, &len); 
    buffer[n] = '\0'; 
    printf("Server : %s\n", buffer); 
	close(s_fd);
    return 0; 

}