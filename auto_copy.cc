#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

using namespace std;

int main()
{
	// time_t time0 = time(nullptr);
	// tm* time0_tm = localtime(&time0);
	int child_status;
	pid_t pid = fork();
	do
	{
		if(pid == 0)
		{	
			execl("/bin/expect", "", "nohup_copy.exp", "", NULL);
		}
		else
		{
			cout << "Child " << pid << " Created" << std::endl;
			waitpid(pid, &child_status, 0);
			cout << "Child " << pid << " Exit" << endl;
			pid = fork();
			sleep(1);
		}
	}
	while(true);
	return 0;
}
