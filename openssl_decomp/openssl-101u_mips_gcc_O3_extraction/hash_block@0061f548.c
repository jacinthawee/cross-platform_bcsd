
undefined4 hash_block(int *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  byte *pbVar11;
  int *piVar12;
  byte *pbVar13;
  
  iVar3 = param_1[3];
  if (iVar3 != 0) {
    uVar5 = 0x20U - iVar3;
    if (param_3 <= 0x20U - iVar3) {
      uVar5 = param_3;
    }
    (*(code *)PTR_memcpy_006a9aec)((int)param_1 + iVar3 + 0x50,param_2,uVar5);
    iVar3 = param_1[3];
    param_1[3] = uVar5 + iVar3;
    if ((int)(uVar5 + iVar3) < 0x20) {
      return 1;
    }
    piVar12 = param_1 + 0x14;
    hash_step(param_1[2],param_1 + 4,piVar12);
    param_2 = param_2 + uVar5;
    param_3 = param_3 - uVar5;
    iVar3 = 0;
    piVar8 = param_1 + 0xc;
    piVar10 = piVar12;
    do {
      piVar6 = (int *)((int)piVar8 + 1);
      bVar1 = *(byte *)piVar10;
      piVar10 = (int *)((int)piVar10 + 1);
      iVar4 = (uint)*(byte *)piVar8 + (uint)bVar1 + iVar3;
      iVar3 = iVar4 >> 8;
      *(byte *)piVar8 = (byte)iVar4;
      piVar8 = piVar6;
    } while (piVar12 != piVar6);
    uVar5 = param_1[1];
    param_1[3] = 0;
    uVar7 = uVar5 + 0x20;
    param_1[1] = uVar7;
    *param_1 = (uint)(uVar7 < uVar5) + *param_1;
  }
  if (0x1f < param_3) {
    pbVar13 = param_2;
    uVar5 = param_3;
    do {
      hash_step(param_1[2],param_1 + 4,pbVar13);
      iVar3 = 0;
      piVar8 = param_1 + 0xc;
      pbVar11 = pbVar13;
      do {
        piVar10 = (int *)((int)piVar8 + 1);
        bVar1 = *pbVar11;
        pbVar11 = pbVar11 + 1;
        iVar4 = (uint)*(byte *)piVar8 + (uint)bVar1 + iVar3;
        iVar3 = iVar4 >> 8;
        *(byte *)piVar8 = (byte)iVar4;
        piVar8 = piVar10;
      } while (param_1 + 0x14 != piVar10);
      uVar7 = param_1[1];
      uVar5 = uVar5 - 0x20;
      pbVar13 = pbVar13 + 0x20;
      uVar9 = uVar7 + 0x20;
      param_1[1] = uVar9;
      *param_1 = (uint)(uVar9 < uVar7) + *param_1;
    } while (0x1f < uVar5);
    uVar5 = param_3 - 0x20;
    param_3 = param_3 & 0x1f;
    param_2 = param_2 + ((uVar5 >> 5) + 1) * 0x20;
  }
  puVar2 = PTR_memcpy_006a9aec;
  if (param_3 == 0) {
    return 1;
  }
  param_1[3] = param_3;
  (*(code *)puVar2)(param_1 + 0x14,param_2,param_3);
  return 1;
}

