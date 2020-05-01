#include <iostream>
#include "ParqueNatural.h"
using namespace std;

int main(){
    Parque miParque;
    miParque.an_ecosistema("tundra");
    miParque.an_ejemplares("tundra", "leon", 3);
    miParque.an_ejemplares("tundra", "jirafa", 5);
    miParque.an_ejemplares("tundra", "rinoceronte", 1);
    miParque.an_ejemplares("tundra", "leon", 1);

    miParque.an_ecosistema("jungla");
    miParque.an_ejemplares("jungla", "mono", 12);
    miParque.an_ejemplares("jungla", "camaleon",3);
    miParque.an_ejemplares("jungla", "leon", 5);
    
    cout << miParque.numero_ejemplares_en_ecosistema("tundra", "rinoceronte") << endl;
    cout << miParque.numero_ejemplares_en_parque("leon") << endl;
    
    return 0;
}