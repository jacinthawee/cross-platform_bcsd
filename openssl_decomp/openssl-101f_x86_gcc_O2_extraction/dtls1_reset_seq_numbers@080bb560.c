
void dtls1_reset_seq_numbers(int param_1,byte param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if ((param_2 & 1) == 0) {
    iVar2 = *(int *)(param_1 + 0x58);
    iVar3 = *(int *)(param_1 + 0x5c);
    puVar5 = (undefined4 *)(iVar2 + 0x54);
    uVar4 = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar3 + 0x22e) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)(iVar3 + 0x22a) = uVar4;
    psVar1 = (short *)(*(int *)(param_1 + 0x5c) + 0x20a);
    *psVar1 = *psVar1 + 1;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x5c);
    iVar3 = *(int *)(param_1 + 0x58);
    *(short *)(iVar2 + 0x208) = *(short *)(iVar2 + 0x208) + 1;
    puVar5 = (undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0x20c) = *(undefined4 *)(iVar2 + 0x218);
    *(undefined4 *)(iVar2 + 0x210) = *(undefined4 *)(iVar2 + 0x21c);
    *(undefined4 *)(iVar2 + 0x214) = *(undefined4 *)(iVar2 + 0x220);
    iVar2 = *(int *)(param_1 + 0x5c);
    *(undefined4 *)(iVar2 + 0x218) = 0;
    *(undefined4 *)(iVar2 + 0x21c) = 0;
    *(undefined4 *)(iVar2 + 0x220) = 0;
  }
  *puVar5 = 0;
  puVar5[1] = 0;
  return;
}

