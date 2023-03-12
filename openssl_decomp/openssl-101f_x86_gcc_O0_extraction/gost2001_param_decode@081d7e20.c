
bool gost2001_param_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  EC_KEY *key;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  bool bVar4;
  ASN1_OBJECT *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (ASN1_OBJECT *)0x0;
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  pAVar1 = d2i_ASN1_OBJECT(&local_14,param_2,param_3);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
LAB_081d7ed0:
    bVar4 = false;
  }
  else {
    iVar2 = OBJ_obj2nid(local_14);
    ASN1_OBJECT_free(local_14);
    if (key == (EC_KEY *)0x0) {
      key = EC_KEY_new();
      iVar3 = EVP_PKEY_assign(param_1,0x32b,key);
      if (iVar3 == 0) goto LAB_081d7ed0;
    }
    iVar2 = fill_GOST2001_params(key,iVar2);
    bVar4 = iVar2 != 0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar4;
}

