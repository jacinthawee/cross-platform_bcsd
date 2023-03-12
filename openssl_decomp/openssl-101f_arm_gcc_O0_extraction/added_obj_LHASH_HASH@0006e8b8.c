
uint added_obj_LHASH_HASH(int *param_1)

{
  byte *pbVar1;
  int iVar2;
  ulong uVar3;
  char **ppcVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  
  ppcVar4 = (char **)param_1[1];
  switch(*param_1) {
  case 0:
    break;
  case 1:
    uVar3 = lh_strhash(*ppcVar4);
    return uVar3 & 0x3fffffff | *param_1 << 0x1e;
  case 2:
    uVar3 = lh_strhash(ppcVar4[1]);
    return uVar3 & 0x3fffffff | *param_1 << 0x1e;
  case 3:
    return (uint)ppcVar4[2] & 0x3fffffff | 0xc0000000;
  default:
    return 0;
  }
  pcVar7 = ppcVar4[3];
  uVar6 = (int)pcVar7 << 0x14;
  if (0 < (int)pcVar7) {
    pcVar5 = (char *)0x0;
    do {
      iVar2 = (int)pcVar5 * 3;
      pbVar1 = (byte *)(ppcVar4[4] + (int)pcVar5);
      pcVar5 = pcVar5 + 1;
      uVar6 = uVar6 ^ (uint)*pbVar1 << (iVar2 % 0x18 & 0xffU);
    } while (pcVar5 != pcVar7);
  }
  return uVar6 & 0x3fffffff;
}

