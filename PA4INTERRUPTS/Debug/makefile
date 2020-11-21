################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
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
EXECUTABLES += \
PA3INTTERRUPTS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PA3INTTERRUPTS.list \

OBJCOPY_BIN += \
PA3INTTERRUPTS.bin \


# All Target
all: PA3INTTERRUPTS.elf secondary-outputs

# Tool invocations
PA3INTTERRUPTS.elf: $(OBJS) $(USER_OBJS) /home/suman/STM32CubeIDE/workspace/PA3INTTERRUPTS/STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "PA3INTTERRUPTS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/suman/STM32CubeIDE/workspace/PA3INTTERRUPTS/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PA3INTTERRUPTS.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PA3INTTERRUPTS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PA3INTTERRUPTS.list"
	@echo 'Finished building: $@'
	@echo ' '

PA3INTTERRUPTS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PA3INTTERRUPTS.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
