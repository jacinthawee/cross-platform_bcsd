
ASN1_STRING * ASN1_item_pack(void *obj,ASN1_ITEM *it,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ASN1_STRING *pAVar4;
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar4 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (pAVar4 == (ASN1_STRING *)0x0) {
LAB_0060f874:
      uVar3 = 0x41;
      uVar2 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    pAVar4 = *oct;
    if (pAVar4 == (ASN1_STRING *)0x0) {
      pAVar4 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_0060f874;
      *oct = pAVar4;
    }
  }
  if (pAVar4->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    pAVar4->data = (uchar *)0x0;
  }
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(obj,&pAVar4->data,it);
  pAVar4->length = iVar1;
  if (iVar1 == 0) {
    uVar3 = 0x70;
    uVar2 = 0xba;
  }
  else {
    if (pAVar4->data != (uchar *)0x0) {
      return pAVar4;
    }
    uVar3 = 0x41;
    uVar2 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar3,"asn_pack.c",uVar2);
  return (ASN1_STRING *)0x0;
}

