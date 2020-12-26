#include <iostream>

using namespace std;


typedef struct tagPlayer {
    char szNick[64];
    int nX;
    int nY;
}Player, * Ppalyer;

void SetX(Ppalyer pPlayer, int nX) {
    pPlayer->nX = nX;
}



int GetX(const Ppalyer pPlayer) {
    return pPlayer->nX;
}

void SetY(Ppalyer pPlayer, int nY) {
    pPlayer->nY = nY;
}


int GetY(const Ppalyer pPlayer) {
    return pPlayer->nY;
}

const char* GetNick(const Ppalyer pPlayer) {
    return  pPlayer->szNick;
}


int main()
{

    Player player = { "test", 0, 0 };
    while (true)
    {
        char ch;
        cin >> ch;
        switch (ch)
        {
        case 'a':
            SetX(&player, GetX(&player) - 1);
            break;
        case 'd':
            SetX(&player, GetX(&player) + 1);
            break;
        case 'w':
            SetY(&player, GetY(&player) + 1);
            break;
        case 's':
            SetY(&player, GetY(&player) - 1);
            break;
        default:
            break;
        }
        std::cout << GetNick(&player) << ":"
            << "x:" << GetX(&player)
            << "y:" << GetY(&player)
            << std::endl;
    }

    std::cout << "Hello World!\n" << std::endl;
}
