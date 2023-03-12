
void BF_set_key(BF_KEY *key,int len,uchar *data)

{
  uchar uVar1;
  undefined *puVar2;
  uint *puVar3;
  uint *puVar4;
  uchar *puVar5;
  uint uVar6;
  BF_KEY *pBVar7;
  uchar *puVar8;
  uint uVar9;
  uchar *puVar10;
  uint uVar11;
  uchar *puVar12;
  uchar *puVar13;
  BF_KEY *pBVar14;
  uint local_24;
  uint local_20;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  pBVar7 = key;
  puVar3 = (uint *)bf_init;
  do {
    puVar4 = puVar3;
    pBVar14 = pBVar7;
    uVar11 = puVar4[1];
    uVar9 = puVar4[2];
    uVar6 = puVar4[3];
    pBVar14->P[0] = *puVar4;
    pBVar14->P[1] = uVar11;
    pBVar14->P[2] = uVar9;
    pBVar14->P[3] = uVar6;
    pBVar7 = (BF_KEY *)(pBVar14->P + 4);
    puVar3 = puVar4 + 4;
  } while (puVar4 + 4 != (uint *)(bf_init + 0x1040));
  uVar6 = puVar4[5];
  if (0x48 < len) {
    len = 0x48;
  }
  ((BF_KEY *)(pBVar14->P + 4))->P[0] = bf_init._4160_4_;
  pBVar14->P[5] = uVar6;
  puVar12 = data + len;
  puVar5 = data;
  pBVar7 = key;
  do {
    uVar1 = *puVar5;
    puVar3 = pBVar7->P;
    puVar8 = puVar5 + 1;
    if (puVar12 <= puVar5 + 1) {
      puVar8 = data;
    }
    puVar10 = puVar8 + 1;
    if (puVar12 <= puVar8 + 1) {
      puVar10 = data;
    }
    puVar13 = puVar10 + 1;
    if (puVar12 <= puVar10 + 1) {
      puVar13 = data;
    }
    puVar5 = puVar13 + 1;
    if (puVar12 <= puVar13 + 1) {
      puVar5 = data;
    }
    pBVar7->P[0] = pBVar7->P[0] ^ CONCAT31(CONCAT21(CONCAT11(uVar1,*puVar8),*puVar10),*puVar13);
    pBVar7 = (BF_KEY *)(puVar3 + 1);
  } while ((BF_KEY *)(puVar3 + 1) != (BF_KEY *)key->S);
  local_24 = 0;
  local_20 = 0;
  pBVar7 = key;
  do {
    pBVar14 = (BF_KEY *)(pBVar7->P + 2);
    BF_encrypt(&local_24,key);
    pBVar7->P[0] = local_24;
    pBVar7->P[1] = local_20;
    pBVar7 = pBVar14;
  } while (pBVar14 != (BF_KEY *)key->S);
  do {
    puVar3 = pBVar14->P;
    BF_encrypt(&local_24,key);
    pBVar14->P[0] = local_24;
    pBVar14->P[1] = local_20;
    pBVar14 = (BF_KEY *)(puVar3 + 2);
  } while (key + 1 != (BF_KEY *)(puVar3 + 2));
  if (local_1c == *(int *)puVar2) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return;
}

