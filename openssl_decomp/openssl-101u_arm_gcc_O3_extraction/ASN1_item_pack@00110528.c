
ASN1_STRING * ASN1_item_pack(void *obj,ASN1_ITEM *it,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  ASN1_STRING *pAVar2;
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar2 = ASN1_STRING_new();
    if (pAVar2 == (ASN1_STRING *)0x0) {
LAB_00110588:
      iVar1 = 0xac;
      goto LAB_0011058e;
    }
  }
  else {
    pAVar2 = *oct;
    if (pAVar2 == (ASN1_STRING *)0x0) {
      pAVar2 = ASN1_STRING_new();
      if (pAVar2 == (ASN1_STRING *)0x0) goto LAB_00110588;
      *oct = pAVar2;
    }
  }
  if (pAVar2->data != (uchar *)0x0) {
    CRYPTO_free(pAVar2->data);
    pAVar2->data = (uchar *)0x0;
  }
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)obj,&pAVar2->data,it);
  pAVar2->length = iVar1;
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xc6,0x70,"asn_pack.c",0xba);
    return (ASN1_STRING *)0x0;
  }
  iVar1 = 0xbe;
  if (pAVar2->data != (uchar *)0x0) {
    return pAVar2;
  }
LAB_0011058e:
  ERR_put_error(0xd,0xc6,0x41,"asn_pack.c",iVar1);
  return (ASN1_STRING *)0x0;
}

