#include <iostream>

using namespace std;


class CtagPlayer {
public:
    void SetX( int nX) {

        // 也可不使用this

        this->nX = nX;
    }



    int GetX() {
        return this->nX;
    }

    void SetY(int nY) {
        this->nY = nY;
    }


    int GetY() {
        return this->nY;
    }

    const char* GetNick() {
        return  this->szNick;
    }
private:
    char szNick[64];
    int nX;
    int nY;
};


// 类的成员函数指针类型 

typedef void(CtagPlayer::*P_SET)(int nX);  


int main()
{
    CtagPlayer player;

    while (true)
    {
        char ch;
        cin >> ch;
        switch (ch)
        {
        case 'a':
            player.SetX(player.GetX() - 1);
            break;
        case 'd':
            player.SetX(player.GetX() + 1);
            break;
        case 'w':
            player.SetY(player.GetY() + 1);
            break;
        case 's':
            player.SetY(player.GetY() - 1);
            break;
        default:
            break;
        }
        std::cout << player.GetNick() << ":"
            << "x:" << player.GetX()
            << "y:" << player.GetY()
            << std::endl;
    }


    // 使用类的成员函数指针
    P_SET p_set = &CtagPlayer::SetX;

    (player.*p_set)(10);

    std::cout << "Hello World!\n" << std::endl;
}
