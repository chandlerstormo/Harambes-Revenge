// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HARAMBESREVENGE_Fence_generated_h
#error "Fence.generated.h already included, missing '#pragma once' in Fence.h"
#endif
#define HARAMBESREVENGE_Fence_generated_h

#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_RPC_WRAPPERS
#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUFence(); \
	friend HARAMBESREVENGE_API class UClass* Z_Construct_UClass_UFence(); \
	public: \
	DECLARE_CLASS(UFence, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HarambesRevenge"), NO_API) \
	DECLARE_SERIALIZER(UFence) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_INCLASS \
	private: \
	static void StaticRegisterNativesUFence(); \
	friend HARAMBESREVENGE_API class UClass* Z_Construct_UClass_UFence(); \
	public: \
	DECLARE_CLASS(UFence, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HarambesRevenge"), NO_API) \
	DECLARE_SERIALIZER(UFence) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFence(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFence) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFence); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFence); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFence(UFence&&); \
	NO_API UFence(const UFence&); \
public:


#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFence(UFence&&); \
	NO_API UFence(const UFence&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFence); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFence); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFence)


#define HarambesRevenge_Source_HarambesRevenge_Fence_h_9_PROLOG
#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HarambesRevenge_Source_HarambesRevenge_Fence_h_12_RPC_WRAPPERS \
	HarambesRevenge_Source_HarambesRevenge_Fence_h_12_INCLASS \
	HarambesRevenge_Source_HarambesRevenge_Fence_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HarambesRevenge_Source_HarambesRevenge_Fence_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HarambesRevenge_Source_HarambesRevenge_Fence_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	HarambesRevenge_Source_HarambesRevenge_Fence_h_12_INCLASS_NO_PURE_DECLS \
	HarambesRevenge_Source_HarambesRevenge_Fence_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HarambesRevenge_Source_HarambesRevenge_Fence_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
