
int __private_AES_set_decrypt_key_from_thumb(uchar *userKey,int bits,AES_KEY *key)

{
  AES_KEY *pAVar1;
  int extraout_r1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  AES_KEY *pAVar8;
  AES_KEY *pAVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint in_lr;
  undefined8 unaff_d14;
  undefined8 in_d31;
  
  while( true ) {
    userKey = (uchar *)private_AES_set_encrypt_key(userKey,bits,key);
    if (userKey == (uchar *)0x0) {
      iVar12 = key->rounds;
      pAVar8 = key;
      pAVar9 = (AES_KEY *)(key->rd_key + iVar12 * 4);
      do {
        uVar2 = pAVar8->rd_key[1];
        uVar3 = pAVar8->rd_key[2];
        uVar4 = pAVar8->rd_key[3];
        uVar5 = pAVar9->rd_key[0];
        uVar6 = pAVar9->rd_key[1];
        uVar7 = pAVar9->rd_key[2];
        uVar10 = pAVar9->rd_key[3];
        pAVar1 = pAVar9 + -1;
        pAVar9->rd_key[0] = pAVar8->rd_key[0];
        pAVar9->rd_key[1] = uVar2;
        pAVar9->rd_key[2] = uVar3;
        pAVar9->rd_key[3] = uVar4;
        puVar11 = pAVar8->rd_key;
        pAVar8->rd_key[0] = uVar5;
        pAVar8->rd_key[1] = uVar6;
        pAVar8->rd_key[2] = uVar7;
        pAVar8->rd_key[3] = uVar10;
        pAVar8 = (AES_KEY *)(puVar11 + 4);
        pAVar9 = (AES_KEY *)(pAVar1->rd_key + 0x39);
      } while ((AES_KEY *)(puVar11 + 4) != (AES_KEY *)(pAVar1->rd_key + 0x39));
      uVar2 = key->rd_key[4];
      iVar12 = (iVar12 + -1) * 4;
      puVar11 = key->rd_key + 4;
      do {
        uVar3 = (uVar2 & 0x80808080) - ((uVar2 & 0x80808080) >> 7) & 0x1b1b1b1b ^
                (uVar2 & 0x7f7f7f7f) << 1;
        uVar4 = (uVar3 & 0x80808080) - ((uVar3 & 0x80808080) >> 7) & 0x1b1b1b1b ^
                (uVar3 & 0x7f7f7f7f) << 1;
        uVar5 = (uVar4 & 0x80808080) - ((uVar4 & 0x80808080) >> 7) & 0x1b1b1b1b ^
                (uVar4 & 0x7f7f7f7f) << 1;
        uVar6 = uVar2 ^ uVar5;
        uVar2 = puVar11[1];
        *puVar11 = uVar3 ^ uVar4 ^ uVar5 ^ (uVar3 >> 0x18 | uVar3 << 8) ^
                   (uVar6 >> 0x18 | uVar6 << 8) ^ (uVar4 >> 0x10 | uVar4 << 0x10) ^
                   (uVar6 >> 0x10 | uVar6 << 0x10) ^ (uVar6 >> 8 | uVar6 << 0x18);
        iVar12 = iVar12 + -1;
        puVar11 = puVar11 + 1;
      } while (iVar12 != 0);
      return 0;
    }
    if ((in_lr & 1) == 0) break;
    unaff_d14 = VectorRoundHalvingAdd(unaff_d14,in_d31,2,1);
    bits = extraout_r1;
  }
  return (int)userKey;
}

