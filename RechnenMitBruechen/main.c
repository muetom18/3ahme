#include <stdio.h>
#include <stdlib.h>

int gibGanzeZahlEin(const char *ptxt) {
    
    int zahl = 0;
    char s[40];
    
    printf("%s: ", ptxt);
            
    do {
          fgets(s, 40, stdin); fflush(stdin);
    }      
    while( sscanf(s, "%d", &zahl) != 1);
    
    return zahl;
}

void gibBruchEin(const char *ptxt, int *pzaehler, int *pnenner) {
    
    printf("%s\n", ptxt);
    *pzaehler = gibGanzeZahlEin("Zaehler");
    *pnenner = gibGanzeZahlEin("Nenner");
}

void clscr() {  //Löschen des Bildschirms

    system("clear");
}

void gibMenueAus() {
    
    clscr();
    
    printf("Rechnen mit Bruechen\n"
           "=============================================\n"
           "Addition zweier Brueche......................1\n"
           "Subtraktion zweier brueche...................2\n"
           "Anzahl der Stellen einer Zahl berechnen......3\n"
           "Programmende.................................4\n");
}

void addiereBrueche(int z1, int n1, int z2, int n2, int *ze, int *ne) {
    
    *ze = z1 * n2 + z2 * n1;
    *ne = n1 * n2;
}

void subtrahiereBrueche(int z1, int n1, int z2, int n2, int *ze, int *ne) {
    
    *ze = z1 * n2 - z2 * n1;
    *ne = n1 * n2;
}

int ggT(int a, int b) {
    
    if (a < 0) 
        a = -a;
    if (b < 0) 
        b = -b; 
    if ( (a == 0) || (b == 0) )
            return 1;
        
    while (a != b) {
        
        if(a > b) {
            a -= b; //a = a - b;
            
        } else {
            b -= a; //b = b - a; 
        }
    }
    return a;
}

void kuerzen(int *ze, int *ne) {
    
    int teiler = ggT(*ze, *ne);
    *ze = *ze / teiler;
    *ne = *ne /teiler;
}



void gibBruchAus(char *txt, int ze, int ne) {
    
    printf("%s: \n", txt);
    kuerzen(&ze, &ne);
    printf("%d / %d\n", ze, ne);
}

int main () {
    
    int wahl = 0;
    char s[4] = {0, 0, 0, 0};
    int z1 = 0, n1 = 0, z2 = 0, n2 = 0;
    int ze = 0, ne;
    
    do {
        gibMenueAus();
        //Menüfunktion auswählen
        
        wahl = gibGanzeZahlEin("Waehle die Funktion (1-4)");
        switch(wahl) {
            
            case 1:      //Addieren
                printf("Addieren\n");
                gibBruchEin("Bruch 1", &z1, &n1);
                gibBruchEin("Bruch 2", &z2, &n2);
                addiereBrueche(z1, n1, z2, n2, &ze, &ne);
                gibBruchAus("Ergebnis", ze, ne);
                
                break;
            case 2:      //Subtrahieren
                printf("Subtrahieren\n");
                gibBruchEin("Bruch 1", &z1, &n1);
                gibBruchEin("Bruch 2", &z2, &n2);
                subtrahiereBrueche(z1, n1, z2, n2, &ze, &ne);
                gibBruchAus("Ergebnis", ze, ne);
                        
                break;
            case 3:      //Anzahl der Stellen
                printf("Anzahl der Stellen Berechnen\n");
                z1 = gibGanzeZahlEin("Ihre Zahl");
                break;
            case 4:      //Programmende
                printf("Programmende");
                break;
            default:     //ungueltig
                printf("Die Auswahl %d ist ungueltig!", wahl);
                break;
        }
        if (wahl != 4) {
        
            //Warten bis der Benutzer fortfährt.
            
            fgets(s, 40, stdin); fflush(stdin);
        }
    }
    while(wahl != 4);
    
    return 0;
}

