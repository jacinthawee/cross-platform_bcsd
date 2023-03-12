
BIGNUM ** gost_do_sign(char *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  BIGNUM *m;
  BN_CTX *ctx;
  BIGNUM **ppBVar4;
  BIGNUM *rem;
  int iVar5;
  BIGNUM *pBVar6;
  undefined4 *puVar7;
  int iVar8;
  BIGNUM *pBVar9;
  char *pcVar10;
  int *piVar11;
  undefined4 uVar12;
  char cStack_4d;
  char local_4c [32];
  undefined4 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pcVar10 = local_4c + 0x1f;
  do {
    cVar1 = *param_1;
    pcVar3 = pcVar10 + -1;
    param_1 = param_1 + 1;
    *pcVar10 = cVar1;
    pcVar10 = pcVar3;
  } while (&cStack_4d != pcVar3);
  iVar8 = 0x20;
  pcVar10 = local_4c;
  if (local_4c[0] == '\0') {
    do {
      pcVar10 = pcVar10 + 1;
      iVar8 = iVar8 + -1;
      if (*pcVar10 != '\0') {
        if (iVar8 != 0) goto LAB_005ddcd8;
        break;
      }
    } while (iVar8 != 0);
    m = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
    (*(code *)PTR_BN_set_word_006a7730)(m,0);
  }
  else {
LAB_005ddcd8:
    m = (BIGNUM *)(*(code *)PTR_BN_bin2bn_006a7904)(pcVar10,iVar8,0);
  }
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (ctx == (BN_CTX *)0x0) {
    piVar11 = (int *)&DAT_0000003d;
    pcVar10 = "gost_sign.c";
    pBVar9 = (BIGNUM *)&DAT_00000041;
    ppBVar4 = (BIGNUM **)0x0;
    (*(code *)PTR_ERR_GOST_error_006a95e4)(0x70,0x41,"gost_sign.c");
    (*(code *)PTR_BN_free_006a701c)(m);
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
    ppBVar4 = (BIGNUM **)(*(code *)PTR_DSA_SIG_new_006a875c)();
    if (ppBVar4 == (BIGNUM **)0x0) {
      piVar11 = (int *)0x43;
      pcVar10 = "gost_sign.c";
      pBVar9 = (BIGNUM *)&DAT_00000076;
      (*(code *)PTR_ERR_GOST_error_006a95e4)(0x70,0x76,"gost_sign.c");
    }
    else {
      rem = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      pcVar3 = (char *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      if (((rem == (BIGNUM *)0x0) || (iVar8 == 0)) || (pcVar3 == (char *)0x0)) {
        piVar11 = (int *)0x4a;
LAB_005dde58:
        pBVar9 = (BIGNUM *)&DAT_00000041;
        pcVar10 = "gost_sign.c";
        (*(code *)PTR_ERR_GOST_error_006a95e4)(0x70,0x41,"gost_sign.c");
        (*(code *)PTR_BN_free_006a701c)(m);
        (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
        (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
        (*(code *)PTR_DSA_SIG_free_006a8758)(ppBVar4);
        ppBVar4 = (BIGNUM **)0x0;
        goto LAB_005ddeb4;
      }
      BN_div((BIGNUM *)0x0,rem,m,*(BIGNUM **)(param_3 + 0x10),ctx);
      if (rem->top == 0) {
        (*(code *)PTR_BN_set_word_006a7730)(m,1);
      }
      do {
        do {
          (*(code *)PTR_BN_rand_range_006a868c)(iVar8,*(undefined4 *)(param_3 + 0x10));
          (*(code *)PTR_BN_mod_exp_006a795c)
                    (rem,*(undefined4 *)(param_3 + 0x14),iVar8,*(undefined4 *)(param_3 + 0xc),ctx);
          pBVar9 = *ppBVar4;
          if (pBVar9 == (BIGNUM *)0x0) {
            pBVar9 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
            *ppBVar4 = pBVar9;
            if (pBVar9 == (BIGNUM *)0x0) {
              piVar11 = (int *)&DAT_0000005c;
              goto LAB_005dde58;
            }
          }
          BN_div((BIGNUM *)0x0,pBVar9,rem,*(BIGNUM **)(param_3 + 0x10),ctx);
        } while ((*ppBVar4)->top == 0);
        (*(code *)PTR_BN_mod_mul_006a8574)
                  (rem,*(undefined4 *)(param_3 + 0x1c),*ppBVar4,*(undefined4 *)(param_3 + 0x10),ctx)
        ;
        (*(code *)PTR_BN_mod_mul_006a8574)(pcVar3,iVar8,m,*(undefined4 *)(param_3 + 0x10),ctx);
        pBVar6 = ppBVar4[1];
        if (pBVar6 == (BIGNUM *)0x0) {
          pBVar6 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
          ppBVar4[1] = pBVar6;
          if (pBVar6 == (BIGNUM *)0x0) {
            piVar11 = (int *)&DAT_00000069;
            goto LAB_005dde58;
          }
        }
        piVar11 = *(int **)(param_3 + 0x10);
        pBVar9 = rem;
        pcVar10 = pcVar3;
        (*(code *)PTR_BN_mod_add_006a9510)(pBVar6,rem,pcVar3,piVar11,ctx);
      } while (ppBVar4[1]->top == 0);
    }
    (*(code *)PTR_BN_free_006a701c)(m);
    (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
    (*(code *)PTR_BN_CTX_free_006a7954)(ctx);
  }
LAB_005ddeb4:
  if (local_2c != *(undefined4 **)puVar2) {
    puVar7 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar2 = PTR_memset_006a99f4;
    *piVar11 = (int)pBVar9 << 1;
    (*(code *)puVar2)(pcVar10,0,(int)pBVar9 << 1);
    uVar12 = puVar7[1];
    iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar12);
    iVar8 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar8 = iVar5 + 0xe;
    }
    if (iVar8 >> 3 <= (int)pBVar9) {
      (*(code *)PTR_memset_006a99f4)(pcVar10,0,pBVar9);
      (*(code *)PTR_BN_bn2bin_006a7200)
                (uVar12,(undefined *)((int)pBVar9 + ((int)pcVar10 - (iVar8 >> 3))));
    }
    uVar12 = *puVar7;
    iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar12);
    iVar8 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar8 = iVar5 + 0xe;
    }
    if (iVar8 >> 3 <= (int)pBVar9) {
      pcVar10 = (char *)((int)&pBVar9->d + (int)pcVar10);
      (*(code *)PTR_memset_006a99f4)(pcVar10,0,pBVar9);
      (*(code *)PTR_BN_bn2bin_006a7200)
                (uVar12,(undefined *)((int)pBVar9 + ((int)pcVar10 - (iVar8 >> 3))));
    }
    (*(code *)PTR_DSA_SIG_free_006a8758)(puVar7);
    return (BIGNUM **)0x1;
  }
  return ppBVar4;
}

