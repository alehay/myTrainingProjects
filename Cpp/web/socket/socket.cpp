#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <cstring>

const int PORT = 13;//8000;

int main(){
  int fd = socket(AF_INET6, SOCK_STREAM, 0);
  
  struct sockaddr_in serv_addr; 
  const char *hello = "Hello from client"; 
  char buffer[1024] = {0}; 
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
    printf("\n Socket creation error \n"); 
    return -1; 
  } 
  
  serv_addr.sin_family = AF_INET; 
  serv_addr.sin_port = htons(PORT); 
  
  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0){ 
    printf("\nInvalid address/ Address not supported \n"); 
    return -1; 
  } 
  
  if (connect(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
    printf("\nConnection Failed \n"); 
    return -1; 
  } 
  send(fd , hello , strlen(hello) , 0 ); 
  printf("Hello message sent\n\n"); 
  int valread = read( fd , buffer, 1024); 
  printf("Get time from daytime service: %s\n",buffer ); 
}