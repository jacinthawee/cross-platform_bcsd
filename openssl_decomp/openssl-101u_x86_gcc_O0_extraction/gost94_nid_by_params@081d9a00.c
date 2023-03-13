
undefined4 gost94_nid_by_params(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *str;
  undefined4 *puVar3;
  int in_GS_OFFSET;
  BIGNUM *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = BN_new();
  if (R3410_paramset._12_4_ != (char *)0x0) {
    str = R3410_paramset._12_4_;
    puVar3 = (undefined4 *)R3410_paramset;
    do {
      BN_dec2bn(&local_14,str);
      iVar1 = BN_cmp(local_14,*(BIGNUM **)(param_1 + 0x10));
      if (iVar1 == 0) {
        BN_free(local_14);
        uVar2 = *puVar3;
        goto LAB_081d9a8a;
      }
      str = (char *)puVar3[7];
      puVar3 = puVar3 + 4;
    } while (str != (char *)0x0);
  }
  BN_free(local_14);
  uVar2 = 0;
LAB_081d9a8a:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

