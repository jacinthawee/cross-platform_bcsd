
void show_ciphers(int param_1,BIO *param_2)

{
  ushort **ppuVar1;
  
  ppuVar1 = __ctype_b_loc();
  if (-1 < (int)((uint)(*ppuVar1)[**(byte **)(param_1 + 8)] << 0x16)) {
    return;
  }
  BIO_printf(param_2,"-%-25s");
  n_18884 = n_18884 + 1;
  if (n_18884 != 3) {
    BIO_printf(param_2," ");
    return;
  }
  BIO_printf(param_2,"\n");
  n_18884 = 0;
  return;
}

