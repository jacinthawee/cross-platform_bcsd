
bool null_ctrl(undefined4 param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (param_2 < 0xd) {
    bVar1 = (1 << ((byte)param_2 & 0x1f) & 0x1a16U) != 0;
  }
  return bVar1;
}

