
uint added_obj_LHASH_HASH(int *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  
  iVar6 = *param_1;
  puVar2 = (undefined4 *)param_1[1];
  if (iVar6 == 1) {
    uVar3 = (*(code *)PTR_lh_strhash_006a84ac)(*puVar2);
    iVar6 = *param_1;
  }
  else if (iVar6 < 2) {
    if (iVar6 != 0) {
      return 0;
    }
    iVar7 = puVar2[3];
    pbVar5 = (byte *)puVar2[4];
    uVar3 = iVar7 << 0x14;
    if (0 < iVar7) {
      pbVar8 = pbVar5 + iVar7;
      iVar7 = 0;
      do {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 1;
        uVar4 = iVar7 + (iVar7 / 0x18) * 8;
        iVar7 = iVar7 + 3;
        uVar3 = uVar3 ^ (uint)bVar1 << (uVar4 & 0x1f);
      } while (pbVar8 != pbVar5);
    }
  }
  else if (iVar6 == 2) {
    uVar3 = (*(code *)PTR_lh_strhash_006a84ac)(puVar2[1]);
    iVar6 = *param_1;
  }
  else {
    if (iVar6 != 3) {
      return 0;
    }
    uVar3 = puVar2[2];
  }
  return iVar6 << 0x1e | uVar3 & 0x3fffffff;
}

