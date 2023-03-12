
undefined1 * ssl3_get_cipher(uint param_1)

{
  undefined1 *puVar1;
  
  if (param_1 < 0x7d) {
    puVar1 = &ssl3_ciphers + (0x7c - param_1) * 0x30;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}

