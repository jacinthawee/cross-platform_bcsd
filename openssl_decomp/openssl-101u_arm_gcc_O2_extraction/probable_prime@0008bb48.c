
undefined4 probable_prime(BIGNUM *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  uint extraout_r1;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  ushort uStack_1028;
  ushort local_1026 [2049];
  
  puVar1 = PTR_DAT_0008bbd0;
  do {
    iVar2 = BN_rand(param_1,param_2,1,1);
    puVar4 = (ushort *)PTR_primes_0008bbd4;
    puVar5 = &uStack_1028;
    if (iVar2 == 0) {
      return 0;
    }
    do {
      puVar4 = puVar4 + 1;
      uVar3 = BN_mod_word(param_1,(uint)*puVar4);
      puVar5[1] = (short)uVar3;
      puVar5 = puVar5 + 1;
    } while (puVar4 != (ushort *)puVar1);
    uVar3 = 0;
    do {
      puVar6 = (undefined2 *)&primes;
      puVar4 = &uStack_1028;
      while( true ) {
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
        __aeabi_uidivmod(*puVar4 + uVar3,*puVar6);
        if (extraout_r1 < 2) break;
        if (puVar4 == local_1026 + 0x7fe) {
          iVar2 = BN_add_word(param_1,uVar3);
          if (iVar2 == 0) {
            return 0;
          }
          return 1;
        }
      }
      uVar3 = uVar3 + 2;
    } while (uVar3 != 0xffffba3a);
  } while( true );
}

