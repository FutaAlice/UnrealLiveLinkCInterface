#include <cstdio>
#include <cmath>
#include <chrono>
#include <thread>

#include <UnrealLiveLinkCInterface.h>

/* number of circles to perform */
#define CIRCLES 30

/* size in Unreal units of the circle on the X-Y plane */
#define CIRCLE_RADIUS 200

/* number of steps to perform the circles */
#define STEP_COUNT 10000

/* Z axis location -- number of units above origin */
#define HEIGHT 100

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main()
{    
    /* check API version */
    if (UnrealLiveLink_GetVersion() != UNREAL_LIVE_LINK_API_VERSION) {
        printf("error: wrong version");
        return 1;
    }

    UnrealLiveLink_InitializeMessagingInterface("CirclingTransform");

	printf("Starting...\n");

	/* set up transform live link role */
	UnrealLiveLink_SetTransformStructure("circle", 0);
	
	/* initialize the per frame transform structure */
	struct UnrealLiveLink_Transform xform;
	UnrealLiveLink_InitTransform(&xform);
	xform.translation[2] = HEIGHT;

	/* calculate the radian step */
	const double step = 2.0 * M_PI * CIRCLES / STEP_COUNT;

	/* loop STEP_COUNT times sending data every 16ms (not exact) */
    double angle = 0.0;
    double worldTime = 0.0;
	for (int i = 0; i < STEP_COUNT; i++)
	{
		xform.translation[0] = (float)sin(angle) * CIRCLE_RADIUS;
		xform.translation[1] = (float)cos(angle) * CIRCLE_RADIUS;

		UnrealLiveLink_UpdateTransformFrame("circle", worldTime, 0, 0, &xform);
		
		angle += step;
		
		/* sleep 16ms */
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
		worldTime += 16.0;
	}

    UnrealLiveLink_UninitializeMessagingInterface();
	return 0;
}

