
void gost_destroy(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *param_1 = 0;
  param_1[7] = 0;
  do {
    *(undefined4 *)(((uint)(param_1 + 1) & 0xfffffffc) + uVar1) = 0;
    uVar1 = uVar1 + 4;
  } while (uVar1 < ((int)param_1 + (0x20 - ((uint)(param_1 + 1) & 0xfffffffc)) & 0xfffffffc));
  return;
}

