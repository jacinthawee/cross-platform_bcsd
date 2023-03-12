
uint read_n(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar2 = *(int *)(param_1 + 0x54);
  iVar8 = *(int *)(iVar2 + 0x28);
  if ((int)param_2 <= iVar8) {
    if (param_4 == 0) {
      iVar5 = *(int *)(iVar2 + 0x2c);
      *(int *)(param_1 + 0x4c) = *(int *)(iVar2 + 0x30) + iVar5;
      uVar7 = param_2;
    }
    else {
      iVar5 = *(int *)(iVar2 + 0x2c);
      uVar7 = param_2 + *(int *)(param_1 + 0x50);
    }
    *(uint *)(param_1 + 0x50) = uVar7;
    *(uint *)(iVar2 + 0x28) = iVar8 - param_2;
    *(uint *)(iVar2 + 0x2c) = param_2 + iVar5;
    return param_2;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
    param_3 = param_2;
  }
  uVar7 = 0x8001;
  if (param_3 < 0x8002) {
    uVar7 = param_3;
  }
  if (iVar8 == 0) {
    iVar5 = *(int *)(param_1 + 0x50);
    if ((iVar5 != 0) && (param_4 != 0)) goto LAB_0047d160;
    iVar5 = 0;
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar2 + 0x30);
    if ((int)param_2 < 1) goto LAB_0047d19c;
  }
  else {
    if (param_4 == 0) {
      iVar6 = *(int *)(iVar2 + 0x30);
      if (*(int *)(iVar2 + 0x2c) != 0) {
        iVar5 = 0;
        (*(code *)PTR_memcpy_006aabf4)(iVar6,iVar6 + *(int *)(iVar2 + 0x2c),iVar8);
        iVar2 = *(int *)(param_1 + 0x54);
        *(undefined4 *)(iVar2 + 0x2c) = 0;
        *(undefined4 *)(iVar2 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar2 + 0x30);
        goto LAB_0047d078;
      }
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(param_1 + 0x50);
LAB_0047d160:
      iVar6 = *(int *)(iVar2 + 0x30);
      if (*(int *)(param_1 + 0x4c) != iVar6) {
        (*(code *)PTR_memcpy_006aabf4)(iVar6,*(int *)(param_1 + 0x4c),iVar8 + iVar5);
        iVar2 = *(int *)(param_1 + 0x54);
        *(undefined4 *)(iVar2 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar2 + 0x30);
        goto LAB_0047d078;
      }
    }
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(int *)(param_1 + 0x4c) = iVar6;
  }
LAB_0047d078:
  puVar3 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  do {
    puVar1 = PTR_BIO_read_006a85bc;
    iVar2 = *(int *)(param_1 + 0xc);
    *puVar3 = 0;
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x70,0xd3,"s2_pkt.c",0x180);
      uVar4 = 0xffffffff;
LAB_0047d100:
      *(int *)(*(int *)(param_1 + 0x54) + 0x28) = *(int *)(*(int *)(param_1 + 0x54) + 0x28) + iVar8;
      return uVar4;
    }
    *(undefined4 *)(param_1 + 0x18) = 3;
    uVar4 = (*(code *)puVar1)(iVar2,*(int *)(*(int *)(param_1 + 0x54) + 0x30) + iVar8 + iVar5,
                              uVar7 - iVar8);
    if ((int)uVar4 < 1) goto LAB_0047d100;
    iVar8 = iVar8 + uVar4;
  } while (iVar8 < (int)param_2);
  iVar2 = *(int *)(param_1 + 0x54);
LAB_0047d19c:
  if ((int)param_2 < iVar8) {
    *(uint *)(iVar2 + 0x2c) = iVar5 + param_2;
    *(uint *)(iVar2 + 0x28) = iVar8 - param_2;
  }
  else {
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
  }
  uVar7 = param_2;
  if (param_4 != 0) {
    uVar7 = param_2 + *(int *)(param_1 + 0x50);
  }
  *(uint *)(param_1 + 0x50) = uVar7;
  *(undefined4 *)(param_1 + 0x18) = 1;
  return param_2;
}

