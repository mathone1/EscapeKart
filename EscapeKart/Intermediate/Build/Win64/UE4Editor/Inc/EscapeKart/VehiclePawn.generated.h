// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPEKART_VehiclePawn_generated_h
#error "VehiclePawn.generated.h already included, missing '#pragma once' in VehiclePawn.h"
#endif
#define ESCAPEKART_VehiclePawn_generated_h

#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_SPARSE_DATA
#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_RPC_WRAPPERS
#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVehiclePawn(); \
	friend struct Z_Construct_UClass_AVehiclePawn_Statics; \
public: \
	DECLARE_CLASS(AVehiclePawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeKart"), NO_API) \
	DECLARE_SERIALIZER(AVehiclePawn)


#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAVehiclePawn(); \
	friend struct Z_Construct_UClass_AVehiclePawn_Statics; \
public: \
	DECLARE_CLASS(AVehiclePawn, AWheeledVehicle, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeKart"), NO_API) \
	DECLARE_SERIALIZER(AVehiclePawn)


#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVehiclePawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVehiclePawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVehiclePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVehiclePawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVehiclePawn(AVehiclePawn&&); \
	NO_API AVehiclePawn(const AVehiclePawn&); \
public:


#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVehiclePawn(AVehiclePawn&&); \
	NO_API AVehiclePawn(const AVehiclePawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVehiclePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVehiclePawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVehiclePawn)


#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArm() { return STRUCT_OFFSET(AVehiclePawn, SpringArm); } \
	FORCEINLINE static uint32 __PPO__Camera() { return STRUCT_OFFSET(AVehiclePawn, Camera); }


#define EscapeKart_Source_EscapeKart_VehiclePawn_h_12_PROLOG
#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_PRIVATE_PROPERTY_OFFSET \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_SPARSE_DATA \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_RPC_WRAPPERS \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_INCLASS \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeKart_Source_EscapeKart_VehiclePawn_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_PRIVATE_PROPERTY_OFFSET \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_SPARSE_DATA \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_INCLASS_NO_PURE_DECLS \
	EscapeKart_Source_EscapeKart_VehiclePawn_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPEKART_API UClass* StaticClass<class AVehiclePawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeKart_Source_EscapeKart_VehiclePawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
