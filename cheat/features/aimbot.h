#pragma once

/*
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
*/
#include "../core/interfaces.h"
#include "../sdk/data/matrix.h"
#include <vector>
#include <algorithm>
#define PI 3.1415927f

class Aimbot {
private:
    struct vec3
    {
        float x, y, z;
    };

    vec3 Subtract(vec3 src, vec3 dst)
    {
        vec3 diff;
        diff.x = src.x - dst.x;
        diff.y = src.y - dst.y;
        diff.z = src.z - dst.z;
        return diff;
    }

    float Magnitude(vec3 vec)
    {
        return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    }

    float Distance(vec3 src, vec3 dst)
    {
        vec3 diff = Subtract(src, dst);
        return Magnitude(diff);
    }

    /*
    vec3 CalcAngle(vec3 src, vec3 dst)
    {
        vec3 angle;
        angle.x = -atan2f(dst.x - src.x, dst.y - src.y) / PI * 180.0f + 180.0f;
        angle.y = asinf((dst.z - src.z) / Distance(src, dst)) * 180.0f / PI;
        angle.z = 0.0f;
        return angle;
    }
    */
    void clampAngle(vec3& angle) {
        std::clamp(angle.x, -89.f, 89.f);
        std::clamp(angle.y, -180.f, 180.f);
        angle.z = 0.0f;
    }

    void normalise(vec3& angle) {
        if (angle.x > 89.0f) angle.x -= 180.0f;
        if (angle.x < -89.0f) angle.x += 180.0f;
        angle.y = std::remainderf(angle.y, 360.0f);
    }

    vec3 calcAngle(const vec3& source, const vec3& destination) {
        vec3 retAngle;
        vec3 delta = Subtract(source, destination);
        float hyp = sqrtf(delta.x * delta.x + delta.y * delta.y);
        retAngle.x = (float)(atan(delta.z / hyp) * (180.0f / PI));
        retAngle.y = (float)(atan(delta.y / delta.x) * (180.0f / PI));
        retAngle.z = 0.f;
        if (delta.x >= 0.f)
            retAngle.y += 180.f;

        return retAngle;
    }

public:
	void OnCreateMove(UserCmd* cmd);
};
