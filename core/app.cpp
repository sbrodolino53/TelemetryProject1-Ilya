#include "app.h"
#include <iostream>
#include "../thirdparty/imgui/misc/cpp/imgui_stdlib.h"
#include "state.h"

char username[256], password[256];

/*void NuovaSchermataMessaggio(char *message, int x, int y)
{
    ImVec2 vec = {(float)x, (float)y};
    ImGui::SetNextWindowSize(vec);
    ImGui::Begin(message);
    ImGui::End();
}*/

int CheckLegth(char *a)
{
    int i = 0;
    while (a[i++]);
    return i;
}

bool CheckForEqual(char *a, char *b)
{
    int i = 0;
    if (CheckLegth(a) != CheckLegth(b))
        return false;
    while (a[i] && b[i])
    {
        if (a[i] != b[i])
            return false;
        i++;
    }
    return true;
}

bool CheckFakeDB(char *user, char *passw)
{                           // 0        1       2
    char *usrnameList[] = {"admin", "main", "user"};
    char *pswdList[] = {"admin123", "main123", "user123"};
    for (int i = 0; i < 3; i++)
    {
        if (CheckForEqual(user, usrnameList[i]) && CheckForEqual(passw, pswdList[i]))
        {
            State::SetState(i + 1);
            return true;
        } 
    }
    return false;
}

void printStr(char *str)
{
    int i = 0;
    while (str[i])
        std::cout << str[i++];
    std::cout << "\n";
}

void Login()
{

    ImGui::Begin("Login Window");
    ImGui::SetWindowSize(ImVec2(300,100));
    ImGui::InputText("Username", username, CHAR_MAX);
    ImGui::InputText("Password", password, CHAR_MAX, ImGuiInputTextFlags_Password);
    if (ImGui::Button("Login"))
    {
        CheckFakeDB(username, password);
        /*printStr(username);
        printStr(password);
        if (CheckFakeDB(username, password))
        {
            printStr("loggato :)");
            //NuovaSchermataMessaggio("Loggato!", 1000, 300);
        }
        else
        {
            //NuovaSchermataMessaggio("Login Errato", 1000, 300);
            printStr("non loggato :(");
        }*/
    }
    ImGui::End();
}
/*
void app_render(){
    //ImGui::Text("Project 1");
    Login();
    if (isLogged)
    {
        CoseACaso();
    }
    
}*/
