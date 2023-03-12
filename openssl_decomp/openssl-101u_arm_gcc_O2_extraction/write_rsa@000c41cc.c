
void write_rsa(uchar **param_1,int param_2,int param_3)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uchar *puVar6;
  BIGNUM *pBVar7;
  uchar *puVar8;
  uchar *puVar9;
  uchar *puVar10;
  size_t sVar11;
  
  iVar2 = BN_num_bits(*(BIGNUM **)(param_2 + 0x10));
  iVar3 = BN_num_bits(*(BIGNUM **)(param_2 + 0x10));
  pBVar7 = *(BIGNUM **)(param_2 + 0x14);
  puVar9 = *param_1;
  iVar4 = BN_num_bits(pBVar7);
  iVar5 = iVar4 + 0xe;
  if (-1 < iVar4 + 7) {
    iVar5 = iVar4 + 7;
  }
  BN_bn2bin(pBVar7,puVar9);
  iVar4 = iVar5 >> 3;
  iVar5 = iVar4 - (iVar5 >> 0x1f) >> 1;
  if (0 < iVar5) {
    puVar6 = puVar9 + iVar4 + -1;
    puVar8 = puVar9;
    do {
      uVar1 = *puVar8;
      puVar10 = puVar8 + 1;
      *puVar8 = *puVar6;
      *puVar6 = uVar1;
      puVar6 = puVar6 + -1;
      puVar8 = puVar10;
    } while (puVar10 != puVar9 + iVar5);
  }
  sVar11 = 4 - iVar4;
  puVar9 = *param_1 + iVar4;
  *param_1 = puVar9;
  if (0 < (int)sVar11) {
    memset(puVar9,0,sVar11);
    puVar9 = *param_1 + sVar11;
    *param_1 = puVar9;
  }
  pBVar7 = *(BIGNUM **)(param_2 + 0x10);
  iVar4 = BN_num_bits(pBVar7);
  iVar5 = iVar4 + 7;
  if (iVar4 + 7 < 0) {
    iVar5 = iVar4 + 0xe;
  }
  iVar4 = iVar5 >> 3;
  BN_bn2bin(pBVar7,puVar9);
  iVar5 = iVar4 - (iVar5 >> 0x1f) >> 1;
  if (0 < iVar5) {
    puVar6 = puVar9 + iVar4 + -1;
    puVar8 = puVar9;
    do {
      uVar1 = *puVar8;
      puVar10 = puVar8 + 1;
      *puVar8 = *puVar6;
      *puVar6 = uVar1;
      puVar6 = puVar6 + -1;
      puVar8 = puVar10;
    } while (puVar10 != puVar9 + iVar5);
  }
  puVar9 = *param_1 + iVar4;
  *param_1 = puVar9;
  if (param_3 == 0) {
    pBVar7 = *(BIGNUM **)(param_2 + 0x1c);
    iVar4 = BN_num_bits(pBVar7);
    iVar5 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar5 = iVar4 + 0xe;
    }
    iVar4 = iVar5 >> 3;
    BN_bn2bin(pBVar7,puVar9);
    iVar5 = iVar4 - (iVar5 >> 0x1f) >> 1;
    if (0 < iVar5) {
      puVar6 = puVar9 + iVar4 + -1;
      puVar8 = puVar9;
      do {
        uVar1 = *puVar8;
        puVar10 = puVar8 + 1;
        *puVar8 = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + -1;
        puVar8 = puVar10;
      } while (puVar10 != puVar9 + iVar5);
    }
    iVar5 = iVar3 + 0xf >> 4;
    puVar9 = *param_1 + iVar4;
    *param_1 = puVar9;
    if ((0 < iVar5) && (sVar11 = iVar5 - iVar4, 0 < (int)sVar11)) {
      memset(puVar9,0,sVar11);
      puVar9 = *param_1 + sVar11;
      *param_1 = puVar9;
    }
    pBVar7 = *(BIGNUM **)(param_2 + 0x20);
    iVar4 = BN_num_bits(pBVar7);
    iVar3 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar3 = iVar4 + 0xe;
    }
    iVar4 = iVar3 >> 3;
    BN_bn2bin(pBVar7,puVar9);
    iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
    if (0 < iVar3) {
      puVar6 = puVar9 + iVar4 + -1;
      puVar8 = puVar9;
      do {
        uVar1 = *puVar8;
        puVar10 = puVar8 + 1;
        *puVar8 = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + -1;
        puVar8 = puVar10;
      } while (puVar10 != puVar9 + iVar3);
    }
    puVar9 = *param_1 + iVar4;
    *param_1 = puVar9;
    if ((0 < iVar5) && (sVar11 = iVar5 - iVar4, 0 < (int)sVar11)) {
      memset(puVar9,0,sVar11);
      puVar9 = *param_1 + sVar11;
      *param_1 = puVar9;
    }
    pBVar7 = *(BIGNUM **)(param_2 + 0x24);
    iVar4 = BN_num_bits(pBVar7);
    iVar3 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar3 = iVar4 + 0xe;
    }
    iVar4 = iVar3 >> 3;
    BN_bn2bin(pBVar7,puVar9);
    iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
    if (0 < iVar3) {
      puVar6 = puVar9 + iVar4 + -1;
      puVar8 = puVar9;
      do {
        uVar1 = *puVar8;
        puVar10 = puVar8 + 1;
        *puVar8 = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + -1;
        puVar8 = puVar10;
      } while (puVar10 != puVar9 + iVar3);
    }
    puVar9 = *param_1 + iVar4;
    *param_1 = puVar9;
    if ((0 < iVar5) && (sVar11 = iVar5 - iVar4, 0 < (int)sVar11)) {
      memset(puVar9,0,sVar11);
      puVar9 = *param_1 + sVar11;
      *param_1 = puVar9;
    }
    pBVar7 = *(BIGNUM **)(param_2 + 0x28);
    iVar4 = BN_num_bits(pBVar7);
    iVar3 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar3 = iVar4 + 0xe;
    }
    iVar4 = iVar3 >> 3;
    BN_bn2bin(pBVar7,puVar9);
    iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
    if (0 < iVar3) {
      puVar6 = puVar9 + iVar4 + -1;
      puVar8 = puVar9;
      do {
        uVar1 = *puVar8;
        puVar10 = puVar8 + 1;
        *puVar8 = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + -1;
        puVar8 = puVar10;
      } while (puVar10 != puVar9 + iVar3);
    }
    puVar9 = *param_1 + iVar4;
    *param_1 = puVar9;
    if ((0 < iVar5) && (sVar11 = iVar5 - iVar4, 0 < (int)sVar11)) {
      memset(puVar9,0,sVar11);
      puVar9 = *param_1 + sVar11;
      *param_1 = puVar9;
    }
    pBVar7 = *(BIGNUM **)(param_2 + 0x2c);
    iVar4 = BN_num_bits(pBVar7);
    iVar3 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar3 = iVar4 + 0xe;
    }
    iVar4 = iVar3 >> 3;
    BN_bn2bin(pBVar7,puVar9);
    iVar3 = iVar4 - (iVar3 >> 0x1f) >> 1;
    if (0 < iVar3) {
      puVar6 = puVar9 + iVar4 + -1;
      puVar8 = puVar9;
      do {
        uVar1 = *puVar8;
        puVar10 = puVar8 + 1;
        *puVar8 = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + -1;
        puVar8 = puVar10;
      } while (puVar10 != puVar9 + iVar3);
    }
    puVar9 = *param_1 + iVar4;
    *param_1 = puVar9;
    if ((0 < iVar5) && (sVar11 = iVar5 - iVar4, 0 < (int)sVar11)) {
      memset(puVar9,0,sVar11);
      puVar9 = *param_1 + sVar11;
      *param_1 = puVar9;
    }
    pBVar7 = *(BIGNUM **)(param_2 + 0x18);
    iVar3 = BN_num_bits(pBVar7);
    iVar5 = iVar3 + 0xe;
    if (-1 < iVar3 + 7) {
      iVar5 = iVar3 + 7;
    }
    BN_bn2bin(pBVar7,puVar9);
    iVar3 = iVar5 >> 3;
    iVar5 = iVar3 - (iVar5 >> 0x1f) >> 1;
    if (0 < iVar5) {
      puVar6 = puVar9 + iVar3 + -1;
      puVar8 = puVar9;
      do {
        uVar1 = *puVar8;
        puVar10 = puVar8 + 1;
        *puVar8 = *puVar6;
        *puVar6 = uVar1;
        puVar6 = puVar6 + -1;
        puVar8 = puVar10;
      } while (puVar10 != puVar9 + iVar5);
    }
    puVar9 = *param_1;
    iVar5 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar5 = iVar2 + 7;
    }
    *param_1 = puVar9 + iVar3;
    if (iVar5 >> 3 < 1) {
      return;
    }
    sVar11 = (iVar5 >> 3) - iVar3;
    if (0 < (int)sVar11) {
      memset(puVar9 + iVar3,0,sVar11);
      *param_1 = *param_1 + sVar11;
      return;
    }
  }
  return;
}

