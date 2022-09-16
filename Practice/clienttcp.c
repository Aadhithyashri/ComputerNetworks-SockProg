#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define PORT 8080

int main(){
    int sfd, cfd, valread, fact=1;
    struct sockaddr_in cad, sad;
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1){
        printf("Socket creation failed");
        exit(0);
    }

    if(cfd = connect(sfd,(struct sockaddr_in *)&sad, sizeof(sad)) !=0){
        printf("Failed to connect");
        exit(0);
    }
    int num = 6;
    write(sfd, num, sizeof(num));
	printf("message sent\n");
	valread = read(sfd, fact, sizeof(fact));
	printf("%d\n", fact);
	close(cfd);
	return 0;
}