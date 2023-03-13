
void show_ciphers(int param_1,BIO *param_2)

{
  ushort **ppuVar1;
  byte *pbVar2;
  
  ppuVar1 = __ctype_b_loc();
  pbVar2 = *(byte **)(param_1 + 8);
  if ((*(byte *)((int)*ppuVar1 + (uint)*pbVar2 * 2 + 1) & 2) != 0) {
    BIO_printf(param_2,"-%-25s",pbVar2);
    n_16282 = n_16282 + 1;
    if (n_16282 != 3) {
      BIO_printf(param_2," ");
      return;
    }
    BIO_printf(param_2,"\n",pbVar2);
    n_16282 = 0;
  }
  return;
}

