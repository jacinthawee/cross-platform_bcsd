
BN_MONT_CTX * BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  undefined *puVar1;
  BIGNUM *r;
  BIGNUM *pBVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  BN_MONT_CTX *pBVar8;
  BIGNUM *a;
  BIGNUM *a_00;
  code *pcVar9;
  BIGNUM local_48;
  ulong local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_lock_006a8144)(5,lock,"bn_mont.c",0x20f);
  pBVar8 = *pmont;
  (*(code *)PTR_CRYPTO_lock_006a8144)(6,lock,"bn_mont.c",0x211);
  if (pBVar8 != (BN_MONT_CTX *)0x0) goto LAB_00500790;
  pBVar8 = (BN_MONT_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x4c,"bn_mont.c",0x155);
  if (pBVar8 != (BN_MONT_CTX *)0x0) {
    a = &pBVar8->RR;
    pBVar8->ri = 0;
    a_00 = &pBVar8->N;
    BN_init(a);
    BN_init(a_00);
    BN_init(&pBVar8->Ni);
    iVar5 = mod->top;
    pBVar8->n0[1] = 0;
    pBVar8->n0[0] = 0;
    pBVar8->flags = 1;
    if (iVar5 != 0) {
      BN_CTX_start(ctx);
      r = BN_CTX_get(ctx);
      if ((r != (BIGNUM *)0x0) && (pBVar2 = BN_copy(a_00,mod), pBVar2 != (BIGNUM *)0x0)) {
        (pBVar8->N).neg = 0;
        BN_init(&local_48);
        local_48.neg = 0;
        local_48.dmax = 2;
        local_48.d = &local_34;
        iVar3 = BN_num_bits(mod);
        iVar5 = iVar3 + 0x1f;
        if (iVar3 + 0x1f < 0) {
          iVar5 = iVar3 + 0x3e;
        }
        pBVar8->ri = (iVar5 >> 5) << 5;
        BN_set_word(a,0);
        iVar5 = BN_set_bit(a,0x20);
        if (iVar5 != 0) {
          local_34 = *mod->d;
          local_30 = 0;
          local_48.top = (int)(local_34 != 0);
          iVar5 = (*(code *)PTR_BN_mod_inverse_006a85f0)(r,a,&local_48,ctx);
          if ((iVar5 != 0) && (iVar5 = BN_lshift(r,r,0x20), iVar5 != 0)) {
            if (r->top == 0) {
              iVar5 = BN_set_word(r,0xffffffff);
            }
            else {
              iVar5 = BN_sub_word(r,1);
            }
            if ((iVar5 != 0) &&
               (iVar5 = (*(code *)PTR_BN_div_006a855c)(r,0,r,&local_48,ctx), iVar5 != 0)) {
              uVar4 = 0;
              if (0 < r->top) {
                uVar4 = *r->d;
              }
              pBVar8->n0[0] = uVar4;
              pBVar8->n0[1] = 0;
              BN_set_word(a,0);
              iVar5 = BN_set_bit(a,pBVar8->ri << 1);
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_BN_div_006a855c)(0,a,a,a_00,ctx);
                BN_CTX_end(ctx);
                if (iVar5 != 0) {
                  (*(code *)PTR_CRYPTO_lock_006a8144)(9,lock,"bn_mont.c",0x226);
                  if (*pmont == (BN_MONT_CTX *)0x0) {
                    *pmont = pBVar8;
                  }
                  else {
                    BN_clear_free(a);
                    BN_clear_free(a_00);
                    BN_clear_free(&pBVar8->Ni);
                    if ((pBVar8->flags & 1U) != 0) {
                      (*(code *)PTR_CRYPTO_free_006a6e88)(pBVar8);
                    }
                    pBVar8 = *pmont;
                  }
                  (*(code *)PTR_CRYPTO_lock_006a8144)(10,lock,"bn_mont.c",0x22c);
                  goto LAB_00500790;
                }
                goto LAB_00500848;
              }
            }
          }
        }
      }
      BN_CTX_end(ctx);
    }
LAB_00500848:
    BN_clear_free(a);
    BN_clear_free(a_00);
    BN_clear_free(&pBVar8->Ni);
    if ((pBVar8->flags & 1U) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(pBVar8);
      pBVar8 = (BN_MONT_CTX *)0x0;
      goto LAB_00500790;
    }
  }
  pBVar8 = (BN_MONT_CTX *)0x0;
LAB_00500790:
  if (local_2c == *(int *)puVar1) {
    return pBVar8;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar5 == 0) {
    uVar7 = 0x6c;
    uVar6 = 0x50;
  }
  else {
    if (*(int *)(iVar5 + 8) != 0) {
      pBVar8 = (BN_MONT_CTX *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xac,"ec_lib.c",0x58);
      if (pBVar8 == (BN_MONT_CTX *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x6c,0x41,"ec_lib.c",0x5a);
        return (BN_MONT_CTX *)0x0;
      }
      pBVar8->ri = iVar5;
      pBVar8->n0[1] = 0;
      (pBVar8->RR).d = (ulong *)0x0;
      BN_init((BIGNUM *)&(pBVar8->RR).top);
      BN_init((BIGNUM *)&(pBVar8->N).top);
      pcVar9 = *(code **)(iVar5 + 8);
      (pBVar8->Ni).top = 0;
      (pBVar8->Ni).dmax = 0;
      (pBVar8->Ni).neg = 4;
      (pBVar8->Ni).flags = 0;
      pBVar8->n0[0] = 0;
      iVar5 = (*pcVar9)(pBVar8);
      if (iVar5 != 0) {
        return pBVar8;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      return (BN_MONT_CTX *)0x0;
    }
    uVar7 = 0x42;
    uVar6 = 0x54;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x6c,uVar7,"ec_lib.c",uVar6);
  return (BN_MONT_CTX *)0x0;
}

