
int X509_check_purpose(X509 *x,int id,int ca)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  int in_GS_OFFSET;
  int local_2c [7];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if ((*(byte *)((int)&x->ex_flags + 1) & 1) == 0) {
    CRYPTO_lock(0,9,(char *)0x3,(int)"v3_purp.c");
    if ((*(byte *)((int)&x->ex_flags + 1) & 1) == 0) {
      iVar1 = x509v3_cache_extensions_part_6();
    }
    CRYPTO_lock(iVar1,10,(char *)0x3,(int)"v3_purp.c");
  }
  if (id == -1) {
    uVar3 = 1;
    goto LAB_081744dc;
  }
  uVar3 = id - 1;
  if (8 < uVar3) {
    local_2c[0] = id;
    if ((xptable == (_STACK *)0x0) || (iVar1 = sk_find(xptable,local_2c), iVar1 == -1)) {
      uVar3 = 0xffffffff;
      goto LAB_081744dc;
    }
    uVar3 = iVar1 + 9;
    if (uVar3 == 0xffffffff) goto LAB_081744dc;
    if ((int)uVar3 < 0) {
      do {
        invalidInstructionException();
      } while( true );
    }
  }
  if ((int)uVar3 < 9) {
    puVar2 = xstandard + uVar3 * 0x1c;
  }
  else {
    puVar2 = (undefined1 *)sk_value(xptable,uVar3 - 9);
  }
  uVar3 = (**(code **)(puVar2 + 0xc))(puVar2,x,ca);
LAB_081744dc:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

