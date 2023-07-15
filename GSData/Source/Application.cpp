#include "Application.h"

#include "imgui.h"
#include "Dota2/Dota2Game.h"
#include "Games/CSGO/CSGOGame.h"

Application::Application()
{
    //idea: ability to disable games?
    //Also better way to register games?
    supportedGames[0] = new CSGOGame();
    supportedGames[1] = new Dota2Game();
}

void Application::RenderUI()
{
    //TO DO: fix resizing rerenders
    static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration;
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);

    ImGui::Begin("App", nullptr, flags);
    RenderGamesDropdown();
    RenderMainLayout();
    ImGui::End();

#ifdef _DEBUG
    ImGui::ShowDemoWindow();
#endif
}

void Application::RenderGamesDropdown()
{
    //Set up initial games dropdown box
    const ImGuiComboFlags flags = 0;
    ImGui::Text("Game:");
    ImGui::SameLine();
    const char* previewValue = supportedGames[0]->GetName();

    if (ImGui::BeginCombo(" ", previewValue, flags))
    {
        for (auto game : supportedGames)
        {
            ImGui::Image((void*)(intptr_t)game->GetGameIcon()->iconTexture,
                         ImVec2(game->GetGameIcon()->iconWidth, game->GetGameIcon()->iconHeight));
            ImGui::SameLine();
            ImGui::Selectable(game->GetName(), true);
        }
        ImGui::EndCombo();
    }
}

void Application::RenderMainLayout()
{
    const ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar;
    ImGui::BeginChild("IncomingData", ImVec2(ImGui::GetContentRegionAvail().x * 0.4f, 0), true, flags);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Incoming data"))
        {
            //TO DO: strutured data based on incoming json
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::EndChild();

    ImGui::SameLine();
    ImGui::Button("Button", ImVec2(ImGui::GetContentRegionAvail().x * 0.2f, 0));
    ImGui::SameLine();

    ImGui::BeginChild("OutputData", ImVec2(0, 0), true, flags);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Output data"))
        {
            //TO DO: Infrastructure to visually create desired json
            //TO DO: Infrastructure to connect relevant data and spit out ready to send message
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
    ImGui::EndChild();
}
