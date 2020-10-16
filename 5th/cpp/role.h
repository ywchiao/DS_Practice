
#include <string>

using namespace std;

class Role {
    public:
        Role() {};

        void dump();

    private:
        string name { "路人甲" };     // 姓名
        int level { 1 }; // 等級
        int hp { 100 };  // hit points 血量
        int ap { 1 };    // attack power 攻擊力
        int dp { 3 };    // defence power 防禦力
        int sp { 10 };   // spirit power 精神力
};
