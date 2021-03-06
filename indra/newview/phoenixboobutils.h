// As of the inclusion on LL V2 AV physics in build 1060, this file is no longer used, butkept in case of backing out LL V2 AV Physics.
#ifndef __phoenixboobutils_h
#define __phoenixboobutils_h

#include <iostream>
#include <list>

#include "stdtypes.h"
#include "v3math.h"
#include "llquaternion.h"

struct PhoenixGlobalBoobConfig
{
	bool enabled;
	F32 mass;
	F32 hardness;
	F32 zMax;
	F32 velMin;
	F32 velMax;
	F32 zInfluence;
	F32 friction;
	F32 XYInfluence;

	PhoenixGlobalBoobConfig()
		: enabled(false),
			mass(6.4f),
			hardness(0.67f),
			zMax(1.29f),
			velMin(0.0027f*0.017f),
			velMax(0.0027f),
			zInfluence(0.0f),
			friction(0.35f),
			XYInfluence(0.3f)
	{
	}

	bool operator==(const PhoenixGlobalBoobConfig &other) const
	{
		return
			enabled == other.enabled &&
			mass == other.mass &&
			zMax == other.zMax &&
			velMax == other.velMax &&
			velMin == other.velMin &&
			zInfluence == other.zInfluence &&
			XYInfluence == other.XYInfluence &&
			friction == other.friction;
	}
};

std::ostream &operator<<(std::ostream &os, const PhoenixGlobalBoobConfig &v);

struct PhoenixAvatarLocalBoobConfig
{
	F32 actualBoobGrav;
	F32 actualButtGrav;
	F32 actualFatGrav;
	F32 boobSize;

	PhoenixAvatarLocalBoobConfig()
		: actualBoobGrav(0.0f),
		  actualButtGrav(0.0f),
		  actualFatGrav(0.0f),
			boobSize(0.0f)
	{
	}

	bool operator==(const PhoenixAvatarLocalBoobConfig &other) const
	{
		return
			actualBoobGrav == other.actualBoobGrav &&
			actualButtGrav == other.actualButtGrav &&
			actualFatGrav == other.actualFatGrav &&
			boobSize == other.boobSize;
	}

};

std::ostream &operator<<(std::ostream &os, const PhoenixAvatarLocalBoobConfig &v);

struct PhoenixBoobBounceState;

struct PhoenixBoobState
{
	F32 boobGrav;
	LLVector3 chestPosition;
	LLQuaternion chestRotation;
	F32 elapsedTime;
	F32 frameDuration;
	LLVector3 chestDisplacement;
	LLVector3 localChestDisplacement;
	LLVector3 displacementForce;
	F32 mysteryValue;
	std::list<PhoenixBoobBounceState> bounceStates;

	PhoenixBoobState()
		: boobGrav(0.0f),
			chestPosition(0.0f,0.0f,0.0f),
			chestRotation(0.0f,0.0f,0.0f,1.0f),
			elapsedTime(0.0f),
			frameDuration(0.0f),
			chestDisplacement(0.0f,0.0f,0.0f),
			localChestDisplacement(0.0f,0.0f,0.0f),
			displacementForce(0.0f,0.0f,0.0f),
			mysteryValue(0.0f)
	{
	}

	bool operator==(const PhoenixBoobState &other) const
	{
		return
			boobGrav == other.boobGrav &&
			chestPosition == other.chestPosition &&
			chestRotation == other.chestRotation &&
			elapsedTime == other.elapsedTime &&
			frameDuration == other.frameDuration &&
			chestDisplacement == other.chestDisplacement &&
			localChestDisplacement == other.localChestDisplacement &&
			displacementForce == other.displacementForce &&
			mysteryValue == other.mysteryValue &&
			bounceStates == other.bounceStates;
	}
};

std::ostream &operator<<(std::ostream &os, const PhoenixBoobState &v);

struct PhoenixBoobInputs
{
	LLVector3 chestPosition;
	LLQuaternion chestRotation;
	F32 elapsedTime;
	bool appearanceFlag;
	bool appearanceAnimating;
	S32 type;

	PhoenixBoobInputs()
		: chestPosition(0.0f,0.0f,0.0f),
			chestRotation(0.0f,0.0f,0.0f,1.0f),
			elapsedTime(0.0f),
			appearanceFlag(false),
			appearanceAnimating(false),
			type(0)
	{
	}

	bool operator==(const PhoenixBoobInputs &other) const
	{
		return
			chestPosition == other.chestPosition &&
			chestRotation == other.chestRotation &&
			elapsedTime == other.elapsedTime &&
			appearanceFlag == other.appearanceFlag &&
			appearanceAnimating == other.appearanceAnimating &&
			type == other.type;
	}
};

std::ostream &operator<<(std::ostream &os, const PhoenixBoobInputs &v);

struct PhoenixBoobBounceState
{
	F32 bounceStart;
	F32 bounceStartAmplitude;
	F32 bounceStartFrameDuration;

	PhoenixBoobBounceState()
		: bounceStart(0.0f),
			bounceStartAmplitude(0.0f),
			bounceStartFrameDuration(0.0f)
	{
	};

	bool operator==(const PhoenixBoobBounceState &other) const
	{
		return
			bounceStart == other.bounceStart &&
			bounceStartAmplitude == other.bounceStartAmplitude &&
			bounceStartFrameDuration == other.bounceStartFrameDuration;
	}
};

std::ostream &operator<<(std::ostream &os, const PhoenixBoobBounceState &v);


struct PhoenixBoobUtils
{
public:
	static PhoenixBoobState idleUpdate(const PhoenixGlobalBoobConfig &config, const PhoenixAvatarLocalBoobConfig &localConfig, const PhoenixBoobState &oldState, const PhoenixBoobInputs &inputs);

	static F32 convertMass(F32 displayMass);
	static F32 convertHardness(F32 displayHardness);
	static F32 convertVelMax(F32 displayVelMax);
	static F32 convertFriction(F32 displayFriction);
	static F32 convertVelMin(F32 displayVelMin);
};


#endif
