
#include <stdio.h>
#include <stdlib.h>

#include "role.h"

static void dump(const Role *const);

Role *newRole() {
    Role *role = (Role *)malloc(sizeof(Role));

    role->name = "路人甲";     // 姓名
    role->level = 1; // 等級
    role->hp = 100;  // hit points 血量
    role->ap = 1;    // attack power 攻擊力
    role->dp = 3;    // defence power 防禦力
    role->sp = 10;   // spirit power 精神力

    role->dump = dump;

    return role;
}

void dump(const Role *const this) {
    printf("目前狀態 ---\n");
    printf("  name:               %s\n", this->name);
    printf("  level:              %d\n", this->level);
    printf("  hp (HitPoint):      %d\n", this->hp);
    printf("  ap (Attack Power):  %d\n", this->ap);
    printf("  dp (Defence Power): %d\n", this->dp);
    printf("  sp (Spirit Power):  %d\n", this->sp);
}
