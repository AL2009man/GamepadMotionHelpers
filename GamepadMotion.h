#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#if defined(_WIN32)
    #define GamepadMotion_WRAPPER __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
    #define GamepadMotion_WRAPPER __attribute__((visibility("default")))
#else
    #define GamepadMotion_WRAPPER
#endif

// Use the actual C++ class pointer for the handle
typedef struct GamepadMotion GamepadMotion;
typedef GamepadMotion* GamepadMotionHandle;

// Creation and destruction
GamepadMotion_WRAPPER GamepadMotionHandle CreateGamepadMotion(void);
GamepadMotion_WRAPPER void DeleteGamepadMotion(GamepadMotionHandle handle);

// Core motion processing
GamepadMotion_WRAPPER void ProcessMotion(GamepadMotionHandle handle, float gyroX, float gyroY, float gyroZ,
                   float accelX, float accelY, float accelZ, float deltaTime);
GamepadMotion_WRAPPER void ResetGamepadMotion(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void ResetMotion(GamepadMotionHandle handle);

// State getters
GamepadMotion_WRAPPER void GetCalibratedGyro(GamepadMotionHandle handle, float* x, float* y, float* z);
GamepadMotion_WRAPPER void GetGravity(GamepadMotionHandle handle, float* x, float* y, float* z);
GamepadMotion_WRAPPER void GetProcessedAcceleration(GamepadMotionHandle handle, float* x, float* y, float* z);
GamepadMotion_WRAPPER void GetOrientation(GamepadMotionHandle handle, float* w, float* x, float* y, float* z);
GamepadMotion_WRAPPER void GetPlayerSpaceGyro(GamepadMotionHandle handle, float* x, float* y, const float yawRelaxFactor);
GamepadMotion_WRAPPER void GetWorldSpaceGyro(GamepadMotionHandle handle, float* x, float* y, const float sideReductionThreshold);

// Calibration
GamepadMotion_WRAPPER void StartContinuousCalibration(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void PauseContinuousCalibration(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void ResetContinuousCalibration(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void GetCalibrationOffset(GamepadMotionHandle handle, float* xOffset, float* yOffset, float* zOffset);
GamepadMotion_WRAPPER void SetCalibrationOffset(GamepadMotionHandle handle, float xOffset, float yOffset, float zOffset, int weight);
GamepadMotion_WRAPPER float GetAutoCalibrationConfidence(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetAutoCalibrationConfidence(GamepadMotionHandle handle, float newConfidence);
GamepadMotion_WRAPPER bool GetAutoCalibrationIsSteady(GamepadMotionHandle handle);

// Calibration mode  
GamepadMotion_WRAPPER int GetCalibrationMode(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetCalibrationMode(GamepadMotionHandle handle, int mode);

// GamepadMotionSettings: Getters and Setters
GamepadMotion_WRAPPER void SetMinStillnessSamples(GamepadMotionHandle handle, int value);
GamepadMotion_WRAPPER int  GetMinStillnessSamples(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetMinStillnessCollectionTime(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetMinStillnessCollectionTime(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetMinStillnessCorrectionTime(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetMinStillnessCorrectionTime(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetMaxStillnessError(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetMaxStillnessError(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessSampleDeteriorationRate(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessSampleDeteriorationRate(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessErrorClimbRate(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessErrorClimbRate(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessErrorDropOnRecalibrate(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessErrorDropOnRecalibrate(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessCalibrationEaseInTime(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessCalibrationEaseInTime(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessCalibrationHalfTime(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessCalibrationHalfTime(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessConfidenceRate(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessConfidenceRate(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessGyroDelta(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessGyroDelta(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetStillnessAccelDelta(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetStillnessAccelDelta(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetSensorFusionCalibrationSmoothingStrength(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetSensorFusionCalibrationSmoothingStrength(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetSensorFusionAngularAccelerationThreshold(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetSensorFusionAngularAccelerationThreshold(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetSensorFusionCalibrationEaseInTime(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetSensorFusionCalibrationEaseInTime(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetSensorFusionCalibrationHalfTime(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetSensorFusionCalibrationHalfTime(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetSensorFusionConfidenceRate(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetSensorFusionConfidenceRate(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionShakinessMaxThreshold(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionShakinessMaxThreshold(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionShakinessMinThreshold(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionShakinessMinThreshold(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionStillSpeed(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionStillSpeed(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionShakySpeed(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionShakySpeed(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionGyroFactor(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionGyroFactor(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionGyroMinThreshold(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionGyroMinThreshold(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionGyroMaxThreshold(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionGyroMaxThreshold(GamepadMotionHandle handle);
GamepadMotion_WRAPPER void SetGravityCorrectionMinimumSpeed(GamepadMotionHandle handle, float value);
GamepadMotion_WRAPPER float GetGravityCorrectionMinimumSpeed(GamepadMotionHandle handle);

#ifdef __cplusplus
}
#endif
