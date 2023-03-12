
ASN1_STRING * dh_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  ASN1_STRING *a;
  ASN1_INTEGER *a_00;
  ASN1_OBJECT *aobj;
  int iVar1;
  DH *a_01;
  uchar *local_1c [2];
  
  a_01 = *(DH **)(param_2 + 0x14);
  local_1c[0] = (uchar *)0x0;
  a = ASN1_STRING_new();
  iVar1 = 0x8b;
  if (a != (ASN1_STRING *)0x0) {
    iVar1 = i2d_DHparams(a_01,&a->data);
    a->length = iVar1;
    if (iVar1 < 1) {
      iVar1 = 0x90;
    }
    else {
      a_00 = BN_to_ASN1_INTEGER(a_01->pub_key,(ASN1_INTEGER *)0x0);
      if (a_00 == (ASN1_INTEGER *)0x0) goto LAB_0009962c;
      iVar1 = i2d_ASN1_INTEGER(a_00,local_1c);
      ASN1_INTEGER_free(a_00);
      if (0 < iVar1) {
        aobj = OBJ_nid2obj(0x1c);
        iVar1 = X509_PUBKEY_set0_param(param_1,aobj,0x10,a,local_1c[0],iVar1);
        if (iVar1 != 0) {
          return (ASN1_STRING *)0x1;
        }
        goto LAB_0009962c;
      }
      iVar1 = 0x9e;
    }
  }
  ERR_put_error(5,0x6d,0x41,"dh_ameth.c",iVar1);
LAB_0009962c:
  if (local_1c[0] != (uchar *)0x0) {
    CRYPTO_free(local_1c[0]);
  }
  if (a != (ASN1_STRING *)0x0) {
    ASN1_STRING_free(a);
    a = (ASN1_STRING *)0x0;
  }
  return a;
}

