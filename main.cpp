#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
#include <unistd.h>

int main()
{
   int fd, result;

   fd = wiringPiI2CSetup(0x10);

   std::cout << "Init result: "<< fd << std::endl;

   for(int i = 0; i < 0x0000ffff; i++)
   {

     result = wiringPiI2CWriteReg16(fd, 0x0000, i) ;

      if(result == -1)
      {
         std::cout << "Error.  Errno is: " << errno << std::endl;
      }
	usleep(100000);
   }
}
