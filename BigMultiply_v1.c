#include "include/check.h"
#include "include/multiply.h"

// Main code
int main(int argc, char **argv)
{

    if (check_input (argc, argv) == 0 )
    {
        multiply(argv[1], argv[2]);

        return 0;
    }

    else return 1;

}
