
ASN1_INTEGER * c2i_ASN1_INTEGER(ASN1_INTEGER **a,uchar **pp,long length)

{
  undefined *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  uchar *puVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  ASN1_STRING *a_00;
  byte *pbVar9;
  byte *pbVar10;
  long lVar11;
  int iVar12;
  
  if ((a == (ASN1_INTEGER **)0x0) || (a_00 = *a, a_00 == (ASN1_INTEGER *)0x0)) {
    a_00 = ASN1_STRING_type_new(2);
    puVar1 = PTR_CRYPTO_malloc_006a7008;
    if (a_00 == (ASN1_STRING *)0x0) {
      return (ASN1_INTEGER *)0x0;
    }
    pbVar9 = *pp;
    a_00->type = 2;
    puVar2 = (uchar *)(*(code *)puVar1)(length + 1,"a_int.c",0xd0);
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(0xd,0xc2,0x41,"a_int.c",0x10d);
      if (a == (ASN1_INTEGER **)0x0) goto LAB_0054b034;
      goto LAB_0054b028;
    }
  }
  else {
    pbVar9 = *pp;
    puVar2 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(length + 1,"a_int.c",0xd0);
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(0xd,0xc2,0x41,"a_int.c",0x10d);
LAB_0054b028:
      if (*a == a_00) {
        return (ASN1_INTEGER *)0x0;
      }
LAB_0054b034:
      ASN1_STRING_free(a_00);
      return (ASN1_INTEGER *)0x0;
    }
  }
  pbVar10 = pbVar9 + length;
  if (length == 0) {
    a_00->type = 2;
  }
  else if ((char)*pbVar9 < '\0') {
    a_00->type = 0x102;
    bVar6 = *pbVar9;
    if (bVar6 == 0xff) {
      puVar5 = puVar2;
      iVar4 = 1;
      if (length != 1) {
        iVar4 = length + -1;
        pbVar9 = pbVar9 + iVar4;
        bVar6 = *pbVar9;
        puVar3 = puVar2 + length + -2;
        iVar12 = iVar4;
        length = iVar4;
        puVar5 = puVar3;
        if (bVar6 == 0) goto joined_r0x0054b0fc;
LAB_0054b094:
        puVar5 = puVar3;
        length = iVar12;
        if (iVar4 == 0) goto LAB_0054b104;
      }
    }
    else {
      pbVar9 = pbVar9 + length + -1;
      bVar6 = *pbVar9;
      puVar5 = puVar2 + length + -1;
      iVar4 = length;
      iVar12 = length;
      if (bVar6 == 0) {
        do {
          puVar3 = puVar5 + -1;
          *puVar5 = '\0';
          pbVar9 = pbVar9 + -1;
          bVar6 = *pbVar9;
          iVar4 = length + -1;
          length = iVar4;
          puVar5 = puVar3;
          if (bVar6 != 0) goto LAB_0054b094;
joined_r0x0054b0fc:
        } while (length != 0);
LAB_0054b104:
        length = iVar12 + 1;
        *puVar2 = '\x01';
        puVar2[iVar12] = '\0';
        goto LAB_0054aee0;
      }
    }
    *puVar5 = -bVar6;
    if (1 < iVar4) {
      pbVar7 = puVar5 + -1;
      do {
        pbVar9 = pbVar9 + -1;
        pbVar8 = pbVar7 + -1;
        *pbVar7 = ~*pbVar9;
        pbVar7 = pbVar8;
      } while (pbVar8 != puVar5 + -iVar4);
      puVar5 = a_00->data;
      goto LAB_0054aee4;
    }
  }
  else {
    a_00->type = 2;
    lVar11 = length;
    if (*pbVar9 == 0) {
      if (length == 1) {
        lVar11 = 1;
      }
      else {
        lVar11 = length + -1;
        pbVar9 = pbVar9 + 1;
        length = lVar11;
      }
    }
    (*(code *)PTR_memcpy_006a9aec)(puVar2,pbVar9,lVar11);
  }
LAB_0054aee0:
  puVar5 = a_00->data;
LAB_0054aee4:
  if (puVar5 != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  a_00->data = puVar2;
  a_00->length = length;
  if (a != (ASN1_INTEGER **)0x0) {
    *a = a_00;
  }
  *pp = pbVar10;
  return a_00;
}

