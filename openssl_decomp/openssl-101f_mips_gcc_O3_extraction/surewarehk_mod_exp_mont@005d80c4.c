
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int surewarehk_mod_exp_mont
              (int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
    iVar5 = 0x6b;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c",0x403);
    iVar2 = 0;
  }
  else {
    iVar5 = param_4[1];
    (*(code *)PTR_bn_expand2_006a9680)(param_1,iVar5);
    if (param_1 != (int *)0x0) {
      iVar5 = param_1[2];
      if (iVar5 == param_4[1]) {
        iVar2 = (*p_surewarehk_Mod_Exp)
                          (&local_64,iVar5 << 2,*param_4,param_3[1] << 2,*param_3,param_2[1] << 2,
                           *param_2,*param_1);
        iVar5 = 0x6b;
        surewarehk_error_handling(&local_64,0x6b,iVar2);
        if (iVar2 == 1) {
          iVar3 = param_4[1];
          param_1[1] = iVar3;
          if (0 < iVar3) {
            iVar4 = *param_1 + iVar3 * 4 + -8;
            do {
              iVar5 = *(int *)(iVar4 + 4);
              if (iVar5 != 0) break;
              iVar3 = iVar3 + -1;
              iVar4 = iVar4 + -4;
            } while (iVar3 != 0);
            param_1[1] = iVar3;
          }
        }
        goto LAB_005d8188;
      }
    }
    iVar2 = 0;
  }
LAB_005d8188:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (p_surewarehk_Free != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005d82cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*p_surewarehk_Free)(iVar5,0);
    return iVar2;
  }
  if (SUREWARE_lib_error_code == 0) {
    SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
                    /* WARNING: Could not recover jumptable at 0x005d8334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x66,0x75,"e_sureware.c",0x344);
  return iVar2;
}

