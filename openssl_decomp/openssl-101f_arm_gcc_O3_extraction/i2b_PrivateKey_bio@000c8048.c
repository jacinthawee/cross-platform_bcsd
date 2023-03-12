
int i2b_PrivateKey_bio(BIO *out,EVP_PKEY *pk)

{
  uchar uVar1;
  uint uVar2;
  undefined *data;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  char *pcVar6;
  uchar *puVar7;
  uchar *puVar8;
  uchar *puVar9;
  BIGNUM *pBVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  dsa_st *pdVar14;
  undefined uVar15;
  size_t sVar16;
  uchar *local_30;
  undefined4 local_2c [2];
  
  pcVar6 = (char *)pk->type;
  local_2c[0] = 0;
  if (pcVar6 == (char *)0x74) {
    pdVar14 = (pk->pkey).dsa;
    uVar2 = BN_num_bits(pdVar14->p);
    if (((((uVar2 & 7) == 0) && (iVar13 = BN_num_bits(pdVar14->q), iVar13 == 0xa0)) &&
        (iVar13 = BN_num_bits(pdVar14->g), iVar13 <= (int)uVar2)) &&
       (iVar13 = BN_num_bits(pdVar14->priv_key), iVar13 < 0xa1)) {
      pcVar6 = (char *)0x32535344;
      local_2c[0] = 0x32535344;
    }
    else {
      pcVar6 = "pvkfmt.c";
      uVar2 = 0;
      ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x23c);
    }
    uVar15 = 0x22;
    iVar13 = 0x2200;
  }
  else {
    if (pcVar6 != (char *)0x6) {
      return -1;
    }
    uVar2 = check_bitlen_rsa((pk->pkey).ptr,0,local_2c);
    uVar15 = 0xa4;
    iVar13 = 0xa400;
  }
  if (uVar2 != 0) {
    if (iVar13 != 0x2200) {
      pcVar6 = (char *)(uVar2 + 0xf);
    }
    uVar11 = uVar2 + 7 >> 3;
    if (iVar13 != 0x2200) {
      iVar12 = ((uint)pcVar6 >> 4) * 5 + (uVar11 + 2) * 2;
    }
    else {
      iVar12 = (uVar11 + 0x20) * 2;
    }
    iVar12 = iVar12 + 0x10;
    data = (undefined *)CRYPTO_malloc(iVar12,"pvkfmt.c",0x1ff);
    if (data != (undefined *)0x0) {
      *data = 7;
      data[1] = 2;
      data[2] = 0;
      data[3] = 0;
      local_30 = data + 0x10;
      data[4] = 0;
      data[5] = uVar15;
      data[6] = 0;
      data[7] = 0;
      data[0xc] = (char)uVar2;
      data[0xd] = (char)(uVar2 >> 8);
      data[8] = (char)local_2c[0];
      data[9] = (char)((uint)local_2c[0] >> 8);
      data[10] = (char)((uint)local_2c[0] >> 0x10);
      data[0xe] = (char)(uVar2 >> 0x10);
      data[0xb] = (char)((uint)local_2c[0] >> 0x18);
      data[0xf] = (char)(uVar2 >> 0x18);
      if (iVar13 == 0x2200) {
        pdVar14 = (pk->pkey).dsa;
        iVar3 = BN_num_bits(pdVar14->p);
        puVar5 = local_30;
        pBVar10 = pdVar14->p;
        iVar13 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar13 = iVar3 + 7;
        }
        iVar4 = BN_num_bits(pBVar10);
        iVar13 = iVar13 >> 3;
        iVar3 = iVar4 + 0xe;
        if (-1 < iVar4 + 7) {
          iVar3 = iVar4 + 7;
        }
        BN_bn2bin(pBVar10,puVar5);
        iVar4 = iVar3 >> 3;
        iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
        if (0 < iVar3) {
          puVar7 = puVar5 + iVar4 + -1;
          puVar9 = puVar5;
          do {
            uVar1 = *puVar9;
            puVar8 = puVar9 + 1;
            *puVar9 = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + -1;
            puVar9 = puVar8;
          } while (puVar8 != puVar5 + iVar3);
        }
        puVar5 = local_30 + iVar4;
        if ((0 < iVar13) && (sVar16 = iVar13 - iVar4, 0 < (int)sVar16)) {
          local_30 = puVar5;
          memset(puVar5,0,sVar16);
          puVar5 = local_30 + sVar16;
        }
        pBVar10 = pdVar14->q;
        local_30 = puVar5;
        iVar4 = BN_num_bits(pBVar10);
        iVar3 = iVar4 + 0xe;
        if (-1 < iVar4 + 7) {
          iVar3 = iVar4 + 7;
        }
        BN_bn2bin(pBVar10,puVar5);
        iVar4 = iVar3 >> 3;
        iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
        if (0 < iVar3) {
          puVar7 = puVar5 + iVar4 + -1;
          puVar9 = puVar5;
          do {
            uVar1 = *puVar9;
            puVar8 = puVar9 + 1;
            *puVar9 = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + -1;
            puVar9 = puVar8;
          } while (puVar8 != puVar5 + iVar3);
        }
        sVar16 = 0x14 - iVar4;
        puVar5 = local_30 + iVar4;
        if (0 < (int)sVar16) {
          local_30 = puVar5;
          memset(puVar5,0,sVar16);
          puVar5 = local_30 + sVar16;
        }
        pBVar10 = pdVar14->g;
        local_30 = puVar5;
        iVar4 = BN_num_bits(pBVar10);
        iVar3 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar3 = iVar4 + 0xe;
        }
        iVar4 = iVar3 >> 3;
        BN_bn2bin(pBVar10,puVar5);
        iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
        if (0 < iVar3) {
          puVar7 = puVar5 + iVar4 + -1;
          puVar9 = puVar5;
          do {
            uVar1 = *puVar9;
            puVar8 = puVar9 + 1;
            *puVar9 = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + -1;
            puVar9 = puVar8;
          } while (puVar8 != puVar5 + iVar3);
        }
        puVar5 = local_30 + iVar4;
        if ((0 < iVar13) && (sVar16 = iVar13 - iVar4, 0 < (int)sVar16)) {
          local_30 = puVar5;
          memset(puVar5,0,sVar16);
          puVar5 = local_30 + sVar16;
        }
        pBVar10 = pdVar14->priv_key;
        local_30 = puVar5;
        iVar3 = BN_num_bits(pBVar10);
        iVar13 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar13 = iVar3 + 7;
        }
        BN_bn2bin(pBVar10,puVar5);
        iVar3 = iVar13 >> 3;
        iVar13 = iVar3 - (iVar13 >> 0x1f) >> 1;
        if (0 < iVar13) {
          puVar7 = puVar5 + iVar3 + -1;
          puVar9 = puVar5;
          do {
            uVar1 = *puVar9;
            puVar8 = puVar9 + 1;
            *puVar9 = *puVar7;
            *puVar7 = uVar1;
            puVar7 = puVar7 + -1;
            puVar9 = puVar8;
          } while (puVar8 != puVar5 + iVar13);
        }
        sVar16 = 0x14 - iVar3;
        local_30 = local_30 + iVar3;
        if (0 < (int)sVar16) {
          memset(local_30,0,sVar16);
          local_30 = local_30 + sVar16;
        }
        memset(local_30,0xff,0x18);
      }
      else {
        write_rsa(&local_30,(pk->pkey).ptr);
      }
      if (-1 < iVar12) {
        iVar13 = BIO_write(out,data,iVar12);
        CRYPTO_free(data);
        if (iVar13 != iVar12) {
          iVar12 = -1;
        }
        return iVar12;
      }
    }
  }
  return -1;
}

