
undefined4 start_hash(undefined4 *param_1)

{
  uint uVar1;
  
  if (param_1[2] != 0) {
    param_1[4] = 0;
    param_1[0xb] = 0;
    uVar1 = 0;
    do {
      *(undefined4 *)(((uint)(param_1 + 5) & 0xfffffffc) + uVar1) = 0;
      uVar1 = uVar1 + 4;
    } while (uVar1 < ((int)param_1 + (0x30 - ((uint)(param_1 + 5) & 0xfffffffc)) & 0xfffffffc));
    param_1[0xc] = 0;
    param_1[0x13] = 0;
    uVar1 = 0;
    do {
      *(undefined4 *)(((uint)(param_1 + 0xd) & 0xfffffffc) + uVar1) = 0;
      uVar1 = uVar1 + 4;
    } while (uVar1 < ((int)param_1 + (0x50 - ((uint)(param_1 + 0xd) & 0xfffffffc)) & 0xfffffffc));
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = 0;
    return 1;
  }
  return 0;
}

