#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>

int LEFT_INDENT = 10;

using namespace std;

/*void printTri(){
    printf("            /\\            \n");
    printf("           /  \\           \n");
    printf("          /    \\          \n");
    printf("         /    * \\         \n");
    printf("        /  *     \\        \n");
    printf("        ---    ---         \n");
    printf("          /  * \\          \n");
    printf("         /      \\          \n");
    printf("        /  *     \\          \n");
    printf("       /       *  \\          \n");
    printf("       ---      ---         \n");
    printf("         /      \\          \n");
    printf("        /  *     \\          \n");
    printf("       /      *   \\          \n");
    printf("      / *         \\          \n");
    printf("      -----   ------         \n");
    printf("           |  |                        \n");
    printf("       -----------                     \n");
    printf("       \\         /                     \n");
    printf("        \\       /      Merry Christmas!  \n");
    printf("         -------                         \n");
}*/

string printTriangle(int height){
    int left = LEFT_INDENT;

    string graph;
    int j = 0;
    string edge(left, ' ');
    string floor;
    int r;
    for(int i = 1;i <= height;++i){
        r = rand() % 4;
        graph += edge + "/" + floor + "\\ \n";
        edge.erase(0, 1);
        if(r == 0){
            floor.insert(0, " *");
        }
        else if(r == 1){
            floor.insert(0, "* ");
        }
        else{
            floor.insert(0, "  ");
        }
        left -= 1;
    }
    string fl(height * 2, '-');
    string li(left, ' ');
    graph += li + " " + fl + "\n"; 
    return graph;
}

string parseTri(string g, int dh){
    stringstream ss(g);
    string tmp;
    int i = dh;
    string ret;
    while(getline(ss, tmp)){
        if(i == 0){
            ret += tmp + "\n";
        }
        else{
            i -= 1;
        }
    }
    return ret;
}

string box(){
    int left = LEFT_INDENT - 5;
    string l(left, ' ');
    string b = 
        l + "    |  |     \n" +
        l + "-------------\n" +
        l + "\\           /\n" +
        l + " \\         / \n" +
        l + "  \\       /  \n" +
        l + "   -------   \n";
    return b;
}

int main(){
    //printTri();
    int layer;
    srand(time(nullptr));
    cout << "你的聖誕樹要幾層? 0離開, 輸入數字喔，不然程式就壞ㄌ: ";
    cin >> layer;
    if(layer <= 0){
        cout << "掰掰!\n";
        return 0;
    }
    if(layer == 1){
        cout << "樹至少兩層喔，幫你變兩層哈哈\n";
        layer = 2;
    }
    LEFT_INDENT = layer * 3;
    cout << printTriangle(layer);
    string l;
    for(int i = 1;i < layer;++i){
        l = printTriangle(layer + i * 2);
        l = parseTri(l, i * 2);
        cout << l;
    }
    cout << box();
    if(layer >= 8){
        cout << string(LEFT_INDENT, ' ') + " 你的樹很大喔, 塞得下嗎？\n";
    }
    else{
        cout << string(LEFT_INDENT, ' ') + " Merry Christmas!\n";
    }
}
