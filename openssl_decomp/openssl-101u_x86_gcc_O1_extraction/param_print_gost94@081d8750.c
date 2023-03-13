
undefined4 param_print_gost94(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int in_GS_OFFSET;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pvVar1 = EVP_PKEY_get0(param_2);
  local_24 = BN_new();
  if (R3410_paramset._12_4_ != (char *)0x0) {
    pcVar3 = R3410_paramset._12_4_;
    piVar4 = (int *)R3410_paramset;
    do {
      BN_dec2bn(&local_24,pcVar3);
      iVar2 = BN_cmp(local_24,*(BIGNUM **)((int)pvVar1 + 0x10));
      if (iVar2 == 0) {
        BN_free(local_24);
        iVar2 = *piVar4;
        goto LAB_081d87ea;
      }
      pcVar3 = (char *)piVar4[7];
      piVar4 = piVar4 + 4;
    } while (pcVar3 != (char *)0x0);
  }
  iVar2 = 0;
  BN_free(local_24);
LAB_081d87ea:
  BIO_indent(param_1,param_3,0x80);
  pcVar3 = OBJ_nid2ln(iVar2);
  BIO_printf(param_1,"Parameter set: %s\n",pcVar3);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

