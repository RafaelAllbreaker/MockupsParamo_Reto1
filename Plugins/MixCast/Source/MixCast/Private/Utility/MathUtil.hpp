/**********************************************************************************
* Blueprint Reality Inc. CONFIDENTIAL
* 2019 Blueprint Reality Inc.
* All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains, the property of
* Blueprint Reality Inc. and its suppliers, if any.  The intellectual and
* technical concepts contained herein are proprietary to Blueprint Reality Inc.
* and its suppliers and may be covered by Patents, pending patents, and are
* protected by trade secret or copyright law.
*
* Dissemination of this information or reproduction of this material is strictly
* forbidden unless prior written permission is obtained from Blueprint Reality Inc.
***********************************************************************************/

#pragma once

#include "CoreMinimal.h"

class MIXCAST_API MathUtil
{
public:
	// Builds a rotation LookAt matrix and converts it to a quaternion.
	static FQuat GetLookAtMatrix(const FVector& From, const FVector& LookAt, const FVector& Up)
	{
		FVector ForwardVector = LookAt - From;
		FVector LateralVector = FVector::CrossProduct(ForwardVector, Up);
		ForwardVector.Normalize();
		LateralVector.Normalize();
		FVector UpVector = FVector::CrossProduct(ForwardVector, LateralVector);
		FMatrix Matrix;
		Matrix.SetAxes(&LateralVector, &UpVector, &ForwardVector);
		return Matrix.ToQuat();
	}

	// Based on Unity's SmoothDamp function, using numeric integration.
	static float SmoothDamp(const float Current, const float Target, float &Speed, const float SmoothTime, const float DeltaTime)
	{
		const float T1 = 0.36 * SmoothTime;
		const float T2 = 0.64 * SmoothTime;
		const float Interval = Current - Target;
		const float Result = Interval + DeltaTime * Speed;
		Speed = Speed - DeltaTime * (1.0f / (T1 * T2) * Interval + (T1 + T2) / (T1 * T2) * Speed);
		return Target + Result;
	}

	static FVector SmoothDamp(const FVector& Position, const FVector& TargetPosition, FVector &Speed, const float SmoothTime, const float DeltaTime)
	{
		FVector Result;
		Result.X = SmoothDamp(Position.X, TargetPosition.X, Speed.X, SmoothTime, DeltaTime);
		Result.Y = SmoothDamp(Position.Y, TargetPosition.Y, Speed.Y, SmoothTime, DeltaTime);
		Result.Z = SmoothDamp(Position.Z, TargetPosition.Z, Speed.Z, SmoothTime, DeltaTime);
		return Result;
	}

	static float SmoothDampAngle(const float Current, const float Target, float &Speed, const float SmoothTime, const float DeltaTime)
	{
		float TargetAngle = fmodf(Target - Current, 360.0f);

		if (TargetAngle > 180.0f)
		{
			TargetAngle -= 360.0f;
		}
		else if (TargetAngle < -180.0f)
		{
			TargetAngle += 360.0f;
		}

		return SmoothDamp(Current, Current + TargetAngle, Speed, SmoothTime, DeltaTime);
	}

	static FQuat SmoothDampRotation(const FQuat& Rotation, const FQuat& TargetRotation, FVector &Speed, const float SmoothTime, const float DeltaTime)
	{
		const FVector TargetEulerAngles = TargetRotation.Euler();
		FVector EulerAngles = Rotation.Euler();
		EulerAngles.X = SmoothDampAngle(EulerAngles.X, TargetEulerAngles.X, Speed.X, SmoothTime, DeltaTime);
		EulerAngles.Y = SmoothDampAngle(EulerAngles.Y, TargetEulerAngles.Y, Speed.Y, SmoothTime, DeltaTime);
		EulerAngles.Z = SmoothDampAngle(EulerAngles.Z, TargetEulerAngles.Z, Speed.Z, SmoothTime, DeltaTime);
		return FQuat::MakeFromEuler(EulerAngles);
	}

	static FVector UnityPositionToUnreal(const FVector &UnityPosition)
	{
		// Unity uses X for left, Y for up and Z for forward, but Unreal uses X for forward, Y for left and Z for up.
		// Both coordinate systems are left handed. Unreal also uses centimeters for units instead of meters.
		return {
			UnityPosition.Z * 100.0f, // X
			UnityPosition.X * 100.0f, // Y
			UnityPosition.Y * 100.0f, // Z
		};
	}

	static FQuat UnityRotationToUnreal(const FQuat &UnityRotation)
	{
		const FVector UnityX = UnityRotation.GetForwardVector();
		const FVector UnityY = UnityRotation.GetRightVector();
		const FVector UnityZ = UnityRotation.GetUpVector();

		const FVector UnrealX = UnityPositionToUnreal(UnityZ);
		const FVector UnrealY = UnityPositionToUnreal(UnityX);
		const FVector UnrealZ = UnityPositionToUnreal(UnityY);

		const FMatrix OrientationMatrix(UnrealX.GetSafeNormal(), UnrealY.GetSafeNormal(), UnrealZ.GetSafeNormal(), FVector::ZeroVector);
		return FQuat(OrientationMatrix);
	}

	//degrees in/out
	static float VerticalFoVToHorizontal(const float vertFoV, const float aspectRatio)
	{
		const float vFovRadians = vertFoV * PI / 180.0f;
		const float hFovRadians = atan(tan(vFovRadians / 2.0f) * aspectRatio) * 2.0f;
		return hFovRadians / PI * 180.0f;
	}
};
