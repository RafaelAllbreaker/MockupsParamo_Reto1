// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AController;
#ifdef VREXPANSIONPLUGIN_VRWheeledVehicle_generated_h
#error "VRWheeledVehicle.generated.h already included, missing '#pragma once' in VRWheeledVehicle.h"
#endif
#define VREXPANSIONPLUGIN_VRWheeledVehicle_generated_h

#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execForceSecondaryPossession) \
	{ \
		P_GET_OBJECT(AController,Z_Param_NewController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ForceSecondaryPossession(Z_Param_NewController); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOverrideController) \
	{ \
		P_GET_OBJECT(AController,Z_Param_NewController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetOverrideController(Z_Param_NewController); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBindToInput) \
	{ \
		P_GET_OBJECT(AController,Z_Param_CController); \
		P_GET_UBOOL(Z_Param_bBindToInput); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetBindToInput(Z_Param_CController,Z_Param_bBindToInput); \
		P_NATIVE_END; \
	}


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execForceSecondaryPossession) \
	{ \
		P_GET_OBJECT(AController,Z_Param_NewController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ForceSecondaryPossession(Z_Param_NewController); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetOverrideController) \
	{ \
		P_GET_OBJECT(AController,Z_Param_NewController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetOverrideController(Z_Param_NewController); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBindToInput) \
	{ \
		P_GET_OBJECT(AController,Z_Param_CController); \
		P_GET_UBOOL(Z_Param_bBindToInput); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SetBindToInput(Z_Param_CController,Z_Param_bBindToInput); \
		P_NATIVE_END; \
	}


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRWheeledVehicle(); \
	friend struct Z_Construct_UClass_AVRWheeledVehicle_Statics; \
public: \
	DECLARE_CLASS(AVRWheeledVehicle, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVRWheeledVehicle)


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_INCLASS \
private: \
	static void StaticRegisterNativesAVRWheeledVehicle(); \
	friend struct Z_Construct_UClass_AVRWheeledVehicle_Statics; \
public: \
	DECLARE_CLASS(AVRWheeledVehicle, AWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVRWheeledVehicle)


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVRWheeledVehicle(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRWheeledVehicle) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRWheeledVehicle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRWheeledVehicle); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRWheeledVehicle(AVRWheeledVehicle&&); \
	NO_API AVRWheeledVehicle(const AVRWheeledVehicle&); \
public:


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVRWheeledVehicle(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRWheeledVehicle(AVRWheeledVehicle&&); \
	NO_API AVRWheeledVehicle(const AVRWheeledVehicle&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRWheeledVehicle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRWheeledVehicle); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRWheeledVehicle)


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_PRIVATE_PROPERTY_OFFSET
#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_21_PROLOG
#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_PRIVATE_PROPERTY_OFFSET \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_RPC_WRAPPERS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_INCLASS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_PRIVATE_PROPERTY_OFFSET \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_INCLASS_NO_PURE_DECLS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_RPC_WRAPPERS
#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_RPC_WRAPPERS_NO_PURE_DECLS
#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVRSimpleWheeledVehicle(); \
	friend struct Z_Construct_UClass_AVRSimpleWheeledVehicle_Statics; \
public: \
	DECLARE_CLASS(AVRSimpleWheeledVehicle, AVRWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVRSimpleWheeledVehicle)


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_INCLASS \
private: \
	static void StaticRegisterNativesAVRSimpleWheeledVehicle(); \
	friend struct Z_Construct_UClass_AVRSimpleWheeledVehicle_Statics; \
public: \
	DECLARE_CLASS(AVRSimpleWheeledVehicle, AVRWheeledVehicle, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVRSimpleWheeledVehicle)


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVRSimpleWheeledVehicle(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRSimpleWheeledVehicle) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRSimpleWheeledVehicle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRSimpleWheeledVehicle); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRSimpleWheeledVehicle(AVRSimpleWheeledVehicle&&); \
	NO_API AVRSimpleWheeledVehicle(const AVRSimpleWheeledVehicle&); \
public:


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVRSimpleWheeledVehicle(AVRSimpleWheeledVehicle&&); \
	NO_API AVRSimpleWheeledVehicle(const AVRSimpleWheeledVehicle&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVRSimpleWheeledVehicle); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVRSimpleWheeledVehicle); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVRSimpleWheeledVehicle)


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_PRIVATE_PROPERTY_OFFSET
#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_177_PROLOG
#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_PRIVATE_PROPERTY_OFFSET \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_RPC_WRAPPERS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_INCLASS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_PRIVATE_PROPERTY_OFFSET \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_RPC_WRAPPERS_NO_PURE_DECLS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_INCLASS_NO_PURE_DECLS \
	MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h_180_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MockupsParamo_Reto1_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_Misc_VRWheeledVehicle_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
