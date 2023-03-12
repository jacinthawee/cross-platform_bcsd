
undefined4 dh_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_STRING *a;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  int iVar1;
  uchar *local_24 [2];
  
  local_24[0] = (uchar *)0x0;
  a = ASN1_STRING_new();
  iVar1 = 0xf2;
  if (a != (ASN1_STRING *)0x0) {
    iVar1 = i2d_DHparams(*(DH **)(param_2 + 0x14),&a->data);
    a->length = iVar1;
    if (0 < iVar1) {
      a->type = 0x10;
      a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x18),(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(5,0x6f,0x6a,"dh_ameth.c",0x101);
      }
      else {
        iVar1 = i2d_ASN1_INTEGER(a_00,local_24);
        ASN1_STRING_clear_free(a_00);
        aobj = OBJ_nid2obj(0x1c);
        iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,local_24[0],iVar1);
        if (iVar1 != 0) {
          return 1;
        }
      }
      goto LAB_000994a8;
    }
    iVar1 = 0xf8;
  }
  ERR_put_error(5,0x6f,0x41,"dh_ameth.c",iVar1);
LAB_000994a8:
  if (local_24[0] != (uchar *)0x0) {
    CRYPTO_free(local_24[0]);
  }
  if (a != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a);
  }
  return 0;
}

