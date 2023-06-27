################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/libcpu/arm/cortex-m4/cpuport.c 

S_UPPER_SRCS += \
../rt-thread/libcpu/arm/cortex-m4/context_gcc.S 

OBJS += \
./rt-thread/libcpu/arm/cortex-m4/context_gcc.o \
./rt-thread/libcpu/arm/cortex-m4/cpuport.o 

S_UPPER_DEPS += \
./rt-thread/libcpu/arm/cortex-m4/context_gcc.d 

C_DEPS += \
./rt-thread/libcpu/arm/cortex-m4/cpuport.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/libcpu/arm/cortex-m4/%.o: ../rt-thread/libcpu/arm/cortex-m4/%.S
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -x assembler-with-cpp -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522" -Xassembler -mimplicit-it=thumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
rt-thread/libcpu/arm/cortex-m4/%.o: ../rt-thread/libcpu/arm/cortex-m4/%.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F4 -DUSE_HAL_DRIVER -DSTM32F407xx -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\drivers" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\drivers\include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\drivers\include\config" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\STM32F4xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\STM32F4xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\applications" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\cubemx\Inc" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\cubemx" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\drivers\spi" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\compilers\common" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\libcpu\arm\cortex-m4" -include"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

