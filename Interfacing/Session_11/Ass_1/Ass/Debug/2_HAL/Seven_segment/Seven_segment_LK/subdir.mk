################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_CONFIG.c \
../2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_PROGRAM.c 

OBJS += \
./2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_CONFIG.o \
./2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_PROGRAM.o 

C_DEPS += \
./2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_CONFIG.d \
./2_HAL/Seven_segment/Seven_segment_LK/Seven_segment_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
2_HAL/Seven_segment/Seven_segment_LK/%.o: ../2_HAL/Seven_segment/Seven_segment_LK/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


