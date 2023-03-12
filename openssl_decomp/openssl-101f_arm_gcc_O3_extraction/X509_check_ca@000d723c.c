
int X509_check_ca(X509 *x)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = x->ex_flags;
  if (-1 < (int)(uVar4 << 0x17)) {
    CRYPTO_lock(9,3,"v3_purp.c",0x214);
    if (-1 < (int)(x->ex_flags << 0x17)) {
      x509v3_cache_extensions_part_6(x);
    }
    CRYPTO_lock(10,3,"v3_purp.c",0x216);
    uVar4 = x->ex_flags;
  }
  uVar3 = uVar4 & 2;
  if ((uVar3 == 0) || (uVar1 = x->ex_kusage & 4, uVar1 != 0)) {
    if ((int)(uVar4 << 0x1f) < 0) {
      return (uVar4 << 0x1b) >> 0x1f;
    }
    if ((uVar4 & 0x60) == 0x60) {
      return 3;
    }
    if (uVar3 != 0) {
      return 4;
    }
    uVar1 = uVar3;
    if ((int)(uVar4 << 0x1c) < 0) {
      if ((x->ex_nscert & 7) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = 5;
      }
      return iVar2;
    }
  }
  return uVar1;
}

