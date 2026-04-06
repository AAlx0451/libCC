#include <unistd.h>
#include <stdlib.h>

extern "C" {
    void __pure_virtual_called() 
    { 
        write(STDOUT_FILENO, "pure virtual method called\n", 27);
        abort(); 
    }
}
