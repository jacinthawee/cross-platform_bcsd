
int private_AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  AES_KEY *pAVar7;
  AES_KEY *pAVar8;
  int iVar9;
  
  iVar5 = private_AES_set_encrypt_key(userKey,bits,key);
  if (-1 < iVar5) {
    iVar5 = key->rounds;
    if (0 < iVar5 * 4) {
      iVar9 = 0;
      puVar6 = key->rd_key + iVar5 * 4;
      pAVar7 = key;
      do {
        uVar3 = pAVar7->rd_key[0];
        iVar9 = iVar9 + 4;
        pAVar7->rd_key[0] = *puVar6;
        *puVar6 = uVar3;
        uVar3 = pAVar7->rd_key[1];
        pAVar7->rd_key[1] = puVar6[1];
        puVar6[1] = uVar3;
        uVar3 = pAVar7->rd_key[2];
        pAVar7->rd_key[2] = puVar6[2];
        puVar6[2] = uVar3;
        uVar3 = pAVar7->rd_key[3];
        pAVar7->rd_key[3] = puVar6[3];
        puVar6[3] = uVar3;
        puVar6 = puVar6 + -4;
        pAVar7 = (AES_KEY *)(pAVar7->rd_key + 4);
      } while (iVar9 < iVar5 * 4 - iVar9);
      iVar5 = key->rounds;
    }
    iVar9 = 1;
    pAVar7 = key;
    if (1 < iVar5) {
      do {
        pAVar8 = (AES_KEY *)(pAVar7->rd_key + 4);
        uVar3 = pAVar8->rd_key[0];
        iVar9 = iVar9 + 1;
        uVar4 = pAVar7->rd_key[5];
        bVar1 = Te1[(uVar4 >> 0x18) * 4];
        pAVar8->rd_key[0] =
             *(uint *)(Td0 + (uint)(byte)Te1[(uVar3 >> 0x18) * 4] * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar3 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[(uVar3 >> 0x10 & 0xff) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[(uVar3 >> 8 & 0xff) * 4] * 4);
        uVar3 = pAVar7->rd_key[6];
        bVar2 = Te1[(uVar3 >> 0x18) * 4];
        pAVar7->rd_key[5] =
             *(uint *)(Td0 + (uint)bVar1 * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar4 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[(uVar4 >> 0x10 & 0xff) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[(uVar4 >> 8 & 0xff) * 4] * 4);
        uVar4 = pAVar7->rd_key[7];
        bVar1 = Te1[(uVar4 >> 0x18) * 4];
        pAVar7->rd_key[6] =
             *(uint *)(Td0 + (uint)bVar2 * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar3 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[(uVar3 >> 0x10 & 0xff) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[(uVar3 >> 8 & 0xff) * 4] * 4);
        pAVar7->rd_key[7] =
             *(uint *)(Td0 + (uint)bVar1 * 4) ^
             *(uint *)(Td3 + (uint)(byte)Te1[(uVar4 & 0xff) * 4] * 4) ^
             *(uint *)(Td1 + (uint)(byte)Te1[(uVar4 >> 0x10 & 0xff) * 4] * 4) ^
             *(uint *)(Td2 + (uint)(byte)Te1[(uVar4 >> 8 & 0xff) * 4] * 4);
        pAVar7 = pAVar8;
      } while (key->rounds != iVar9 && iVar9 <= key->rounds);
    }
    iVar5 = 0;
  }
  return iVar5;
}

