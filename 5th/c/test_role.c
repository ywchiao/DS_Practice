
#include "role.h"

int main(int argc, char *argv[]) {
    Role *role = newRole();

    role->dump(role);
}
