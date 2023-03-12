
void keyUnwrapCryptoPro(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined auStack_40 [4];
  undefined auStack_3c [32];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  keyDiversifyCryptoPro();
  gost_key(param_1,auStack_3c);
  gost_dec(param_1,param_3 + 8,param_4,4);
  gost_mac_iv(param_1,0x20,param_3,param_4,0x20,auStack_40);
  iVar1 = memcmp(auStack_40,(void *)(param_3 + 0x28),4);
  uVar2 = count_leading_zeroes(iVar1);
  if (local_1c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2 >> 5);
}

