
int private_AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  AES_KEY *pAVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  AES_KEY *pAVar9;
  AES_KEY *pAVar10;
  uint uVar11;
  uint *puVar12;
  uint in_lr;
  
  iVar2 = private_AES_set_encrypt_key(userKey,bits,key);
  if (iVar2 == 0) {
    iVar2 = key->rounds;
    pAVar9 = key;
    pAVar10 = (AES_KEY *)(key->rd_key + iVar2 * 4);
    do {
      uVar3 = pAVar9->rd_key[1];
      uVar4 = pAVar9->rd_key[2];
      uVar5 = pAVar9->rd_key[3];
      uVar6 = pAVar10->rd_key[0];
      uVar7 = pAVar10->rd_key[1];
      uVar8 = pAVar10->rd_key[2];
      uVar11 = pAVar10->rd_key[3];
      pAVar1 = pAVar10 + -1;
      pAVar10->rd_key[0] = pAVar9->rd_key[0];
      pAVar10->rd_key[1] = uVar3;
      pAVar10->rd_key[2] = uVar4;
      pAVar10->rd_key[3] = uVar5;
      puVar12 = pAVar9->rd_key;
      pAVar9->rd_key[0] = uVar6;
      pAVar9->rd_key[1] = uVar7;
      pAVar9->rd_key[2] = uVar8;
      pAVar9->rd_key[3] = uVar11;
      pAVar9 = (AES_KEY *)(puVar12 + 4);
      pAVar10 = (AES_KEY *)(pAVar1->rd_key + 0x39);
    } while ((AES_KEY *)(puVar12 + 4) != (AES_KEY *)(pAVar1->rd_key + 0x39));
    uVar3 = key->rd_key[4];
    iVar2 = (iVar2 + -1) * 4;
    puVar12 = key->rd_key + 4;
    do {
      uVar4 = (uVar3 & 0x80808080) - ((uVar3 & 0x80808080) >> 7) & 0x1b1b1b1b ^
              (uVar3 & 0x7f7f7f7f) << 1;
      uVar5 = (uVar4 & 0x80808080) - ((uVar4 & 0x80808080) >> 7) & 0x1b1b1b1b ^
              (uVar4 & 0x7f7f7f7f) << 1;
      uVar6 = (uVar5 & 0x80808080) - ((uVar5 & 0x80808080) >> 7) & 0x1b1b1b1b ^
              (uVar5 & 0x7f7f7f7f) << 1;
      uVar7 = uVar3 ^ uVar6;
      uVar3 = puVar12[1];
      *puVar12 = uVar4 ^ uVar5 ^ uVar6 ^ (uVar4 >> 0x18 | uVar4 << 8) ^ (uVar7 >> 0x18 | uVar7 << 8)
                 ^ (uVar5 >> 0x10 | uVar5 << 0x10) ^ (uVar7 >> 0x10 | uVar7 << 0x10) ^
                 (uVar7 >> 8 | uVar7 << 0x18);
      iVar2 = iVar2 + -1;
      puVar12 = puVar12 + 1;
    } while (iVar2 != 0);
    return 0;
  }
  if ((in_lr & 1) != 0) {
    return iVar2;
  }
  return iVar2;
}

