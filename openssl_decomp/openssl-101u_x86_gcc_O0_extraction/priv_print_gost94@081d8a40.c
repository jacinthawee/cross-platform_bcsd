
int priv_print_gost94(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  EC_KEY *key;
  BIGNUM *pBVar4;
  int *piVar5;
  int in_GS_OFFSET;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 == 0) goto LAB_081d8a71;
  BIO_printf(param_1,"Private key: ");
  iVar1 = EVP_PKEY_base_id(param_2);
  if (iVar1 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_2);
    if ((key == (EC_KEY *)0x0) || (pBVar4 = EC_KEY_get0_private_key(key), pBVar4 == (BIGNUM *)0x0))
    goto LAB_081d8abf;
LAB_081d8be7:
    BN_print(param_1,pBVar4);
  }
  else {
    if ((iVar1 == 0x32c) &&
       ((pvVar2 = EVP_PKEY_get0(param_2), pvVar2 != (void *)0x0 &&
        (pBVar4 = *(BIGNUM **)((int)pvVar2 + 0x1c), pBVar4 != (BIGNUM *)0x0)))) goto LAB_081d8be7;
LAB_081d8abf:
    BIO_printf(param_1,"<undefined>");
  }
  BIO_printf(param_1,"\n");
  pvVar2 = EVP_PKEY_get0(param_2);
  pBVar4 = *(BIGNUM **)((int)pvVar2 + 0x18);
  BIO_indent(param_1,param_3,0x80);
  BIO_printf(param_1,"Public key: ");
  BN_print(param_1,pBVar4);
  BIO_printf(param_1,"\n");
  pvVar2 = EVP_PKEY_get0(param_2);
  local_24 = BN_new();
  if (R3410_paramset._12_4_ != (char *)0x0) {
    pcVar3 = R3410_paramset._12_4_;
    piVar5 = (int *)R3410_paramset;
    do {
      BN_dec2bn(&local_24,pcVar3);
      iVar1 = BN_cmp(local_24,*(BIGNUM **)((int)pvVar2 + 0x10));
      if (iVar1 == 0) {
        BN_free(local_24);
        iVar1 = *piVar5;
        goto LAB_081d8b8f;
      }
      pcVar3 = (char *)piVar5[7];
      piVar5 = piVar5 + 4;
    } while (pcVar3 != (char *)0x0);
  }
  iVar1 = 0;
  BN_free(local_24);
LAB_081d8b8f:
  BIO_indent(param_1,param_3,0x80);
  pcVar3 = OBJ_nid2ln(iVar1);
  BIO_printf(param_1,"Parameter set: %s\n",pcVar3);
  iVar1 = 1;
LAB_081d8a71:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

