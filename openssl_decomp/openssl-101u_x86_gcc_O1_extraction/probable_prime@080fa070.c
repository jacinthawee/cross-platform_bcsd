
uint __regparm3 probable_prime(BIGNUM *param_1,int param_2)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int in_GS_OFFSET;
  ushort auStack_1020 [2048];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  do {
    uVar1 = BN_rand(param_1,param_2,1,1);
    if (uVar1 == 0) {
LAB_080fa12d:
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return uVar1;
    }
    iVar3 = 0;
    do {
      uVar2 = BN_mod_word(param_1,(uint)*(ushort *)(primes + iVar3 + 2));
      *(short *)((int)auStack_1020 + iVar3 + 2) = (short)uVar2;
      iVar3 = iVar3 + 2;
    } while (iVar3 != 0xffe);
    uVar2 = 0;
    do {
      iVar3 = 1;
      while (1 < (auStack_1020[iVar3] + uVar2) % (uint)*(ushort *)(primes + iVar3 * 2)) {
        iVar3 = iVar3 + 1;
        if (iVar3 == 0x800) {
          iVar3 = BN_add_word(param_1,uVar2);
          uVar1 = (uint)(iVar3 != 0);
          goto LAB_080fa12d;
        }
      }
      uVar2 = uVar2 + 2;
    } while (uVar2 != 0xffffba3a);
  } while( true );
}

