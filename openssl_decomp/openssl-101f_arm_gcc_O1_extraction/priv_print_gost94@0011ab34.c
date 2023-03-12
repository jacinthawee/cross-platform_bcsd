
undefined4 priv_print_gost94(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  EC_KEY *key;
  BIGNUM *pBVar5;
  BIGNUM *local_1c [2];
  
  iVar2 = BIO_indent(param_1,param_3,0x80);
  if (iVar2 == 0) {
    return 0;
  }
  BIO_printf(param_1,"Private key: ");
  iVar2 = EVP_PKEY_base_id(param_2);
  if (iVar2 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_2);
    if (key != (EC_KEY *)0x0) {
      pBVar5 = EC_KEY_get0_private_key(key);
      goto joined_r0x0011ac54;
    }
  }
  else if ((iVar2 == 0x32c) && (pvVar3 = EVP_PKEY_get0(param_2), pvVar3 != (void *)0x0)) {
    pBVar5 = *(BIGNUM **)((int)pvVar3 + 0x1c);
joined_r0x0011ac54:
    if (pBVar5 != (BIGNUM *)0x0) {
      BN_print(param_1,pBVar5);
      goto LAB_0011ab84;
    }
  }
  BIO_printf(param_1,"<undefined>");
LAB_0011ab84:
  BIO_printf(param_1,"\n");
  pvVar3 = EVP_PKEY_get0(param_2);
  pBVar5 = *(BIGNUM **)((int)pvVar3 + 0x18);
  BIO_indent(param_1,param_3,0x80);
  BIO_printf(param_1,"Public key: ");
  BN_print(param_1,pBVar5);
  BIO_printf(param_1,"\n");
  pvVar3 = EVP_PKEY_get0(param_2);
  local_1c[0] = BN_new();
  piVar1 = (int *)R3410_paramset;
  pcVar4 = R3410_paramset._12_4_;
  do {
    if (pcVar4 == (char *)0x0) {
      iVar2 = 0;
      BN_free(local_1c[0]);
LAB_0011ac04:
      BIO_indent(param_1,param_3,0x80);
      pcVar4 = OBJ_nid2ln(iVar2);
      BIO_printf(param_1,"Parameter set: %s\n",pcVar4);
      return 1;
    }
    BN_dec2bn(local_1c,pcVar4);
    iVar2 = BN_cmp(local_1c[0],*(BIGNUM **)((int)pvVar3 + 0x10));
    if (iVar2 == 0) {
      BN_free(local_1c[0]);
      iVar2 = *piVar1;
      goto LAB_0011ac04;
    }
    pcVar4 = (char *)piVar1[7];
    piVar1 = piVar1 + 4;
  } while( true );
}

