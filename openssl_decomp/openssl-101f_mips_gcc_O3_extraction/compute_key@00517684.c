
undefined4 compute_key(undefined4 param_1,BIGNUM *param_2,DH *param_3)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  BN_CTX *ctx;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  BIGNUM *rnd;
  BN_CTX *unaff_s1;
  undefined4 uVar9;
  BIGNUM *unaff_s4;
  int iVar10;
  BN_MONT_CTX *unaff_s5;
  BN_MONT_CTX *pBVar11;
  undefined4 uVar12;
  BN_CTX *in_stack_ffffff64;
  BN_MONT_CTX *in_stack_ffffff68;
  BIGNUM BStack_88;
  int iStack_74;
  undefined4 uStack_70;
  BN_CTX *pBStack_6c;
  undefined *puStack_68;
  BIGNUM *pBStack_64;
  BIGNUM *pBStack_60;
  BN_MONT_CTX *pBStack_5c;
  undefined4 uStack_58;
  code *pcStack_54;
  int local_28;
  int local_24;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(param_3->p);
  if (iVar3 < 0x2711) {
    unaff_s1 = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a8a38)();
    if (unaff_s1 == (BN_CTX *)0x0) goto LAB_005178a8;
    (*(code *)PTR_BN_CTX_start_006a9644)(unaff_s1);
    unaff_s4 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(unaff_s1);
    if (param_3->priv_key == (BIGNUM *)0x0) {
      iVar10 = 100;
      iVar3 = 0xe0;
LAB_00517864:
      uStack_70 = 0xffffffff;
      ERR_put_error(5,0x66,iVar10,"dh_key.c",iVar3);
    }
    else {
      if ((param_3->flags & 1U) == 0) {
        unaff_s5 = (BN_MONT_CTX *)0x0;
LAB_00517744:
        iVar3 = DH_check_pub_key(param_3,param_2,&local_28);
        if ((iVar3 == 0) || (local_28 != 0)) {
          iVar10 = 0x66;
          iVar3 = 0xf3;
        }
        else {
          iVar3 = (*param_3->meth->bn_mod_exp)
                            (param_3,unaff_s4,param_2,param_3->priv_key,param_3->p,unaff_s1,unaff_s5
                            );
          if (iVar3 != 0) {
            uStack_70 = (*(code *)PTR_BN_bn2bin_006a8300)(unaff_s4,param_1);
            goto LAB_005177b0;
          }
          iVar10 = 3;
          iVar3 = 0xf9;
        }
        goto LAB_00517864;
      }
      unaff_s5 = BN_MONT_CTX_set_locked(&param_3->method_mont_p,0x1a,param_3->p,unaff_s1);
      if ((param_3->flags & 2U) == 0) {
        param_3->priv_key->flags = param_3->priv_key->flags | 4;
      }
      if (unaff_s5 != (BN_MONT_CTX *)0x0) goto LAB_00517744;
      uStack_70 = 0xffffffff;
    }
LAB_005177b0:
    (*(code *)PTR_BN_CTX_end_006a9654)(unaff_s1);
    (*(code *)PTR_BN_CTX_free_006a8a40)(unaff_s1);
  }
  else {
    ERR_put_error(5,0x66,0x67,"dh_key.c",0xd5);
LAB_005178a8:
    uStack_70 = 0xffffffff;
  }
  if (local_24 == *(int *)puStack_68) {
    return uStack_70;
  }
  pcStack_54 = generate_key;
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_6c = unaff_s1;
  pBStack_64 = param_2;
  pBStack_60 = unaff_s4;
  pBStack_5c = unaff_s5;
  uStack_58 = param_1;
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  if (ctx == (BN_CTX *)0x0) {
LAB_00517bb8:
    rnd = (BIGNUM *)0x0;
    iVar10 = 0;
LAB_005179dc:
    puVar7 = (undefined4 *)0x3;
    pcVar8 = "dh_key.c";
    uVar12 = 0xc3;
    iVar4 = 0x67;
    uVar9 = 0;
    ERR_put_error(5,0x67,3,"dh_key.c",0xc3);
    if (iVar10 == 0) goto LAB_00517a14;
    iVar5 = *(int *)(iVar3 + 0x14);
  }
  else {
    rnd = *(BIGNUM **)(iVar3 + 0x18);
    bVar1 = false;
    if (rnd == (BIGNUM *)0x0) {
      rnd = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
      if (rnd == (BIGNUM *)0x0) goto LAB_00517bb8;
      bVar1 = true;
    }
    iVar10 = *(int *)(iVar3 + 0x14);
    if ((iVar10 == 0) && (iVar10 = (*(code *)PTR_BN_new_006a82b4)(), iVar10 == 0))
    goto LAB_005179dc;
    if ((*(uint *)(iVar3 + 0x1c) & 1) == 0) {
      pBVar11 = (BN_MONT_CTX *)0x0;
      if (!bVar1) {
LAB_00517aac:
        uVar6 = *(uint *)(iVar3 + 0x1c);
        goto LAB_00517ab0;
      }
LAB_00517974:
      if (*(BIGNUM **)(iVar3 + 0x24) == (BIGNUM *)0x0) {
        iVar4 = *(int *)(iVar3 + 0x10);
        if (iVar4 == 0) {
          iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar3 + 8));
          iVar4 = iVar4 + -1;
        }
        iVar4 = BN_rand(rnd,iVar4,0,0);
        if (iVar4 != 0) goto LAB_00517aac;
      }
      else {
        iVar4 = BN_rand_range(rnd,*(BIGNUM **)(iVar3 + 0x24));
        while (iVar4 != 0) {
          if ((rnd->top != 0) && (((rnd->top != 1 || (*rnd->d != 1)) || (rnd->neg != 0))))
          goto LAB_00517aac;
          iVar4 = BN_rand_range(rnd,*(BIGNUM **)(iVar3 + 0x24));
        }
      }
      goto LAB_005179dc;
    }
    pBVar11 = BN_MONT_CTX_set_locked
                        ((BN_MONT_CTX **)(iVar3 + 0x20),0x1a,*(BIGNUM **)(iVar3 + 8),ctx);
    if (pBVar11 == (BN_MONT_CTX *)0x0) goto LAB_005179dc;
    if (bVar1) goto LAB_00517974;
    uVar6 = *(uint *)(iVar3 + 0x1c);
LAB_00517ab0:
    pcVar8 = (char *)rnd;
    if ((uVar6 & 2) == 0) {
      (*(code *)PTR_BN_init_006a96a0)(&BStack_88);
      BStack_88.d = rnd->d;
      BStack_88.top = rnd->top;
      BStack_88.dmax = rnd->dmax;
      BStack_88.neg = rnd->neg;
      BStack_88.flags = BStack_88.flags & 1U | rnd->flags & 0xfffffffeU | 6;
      pcVar8 = (char *)&BStack_88;
    }
    uVar12 = *(undefined4 *)(iVar3 + 8);
    puVar7 = *(undefined4 **)(iVar3 + 0xc);
    iVar4 = iVar10;
    in_stack_ffffff64 = ctx;
    iVar5 = (**(code **)(*(int *)(iVar3 + 0x44) + 0xc))
                      (iVar3,iVar10,puVar7,pcVar8,uVar12,ctx,pBVar11);
    in_stack_ffffff68 = pBVar11;
    if (iVar5 == 0) goto LAB_005179dc;
    *(int *)(iVar3 + 0x14) = iVar10;
    uVar9 = 1;
    *(BIGNUM **)(iVar3 + 0x18) = rnd;
    iVar5 = iVar10;
  }
  if (iVar5 == 0) {
    (*(code *)PTR_BN_free_006a811c)(iVar10);
  }
LAB_00517a14:
  if ((rnd != (BIGNUM *)0x0) && (*(int *)(iVar3 + 0x18) == 0)) {
    (*(code *)PTR_BN_free_006a811c)(rnd);
  }
  (*(code *)PTR_BN_CTX_free_006a8a40)(ctx);
  if (iStack_74 != *(int *)puVar2) {
    iVar3 = iStack_74;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if ((puVar7[1] == 1) && ((*(uint *)(iVar3 + 0x1c) & 2) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00517c74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar12 = (*(code *)PTR_BN_mod_exp_mont_word_006a98a8)
                         (iVar4,*(undefined4 *)*puVar7,pcVar8,uVar12,in_stack_ffffff64,
                          in_stack_ffffff68);
      return uVar12;
    }
                    /* WARNING: Could not recover jumptable at 0x00517c44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)PTR_BN_mod_exp_mont_006a96f4)
                       (iVar4,puVar7,pcVar8,uVar12,in_stack_ffffff64,in_stack_ffffff68);
    return uVar12;
  }
  return uVar9;
}

