
void gost94_param_encode(EVP_PKEY *param_1,uchar **param_2)

{
  void *pvVar1;
  int iVar2;
  ASN1_OBJECT *a;
  char *str;
  int *piVar3;
  int in_GS_OFFSET;
  BIGNUM *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pvVar1 = EVP_PKEY_get0(param_1);
  local_24 = BN_new();
  if (R3410_paramset._12_4_ != (char *)0x0) {
    str = R3410_paramset._12_4_;
    piVar3 = (int *)R3410_paramset;
    do {
      BN_dec2bn(&local_24,str);
      iVar2 = BN_cmp(local_24,*(BIGNUM **)((int)pvVar1 + 0x10));
      if (iVar2 == 0) {
        BN_free(local_24);
        iVar2 = *piVar3;
        goto LAB_081d886a;
      }
      str = (char *)piVar3[7];
      piVar3 = piVar3 + 4;
    } while (str != (char *)0x0);
  }
  BN_free(local_24);
  iVar2 = 0;
LAB_081d886a:
  a = OBJ_nid2obj(iVar2);
  i2d_ASN1_OBJECT(a,param_2);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

