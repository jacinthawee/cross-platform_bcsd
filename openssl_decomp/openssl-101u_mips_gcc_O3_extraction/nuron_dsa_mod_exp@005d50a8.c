
/* WARNING: Restarted to delay deadcode elimination for space: ram */

bool nuron_dsa_mod_exp(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                      undefined4 param_6,char *param_7,undefined4 param_8)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  bool bVar6;
  undefined auStack_40 [20];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_BN_init_006a857c)(auStack_40);
  if (pvDSOHandle == 0) {
LAB_005d51fc:
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    pcVar5 = "e_nuron.c";
    param_3 = 0x67;
    (*(code *)PTR_ERR_put_error_006a7f34)(NURON_lib_error_code,0x67,0x69,"e_nuron.c",0xc1);
  }
  else {
    pcVar5 = param_7;
    iVar2 = (*pfnModExp)(param_2,param_3,param_4);
    if (iVar2 != 0) {
      if (pvDSOHandle == 0) goto LAB_005d51fc;
      pcVar5 = param_7;
      iVar2 = (*pfnModExp)(auStack_40,param_5,param_6);
      param_3 = param_5;
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_BN_mod_mul_006a8574)(param_2,param_2,auStack_40,param_7,param_8);
        bVar6 = iVar2 != 0;
        goto LAB_005d5158;
      }
    }
  }
  param_7 = pcVar5;
  param_2 = param_3;
  bVar6 = false;
LAB_005d5158:
  (*(code *)PTR_BN_free_006a701c)(auStack_40);
  if (local_2c == *(int *)puVar1) {
    return bVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_2 == 200) {
    if (param_7 == (char *)0x0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar4 = 0x43;
      uVar3 = 0xae;
    }
    else {
      if (pvDSOHandle == 0) {
        if (NURON_LIBNAME != 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        NURON_LIBNAME = 0;
        NURON_LIBNAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_7);
        return NURON_LIBNAME != 0;
      }
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar4 = 100;
      uVar3 = 0xb2;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(NURON_lib_error_code,100,uVar4,"e_nuron.c",uVar3);
    return false;
  }
  if (NURON_lib_error_code == 0) {
    NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(NURON_lib_error_code,100,0x65,"e_nuron.c",0xb9);
  return false;
}

