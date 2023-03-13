
int AES_set_encrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iStack_1c;
  uint uStack_18;
  
  if ((userKey == (uchar *)0x0) || (key == (AES_KEY *)0x0)) {
    return -1;
  }
  if ((bits & 0xffffffbfU) == 0x80) {
    if (bits == 0x80) {
      key->rounds = 10;
      goto LAB_080e5d87;
    }
    if (bits == 0xc0) {
      key->rounds = 0xc;
      goto LAB_080e5d87;
    }
  }
  else if (bits != 0x100) {
    return -2;
  }
  key->rounds = 0xe;
LAB_080e5d87:
  uVar4 = (uint)userKey[1] << 0x10 ^ (uint)*userKey << 0x18 ^ (uint)userKey[3] ^
          (uint)userKey[2] << 8;
  key->rd_key[0] = uVar4;
  uVar5 = (uint)userKey[4] << 0x18 ^ (uint)userKey[5] << 0x10 ^ (uint)userKey[7] ^
          (uint)userKey[6] << 8;
  key->rd_key[1] = uVar5;
  uStack_18 = (uint)userKey[9] << 0x10 ^ (uint)userKey[8] << 0x18 ^ (uint)userKey[0xb] ^
              (uint)userKey[10] << 8;
  key->rd_key[2] = uStack_18;
  bVar1 = userKey[0xc];
  uVar2 = (uint)userKey[0xd] << 0x10 ^ (uint)bVar1 << 0x18;
  uVar3 = uVar2 ^ userKey[0xf] ^ (uint)userKey[0xe] << 8;
  key->rd_key[3] = uVar3;
  if (bits == 0x80) {
    uVar2 = *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000 ^
            uVar4 ^ 0x1000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uint)bVar1 * 4] ^
            *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[4] = uVar2;
    key->rd_key[5] = uVar5;
    uStack_18 = uStack_18 ^ uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[6] = uStack_18;
    key->rd_key[7] = uVar3;
    uVar2 = uVar2 ^ 0x2000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[8] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[9] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[10] = uStack_18;
    key->rd_key[0xb] = uVar3;
    uVar2 = uVar2 ^ 0x4000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0xc] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0xd] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0xe] = uStack_18;
    key->rd_key[0xf] = uVar3;
    uVar2 = uVar2 ^ 0x8000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x10] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x11] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0x12] = uStack_18;
    key->rd_key[0x13] = uVar3;
    uVar2 = uVar2 ^ 0x10000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x14] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x15] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0x16] = uStack_18;
    key->rd_key[0x17] = uVar3;
    uVar2 = uVar2 ^ 0x20000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x18] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x19] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0x1a] = uStack_18;
    key->rd_key[0x1b] = uVar3;
    uVar2 = uVar2 ^ 0x40000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x1c] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x1d] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0x1e] = uStack_18;
    key->rd_key[0x1f] = uVar3;
    uVar2 = uVar2 + 0x80000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x20] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x21] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0x22] = uStack_18;
    key->rd_key[0x23] = uVar3;
    uVar2 = *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000 ^
            uVar2 ^ 0x1b000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x24] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x25] = uVar5;
    uVar3 = uVar3 ^ uStack_18;
    key->rd_key[0x26] = uStack_18;
    key->rd_key[0x27] = uVar3;
    uVar2 = uVar2 ^ 0x36000000 ^ *(uint *)(Te0 + (uVar3 & 0xff) * 4) & 0xff00 ^
            (uint)(byte)Te1[(uVar3 >> 0x18) * 4] ^
            *(uint *)(Te2 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff000000 ^
            *(uint *)(Te3 + (uVar3 >> 8 & 0xff) * 4) & 0xff0000;
    uVar5 = uVar5 ^ uVar2;
    key->rd_key[0x28] = uVar2;
    uStack_18 = uStack_18 ^ uVar5;
    key->rd_key[0x29] = uVar5;
    key->rd_key[0x2a] = uStack_18;
    key->rd_key[0x2b] = uVar3 ^ uStack_18;
  }
  else {
    key->rd_key[4] =
         (uint)userKey[0x12] << 8 ^
         (uint)userKey[0x10] << 0x18 ^ (uint)userKey[0x11] << 0x10 ^ (uint)userKey[0x13];
    bVar1 = userKey[0x14];
    uVar6 = (uint)bVar1 << 0x18 ^ (uint)userKey[0x15] << 0x10;
    uVar2 = (uint)userKey[0x16] << 8 ^ uVar6 ^ userKey[0x17];
    key->rd_key[5] = uVar2;
    if (bits == 0xc0) {
      uVar4 = *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
              uVar4 ^ 0x1000000 ^ *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^
              (uint)(byte)Te1[(uint)bVar1 * 4] ^
              *(uint *)(Te2 + (uVar6 >> 0x10 & 0xff) * 4) & 0xff000000;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[6] = uVar4;
      key->rd_key[7] = uVar5;
      uStack_18 = uStack_18 ^ uVar5;
      uVar3 = uVar3 ^ uStack_18;
      key->rd_key[8] = uStack_18;
      uVar6 = key->rd_key[4] ^ uVar3;
      key->rd_key[9] = uVar3;
      uVar2 = uVar2 ^ uVar6;
      key->rd_key[10] = uVar6;
      key->rd_key[0xb] = uVar2;
      uVar4 = *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
              *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
              (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^ *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^
              0x2000000 ^ uVar4;
      key->rd_key[0xc] = uVar4;
      uVar5 = uVar5 ^ uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0xd] = uVar5;
      uVar3 = uVar3 ^ uStack_18;
      key->rd_key[0xe] = uStack_18;
      uVar6 = uVar6 ^ uVar3;
      key->rd_key[0xf] = uVar3;
      uVar2 = uVar2 ^ uVar6;
      key->rd_key[0x10] = uVar6;
      key->rd_key[0x11] = uVar2;
      uVar4 = uVar4 ^ *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
                      *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
                      (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
                      *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ 0x4000000;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[0x12] = uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0x13] = uVar5;
      uVar3 = uVar3 ^ uStack_18;
      key->rd_key[0x14] = uStack_18;
      uVar6 = uVar6 ^ uVar3;
      key->rd_key[0x15] = uVar3;
      uVar2 = uVar2 ^ uVar6;
      key->rd_key[0x16] = uVar6;
      key->rd_key[0x17] = uVar2;
      uVar4 = *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
              *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
              (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^ *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^
              0x8000000 ^ uVar4;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[0x18] = uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0x19] = uVar5;
      uVar3 = uVar3 ^ uStack_18;
      key->rd_key[0x1a] = uStack_18;
      uVar6 = uVar6 ^ uVar3;
      key->rd_key[0x1b] = uVar3;
      uVar2 = uVar2 ^ uVar6;
      key->rd_key[0x1c] = uVar6;
      key->rd_key[0x1d] = uVar2;
      uVar4 = *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
              *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
              (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^ *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^
              0x10000000 ^ uVar4;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[0x1e] = uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0x1f] = uVar5;
      uVar3 = uVar3 ^ uStack_18;
      key->rd_key[0x20] = uStack_18;
      uVar6 = uVar6 ^ uVar3;
      key->rd_key[0x21] = uVar3;
      uVar2 = uVar2 ^ uVar6;
      key->rd_key[0x22] = uVar6;
      key->rd_key[0x23] = uVar2;
      uVar4 = uVar4 ^ *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
                      *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
                      (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
                      *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^ 0x20000000;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[0x24] = uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0x25] = uVar5;
      key->rd_key[0x26] = uStack_18;
      uVar3 = uVar3 ^ uStack_18;
      uVar6 = uVar6 ^ uVar3;
      key->rd_key[0x27] = uVar3;
      uVar2 = uVar2 ^ uVar6;
      key->rd_key[0x28] = uVar6;
      key->rd_key[0x29] = uVar2;
      uVar4 = *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
              (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^ *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00 ^
              0x40000000 ^ *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^ uVar4;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[0x2a] = uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0x2b] = uVar5;
      key->rd_key[0x2c] = uStack_18;
      uVar3 = uVar3 ^ uStack_18;
      key->rd_key[0x2d] = uVar3;
      uVar2 = uVar2 ^ uVar6 ^ uVar3;
      key->rd_key[0x2e] = uVar6 ^ uVar3;
      key->rd_key[0x2f] = uVar2;
      uVar4 = uVar4 ^ *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000 ^
                      ((uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
                      *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00) + 0x80000000 ^
                      *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000;
      uVar5 = uVar5 ^ uVar4;
      key->rd_key[0x30] = uVar4;
      uStack_18 = uStack_18 ^ uVar5;
      key->rd_key[0x31] = uVar5;
      key->rd_key[0x32] = uStack_18;
      key->rd_key[0x33] = uStack_18 ^ uVar3;
    }
    else {
      key->rd_key[6] =
           (uint)userKey[0x1a] << 8 ^
           (uint)userKey[0x18] << 0x18 ^ (uint)userKey[0x19] << 0x10 ^ (uint)userKey[0x1b];
      key->rd_key[7] =
           (uint)userKey[0x1d] << 0x10 ^ (uint)userKey[0x1c] << 0x18 ^ (uint)userKey[0x1f] ^
           (uint)userKey[0x1e] << 8;
      if (bits == 0x100) {
        iStack_1c = 0;
        while( true ) {
          uVar2 = key->rd_key[7];
          uVar4 = *(uint *)(Te3 + (uVar2 >> 8 & 0xff) * 4) & 0xff0000 ^
                  uVar4 ^ *(uint *)(rcon + iStack_1c) ^ *(uint *)(Te0 + (uVar2 & 0xff) * 4) & 0xff00
                  ^ (uint)(byte)Te1[(uVar2 >> 0x18) * 4] ^
                  *(uint *)(Te2 + (uVar2 >> 0x10 & 0xff) * 4) & 0xff000000;
          uVar5 = uVar5 ^ uVar4;
          uStack_18 = uStack_18 ^ uVar5;
          ((AES_KEY *)(key->rd_key + 8))->rd_key[0] = uVar4;
          key->rd_key[9] = uVar5;
          uVar3 = uVar3 ^ uStack_18;
          key->rd_key[10] = uStack_18;
          key->rd_key[0xb] = uVar3;
          if (iStack_1c + 4 == 0x1c) break;
          uVar6 = *(uint *)(Te0 + (uVar3 >> 8 & 0xff) * 4) & 0xff00 ^
                  *(uint *)(Te3 + (uVar3 >> 0x10 & 0xff) * 4) & 0xff0000 ^
                  (uint)(byte)Te1[(uVar3 & 0xff) * 4] ^
                  *(uint *)(Te2 + (uVar3 >> 0x18) * 4) & 0xff000000 ^ key->rd_key[4];
          key->rd_key[0xc] = uVar6;
          uVar6 = uVar6 ^ key->rd_key[5];
          key->rd_key[0xd] = uVar6;
          uVar6 = uVar6 ^ key->rd_key[6];
          key->rd_key[0xe] = uVar6;
          key->rd_key[0xf] = uVar2 ^ uVar6;
          key = (AES_KEY *)(key->rd_key + 8);
          iStack_1c = iStack_1c + 4;
        }
      }
    }
  }
  return 0;
}

