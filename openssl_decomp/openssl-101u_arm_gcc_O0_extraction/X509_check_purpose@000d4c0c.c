
int X509_check_purpose(X509 *x,int id,int ca)

{
  uint uVar1;
  undefined1 *puVar2;
  int iVar3;
  int local_2c [7];
  
  if (-1 < (int)(x->ex_flags << 0x17)) {
    CRYPTO_lock(9,3,"v3_purp.c",0x84);
    if (-1 < (int)(x->ex_flags << 0x17)) {
      x509v3_cache_extensions_part_6(x);
    }
    CRYPTO_lock(10,3,"v3_purp.c",0x86);
  }
  if (id == -1) {
    return 1;
  }
  uVar1 = id - 1;
  if (8 < uVar1) {
    if ((xptable == (_STACK *)0x0) ||
       (local_2c[0] = id, iVar3 = sk_find(xptable,local_2c), iVar3 == -1)) {
      return -1;
    }
    uVar1 = iVar3 + 9;
    if (iVar3 == -10) {
      return uVar1;
    }
    if ((int)uVar1 < 0) {
      puVar2 = (undefined1 *)0x0;
      goto LAB_000d4c3e;
    }
  }
  if ((int)uVar1 < 9) {
    puVar2 = &xstandard + uVar1 * 0x1c;
  }
  else {
    puVar2 = (undefined1 *)sk_value(xptable,uVar1 - 9);
  }
LAB_000d4c3e:
  iVar3 = (**(code **)(puVar2 + 0xc))(puVar2,x,ca);
  return iVar3;
}

