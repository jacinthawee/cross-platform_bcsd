
int gost94_param_decode(EVP_PKEY *param_1,uchar **param_2,long param_3)

{
  DSA *key;
  ASN1_OBJECT *pAVar1;
  int iVar2;
  int iVar3;
  ASN1_OBJECT *local_1c;
  
  local_1c = (ASN1_OBJECT *)0x0;
  key = (DSA *)EVP_PKEY_get0(param_1);
  pAVar1 = d2i_ASN1_OBJECT(&local_1c,param_2,param_3);
  if (pAVar1 == (ASN1_OBJECT *)0x0) {
    return 0;
  }
  iVar2 = OBJ_obj2nid(local_1c);
  ASN1_OBJECT_free(local_1c);
  if (key == (DSA *)0x0) {
    key = DSA_new();
    iVar3 = EVP_PKEY_assign(param_1,0x32c,key);
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar2 = fill_GOST94_params(key,iVar2);
  if (iVar2 != 0) {
    iVar2 = 1;
  }
  return iVar2;
}

