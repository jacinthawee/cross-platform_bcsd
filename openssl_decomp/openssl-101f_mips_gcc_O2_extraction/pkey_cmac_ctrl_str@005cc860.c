
uint pkey_cmac_ctrl_str(int param_1,char *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_3 != 0) {
    if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0'))
    {
      iVar2 = (*(code *)PTR_strlen_006aab30)(param_3);
      if (-1 < iVar2) {
        iVar2 = (*(code *)PTR_CMAC_Init_006aa62c)(*(undefined4 *)(param_1 + 0x14),param_3,iVar2,0,0)
        ;
        uVar4 = (uint)(iVar2 != 0);
        goto LAB_005cc99c;
      }
    }
    else {
      iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"cipher");
      if (iVar2 != 0) {
        uVar4 = (*(code *)PTR_strcmp_006aac20)(param_2,"hexkey");
        if (uVar4 == 0) {
          iVar2 = (*(code *)PTR_string_to_hex_006a848c)(param_3,&local_20);
          if (iVar2 != 0) {
            if (-1 < local_20) {
              iVar3 = (*(code *)PTR_CMAC_Init_006aa62c)
                                (*(undefined4 *)(param_1 + 0x14),iVar2,local_20,0,0);
              uVar4 = (uint)(iVar3 != 0);
            }
            (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
          }
        }
        else {
          uVar4 = 0xfffffffe;
        }
        goto LAB_005cc99c;
      }
      iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(param_3);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_CMAC_Init_006aa62c)
                          (*(undefined4 *)(param_1 + 0x14),0,0,iVar2,*(undefined4 *)(param_1 + 4));
        uVar4 = (uint)(iVar2 != 0);
        goto LAB_005cc99c;
      }
    }
  }
  uVar4 = 0;
LAB_005cc99c:
  if (local_1c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return 1;
}

