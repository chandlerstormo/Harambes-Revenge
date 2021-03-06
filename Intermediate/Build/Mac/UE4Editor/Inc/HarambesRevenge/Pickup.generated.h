// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef HARAMBESREVENGE_Pickup_generated_h
#error "Pickup.generated.h already included, missing '#pragma once' in Pickup.h"
#endif
#define HARAMBESREVENGE_Pickup_generated_h

#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execNotifyActorBeginOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->NotifyActorBeginOverlap(Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execNotifyActorBeginOverlap) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->NotifyActorBeginOverlap(Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAPickup(); \
	friend HARAMBESREVENGE_API class UClass* Z_Construct_UClass_APickup(); \
	public: \
	DECLARE_CLASS(APickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HarambesRevenge"), NO_API) \
	DECLARE_SERIALIZER(APickup) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAPickup(); \
	friend HARAMBESREVENGE_API class UClass* Z_Construct_UClass_APickup(); \
	public: \
	DECLARE_CLASS(APickup, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HarambesRevenge"), NO_API) \
	DECLARE_SERIALIZER(APickup) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public:


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickup)


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_8_PROLOG
#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_RPC_WRAPPERS \
	HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_INCLASS \
	HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_INCLASS_NO_PURE_DECLS \
	HarambesRevenge_Source_HarambesRevenge_Pickup_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HarambesRevenge_Source_HarambesRevenge_Pickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
