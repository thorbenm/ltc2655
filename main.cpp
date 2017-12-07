#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>
#include <unistd.h>

int main()
{
   int current, piezo, result;

   current = wiringPiI2CSetup(0x10);
   piezo = wiringPiI2CSetup(0x12);

//   std::cout << "Init result: "<< fd << std::endl;

for(;;){
for(int j = 0; j < 0x1f ; j++){
 //    result = wiringPiI2CWriteReg16(piezo, 0x0000, j) ;
     result = wiringPiI2CWriteReg16(current, 0x0000, j) ;

      if(result == -1)
      {
         std::cout << "Error.  Errno is: " << errno << std::endl;
      }
	usleep(100000);
}

for(int j = 0x1f; j > 0 ; j--){
//     result = wiringPiI2CWriteReg16(piezo, 0x0000, j) ;
     result = wiringPiI2CWriteReg16(current, 0x0000, j) ;

      if(result == -1)
      {
         std::cout << "Error.  Errno is: " << errno << std::endl;
      }
	usleep(100000);
}
}
}
