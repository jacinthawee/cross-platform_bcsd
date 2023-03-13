
undefined4 generate_key(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  BN_CTX *ctx;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  char *pcVar7;
  BIGNUM *rnd;
  undefined4 uVar8;
  int iVar9;
  BN_MONT_CTX *pBVar10;
  undefined4 uVar11;
  BN_CTX *in_stack_ffffffb4;
  BN_MONT_CTX *in_stack_ffffffb8;
  BIGNUM local_38;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (ctx == (BN_CTX *)0x0) {
LAB_00515c98:
    rnd = (BIGNUM *)0x0;
    iVar9 = 0;
LAB_00515abc:
    puVar6 = (undefined4 *)0x3;
    pcVar7 = "dh_key.c";
    uVar11 = 0xb8;
    iVar3 = 0x67;
    uVar8 = 0;
    ERR_put_error(5,0x67,3,"dh_key.c",0xb8);
    if (iVar9 == 0) goto LAB_00515af4;
    iVar4 = *(int *)(param_1 + 0x14);
  }
  else {
    rnd = *(BIGNUM **)(param_1 + 0x18);
    bVar1 = false;
    if (rnd == (BIGNUM *)0x0) {
      rnd = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
      if (rnd == (BIGNUM *)0x0) goto LAB_00515c98;
      bVar1 = true;
    }
    iVar9 = *(int *)(param_1 + 0x14);
    if ((iVar9 == 0) && (iVar9 = (*(code *)PTR_BN_new_006a71b4)(), iVar9 == 0)) goto LAB_00515abc;
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      pBVar10 = (BN_MONT_CTX *)0x0;
      if (!bVar1) {
LAB_00515b8c:
        uVar5 = *(uint *)(param_1 + 0x1c);
        goto LAB_00515b90;
      }
LAB_00515a54:
      if (*(BIGNUM **)(param_1 + 0x24) == (BIGNUM *)0x0) {
        iVar3 = *(int *)(param_1 + 0x10);
        if (iVar3 == 0) {
          iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(param_1 + 8));
          iVar3 = iVar3 + -1;
        }
        iVar3 = BN_rand(rnd,iVar3,0,0);
        if (iVar3 != 0) goto LAB_00515b8c;
      }
      else {
        iVar3 = BN_rand_range(rnd,*(BIGNUM **)(param_1 + 0x24));
        while (iVar3 != 0) {
          if ((rnd->top != 0) && (((rnd->top != 1 || (*rnd->d != 1)) || (rnd->neg != 0))))
          goto LAB_00515b8c;
          iVar3 = BN_rand_range(rnd,*(BIGNUM **)(param_1 + 0x24));
        }
      }
      goto LAB_00515abc;
    }
    pBVar10 = BN_MONT_CTX_set_locked
                        ((BN_MONT_CTX **)(param_1 + 0x20),0x1a,*(BIGNUM **)(param_1 + 8),ctx);
    if (pBVar10 == (BN_MONT_CTX *)0x0) goto LAB_00515abc;
    if (bVar1) goto LAB_00515a54;
    uVar5 = *(uint *)(param_1 + 0x1c);
LAB_00515b90:
    pcVar7 = (char *)rnd;
    if ((uVar5 & 2) == 0) {
      (*(code *)PTR_BN_init_006a857c)(&local_38);
      local_38.d = rnd->d;
      local_38.top = rnd->top;
      local_38.dmax = rnd->dmax;
      local_38.neg = rnd->neg;
      local_38.flags = local_38.flags & 1U | rnd->flags & 0xfffffffeU | 6;
      pcVar7 = (char *)&local_38;
    }
    uVar11 = *(undefined4 *)(param_1 + 8);
    puVar6 = *(undefined4 **)(param_1 + 0xc);
    iVar3 = iVar9;
    in_stack_ffffffb4 = ctx;
    iVar4 = (**(code **)(*(int *)(param_1 + 0x44) + 0xc))
                      (param_1,iVar9,puVar6,pcVar7,uVar11,ctx,pBVar10);
    in_stack_ffffffb8 = pBVar10;
    if (iVar4 == 0) goto LAB_00515abc;
    *(int *)(param_1 + 0x14) = iVar9;
    uVar8 = 1;
    *(BIGNUM **)(param_1 + 0x18) = rnd;
    iVar4 = iVar9;
  }
  if (iVar4 == 0) {
    (*(code *)PTR_BN_free_006a701c)(iVar9);
  }
LAB_00515af4:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
    (*(code *)PTR_BN_free_006a701c)(rnd);
  }
  (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  if (local_24 != *(int *)puVar2) {
    iVar9 = local_24;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if ((puVar6[1] == 1) && ((*(uint *)(iVar9 + 0x1c) & 2) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00515d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar11 = (*(code *)PTR_BN_mod_exp_mont_word_006a8784)
                         (iVar3,*(undefined4 *)*puVar6,pcVar7,uVar11,in_stack_ffffffb4,
                          in_stack_ffffffb8);
      return uVar11;
    }
                    /* WARNING: Could not recover jumptable at 0x00515d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar11 = (*(code *)PTR_BN_mod_exp_mont_006a85d0)
                       (iVar3,puVar6,pcVar7,uVar11,in_stack_ffffffb4,in_stack_ffffffb8);
    return uVar11;
  }
  return uVar8;
}

