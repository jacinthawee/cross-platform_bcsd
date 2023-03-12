
undefined1 * ssl2_get_cipher(uint param_1)

{
  if (param_1 < 7) {
    return ssl2_ciphers + (6 - param_1) * 0x30;
  }
  return (undefined1 *)0x0;
}

