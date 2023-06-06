################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
sw/solutions/Mbds/Algo/%.obj: ../sw/solutions/Mbds/Algo/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Program Files/ccs1031/ccs/tools/compiler/ti-cgt-c2000_20.2.4.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -Ooff --include_path="D:/Program Files/ccs1031/ccs/tools/compiler/ti-cgt-c2000_20.2.4.LTS/include" --include_path="D:/Program Files/ccs1031/kll/M_MOT_MBD_290_1500Nm_keshi" --preinclude="D:/Program Files/ccs1031/kll/M_MOT_MBD_290_1500Nm_keshi/sw/config/config.h" --define=_INLINE --define=FLASH --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="sw/solutions/Mbds/Algo/$(basename $(<F)).d_raw" --obj_directory="sw/solutions/Mbds/Algo" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


