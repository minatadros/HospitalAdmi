################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bed.cpp \
../doctor.cpp \
../hospital.cpp \
../hospitalsystem.cpp \
../patient.cpp \
../room.cpp 

OBJS += \
./bed.o \
./doctor.o \
./hospital.o \
./hospitalsystem.o \
./patient.o \
./room.o 

CPP_DEPS += \
./bed.d \
./doctor.d \
./hospital.d \
./hospitalsystem.d \
./patient.d \
./room.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


