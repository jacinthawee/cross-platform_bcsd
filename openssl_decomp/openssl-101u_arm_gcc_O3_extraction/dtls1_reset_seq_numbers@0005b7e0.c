
void dtls1_reset_seq_numbers(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 << 0x1f < 0) {
    iVar2 = *(int *)(param_1 + 0x5c);
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x58) + 8);
    *(short *)(iVar2 + 0x208) = *(short *)(iVar2 + 0x208) + 1;
    *(undefined4 *)(iVar2 + 0x20c) = *(undefined4 *)(iVar2 + 0x218);
    *(undefined4 *)(iVar2 + 0x214) = *(undefined4 *)(iVar2 + 0x220);
    *(undefined4 *)(iVar2 + 0x210) = *(undefined4 *)(iVar2 + 0x21c);
    iVar2 = *(int *)(param_1 + 0x5c);
    *(undefined *)(iVar2 + 0x218) = 0;
    *(undefined *)(iVar2 + 0x219) = 0;
    *(undefined *)(iVar2 + 0x21a) = 0;
    *(undefined *)(iVar2 + 0x21b) = 0;
    *(undefined *)(iVar2 + 0x21c) = 0;
    *(undefined *)(iVar2 + 0x21d) = 0;
    *(undefined *)(iVar2 + 0x21e) = 0;
    *(undefined *)(iVar2 + 0x21f) = 0;
    *(undefined *)(iVar2 + 0x220) = 0;
    *(undefined *)(iVar2 + 0x221) = 0;
    *(undefined *)(iVar2 + 0x222) = 0;
    *(undefined *)(iVar2 + 0x223) = 0;
    dtls1_clear_received_buffer();
  }
  else {
    iVar2 = *(int *)(param_1 + 0x5c);
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x58) + 0x54);
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x58);
    *(undefined4 *)(iVar2 + 0x22a) = *puVar3;
    *(undefined4 *)(iVar2 + 0x22e) = uVar1;
    *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) = *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) + 1;
  }
  *(undefined *)puVar3 = 0;
  *(undefined *)((int)puVar3 + 1) = 0;
  *(undefined *)((int)puVar3 + 2) = 0;
  *(undefined *)((int)puVar3 + 3) = 0;
  *(undefined *)(puVar3 + 1) = 0;
  *(undefined *)((int)puVar3 + 5) = 0;
  *(undefined *)((int)puVar3 + 6) = 0;
  *(undefined *)((int)puVar3 + 7) = 0;
  return;
}

