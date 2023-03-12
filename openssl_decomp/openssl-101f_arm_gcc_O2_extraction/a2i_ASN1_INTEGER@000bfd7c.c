
int a2i_ASN1_INTEGER(BIO *bp,ASN1_INTEGER *bs,char *buf,int size)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  uchar *addr;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int old_num;
  byte *pbVar14;
  byte *pbVar15;
  
  bs->type = 2;
  iVar5 = BIO_gets(bp,buf,size);
  if (0 < iVar5) {
    pbVar15 = (byte *)(buf + iVar5);
    old_num = 0;
    bVar2 = pbVar15[-1];
    bVar3 = true;
    iVar4 = 0;
    addr = (uchar *)0x0;
    do {
      uVar13 = (uint)bVar2;
      if (uVar13 == 10) {
        iVar5 = iVar5 + -1;
        buf[iVar5] = '\0';
        if (iVar5 == 0) break;
        pbVar15 = (byte *)(buf + iVar5);
        uVar13 = (uint)pbVar15[-1];
      }
      if (uVar13 == 0xd) {
        iVar5 = iVar5 + -1;
        buf[iVar5] = '\0';
        if (iVar5 == 0) break;
        pbVar15 = (byte *)(buf + iVar5);
        uVar13 = (uint)pbVar15[-1];
      }
      uVar13 = count_leading_zeroes(uVar13 - 0x5c);
      iVar12 = 0;
      pbVar8 = (byte *)buf;
      do {
        if ((9 < *pbVar8 - 0x30) &&
           (iVar6 = iVar12, pbVar14 = pbVar8, 5 < (*pbVar8 & 0xffffffdf) - 0x41)) break;
        iVar12 = iVar12 + 1;
        iVar6 = iVar5;
        pbVar8 = pbVar8 + 1;
        pbVar14 = pbVar15;
      } while (iVar12 < iVar5);
      *pbVar14 = 0;
      if (iVar6 < 2) break;
      pbVar15 = (byte *)buf;
      if (((bVar3) && (*buf == '0')) && (buf[1] == '0')) {
        iVar6 = iVar6 + -2;
        pbVar15 = (byte *)(buf + 2);
      }
      iVar6 = iVar6 - (uVar13 >> 5);
      if (iVar6 * -0x80000000 < 0) {
        ERR_put_error(0xd,0x66,0x91,"f_int.c",0xa2);
        return 0;
      }
      iVar6 = iVar6 >> 1;
      iVar12 = iVar4 + iVar6;
      puVar7 = addr;
      if (old_num < iVar12) {
        if (addr == (uchar *)0x0) {
          puVar7 = (uchar *)CRYPTO_malloc(iVar12 + iVar6,"f_int.c",0xaa);
        }
        else {
          puVar7 = (uchar *)CRYPTO_realloc_clean(addr,old_num,iVar12 + iVar6,"f_int.c",0xac);
        }
        old_num = iVar12 + iVar6;
        if (puVar7 == (uchar *)0x0) {
          ERR_put_error(0xd,0x66,0x41,"f_int.c",0xaf);
          if (addr == (uchar *)0x0) {
            return 0;
          }
          CRYPTO_free(addr);
          return 0;
        }
      }
      pbVar14 = pbVar15 + iVar6 * 2;
      pbVar8 = puVar7 + iVar4;
      if (iVar6 != 0) {
LAB_000bfe9c:
        do {
          uVar11 = (uint)*pbVar15;
          uVar9 = uVar11 - 0x30;
          if (9 < uVar9) {
            if (uVar11 - 0x61 < 6) {
              uVar9 = uVar11 - 0x57;
            }
            else {
              if (5 < uVar11 - 0x41) goto LAB_000bff1c;
              uVar9 = uVar11 - 0x37;
            }
          }
          uVar10 = (uVar9 | (uint)*pbVar8 << 4) & 0xff;
          *pbVar8 = (byte)uVar10;
          pbVar1 = pbVar15 + 1;
          uVar11 = (uint)*pbVar1;
          uVar9 = uVar11 - 0x30;
          if (9 < uVar9) {
            if (uVar11 - 0x61 < 6) {
              pbVar15 = pbVar15 + 2;
              *pbVar8 = *pbVar1 + 0xa9 | (byte)(uVar10 << 4);
              pbVar8 = pbVar8 + 1;
              if (pbVar15 == pbVar14) break;
              goto LAB_000bfe9c;
            }
            if (5 < uVar11 - 0x41) {
LAB_000bff1c:
              ERR_put_error(0xd,0x66,0x8d,"f_int.c",0xc3);
              return 0;
            }
            uVar9 = uVar11 - 0x37;
          }
          pbVar15 = pbVar15 + 2;
          *pbVar8 = (byte)uVar9 | (byte)(uVar10 << 4);
          pbVar8 = pbVar8 + 1;
        } while (pbVar15 != pbVar14);
      }
      if (uVar13 >> 5 == 0) {
        bs->length = iVar12;
        bs->data = puVar7;
        return 1;
      }
      iVar5 = BIO_gets(bp,buf,size);
      if (iVar5 < 1) break;
      pbVar15 = (byte *)(buf + iVar5);
      bVar3 = false;
      bVar2 = pbVar15[-1];
      iVar4 = iVar12;
      addr = puVar7;
    } while( true );
  }
  ERR_put_error(0xd,0x66,0x96,"f_int.c",0xd7);
  return 0;
}

