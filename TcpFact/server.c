#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SA struct sockaddr
#define max sizeof(int)

int factorial(a){
    if(a>=1){
        return(a*factorial(a-1));
    }
    else{
        return 1;
    }
}

void func(conid){
    int a,b;
    read(conid, &a, max);
    b = factorial(a);
    printf("%d", b);
    write(conid, &b, max);
}

int main(){
    int sockid, conid, len;
    struct sockaddr_in server, client;
    sockid = socket(AF_INET,SOCK_STREAM,0);
    int opt = 1;
    setsockopt(sockid, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt));
    socklen_t serAdd;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9100);
    bind(sockid, (SA *)&server, sizeof(server));
    listen(sockid,5);
    conid = accept(sockid, (SA *)&client, &serAdd);
    func(conid);
    return 0;
}