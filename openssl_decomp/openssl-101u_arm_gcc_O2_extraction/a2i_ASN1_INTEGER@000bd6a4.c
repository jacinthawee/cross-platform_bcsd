
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uchar *puVar14;
  int old_num;
  byte *pbVar15;
  byte *pbVar16;
  
  bs->type = 2;
  iVar5 = BIO_gets(bp,buf,size);
  if (0 < iVar5) {
    pbVar16 = (byte *)(buf + iVar5);
    old_num = 0;
    bVar2 = pbVar16[-1];
    bVar3 = true;
    iVar4 = 0;
    puVar14 = (uchar *)0x0;
    do {
      uVar13 = (uint)bVar2;
      if (uVar13 == 10) {
        iVar5 = iVar5 + -1;
        buf[iVar5] = '\0';
        if (iVar5 == 0) goto LAB_000bd880;
        pbVar16 = (byte *)(buf + iVar5);
        uVar13 = (uint)pbVar16[-1];
      }
      if (uVar13 == 0xd) {
        iVar5 = iVar5 + -1;
        buf[iVar5] = '\0';
        if (iVar5 == 0) goto LAB_000bd880;
        pbVar16 = (byte *)(buf + iVar5);
        uVar13 = (uint)pbVar16[-1];
      }
      uVar13 = count_leading_zeroes(uVar13 - 0x5c);
      iVar12 = 0;
      pbVar8 = (byte *)buf;
      do {
        if ((9 < *pbVar8 - 0x30) &&
           (iVar6 = iVar12, pbVar15 = pbVar8, 5 < (*pbVar8 & 0xffffffdf) - 0x41)) break;
        iVar12 = iVar12 + 1;
        iVar6 = iVar5;
        pbVar8 = pbVar8 + 1;
        pbVar15 = pbVar16;
      } while (iVar12 < iVar5);
      *pbVar15 = 0;
      if (iVar6 < 2) goto LAB_000bd880;
      pbVar16 = (byte *)buf;
      if (((bVar3) && (*buf == '0')) && (buf[1] == '0')) {
        iVar6 = iVar6 + -2;
        pbVar16 = (byte *)(buf + 2);
      }
      iVar6 = iVar6 - (uVar13 >> 5);
      if (iVar6 * -0x80000000 < 0) {
        ERR_put_error(0xd,0x66,0x91,"f_int.c",0xa3);
        goto LAB_000bd85e;
      }
      iVar6 = iVar6 >> 1;
      iVar12 = iVar4 + iVar6;
      puVar7 = puVar14;
      if (old_num < iVar12) {
        if (puVar14 == (uchar *)0x0) {
          puVar7 = (uchar *)CRYPTO_malloc(iVar12 + iVar6,"f_int.c",0xaa);
        }
        else {
          puVar7 = (uchar *)CRYPTO_realloc_clean(puVar14,old_num,iVar12 + iVar6,"f_int.c",0xac);
        }
        old_num = iVar12 + iVar6;
        if (puVar7 == (uchar *)0x0) {
          ERR_put_error(0xd,0x66,0x41,"f_int.c",0xae);
          goto LAB_000bd85e;
        }
      }
      puVar14 = puVar7;
      if (iVar6 != 0) {
        pbVar15 = pbVar16 + iVar6 * 2;
        pbVar8 = puVar7 + iVar4;
LAB_000bd7cc:
        do {
          uVar11 = (uint)*pbVar16;
          uVar9 = uVar11 - 0x30;
          if (9 < uVar9) {
            if (uVar11 - 0x61 < 6) {
              uVar9 = uVar11 - 0x57;
              goto LAB_000bd792;
            }
            if (uVar11 - 0x41 < 6) {
              uVar9 = uVar11 - 0x37;
              goto LAB_000bd792;
            }
LAB_000bd848:
            ERR_put_error(0xd,0x66,0x8d,"f_int.c",0xbf);
            goto LAB_000bd85e;
          }
LAB_000bd792:
          uVar10 = (uVar9 | (uint)*pbVar8 << 4) & 0xff;
          *pbVar8 = (byte)uVar10;
          pbVar1 = pbVar16 + 1;
          uVar11 = (uint)*pbVar1;
          uVar9 = uVar11 - 0x30;
          if (9 < uVar9) {
            if (uVar11 - 0x61 < 6) {
              pbVar16 = pbVar16 + 2;
              *pbVar8 = *pbVar1 + 0xa9 | (byte)(uVar10 << 4);
              pbVar8 = pbVar8 + 1;
              if (pbVar16 == pbVar15) break;
              goto LAB_000bd7cc;
            }
            if (5 < uVar11 - 0x41) goto LAB_000bd848;
            uVar9 = uVar11 - 0x37;
          }
          pbVar16 = pbVar16 + 2;
          *pbVar8 = (byte)uVar9 | (byte)(uVar10 << 4);
          pbVar8 = pbVar8 + 1;
        } while (pbVar16 != pbVar15);
      }
      if (uVar13 >> 5 == 0) {
        bs->length = iVar12;
        bs->data = puVar7;
        return 1;
      }
      iVar5 = BIO_gets(bp,buf,size);
      if (iVar5 < 1) goto LAB_000bd880;
      pbVar16 = (byte *)(buf + iVar5);
      bVar3 = false;
      bVar2 = pbVar16[-1];
      iVar4 = iVar12;
    } while( true );
  }
  puVar14 = (uchar *)0x0;
LAB_000bd880:
  ERR_put_error(0xd,0x66,0x96,"f_int.c",0xd2);
LAB_000bd85e:
  CRYPTO_free(puVar14);
  return 0;
}

