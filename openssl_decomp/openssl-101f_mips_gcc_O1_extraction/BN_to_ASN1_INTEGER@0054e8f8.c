
ASN1_INTEGER * BN_to_ASN1_INTEGER(BIGNUM *bn,ASN1_INTEGER *ai)

{
  undefined *puVar1;
  int iVar2;
  uchar *puVar3;
  ASN1_INTEGER *a;
  int iVar4;
  
  a = ai;
  if ((ai == (ASN1_INTEGER *)0x0) && (a = ASN1_STRING_type_new(2), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0x8b,0x3a,"a_int.c",0x19f);
    return (ASN1_INTEGER *)0x0;
  }
  puVar1 = PTR_BN_num_bits_006a82f4;
  iVar2 = 0x102;
  if (bn->neg == 0) {
    iVar2 = 2;
  }
  a->type = iVar2;
  iVar2 = (*(code *)puVar1)(bn);
  if (iVar2 == 0) {
    iVar4 = 0;
    if (3 < a->length) {
LAB_0054e96c:
      iVar2 = (*(code *)PTR_BN_bn2bin_006a8300)(bn,a->data);
      a->length = iVar2;
      goto joined_r0x0054ea10;
    }
  }
  else {
    if (iVar2 < 0) {
      iVar2 = iVar2 + 7;
    }
    iVar4 = (iVar2 >> 3) + 1;
    if ((iVar2 >> 3) + 4 < a->length) goto LAB_0054e96c;
  }
  puVar3 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a8c44)(a->data,iVar4 + 4,"a_int.c",0x1a9);
  puVar1 = PTR_BN_bn2bin_006a8300;
  if (puVar3 == (uchar *)0x0) {
    ERR_put_error(0xd,0x8b,0x41,"a_int.c",0x1ac);
    if (ai != a) {
      ASN1_STRING_free(a);
    }
    return (ASN1_INTEGER *)0x0;
  }
  a->data = puVar3;
  iVar2 = (*(code *)puVar1)(bn,puVar3);
  a->length = iVar2;
joined_r0x0054ea10:
  if (iVar2 == 0) {
    *a->data = '\0';
    a->length = 1;
    return a;
  }
  return a;
}

