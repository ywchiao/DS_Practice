
#include <iostream>

#include "role.h"

void Role::dump() {
    cout << "目前狀態 ---" << endl;
    cout << "  name:               " << name << endl;
    cout << "  level:              " << level << endl;
    cout << "  hp (HitPoint):      " << hp << endl;
    cout << "  ap (Attack Power):  " << ap << endl;
    cout << "  dp (Defence Power): " << dp << endl;
    cout << "  sp (Spirit Power):  " << sp << endl;
}
