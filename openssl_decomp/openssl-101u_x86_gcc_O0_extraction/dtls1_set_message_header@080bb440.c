
int dtls1_set_message_header
              (int param_1,int param_2,undefined param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if ((param_5 == 0) && (*(int *)(iVar1 + 0x254) == 0)) {
    sVar2 = *(short *)(iVar1 + 0x226);
    *(short *)(iVar1 + 0x224) = sVar2;
    *(short *)(iVar1 + 0x226) = sVar2 + 1;
  }
  else {
    sVar2 = *(short *)(iVar1 + 0x224);
  }
  *(int *)(iVar1 + 0x26c) = param_5;
  *(undefined *)(iVar1 + 0x260) = param_3;
  *(short *)(iVar1 + 0x268) = sVar2;
  *(undefined4 *)(iVar1 + 0x264) = param_4;
  *(undefined4 *)(iVar1 + 0x270) = param_6;
  return param_2 + 0xc;
}

