// Copyright 2016 The Android Open Source Project
//
// This software is licensed under the terms of the GNU General Public
// License version 2, as published by the Free Software Foundation, and
// may be copied, distributed, and modified under those terms.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

#pragma once

#include "android/utils/compiler.h"

#include <stdbool.h>

ANDROID_BEGIN_HEADER

// C interface for metrics reporting initialization/termination.
//
// We don't provide an interface for event logging other than a predefined
// 'common info' - logged event is a C++ class (generated from a protobuf
// definition), and the only way to make it into a C interface is to duplicate
// the fields into some C struct or set of functions. Way too much work for no
// real gains.

bool android_metrics_start(const char* emulatorVersion,
                           const char* emulatorFullVersion,
                           const char* qemuVersion,
                           int controlConsolePort);

// A set of reasons for stopping metrics.
typedef enum {
    METRICS_STOP_GRACEFUL,
    METRICS_STOP_CRASH
} MetricsStopReason;

void android_metrics_stop(MetricsStopReason reason);

// A strongly-typed interface for C++ and a compatible one for C.
#ifdef __cplusplus
namespace android { namespace emulation { class AdbInterface; } }
using AdbInterfacePtr = android::emulation::AdbInterface*;
#else
typedef void* AdbInterfacePtr;
#endif

bool android_metrics_start_adb_liveness_checker(AdbInterfacePtr adb);

// |opaque| is assumed to be a pointer to the
// android_studio::AndroidStudioEvent protobuf. Since this is a C file used in
// many other C environments, we do not include the protobuf headers here.
void android_metrics_fill_common_info(bool openglAlive, void* opaque);

void android_metrics_report_common_info(bool openglAlive);

ANDROID_END_HEADER
