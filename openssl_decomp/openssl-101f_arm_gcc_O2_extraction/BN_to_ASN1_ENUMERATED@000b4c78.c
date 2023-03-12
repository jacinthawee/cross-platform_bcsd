
ASN1_ENUMERATED * BN_to_ASN1_ENUMERATED(BIGNUM *bn,ASN1_ENUMERATED *ai)

{
  uchar *to;
  ASN1_ENUMERATED *a;
  int iVar1;
  int iVar2;
  
  a = ai;
  if ((ai == (ASN1_ENUMERATED *)0x0) && (a = ASN1_STRING_type_new(10), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8a,0x3a,"a_enum.c",0x95);
    return (ASN1_ENUMERATED *)0x0;
  }
  if (bn->neg == 0) {
    iVar2 = 10;
  }
  else {
    iVar2 = 0x10a;
  }
  a->type = iVar2;
  iVar2 = BN_num_bits(bn);
  if (iVar2 == 0) {
    if (a->length < 4) goto LAB_000b4caa;
  }
  else {
    iVar1 = iVar2 + 7;
    if (-1 < iVar2) {
      iVar1 = iVar2;
    }
    iVar2 = (iVar1 >> 3) + 1;
    if (a->length <= (iVar1 >> 3) + 4) {
LAB_000b4caa:
      to = (uchar *)CRYPTO_realloc(a->data,iVar2 + 4,"a_enum.c",0x9e);
      if (to == (uchar *)0x0) {
        ERR_put_error(0xd,0x8a,0x41,"a_enum.c",0xa1);
        if (ai == a) {
          return (ASN1_ENUMERATED *)0x0;
        }
        ASN1_STRING_free(a);
        return (ASN1_ENUMERATED *)0x0;
      }
      a->data = to;
      goto LAB_000b4cc4;
    }
  }
  to = a->data;
LAB_000b4cc4:
  iVar2 = BN_bn2bin(bn,to);
  a->length = iVar2;
  return a;
}

