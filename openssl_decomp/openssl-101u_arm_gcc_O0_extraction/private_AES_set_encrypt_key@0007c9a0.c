
int private_AES_set_encrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint in_lr;
  
  if (userKey == (uchar *)0x0) {
    iVar1 = -1;
  }
  else if (key == (AES_KEY *)0x0) {
    iVar1 = -1;
  }
  else if (((bits == 0x80) || (bits == 0xc0)) || (bits == 0x100)) {
    uVar2 = *(uint *)userKey;
    uVar3 = *(uint *)(userKey + 4);
    uVar4 = *(uint *)(userKey + 8);
    uVar5 = *(uint *)(userKey + 0xc);
    uVar2 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
            uVar2 >> 0x18;
    uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18;
    uVar4 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
            uVar4 >> 0x18;
    uVar5 = uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18;
    key->rd_key[0] = uVar2;
    key->rd_key[1] = uVar3;
    key->rd_key[2] = uVar4;
    key->rd_key[3] = uVar5;
    if (bits == 0x80) {
      iVar1 = 10;
      key->rounds = 10;
      puVar6 = &DAT_0007c720;
      puVar7 = key->rd_key + 4;
      do {
        uVar2 = uVar2 ^ ((uint)(byte)(&DAT_0007c620)[uVar5 >> 0x18] |
                         (uint)(byte)(&DAT_0007c620)[uVar5 >> 0x10 & 0xff] << 0x18 |
                         (uint)(byte)(&DAT_0007c620)[uVar5 >> 8 & 0xff] << 0x10 |
                        (uint)(byte)(&DAT_0007c620)[uVar5 & 0xff] << 8) ^ *puVar6;
        uVar3 = uVar3 ^ uVar2;
        *puVar7 = uVar2;
        uVar4 = uVar4 ^ uVar3;
        puVar7[1] = uVar3;
        uVar5 = uVar5 ^ uVar4;
        puVar7[2] = uVar4;
        iVar1 = iVar1 + -1;
        puVar7[3] = uVar5;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 4;
      } while (iVar1 != 0);
    }
    else {
      uVar8 = *(uint *)(userKey + 0x10);
      uVar9 = *(uint *)(userKey + 0x14);
      uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
              uVar9 >> 0x18;
      key->rd_key[4] =
           uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 | uVar8 >> 0x18
      ;
      key->rd_key[5] = uVar9;
      if (bits == 0xc0) {
        key->rounds = 0xc;
        iVar1 = 8;
        puVar6 = &DAT_0007c720;
        puVar7 = key->rd_key + 6;
        while( true ) {
          uVar2 = uVar2 ^ ((uint)(byte)(&DAT_0007c620)[uVar9 >> 0x18] |
                           (uint)(byte)(&DAT_0007c620)[uVar9 >> 0x10 & 0xff] << 0x18 |
                           (uint)(byte)(&DAT_0007c620)[uVar9 >> 8 & 0xff] << 0x10 |
                          (uint)(byte)(&DAT_0007c620)[uVar9 & 0xff] << 8) ^ *puVar6;
          uVar3 = uVar3 ^ uVar2;
          *puVar7 = uVar2;
          uVar4 = uVar4 ^ uVar3;
          puVar7[1] = uVar3;
          uVar5 = uVar5 ^ uVar4;
          puVar7[2] = uVar4;
          iVar1 = iVar1 + -1;
          puVar7[3] = uVar5;
          if (iVar1 == 0) break;
          uVar9 = puVar7[-1] ^ puVar7[-2] ^ uVar5;
          puVar7[4] = puVar7[-2] ^ uVar5;
          puVar7[5] = uVar9;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 6;
        }
      }
      else {
        uVar8 = *(uint *)(userKey + 0x18);
        uVar9 = *(uint *)(userKey + 0x1c);
        uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
                uVar9 >> 0x18;
        puVar6 = key->rd_key;
        key->rd_key[6] =
             uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
             uVar8 >> 0x18;
        key->rd_key[7] = uVar9;
        key->rounds = 0xe;
        iVar1 = 7;
        puVar7 = &DAT_0007c720;
        while( true ) {
          puVar6 = puVar6 + 8;
          uVar2 = uVar2 ^ ((uint)(byte)(&DAT_0007c620)[uVar9 >> 0x18] |
                           (uint)(byte)(&DAT_0007c620)[uVar9 >> 0x10 & 0xff] << 0x18 |
                           (uint)(byte)(&DAT_0007c620)[uVar9 >> 8 & 0xff] << 0x10 |
                          (uint)(byte)(&DAT_0007c620)[uVar9 & 0xff] << 8) ^ *puVar7;
          uVar3 = uVar3 ^ uVar2;
          *puVar6 = uVar2;
          uVar4 = uVar4 ^ uVar3;
          puVar6[1] = uVar3;
          uVar5 = uVar5 ^ uVar4;
          puVar6[2] = uVar4;
          iVar1 = iVar1 + -1;
          puVar6[3] = uVar5;
          if (iVar1 == 0) break;
          uVar8 = puVar6[-4] ^
                  CONCAT13((&DAT_0007c620)[uVar5 >> 0x18],
                           CONCAT12((&DAT_0007c620)[uVar5 >> 0x10 & 0xff],
                                    CONCAT11((&DAT_0007c620)[uVar5 >> 8 & 0xff],
                                             (&DAT_0007c620)[uVar5 & 0xff])));
          uVar9 = puVar6[-3] ^ uVar8;
          puVar6[4] = uVar8;
          uVar8 = puVar6[-2] ^ uVar9;
          puVar6[5] = uVar9;
          uVar9 = puVar6[-1] ^ uVar8;
          puVar6[6] = uVar8;
          puVar6[7] = uVar9;
          puVar7 = puVar7 + 1;
        }
      }
    }
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  if ((in_lr & 1) == 0) {
    return iVar1;
  }
  return iVar1;
}

