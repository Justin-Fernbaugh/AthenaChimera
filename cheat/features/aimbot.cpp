
#include "aimbot.h"

#include "../other/render.h"
#include "../sdk/definitions.h"

#include "../sdk/data/vector.h"
#include "../sdk/data/utlvector.h"

#include "../sdk/data/matrix.h"
#include "../sdk/classes/usercmd.h"
#include "../sdk/sdk.h"
#include "../core/hooks.h"
#include "../sdk/data/QAngle.hpp"

#include "../core/variables.h"

void Aimbot::OnCreateMove(UserCmd* cmd)
{
    if (!v::aimbot.AimbotEnable)
        return;
    //ImGui::io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    

    for (const auto& player : g::entities.playerList) {
        if (!g::localPlayer)
            return;

        if (player->IsDormant() || !player->IsAlive())
            continue;
        if (!(i::entity))
            continue;

        if (g::localPlayer->IsAlive()) {
            const auto target = g::localPlayer->GetObserverTarget();
            if (target == player)
                continue;
        }
        if (player->GetTeam() == g::localPlayer->GetTeam())
            continue;

        //i::engine->GetViewAngles(test);
        Vector localEyePosNew = g::localPlayer->GetEyePosition();
        Vector targetBone = player->GetBonePosition(8);


        vec3 paramVal = { targetBone.x, targetBone.y, targetBone .z };
        vec3 paramValTwo = { localEyePosNew.x, localEyePosNew.y, localEyePosNew.z };

        auto returnVal = calcAngle(paramValTwo, paramVal);
        Vector test = { returnVal.x, returnVal.y, returnVal.z };

        i::engine->SetViewAngles(test); 
        
        if (v::aimbot.AimbotEnable) {
            i::engine->SetViewAngles(test);
        }
        


    }

}