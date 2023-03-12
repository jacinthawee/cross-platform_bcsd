
undefined4 pub_print_gost94(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  int *piVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  BIGNUM *a;
  BIGNUM *local_1c [2];
  
  pvVar2 = EVP_PKEY_get0(param_2);
  a = *(BIGNUM **)((int)pvVar2 + 0x18);
  BIO_indent(param_1,param_3,0x80);
  BIO_printf(param_1,"Public key: ");
  BN_print(param_1,a);
  BIO_printf(param_1,"\n");
  pvVar2 = EVP_PKEY_get0(param_2);
  local_1c[0] = BN_new();
  piVar1 = (int *)R3410_paramset;
  pcVar3 = R3410_paramset._12_4_;
  do {
    if (pcVar3 == (char *)0x0) {
      iVar4 = 0;
      BN_free(local_1c[0]);
LAB_0011ae16:
      BIO_indent(param_1,param_3,0x80);
      pcVar3 = OBJ_nid2ln(iVar4);
      BIO_printf(param_1,"Parameter set: %s\n",pcVar3);
      return 1;
    }
    BN_dec2bn(local_1c,pcVar3);
    iVar4 = BN_cmp(local_1c[0],*(BIGNUM **)((int)pvVar2 + 0x10));
    if (iVar4 == 0) {
      BN_free(local_1c[0]);
      iVar4 = *piVar1;
      goto LAB_0011ae16;
    }
    pcVar3 = (char *)piVar1[7];
    piVar1 = piVar1 + 4;
  } while( true );
}

