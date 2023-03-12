
undefined4 hash_block(int *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  byte *pbVar10;
  int *piVar11;
  byte *pbVar12;
  byte *pbVar13;
  int *piVar14;
  byte *pbVar15;
  
  iVar3 = param_1[3];
  pbVar13 = param_2;
  if (iVar3 != 0) {
    uVar4 = 0x20U - iVar3;
    if (param_3 <= 0x20U - iVar3) {
      uVar4 = param_3;
    }
    (*(code *)PTR_memcpy_006aabf4)((int)param_1 + iVar3 + 0x50,param_2,uVar4);
    iVar3 = param_1[3];
    param_1[3] = uVar4 + iVar3;
    if ((int)(uVar4 + iVar3) < 0x20) {
      return 1;
    }
    piVar14 = param_1 + 0x14;
    hash_step(param_1[2],param_1 + 4,piVar14);
    iVar3 = 0;
    piVar7 = param_1 + 0xc;
    piVar11 = piVar14;
    do {
      piVar8 = (int *)((int)piVar7 + 1);
      bVar1 = *(byte *)piVar11;
      piVar11 = (int *)((int)piVar11 + 1);
      iVar5 = (uint)*(byte *)piVar7 + (uint)bVar1 + iVar3;
      iVar3 = iVar5 >> 8;
      *(byte *)piVar7 = (byte)iVar5;
      piVar7 = piVar8;
    } while (piVar14 != piVar8);
    uVar6 = param_1[1];
    param_1[3] = 0;
    uVar9 = uVar6 + 0x20;
    param_1[1] = uVar9;
    *param_1 = (uint)(uVar9 < uVar6) + *param_1;
    pbVar13 = param_2 + uVar4;
  }
  pbVar12 = param_2 + (param_3 - 0x20);
  if (pbVar13 <= pbVar12) {
    pbVar15 = pbVar13;
    do {
      hash_step(param_1[2],param_1 + 4,pbVar15);
      iVar3 = 0;
      piVar7 = param_1 + 0xc;
      pbVar10 = pbVar15;
      do {
        piVar11 = (int *)((int)piVar7 + 1);
        bVar1 = *pbVar10;
        pbVar10 = pbVar10 + 1;
        iVar5 = (uint)*(byte *)piVar7 + (uint)bVar1 + iVar3;
        iVar3 = iVar5 >> 8;
        *(byte *)piVar7 = (byte)iVar5;
        piVar7 = piVar11;
      } while (param_1 + 0x14 != piVar11);
      uVar4 = param_1[1];
      pbVar15 = pbVar15 + 0x20;
      uVar6 = uVar4 + 0x20;
      param_1[1] = uVar6;
      *param_1 = (uint)(uVar6 < uVar4) + *param_1;
    } while (pbVar15 <= pbVar12);
    pbVar13 = pbVar13 + (((uint)((int)pbVar12 - (int)pbVar13) >> 5) + 1) * 0x20;
  }
  puVar2 = PTR_memcpy_006aabf4;
  iVar3 = (int)(param_2 + param_3) - (int)pbVar13;
  if (param_2 + param_3 == pbVar13) {
    return 1;
  }
  param_1[3] = iVar3;
  (*(code *)puVar2)(param_1 + 0x14,pbVar13,iVar3);
  return 1;
}

