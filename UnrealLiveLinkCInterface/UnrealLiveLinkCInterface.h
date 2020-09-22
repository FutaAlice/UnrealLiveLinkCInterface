#pragma once

#include "UnrealLiveLinkCInterfaceTypes.h"

#if defined(WIN32) && defined(WITH_EDITOR)
#define APICALL __declspec(dllexport)
#else
#define APICALL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * get the current version of the Unreal Live Link C Interface
 * the version integer is specific to this API and not matching against Unreal Versions
 * @return version of the Unreal Live Link C Interface (UNREAL_LIVE_LINK_API_VERSION value at compile time)
 */
APICALL int UnrealLiveLink_GetVersion();

/**
 * initialize message interface
 * automatically called by UnrealLiveLink_Load() so user does not need to call directly
 * @param interfaceName name of Live Link interface appearing in Unreal
 * @return results (success returns UNREAL_LIVE_LINK_OK)
 */
APICALL int UnrealLiveLink_InitializeMessagingInterface(const char *interfaceName);

/**
 * uninitialize message interface
 * automatically called by UnrealLiveLink_Unload() so user does not need to call directly
 * @param interfaceName name of Live Link interface appearing in Unreal
 * @return results (success returns UNREAL_LIVE_LINK_OK)
 */
APICALL int UnrealLiveLink_UninitializeMessagingInterface();

/**
 * register a function callback if the connection to Unreal changes
 * @param callback callback function
 */
APICALL void UnrealLiveLink_RegisterConnectionUpdateCallback(void (*callback)());

/**
 * connection with Unreal?
 * @return UNREAL_LIVE_LINK_OK if connected, UNREADL_LIVE_LINK_NOT_CONNECTED if not
 */
APICALL int UnrealLiveLink_HasConnection();

/**
 * initialize the Metadata structure with default values
 * @param metadata Metadata structure
 */
APICALL void UnrealLiveLink_InitMetadata(struct UnrealLiveLink_Metadata *metadata);

/** Basic Generic Roll **/

/**
 * Basic Generic Roll setup
 * @param subjectName Unreal subject name
 * @param properties named float properties
 */
APICALL void UnrealLiveLink_SetBasicStructure(const char *subjectName, const UnrealLiveLink_Properties *properties);

/**
 * Basic Generic Roll per frame values
 * @param subjectName Unreal subject name
 * @param worldTime frame time
 * @param metadata associated metadata (may pass in null for none)
 * @param propValues named properties float values (may pass in null for none)
 */
APICALL void UnrealLiveLink_UpdateBasicFrame(const char *subjectName, const double worldTime,
	const UnrealLiveLink_Metadata *metadata, const UnrealLiveLink_PropertyValues *propValues);

/** Animation Roll **/

/**
 * UNUSED
 */
APICALL void UnrealLiveLink_DefaultAnimationStructure(const char *name, const UnrealLiveLink_Properties *properties);

/**
 * Animation Roll setup
 * @param subjectName Unreal subject name
 * @param properties named float properties
 */
APICALL void UnrealLiveLink_SetAnimationStructure(
	const char *subjectName, const UnrealLiveLink_Properties *properties, UnrealLiveLink_AnimationStatic *structure);

/**
 * Animation Roll per frame values
 * @param subjectName Unreal subject name
 * @param worldTime frame time
 * @param metadata associated metadata (may pass in null for none)
 * @param propValues named properties float values (may pass in null for none)
 * @param frame animation frame
 */
APICALL void UnrealLiveLink_UpdateAnimationFrame(const char *subjectName, const double worldTime,
	const UnrealLiveLink_Metadata *metadata, const UnrealLiveLink_PropertyValues *propValues,
	const UnrealLiveLink_Animation *frame);

/** Transform Roll **/

/**
 * initialize transform structure to identity
 * @param transform transform to set
 */
APICALL void UnrealLiveLink_InitTransform(struct UnrealLiveLink_Transform *transform);

/**
 * Transform Roll setup
 * @param subjectName Unreal subject name
 * @param properties named float properties
 */
APICALL void UnrealLiveLink_SetTransformStructure(const char *subjectName, const UnrealLiveLink_Properties *properties);

/**
 * Transform Roll per frame values
 * @param subjectName Unreal subject name
 * @param worldTime frame time
 * @param metadata associated metadata (may pass in null for none)
 * @param propValues named properties float values (may pass in null for none)
 * @param frame transform
 */
APICALL void UnrealLiveLink_UpdateTransformFrame(const char *subjectName, const double worldTime,
	const UnrealLiveLink_Metadata *metadata, const UnrealLiveLink_PropertyValues *propValues,
	const UnrealLiveLink_Transform *frame);

/** Camera Roll **/

/**
 * initialize camera static to default values
 * @param structure structure to set
 */
APICALL void UnrealLiveLink_InitCameraStatic(struct UnrealLiveLink_CameraStatic *structure);

/**
 * initialize camera per frame to default values
 * @param structure structure to set
 */
APICALL void UnrealLiveLink_InitCamera(struct UnrealLiveLink_Camera *structure);

/**
 * Camera Roll setup
 * @param subjectName Unreal subject name
 * @param properties named float properties
 */
APICALL void UnrealLiveLink_SetCameraStructure(
	const char *subjectName, const UnrealLiveLink_Properties *properties, UnrealLiveLink_CameraStatic *structure);

/**
 * Camera Roll per frame values
 * @param subjectName Unreal subject name
 * @param worldTime frame time
 * @param metadata associated metadata (may pass in null for none)
 * @param propValues named properties float values (may pass in null for none)
 * @param frame camera values
 */
APICALL void UnrealLiveLink_UpdateCameraFrame(const char *subjectName, const double worldTime,
	const UnrealLiveLink_Metadata *metadata, const UnrealLiveLink_PropertyValues *propValues, const UnrealLiveLink_Camera *frame);

/** Light Roll **/

/**
 * initialize light static to default values
 * @param structure structure to set
 */
APICALL void UnrealLiveLink_InitLightStatic(struct UnrealLiveLink_LightStatic *structure);

/**
 * initialize light per frame to default values
 * @param structure structure to set
 */
APICALL void UnrealLiveLink_InitLight(struct UnrealLiveLink_Light *structure);

/**
 * Light Roll setup
 * @param subjectName Unreal subject name
 * @param properties named float properties
 */
APICALL void UnrealLiveLink_SetLightStructure(
	const char *subjectName, const UnrealLiveLink_Properties *properties, UnrealLiveLink_LightStatic *structure);

/**
 * Light Roll per frame values
 * @param subjectName Unreal subject name
 * @param worldTime frame time
 * @param metadata associated metadata (may pass in null for none)
 * @param propValues named properties float values (may pass in null for none)
 * @param frame light values
 */
APICALL void UnrealLiveLink_UpdateLightFrame(const char *subjectName, const double worldTime,
	const UnrealLiveLink_Metadata *metadata, const UnrealLiveLink_PropertyValues *propValues, const UnrealLiveLink_Light *frame);

#ifdef __cplusplus
}
#endif
