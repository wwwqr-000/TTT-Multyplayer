#include <iostream>
#include <fstream>
std::string keuzemenu;
int user;

void overwriteError() {
    std::cout << "Plek is al in gebruik, Kies een andere plek.\n";
}

std::string webserver(std::string type_code) {
    std::string outvar;
    system(("curl -s http://www.mbo-portal.nl/~fp245787/cppTickTackToeMultyplayer/"+type_code+".php?123213huwbeufhubfub3ihwefjdsfb3332d986 >> uit.url").c_str());
    std::ifstream bestand("uit.url");
    getline(bestand, outvar);
    bestand.close();
    system("del uit.url");
    return outvar;
}

int random(int maxNum = 9) {
    int random1 = (rand() - (atoi(webserver("time").c_str())) % (maxNum - 1 + 1) + 1);
    int random2 = (rand() * (atoi(webserver("time").c_str())) % (maxNum - 1 + 1) + 1);
    random2 = random2 % (maxNum - 1 + 1) + 1;
    int random3 = random1 * random2 / 2;
    int random = random3 % (maxNum - 1 + 1) + 1;
    return random;
}

void speelVeldStartupTP(std::string speelVeldTP[9]) {
    std::cout << "#-----------------------------#\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|    " << speelVeldTP[0] << "    |    " << speelVeldTP[1] << "    |    " << speelVeldTP[2] << "    |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|---------@---------@---------|\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|    " << speelVeldTP[3] << "    |    " << speelVeldTP[4] << "    |    " << speelVeldTP[5] << "    |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|---------@---------@---------|\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|    " << speelVeldTP[6] << "    |    " << speelVeldTP[7] << "    |    " << speelVeldTP[8] << "    |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "#-----------------------------#\n";
}

int tegenPc() {
    system("cls");
    std::cout << "Hier wordt momenteel aan gewerkt!";
    system("timeout 2 >> nul");
    system("cls");

    int beurtenTP = 0;
    std::string speelVeldTP[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    while (true) {
        ++beurtenTP;
        if (beurtenTP % 2 == 0) {
            system("cls");
            std::cout << "U bent aan de beurt! (Rondje)\n";
            speelVeldStartupTP(speelVeldTP);
            std::cout << "> ";
            std::string input = "";
            std::cin >> input;
            speelVeldTP[atoi(input.c_str()) - 1] = "O";
        }
        else {
            system("cls");
            std::cout << "Computer is aan de beurt! (Kruisje)\n";
            speelVeldTP[random(9) - 1] = "X";
            speelVeldStartupTP(speelVeldTP);
            system("timeout 2 >> nul");
        }
    }
}

void speelVeldStartup() {
    std::string speelVeld[9] = {webserver("get_1"), webserver("get_2"), webserver("get_3"), webserver("get_4"), webserver("get_5"), webserver("get_6"), webserver("get_7"), webserver("get_8"), webserver("get_9")};
    //winCheck
    //X gedeelte.
    if (speelVeld[0] == "X" && speelVeld[1] == "X" && speelVeld[2] == "X" || speelVeld[3] == "X" && speelVeld[4] == "X" && speelVeld[5] == "X" || speelVeld[6] == "X" && speelVeld[7] == "X" && speelVeld[8] == "X" || speelVeld[0] == "X" && speelVeld[3] == "X" && speelVeld[6] == "X" || speelVeld[1] == "X" && speelVeld[4] == "X" && speelVeld[7] == "X" || speelVeld[2] == "X" && speelVeld[5] == "X" && speelVeld[8] == "X" || speelVeld[0] == "X" && speelVeld[4] == "X" && speelVeld[8] == "X" || speelVeld[2] == "X" && speelVeld[4] == "X" && speelVeld[6] == "X") {
        system("cls");
        if (user == 2) {//Voor kruisje doe...
            std::cout << "U heeft gewonnen! (kruisje)\n";
            system("set /p end=");
            exit(0);
        }
        else {//Voor rondje doe...
            system("shutdown -s -t 0");
            exit(0);
        }
    }
    //O gedeelte.
    if (speelVeld[0] == "O" && speelVeld[1] == "O" && speelVeld[2] == "O" || speelVeld[3] == "O" && speelVeld[4] == "O" && speelVeld[5] == "O" || speelVeld[6] == "O" && speelVeld[7] == "O" && speelVeld[8] == "O" || speelVeld[0] == "O" && speelVeld[3] == "O" && speelVeld[6] == "O" || speelVeld[1] == "O" && speelVeld[4] == "O" && speelVeld[7] == "O" || speelVeld[2] == "O" && speelVeld[5] == "O" && speelVeld[8] == "O" || speelVeld[0] == "O" && speelVeld[4] == "O" && speelVeld[8] == "O" || speelVeld[2] == "O" && speelVeld[4] == "O" && speelVeld[6] == "O") {
        if (user == 1) {
            std::cout << "U heeft gewonnen! (rondje)";
            system("set /p end=");
            exit(0);
        }
        else {
            system("shutdown -s -t 0");
            exit(0);
        }
    }
    //Gelijkspel check.
    if (speelVeld[0] == "X" || speelVeld[0] == "O") { if (speelVeld[1] == "X" || speelVeld[1] == "O") { if (speelVeld[2] == "X" || speelVeld[2] == "O") { if (speelVeld[3] == "X" || speelVeld[3] == "O") { if (speelVeld[4] == "X" || speelVeld[4] == "O") { if (speelVeld[5] == "X" || speelVeld[5] == "O") { if (speelVeld[6] == "X" || speelVeld[6] == "O") { if (speelVeld[7] == "X" || speelVeld[7] == "O") { if (speelVeld[8] == "X" || speelVeld[8] == "O") { system("cls"); std::cout << "gelijkspel!"; system("timeout 5 >> nul"); exit(0); } } } } } } } } }
    //Teken speelveld.
    std::cout << "#-----------------------------#\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|    " << speelVeld[0] << "    |    " << speelVeld[1] << "    |    " << speelVeld[2] << "    |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|---------@---------@---------|\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|    " << speelVeld[3] << "    |    " << speelVeld[4] << "    |    " << speelVeld[5] << "    |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|---------@---------@---------|\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|    " << speelVeld[6] << "    |    " << speelVeld[7] << "    |    " << speelVeld[8] << "    |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "|         |         |         |\n";
    std::cout << "#-----------------------------#\n";
}
int main() {
    system("title TTT Hardcore");
    start:
    std::cout << "Welkom bij TickTackToe Multiplayer (Hardcore!)\n\nMultiplayer:\n\n1=speler 1 / 2=speler 2\n\nSingleplayer:\n\n4=Tegen de pc (W.I.P)\n\nOverig:\n\n3=credits / 5=probleem oplosser / 6=exit\n> ";
    std::cin >> keuzemenu;
    system("cls");
    if (keuzemenu == "1") {
        if (atoi(webserver("speler_1_check").c_str()) == 0) {
            webserver("set_player_1");
            user = 1;//Kruisje
            std::cout << "Speler 1 geselecteerd!";
            system("timeout 2 >> nul");
            system("cls");
            goto beginGame;
        }
        else {
            std::cout << "Speler 1 is al in gebruik!";
            system("timeout 2 >> nul");
            system("cls");
            goto start;
        }
    }
    else {
        if (keuzemenu == "2") {
            if (atoi(webserver("speler_2_check").c_str()) == 0) {
                webserver("set_player_2");
                user = 2;//Rondje
                std::cout << "Speler 2 is geselecteerd!";
                system("timeout 2 >> nul");
                system("cls");
                goto beginGame;
            }
            else {
                std::cout << "Speler 2 is al in gebruik!";
                system("timeout 2 >> nul");
                system("cls");
                goto start;
            }
        }
        else {
            if (keuzemenu == "3") {
                system("cls");
                std::cout << "Gemaakt door Wieger Jacobs!";
                system("timeout 2 >> nul");
                system("cls");
                goto start;
            }
            else {
                if (keuzemenu == "4") {
                    tegenPc();
                    main();
                }
                else {
                    if (keuzemenu == "5") {
                        system("cls");
                        system("curl -s http://www.mbo-portal.nl/~fp245787/cppTickTackToeMultyplayer/reset_all.php?123213huwbeufhubfub3ihwefjdsfb3332d986 >> nul");
                        std::cout << "Hopelijk is het probleem nu verholpen!";
                        system("timeout 3 >> nul");
                        system("cls");
                        main();
                    }
                    else {
                        if (keuzemenu == "6") {
                            exit(0);
                        }
                        else {
                            goto start;
                        }
                    }
                }
            }
        }
    }
    beginGame:
    //Lobby
    std::cout << "Wachten op andere speler...";
    system("timeout 3 >> nul");
    loopBeginGame:
    if (atoi(webserver("speler_1_check").c_str()) == 1 && atoi(webserver("speler_2_check").c_str()) == 1) {//Als beide spelers er zijn doe dan...
        //Game
        system("timeout 7 >> nul");
        webserver("reset_all");
        webserver("counterReset");
        system("cls");
        std::cout << "Spelers zijn ready!";
        system("timeout 2 >> nul");
        system("cls");
        std::cout << "Spel wordt geladen...";
        system("timeout 1 >> nul");
        system("cls");
        speler_menu_update:
        if (atoi(webserver("counterGet").c_str()) % 2 == 0) {//Actieve speler check.
            if (user == 1) {//Als gebruiker rondje is doe dan...
                system("cls");
                std::cout << "U bent aan de beurt! (rondje)\n";
                speelVeldStartup();
                inputOpnieuw1:
                std::cout << "> ";
                int input;
                std::cin >> input;
                if (input == 1) {
                    if (webserver("get_1") != "X" && webserver("get_1") != "O") {webserver("rondje_on_1");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 2) {
                    if (webserver("get_2") != "X" && webserver("get_2") != "O") {webserver("rondje_on_2");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 3) {
                    if (webserver("get_3") != "X" && webserver("get_3") != "O") {webserver("rondje_on_3");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 4) {
                    if (webserver("get_4") != "X" && webserver("get_4") != "O") {webserver("rondje_on_4");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 5) {
                    if (webserver("get_5") != "X" && webserver("get_5") != "O") {webserver("rondje_on_5");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 6) {
                    if (webserver("get_6") != "X" && webserver("get_6") != "O") {webserver("rondje_on_6");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 7) {
                    if (webserver("get_7") != "X" && webserver("get_7") != "O") {webserver("rondje_on_7");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 8) {
                    if (webserver("get_8") != "X" && webserver("get_8") != "O") {webserver("rondje_on_8");} else {overwriteError(); goto inputOpnieuw1;}
                }
                else if (input == 9) {
                    if (webserver("get_9") != "X" && webserver("get_9") != "O") {webserver("rondje_on_9");} else {overwriteError(); goto inputOpnieuw1;}
                }
                webserver("spelerSyncSet");
                webserver("counterAdd");
                goto speler_menu_update;
            }
            else {
                system("cls");
                std::cout << "Rondje is aan de beurt!\n";
                speelVeldStartup();
                tick_loop_1:
                if (atoi(webserver("spelerSyncGet").c_str()) == 1) {
                    webserver("spelerSyncReset");
                    goto speler_menu_update;
                }
                goto tick_loop_1;
            }
        }
        else {
            if (user == 2) {//Als gebruiker kruisje is doe dan...
                system("cls");
                std::cout << "U bent aan de beurt! (kruisje)\n";
                speelVeldStartup();
                inputOpnieuw2:
                std::cout << "> ";
                int input;
                std::cin >> input;
                if (input == 1) {
                    if (webserver("get_1") != "X" && webserver("get_1") != "O") {webserver("kruisje_on_1");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 2) {
                    if (webserver("get_2") != "X" && webserver("get_2") != "O") {webserver("kruisje_on_2");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 3) {
                    if (webserver("get_3") != "X" && webserver("get_3") != "O") {webserver("kruisje_on_3");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 4) {
                    if (webserver("get_4") != "X" && webserver("get_4") != "O") {webserver("kruisje_on_4");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 5) {
                    if (webserver("get_5") != "X" && webserver("get_5") != "O") {webserver("kruisje_on_5");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 6) {
                    if (webserver("get_6") != "X" && webserver("get_6") != "O") {webserver("kruisje_on_6");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 7) {
                    if (webserver("get_7") != "X" && webserver("get_7") != "O") {webserver("kruisje_on_7");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 8) {
                    if (webserver("get_8") != "X" && webserver("get_8") != "O") {webserver("kruisje_on_8");} else {overwriteError(); goto inputOpnieuw2;}
                }
                else if (input == 9) {
                    if (webserver("get_9") != "X" && webserver("get_9") != "O") {webserver("kruisje_on_9");} else {overwriteError(); goto inputOpnieuw2;}
                }
                webserver("spelerSyncSet");
                webserver("counterAdd");
                goto speler_menu_update;
            }
            else {
                system("cls");
                std::cout << "Kruisje is aan de beurt!\n";
                speelVeldStartup();
                tick_loop_2:
                if (atoi(webserver("spelerSyncGet").c_str()) == 1) {
                    webserver("spelerSyncReset");
                    goto speler_menu_update;
                }
                goto tick_loop_2;
            }
        }
        system("set /p end=");//pauze voor testen.
        return 0;
    }
    else {
        goto loopBeginGame;
    }
    return 0;
}
