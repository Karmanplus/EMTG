// Copyright (c) 2023 The Regents of the University of Colorado.
// All Other Rights Reserved.


#ifndef CONSTRUCT_HARDWARE_H_
#define CONSTRUCT_HARDWARE_H_

#include "engine_model.h"
#include "missionoptions.h"
#include "LaunchVehicle.h"
#include "Spacecraft.h"

void ConstructHardware(EMTG::missionoptions & options, EMTG::HardwareModels::LaunchVehicleOptions & myLaunchVehicleOptions, EMTG::HardwareModels::SpacecraftOptions & mySpacecraftOptions);

#endif