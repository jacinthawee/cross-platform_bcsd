
int a2i_ASN1_STRING(BIO *bp,ASN1_STRING *bs,char *buf,int size)

{
  byte bVar1;
  int iVar2;
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
  uint uVar12;
  uchar *puVar13;
  int num;
  byte *pbVar14;
  bool bVar15;
  
  iVar3 = BIO_gets(bp,buf,size);
  if (iVar3 < 1) {
    iVar11 = 0;
    puVar5 = (uchar *)0x0;
LAB_0010e30c:
    bs->length = iVar11;
    bs->data = puVar5;
    return 1;
  }
  pbVar14 = (byte *)(buf + iVar3);
  num = 0;
  bVar1 = pbVar14[-1];
  iVar2 = 0;
  puVar13 = (uchar *)0x0;
  pbVar6 = extraout_r1;
  do {
    uVar12 = (uint)bVar1;
    if (uVar12 == 10) {
      iVar3 = iVar3 + -1;
      buf[iVar3] = '\0';
      if (iVar3 == 0) {
LAB_0010e2d6:
        ERR_put_error(0xd,0x67,0x96,"f_string.c",0xcc);
LAB_0010e2c8:
        CRYPTO_free(puVar13);
        return 0;
      }
      pbVar14 = (byte *)(buf + iVar3);
      uVar12 = (uint)pbVar14[-1];
    }
    if (uVar12 == 0xd) {
      iVar3 = iVar3 + -1;
      buf[iVar3] = '\0';
      if (iVar3 == 0) goto LAB_0010e2d6;
      pbVar14 = (byte *)(buf + iVar3);
      uVar12 = (uint)pbVar14[-1];
    }
    iVar11 = iVar3 + -1;
    bVar15 = iVar11 != 0;
    uVar12 = count_leading_zeroes(uVar12 - 0x5c);
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
    if (iVar4 == 1) goto LAB_0010e2d6;
    iVar4 = iVar4 - (uVar12 >> 5);
    if (iVar4 * -0x80000000 < 0) {
      ERR_put_error(0xd,0x67,0x91,"f_string.c",0x9b);
      goto LAB_0010e2c8;
    }
    iVar4 = iVar4 >> 1;
    iVar11 = iVar2 + iVar4;
    puVar5 = puVar13;
    if (num < iVar11) {
      num = iVar11 + iVar4;
      if (puVar13 == (uchar *)0x0) {
        puVar5 = (uchar *)CRYPTO_malloc(num,"f_string.c",0xa2);
      }
      else {
        puVar5 = (uchar *)CRYPTO_realloc(puVar13,num,"f_string.c",0xa6);
      }
      if (puVar5 == (uchar *)0x0) {
        ERR_put_error(0xd,0x67,0x41,"f_string.c",0xa8);
        goto LAB_0010e2c8;
      }
    }
    puVar13 = puVar5;
    if (0 < iVar4) {
      pbVar14 = (byte *)buf;
      pbVar6 = puVar5 + iVar2;
LAB_0010e23a:
      do {
        uVar9 = (uint)*pbVar14;
        uVar7 = uVar9 - 0x30;
        if (9 < uVar7) {
          if (uVar9 - 0x61 < 6) {
            uVar7 = uVar9 - 0x57;
            goto LAB_0010e200;
          }
          if (uVar9 - 0x41 < 6) {
            uVar7 = uVar9 - 0x37;
            goto LAB_0010e200;
          }
LAB_0010e2b2:
          ERR_put_error(0xd,0x67,0x8d,"f_string.c",0xb9);
          goto LAB_0010e2c8;
        }
LAB_0010e200:
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
            goto LAB_0010e23a;
          }
          if (5 < uVar9 - 0x41) goto LAB_0010e2b2;
          uVar7 = uVar9 - 0x37;
        }
        pbVar14 = pbVar14 + 2;
        *pbVar6 = (byte)uVar7 | (byte)(uVar8 << 4);
        pbVar6 = pbVar6 + 1;
      } while (pbVar14 != (byte *)(buf + iVar4 * 2));
    }
    if (uVar12 >> 5 == 0) goto LAB_0010e30c;
    iVar3 = BIO_gets(bp,buf,size);
    if (iVar3 < 1) goto LAB_0010e2d6;
    pbVar14 = (byte *)(buf + iVar3);
    bVar1 = pbVar14[-1];
    iVar2 = iVar11;
    pbVar6 = extraout_r1_00;
  } while( true );
}

