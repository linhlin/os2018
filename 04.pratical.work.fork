#include <stdio.h>
#include <unistd.h>

int main(){
	printf("main before fork()\n");
	int pid = fork();
	if(pid == 0){
		int pid1 = fork();
               	if(pid1 == 0){
                        printf("i am a child after fork(), launching free -h\n");
                        char *args1[]  = { "free", "-h", NULL};
                        execvp("free", args1);
                }
                else{
			printf("i am a child after fork(), launching ps -ef\n");
                	char *args[]  = { "/bin/ps", "-ef", NULL};			
                	execvp("/bin/ps", args);
		}
	}
	return 0;

}
