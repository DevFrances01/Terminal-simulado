#include <cstdio>
#include <string>
#include <map>
#include <functional>
#include <iostream>
#include <windows.h>
void printDD()
{
    const std::string cor_vermelha = "\033[1;31m";
    const std::string reset_cor = "\033[0m";
    std::cout << cor_vermelha;
    printf("\n            ____________________________________________");
    printf("\n            |                                          |");
    printf("\n            |                 HELLO                    |");
    printf("\n            |                                          |");
    printf("\n            |  SEJA BEM-VINDO AO Terminal-simulado     |");
    printf("\n            |                                          |");
    printf("\n            |   OBS: ESTE NAO E UM SISTEMA REAL        |");
    printf("\n            |                SE DIVIRTA!               |");
    printf("\n            |        Para iniciar digite: help         |");
    printf("\n            |__________________________________________|\n\n");
    std::cout << reset_cor;
}

void lodboot()
{
    printf("Booting Terminal-simulado...\n");
    Sleep(800);
    Sleep(800);
    printf("[ OK ] Loading lib\n");
    Sleep(800);
    printf("[ OK ] Loading terminal\n");
    Sleep(600);
    printf("[ OK ] Starting services\n");
    Sleep(600);
    printf("[ OK ] Mounting filesystem\n");
    Sleep(600);
    printf("[ OK ]  [-----------------------------]\n");
    Sleep(800);
    printf("[ OK ] System ready\n\n");
}
int main()  
{
    std::string comando;
    std::string user;
    lodboot();
    printDD();
    std::cout << "User name: ";
    std::getline(std::cin, user);
    std::cout << "Hello, " << user << "\n";
    std::map<std::string, std::function<void()>> comandos;
    comandos["help"] = []() {
    printf("\nComandos disponiveis:\n");
    printf("help    - mostrar comandos\n");
    printf("version - versao do sistema\n");
    printf("clear   - limpar tela\n");
    printf("user    - criar/alterar usuario\n");
    printf("exit    - sair\n");
};
comandos["user"] = [&user]() {
    std::string novoUser;

    std::cout << "Digite o nome do novo usuario: ";
    std::getline(std::cin, novoUser);

if (!novoUser.empty()) {
        user = novoUser;
        std::cout << "Usuario alterado com sucesso!\n";
    } else {
        std::cout << "Nome invalido!\n";
    }
};
    comandos["version"] = []() {
        printf("Terminal-simulado v1.0\n");
    };
    comandos["clear"] = []() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printDD();
    };
    while (true)
    {
      std::cout << "\n" << user << "@kernel> ";
        std::getline(std::cin, comando);
        if (comando == "exit")
            break;
        if (comandos.find(comando) != comandos.end())
        {        comandos[comando](); }
        else
        {  printf("Comando desconhecido\n");}
    }
    return 0;
}