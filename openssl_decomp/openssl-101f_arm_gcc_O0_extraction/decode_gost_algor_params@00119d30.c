
ASN1_OBJECT ** decode_gost_algor_params(EVP_PKEY *param_1,X509_ALGOR *param_2)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  DSA *key;
  EC_KEY *key_00;
  ASN1_OBJECT *local_28;
  int local_24;
  undefined4 *local_20;
  undefined4 local_1c [2];
  
  local_28 = (ASN1_OBJECT *)0x0;
  local_24 = -1;
  X509_ALGOR_get0(&local_28,&local_24,&local_20,param_2);
  if (local_24 == 0x10) {
    local_1c[0] = local_20[2];
    iVar2 = OBJ_obj2nid(local_28);
    ppAVar1 = (ASN1_OBJECT **)d2i_GOST_KEY_PARAMS(0,local_1c,*local_20);
    if (ppAVar1 == (ASN1_OBJECT **)0x0) {
      ERR_GOST_error(99,100,"gost_ameth.c",0x75);
    }
    else {
      iVar3 = OBJ_obj2nid(*ppAVar1);
      GOST_KEY_PARAMS_free(ppAVar1);
      EVP_PKEY_set_type(param_1,iVar2);
      if (iVar2 == 0x32b) {
        key_00 = (EC_KEY *)EVP_PKEY_get0(param_1);
        if (key_00 != (EC_KEY *)0x0) {
LAB_00119dd4:
          ppAVar1 = (ASN1_OBJECT **)fill_GOST2001_params(key_00,iVar3);
          if (ppAVar1 != (ASN1_OBJECT **)0x0) {
            ppAVar1 = (ASN1_OBJECT **)0x1;
          }
          return ppAVar1;
        }
        key_00 = EC_KEY_new();
        iVar2 = EVP_PKEY_assign(param_1,0x32b,key_00);
        if (iVar2 != 0) goto LAB_00119dd4;
      }
      else {
        if (iVar2 != 0x32c) {
          return (ASN1_OBJECT **)0x1;
        }
        key = (DSA *)EVP_PKEY_get0(param_1);
        if (key != (DSA *)0x0) {
LAB_00119db8:
          ppAVar1 = (ASN1_OBJECT **)fill_GOST94_params(key,iVar3);
          if (ppAVar1 != (ASN1_OBJECT **)0x0) {
            ppAVar1 = (ASN1_OBJECT **)0x1;
          }
          return ppAVar1;
        }
        key = DSA_new();
        iVar2 = EVP_PKEY_assign(param_1,0x32c,key);
        if (iVar2 != 0) goto LAB_00119db8;
      }
      ppAVar1 = (ASN1_OBJECT **)0x0;
    }
  }
  else {
    ERR_GOST_error(99,99,"gost_ameth.c",0x6b);
    ppAVar1 = (ASN1_OBJECT **)0x0;
  }
  return ppAVar1;
}

