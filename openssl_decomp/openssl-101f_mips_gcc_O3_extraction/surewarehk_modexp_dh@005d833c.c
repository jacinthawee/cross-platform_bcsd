
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int surewarehk_modexp_dh
              (undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
              undefined4 *param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined auStack_56 [50];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_64 = DAT_00674c1c;
  local_60 = DAT_00674c20;
  local_5c = DAT_00674c24;
  local_58 = DAT_00674c28;
  (*(code *)PTR_memset_006aab00)(auStack_56,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x403);
    iVar2 = 0;
  }
  else {
    (*(code *)PTR_bn_expand2_006a9680)(param_2,param_5[1]);
    if (param_2 != (int *)0x0) {
      if (param_2[2] == param_5[1]) {
        iVar2 = (*p_surewarehk_Mod_Exp)
                          (&local_64,param_2[2] << 2,*param_5,param_4[1] << 2,*param_4,
                           param_3[1] << 2,*param_3,*param_2);
        surewarehk_error_handling(&local_64,0x6b,iVar2);
        if (iVar2 == 1) {
          iVar3 = param_5[1];
          param_2[1] = iVar3;
          if (0 < iVar3) {
            iVar4 = *param_2 + iVar3 * 4 + -8;
            do {
              if (*(int *)(iVar4 + 4) != 0) break;
              iVar3 = iVar3 + -1;
              iVar4 = iVar4 + -4;
            } while (iVar3 != 0);
            param_2[1] = iVar3;
          }
        }
        goto LAB_005d8400;
      }
    }
    iVar2 = 0;
  }
LAB_005d8400:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (surewarehk_dso == 0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    iVar2 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x67,0x70,"e_sureware.c",0x227);
  }
  else {
    (*p_surewarehk_Finish)();
    iVar2 = (*(code *)PTR_DSO_free_006a9994)(surewarehk_dso);
    if (iVar2 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      iVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x67,0x68,"e_sureware.c",0x22e);
    }
    else {
      iVar2 = 1;
    }
  }
  if (logstream != 0) {
    (*(code *)PTR_BIO_free_006a7f70)();
  }
  surewarehk_dso = 0;
  p_surewarehk_Init = 0;
  p_surewarehk_Finish = (code *)0x0;
  p_surewarehk_Rand_Bytes = 0;
  p_surewarehk_Mod_Exp = (code *)0x0;
  p_surewarehk_Rand_Seed = 0;
  p_surewarehk_Load_Privkey = 0;
  p_surewarehk_Load_Rsa_Pubkey = 0;
  p_surewarehk_Free = 0;
  p_surewarehk_Rsa_Priv_Dec = 0;
  p_surewarehk_Rsa_Sign = 0;
  p_surewarehk_Dsa_Sign = 0;
  p_surewarehk_Info_Pubkey = 0;
  p_surewarehk_Load_Dsa_Pubkey = 0;
  return iVar2;
}

