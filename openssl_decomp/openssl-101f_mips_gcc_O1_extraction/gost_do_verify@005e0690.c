
bool gost_do_verify(char *param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  char cVar1;
  undefined *puVar2;
  BN_CTX *ctx;
  int iVar3;
  char *pcVar4;
  BIGNUM *m;
  BIGNUM *rem;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  BIGNUM *m_00;
  BIGNUM *rem_00;
  bool bVar10;
  undefined4 uVar8;
  undefined4 uVar9;
  char *pcVar11;
  char cStack_4d;
  char local_4c [32];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(ctx);
  iVar3 = (*(code *)PTR_BN_cmp_006a8a4c)(param_3[1],*(undefined4 *)(param_4 + 0x10));
  if ((iVar3 < 1) &&
     (iVar3 = (*(code *)PTR_BN_cmp_006a8a4c)(*param_3,*(undefined4 *)(param_4 + 0x10)), iVar3 < 1))
  {
    pcVar11 = local_4c + 0x1f;
    do {
      cVar1 = *param_1;
      pcVar4 = pcVar11 + -1;
      param_1 = param_1 + 1;
      *pcVar11 = cVar1;
      pcVar11 = pcVar4;
    } while (pcVar4 != &cStack_4d);
    iVar3 = 0x20;
    pcVar11 = local_4c;
    if (local_4c[0] == '\0') {
      do {
        pcVar11 = pcVar11 + 1;
        iVar3 = iVar3 + -1;
        if (*pcVar11 != '\0') {
          if (iVar3 != 0) goto LAB_005e07ec;
          break;
        }
      } while (iVar3 != 0);
      m = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
      (*(code *)PTR_BN_set_word_006a8820)(m,0);
    }
    else {
LAB_005e07ec:
      m = (BIGNUM *)(*(code *)PTR_BN_bin2bn_006a89f0)(pcVar11,iVar3,0);
    }
    rem = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    uVar8 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    uVar9 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    uVar5 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    uVar6 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    uVar7 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    m_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    rem_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    BN_div((BIGNUM *)0x0,rem,m,*(BIGNUM **)(param_4 + 0x10),ctx);
    if (rem->top == 0) {
      (*(code *)PTR_BN_set_word_006a8820)(m,1);
    }
    (*(code *)PTR_BN_copy_006a9570)(uVar9,*(undefined4 *)(param_4 + 0x10));
    (*(code *)PTR_BN_sub_word_006a95bc)(uVar9,2);
    (*(code *)PTR_BN_mod_exp_006a8a48)(uVar8,m,uVar9,*(undefined4 *)(param_4 + 0x10),ctx);
    (*(code *)PTR_BN_mod_mul_006a9698)(uVar5,param_3[1],uVar8,*(undefined4 *)(param_4 + 0x10),ctx);
    BN_sub(rem,*(BIGNUM **)(param_4 + 0x10),*param_3);
    (*(code *)PTR_BN_mod_mul_006a9698)(uVar6,rem,uVar8,*(undefined4 *)(param_4 + 0xc),ctx);
    (*(code *)PTR_BN_mod_exp_006a8a48)
              (rem,*(undefined4 *)(param_4 + 0x14),uVar5,*(undefined4 *)(param_4 + 0xc),ctx);
    (*(code *)PTR_BN_mod_exp_006a8a48)
              (uVar7,*(undefined4 *)(param_4 + 0x18),uVar6,*(undefined4 *)(param_4 + 0xc),ctx);
    (*(code *)PTR_BN_mod_mul_006a9698)(m_00,rem,uVar7,*(undefined4 *)(param_4 + 0xc),ctx);
    BN_div((BIGNUM *)0x0,rem_00,m_00,*(BIGNUM **)(param_4 + 0x10),ctx);
    iVar3 = (*(code *)PTR_BN_cmp_006a8a4c)(rem_00,*param_3);
    (*(code *)PTR_BN_free_006a811c)(m);
    (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
    (*(code *)PTR_BN_CTX_free_006a8a40)(ctx);
    if (iVar3 == 0) {
      bVar10 = true;
    }
    else {
      (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x71,0x7e,"gost_sign.c",0xb9);
      bVar10 = iVar3 == 0;
    }
  }
  else {
    (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x71,0x7f,"gost_sign.c",0x95);
    bVar10 = false;
  }
  if (local_2c == *(int *)puVar2) {
    return bVar10;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar8 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (*(int *)(iVar3 + 0x14) == 0) {
    (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x6e,0x71,"gost_sign.c",200);
    return false;
  }
  uVar9 = (*(code *)PTR_BN_new_006a82b4)();
  puVar2 = PTR_BN_mod_exp_006a8a48;
  *(undefined4 *)(iVar3 + 0x18) = uVar9;
  (*(code *)puVar2)(uVar9,*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x1c),
                    *(undefined4 *)(iVar3 + 0xc),uVar8);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar8);
  return true;
}

