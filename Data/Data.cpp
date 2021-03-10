#include "Common.h"
#include "Utilities.h"

int main()
{
    Family obj_family = Family("Hall");
    util::initialise_family(obj_family);
    std::cout << obj_family.get_family_name() << "\n";
}
