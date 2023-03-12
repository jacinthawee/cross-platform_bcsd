
bool __regparm3 decode_gost_algor_params(EVP_PKEY *param_1,X509_ALGOR *param_2)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  DSA *key;
  EC_KEY *key_00;
  int in_GS_OFFSET;
  bool bVar4;
  ASN1_OBJECT *local_30;
  int local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = (ASN1_OBJECT *)0x0;
  local_2c = -1;
  X509_ALGOR_get0(&local_30,&local_2c,&local_28,param_2);
  if (local_2c == 0x10) {
    local_24 = local_28[2];
    iVar1 = OBJ_obj2nid(local_30);
    ppAVar2 = (ASN1_OBJECT **)d2i_GOST_KEY_PARAMS(0,&local_24,*local_28);
    if (ppAVar2 == (ASN1_OBJECT **)0x0) {
      ERR_GOST_error(99,100,"gost_ameth.c",0x75);
      bVar4 = false;
    }
    else {
      iVar3 = OBJ_obj2nid(*ppAVar2);
      GOST_KEY_PARAMS_free(ppAVar2);
      EVP_PKEY_set_type(param_1,iVar1);
      if (iVar1 == 0x32b) {
        key_00 = (EC_KEY *)EVP_PKEY_get0(param_1);
        if (key_00 == (EC_KEY *)0x0) {
          key_00 = EC_KEY_new();
          iVar1 = EVP_PKEY_assign(param_1,0x32b,key_00);
          if (iVar1 == 0) {
            bVar4 = false;
            goto LAB_081d7919;
          }
        }
        iVar1 = fill_GOST2001_params(key_00,iVar3);
        bVar4 = iVar1 != 0;
      }
      else {
        bVar4 = true;
        if (iVar1 == 0x32c) {
          key = (DSA *)EVP_PKEY_get0(param_1);
          if (key == (DSA *)0x0) {
            key = DSA_new();
            iVar1 = EVP_PKEY_assign(param_1,0x32c,key);
            if (iVar1 == 0) {
              bVar4 = false;
              goto LAB_081d7919;
            }
          }
          iVar1 = fill_GOST94_params(key,iVar3);
          bVar4 = iVar1 != 0;
        }
      }
    }
  }
  else {
    ERR_GOST_error(99,99,"gost_ameth.c",0x6b);
    bVar4 = false;
  }
LAB_081d7919:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

