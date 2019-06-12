/* Was needed to make TASE compile in freestanding mode. */
#include <termios.h>

#define termio termios
