
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  undefined *puVar1;
  uchar *puVar2;
  int iVar3;
  uchar *puVar4;
  uint uVar5;
  long lVar6;
  uchar *puVar7;
  ASN1_OBJECT *pAVar8;
  
  puVar7 = *pp;
  if (0 < length) {
    puVar2 = puVar7;
    do {
      if ((*puVar2 == 0x80) && ((puVar2 == puVar7 || (-1 < (char)puVar2[-1])))) {
        ERR_put_error(0xd,0xc4,0xd8,"a_object.c",300);
        return (ASN1_OBJECT *)0x0;
      }
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar7 + length);
  }
  if (((a == (ASN1_OBJECT **)0x0) || (pAVar8 = *a, pAVar8 == (ASN1_OBJECT *)0x0)) ||
     ((pAVar8->flags & 1U) == 0)) {
    pAVar8 = (ASN1_OBJECT *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x18,"a_object.c",0x15f);
    if (pAVar8 == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x162);
      return (ASN1_OBJECT *)0x0;
    }
    pAVar8->data = (uchar *)0x0;
    pAVar8->sn = (char *)0x0;
    pAVar8->ln = (char **)0x0;
    pAVar8->length = 0;
    pAVar8->nid = 0;
    puVar7 = *pp;
    pAVar8->flags = 1;
LAB_0054b750:
    pAVar8->length = 0;
  }
  else {
    puVar2 = pAVar8->data;
    pAVar8->data = (uchar *)0x0;
    puVar1 = PTR_CRYPTO_free_006a7f88;
    if (puVar2 == (uchar *)0x0) goto LAB_0054b750;
    if (length <= pAVar8->length) {
      puVar4 = (uchar *)(*(code *)PTR_memcpy_006aabf4)(puVar2,puVar7,length);
      puVar2 = puVar7 + length;
      pAVar8->data = puVar4;
      pAVar8->length = length;
      pAVar8->sn = (char *)0x0;
      pAVar8->ln = (char **)0x0;
      *a = pAVar8;
      goto LAB_0054b7b4;
    }
    pAVar8->length = 0;
    (*(code *)puVar1)(puVar2);
  }
  lVar6 = 1;
  if (length != 0) {
    lVar6 = length;
  }
  iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(lVar6,"a_object.c",0x143);
  puVar1 = PTR_memcpy_006aabf4;
  if (iVar3 == 0) {
    ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x155);
    if ((a != (ASN1_OBJECT **)0x0) && (pAVar8 == *a)) {
      return (ASN1_OBJECT *)0x0;
    }
    uVar5 = pAVar8->flags;
    if ((uVar5 & 4) != 0) {
      if (pAVar8->sn != (char *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      if (pAVar8->ln != (char **)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      uVar5 = pAVar8->flags;
      pAVar8->ln = (char **)0x0;
      pAVar8->sn = (char *)0x0;
    }
    if ((uVar5 & 8) != 0) {
      if (pAVar8->data != (uchar *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        uVar5 = pAVar8->flags;
      }
      pAVar8->data = (uchar *)0x0;
      pAVar8->length = 0;
    }
    if ((uVar5 & 1) == 0) {
      return (ASN1_OBJECT *)0x0;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(pAVar8);
    return (ASN1_OBJECT *)0x0;
  }
  puVar2 = puVar7 + length;
  pAVar8->flags = pAVar8->flags | 8;
  puVar7 = (uchar *)(*(code *)puVar1)(iVar3,puVar7,length);
  pAVar8->data = puVar7;
  pAVar8->length = length;
  pAVar8->sn = (char *)0x0;
  pAVar8->ln = (char **)0x0;
  if (a != (ASN1_OBJECT **)0x0) {
    *a = pAVar8;
  }
LAB_0054b7b4:
  *pp = puVar2;
  return pAVar8;
}

