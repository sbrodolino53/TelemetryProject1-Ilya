#include "logged.h"
#include "../thirdparty/imgui/misc/cpp/imgui_stdlib.h"
#include "state.h"
#include <time.h>
#include <iostream>
namespace Logged
{
	float color[4] = {0, 0, 0, 1};
	void ShowLogout()
	{
		ImGui::Begin("##Logout");
		ImGui::SetWindowSize(ImVec2(0,0));
		if (ImGui::Button("Logout"))
			State::SetState(0);
		ImGui::End();
	}
	void ShowStuff()
	{
		int state = State::GetState();
		if (state == 1) //admin
		{
			ImGui::Begin("Admin Stuff");
    		ImGui::SetWindowSize(ImVec2(360,500));
			ImGui::Text("   Cose Inutili che solo l'Admin deve sapere   ");
			ImGui::Text("-----------------------------------------------");
			ImGui::BeginChild("Scrolling");
			for (int i = 0; i < 100; i++)
				ImGui::Text("%03d: Uau, veramente del testo NON interessante!", i + 1);
			ImGui::EndChild();
			ImGui::End();
			ShowLogout();
		}
		else if (state == 2) //maintenance
		{
			ImGui::Begin("Maintenance Stuff");
    		ImGui::SetWindowSize(ImVec2(320,100));
			float points[100];
			for (int i = 0; i < 100; i++)
				points[i] = sinf(i * 0.2f + ImGui::GetTime() * 1.5f);
			ImGui::Text("Uauu che bella la linea della funzione Seno");
			ImGui::PlotLines("##Points", points, 100);
			ImGui::Text("Che belli i dati a caso");
			ImGui::End();
			ShowLogout();
		}
		else if (state == 3) //user
		{
			ImGui::Begin("User Stuff");
    		ImGui::SetWindowSize(ImVec2(510,90));
			ImGui::Text("Scegli un Colore perché i colori sono belli");
			ImGui::ColorEdit4("Color", color);
			ImGui::Text("Se vuoi fare/vedere altre cose chiedi le credenziali admin o mantainer");
			ImGui::End();
			ShowLogout();
		}
		else
		{
			std::cout << "wrong state or user not loggedIn";
		}
	}
}