
ASN1_INTEGER * BN_to_ASN1_INTEGER(BIGNUM *bn,ASN1_INTEGER *ai)

{
  int iVar1;
  uchar *to;
  ASN1_INTEGER *a;
  int iVar2;
  
  a = ai;
  if ((ai == (ASN1_INTEGER *)0x0) && (a = ASN1_STRING_type_new(2), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8b,0x3a,"a_int.c",0x19f);
    return (ASN1_INTEGER *)0x0;
  }
  a->type = (-(uint)(bn->neg == 0) & 0xffffff00) + 0x102;
  iVar1 = BN_num_bits(bn);
  if (iVar1 == 0) {
    iVar2 = 0;
    if (3 < a->length) {
LAB_0813af60:
      to = a->data;
      goto LAB_0813af63;
    }
  }
  else {
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    iVar2 = (iVar1 >> 3) + 1;
    iVar1 = (iVar1 >> 3) + 4;
    if (a->length != iVar1 && iVar1 <= a->length) goto LAB_0813af60;
  }
  to = (uchar *)CRYPTO_realloc(a->data,iVar2 + 4,"a_int.c",0x1a9);
  if (to == (uchar *)0x0) {
    ERR_put_error(0xd,0x8b,0x41,"a_int.c",0x1ac);
    if (ai != a) {
      ASN1_STRING_free(a);
    }
    return (ASN1_INTEGER *)0x0;
  }
  a->data = to;
LAB_0813af63:
  iVar1 = BN_bn2bin(bn,to);
  a->length = iVar1;
  if (iVar1 == 0) {
    *a->data = '\0';
    a->length = 1;
  }
  return a;
}

