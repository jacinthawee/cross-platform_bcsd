
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 cca_get_random_bytes(undefined4 *param_1,uint param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int local_50;
  undefined auStack_4c [4];
  undefined auStack_48 [4];
  undefined auStack_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  char local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_38 = s_RANDOM_00673b0c._0_4_;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34 = s_RANDOM_00673b0c._4_4_;
  local_30 = s_RANDOM_00673b0c[8];
  if (7 < (int)param_2) {
    do {
      (*randomNumberGenerate)(&local_50,auStack_4c,auStack_48,auStack_44,&local_38,&local_40);
      if (local_50 != 0) goto LAB_005ccb48;
      param_2 = param_2 - 8;
      *param_1 = local_40;
      param_1[1] = local_3c;
      param_1 = param_1 + 2;
    } while (7 < param_2);
  }
  uVar2 = 1;
  if (param_2 != 0) {
    (*randomNumberGenerate)(&local_50,auStack_4c,0,0,&local_38,&local_40);
    if (local_50 == 0) {
      (*(code *)PTR_memcpy_006aabf4)(param_1,&local_40,param_2);
      uVar2 = 1;
    }
    else {
LAB_005ccb48:
      uVar2 = 0;
    }
  }
  if (local_2c == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (CCA4758_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006aa63c)(CCA4758_lib_error_code,CCA4758_str_functs);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(CCA4758_lib_error_code,CCA4758_str_reasons);
    CCA4758_error_init = 1;
  }
  if (CCA4758_LIB_NAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  CCA4758_LIB_NAME = 0;
  return 1;
}

