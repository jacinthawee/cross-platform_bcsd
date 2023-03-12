
undefined4 MDC2_Final(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_2;
  if (iVar3 == 0) {
    if (param_2[7] != 2) goto LAB_005e2868;
LAB_005e2908:
    *(undefined *)((int)param_2 + iVar3 + 4) = 0x80;
    iVar3 = iVar3 + 1;
  }
  else if (param_2[7] == 2) goto LAB_005e2908;
  (*(code *)PTR_memset_006aab00)((int)param_2 + iVar3 + 4,0,8 - iVar3,param_4,&_gp);
  mdc2_body(param_2,param_2 + 1,8);
LAB_005e2868:
  iVar3 = param_2[4];
  *param_1 = param_2[3];
  param_1[1] = iVar3;
  uVar4 = param_2[5];
  iVar3 = param_2[6];
  uVar1 = (uint)(param_1 + 2) & 3;
  puVar2 = (uint *)((int)(param_1 + 2) - uVar1);
  *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar4 >> uVar1 * 8;
  uVar1 = (int)param_1 + 0xbU & 3;
  puVar2 = (uint *)(((int)param_1 + 0xbU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar4 << (3 - uVar1) * 8;
  param_1[3] = iVar3;
  return 1;
}

