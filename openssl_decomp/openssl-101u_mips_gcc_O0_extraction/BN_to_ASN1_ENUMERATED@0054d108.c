
ASN1_ENUMERATED * BN_to_ASN1_ENUMERATED(BIGNUM *bn,ASN1_ENUMERATED *ai)

{
  undefined *puVar1;
  int iVar2;
  uchar *puVar3;
  ASN1_ENUMERATED *a;
  int iVar4;
  
  a = ai;
  if ((ai == (ASN1_ENUMERATED *)0x0) && (a = ASN1_STRING_type_new(10), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8a,0x3a,"a_enum.c",0x92);
    return (ASN1_ENUMERATED *)0x0;
  }
  puVar1 = PTR_BN_num_bits_006a71f4;
  iVar2 = 0x10a;
  if (bn->neg == 0) {
    iVar2 = 10;
  }
  a->type = iVar2;
  iVar2 = (*(code *)puVar1)(bn);
  if (iVar2 == 0) {
    iVar4 = 0;
    if (3 < a->length) {
LAB_0054d200:
      puVar3 = a->data;
      goto LAB_0054d1a4;
    }
  }
  else {
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    iVar4 = (iVar2 >> 3) + 1;
    if ((iVar2 >> 3) + 4 < a->length) goto LAB_0054d200;
  }
  puVar3 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a7b58)(a->data,iVar4 + 4,"a_enum.c",0x9c);
  if (puVar3 == (uchar *)0x0) {
    ERR_put_error(0xd,0x8a,0x41,"a_enum.c",0x9e);
    if (ai != a) {
      ASN1_STRING_free(a);
      return (ASN1_ENUMERATED *)0x0;
    }
    return (ASN1_ENUMERATED *)0x0;
  }
  a->data = puVar3;
LAB_0054d1a4:
  iVar2 = (*(code *)PTR_BN_bn2bin_006a7200)(bn,puVar3);
  a->length = iVar2;
  return a;
}

