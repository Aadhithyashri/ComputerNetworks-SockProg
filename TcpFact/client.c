#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SA struct sockaddr
#define max sizeof(int)

void func(int sockid){
    int a,b;
    printf("Enter number: ");
    scanf("%d", &a);
    write(sockid, &a, max);
    read(sockid, &b, max);
    printf("Answer: %d", b);
}

int main(){
    int sockid;
    struct sockaddr_in server;
    sockid = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9100);

    connect(sockid, (SA*)&server, sizeof(server));
    func(sockid);
    return 0;
}