// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef HARAMBESREVENGE_BananaActor_generated_h
#error "BananaActor.generated.h already included, missing '#pragma once' in BananaActor.h"
#endif
#define HARAMBESREVENGE_BananaActor_generated_h

#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABananaActor(); \
	friend HARAMBESREVENGE_API class UClass* Z_Construct_UClass_ABananaActor(); \
	public: \
	DECLARE_CLASS(ABananaActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HarambesRevenge"), NO_API) \
	DECLARE_SERIALIZER(ABananaActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesABananaActor(); \
	friend HARAMBESREVENGE_API class UClass* Z_Construct_UClass_ABananaActor(); \
	public: \
	DECLARE_CLASS(ABananaActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HarambesRevenge"), NO_API) \
	DECLARE_SERIALIZER(ABananaActor) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABananaActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABananaActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABananaActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABananaActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABananaActor(ABananaActor&&); \
	NO_API ABananaActor(const ABananaActor&); \
public:


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABananaActor(ABananaActor&&); \
	NO_API ABananaActor(const ABananaActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABananaActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABananaActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABananaActor)


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_8_PROLOG
#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_RPC_WRAPPERS \
	HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_INCLASS \
	HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_INCLASS_NO_PURE_DECLS \
	HarambesRevenge_Source_HarambesRevenge_BananaActor_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HarambesRevenge_Source_HarambesRevenge_BananaActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS