
undefined4
padlock_aes_init_key(EVP_CIPHER_CTX *param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  bool bVar14;
  byte bVar15;
  
  bVar15 = 0;
  iVar6 = EVP_CIPHER_CTX_key_length(param_1);
  iVar6 = iVar6 * 8;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  puVar11 = (undefined4 *)((-(int)param_1->cipher_data & 0xfU) + (int)param_1->cipher_data);
  *puVar11 = 0;
  puVar11[0x44] = 0;
  puVar12 = (undefined4 *)((uint)(puVar11 + 1) & 0xfffffffc);
  for (uVar9 = (uint)((int)puVar11 + (0x114 - (int)(undefined4 *)((uint)(puVar11 + 1) & 0xfffffffc))
                     ) >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + (uint)bVar15 * -2 + 1;
  }
  uVar7 = EVP_CIPHER_CTX_flags(param_1);
  bVar14 = false;
  if ((uVar7 & 0xf0007) != 4) {
    bVar14 = param_1->encrypt == 0;
  }
  iVar13 = iVar6 + -0x80;
  bVar15 = *(byte *)(puVar11 + 4);
  iVar8 = iVar6 + -0x61;
  if (-1 < iVar13) {
    iVar8 = iVar13;
  }
  bVar5 = (char)(iVar8 >> 5) + 10U & 0xf;
  *(byte *)(puVar11 + 4) = bVar5 | bVar15 & 0xf0;
  iVar8 = iVar6 + -0x41;
  if (-1 < iVar13) {
    iVar8 = iVar13;
  }
  *(byte *)((int)puVar11 + 0x11) =
       (byte)((iVar8 >> 6 & 3U) << 2) | *(byte *)((int)puVar11 + 0x11) & 0xf1 | bVar14 * '\x02';
  if ((iVar6 == 0xc0) || (iVar6 == 0x100)) {
    uVar7 = EVP_CIPHER_CTX_flags(param_1);
    if (((uVar7 & 0xf0007) == 3) ||
       ((uVar7 = EVP_CIPHER_CTX_flags(param_1), (uVar7 & 0xf0007) == 4 || (param_4 != 0)))) {
      AES_set_encrypt_key((uchar *)param_2,iVar6,(AES_KEY *)(puVar11 + 8));
    }
    else {
      AES_set_decrypt_key((uchar *)param_2,iVar6,(AES_KEY *)(puVar11 + 8));
    }
    puVar10 = puVar11 + 8;
    do {
      uVar9 = *puVar10;
      *puVar10 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
      puVar10 = puVar10 + 1;
    } while (puVar10 != puVar11 + 0x44);
    *(byte *)(puVar11 + 4) = *(byte *)(puVar11 + 4) | 0x80;
  }
  else {
    if (iVar6 != 0x80) {
      return 0;
    }
    uVar1 = *param_2;
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    *(byte *)(puVar11 + 4) = bVar5 | bVar15 & 0x70;
    puVar11[8] = uVar1;
    puVar11[9] = uVar2;
    puVar11[10] = uVar3;
    puVar11[0xb] = uVar4;
  }
  return 1;
}

