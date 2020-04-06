/*
* Copyright (C) 2011 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "OpenGLESDispatch/EGLDispatch.h"

#include "emugl/common/shared_library.h"

#include <stdio.h>
#include <stdlib.h>

EGLDispatch s_egl;

#define DEFAULT_EGL_LIB EMUGL_LIBNAME("EGL_translator")

#define RENDER_EGL_LOAD_FIELD(return_type, function_name, signature) \
    s_egl. function_name = (function_name ## _t) lib->findSymbol(#function_name); \

#define RENDER_EGL_LOAD_FIELD_WITH_EGL(return_type, function_name, signature) \
    if ((!s_egl. function_name) && s_egl.eglGetProcAddress) s_egl. function_name = \
            (function_name ## _t) s_egl.eglGetProcAddress(#function_name); \

#define RENDER_EGL_LOAD_OPTIONAL_FIELD(return_type, function_name, signature) \
    if (s_egl.eglGetProcAddress) s_egl. function_name = \
            (function_name ## _t) s_egl.eglGetProcAddress(#function_name); \
    if (!s_egl.function_name || !s_egl.eglGetProcAddress) \
            RENDER_EGL_LOAD_FIELD(return_type, function_name, signature)

#define RENDER_EGL_LOAD_FIELD_STATIC(return_type, function_name, signature) \
    s_egl. function_name = (function_name ## _t) (translator::egl::function_name); \

#define RENDER_EGL_LOAD_FIELD_WITH_EGL(return_type, function_name, signature) \
    if ((!s_egl. function_name) && s_egl.eglGetProcAddress) s_egl. function_name = \
            (function_name ## _t) s_egl.eglGetProcAddress(#function_name); \

#define RENDER_EGL_LOAD_OPTIONAL_FIELD_STATIC(return_type, function_name, signature) \
    if (s_egl.eglGetProcAddress) s_egl. function_name = \
            (function_name ## _t) s_egl.eglGetProcAddress(#function_name); \
    if (!s_egl.function_name || !s_egl.eglGetProcAddress) \
            RENDER_EGL_LOAD_FIELD_STATIC(return_type, function_name, signature)

bool init_egl_dispatch_from_static() {
    if (s_egl.initialized) return true;

    LIST_RENDER_EGL_FUNCTIONS(RENDER_EGL_LOAD_FIELD_STATIC)
    LIST_RENDER_EGL_FUNCTIONS(RENDER_EGL_LOAD_FIELD_WITH_EGL)
    LIST_RENDER_EGL_EXTENSIONS_FUNCTIONS(RENDER_EGL_LOAD_OPTIONAL_FIELD_STATIC)
    LIST_RENDER_EGL_SNAPSHOT_FUNCTIONS(RENDER_EGL_LOAD_FIELD_STATIC)

    s_egl.initialized = true;
    return true;
}

bool init_egl_dispatch() {
    if (s_egl.initialized) return true;

    const char* useStatic = getenv("ANDROID_EMU_STATIC_TRANSLATOR");
    if (useStatic) {
        return init_egl_dispatch_from_static();
    }

    const char *libName = getenv("ANDROID_EGL_LIB");
    if (!libName) libName = DEFAULT_EGL_LIB;
    char error[256];
    emugl::SharedLibrary *lib = emugl::SharedLibrary::open(libName, error, sizeof(error));
    if (!lib) {
        return init_egl_dispatch_from_static();
    }

    LIST_RENDER_EGL_FUNCTIONS(RENDER_EGL_LOAD_FIELD)
    LIST_RENDER_EGL_FUNCTIONS(RENDER_EGL_LOAD_FIELD_WITH_EGL)
    LIST_RENDER_EGL_EXTENSIONS_FUNCTIONS(RENDER_EGL_LOAD_OPTIONAL_FIELD)
    LIST_RENDER_EGL_SNAPSHOT_FUNCTIONS(RENDER_EGL_LOAD_FIELD)

    s_egl.initialized = true;
    return true;
}
