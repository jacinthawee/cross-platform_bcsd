
undefined1 * ssl3_get_cipher(uint param_1)

{
  if (param_1 < 0x7d) {
    return ssl3_ciphers + (0x7c - param_1) * 0x30;
  }
  return (undefined1 *)0x0;
}

