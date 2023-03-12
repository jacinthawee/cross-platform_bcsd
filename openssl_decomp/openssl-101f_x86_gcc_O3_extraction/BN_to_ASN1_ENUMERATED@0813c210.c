
ASN1_ENUMERATED * BN_to_ASN1_ENUMERATED(BIGNUM *bn,ASN1_ENUMERATED *ai)

{
  int iVar1;
  uchar *to;
  ASN1_ENUMERATED *a;
  int iVar2;
  
  a = ai;
  if ((ai == (ASN1_ENUMERATED *)0x0) && (a = ASN1_STRING_type_new(10), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8a,0x3a,"a_enum.c",0x95);
    return (ASN1_ENUMERATED *)0x0;
  }
  a->type = (-(uint)(bn->neg == 0) & 0xffffff00) + 0x10a;
  iVar1 = BN_num_bits(bn);
  if (iVar1 == 0) {
    iVar2 = 0;
    if (a->length < 4) {
LAB_0813c250:
      to = (uchar *)CRYPTO_realloc(a->data,iVar2 + 4,"a_enum.c",0x9e);
      if (to == (uchar *)0x0) {
        ERR_put_error(0xd,0x8a,0x41,"a_enum.c",0xa1);
        if (ai != a) {
          ASN1_STRING_free(a);
        }
        return (ASN1_ENUMERATED *)0x0;
      }
      a->data = to;
      goto LAB_0813c270;
    }
  }
  else {
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    iVar2 = (iVar1 >> 3) + 1;
    iVar1 = (iVar1 >> 3) + 4;
    if (a->length == iVar1 || a->length < iVar1) goto LAB_0813c250;
  }
  to = a->data;
LAB_0813c270:
  iVar1 = BN_bn2bin(bn,to);
  a->length = iVar1;
  return a;
}

