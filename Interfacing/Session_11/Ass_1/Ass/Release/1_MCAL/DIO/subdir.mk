################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1_MCAL/DIO/DIO_PROGRAM.c 

OBJS += \
./1_MCAL/DIO/DIO_PROGRAM.o 

C_DEPS += \
./1_MCAL/DIO/DIO_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
1_MCAL/DIO/%.o: ../1_MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


