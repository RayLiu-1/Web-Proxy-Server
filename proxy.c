#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define BUFSIZE 4096
#define QUESIZE 4// maximum number of client connections
int ListenPort;
char DocumentRoot[200];
char WebPage[10][100];
char ContentType[20][2][100];

void *connection_handler(void *);
int set_config();

int main(int argc, char *argv[]) {
	if (set_config() != 0) {
		perror("set config error");
	}
	if (argc < 1) {
		printf("USAGE:  <proxy_port>\n");
		exit(1);
	}
	int lsfd, cnfd, *sock;
	struct sockaddr_in server, client, proxy;
	lsfd = socket(AF_INET, SOCK_STREAM, 0);
	if (lsfd == -1) {
		perror("Create sock failed");
		return 1;
	}
	puts("Create sock.");

	proxy.sin_family = AF_INET;
	proxy.sin_addr.s_addr = INADDR_ANY;
	if (bind(lsfd, (struct sockddr*)&proxy, sizeof(proxy)) < 0) {
		perror("Bind failed");
		return 1;
	}
	return 0;
}