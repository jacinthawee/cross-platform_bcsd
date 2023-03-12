
/* WARNING: Could not reconcile some variable overlaps */

int i2b_PublicKey_bio(BIO *out,EVP_PKEY *pk)

{
  uchar uVar1;
  rsa_st *prVar2;
  BIGNUM *pBVar3;
  dsa_st *pdVar4;
  int iVar5;
  uint uVar6;
  undefined *data;
  int iVar7;
  undefined *puVar8;
  size_t sVar9;
  undefined *puVar10;
  undefined *puVar11;
  uchar *puVar12;
  undefined uVar13;
  int iVar14;
  undefined uVar15;
  undefined *puVar16;
  undefined4 *__s;
  undefined4 *puVar17;
  int iVar18;
  uchar *puVar19;
  uchar *puVar20;
  uchar *puVar21;
  int iVar22;
  uchar *local_34;
  int local_28;
  int local_24;
  
  if (pk->type == 0x74) {
    pdVar4 = (pk->pkey).dsa;
    uVar6 = BN_num_bits(pdVar4->p);
    if (((((uVar6 & 7) != 0) || (iVar5 = BN_num_bits(pdVar4->q), iVar5 != 0xa0)) ||
        (iVar5 = BN_num_bits(pdVar4->g), (int)uVar6 < iVar5)) ||
       (iVar5 = BN_num_bits(pdVar4->pub_key), (int)uVar6 < iVar5)) {
      ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x23c);
      return -1;
    }
    if (uVar6 == 0) {
      return -1;
    }
    uVar13 = 0x53;
    uVar15 = 0x44;
    local_34._0_1_ = 0x22;
    iVar18 = 0x2200;
    iVar5 = (uVar6 + 7 >> 3) * 3 + 0x2c;
  }
  else {
    if (pk->type != 6) {
      return -1;
    }
    prVar2 = (pk->pkey).rsa;
    iVar5 = BN_num_bits(prVar2->e);
    if (0x20 < iVar5) {
      ERR_put_error(9,0x83,0x7e,"pvkfmt.c",0x25e);
      return -1;
    }
    uVar6 = BN_num_bits(prVar2->n);
    BN_num_bits(prVar2->n);
    BN_num_bits(prVar2->n);
    if (uVar6 == 0) {
      return -1;
    }
    uVar13 = 0x41;
    uVar15 = 0x52;
    local_34._0_1_ = 0xa4;
    iVar18 = 0xa400;
    iVar5 = (uVar6 + 7 >> 3) + 4;
  }
  iVar5 = iVar5 + 0x10;
  data = (undefined *)CRYPTO_malloc(iVar5,"pvkfmt.c",0x1ff);
  if (data == (undefined *)0x0) {
    return -1;
  }
  *data = 6;
  data[1] = 2;
  data[2] = 0;
  data[3] = 0;
  data[4] = 0;
  data[0xc] = (char)uVar6;
  data[6] = 0;
  data[7] = 0;
  data[9] = 0x53;
  data[5] = local_34._0_1_;
  data[0xb] = 0x31;
  data[8] = uVar15;
  data[10] = uVar13;
  data[0xd] = (char)(uVar6 >> 8);
  data[0xf] = (char)(uVar6 >> 0x18);
  data[0xe] = (char)(uVar6 >> 0x10);
  puVar19 = data + 0x10;
  if (iVar18 != 0x2200) {
    prVar2 = (pk->pkey).rsa;
    BN_num_bits(prVar2->n);
    BN_num_bits(prVar2->n);
    pBVar3 = prVar2->e;
    iVar7 = BN_num_bits(pBVar3);
    iVar14 = iVar7 + 7;
    iVar18 = iVar7 + 0xe;
    if (-1 < iVar14) {
      iVar18 = iVar14;
    }
    iVar18 = iVar18 >> 3;
    BN_bn2bin(pBVar3,puVar19);
    puVar10 = data + 0x10;
    puVar16 = data + iVar18 + 0xf;
    iVar7 = iVar7 + 0x16;
    if (-1 < iVar14) {
      iVar7 = iVar14;
    }
    puVar11 = puVar10 + (iVar7 >> 4);
    if (0 < iVar7 >> 4) {
      do {
        uVar13 = *puVar10;
        puVar8 = puVar10 + 1;
        *puVar10 = *puVar16;
        *puVar16 = uVar13;
        puVar10 = puVar8;
        puVar16 = puVar16 + -1;
      } while (puVar11 != puVar8);
    }
    sVar9 = 4 - iVar18;
    puVar19 = puVar19 + iVar18;
    puVar20 = puVar19;
    if (0 < (int)sVar9) {
      puVar20 = puVar19 + sVar9;
      memset(puVar19,0,sVar9);
    }
    pBVar3 = prVar2->n;
    iVar14 = BN_num_bits(pBVar3);
    iVar18 = iVar14 + 7;
    BN_bn2bin(pBVar3,puVar20);
    iVar7 = iVar14 + 0xe;
    if (-1 < iVar18) {
      iVar7 = iVar18;
    }
    iVar14 = iVar14 + 0x16;
    if (-1 < iVar18) {
      iVar14 = iVar18;
    }
    if (0 < iVar14 >> 4) {
      puVar19 = puVar20 + (iVar7 >> 3) + -1;
      puVar12 = puVar20;
      do {
        uVar1 = *puVar12;
        puVar21 = puVar12 + 1;
        *puVar12 = *puVar19;
        *puVar19 = uVar1;
        puVar19 = puVar19 + -1;
        puVar12 = puVar21;
      } while (puVar20 + (iVar14 >> 4) != puVar21);
    }
    goto LAB_0815cb9e;
  }
  pdVar4 = (pk->pkey).dsa;
  iVar7 = BN_num_bits(pdVar4->p);
  iVar18 = iVar7 + 7;
  if (iVar7 + 7 < 0) {
    iVar18 = iVar7 + 0xe;
  }
  pBVar3 = pdVar4->p;
  iVar18 = iVar18 >> 3;
  iVar14 = BN_num_bits(pBVar3);
  iVar22 = iVar14 + 7;
  iVar7 = iVar14 + 0xe;
  if (-1 < iVar22) {
    iVar7 = iVar22;
  }
  iVar7 = iVar7 >> 3;
  BN_bn2bin(pBVar3,puVar19);
  iVar14 = iVar14 + 0x16;
  if (-1 < iVar22) {
    iVar14 = iVar22;
  }
  puVar10 = data + 0x10;
  puVar16 = data + iVar7 + 0xf;
  if (0 < iVar14 >> 4) {
    do {
      uVar13 = *puVar10;
      puVar11 = puVar10 + 1;
      *puVar10 = *puVar16;
      *puVar16 = uVar13;
      puVar10 = puVar11;
      puVar16 = puVar16 + -1;
    } while (data + 0x10 + (iVar14 >> 4) != puVar11);
  }
  puVar19 = puVar19 + iVar7;
  puVar20 = puVar19;
  if ((0 < iVar18) && (sVar9 = iVar18 - iVar7, 0 < (int)sVar9)) {
    puVar20 = puVar19 + sVar9;
    memset(puVar19,0,sVar9);
  }
  pBVar3 = pdVar4->q;
  iVar14 = BN_num_bits(pBVar3);
  iVar22 = iVar14 + 7;
  iVar7 = iVar14 + 0xe;
  if (-1 < iVar22) {
    iVar7 = iVar22;
  }
  iVar7 = iVar7 >> 3;
  BN_bn2bin(pBVar3,puVar20);
  puVar19 = puVar20 + iVar7 + -1;
  iVar14 = iVar14 + 0x16;
  if (-1 < iVar22) {
    iVar14 = iVar22;
  }
  puVar12 = puVar20;
  if (0 < iVar14 >> 4) {
    do {
      uVar1 = *puVar12;
      puVar21 = puVar12 + 1;
      *puVar12 = *puVar19;
      *puVar19 = uVar1;
      puVar12 = puVar21;
      puVar19 = puVar19 + -1;
    } while (puVar20 + (iVar14 >> 4) != puVar21);
  }
  puVar20 = puVar20 + iVar7;
  sVar9 = 0x14 - iVar7;
  local_34 = puVar20;
  if (0 < (int)sVar9) {
    local_34 = puVar20 + sVar9;
    memset(puVar20,0,sVar9);
  }
  pBVar3 = pdVar4->g;
  iVar14 = BN_num_bits(pBVar3);
  iVar22 = iVar14 + 7;
  iVar7 = iVar14 + 0xe;
  if (-1 < iVar22) {
    iVar7 = iVar22;
  }
  iVar7 = iVar7 >> 3;
  BN_bn2bin(pBVar3,local_34);
  puVar19 = local_34 + iVar7 + -1;
  iVar14 = iVar14 + 0x16;
  if (-1 < iVar22) {
    iVar14 = iVar22;
  }
  puVar20 = local_34;
  if (0 < iVar14 >> 4) {
    do {
      uVar1 = *puVar20;
      puVar12 = puVar20 + 1;
      *puVar20 = *puVar19;
      *puVar19 = uVar1;
      puVar20 = puVar12;
      puVar19 = puVar19 + -1;
    } while (puVar12 != local_34 + (iVar14 >> 4));
  }
  local_34 = local_34 + iVar7;
  if (iVar18 < 1) {
    pBVar3 = pdVar4->pub_key;
    iVar7 = BN_num_bits(pBVar3);
    iVar14 = iVar7 + 7;
    local_24 = iVar7 + 0xe;
    if (-1 < iVar14) {
      local_24 = iVar14;
    }
    local_24 = local_24 >> 3;
    BN_bn2bin(pBVar3,local_34);
    puVar19 = local_34 + local_24 + -1;
    iVar7 = iVar7 + 0x16;
    if (-1 < iVar14) {
      iVar7 = iVar14;
    }
    iVar7 = iVar7 >> 4;
    if (0 < iVar7) goto LAB_0815ce54;
    puVar17 = (undefined4 *)(local_34 + local_24);
  }
  else {
    sVar9 = iVar18 - iVar7;
    if (0 < (int)sVar9) {
      memset(local_34,0,sVar9);
      local_34 = local_34 + sVar9;
    }
    pBVar3 = pdVar4->pub_key;
    iVar14 = BN_num_bits(pBVar3);
    iVar7 = iVar14 + 7;
    local_28 = iVar14 + 0xe;
    if (-1 < iVar7) {
      local_28 = iVar7;
    }
    local_28 = local_28 >> 3;
    BN_bn2bin(pBVar3,local_34);
    puVar19 = local_34 + local_28 + -1;
    if (iVar7 < 0) {
      iVar7 = iVar14 + 0x16;
    }
    iVar7 = iVar7 >> 4;
    local_24 = local_28;
    if (iVar7 < 1) {
      __s = (undefined4 *)(local_34 + local_28);
    }
    else {
LAB_0815ce54:
      puVar20 = local_34;
      do {
        uVar1 = *puVar20;
        puVar12 = puVar20 + 1;
        *puVar20 = *puVar19;
        *puVar19 = uVar1;
        puVar20 = puVar12;
        puVar19 = puVar19 + -1;
      } while (local_34 + iVar7 != puVar12);
      __s = (undefined4 *)(local_34 + local_24);
      puVar17 = __s;
      local_28 = local_24;
      if (iVar18 < 1) goto LAB_0815cea3;
    }
    sVar9 = iVar18 - local_28;
    puVar17 = __s;
    if (0 < (int)sVar9) {
      puVar17 = (undefined4 *)((int)__s + sVar9);
      memset(__s,0,sVar9);
    }
  }
LAB_0815cea3:
  *puVar17 = 0xffffffff;
  puVar17[1] = 0xffffffff;
  puVar17[2] = 0xffffffff;
  puVar17[3] = 0xffffffff;
  puVar17[4] = 0xffffffff;
  puVar17[5] = 0xffffffff;
LAB_0815cb9e:
  iVar18 = BIO_write(out,data,iVar5);
  CRYPTO_free(data);
  if (iVar18 != iVar5) {
    return -1;
  }
  return iVar5;
}

