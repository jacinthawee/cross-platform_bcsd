
undefined4 tls12_get_sigid(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = *param_1;
  if (iVar1 == tls12_sig._0_4_) {
    puVar2 = tls12_sig;
  }
  else if (iVar1 == tls12_sig._8_4_) {
    puVar2 = (undefined1 *)0x18df2c;
  }
  else {
    if (iVar1 != tls12_sig._16_4_) {
      return 0xffffffff;
    }
    puVar2 = (undefined1 *)0x18df34;
  }
  return *(undefined4 *)(puVar2 + 4);
}

