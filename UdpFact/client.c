#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define SA struct sockaddr

int main()
{
    struct sockaddr_in serv,cli;
    int sockfd;

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    bzero(&serv,sizeof(serv));
    serv.sin_family=AF_INET;
    serv.sin_addr.s_addr=inet_addr("127.0.0.1");
    serv.sin_port=htons(8080);
    int n1,n2,ans,zz;
    int len=sizeof(serv);
    printf("Enter number : ");
    scanf("%d",&n1);
    sendto(sockfd,&n1,sizeof(int),0,(SA*)&serv,len);

    // printf("Enter 2nd number : ");
    // scanf("%d",&n2);
    // sendto(sockfd,&n2,sizeof(int),0,(SA*)&serv,len);

    recvfrom(sockfd,&ans,sizeof(int),0,(SA*)&serv,&len);
    printf("From Server : answer is : %d\n",ans);

    close(sockfd);
    return 0;

}