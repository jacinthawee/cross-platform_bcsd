
undefined4 desx_cbc_init_key(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  (*(code *)PTR_DES_set_key_unchecked_006a8ad8)
            (param_2,*(undefined4 *)(param_1 + 0x60),param_3,param_4,&_gp);
  iVar5 = *(int *)(param_1 + 0x60);
  uVar4 = *(uint *)(param_2 + 8);
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  uVar1 = iVar5 + 0x80U & 3;
  puVar2 = (uint *)((iVar5 + 0x80U) - uVar1);
  *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar4 >> uVar1 * 8;
  uVar1 = iVar5 + 0x83U & 3;
  puVar2 = (uint *)((iVar5 + 0x83U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar4 << (3 - uVar1) * 8;
  *(undefined4 *)(iVar5 + 0x84) = uVar3;
  uVar4 = *(uint *)(param_2 + 0x10);
  uVar3 = *(undefined4 *)(param_2 + 0x14);
  iVar5 = *(int *)(param_1 + 0x60);
  uVar1 = iVar5 + 0x88U & 3;
  puVar2 = (uint *)((iVar5 + 0x88U) - uVar1);
  *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar4 >> uVar1 * 8;
  uVar1 = iVar5 + 0x8bU & 3;
  puVar2 = (uint *)((iVar5 + 0x8bU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar4 << (3 - uVar1) * 8;
  *(undefined4 *)(iVar5 + 0x8c) = uVar3;
  return 1;
}

