#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{

	for(int i=0; i<5; i++)
	{
		if(fork() == 0)
		{
			sleep(500);
			exit();
		}
	}

	if(fork() == 0)
	{
		char *args[] = {"ps", 0};
		
		exec("./ps", args);
	
		printf(1, "Exec failed \n");
		exit();
	}

	while(wait() > 0);

	exit();
}