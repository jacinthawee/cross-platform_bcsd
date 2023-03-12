
int AES_set_encrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  AES_KEY *pAVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  
  if (userKey == (uchar *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = -1;
    if (key != (AES_KEY *)0x0) {
      if (bits == 0x80) {
        key->rounds = 10;
      }
      else if (bits == 0xc0) {
        key->rounds = 0xc;
      }
      else {
        if (bits != 0x100) {
          return -2;
        }
        key->rounds = 0xe;
      }
      uVar4 = (uint)*userKey << 0x18 ^ (uint)userKey[1] << 0x10 ^ (uint)userKey[3] ^
              (uint)userKey[2] << 8;
      key->rd_key[0] = uVar4;
      uVar10 = (uint)userKey[4] << 0x18 ^ (uint)userKey[5] << 0x10 ^ (uint)userKey[7] ^
               (uint)userKey[6] << 8;
      key->rd_key[1] = uVar10;
      uVar8 = (uint)userKey[8] << 0x18 ^ (uint)userKey[9] << 0x10 ^ (uint)userKey[0xb] ^
              (uint)userKey[10] << 8;
      key->rd_key[2] = uVar8;
      bVar1 = userKey[0xc];
      uVar3 = (uint)bVar1 << 0x18 ^ (uint)userKey[0xd] << 0x10 ^ (uint)userKey[0xf] ^
              (uint)userKey[0xe] << 8;
      key->rd_key[3] = uVar3;
      if (bits == 0x80) {
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x1000000 ^
                (uint)(byte)Te1[(uint)bVar1 * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar4 ^ uVar10;
        uVar8 = uVar10 ^ uVar8;
        key->rd_key[4] = uVar4;
        uVar3 = uVar8 ^ uVar3;
        key->rd_key[5] = uVar10;
        key->rd_key[6] = uVar8;
        key->rd_key[7] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x2000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar4 ^ uVar10;
        uVar8 = uVar10 ^ uVar8;
        key->rd_key[8] = uVar4;
        uVar3 = uVar8 ^ uVar3;
        key->rd_key[9] = uVar10;
        key->rd_key[10] = uVar8;
        key->rd_key[0xb] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x4000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar4 ^ uVar10;
        uVar8 = uVar10 ^ uVar8;
        key->rd_key[0xc] = uVar4;
        uVar3 = uVar8 ^ uVar3;
        key->rd_key[0xd] = uVar10;
        key->rd_key[0xe] = uVar8;
        key->rd_key[0xf] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x8000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar4 ^ uVar10;
        uVar8 = uVar10 ^ uVar8;
        key->rd_key[0x10] = uVar4;
        uVar3 = uVar8 ^ uVar3;
        key->rd_key[0x11] = uVar10;
        key->rd_key[0x12] = uVar8;
        key->rd_key[0x13] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x10000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar4 ^ uVar10;
        uVar8 = uVar10 ^ uVar8;
        key->rd_key[0x14] = uVar4;
        uVar3 = uVar8 ^ uVar3;
        key->rd_key[0x15] = uVar10;
        key->rd_key[0x16] = uVar8;
        key->rd_key[0x17] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x20000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar10 ^ uVar4;
        uVar8 = uVar8 ^ uVar10;
        key->rd_key[0x18] = uVar4;
        uVar3 = uVar3 ^ uVar8;
        key->rd_key[0x19] = uVar10;
        key->rd_key[0x1a] = uVar8;
        key->rd_key[0x1b] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x40000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar10 ^ uVar4;
        uVar8 = uVar8 ^ uVar10;
        key->rd_key[0x1c] = uVar4;
        uVar3 = uVar3 ^ uVar8;
        key->rd_key[0x1d] = uVar10;
        key->rd_key[0x1e] = uVar8;
        key->rd_key[0x1f] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x80000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar10 ^ uVar4;
        uVar8 = uVar8 ^ uVar10;
        key->rd_key[0x20] = uVar4;
        uVar3 = uVar3 ^ uVar8;
        key->rd_key[0x21] = uVar10;
        key->rd_key[0x22] = uVar8;
        key->rd_key[0x23] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x1b000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar10 ^ uVar4;
        uVar8 = uVar8 ^ uVar10;
        key->rd_key[0x24] = uVar4;
        uVar3 = uVar3 ^ uVar8;
        key->rd_key[0x25] = uVar10;
        key->rd_key[0x26] = uVar8;
        key->rd_key[0x27] = uVar3;
        uVar4 = *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x36000000 ^
                (uint)(byte)Te1[(uVar3 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar3 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar10 = uVar4 ^ uVar10;
        uVar8 = uVar10 ^ uVar8;
        key->rd_key[0x28] = uVar4;
        key->rd_key[0x29] = uVar10;
        key->rd_key[0x2a] = uVar8;
        key->rd_key[0x2b] = uVar8 ^ uVar3;
      }
      else {
        uVar12 = (uint)userKey[0x10] << 0x18 ^ (uint)userKey[0x11] << 0x10 ^ (uint)userKey[0x13] ^
                 (uint)userKey[0x12] << 8;
        key->rd_key[4] = uVar12;
        bVar1 = userKey[0x14];
        uVar7 = (uint)bVar1 << 0x18 ^ (uint)userKey[0x15] << 0x10 ^ (uint)userKey[0x17] ^
                (uint)userKey[0x16] << 8;
        key->rd_key[5] = uVar7;
        if (bits == 0xc0) {
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^ uVar4 ^ 0x1000000 ^
                  (uint)(byte)Te1[(uint)bVar1 * 4 + 3] ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[6] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[7] = uVar10;
          uVar12 = uVar3 ^ uVar12;
          key->rd_key[8] = uVar8;
          uVar7 = uVar7 ^ uVar12;
          key->rd_key[9] = uVar3;
          key->rd_key[10] = uVar12;
          key->rd_key[0xb] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x2000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[0xc] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[0xd] = uVar10;
          uVar12 = uVar3 ^ uVar12;
          key->rd_key[0xe] = uVar8;
          uVar7 = uVar7 ^ uVar12;
          key->rd_key[0xf] = uVar3;
          key->rd_key[0x10] = uVar12;
          key->rd_key[0x11] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x4000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[0x12] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[0x13] = uVar10;
          uVar12 = uVar3 ^ uVar12;
          key->rd_key[0x14] = uVar8;
          uVar7 = uVar7 ^ uVar12;
          key->rd_key[0x15] = uVar3;
          key->rd_key[0x16] = uVar12;
          key->rd_key[0x17] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x8000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[0x18] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[0x19] = uVar10;
          uVar12 = uVar3 ^ uVar12;
          key->rd_key[0x1a] = uVar8;
          uVar7 = uVar7 ^ uVar12;
          key->rd_key[0x1b] = uVar3;
          key->rd_key[0x1c] = uVar12;
          key->rd_key[0x1d] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x10000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[0x1e] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[0x1f] = uVar10;
          uVar12 = uVar3 ^ uVar12;
          key->rd_key[0x20] = uVar8;
          uVar7 = uVar7 ^ uVar12;
          key->rd_key[0x21] = uVar3;
          key->rd_key[0x22] = uVar12;
          key->rd_key[0x23] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x20000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[0x24] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[0x25] = uVar10;
          uVar12 = uVar3 ^ uVar12;
          key->rd_key[0x26] = uVar8;
          uVar7 = uVar7 ^ uVar12;
          key->rd_key[0x27] = uVar3;
          key->rd_key[0x28] = uVar12;
          key->rd_key[0x29] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x40000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar10 ^ uVar4;
          uVar8 = uVar8 ^ uVar10;
          key->rd_key[0x2a] = uVar4;
          uVar3 = uVar3 ^ uVar8;
          key->rd_key[0x2b] = uVar10;
          key->rd_key[0x2c] = uVar8;
          uVar7 = uVar7 ^ uVar3 ^ uVar12;
          key->rd_key[0x2d] = uVar3;
          key->rd_key[0x2e] = uVar3 ^ uVar12;
          key->rd_key[0x2f] = uVar7;
          uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^ 0x80000000 ^
                  *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar4;
          uVar10 = uVar4 ^ uVar10;
          uVar8 = uVar10 ^ uVar8;
          key->rd_key[0x30] = uVar4;
          key->rd_key[0x31] = uVar10;
          key->rd_key[0x32] = uVar8;
          key->rd_key[0x33] = uVar8 ^ uVar3;
        }
        else {
          key->rd_key[6] =
               (uint)userKey[0x18] << 0x18 ^ (uint)userKey[0x19] << 0x10 ^ (uint)userKey[0x1b] ^
               (uint)userKey[0x1a] << 8;
          key->rd_key[7] =
               (uint)userKey[0x1c] << 0x18 ^ (uint)userKey[0x1d] << 0x10 ^ (uint)userKey[0x1f] ^
               (uint)userKey[0x1e] << 8;
          if (bits == 0x100) {
            pAVar9 = key;
            puVar11 = (uint *)rcon;
            while( true ) {
              uVar7 = pAVar9->rd_key[7];
              uVar4 = *(uint *)(Te0 + (uVar7 & 0xff) * 4) & 0xff00 ^ uVar4 ^ *puVar11 ^
                      (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] ^
                      *(uint *)(Te2 + ((uVar7 << 8) >> 0x18) * 4) & 0xff000000 ^
                      *(uint *)(Te3 + ((uVar7 << 0x10) >> 0x18) * 4) & 0xff0000;
              uVar10 = uVar10 ^ uVar4;
              uVar8 = uVar8 ^ uVar10;
              pAVar9->rd_key[8] = uVar4;
              uVar3 = uVar3 ^ uVar8;
              pAVar9->rd_key[9] = uVar10;
              pAVar9->rd_key[10] = uVar8;
              pAVar9->rd_key[0xb] = uVar3;
              if (pAVar9 == (AES_KEY *)(key->rd_key + 0x30)) break;
              uVar6 = *(uint *)(Te2 + (uVar3 >> 0x18) * 4) & 0xff000000 ^
                      (uint)(byte)Te1[(uVar3 & 0xff) * 4 + 3] ^ pAVar9->rd_key[4] ^
                      *(uint *)(Te3 + ((uVar3 << 8) >> 0x18) * 4) & 0xff0000 ^
                      *(uint *)(Te0 + ((uVar3 << 0x10) >> 0x18) * 4) & 0xff00;
              uVar5 = uVar6 ^ pAVar9->rd_key[5];
              uVar12 = uVar5 ^ pAVar9->rd_key[6];
              pAVar9->rd_key[0xc] = uVar6;
              pAVar9->rd_key[0xd] = uVar5;
              pAVar9->rd_key[0xe] = uVar12;
              pAVar9->rd_key[0xf] = uVar7 ^ uVar12;
              pAVar9 = (AES_KEY *)(pAVar9->rd_key + 8);
              puVar11 = puVar11 + 1;
            }
            return 0;
          }
        }
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}

