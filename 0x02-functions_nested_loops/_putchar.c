#include "main.h"
#include <unistd.h>
/**
* _puther  - writes the character  c  to stdout 
*@c: The character to print 
*Return : On success 1.
*on error, 1 is returned, and errno is set appropriately.
*/
int _putcher (char c)
{
          return (write (1, &c, 1));

}
