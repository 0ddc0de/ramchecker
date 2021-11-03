LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := ramchecker
LOCAL_CPPFLAGS += -std=c++17 -ggdb -Werror -Wpedantic -fexceptions
LOCAL_SRC_FILES := main.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
include $(BUILD_EXECUTABLE)
