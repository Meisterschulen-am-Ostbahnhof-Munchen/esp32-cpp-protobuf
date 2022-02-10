#include <sstream>
#include <utility>
#include <inttypes.h>
#include <string>


extern "C" {
    void app_main(void);
}

void try_addressbook_main(void);

void app_main(void) 
{

	try_addressbook_main();
}
