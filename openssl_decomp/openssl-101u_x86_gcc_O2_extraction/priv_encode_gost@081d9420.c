
int priv_encode_gost(PKCS8_PRIV_KEY_INFO *param_1,EVP_PKEY *param_2)

{
  int iVar1;
  ASN1_OBJECT *aobj;
  void *pval;
  void *pvVar2;
  BIGNUM *bn;
  ASN1_INTEGER *a;
  EC_KEY *key;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = EVP_PKEY_base_id(param_2);
  aobj = OBJ_nid2obj(iVar1);
  pval = (void *)encode_gost_algor_params();
  local_24 = (uchar *)0x0;
  iVar1 = 0;
  if (pval == (void *)0x0) goto LAB_081d94db;
  iVar1 = EVP_PKEY_base_id(param_2);
  if (iVar1 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_2);
    if (key == (EC_KEY *)0x0) goto LAB_081d9498;
    bn = EC_KEY_get0_private_key(key);
  }
  else {
    if (iVar1 == 0x32c) {
      pvVar2 = EVP_PKEY_get0(param_2);
      if (pvVar2 != (void *)0x0) {
        bn = *(BIGNUM **)((int)pvVar2 + 0x1c);
        goto LAB_081d949a;
      }
    }
LAB_081d9498:
    bn = (BIGNUM *)0x0;
  }
LAB_081d949a:
  a = BN_to_ASN1_INTEGER(bn,(ASN1_INTEGER *)0x0);
  iVar1 = i2d_ASN1_INTEGER(a,&local_24);
  ASN1_INTEGER_free(a);
  iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,pval,local_24,iVar1);
LAB_081d94db:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

