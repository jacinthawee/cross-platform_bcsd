
bool gost_do_verify(char *param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  char cVar1;
  undefined *puVar2;
  BN_CTX *ctx;
  int iVar3;
  char *pcVar4;
  BIGNUM *m;
  BIGNUM *rem;
  int iVar5;
  int iVar6;
  BIGNUM *m_00;
  BIGNUM *rem_00;
  int iVar7;
  int iVar8;
  char *pcVar9;
  bool bVar10;
  char cStack_4d;
  char local_4c [32];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (ctx == (BN_CTX *)0x0) {
    bVar10 = false;
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x71,0x41,"gost_sign.c",0xac);
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
    iVar3 = (*(code *)PTR_BN_cmp_006a7960)(param_3[1],*(undefined4 *)(param_4 + 0x10));
    if ((iVar3 < 1) &&
       (iVar3 = (*(code *)PTR_BN_cmp_006a7960)(*param_3,*(undefined4 *)(param_4 + 0x10)), iVar3 < 1)
       ) {
      pcVar9 = local_4c + 0x1f;
      do {
        cVar1 = *param_1;
        pcVar4 = pcVar9 + -1;
        param_1 = param_1 + 1;
        *pcVar9 = cVar1;
        pcVar9 = pcVar4;
      } while (pcVar4 != &cStack_4d);
      iVar3 = 0x20;
      pcVar9 = local_4c;
      if (local_4c[0] == '\0') {
        do {
          pcVar9 = pcVar9 + 1;
          iVar3 = iVar3 + -1;
          if (*pcVar9 != '\0') {
            if (iVar3 != 0) goto LAB_005de318;
            break;
          }
        } while (iVar3 != 0);
        m = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
        (*(code *)PTR_BN_set_word_006a7730)(m,0);
      }
      else {
LAB_005de318:
        m = (BIGNUM *)(*(code *)PTR_BN_bin2bn_006a7904)(pcVar9,iVar3,0);
      }
      rem = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      iVar7 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      iVar5 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      iVar6 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      m_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      rem_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      if (((((rem == (BIGNUM *)0x0) || (iVar3 == 0)) || (iVar7 == 0)) ||
          ((iVar8 == 0 || (iVar5 == 0)))) ||
         ((iVar6 == 0 || ((m_00 == (BIGNUM *)0x0 || (rem_00 == (BIGNUM *)0x0)))))) {
        bVar10 = false;
        (*(code *)PTR_ERR_GOST_error_006a95e4)(0x71,0x41,"gost_sign.c",0xc0);
      }
      else {
        BN_div((BIGNUM *)0x0,rem,m,*(BIGNUM **)(param_4 + 0x10),ctx);
        if (rem->top == 0) {
          (*(code *)PTR_BN_set_word_006a7730)(m,1);
        }
        (*(code *)PTR_BN_copy_006a8450)(iVar7,*(undefined4 *)(param_4 + 0x10));
        (*(code *)PTR_BN_sub_word_006a849c)(iVar7,2);
        (*(code *)PTR_BN_mod_exp_006a795c)(iVar3,m,iVar7,*(undefined4 *)(param_4 + 0x10),ctx);
        (*(code *)PTR_BN_mod_mul_006a8574)
                  (iVar8,param_3[1],iVar3,*(undefined4 *)(param_4 + 0x10),ctx);
        BN_sub(rem,*(BIGNUM **)(param_4 + 0x10),*param_3);
        (*(code *)PTR_BN_mod_mul_006a8574)(iVar5,rem,iVar3,*(undefined4 *)(param_4 + 0xc),ctx);
        (*(code *)PTR_BN_mod_exp_006a795c)
                  (rem,*(undefined4 *)(param_4 + 0x14),iVar8,*(undefined4 *)(param_4 + 0xc),ctx);
        (*(code *)PTR_BN_mod_exp_006a795c)
                  (iVar6,*(undefined4 *)(param_4 + 0x18),iVar5,*(undefined4 *)(param_4 + 0xc),ctx);
        (*(code *)PTR_BN_mod_mul_006a8574)(m_00,rem,iVar6,*(undefined4 *)(param_4 + 0xc),ctx);
        BN_div((BIGNUM *)0x0,rem_00,m_00,*(BIGNUM **)(param_4 + 0x10),ctx);
        iVar3 = (*(code *)PTR_BN_cmp_006a7960)(rem_00,*param_3);
        bVar10 = iVar3 == 0;
        if (iVar3 != 0) {
          (*(code *)PTR_ERR_GOST_error_006a95e4)(0x71,0x7e,"gost_sign.c",0xd5);
        }
      }
      if (m != (BIGNUM *)0x0) {
        (*(code *)PTR_BN_free_006a701c)(m);
      }
    }
    else {
      bVar10 = false;
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x71,0x7f,"gost_sign.c",0xb2);
    }
    (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
    (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  }
  if (local_2c == *(int *)puVar2) {
    return bVar10;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(iVar3 + 0x14) == 0) {
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x6e,0x71,"gost_sign.c",0xe9);
    return false;
  }
  iVar7 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar7 == 0) {
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x6e,0x41,"gost_sign.c",0xee);
    bVar10 = false;
  }
  else {
    iVar8 = (*(code *)PTR_BN_new_006a71b4)();
    *(int *)(iVar3 + 0x18) = iVar8;
    if (iVar8 == 0) {
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x6e,0x41,"gost_sign.c",0xf4);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar7);
      bVar10 = false;
    }
    else {
      (*(code *)PTR_BN_mod_exp_006a795c)
                (iVar8,*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x1c),
                 *(undefined4 *)(iVar3 + 0xc),iVar7);
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar7);
      bVar10 = true;
    }
  }
  return bVar10;
}

