
uint probable_prime(BIGNUM *param_1,BIGNUM *param_2)

{
  undefined *puVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  ushort *puVar5;
  BIGNUM *pBVar6;
  BIGNUM *m;
  BIGNUM *b;
  BIGNUM *p;
  ushort *puVar7;
  ushort *puVar8;
  undefined *local_1038;
  BN_CTX *pBStack_1034;
  BN_MONT_CTX *pBStack_1030;
  BIGNUM local_102a [204];
  BIGNUM *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar7 = (ushort *)(primes + 2);
  local_1038 = &_gp;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  do {
    p = (BIGNUM *)0x1;
    b = (BIGNUM *)0x1;
    m = param_2;
    uVar2 = BN_rand(param_1,(int)param_2,1,1);
    puVar5 = puVar7;
    pBVar6 = local_102a;
    if (uVar2 == 0) {
LAB_004fa8d0:
      if (local_2c == *(BIGNUM **)puVar1) {
        return uVar2;
      }
      pBVar6 = local_2c;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar4 = BN_mod_exp_mont(pBVar6,pBVar6,p,m,pBStack_1034,pBStack_1030);
      if (iVar4 == 0) {
        return 0xffffffff;
      }
      if (((pBVar6->top != 1) || (*pBVar6->d != 1)) || (pBVar6->neg != 0)) {
        iVar4 = BN_cmp(pBVar6,b);
        while (iVar4 != 0) {
          local_1038 = local_1038 + -1;
          if (local_1038 == (undefined *)0x0) {
            return 1;
          }
          iVar4 = BN_mod_mul(pBVar6,pBVar6,pBVar6,m,pBStack_1034);
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          if (((pBVar6->top == 1) && (*pBVar6->d == 1)) && (pBVar6->neg == 0)) {
            return 1;
          }
          iVar4 = BN_cmp(pBVar6,b);
        }
      }
      return 0;
    }
    do {
      puVar8 = puVar5 + 1;
      uVar3 = BN_mod_word(param_1,(uint)*puVar5);
      *(short *)&pBVar6->d = (short)uVar3;
      puVar5 = puVar8;
      pBVar6 = (BIGNUM *)((int)&pBVar6->d + 2);
    } while (puVar8 != (ushort *)"bn_recp.c");
    m = (BIGNUM *)0x0;
    p = (BIGNUM *)0xffffba3a;
    puVar5 = puVar7;
    b = local_102a;
    do {
      while( true ) {
        if (*puVar5 == 0) {
          trap(7);
        }
        puVar8 = puVar5 + 1;
        if (((int)&m->d + (uint)*(ushort *)&b->d) % (uint)*puVar5 < 2) break;
        b = (BIGNUM *)((int)&b->d + 2);
        puVar5 = puVar8;
        if (puVar8 == (ushort *)"bn_recp.c") {
          iVar4 = BN_add_word(param_1,(ulong)m);
          uVar2 = (uint)(iVar4 != 0);
          goto LAB_004fa8d0;
        }
      }
      m = (BIGNUM *)((int)&m->d + 2);
      puVar5 = puVar7;
      b = local_102a;
    } while (m != (BIGNUM *)0xffffba3a);
  } while( true );
}

