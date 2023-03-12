
undefined4 dsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_STRING *a;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  int iVar1;
  uchar *local_24 [2];
  
  local_24[0] = (uchar *)0x0;
  if ((*(int *)(param_2 + 0x14) == 0) || (*(int *)(*(int *)(param_2 + 0x14) + 0x1c) == 0)) {
    a = (ASN1_STRING *)0x0;
    ERR_put_error(10,0x74,0x65,"dsa_ameth.c",0x124);
  }
  else {
    a = ASN1_STRING_new();
    iVar1 = 299;
    if (a != (ASN1_STRING *)0x0) {
      iVar1 = i2d_DSAparams(*(DSA **)(param_2 + 0x14),&a->data);
      a->length = iVar1;
      if (0 < iVar1) {
        a->type = 0x10;
        a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x1c),(ASN1_INTEGER *)0x0)
        ;
        if (a_00 == (ASN1_INTEGER *)0x0) {
          ERR_put_error(10,0x74,0x6d,"dsa_ameth.c",0x13a);
        }
        else {
          iVar1 = i2d_ASN1_INTEGER(a_00,local_24);
          ASN1_STRING_clear_free(a_00);
          aobj = OBJ_nid2obj(0x74);
          iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,local_24[0],iVar1);
          if (iVar1 != 0) {
            return 1;
          }
        }
        goto LAB_00107184;
      }
      iVar1 = 0x131;
    }
    ERR_put_error(10,0x74,0x41,"dsa_ameth.c",iVar1);
  }
LAB_00107184:
  if (local_24[0] != (uchar *)0x0) {
    CRYPTO_free(local_24[0]);
  }
  if (a != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a);
  }
  return 0;
}

