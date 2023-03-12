
void dtls1_reset_seq_numbers(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  if ((param_2 & 1) == 0) {
    iVar3 = *(int *)(param_1 + 0x58);
    iVar6 = *(int *)(param_1 + 0x5c);
    uVar5 = *(uint *)(iVar3 + 0x54);
    uVar4 = *(undefined4 *)(iVar3 + 0x58);
    uVar1 = iVar6 + 0x22aU & 3;
    puVar2 = (uint *)((iVar6 + 0x22aU) - uVar1);
    *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar5 >> uVar1 * 8;
    uVar1 = iVar6 + 0x22dU & 3;
    puVar2 = (uint *)((iVar6 + 0x22dU) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar5 << (3 - uVar1) * 8;
    *(undefined4 *)(iVar6 + 0x22e) = uVar4;
    *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) = *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) + 1;
    *(undefined *)(uint *)(iVar3 + 0x54) = 0;
    *(undefined *)(iVar3 + 0x55) = 0;
    *(undefined *)(iVar3 + 0x56) = 0;
    *(undefined *)(iVar3 + 0x57) = 0;
    *(undefined *)(iVar3 + 0x58) = 0;
    *(undefined *)(iVar3 + 0x59) = 0;
    *(undefined *)(iVar3 + 0x5a) = 0;
    *(undefined *)(iVar3 + 0x5b) = 0;
    return;
  }
  iVar6 = *(int *)(param_1 + 0x5c);
  iVar3 = *(int *)(param_1 + 0x58);
  *(short *)(iVar6 + 0x208) = *(short *)(iVar6 + 0x208) + 1;
  uVar5 = *(uint *)(iVar6 + 0x218);
  uVar7 = *(undefined4 *)(iVar6 + 0x21c);
  uVar4 = *(undefined4 *)(iVar6 + 0x220);
  uVar1 = iVar6 + 0x20cU & 3;
  puVar2 = (uint *)((iVar6 + 0x20cU) - uVar1);
  *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar5 >> uVar1 * 8;
  uVar1 = iVar6 + 0x20fU & 3;
  puVar2 = (uint *)((iVar6 + 0x20fU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar5 << (3 - uVar1) * 8;
  *(undefined4 *)(iVar6 + 0x210) = uVar7;
  *(undefined4 *)(iVar6 + 0x214) = uVar4;
  iVar6 = *(int *)(param_1 + 0x5c);
  *(undefined *)(iVar6 + 0x218) = 0;
  *(undefined *)(iVar6 + 0x219) = 0;
  *(undefined *)(iVar6 + 0x21a) = 0;
  *(undefined *)(iVar6 + 0x21b) = 0;
  *(undefined *)(iVar6 + 0x21c) = 0;
  *(undefined *)(iVar6 + 0x21d) = 0;
  *(undefined *)(iVar6 + 0x21e) = 0;
  *(undefined *)(iVar6 + 0x21f) = 0;
  *(undefined *)(iVar6 + 0x220) = 0;
  *(undefined *)(iVar6 + 0x221) = 0;
  *(undefined *)(iVar6 + 0x222) = 0;
  *(undefined *)(iVar6 + 0x223) = 0;
  *(undefined *)(iVar3 + 8) = 0;
  *(undefined *)(iVar3 + 9) = 0;
  *(undefined *)(iVar3 + 10) = 0;
  *(undefined *)(iVar3 + 0xb) = 0;
  *(undefined *)(iVar3 + 0xc) = 0;
  *(undefined *)(iVar3 + 0xd) = 0;
  *(undefined *)(iVar3 + 0xe) = 0;
  *(undefined *)(iVar3 + 0xf) = 0;
  return;
}

