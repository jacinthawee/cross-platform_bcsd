
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  undefined *puVar1;
  uchar *puVar2;
  uint uVar3;
  int iVar4;
  uchar *puVar5;
  ASN1_OBJECT *pAVar6;
  uchar *puVar7;
  
  if ((length < 1) || (pp == (uchar **)0x0)) {
LAB_005486b0:
    iVar4 = 0x11f;
LAB_00548434:
    ERR_put_error(0xd,0xc4,0xd8,"a_object.c",iVar4);
    return (ASN1_OBJECT *)0x0;
  }
  puVar7 = *pp;
  puVar5 = puVar7 + length;
  if ((puVar7 == (uchar *)0x0) || (puVar2 = puVar7, (char)puVar5[-1] < '\0')) goto LAB_005486b0;
  do {
    if ((*puVar2 == 0x80) && ((puVar2 == puVar7 || (-1 < (char)puVar2[-1])))) {
      iVar4 = 0x126;
      goto LAB_00548434;
    }
    puVar2 = puVar2 + 1;
  } while (puVar5 != puVar2);
  if (((a == (ASN1_OBJECT **)0x0) || (pAVar6 = *a, pAVar6 == (ASN1_OBJECT *)0x0)) ||
     ((pAVar6->flags & 1U) == 0)) {
    pAVar6 = (ASN1_OBJECT *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x18,"a_object.c",0x15e);
    if (pAVar6 == (ASN1_OBJECT *)0x0) {
      ERR_put_error(0xd,0x7b,0x41,"a_object.c",0x160);
      return (ASN1_OBJECT *)0x0;
    }
    pAVar6->data = (uchar *)0x0;
    pAVar6->sn = (char *)0x0;
    pAVar6->ln = (char **)0x0;
    pAVar6->length = 0;
    pAVar6->nid = 0;
    puVar7 = *pp;
    pAVar6->flags = 1;
LAB_0054858c:
    puVar1 = PTR_CRYPTO_malloc_006a7008;
    pAVar6->length = 0;
    iVar4 = (*(code *)puVar1)(length,"a_object.c",0x13f);
    puVar5 = puVar7 + length;
    if (iVar4 == 0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
      if (a == (ASN1_OBJECT **)0x0) goto LAB_005485e8;
LAB_005485dc:
      if (*a == pAVar6) {
        return (ASN1_OBJECT *)0x0;
      }
LAB_005485e8:
      uVar3 = pAVar6->flags;
      if ((uVar3 & 4) != 0) {
        if (pAVar6->sn != (char *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        if (pAVar6->ln != (char **)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
        }
        uVar3 = pAVar6->flags;
        pAVar6->ln = (char **)0x0;
        pAVar6->sn = (char *)0x0;
      }
      if ((uVar3 & 8) != 0) {
        if (pAVar6->data != (uchar *)0x0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          uVar3 = pAVar6->flags;
        }
        pAVar6->data = (uchar *)0x0;
        pAVar6->length = 0;
      }
      if ((uVar3 & 1) == 0) {
        return (ASN1_OBJECT *)0x0;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(pAVar6);
      return (ASN1_OBJECT *)0x0;
    }
  }
  else {
    puVar2 = pAVar6->data;
    pAVar6->data = (uchar *)0x0;
    puVar1 = PTR_CRYPTO_free_006a6e88;
    if (puVar2 == (uchar *)0x0) goto LAB_0054858c;
    if (length <= pAVar6->length) {
      puVar7 = (uchar *)(*(code *)PTR_memcpy_006a9aec)(puVar2,puVar7,length);
      pAVar6->data = puVar7;
      pAVar6->length = length;
      pAVar6->sn = (char *)0x0;
      pAVar6->ln = (char **)0x0;
      *a = pAVar6;
      goto LAB_0054851c;
    }
    pAVar6->length = 0;
    (*(code *)puVar1)(puVar2);
    iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(length,"a_object.c",0x13f);
    if (iVar4 == 0) {
      ERR_put_error(0xd,0xc4,0x41,"a_object.c",0x154);
      goto LAB_005485dc;
    }
  }
  puVar1 = PTR_memcpy_006a9aec;
  pAVar6->flags = pAVar6->flags | 8;
  puVar7 = (uchar *)(*(code *)puVar1)(iVar4,puVar7,length);
  pAVar6->data = puVar7;
  pAVar6->length = length;
  pAVar6->sn = (char *)0x0;
  pAVar6->ln = (char **)0x0;
  if (a != (ASN1_OBJECT **)0x0) {
    *a = pAVar6;
  }
LAB_0054851c:
  *pp = puVar5;
  return pAVar6;
}

