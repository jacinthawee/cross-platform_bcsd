
int __regparm1 X509_check_ca(X509 *x)

{
  uint uVar1;
  uint uVar2;
  int in_stack_00000004;
  
  uVar2 = *(uint *)(in_stack_00000004 + 0x28);
  if ((uVar2 & 0x100) == 0) {
    CRYPTO_lock((int)x,9,(char *)0x3,(int)"v3_purp.c");
    if ((*(byte *)(in_stack_00000004 + 0x29) & 1) == 0) {
      x = (X509 *)x509v3_cache_extensions_part_6();
    }
    CRYPTO_lock((int)x,10,(char *)0x3,(int)"v3_purp.c");
    uVar2 = *(uint *)(in_stack_00000004 + 0x28);
  }
  if (((uVar2 & 2) == 0) || (uVar1 = 0, (*(byte *)(in_stack_00000004 + 0x2c) & 4) != 0)) {
    if ((uVar2 & 1) != 0) {
      return uVar2 >> 4 & 1;
    }
    uVar1 = 3;
    if ((((uVar2 & 0x60) != 0x60) && (uVar1 = 4, (uVar2 & 2) == 0)) && (uVar1 = 0, (uVar2 & 8) != 0)
       ) {
      uVar1 = ~-(uint)((*(uint *)(in_stack_00000004 + 0x34) & 7) == 0) & 5;
    }
  }
  return uVar1;
}

