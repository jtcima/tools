#include <stdio.h>
#include "startup.h"
#include <unistd.h>


void cima(void)
{
    puts("       @@@@@@@       @@@@@@@@@@           @@            @@                  @@  ");
    //sleep(1);
    puts("     @@       @@         @@              @@@@          @@@@                @@@@");
    //sleep(1);
    puts("    @@         @@        @@             @@  @@        @@  @@              @@  @@");
    //sleep(1);
    puts("    @@                   @@            @@    @@      @@    @@            @@    @@");
    //sleep(1);
    puts(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>@created by JT");
    puts("    @@                   @@           @@      @@    @@      @@          @@@@@@@@@@ ");
    puts("    @@         @@        @@          @@        @@  @@        @@        @@        @@ ");
    puts("     @@       @@         @@         @@          @@@@          @@      @@          @@");
    puts("       @@@@@@@       @@@@@@@@@@    @@            @@            @@    @@            @@");
    puts(""); 
    sleep(1);
}



void startup(void)
{
    cima();
}