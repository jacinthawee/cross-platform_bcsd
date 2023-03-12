
undefined4 ssl23_get_cipher(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = ssl3_num_ciphers();
  if (param_1 < uVar1) {
    uVar2 = ssl3_get_cipher(param_1);
    return uVar2;
  }
  return 0;
}

