
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  int iVar16;
  uchar *puVar17;
  byte bVar18;
  
  iVar2 = (*(code *)PTR_BIO_gets_006a85d0)(bp,buf,size);
  if (iVar2 < 1) {
    iVar8 = 0;
    puVar4 = (uchar *)0x0;
LAB_0060c910:
    bs->length = iVar8;
    iVar2 = 1;
    bs->data = puVar4;
  }
  else {
    iVar16 = 0;
    iVar11 = 0;
    puVar17 = (uchar *)0x0;
    do {
      pbVar15 = (byte *)(buf + iVar2);
      bVar18 = pbVar15[-1];
      if (bVar18 == 10) {
        iVar2 = iVar2 + -1;
        pbVar15 = (byte *)(buf + iVar2);
        *pbVar15 = 0;
        if (iVar2 == 0) break;
        bVar18 = pbVar15[-1];
      }
      if (bVar18 == 0xd) {
        iVar2 = iVar2 + -1;
        pbVar15 = (byte *)(buf + iVar2);
        *pbVar15 = 0;
        if (iVar2 == 0) break;
        bVar18 = pbVar15[-1];
      }
      iVar8 = iVar2 + -1;
      pbVar13 = (byte *)(buf + iVar8);
      for (; iVar3 = iVar2, pbVar12 = pbVar15, iVar8 != 0; iVar8 = iVar8 + -1) {
        if ((9 < *pbVar13 - 0x30) &&
           (iVar3 = iVar8, pbVar12 = pbVar13, 5 < (*pbVar13 & 0xffffffdf) - 0x41)) break;
        pbVar13 = pbVar13 + -1;
      }
      *pbVar12 = 0;
      if (iVar3 == 1) break;
      uVar6 = iVar3 - (uint)(bVar18 == 0x5c);
      iVar2 = (int)uVar6 >> 1;
      if ((uVar6 & 1) != 0) {
        uVar10 = 0x91;
        uVar5 = 0x9a;
        goto LAB_0060c850;
      }
      iVar8 = iVar11 + iVar2;
      puVar4 = puVar17;
      if (iVar16 < iVar8) {
        if (puVar17 == (uchar *)0x0) {
          puVar4 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2 + iVar8,"f_string.c",0xa2);
        }
        else {
          puVar4 = (uchar *)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                      (puVar17,iVar2 + iVar8,"f_string.c",0xa5);
        }
        iVar16 = iVar2 + iVar8;
        if (puVar4 == (uchar *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,0x41,"f_string.c",0xa8);
          if (puVar17 != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar17);
            return 0;
          }
          return 0;
        }
      }
      if (iVar2 != 0) {
        pbVar15 = (byte *)buf;
        pbVar13 = puVar4 + iVar11;
LAB_0060c798:
        do {
          uVar7 = (uint)*pbVar15;
          uVar6 = uVar7 - 0x30;
          if (9 < uVar6) {
            uVar6 = uVar7 - 0x57;
            if (uVar7 - 0x61 < 6) {
              bVar1 = *pbVar13;
              goto LAB_0060c73c;
            }
            uVar6 = uVar7 - 0x37;
            if (uVar7 - 0x41 < 6) goto LAB_0060c738;
LAB_0060c83c:
            uVar10 = 0x8d;
            uVar5 = 0xbc;
            goto LAB_0060c850;
          }
LAB_0060c738:
          bVar1 = *pbVar13;
LAB_0060c73c:
          uVar6 = ((uint)bVar1 << 4 | uVar6) & 0xff;
          *pbVar13 = (byte)uVar6;
          pbVar12 = pbVar15 + 1;
          uVar9 = (uint)*pbVar12;
          uVar7 = uVar9 - 0x30;
          if (9 < uVar7) {
            if (uVar9 - 0x61 < 6) {
              pbVar14 = pbVar13 + 1;
              pbVar15 = pbVar15 + 2;
              *pbVar13 = (byte)(uVar6 << 4) | *pbVar12 + 0xa9;
              pbVar13 = pbVar14;
              if (pbVar14 == puVar4 + iVar8) break;
              goto LAB_0060c798;
            }
            uVar7 = uVar9 - 0x37;
            if (5 < uVar9 - 0x41) goto LAB_0060c83c;
          }
          pbVar12 = pbVar13 + 1;
          pbVar15 = pbVar15 + 2;
          *pbVar13 = (byte)(uVar6 << 4) | (byte)uVar7;
          pbVar13 = pbVar12;
        } while (pbVar12 != puVar4 + iVar8);
      }
      if (bVar18 != 0x5c) goto LAB_0060c910;
      iVar2 = (*(code *)PTR_BIO_gets_006a85d0)(bp,buf,size);
      iVar11 = iVar8;
      puVar17 = puVar4;
    } while (0 < iVar2);
    uVar10 = 0x96;
    uVar5 = 0xd0;
LAB_0060c850:
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x67,uVar10,"f_string.c",uVar5);
    iVar2 = 0;
  }
  return iVar2;
}

