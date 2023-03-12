
void dtls1_reset_seq_numbers(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  if ((param_2 & 1) == 0) {
    iVar7 = *(int *)(param_1 + 0x58);
    iVar5 = *(int *)(param_1 + 0x5c);
    uVar4 = *(uint *)(iVar7 + 0x54);
    uVar3 = *(undefined4 *)(iVar7 + 0x58);
    uVar1 = iVar5 + 0x22aU & 3;
    puVar2 = (uint *)((iVar5 + 0x22aU) - uVar1);
    *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar4 >> uVar1 * 8;
    uVar1 = iVar5 + 0x22dU & 3;
    puVar2 = (uint *)((iVar5 + 0x22dU) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar4 << (3 - uVar1) * 8;
    *(undefined4 *)(iVar5 + 0x22e) = uVar3;
    *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) = *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) + 1;
    *(undefined *)(uint *)(iVar7 + 0x54) = 0;
    *(undefined *)(iVar7 + 0x55) = 0;
    *(undefined *)(iVar7 + 0x56) = 0;
    *(undefined *)(iVar7 + 0x57) = 0;
    *(undefined *)(iVar7 + 0x58) = 0;
    *(undefined *)(iVar7 + 0x59) = 0;
    *(undefined *)(iVar7 + 0x5a) = 0;
    *(undefined *)(iVar7 + 0x5b) = 0;
    return;
  }
  iVar5 = *(int *)(param_1 + 0x5c);
  iVar7 = *(int *)(param_1 + 0x58);
  *(short *)(iVar5 + 0x208) = *(short *)(iVar5 + 0x208) + 1;
  uVar4 = *(uint *)(iVar5 + 0x218);
  uVar6 = *(undefined4 *)(iVar5 + 0x21c);
  uVar3 = *(undefined4 *)(iVar5 + 0x220);
  uVar1 = iVar5 + 0x20cU & 3;
  puVar2 = (uint *)((iVar5 + 0x20cU) - uVar1);
  *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | uVar4 >> uVar1 * 8;
  uVar1 = iVar5 + 0x20fU & 3;
  puVar2 = (uint *)((iVar5 + 0x20fU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | uVar4 << (3 - uVar1) * 8;
  *(undefined4 *)(iVar5 + 0x210) = uVar6;
  *(undefined4 *)(iVar5 + 0x214) = uVar3;
  iVar5 = *(int *)(param_1 + 0x5c);
  *(undefined *)(iVar5 + 0x218) = 0;
  *(undefined *)(iVar5 + 0x219) = 0;
  *(undefined *)(iVar5 + 0x21a) = 0;
  *(undefined *)(iVar5 + 0x21b) = 0;
  *(undefined *)(iVar5 + 0x21c) = 0;
  *(undefined *)(iVar5 + 0x21d) = 0;
  *(undefined *)(iVar5 + 0x21e) = 0;
  *(undefined *)(iVar5 + 0x21f) = 0;
  *(undefined *)(iVar5 + 0x220) = 0;
  *(undefined *)(iVar5 + 0x221) = 0;
  *(undefined *)(iVar5 + 0x222) = 0;
  *(undefined *)(iVar5 + 0x223) = 0;
  dtls1_clear_received_buffer();
  *(undefined *)(iVar7 + 8) = 0;
  *(undefined *)(iVar7 + 9) = 0;
  *(undefined *)(iVar7 + 10) = 0;
  *(undefined *)(iVar7 + 0xb) = 0;
  *(undefined *)(iVar7 + 0xc) = 0;
  *(undefined *)(iVar7 + 0xd) = 0;
  *(undefined *)(iVar7 + 0xe) = 0;
  *(undefined *)(iVar7 + 0xf) = 0;
  return;
}

