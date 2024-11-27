#include <iostream> 
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std; 

class tic
{
private:
    char board[3][3];
    int c[9];
    int l[9];
    int size_c;
    int po_c;
    int po_l;
    char po;
public:
    tic();
    void drawboard();
    bool checkwin(char player);
    void available();
    int play_ro();
    int game();
};
