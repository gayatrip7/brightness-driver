#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 

int mouse_read()
{
	int fd, bytes;
	unsigned char data[4];

	const char *pDevice = "/dev/input/mice";

	// Open Mouse
	if((fd = open(pDevice, O_RDWR)) == -1)
	{
		printf("ERROR Opening %s\n", pDevice);
		return -1;
	}

	int left, right;

	// Read Mouse
	bytes = read(fd, data, sizeof(data));

	if(bytes > 0){

		left = data[0] & 0x1;
		right = data[0] & 0x2;

		if(left)
			return 0;
		if(right)
			return 1;
	}
	return -1;
}

