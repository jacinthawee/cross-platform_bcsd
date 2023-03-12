
int i2b_PublicKey_bio(BIO *out,EVP_PKEY *pk)

{
  uchar uVar1;
  int iVar2;
  uint uVar3;
  undefined *data;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  size_t sVar7;
  uchar *puVar8;
  uchar *puVar9;
  dsa_st *pdVar10;
  BIGNUM *pBVar11;
  rsa_st *prVar12;
  uint uVar13;
  int iVar14;
  undefined uVar15;
  uchar *puVar16;
  uint uVar17;
  
  if (pk->type == 0x74) {
    pdVar10 = (pk->pkey).dsa;
    uVar3 = BN_num_bits(pdVar10->p);
    if (((((uVar3 & 7) == 0) && (iVar2 = BN_num_bits(pdVar10->q), iVar2 == 0xa0)) &&
        (iVar2 = BN_num_bits(pdVar10->g), iVar2 <= (int)uVar3)) &&
       (iVar2 = BN_num_bits(pdVar10->pub_key), iVar2 <= (int)uVar3)) {
      uVar17 = 0x31535344;
    }
    else {
      uVar3 = 0;
      ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x23c);
      uVar17 = 0;
    }
    uVar15 = 0x22;
    iVar2 = 0x2200;
  }
  else {
    if (pk->type != 6) {
      return -1;
    }
    prVar12 = (pk->pkey).rsa;
    iVar2 = BN_num_bits(prVar12->e);
    if (iVar2 < 0x21) {
      uVar3 = BN_num_bits(prVar12->n);
      BN_num_bits(prVar12->n);
      BN_num_bits(prVar12->n);
      uVar17 = 0x31415352;
    }
    else {
      uVar3 = 0;
      ERR_put_error(9,0x83,0x7e,"pvkfmt.c",0x25e);
      uVar17 = uVar3;
    }
    uVar15 = 0xa4;
    iVar2 = 0xa400;
  }
  if (uVar3 != 0) {
    uVar13 = uVar3 + 7 >> 3;
    if (iVar2 == 0x2200) {
      iVar14 = uVar13 * 3 + 0x2c;
    }
    else {
      iVar14 = uVar13 + 4;
    }
    iVar14 = iVar14 + 0x10;
    data = (undefined *)CRYPTO_malloc(iVar14,"pvkfmt.c",0x1ff);
    if (data != (undefined *)0x0) {
      data[5] = uVar15;
      data[8] = (char)uVar17;
      data[0xc] = (char)uVar3;
      *data = 6;
      data[1] = 2;
      data[2] = 0;
      data[3] = 0;
      puVar16 = data + 0x10;
      data[4] = 0;
      data[6] = 0;
      data[7] = 0;
      data[9] = (char)(uVar17 >> 8);
      data[10] = (char)(uVar17 >> 0x10);
      data[0xb] = (char)(uVar17 >> 0x18);
      data[0xd] = (char)(uVar3 >> 8);
      data[0xe] = (char)(uVar3 >> 0x10);
      data[0xf] = (char)(uVar3 >> 0x18);
      if (iVar2 == 0x2200) {
        pdVar10 = (pk->pkey).dsa;
        iVar4 = BN_num_bits(pdVar10->p);
        pBVar11 = pdVar10->p;
        iVar2 = iVar4 + 0xe;
        if (-1 < iVar4 + 7) {
          iVar2 = iVar4 + 7;
        }
        iVar5 = BN_num_bits(pBVar11);
        iVar2 = iVar2 >> 3;
        iVar4 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar4 = iVar5 + 7;
        }
        BN_bn2bin(pBVar11,puVar16);
        iVar5 = iVar4 >> 3;
        iVar4 = iVar5 - (iVar4 >> 0x1f) >> 1;
        if (0 < iVar4) {
          puVar9 = puVar16 + iVar5 + -1;
          puVar8 = puVar16;
          do {
            uVar1 = *puVar8;
            puVar6 = puVar8 + 1;
            *puVar8 = *puVar9;
            *puVar9 = uVar1;
            puVar9 = puVar9 + -1;
            puVar8 = puVar6;
          } while (puVar6 != puVar16 + iVar4);
        }
        puVar16 = puVar16 + iVar5;
        puVar9 = puVar16;
        if ((0 < iVar2) && (sVar7 = iVar2 - iVar5, 0 < (int)sVar7)) {
          puVar9 = puVar16 + sVar7;
          memset(puVar16,0,sVar7);
        }
        pBVar11 = pdVar10->q;
        iVar5 = BN_num_bits(pBVar11);
        iVar4 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar4 = iVar5 + 7;
        }
        BN_bn2bin(pBVar11,puVar9);
        iVar5 = iVar4 >> 3;
        iVar4 = iVar5 - (iVar4 >> 0x1f) >> 1;
        if (0 < iVar4) {
          puVar16 = puVar9 + iVar5 + -1;
          puVar8 = puVar9;
          do {
            uVar1 = *puVar8;
            puVar6 = puVar8 + 1;
            *puVar8 = *puVar16;
            *puVar16 = uVar1;
            puVar16 = puVar16 + -1;
            puVar8 = puVar6;
          } while (puVar6 != puVar9 + iVar4);
        }
        sVar7 = 0x14 - iVar5;
        puVar9 = puVar9 + iVar5;
        puVar16 = puVar9;
        if (0 < (int)sVar7) {
          puVar16 = puVar9 + sVar7;
          memset(puVar9,0,sVar7);
        }
        pBVar11 = pdVar10->g;
        iVar5 = BN_num_bits(pBVar11);
        iVar4 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar4 = iVar5 + 7;
        }
        BN_bn2bin(pBVar11,puVar16);
        iVar5 = iVar4 >> 3;
        iVar4 = iVar5 - (iVar4 >> 0x1f) >> 1;
        if (0 < iVar4) {
          puVar9 = puVar16 + iVar5 + -1;
          puVar8 = puVar16;
          do {
            uVar1 = *puVar8;
            puVar6 = puVar8 + 1;
            *puVar8 = *puVar9;
            *puVar9 = uVar1;
            puVar9 = puVar9 + -1;
            puVar8 = puVar6;
          } while (puVar6 != puVar16 + iVar4);
        }
        puVar16 = puVar16 + iVar5;
        puVar9 = puVar16;
        if ((0 < iVar2) && (sVar7 = iVar2 - iVar5, 0 < (int)sVar7)) {
          puVar9 = puVar16 + sVar7;
          memset(puVar16,0,sVar7);
        }
        pBVar11 = pdVar10->pub_key;
        iVar5 = BN_num_bits(pBVar11);
        iVar4 = iVar5 + 0xe;
        if (-1 < iVar5 + 7) {
          iVar4 = iVar5 + 7;
        }
        BN_bn2bin(pBVar11,puVar9);
        iVar5 = iVar4 >> 3;
        iVar4 = iVar5 - (iVar4 >> 0x1f) >> 1;
        if (0 < iVar4) {
          puVar16 = puVar9 + iVar5 + -1;
          puVar8 = puVar9;
          do {
            uVar1 = *puVar8;
            puVar6 = puVar8 + 1;
            *puVar8 = *puVar16;
            *puVar16 = uVar1;
            puVar16 = puVar16 + -1;
            puVar8 = puVar6;
          } while (puVar6 != puVar9 + iVar4);
        }
        puVar9 = puVar9 + iVar5;
        puVar16 = puVar9;
        if ((0 < iVar2) && (sVar7 = iVar2 - iVar5, 0 < (int)sVar7)) {
          puVar16 = puVar9 + sVar7;
          memset(puVar9,0,sVar7);
        }
        memset(puVar16,0xff,0x18);
      }
      else {
        prVar12 = (pk->pkey).rsa;
        BN_num_bits(prVar12->n);
        BN_num_bits(prVar12->n);
        pBVar11 = prVar12->e;
        iVar4 = BN_num_bits(pBVar11);
        iVar2 = iVar4 + 0xe;
        if (-1 < iVar4 + 7) {
          iVar2 = iVar4 + 7;
        }
        BN_bn2bin(pBVar11,puVar16);
        iVar4 = iVar2 >> 3;
        iVar2 = iVar4 - (iVar2 >> 0x1f) >> 1;
        if (0 < iVar2) {
          puVar9 = puVar16;
          puVar8 = puVar16 + iVar4 + -1;
          do {
            uVar1 = *puVar9;
            puVar6 = puVar9 + 1;
            *puVar9 = *puVar8;
            *puVar8 = uVar1;
            puVar9 = puVar6;
            puVar8 = puVar8 + -1;
          } while (puVar6 != puVar16 + iVar2);
        }
        sVar7 = 4 - iVar4;
        puVar16 = puVar16 + iVar4;
        puVar9 = puVar16;
        if (0 < (int)sVar7) {
          puVar9 = puVar16 + sVar7;
          memset(puVar16,0,sVar7);
        }
        pBVar11 = prVar12->n;
        iVar4 = BN_num_bits(pBVar11);
        iVar2 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar2 = iVar4 + 0xe;
        }
        BN_bn2bin(pBVar11,puVar9);
        iVar4 = (iVar2 >> 3) - (iVar2 >> 0x1f) >> 1;
        if (0 < iVar4) {
          puVar16 = puVar9 + (iVar2 >> 3) + -1;
          puVar8 = puVar9;
          do {
            uVar1 = *puVar8;
            puVar6 = puVar8 + 1;
            *puVar8 = *puVar16;
            *puVar16 = uVar1;
            puVar16 = puVar16 + -1;
            puVar8 = puVar6;
          } while (puVar6 != puVar9 + iVar4);
        }
      }
      iVar2 = BIO_write(out,data,iVar14);
      CRYPTO_free(data);
      if (iVar2 == iVar14) {
        return iVar14;
      }
    }
  }
  return -1;
}

