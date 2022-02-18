#pragma once


#include "../other/render.h"
#include "../sdk/definitions.h"
#include "../core/interfaces.h"

#include "../sdk/data/vector.h"
#include "../sdk/data/utlvector.h"

#include "../sdk/data/matrix.h"
#include "../sdk/classes/usercmd.h"
#include "../sdk/sdk.h"
#include "../core/hooks.h"
#include "../sdk/data/QAngle.hpp"


class Aimbot {
public:
	void OnCreateMove(UserCmd* cmd);
};
