
undefined4 dh_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  uchar *penc;
  ASN1_STRING *a;
  int iVar1;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  undefined4 uVar2;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (uchar *)0x0;
  a = ASN1_STRING_new();
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(5,0x6f,0x41,"dh_ameth.c",0xf2);
    if (local_24 != (uchar *)0x0) {
      CRYPTO_free(local_24);
    }
  }
  else {
    iVar1 = i2d_DHparams(*(DH **)(param_2 + 0x14),&a->data);
    a->length = iVar1;
    if (iVar1 < 1) {
      ERR_put_error(5,0x6f,0x41,"dh_ameth.c",0xf8);
    }
    else {
      a->type = 0x10;
      a_00 = BN_to_ASN1_INTEGER(*(BIGNUM **)(*(int *)(param_2 + 0x14) + 0x18),(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) {
        ERR_put_error(5,0x6f,0x6a,"dh_ameth.c",0x101);
      }
      else {
        iVar1 = i2d_ASN1_INTEGER(a_00,&local_24);
        ASN1_STRING_clear_free(a_00);
        penc = local_24;
        aobj = OBJ_nid2obj(0x1c);
        iVar1 = PKCS8_pkey_set0(param_1,aobj,0,0x10,a,penc,iVar1);
        if (iVar1 != 0) {
          uVar2 = 1;
          goto LAB_08110074;
        }
      }
    }
    if (local_24 != (uchar *)0x0) {
      CRYPTO_free(local_24);
    }
    ASN1_STRING_free(a);
  }
  uVar2 = 0;
LAB_08110074:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

