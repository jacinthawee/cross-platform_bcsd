
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uchar *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  byte bVar13;
  int iVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  int iVar18;
  uchar *puVar19;
  
  bs->type = 2;
  iVar3 = (*(code *)PTR_BIO_gets_006a85d0)(bp,buf,size);
  if (0 < iVar3) {
    bVar2 = true;
    iVar18 = 0;
    iVar14 = 0;
    puVar19 = (uchar *)0x0;
    do {
      pbVar17 = (byte *)(buf + iVar3);
      bVar13 = pbVar17[-1];
      if (bVar13 == 10) {
        iVar3 = iVar3 + -1;
        pbVar17 = (byte *)(buf + iVar3);
        *pbVar17 = 0;
        if (iVar3 == 0) break;
        bVar13 = pbVar17[-1];
      }
      if (bVar13 == 0xd) {
        iVar3 = iVar3 + -1;
        pbVar17 = (byte *)(buf + iVar3);
        *pbVar17 = 0;
        if (iVar3 == 0) break;
        bVar13 = pbVar17[-1];
      }
      pbVar9 = (byte *)buf;
      iVar10 = 0;
      do {
        iVar6 = iVar10;
        if ((9 < *pbVar9 - 0x30) && (pbVar15 = pbVar9, 5 < (*pbVar9 & 0xffffffdf) - 0x41)) break;
        iVar10 = iVar6 + 1;
        iVar6 = iVar3;
        pbVar9 = pbVar9 + 1;
        pbVar15 = pbVar17;
      } while (iVar10 < iVar3);
      *pbVar15 = 0;
      if (iVar6 < 2) break;
      pbVar17 = (byte *)buf;
      if (((bVar2) && (*buf == '0')) && (buf[1] == '0')) {
        iVar6 = iVar6 + -2;
        pbVar17 = (byte *)(buf + 2);
      }
      uVar4 = iVar6 - (uint)(bVar13 == 0x5c);
      iVar3 = (int)uVar4 >> 1;
      if ((uVar4 & 1) != 0) {
        uVar12 = 0x91;
        uVar7 = 0xa2;
        goto LAB_00567588;
      }
      iVar10 = iVar14 + iVar3;
      puVar5 = puVar19;
      if (iVar18 < iVar10) {
        if (puVar19 == (uchar *)0x0) {
          puVar5 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)
                                      (iVar3 + iVar10,s_f_int_c_0066ad94,0xaa);
        }
        else {
          puVar5 = (uchar *)(*(code *)PTR_CRYPTO_realloc_clean_006a9a00)
                                      (puVar19,iVar18,iVar3 + iVar10,s_f_int_c_0066ad94,0xac);
        }
        iVar18 = iVar3 + iVar10;
        if (puVar5 == (uchar *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x66,0x41,s_f_int_c_0066ad94,0xaf);
          if (puVar19 != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)(puVar19);
            return 0;
          }
          return 0;
        }
      }
      if (iVar3 != 0) {
        pbVar9 = puVar5 + iVar14;
LAB_005674cc:
        do {
          uVar8 = (uint)*pbVar17;
          uVar4 = uVar8 - 0x30;
          if (9 < uVar4) {
            uVar4 = uVar8 - 0x57;
            if (uVar8 - 0x61 < 6) {
              bVar1 = *pbVar9;
              goto LAB_00567470;
            }
            uVar4 = uVar8 - 0x37;
            if (uVar8 - 0x41 < 6) goto LAB_0056746c;
LAB_00567574:
            uVar12 = 0x8d;
            uVar7 = 0xc3;
            goto LAB_00567588;
          }
LAB_0056746c:
          bVar1 = *pbVar9;
LAB_00567470:
          uVar4 = ((uint)bVar1 << 4 | uVar4) & 0xff;
          *pbVar9 = (byte)uVar4;
          pbVar15 = pbVar17 + 1;
          uVar11 = (uint)*pbVar15;
          uVar8 = uVar11 - 0x30;
          if (uVar8 < 10) {
LAB_005674b4:
            pbVar15 = pbVar9 + 1;
            pbVar17 = pbVar17 + 2;
            *pbVar9 = (byte)(uVar4 << 4) | (byte)uVar8;
            pbVar9 = pbVar15;
            if (pbVar15 == puVar5 + iVar10) break;
            goto LAB_005674cc;
          }
          if (5 < uVar11 - 0x61) {
            uVar8 = uVar11 - 0x37;
            if (5 < uVar11 - 0x41) goto LAB_00567574;
            goto LAB_005674b4;
          }
          pbVar16 = pbVar9 + 1;
          pbVar17 = pbVar17 + 2;
          *pbVar9 = (byte)(uVar4 << 4) | *pbVar15 + 0xa9;
          pbVar9 = pbVar16;
        } while (pbVar16 != puVar5 + iVar10);
      }
      if (bVar13 != 0x5c) {
        bs->length = iVar10;
        bs->data = puVar5;
        return 1;
      }
      iVar3 = (*(code *)PTR_BIO_gets_006a85d0)(bp,buf,size);
      bVar2 = false;
      iVar14 = iVar10;
      puVar19 = puVar5;
    } while (0 < iVar3);
  }
  uVar12 = 0x96;
  uVar7 = 0xd7;
LAB_00567588:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x66,uVar12,s_f_int_c_0066ad94,uVar7);
  return 0;
}

