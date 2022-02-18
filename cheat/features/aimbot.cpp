
/*
#include "Aimbot.hpp"
#include "valve_sdk/sdk.hpp"
#include "helpers/utils.hpp"
#include "valve_sdk/csgostructs.hpp"

*/
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

void Aimbot::OnCreateMove(UserCmd* cmd)
{
    if (!g::localPlayer)
        return;

    if (!g::localPlayer->IsAlive())
        return;

    for (const auto& player : g::entities.playerList) {
        if (!player)
            continue;
        if (player->IsDormant() || !player->IsAlive())
            continue;
        if (!g::localPlayer->IsAlive()) {
            const auto target = g::localPlayer->GetObserverTarget();
            if (target == player)
                continue;
        }
        if (player->GetTeam() == g::localPlayer->GetTeam())
            continue;

        /*
        auto enemyHitbox = ent->GetHitboxPos(0);
        QAngle localEyePos = g_LocalPlayer->m_angEyeAngles();
        Vector localEyePosNew;

        Math::AngleVectors(localEyePos, localEyePosNew);
        auto viewAngle = Math::CalcAngle(enemyHitbox, localEyePosNew);

        Math::ClampAngles(viewAngle);

        g_EngineClient->SetViewAngles(&viewAngle);
        */
        //auto test = ent->GetHitboxPos(0);
        Vector test;
        i::engine->GetViewAngles(test);
        Vector localEyePosNew = g::localPlayer->GetEyePosition();

        QAngle newTest = { test.x, test.y, test.z };
        //Math::AngleVectors(newTest, localEyePosNew);
        //Vector::RelativeAngle(localEyePosNew, newTest, test);

        //g_EngineClient->SetViewAngles(yours);
        i::engine->SetViewAngles(test);


    }

}