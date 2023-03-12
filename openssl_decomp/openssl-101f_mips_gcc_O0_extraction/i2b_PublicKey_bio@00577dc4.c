
int i2b_PublicKey_bio(BIO *out,EVP_PKEY *pk)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  BIGNUM *pBVar7;
  undefined *puVar8;
  ENGINE *pEVar9;
  rsa_st *prVar10;
  undefined uVar13;
  undefined *puVar11;
  undefined *puVar12;
  int iVar14;
  int iVar15;
  undefined uVar16;
  undefined uVar17;
  
  if (pk->type == 0x74) {
    prVar10 = (pk->pkey).rsa;
    uVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->engine);
    if (((((uVar2 & 7) != 0) ||
         (iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n), iVar1 != 0xa0)) ||
        (iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->e), (int)uVar2 < iVar1)) ||
       (iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->d), (int)uVar2 < iVar1)) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x82,0x7e,FUN_0066ce4c,0x23c);
      return -1;
    }
    if (uVar2 == 0) {
      return -1;
    }
    uVar17 = 0x53;
    uVar16 = 0x44;
    uVar13 = 0x22;
    iVar14 = 0x2200;
    iVar1 = (uVar2 + 7 >> 3) * 3 + 0x2c;
  }
  else {
    if (pk->type != 6) {
      return -1;
    }
    prVar10 = (pk->pkey).rsa;
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->e);
    if (0x20 < iVar1) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x83,0x7e,FUN_0066ce4c,0x25e);
      return -1;
    }
    uVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n);
    (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n);
    (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n);
    if (uVar2 == 0) {
      return -1;
    }
    uVar17 = 0x41;
    uVar16 = 0x52;
    iVar1 = (uVar2 + 7 >> 3) + 4;
    uVar13 = 0xa4;
    iVar14 = 0xa400;
  }
  iVar1 = iVar1 + 0x10;
  puVar3 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1,FUN_0066ce4c,0x1ff);
  if (puVar3 == (undefined *)0x0) {
    return -1;
  }
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[9] = 0x53;
  puVar3[5] = uVar13;
  *puVar3 = 6;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar11 = puVar3 + 0x10;
  puVar3[1] = 2;
  puVar3[8] = uVar16;
  puVar3[10] = uVar17;
  puVar3[0xb] = 0x31;
  puVar3[0xc] = (char)uVar2;
  puVar3[0xd] = (char)(uVar2 >> 8);
  puVar3[0xe] = (char)(uVar2 >> 0x10);
  puVar3[0xf] = (char)(uVar2 >> 0x18);
  if (iVar14 != 0x2200) {
    prVar10 = (pk->pkey).rsa;
    (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n);
    (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->n);
    pBVar7 = prVar10->e;
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar7);
    iVar14 = iVar4 + 7;
    iVar15 = iVar4 + 0xe;
    if (-1 < iVar14) {
      iVar15 = iVar14;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar7,puVar11);
    if (-1 >= iVar14) {
      iVar14 = iVar4 + 0x16;
    }
    iVar15 = iVar15 >> 3;
    if (0 < iVar14 >> 4) {
      puVar12 = puVar11 + iVar15 + -1;
      puVar6 = puVar11;
      do {
        uVar13 = *puVar6;
        puVar8 = puVar6 + 1;
        *puVar6 = *puVar12;
        *puVar12 = uVar13;
        puVar12 = puVar12 + -1;
        puVar6 = puVar8;
      } while (puVar11 + (iVar14 >> 4) != puVar8);
    }
    puVar11 = puVar11 + iVar15;
    puVar12 = puVar11;
    if (0 < 4 - iVar15) {
      puVar12 = puVar11 + (4 - iVar15);
      (*(code *)PTR_memset_006aab00)(puVar11,0);
    }
    pBVar7 = prVar10->n;
    iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar7);
    iVar4 = iVar15 + 7;
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar7,puVar12);
    iVar14 = iVar15 + 0xe;
    if (-1 < iVar4) {
      iVar14 = iVar4;
    }
    iVar15 = iVar15 + 0x16;
    if (-1 < iVar4) {
      iVar15 = iVar4;
    }
    if (0 < iVar15 >> 4) {
      puVar11 = puVar12 + (iVar14 >> 3) + -1;
      puVar6 = puVar12;
      do {
        uVar13 = *puVar6;
        puVar8 = puVar6 + 1;
        *puVar6 = *puVar11;
        *puVar11 = uVar13;
        puVar11 = puVar11 + -1;
        puVar6 = puVar8;
      } while (puVar12 + (iVar15 >> 4) != puVar8);
    }
    goto LAB_00578064;
  }
  prVar10 = (pk->pkey).rsa;
  iVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(prVar10->engine);
  pEVar9 = prVar10->engine;
  iVar14 = iVar15 + 7;
  if (iVar15 + 7 < 0) {
    iVar14 = iVar15 + 0xe;
  }
  iVar14 = iVar14 >> 3;
  iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(pEVar9);
  iVar15 = iVar5 + 7;
  iVar4 = iVar5 + 0xe;
  if (-1 < iVar15) {
    iVar4 = iVar15;
  }
  (*(code *)PTR_BN_bn2bin_006a8300)(pEVar9,puVar11);
  iVar4 = iVar4 >> 3;
  if (-1 >= iVar15) {
    iVar15 = iVar5 + 0x16;
  }
  if (0 < iVar15 >> 4) {
    puVar12 = puVar11;
    puVar6 = puVar11 + iVar4 + -1;
    do {
      uVar13 = *puVar12;
      puVar8 = puVar12 + 1;
      *puVar12 = *puVar6;
      *puVar6 = uVar13;
      puVar12 = puVar8;
      puVar6 = puVar6 + -1;
    } while (puVar11 + (iVar15 >> 4) != puVar8);
  }
  puVar11 = puVar11 + iVar4;
  puVar12 = puVar11;
  if ((0 < iVar14) && (0 < iVar14 - iVar4)) {
    puVar12 = puVar11 + (iVar14 - iVar4);
    (*(code *)PTR_memset_006aab00)(puVar11,0);
  }
  pBVar7 = prVar10->n;
  iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar7);
  iVar15 = iVar5 + 7;
  iVar4 = iVar5 + 0xe;
  if (-1 < iVar15) {
    iVar4 = iVar15;
  }
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar7,puVar12);
  iVar4 = iVar4 >> 3;
  if (-1 >= iVar15) {
    iVar15 = iVar5 + 0x16;
  }
  if (0 < iVar15 >> 4) {
    puVar11 = puVar12;
    puVar6 = puVar12 + iVar4 + -1;
    do {
      uVar13 = *puVar11;
      puVar8 = puVar11 + 1;
      *puVar11 = *puVar6;
      *puVar6 = uVar13;
      puVar11 = puVar8;
      puVar6 = puVar6 + -1;
    } while (puVar12 + (iVar15 >> 4) != puVar8);
  }
  puVar12 = puVar12 + iVar4;
  puVar11 = puVar12;
  if (0 < 0x14 - iVar4) {
    puVar11 = puVar12 + (0x14 - iVar4);
    (*(code *)PTR_memset_006aab00)(puVar12,0);
  }
  pBVar7 = prVar10->e;
  iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar7);
  iVar15 = iVar5 + 7;
  iVar4 = iVar5 + 0xe;
  if (-1 < iVar15) {
    iVar4 = iVar15;
  }
  (*(code *)PTR_BN_bn2bin_006a8300)(pBVar7,puVar11);
  iVar4 = iVar4 >> 3;
  if (-1 >= iVar15) {
    iVar15 = iVar5 + 0x16;
  }
  if (0 < iVar15 >> 4) {
    puVar12 = puVar11;
    puVar6 = puVar11 + iVar4 + -1;
    do {
      uVar13 = *puVar12;
      puVar8 = puVar12 + 1;
      *puVar12 = *puVar6;
      *puVar6 = uVar13;
      puVar12 = puVar8;
      puVar6 = puVar6 + -1;
    } while (puVar8 != puVar11 + (iVar15 >> 4));
  }
  puVar11 = puVar11 + iVar4;
  if (iVar14 < 1) {
    pBVar7 = prVar10->d;
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar7);
    iVar15 = iVar5 + 7;
    iVar4 = iVar5 + 0xe;
    if (-1 < iVar15) {
      iVar4 = iVar15;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar7,puVar11);
    if (-1 >= iVar15) {
      iVar15 = iVar5 + 0x16;
    }
    iVar4 = iVar4 >> 3;
    iVar15 = iVar15 >> 4;
    puVar12 = puVar11 + iVar4 + -1;
    if (0 < iVar15) goto LAB_005783c8;
    puVar12 = puVar11 + iVar4;
  }
  else {
    iVar4 = iVar14 - iVar4;
    if (0 < iVar4) {
      (*(code *)PTR_memset_006aab00)(puVar11,0,iVar4);
      puVar11 = puVar11 + iVar4;
    }
    pBVar7 = prVar10->d;
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(pBVar7);
    iVar15 = iVar5 + 7;
    iVar4 = iVar5 + 0xe;
    if (-1 < iVar15) {
      iVar4 = iVar15;
    }
    (*(code *)PTR_BN_bn2bin_006a8300)(pBVar7,puVar11);
    if (-1 >= iVar15) {
      iVar15 = iVar5 + 0x16;
    }
    iVar4 = iVar4 >> 3;
    iVar15 = iVar15 >> 4;
    puVar12 = puVar11 + iVar4 + -1;
    if (iVar15 < 1) {
      puVar11 = puVar11 + iVar4;
    }
    else {
LAB_005783c8:
      puVar6 = puVar11;
      do {
        uVar13 = *puVar6;
        puVar8 = puVar6 + 1;
        *puVar6 = *puVar12;
        *puVar12 = uVar13;
        puVar6 = puVar8;
        puVar12 = puVar12 + -1;
      } while (puVar11 + iVar15 != puVar8);
      puVar11 = puVar11 + iVar4;
      puVar12 = puVar11;
      if (iVar14 < 1) goto LAB_00578414;
    }
    puVar12 = puVar11;
    if (0 < iVar14 - iVar4) {
      puVar12 = puVar11 + (iVar14 - iVar4);
      (*(code *)PTR_memset_006aab00)(puVar11,0);
    }
  }
LAB_00578414:
  (*(code *)PTR_memset_006aab00)(puVar12,0xff,0x18);
LAB_00578064:
  iVar14 = (*(code *)PTR_BIO_write_006a7f14)(out,puVar3,iVar1);
  (*(code *)PTR_CRYPTO_free_006a7f88)(puVar3);
  if (iVar14 != iVar1) {
    return -1;
  }
  return iVar1;
}

