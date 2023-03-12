
BIGNUM ** gost_do_sign(char *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  BIGNUM **ppBVar3;
  BIGNUM *m;
  BN_CTX *ctx;
  BIGNUM *rem;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  BIGNUM *pBVar7;
  undefined4 *puVar8;
  int iVar9;
  BIGNUM *pBVar10;
  char *pcVar11;
  int *piVar12;
  char cStack_4d;
  char local_4c [32];
  undefined4 *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  ppBVar3 = (BIGNUM **)(*(code *)PTR_DSA_SIG_new_006a9880)();
  pcVar11 = local_4c + 0x1f;
  do {
    cVar1 = *param_1;
    pcVar6 = pcVar11 + -1;
    param_1 = param_1 + 1;
    *pcVar11 = cVar1;
    pcVar11 = pcVar6;
  } while (pcVar6 != &cStack_4d);
  iVar9 = 0x20;
  pcVar11 = local_4c;
  if (local_4c[0] == '\0') {
    do {
      pcVar11 = pcVar11 + 1;
      iVar9 = iVar9 + -1;
      if (*pcVar11 != '\0') {
        if (iVar9 != 0) goto LAB_005e02c4;
        break;
      }
    } while (iVar9 != 0);
    m = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
    (*(code *)PTR_BN_set_word_006a8820)(m,0);
  }
  else {
LAB_005e02c4:
    m = (BIGNUM *)(*(code *)PTR_BN_bin2bn_006a89f0)(pcVar11,iVar9,0);
  }
  ctx = (BN_CTX *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(ctx);
  if (ppBVar3 == (BIGNUM **)0x0) {
    piVar12 = (int *)&DAT_0000003d;
    pcVar11 = "gost_sign.c";
    pBVar10 = (BIGNUM *)&DAT_00000076;
    (*(code *)PTR_ERR_GOST_error_006aa6f0)(0x70,0x76,"gost_sign.c");
  }
  else {
    rem = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    pcVar6 = (char *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
    BN_div((BIGNUM *)0x0,rem,m,*(BIGNUM **)(param_3 + 0x10),ctx);
    if (rem->top == 0) {
      (*(code *)PTR_BN_set_word_006a8820)(m,1);
    }
    do {
      do {
        (*(code *)PTR_BN_rand_range_006a97b0)(uVar4,*(undefined4 *)(param_3 + 0x10));
        (*(code *)PTR_BN_mod_exp_006a8a48)
                  (rem,*(undefined4 *)(param_3 + 0x14),uVar4,*(undefined4 *)(param_3 + 0xc),ctx);
        pBVar10 = *ppBVar3;
        if (pBVar10 == (BIGNUM *)0x0) {
          pBVar10 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
          *ppBVar3 = pBVar10;
        }
        BN_div((BIGNUM *)0x0,pBVar10,rem,*(BIGNUM **)(param_3 + 0x10),ctx);
      } while ((*ppBVar3)->top == 0);
      (*(code *)PTR_BN_mod_mul_006a9698)
                (rem,*(undefined4 *)(param_3 + 0x1c),*ppBVar3,*(undefined4 *)(param_3 + 0x10),ctx);
      (*(code *)PTR_BN_mod_mul_006a9698)(pcVar6,uVar4,m,*(undefined4 *)(param_3 + 0x10),ctx);
      pBVar7 = ppBVar3[1];
      if (pBVar7 == (BIGNUM *)0x0) {
        pBVar7 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
        ppBVar3[1] = pBVar7;
      }
      piVar12 = *(int **)(param_3 + 0x10);
      pBVar10 = rem;
      pcVar11 = pcVar6;
      (*(code *)PTR_BN_mod_add_006aa61c)(pBVar7,rem,pcVar6,piVar12,ctx);
    } while (ppBVar3[1]->top == 0);
  }
  (*(code *)PTR_BN_free_006a811c)(m);
  (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
  (*(code *)PTR_BN_CTX_free_006a8a40)(ctx);
  if (local_2c != *(undefined4 **)puVar2) {
    puVar8 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar2 = PTR_memset_006aab00;
    *piVar12 = (int)pBVar10 << 1;
    (*(code *)puVar2)(pcVar11,0,(int)pBVar10 << 1);
    uVar4 = puVar8[1];
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar4);
    iVar9 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar9 = iVar5 + 0xe;
    }
    if (iVar9 >> 3 <= (int)pBVar10) {
      (*(code *)PTR_memset_006aab00)(pcVar11,0,pBVar10);
      (*(code *)PTR_BN_bn2bin_006a8300)
                (uVar4,(undefined *)((int)pBVar10 + ((int)pcVar11 - (iVar9 >> 3))));
    }
    uVar4 = *puVar8;
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar4);
    iVar9 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar9 = iVar5 + 0xe;
    }
    if (iVar9 >> 3 <= (int)pBVar10) {
      pcVar11 = (char *)((int)&pBVar10->d + (int)pcVar11);
      (*(code *)PTR_memset_006aab00)(pcVar11,0,pBVar10);
      (*(code *)PTR_BN_bn2bin_006a8300)
                (uVar4,(undefined *)((int)pBVar10 + ((int)pcVar11 - (iVar9 >> 3))));
    }
    (*(code *)PTR_DSA_SIG_free_006a987c)(puVar8);
    return (BIGNUM **)0x1;
  }
  return ppBVar3;
}

