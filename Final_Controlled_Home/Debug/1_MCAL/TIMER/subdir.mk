################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1_MCAL/TIMER/TIMER_program.c 

OBJS += \
./1_MCAL/TIMER/TIMER_program.o 

C_DEPS += \
./1_MCAL/TIMER/TIMER_program.d 


# Each subdirectory must supply rules for building sources it contributes
1_MCAL/TIMER/%.o: ../1_MCAL/TIMER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


