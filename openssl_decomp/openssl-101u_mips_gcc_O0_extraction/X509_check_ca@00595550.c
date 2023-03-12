
int X509_check_ca(X509 *x)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = x->ex_flags;
  if ((uVar1 & 0x100) == 0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,3,"v3_purp.c",0x23c);
    if ((x->ex_flags & 0x100) == 0) {
      x509v3_cache_extensions_part_6(x);
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,3,"v3_purp.c",0x23e);
    uVar1 = x->ex_flags;
  }
  if (((uVar1 & 2) != 0) && ((x->ex_kusage & 4) == 0)) {
    return 0;
  }
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x60) == 0x60) {
      return 3;
    }
    if ((uVar1 & 2) != 0) {
      return 4;
    }
    uVar2 = 5;
    if ((uVar1 & 8) == 0) {
      return 0;
    }
    if ((x->ex_nscert & 7) == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = (uVar1 << 0x1b) >> 0x1f;
  }
  return uVar2;
}

