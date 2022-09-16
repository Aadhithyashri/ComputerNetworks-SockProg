#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define PORT 8080

int main(){
    int sfd, newsocket, valread, buffer = 0;
    struct sockaddr_in sad;
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1){
        printf("Cannot create socket");
        exit(0);
    }
    sad.sin_family = AF_INET;
    sad.sin_addr.s_addr = htonl(INADDR_ANY);
    sad.sin_port = htons(PORT);

    if(bind(sfd,(struct sockaddr_in *)&sad,sizeof(sad))!=0){
        printf("Bind failed");
        exit(0);
    }

    if(listen(sfd, 5)!=0){
        printf("Listen Failed");
        exit(0);
    }
    int len = sizeof(sad);
    if(newsocket = accept(sfd,(struct sockaddr_in *)&sad, &len)<0){
        printf("Cannot accept");
        exit(0);
    }

    valread = read(newsocket, buffer, sizeof(buffer));
	printf("%s\n", buffer);
    int fact = 1;
	for(int i=1; i<=buffer; i++){
        fact = fact*i;
    }
	write(newsocket, fact, sizeof(fact));
	printf("Hello message sent\n");
	close(newsocket);
	shutdown(sfd, SHUT_RDWR);
	return 0;
    
}