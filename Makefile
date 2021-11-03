EXECUTABLE := ramchecker

.PHONY: clean build run

build:
	ndk-build

run: build
	adb push libs/arm64-v8a/$(EXECUTABLE) /data/local/tmp/
	adb shell "/data/local/tmp/$(EXECUTABLE)"

clean:
	$(RM) -r libs/ obj/


