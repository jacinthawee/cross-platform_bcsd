
void BF_set_key(BF_KEY *key,int len,uchar *data)

{
  uint *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  BF_KEY *pBVar8;
  BF_KEY *pBVar9;
  uint local_20;
  uint local_1c;
  
  memcpy(key,&bf_init,0x1048);
  puVar4 = data;
  pBVar8 = key;
  if (len < 0x49) {
    puVar7 = data + len;
  }
  else {
    puVar7 = data + 0x48;
  }
  do {
    puVar2 = puVar4 + 1;
    if (puVar7 <= puVar4 + 1) {
      puVar2 = data;
    }
    puVar5 = puVar2 + 1;
    if (puVar7 <= puVar2 + 1) {
      puVar5 = data;
    }
    puVar3 = puVar5 + 1;
    if (puVar7 <= puVar5 + 1) {
      puVar3 = data;
    }
    puVar6 = puVar3 + 1;
    if (puVar7 <= puVar3 + 1) {
      puVar6 = data;
    }
    puVar1 = pBVar8->P;
    pBVar8->P[0] = pBVar8->P[0] ^ CONCAT31(CONCAT21(CONCAT11(*puVar4,*puVar2),*puVar5),*puVar3);
    puVar4 = puVar6;
    pBVar8 = (BF_KEY *)(puVar1 + 1);
  } while ((BF_KEY *)(puVar1 + 1) != (BF_KEY *)key->S);
  local_20 = 0;
  local_1c = 0;
  pBVar8 = key;
  do {
    pBVar9 = pBVar8;
    BF_encrypt(&local_20,key);
    pBVar9->P[0] = local_20;
    pBVar9->P[1] = local_1c;
    pBVar8 = (BF_KEY *)(pBVar9->P + 2);
  } while (pBVar8 != (BF_KEY *)key->S);
  do {
    BF_encrypt(&local_20,key);
    pBVar8->P[0] = local_20;
    pBVar8->P[1] = local_1c;
    pBVar8 = (BF_KEY *)(pBVar8->P + 2);
  } while (pBVar8 != (BF_KEY *)(pBVar9->S + 0x3f0));
  return;
}

