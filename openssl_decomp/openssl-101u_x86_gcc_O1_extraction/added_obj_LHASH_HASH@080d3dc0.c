
uint added_obj_LHASH_HASH(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  char **ppcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  int local_24;
  
  local_24 = *param_1;
  ppcVar3 = (char **)param_1[1];
  if (local_24 == 1) {
    pcVar5 = *ppcVar3;
  }
  else {
    if (local_24 < 2) {
      if (local_24 != 0) {
        return 0;
      }
      pcVar4 = ppcVar3[3];
      pbVar7 = (byte *)ppcVar3[4];
      pcVar5 = (char *)((int)pcVar4 << 0x14);
      if (0 < (int)pcVar4) {
        pbVar1 = pbVar7 + (int)pcVar4;
        iVar6 = 0;
        do {
          bVar2 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          pcVar5 = (char *)((uint)pcVar5 ^
                           (uint)bVar2 << ((char)iVar6 + (char)(iVar6 / 0x18) * -0x18 & 0x1fU));
          iVar6 = iVar6 + 3;
        } while (pbVar1 != pbVar7);
      }
      goto LAB_080d3df0;
    }
    if (local_24 != 2) {
      if (local_24 != 3) {
        return 0;
      }
      pcVar5 = ppcVar3[2];
      goto LAB_080d3df0;
    }
    pcVar5 = ppcVar3[1];
  }
  pcVar5 = (char *)lh_strhash(pcVar5);
  local_24 = *param_1;
LAB_080d3df0:
  return local_24 << 0x1e | (uint)pcVar5 & 0x3fffffff;
}

