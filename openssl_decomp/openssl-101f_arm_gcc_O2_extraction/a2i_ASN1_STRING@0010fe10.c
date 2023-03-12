
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  byte bVar1;
  uchar *puVar2;
  uchar *addr;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  byte *extraout_r1;
  byte *pbVar6;
  uint uVar7;
  byte *extraout_r1_00;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  uchar *puVar12;
  uint uVar13;
  uchar *num;
  byte *pbVar14;
  bool bVar15;
  
  iVar3 = BIO_gets(bp,buf,size);
  if (iVar3 < 1) {
    puVar12 = (uchar *)0x0;
    puVar5 = puVar12;
LAB_0010fffc:
    bs->length = (int)puVar12;
    bs->data = puVar5;
    return 1;
  }
  pbVar14 = (byte *)(buf + iVar3);
  num = (uchar *)0x0;
  bVar1 = pbVar14[-1];
  puVar2 = (uchar *)0x0;
  addr = (uchar *)0x0;
  pbVar6 = extraout_r1;
  do {
    uVar13 = (uint)bVar1;
    if (uVar13 == 10) {
      iVar3 = iVar3 + -1;
      buf[iVar3] = '\0';
      if (iVar3 == 0) {
LAB_0010ffb0:
        ERR_put_error(0xd,0x67,0x96,"f_string.c",0xd0);
        return 0;
      }
      pbVar14 = (byte *)(buf + iVar3);
      uVar13 = (uint)pbVar14[-1];
    }
    if (uVar13 == 0xd) {
      iVar3 = iVar3 + -1;
      buf[iVar3] = '\0';
      if (iVar3 == 0) goto LAB_0010ffb0;
      pbVar14 = (byte *)(buf + iVar3);
      uVar13 = (uint)pbVar14[-1];
    }
    iVar11 = iVar3 + -1;
    bVar15 = iVar11 != 0;
    uVar13 = count_leading_zeroes(uVar13 - 0x5c);
    if (bVar15) {
      pbVar6 = (byte *)(buf + iVar11);
    }
    while (iVar4 = iVar3, pbVar10 = pbVar14, bVar15) {
      if ((9 < *pbVar6 - 0x30) &&
         (iVar4 = iVar11, pbVar10 = pbVar6, 5 < (*pbVar6 & 0xffffffdf) - 0x41)) break;
      iVar11 = iVar11 + -1;
      bVar15 = iVar11 != 0;
      pbVar6 = pbVar6 + -1;
    }
    *pbVar10 = 0;
    if (iVar4 == 1) goto LAB_0010ffb0;
    iVar4 = iVar4 - (uVar13 >> 5);
    if (iVar4 * -0x80000000 < 0) {
      ERR_put_error(0xd,0x67,0x91,"f_string.c",0x9a);
      return 0;
    }
    iVar4 = iVar4 >> 1;
    puVar12 = puVar2 + iVar4;
    puVar5 = addr;
    if ((int)num < (int)puVar12) {
      num = puVar12 + iVar4;
      if (addr == (uchar *)0x0) {
        puVar5 = (uchar *)CRYPTO_malloc((int)num,"f_string.c",0xa2);
      }
      else {
        puVar5 = (uchar *)CRYPTO_realloc(addr,(int)num,"f_string.c",0xa5);
      }
      if (puVar5 == (uchar *)0x0) {
        ERR_put_error(0xd,0x67,0x41,"f_string.c",0xa8);
        if (addr == (uchar *)0x0) {
          return 0;
        }
        CRYPTO_free(addr);
        return 0;
      }
    }
    if (0 < iVar4) {
      pbVar14 = (byte *)buf;
      pbVar6 = puVar2 + (int)puVar5;
LAB_0010ff1a:
      do {
        uVar9 = (uint)*pbVar14;
        uVar7 = uVar9 - 0x30;
        if (9 < uVar7) {
          if (uVar9 - 0x61 < 6) {
            uVar7 = uVar9 - 0x57;
          }
          else {
            if (5 < uVar9 - 0x41) goto LAB_0010ff92;
            uVar7 = uVar9 - 0x37;
          }
        }
        uVar8 = (uVar7 | (uint)*pbVar6 << 4) & 0xff;
        *pbVar6 = (byte)uVar8;
        pbVar10 = pbVar14 + 1;
        uVar9 = (uint)*pbVar10;
        uVar7 = uVar9 - 0x30;
        if (9 < uVar7) {
          if (uVar9 - 0x61 < 6) {
            pbVar14 = pbVar14 + 2;
            *pbVar6 = *pbVar10 + 0xa9 | (byte)(uVar8 << 4);
            pbVar6 = pbVar6 + 1;
            if (pbVar14 == (byte *)(buf + iVar4 * 2)) break;
            goto LAB_0010ff1a;
          }
          if (5 < uVar9 - 0x41) {
LAB_0010ff92:
            ERR_put_error(0xd,0x67,0x8d,"f_string.c",0xbc);
            return 0;
          }
          uVar7 = uVar9 - 0x37;
        }
        pbVar14 = pbVar14 + 2;
        *pbVar6 = (byte)uVar7 | (byte)(uVar8 << 4);
        pbVar6 = pbVar6 + 1;
      } while (pbVar14 != (byte *)(buf + iVar4 * 2));
    }
    if (uVar13 >> 5 == 0) goto LAB_0010fffc;
    iVar3 = BIO_gets(bp,buf,size);
    if (iVar3 < 1) goto LAB_0010ffb0;
    pbVar14 = (byte *)(buf + iVar3);
    bVar1 = pbVar14[-1];
    puVar2 = puVar12;
    addr = puVar5;
    pbVar6 = extraout_r1_00;
  } while( true );
}

