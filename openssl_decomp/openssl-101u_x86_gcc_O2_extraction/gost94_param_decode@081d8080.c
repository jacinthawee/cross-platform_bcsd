
bool gost94_param_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  DSA *key;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  bool bVar4;
  ASN1_OBJECT *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (ASN1_OBJECT *)0x0;
  key = (DSA *)EVP_PKEY_get0(param_1);
  pAVar1 = d2i_ASN1_OBJECT(&local_14,param_2,param_3);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
LAB_081d8130:
    bVar4 = false;
  }
  else {
    iVar2 = OBJ_obj2nid(local_14);
    ASN1_OBJECT_free(local_14);
    if (key == (DSA *)0x0) {
      key = DSA_new();
      iVar3 = EVP_PKEY_assign(param_1,0x32c,key);
      if (iVar3 == 0) goto LAB_081d8130;
    }
    iVar2 = fill_GOST94_params(key,iVar2);
    bVar4 = iVar2 != 0;
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar4;
}

