################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 3_APP/App_1/subdir.mk
-include 2_HAL/LCD/subdir.mk
-include 1_MCAL/USART/subdir.mk
-include 1_MCAL/DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
lab19.lss \

FLASH_IMAGE += \
lab19.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab19.elf secondary-outputs

# Tool invocations
lab19.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab19.map -mmcu=atmega32 -o "lab19.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab19.lss: lab19.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab19.elf  >"lab19.lss"
	@echo 'Finished building: $@'
	@echo ' '

lab19.hex: lab19.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lab19.elf  "lab19.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab19.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lab19.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab19.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
