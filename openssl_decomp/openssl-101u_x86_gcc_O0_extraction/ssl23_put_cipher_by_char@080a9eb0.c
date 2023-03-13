
undefined4 ssl23_put_cipher_by_char(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  
  if (((((*(int *)(param_1 + 0xc) - 0x20U & 0xffffffdf) != 0) && (*(int *)(param_1 + 0xc) != 0x80))
      && (*(int *)(param_1 + 0x10) != 0x10)) && (*(int *)(param_1 + 0x10) != 0x40)) {
    if (param_2 != (undefined *)0x0) {
      uVar1 = *(undefined4 *)(param_1 + 8);
      param_2[2] = (char)uVar1;
      *param_2 = (char)((uint)uVar1 >> 0x10);
      param_2[1] = (char)((uint)uVar1 >> 8);
      return 3;
    }
    return 3;
  }
  return 0;
}

