
undefined4 ssl2_pending(int param_1)

{
  uint uVar1;
  
  uVar1 = (*(code *)PTR_SSL_state_006a88f4)();
  if ((uVar1 & 0x3000) == 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x54) + 0x44);
  }
  return 0;
}

