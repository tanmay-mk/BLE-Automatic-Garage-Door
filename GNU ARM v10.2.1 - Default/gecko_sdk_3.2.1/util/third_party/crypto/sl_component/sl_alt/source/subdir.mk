################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.c \
../gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.c 

OBJS += \
./gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.o \
./gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.o 

C_DEPS += \
./gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.d \
./gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.o: ../gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32BG13P632F512GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CLIENT=1' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/Device/SiliconLabs/EFR32BG13P/Include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/app/common/util/app_assert" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/app/common/util/app_log" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/common/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/protocol/bluetooth/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/board/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/bootloader" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/bootloader/api" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/CMSIS/Include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/device_init/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/middleware/glib/dmd" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/middleware/glib" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/emlib/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/middleware/glib/glib" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/driver/i2cspm/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/iostream/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/memlcd/src/ls013b7dh03" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/mbedtls/include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/mbedtls/library" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/memlcd/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/memlcd/inc/memlcd_usart" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/mpu/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/app/bluetooth/common/ota_dfu" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/power_manager/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/common" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/ble" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/ieee802154" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/zwave" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/mfm" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/plugin/pa-conversions" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/plugin/pa-conversions/efr32xg1x" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/plugin/rail_util_pti" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/silicon_labs/silabs_core/memory_manager" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/common/toolchain/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/system/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/sleeptimer/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/udelay/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/autogen" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.d" -MT"gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_entropy.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.o: ../gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DEFR32BG13P632F512GM48=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CLIENT=1' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/Device/SiliconLabs/EFR32BG13P/Include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/app/common/util/app_assert" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/app/common/util/app_log" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/common/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/protocol/bluetooth/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/board/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/bootloader" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/bootloader/api" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/CMSIS/Include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/device_init/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/middleware/glib/dmd" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/middleware/glib" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/emlib/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/middleware/glib/glib" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/driver/i2cspm/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/iostream/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/memlcd/src/ls013b7dh03" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/mbedtls/include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/mbedtls/library" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/include" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/memlcd/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/memlcd/inc/memlcd_usart" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/mpu/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/app/bluetooth/common/ota_dfu" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/power_manager/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/common" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/ble" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/ieee802154" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/zwave" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/protocol/mfm" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/plugin/pa-conversions" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/plugin/pa-conversions/efr32xg1x" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/radio/rail_lib/plugin/rail_util_pti" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/silicon_labs/silabs_core/memory_manager" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/common/toolchain/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/system/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/sleeptimer/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/gecko_sdk_3.2.1/platform/service/udelay/inc" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/autogen" -I"/Users/dsluiter/SimplicityStudio/v5_workspace/student_submissions/A3/ecen5823-assignment3-tanmay-mk/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.d" -MT"gecko_sdk_3.2.1/util/third_party/crypto/sl_component/sl_alt/source/sl_mbedtls.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


