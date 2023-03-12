
ASN1_STRING * ASN1_item_pack(void *obj,ASN1_ITEM *it,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  int reason;
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar2 = ASN1_STRING_new();
    if (pAVar2 != (ASN1_STRING *)0x0) goto LAB_081d1463;
LAB_081d14cb:
    iVar1 = 0x9e;
  }
  else {
    pAVar2 = *oct;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      pAVar2 = ASN1_STRING_new();
      if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_081d14cb;
      *oct = pAVar2;
    }
LAB_081d1463:
    if (pAVar2->data != (uchar *)0x0) {
      CRYPTO_free(pAVar2->data);
      pAVar2->data = (uchar *)0x0;
    }
    iVar1 = ASN1_item_i2d((ASN1_VALUE *)obj,&pAVar2->data,it);
    pAVar2->length = iVar1;
    if (iVar1 == 0) {
      iVar1 = 0xaa;
      reason = 0x70;
      goto LAB_081d14da;
    }
    if (pAVar2->data != (uchar *)0x0) {
      return pAVar2;
    }
    iVar1 = 0xae;
  }
  reason = 0x41;
LAB_081d14da:
  ERR_put_error(0xd,0xc6,reason,"asn_pack.c",iVar1);
  return (ASN1_STRING *)0x0;
}

