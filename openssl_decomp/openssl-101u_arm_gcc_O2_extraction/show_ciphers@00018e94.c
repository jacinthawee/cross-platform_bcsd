
void show_ciphers(int param_1,BIO *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort **ppuVar1;
  
  ppuVar1 = __ctype_b_loc();
  if (-1 < (int)((uint)(*ppuVar1)[**(byte **)(param_1 + 8)] << 0x16)) {
    return;
  }
  BIO_printf(param_2,"-%-25s",*(byte **)(param_1 + 8),
             (uint)(*ppuVar1)[**(byte **)(param_1 + 8)] << 0x16,param_4);
  n_18894 = n_18894 + 1;
  if (n_18894 != 3) {
    BIO_vprintf(param_2," ",&stack0xfffffff8);
    return;
  }
  BIO_printf(param_2,"\n");
  n_18894 = 0;
  return;
}

