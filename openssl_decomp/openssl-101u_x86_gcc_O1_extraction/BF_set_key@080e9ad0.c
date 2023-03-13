
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BF_set_key(BF_KEY *key,int len,uchar *data)

{
  uchar *puVar1;
  uchar uVar2;
  uint *puVar3;
  uint uVar4;
  uchar *puVar5;
  uchar *puVar6;
  int iVar7;
  uchar *puVar8;
  uchar *puVar9;
  undefined4 *puVar10;
  BF_KEY *pBVar11;
  undefined4 *puVar12;
  BF_KEY *pBVar13;
  int in_GS_OFFSET;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  key->P[0] = _bf_init;
  puVar12 = (undefined4 *)((uint)(key->P + 1) & 0xfffffffc);
  key->S[0x3ff] = _DAT_0821a044;
  iVar7 = (int)key - (int)puVar12;
  puVar10 = (undefined4 *)(&bf_init + -iVar7);
  for (uVar4 = iVar7 + 0x1048U >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar12 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar12 = puVar12 + 1;
  }
  if (0x48 < len) {
    len = 0x48;
  }
  puVar1 = data + len;
  puVar9 = data;
  pBVar11 = key;
  do {
    uVar2 = *puVar9;
    puVar5 = puVar9 + 1;
    if (puVar1 <= puVar9 + 1) {
      puVar5 = data;
    }
    puVar8 = puVar5 + 1;
    if (puVar1 <= puVar5 + 1) {
      puVar8 = data;
    }
    puVar6 = puVar8 + 1;
    if (puVar1 <= puVar8 + 1) {
      puVar6 = data;
    }
    puVar9 = puVar6 + 1;
    if (puVar1 <= puVar6 + 1) {
      puVar9 = data;
    }
    pBVar11->P[0] = pBVar11->P[0] ^ CONCAT31(CONCAT21(CONCAT11(uVar2,*puVar5),*puVar8),*puVar6);
    pBVar11 = (BF_KEY *)(pBVar11->P + 1);
  } while (pBVar11 != (BF_KEY *)key->S);
  local_28 = 0;
  local_24 = 0;
  pBVar11 = key;
  do {
    pBVar13 = (BF_KEY *)(pBVar11->P + 2);
    BF_encrypt(&local_28,key);
    pBVar11->P[0] = local_28;
    pBVar11->P[1] = local_24;
    pBVar11 = pBVar13;
  } while (pBVar13 != (BF_KEY *)key->S);
  do {
    puVar3 = pBVar13->P;
    BF_encrypt(&local_28,key);
    pBVar13->P[0] = local_28;
    pBVar13->P[1] = local_24;
    pBVar13 = (BF_KEY *)(puVar3 + 2);
  } while (key + 1 != (BF_KEY *)(puVar3 + 2));
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

