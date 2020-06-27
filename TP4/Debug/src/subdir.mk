################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Employee.c \
../src/LinkedList.c \
../src/TP3conLLTp4.c \
../src/parser.c \
../src/utn.c 

OBJS += \
./src/Controller.o \
./src/Employee.o \
./src/LinkedList.o \
./src/TP3conLLTp4.o \
./src/parser.o \
./src/utn.o 

C_DEPS += \
./src/Controller.d \
./src/Employee.d \
./src/LinkedList.d \
./src/TP3conLLTp4.d \
./src/parser.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


