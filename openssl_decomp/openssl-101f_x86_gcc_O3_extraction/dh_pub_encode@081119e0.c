
uchar * dh_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  DH *a;
  ASN1_STRING *a_00;
  int iVar1;
  ASN1_INTEGER *a_01;
  ASN1_OBJECT *aobj;
  uchar *puVar2;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (uchar *)0x0;
  a = *(DH **)(param_2 + 0x14);
  a_00 = ASN1_STRING_new();
  iVar1 = i2d_DHparams(a,&a_00->data);
  a_00->length = iVar1;
  if (iVar1 < 1) {
    ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0x91);
    puVar2 = local_24;
    if (local_24 != (uchar *)0x0) {
      CRYPTO_free(local_24);
      puVar2 = (uchar *)0x0;
    }
  }
  else {
    a_01 = BN_to_ASN1_INTEGER(a->pub_key,(ASN1_INTEGER *)0x0);
    if (a_01 != (ASN1_INTEGER *)0x0) {
      iVar1 = i2d_ASN1_INTEGER(a_01,&local_24);
      ASN1_INTEGER_free(a_01);
      puVar2 = local_24;
      if (iVar1 < 1) {
        ERR_put_error(5,0x6d,0x41,"dh_ameth.c",0xa1);
      }
      else {
        aobj = OBJ_nid2obj(0x1c);
        iVar1 = X509_PUBKEY_set0_param(param_1,aobj,0x10,a_00,puVar2,iVar1);
        puVar2 = (uchar *)0x1;
        if (iVar1 != 0) goto LAB_08111aac;
      }
    }
    if (local_24 != (uchar *)0x0) {
      CRYPTO_free(local_24);
    }
    ASN1_STRING_free(a_00);
    puVar2 = (uchar *)0x0;
  }
LAB_08111aac:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return puVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

