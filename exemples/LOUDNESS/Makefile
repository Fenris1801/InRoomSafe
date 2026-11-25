# Exemple capteur de son (LED qui change quand un son est detecte) : a lancer depuis ce dossier (make, make upload, make clean)

# Sous Windows, utilise le shell de Git pour que mkdir -p / rm -rf marchent meme depuis PowerShell
ifeq ($(OS),Windows_NT)
GIT_BIN := C:/PROGRA~1/Git/usr/bin
export PATH := $(GIT_BIN);$(PATH)
SHELL := $(GIT_BIN)/sh.exe
endif

PROGRAM=LoudnessTest
PORT=COM3

BUILD_DIR=Build
# Dossier racine des drivers et drivers utilises par cet exemple
DRIVERS_DIR=../../drivers
DRIVERS=LOUDNESS LED
# -I${DRIVERS_DIR} permet d'ecrire #include "LED/led.h", "BUTTON/button.h"...
INCLUDES=-I. -I${DRIVERS_DIR}
# Les .cpp de ce dossier + tous les .cpp des drivers utilises
SRCS=$(wildcard *.cpp) $(foreach d,${DRIVERS},$(wildcard ${DRIVERS_DIR}/$(d)/*.cpp))
# Tous les .o vont a plat dans Build/ (sinon ../../drivers/... sortirait du dossier Build)
OBJS=$(addprefix ${BUILD_DIR}/,$(notdir $(SRCS:.cpp=.o)))
# Ou make doit chercher les .cpp
vpath %.cpp . $(addprefix ${DRIVERS_DIR}/,${DRIVERS})

ARDUINO_TOOLS=$(LOCALAPPDATA)/Arduino15/packages/arduino/tools
AVR_BIN=$(ARDUINO_TOOLS)/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin
AVRDUDE_DIR=$(ARDUINO_TOOLS)/avrdude/6.3.0-arduino17

CPP="$(AVR_BIN)/avr-g++"
OBJCOPY="$(AVR_BIN)/avr-objcopy"
MMCU=-mmcu=atmega328p

CPPFLAGS= -Os -g -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -x c++ ${MMCU} -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR

all: ${BUILD_DIR}/${PROGRAM}.hex

${BUILD_DIR}/${PROGRAM}.elf: ${OBJS}
	${CPP} -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections ${MMCU} $^ -o $@

${BUILD_DIR}/%.o: %.cpp
	mkdir -p $(dir $@)
	${CPP} -c ${CPPFLAGS} ${INCLUDES} $< -o $@

${BUILD_DIR}/${PROGRAM}.hex: ${BUILD_DIR}/${PROGRAM}.elf
	${OBJCOPY} -O ihex -R .eeprom $< $@

upload: ${BUILD_DIR}/${PROGRAM}.hex
	"$(AVRDUDE_DIR)/bin/avrdude" -C "$(AVRDUDE_DIR)/etc/avrdude.conf" -V -c arduino -p ATMEGA328P -P ${PORT} -b 115200 -U flash:w:$<:i

clean:
	rm -rf ${BUILD_DIR}

-include $(OBJS:.o=.d)

.PHONY: all upload clean
