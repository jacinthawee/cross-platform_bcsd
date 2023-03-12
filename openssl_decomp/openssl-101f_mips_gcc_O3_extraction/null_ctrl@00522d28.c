
bool null_ctrl(undefined4 param_1,uint param_2)

{
  if (param_2 < 0xd) {
    return (1 << (param_2 & 0x1f) & 0x1a16U) != 0;
  }
  return false;
}

