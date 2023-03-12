
int dtls1_set_message_header
              (int param_1,int param_2,undefined param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x5c);
  iVar3 = iVar4;
  if ((param_5 == 0) && (*(int *)(iVar4 + 0x254) == 0)) {
    sVar1 = *(short *)(iVar4 + 0x226);
    *(short *)(iVar4 + 0x226) = sVar1 + 1;
    *(short *)(iVar4 + 0x224) = sVar1;
    iVar3 = *(int *)(param_1 + 0x5c);
  }
  uVar2 = *(undefined2 *)(iVar4 + 0x224);
  *(undefined4 *)(iVar3 + 0x264) = param_4;
  *(undefined *)(iVar3 + 0x260) = param_3;
  *(undefined2 *)(iVar3 + 0x268) = uVar2;
  *(int *)(iVar3 + 0x26c) = param_5;
  *(undefined4 *)(iVar3 + 0x270) = param_6;
  return param_2 + 0xc;
}

