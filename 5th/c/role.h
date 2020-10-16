
typedef struct Role {
    void (* dump)(const struct Role *const);

    char *name; // 姓名
    int level;  // 等級
    int hp;     // hit points 血量
    int ap;     // attack power 攻擊力
    int dp;     // defence power 防禦力
    int sp;     // spirit power 精神力
} Role;

Role *newRole();
