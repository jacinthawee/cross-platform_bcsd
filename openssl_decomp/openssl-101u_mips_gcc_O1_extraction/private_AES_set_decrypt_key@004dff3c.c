
int private_AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  AES_KEY *pAVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  
  iVar2 = private_AES_set_encrypt_key(userKey,bits,key);
  if (-1 < iVar2) {
    iVar2 = key->rounds;
    if (0 < iVar2 * 4) {
      iVar6 = 0;
      puVar3 = key->rd_key + iVar2 * 4;
      pAVar4 = key;
      do {
        uVar10 = pAVar4->rd_key[0];
        iVar6 = iVar6 + 4;
        pAVar4->rd_key[0] = *puVar3;
        *puVar3 = uVar10;
        uVar10 = pAVar4->rd_key[1];
        pAVar4->rd_key[1] = puVar3[1];
        puVar3[1] = uVar10;
        uVar10 = pAVar4->rd_key[2];
        pAVar4->rd_key[2] = puVar3[2];
        puVar3[2] = uVar10;
        uVar10 = pAVar4->rd_key[3];
        pAVar4->rd_key[3] = puVar3[3];
        puVar3[3] = uVar10;
        puVar3 = puVar3 + -4;
        pAVar4 = (AES_KEY *)(pAVar4->rd_key + 4);
      } while (iVar6 < iVar2 * 4 - iVar6);
      iVar2 = key->rounds;
    }
    if (1 < iVar2) {
      iVar2 = 1;
      puVar3 = key->rd_key;
      do {
        puVar3 = puVar3 + 4;
        uVar9 = *puVar3;
        uVar7 = puVar3[1];
        iVar2 = iVar2 + 1;
        uVar10 = puVar3[2];
        uVar12 = puVar3[3];
        uVar11 = *(uint *)(Td3 + (uint)(byte)Te1[(uVar9 & 0xff) * 4 + 3] * 4);
        uVar14 = *(uint *)(Td0 + (uint)(byte)Te1[(uVar10 >> 0x18) * 4 + 3] * 4);
        uVar8 = *(uint *)(Td3 + (uint)(byte)Te1[(uVar10 & 0xff) * 4 + 3] * 4);
        uVar5 = *(uint *)(Td1 + (uint)(byte)Te1[((uVar10 << 8) >> 0x18) * 4 + 3] * 4);
        uVar15 = *(uint *)(Td0 + (uint)(byte)Te1[(uVar9 >> 0x18) * 4 + 3] * 4);
        uVar13 = *(uint *)(Td1 + (uint)(byte)Te1[((uVar9 << 8) >> 0x18) * 4 + 3] * 4);
        uVar10 = *(uint *)(Td2 + (uint)(byte)Te1[((uVar10 << 0x10) >> 0x18) * 4 + 3] * 4);
        uVar9 = *(uint *)(Td2 + (uint)(byte)Te1[((uVar9 << 0x10) >> 0x18) * 4 + 3] * 4);
        bVar1 = Te1[(uVar12 >> 0x18) * 4 + 3];
        puVar3[1] = *(uint *)(Td0 + (uint)(byte)Te1[(uVar7 >> 0x18) * 4 + 3] * 4) ^
                    *(uint *)(Td3 + (uint)(byte)Te1[(uVar7 & 0xff) * 4 + 3] * 4) ^
                    *(uint *)(Td1 + (uint)(byte)Te1[((uVar7 << 8) >> 0x18) * 4 + 3] * 4) ^
                    *(uint *)(Td2 + (uint)(byte)Te1[((uVar7 << 0x10) >> 0x18) * 4 + 3] * 4);
        *puVar3 = uVar15 ^ uVar11 ^ uVar13 ^ uVar9;
        puVar3[2] = uVar14 ^ uVar8 ^ uVar5 ^ uVar10;
        puVar3[3] = *(uint *)(Td0 + (uint)bVar1 * 4) ^
                    *(uint *)(Td3 + (uint)(byte)Te1[(uVar12 & 0xff) * 4 + 3] * 4) ^
                    *(uint *)(Td1 + (uint)(byte)Te1[((uVar12 << 8) >> 0x18) * 4 + 3] * 4) ^
                    *(uint *)(Td2 + (uint)(byte)Te1[((uVar12 << 0x10) >> 0x18) * 4 + 3] * 4);
      } while (iVar2 < key->rounds);
    }
    iVar2 = 0;
  }
  return iVar2;
}

