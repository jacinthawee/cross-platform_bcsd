
uchar * dsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  ASN1_STRING *a;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  uchar *puVar2;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (uchar *)0x0;
  a = ASN1_STRING_new();
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(10,0x74,0x41,"dsa_ameth.c",0x13a);
    puVar2 = local_24;
    if (local_24 != (uchar *)0x0) {
      CRYPTO_free(local_24);
      puVar2 = (uchar *)0x0;
    }
  }
  else {
    iVar1 = i2d_DSAparams(*(DSA **)(param_2 + 0x14),&a->data);
    a->length = iVar1;
    if (iVar1 < 1) {
      a_00 = (ASN1_INTEGER *)0x0;
      ERR_put_error(10,0x74,0x41,"dsa_ameth.c",0x141);
    }
    else {
      a->type = 0x10;
      a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x1c),(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(10,0x74,0x6d,"dsa_ameth.c",0x14b);
      }
      else {
        iVar1 = i2d_ASN1_INTEGER(a_00,&local_24);
        ASN1_INTEGER_free(a_00);
        puVar2 = local_24;
        aobj = OBJ_nid2obj(0x74);
        iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,puVar2,iVar1);
        if (iVar1 != 0) {
          puVar2 = (uchar *)0x1;
          goto LAB_081c364e;
        }
      }
    }
    if (local_24 != (uchar *)0x0) {
      CRYPTO_free(local_24);
    }
    ASN1_STRING_free(a);
    if (a_00 == (ASN1_INTEGER *)0x0) {
      puVar2 = (uchar *)0x0;
    }
    else {
      ASN1_INTEGER_free(a_00);
      puVar2 = (uchar *)0x0;
    }
  }
LAB_081c364e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

