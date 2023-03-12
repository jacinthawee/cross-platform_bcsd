
/* WARNING: Restarted to delay deadcode elimination for space: stack */

int AES_set_encrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  AES_KEY *pAVar1;
  uchar *userKey_00;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_r1;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  AES_KEY *pAVar10;
  AES_KEY *pAVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint in_lr;
  undefined8 unaff_d14;
  undefined8 in_d31;
  
  uVar2 = bits;
  if (userKey == (uchar *)0x0) {
    userKey_00 = (uchar *)0xffffffff;
  }
  else if (key == (AES_KEY *)0x0) {
    userKey_00 = (uchar *)0xffffffff;
  }
  else if (((bits == 0x80) || (bits == 0xc0)) || (bits == 0x100)) {
    uVar2 = *(uint *)userKey;
    uVar4 = *(uint *)(userKey + 4);
    uVar5 = *(uint *)(userKey + 8);
    uVar6 = *(uint *)(userKey + 0xc);
    uVar3 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
            uVar2 >> 0x18;
    uVar2 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
            uVar4 >> 0x18;
    uVar4 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18;
    uVar5 = uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
            uVar6 >> 0x18;
    key->rd_key[0] = uVar3;
    key->rd_key[1] = uVar2;
    key->rd_key[2] = uVar4;
    key->rd_key[3] = uVar5;
    if (bits == 0x80) {
      iVar14 = 10;
      key->rounds = 10;
      puVar7 = &DAT_0007e9e0;
      puVar8 = key->rd_key + 4;
      do {
        puVar13 = puVar8;
        uVar3 = uVar3 ^ ((uint)(byte)(&DAT_0007e8e0)[uVar5 >> 0x18] |
                         (uint)(byte)(&DAT_0007e8e0)[uVar5 >> 0x10 & 0xff] << 0x18 |
                         (uint)(byte)(&DAT_0007e8e0)[uVar5 >> 8 & 0xff] << 0x10 |
                        (uint)(byte)(&DAT_0007e8e0)[uVar5 & 0xff] << 8) ^ *puVar7;
        uVar2 = uVar2 ^ uVar3;
        *puVar13 = uVar3;
        uVar4 = uVar4 ^ uVar2;
        puVar13[1] = uVar2;
        uVar5 = uVar5 ^ uVar4;
        puVar13[2] = uVar4;
        iVar14 = iVar14 + -1;
        puVar13[3] = uVar5;
        puVar7 = puVar7 + 1;
        puVar8 = puVar13 + 4;
      } while (iVar14 != 0);
      key = (AES_KEY *)(puVar13 + -0x28);
    }
    else {
      uVar6 = *(uint *)(userKey + 0x10);
      uVar9 = *(uint *)(userKey + 0x14);
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      key->rd_key[4] =
           uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18
      ;
      key->rd_key[5] = uVar9;
      if (bits == 0xc0) {
        key->rounds = 0xc;
        iVar14 = 8;
        puVar7 = &DAT_0007e9e0;
        puVar8 = key->rd_key + 6;
        while( true ) {
          uVar3 = uVar3 ^ ((uint)(byte)(&DAT_0007e8e0)[uVar9 >> 0x18] |
                           (uint)(byte)(&DAT_0007e8e0)[uVar9 >> 0x10 & 0xff] << 0x18 |
                           (uint)(byte)(&DAT_0007e8e0)[uVar9 >> 8 & 0xff] << 0x10 |
                          (uint)(byte)(&DAT_0007e8e0)[uVar9 & 0xff] << 8) ^ *puVar7;
          uVar2 = uVar2 ^ uVar3;
          *puVar8 = uVar3;
          uVar4 = uVar4 ^ uVar2;
          puVar8[1] = uVar2;
          uVar5 = uVar5 ^ uVar4;
          puVar8[2] = uVar4;
          iVar14 = iVar14 + -1;
          puVar8[3] = uVar5;
          if (iVar14 == 0) break;
          uVar9 = puVar8[-1] ^ puVar8[-2] ^ uVar5;
          puVar8[4] = puVar8[-2] ^ uVar5;
          puVar8[5] = uVar9;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 6;
        }
        key = (AES_KEY *)(puVar8 + -0x30);
      }
      else {
        uVar6 = *(uint *)(userKey + 0x18);
        uVar9 = *(uint *)(userKey + 0x1c);
        uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                uVar9 >> 0x18;
        puVar7 = key->rd_key;
        key->rd_key[6] =
             uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
             uVar6 >> 0x18;
        key->rd_key[7] = uVar9;
        key->rounds = 0xe;
        iVar14 = 7;
        puVar8 = &DAT_0007e9e0;
        while( true ) {
          puVar7 = puVar7 + 8;
          uVar3 = uVar3 ^ ((uint)(byte)(&DAT_0007e8e0)[uVar9 >> 0x18] |
                           (uint)(byte)(&DAT_0007e8e0)[uVar9 >> 0x10 & 0xff] << 0x18 |
                           (uint)(byte)(&DAT_0007e8e0)[uVar9 >> 8 & 0xff] << 0x10 |
                          (uint)(byte)(&DAT_0007e8e0)[uVar9 & 0xff] << 8) ^ *puVar8;
          uVar2 = uVar2 ^ uVar3;
          *puVar7 = uVar3;
          uVar4 = uVar4 ^ uVar2;
          puVar7[1] = uVar2;
          uVar5 = uVar5 ^ uVar4;
          puVar7[2] = uVar4;
          iVar14 = iVar14 + -1;
          puVar7[3] = uVar5;
          if (iVar14 == 0) break;
          uVar6 = puVar7[-4] ^
                  CONCAT13((&DAT_0007e8e0)[uVar5 >> 0x18],
                           CONCAT12((&DAT_0007e8e0)[uVar5 >> 0x10 & 0xff],
                                    CONCAT11((&DAT_0007e8e0)[uVar5 >> 8 & 0xff],
                                             (&DAT_0007e8e0)[uVar5 & 0xff])));
          uVar9 = puVar7[-3] ^ uVar6;
          puVar7[4] = uVar6;
          uVar6 = puVar7[-2] ^ uVar9;
          puVar7[5] = uVar9;
          uVar9 = puVar7[-1] ^ uVar6;
          puVar7[6] = uVar6;
          puVar7[7] = uVar9;
          puVar8 = puVar8 + 1;
        }
        key = (AES_KEY *)(puVar7 + -0x38);
      }
    }
    userKey_00 = (uchar *)0x0;
  }
  else {
    userKey_00 = (uchar *)0xffffffff;
  }
  do {
    if ((in_lr & 1) == 0) {
      return (int)userKey_00;
    }
    unaff_d14 = VectorRoundHalvingAdd(unaff_d14,in_d31,2,1);
    userKey_00 = (uchar *)private_AES_set_encrypt_key(userKey_00,uVar2,key);
    uVar2 = extraout_r1;
  } while (userKey_00 != (uchar *)0x0);
  iVar14 = key->rounds;
  pAVar10 = key;
  pAVar11 = (AES_KEY *)(key->rd_key + iVar14 * 4);
  do {
    uVar2 = pAVar10->rd_key[1];
    uVar3 = pAVar10->rd_key[2];
    uVar4 = pAVar10->rd_key[3];
    uVar5 = pAVar11->rd_key[0];
    uVar6 = pAVar11->rd_key[1];
    uVar9 = pAVar11->rd_key[2];
    uVar12 = pAVar11->rd_key[3];
    pAVar1 = pAVar11 + -1;
    pAVar11->rd_key[0] = pAVar10->rd_key[0];
    pAVar11->rd_key[1] = uVar2;
    pAVar11->rd_key[2] = uVar3;
    pAVar11->rd_key[3] = uVar4;
    puVar7 = pAVar10->rd_key;
    pAVar10->rd_key[0] = uVar5;
    pAVar10->rd_key[1] = uVar6;
    pAVar10->rd_key[2] = uVar9;
    pAVar10->rd_key[3] = uVar12;
    pAVar10 = (AES_KEY *)(puVar7 + 4);
    pAVar11 = (AES_KEY *)(pAVar1->rd_key + 0x39);
  } while ((AES_KEY *)(puVar7 + 4) != (AES_KEY *)(pAVar1->rd_key + 0x39));
  uVar2 = key->rd_key[4];
  iVar14 = (iVar14 + -1) * 4;
  puVar7 = key->rd_key + 4;
  do {
    uVar3 = (uVar2 & 0x80808080) - ((uVar2 & 0x80808080) >> 7) & 0x1b1b1b1b ^
            (uVar2 & 0x7f7f7f7f) << 1;
    uVar4 = (uVar3 & 0x80808080) - ((uVar3 & 0x80808080) >> 7) & 0x1b1b1b1b ^
            (uVar3 & 0x7f7f7f7f) << 1;
    uVar5 = (uVar4 & 0x80808080) - ((uVar4 & 0x80808080) >> 7) & 0x1b1b1b1b ^
            (uVar4 & 0x7f7f7f7f) << 1;
    uVar6 = uVar2 ^ uVar5;
    uVar2 = puVar7[1];
    *puVar7 = uVar3 ^ uVar4 ^ uVar5 ^ (uVar3 >> 0x18 | uVar3 << 8) ^ (uVar6 >> 0x18 | uVar6 << 8) ^
              (uVar4 >> 0x10 | uVar4 << 0x10) ^ (uVar6 >> 0x10 | uVar6 << 0x10) ^
              (uVar6 >> 8 | uVar6 << 0x18);
    iVar14 = iVar14 + -1;
    puVar7 = puVar7 + 1;
  } while (iVar14 != 0);
  return 0;
}

