
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_BN_init_006a96a0)(auStack_40);
  if (pvDSOHandle == 0) {
LAB_005d77cc:
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    pcVar5 = "e_nuron.c";
    param_3 = 0x67;
    (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,0x67,0x69,"e_nuron.c",0xc5);
  }
  else {
    pcVar5 = param_7;
    iVar2 = (*pfnModExp)(param_2,param_3,param_4);
    if (iVar2 != 0) {
      if (pvDSOHandle == 0) goto LAB_005d77cc;
      pcVar5 = param_7;
      iVar2 = (*pfnModExp)(auStack_40,param_5,param_6);
      param_3 = param_5;
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_BN_mod_mul_006a9698)(param_2,param_2,auStack_40,param_7,param_8);
        bVar6 = iVar2 != 0;
        goto LAB_005d7728;
      }
    }
  }
  param_7 = pcVar5;
  param_2 = param_3;
  bVar6 = false;
LAB_005d7728:
  (*(code *)PTR_BN_free_006a811c)(auStack_40);
  if (local_2c == *(int *)puVar1) {
    return bVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (param_2 == 200) {
    if (param_7 == (char *)0x0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar4 = 0x43;
      uVar3 = 0xb0;
    }
    else {
      if (pvDSOHandle == 0) {
        if (NURON_LIBNAME != 0) {
          (*(code *)PTR_CRYPTO_free_006a7f88)();
        }
        NURON_LIBNAME = 0;
        NURON_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(param_7);
        return NURON_LIBNAME != 0;
      }
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar4 = 100;
      uVar3 = 0xb5;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,100,uVar4,"e_nuron.c",uVar3);
    return false;
  }
  if (NURON_lib_error_code == 0) {
    NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
  (*(code *)PTR_ERR_put_error_006a9030)(NURON_lib_error_code,100,0x65,"e_nuron.c",0xbc);
  return false;
}

