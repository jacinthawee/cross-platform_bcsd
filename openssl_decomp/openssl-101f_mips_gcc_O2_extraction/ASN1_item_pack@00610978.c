
ASN1_STRING * ASN1_item_pack(void *obj,ASN1_ITEM *it,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ASN1_STRING *pAVar4;
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    pAVar4 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (pAVar4 == (ASN1_STRING *)0x0) {
LAB_00610a48:
      uVar3 = 0x41;
      uVar2 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    pAVar4 = *oct;
    if (pAVar4 == (ASN1_STRING *)0x0) {
      pAVar4 = (ASN1_STRING *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (pAVar4 == (ASN1_STRING *)0x0) goto LAB_00610a48;
      *oct = pAVar4;
    }
  }
  if (pAVar4->data != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    pAVar4->data = (uchar *)0x0;
  }
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(obj,&pAVar4->data,it);
  pAVar4->length = iVar1;
  if (iVar1 == 0) {
    uVar3 = 0x70;
    uVar2 = 0xaa;
  }
  else {
    if (pAVar4->data != (uchar *)0x0) {
      return pAVar4;
    }
    uVar3 = 0x41;
    uVar2 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar3,"asn_pack.c",uVar2);
  return (ASN1_STRING *)0x0;
}

