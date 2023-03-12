
int dtls1_set_message_header
              (int param_1,int param_2,undefined param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x5c);
  if ((param_5 == 0) && (*(int *)(iVar2 + 0x254) == 0)) {
    sVar1 = *(short *)(iVar2 + 0x226);
    *(undefined *)(iVar2 + 0x260) = param_3;
    *(undefined4 *)(iVar2 + 0x264) = param_4;
    *(undefined4 *)(iVar2 + 0x26c) = 0;
    *(short *)(iVar2 + 0x224) = sVar1;
    *(short *)(iVar2 + 0x268) = sVar1;
    *(short *)(iVar2 + 0x226) = sVar1 + 1;
    *(undefined4 *)(iVar2 + 0x270) = param_6;
    return param_2 + 0xc;
  }
  *(undefined *)(iVar2 + 0x260) = param_3;
  *(undefined4 *)(iVar2 + 0x264) = param_4;
  *(int *)(iVar2 + 0x26c) = param_5;
  *(undefined2 *)(iVar2 + 0x268) = *(undefined2 *)(iVar2 + 0x224);
  *(undefined4 *)(iVar2 + 0x270) = param_6;
  return param_2 + 0xc;
}

