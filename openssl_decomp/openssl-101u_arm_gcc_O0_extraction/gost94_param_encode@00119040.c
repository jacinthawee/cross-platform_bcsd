
void gost94_param_encode(EVP_PKEY *param_1,uchar **param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  ASN1_OBJECT *a;
  char *str;
  BIGNUM *local_14;
  
  pvVar2 = EVP_PKEY_get0(param_1);
  local_14 = BN_new();
  piVar1 = (int *)R3410_paramset;
  str = R3410_paramset._12_4_;
  do {
    if (str == (char *)0x0) {
      BN_free(local_14);
      iVar3 = 0;
LAB_0011908a:
      a = OBJ_nid2obj(iVar3);
      i2d_ASN1_OBJECT(a,param_2);
      return;
    }
    BN_dec2bn(&local_14,str);
    iVar3 = BN_cmp(local_14,*(BIGNUM **)((int)pvVar2 + 0x10));
    if (iVar3 == 0) {
      BN_free(local_14);
      iVar3 = *piVar1;
      goto LAB_0011908a;
    }
    str = (char *)piVar1[7];
    piVar1 = piVar1 + 4;
  } while( true );
}

