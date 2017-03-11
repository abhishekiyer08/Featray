#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main()
{
system("clear");

char *export_path = "/sys/class/gpio/export";
char *direction_path  = "/sys/class/gpio/gpio11/direction";
char *value_path = "/sys/class/gpio/gpio11/value";

int fd, ret;
char buff[20];
/******Opening the export file****/
fd = open(export_path, O_WRONLY);

/*****Validation******/
if (fd == -1)
{
perror("open");
exit(1);
}

//Writing the pin number 11 to the file.
strcpy(buff, "11");
ret = write(fd, buff, strlen(buff));

//Closing the file descriptor.
close(fd);

//Writing direction to the file 
fd = open(direction_path, O_WRONLY);

//Validation
if (fd  == -1)
{
perror("open");
exit(2);
}

//Writing the direction of the pin to the direction file.
strcpy(buff, "out");
ret = write(fd, buff, strlen(buff));
close(fd);

fd = open(value_path, O_WRONLY);

if(fd == -1)
{
perror("open");
exit(3);
}

while(1)
{
//Writing  data to value
strcpy(buff, "1");
write(fd, buff, strlen(buff));
printf("Led on\n");

sleep(5);

strcpy(buff, "0");
write(fd, buff, strlen(buff));
printf("Led off\n");
sleep(5);
}

return 0;
}
