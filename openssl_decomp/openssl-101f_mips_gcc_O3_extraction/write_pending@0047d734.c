
int write_pending(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x54);
  if ((param_3 < *(int *)(iVar7 + 0x14)) ||
     ((*(int *)(iVar7 + 0x18) != param_2 && ((*(uint *)(param_1 + 0x104) & 2) == 0)))) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd4,0x7f,"s2_pkt.c",0x1e0);
    iVar4 = -1;
  }
  else {
    puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
    while( true ) {
      puVar1 = PTR_BIO_write_006a7f14;
      iVar4 = *(int *)(param_1 + 0x10);
      *puVar2 = 0;
      if (iVar4 == 0) break;
      iVar5 = *(int *)(iVar7 + 0x38);
      iVar3 = *(int *)(iVar7 + 0x1c);
      uVar6 = *(undefined4 *)(iVar7 + 0x20);
      *(undefined4 *)(param_1 + 0x18) = 2;
      iVar4 = (*(code *)puVar1)(iVar4,iVar5 + iVar3,uVar6);
      iVar7 = *(int *)(param_1 + 0x54);
      if (iVar4 == *(int *)(iVar7 + 0x20)) goto LAB_0047d830;
      if (iVar4 < 1) {
        return iVar4;
      }
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) - iVar4;
      *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + iVar4;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd4,0x104,"s2_pkt.c",0x1f0);
    iVar7 = *(int *)(param_1 + 0x54);
    if (*(int *)(iVar7 + 0x20) != -1) {
      return -1;
    }
LAB_0047d830:
    iVar4 = *(int *)(iVar7 + 0x24);
    *(undefined4 *)(iVar7 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x18) = 1;
  }
  return iVar4;
}

