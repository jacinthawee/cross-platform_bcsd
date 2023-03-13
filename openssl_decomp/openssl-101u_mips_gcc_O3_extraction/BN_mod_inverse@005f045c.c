
BIGNUM * BN_mod_inverse(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  int *piVar1;
  undefined *puVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *b;
  BIGNUM *a_00;
  BIGNUM *pBVar6;
  BIGNUM *a_01;
  BIGNUM *pBVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  BIGNUM *unaff_s6;
  BIGNUM *local_68;
  BIGNUM local_54;
  ulong *local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_68 = ret;
  if (((a->flags & 4U) == 0) && ((n->flags & 4U) == 0)) {
    (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
    a_01 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    b = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    a_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    pBVar7 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    pBVar5 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    unaff_s6 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    pBVar6 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    if (pBVar6 != (BIGNUM *)0x0) {
      if (ret == (BIGNUM *)0x0) {
        local_68 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
        if (local_68 == (BIGNUM *)0x0) goto LAB_005f0d70;
        (*(code *)PTR_BN_set_word_006a7730)(a_00,1);
        (*(code *)PTR_BN_set_word_006a7730)(unaff_s6,0);
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(b,a);
        if (iVar8 == 0) goto LAB_005f0d70;
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(a_01,n);
        if (iVar8 == 0) goto LAB_005f0d70;
      }
      else {
        (*(code *)PTR_BN_set_word_006a7730)(a_00,1);
        (*(code *)PTR_BN_set_word_006a7730)(unaff_s6,0);
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(b,a);
        if (iVar8 == 0) goto LAB_005f0738;
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(a_01,n);
        if (iVar8 == 0) goto LAB_005f0738;
      }
      a_01->neg = 0;
      if (((b->neg == 0) && (iVar8 = (*(code *)PTR_BN_ucmp_006a7fb4)(b,a_01), iVar8 < 0)) ||
         (iVar8 = (*(code *)PTR_BN_nnmod_006a8548)(b,b,a_01,ctx), iVar8 != 0)) {
        if (((0 < n->top) && ((*n->d & 1) != 0)) &&
           (iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(n), iVar8 < 0x801)) goto LAB_005f0914;
        iVar8 = -1;
        pBVar3 = a_01;
        pBVar4 = b;
        a_01 = a_00;
        if (b->top == 0) goto LAB_005f1014;
        do {
          a_00 = a_01;
          b = pBVar4;
          a_01 = pBVar3;
          iVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(a_01);
          iVar10 = (*(code *)PTR_BN_num_bits_006a71f4)(b);
          if (iVar9 == iVar10) {
LAB_005f0a94:
            iVar9 = (*(code *)PTR_BN_set_word_006a7730)(pBVar7,1);
            if ((iVar9 == 0) || (iVar9 = BN_sub(pBVar5,a_01,b), iVar9 == 0)) break;
            uVar11 = pBVar7->top;
            if (uVar11 != 1) goto LAB_005f0a10;
LAB_005f0ad8:
            uVar12 = *pBVar7->d;
            if (uVar12 != uVar11) {
              if (uVar12 == 2) {
                if (pBVar7->neg != 0) goto LAB_005f0af8;
                iVar9 = (*(code *)PTR_BN_lshift1_006a85b4)(a_01,a_00);
              }
              else if ((uVar12 == 4) && (pBVar7->neg == 0)) {
                iVar9 = (*(code *)PTR_BN_lshift_006a8498)(a_01,a_00,2);
              }
              else {
LAB_005f0af8:
                iVar9 = (*(code *)PTR_BN_copy_006a8450)(a_01,a_00);
                if (iVar9 == 0) break;
                iVar9 = (*(code *)PTR_BN_mul_word_006a8570)(a_01,*pBVar7->d);
              }
              if (iVar9 != 0) goto LAB_005f0a2c;
              break;
            }
            if (pBVar7->neg != 0) goto LAB_005f0af8;
            iVar9 = BN_add(a_01,a_00,unaff_s6);
          }
          else {
            iVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(a_01);
            iVar10 = (*(code *)PTR_BN_num_bits_006a71f4)(b);
            if (iVar9 == iVar10 + 1) {
              iVar9 = (*(code *)PTR_BN_lshift1_006a85b4)(pBVar6,b);
              if (iVar9 == 0) break;
              iVar9 = (*(code *)PTR_BN_ucmp_006a7fb4)(a_01,pBVar6);
              if (iVar9 < 0) goto LAB_005f0a94;
              iVar9 = BN_sub(pBVar5,a_01,pBVar6);
              if ((iVar9 == 0) || (iVar9 = BN_add(pBVar7,pBVar6,b), iVar9 == 0)) break;
              iVar9 = (*(code *)PTR_BN_ucmp_006a7fb4)(a_01,pBVar7);
              if (iVar9 < 0) {
                iVar9 = (*(code *)PTR_BN_set_word_006a7730)(pBVar7,2);
              }
              else {
                iVar9 = (*(code *)PTR_BN_set_word_006a7730)(pBVar7,3);
                if (iVar9 == 0) break;
                iVar9 = BN_sub(pBVar5,pBVar5,b);
              }
            }
            else {
              iVar9 = BN_div(pBVar7,pBVar5,a_01,b,ctx);
            }
            if (iVar9 == 0) break;
            uVar11 = pBVar7->top;
            if (uVar11 == 1) goto LAB_005f0ad8;
LAB_005f0a10:
            iVar9 = (*(code *)PTR_BN_mul_006a853c)(a_01,pBVar7,a_00,ctx);
            if (iVar9 == 0) break;
LAB_005f0a2c:
            iVar9 = BN_add(a_01,a_01,unaff_s6);
          }
          if (iVar9 == 0) break;
          piVar1 = &pBVar5->top;
          iVar8 = -iVar8;
          pBVar3 = b;
          pBVar4 = pBVar5;
          pBVar5 = unaff_s6;
          unaff_s6 = a_00;
          if (*piVar1 == 0) {
            pBVar5 = b;
            if (iVar8 != -1) goto LAB_005f0eac;
            goto LAB_005f1014;
          }
        } while( true );
      }
      goto LAB_005f0730;
    }
  }
  else {
    (*(code *)PTR_BN_CTX_start_006a8528)();
    pBVar5 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    b = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    a_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    pBVar6 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    a_01 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    pBVar7 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
    if (iVar8 != 0) {
      if (ret == (BIGNUM *)0x0) {
        local_68 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
        if (local_68 == (BIGNUM *)0x0) goto LAB_005f0d70;
        (*(code *)PTR_BN_set_word_006a7730)(a_00,1);
        (*(code *)PTR_BN_set_word_006a7730)(pBVar7,0);
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(b,a);
        if (iVar8 == 0) goto LAB_005f0d70;
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(pBVar5,n);
        if (iVar8 == 0) goto LAB_005f0d70;
      }
      else {
        (*(code *)PTR_BN_set_word_006a7730)(a_00,1);
        (*(code *)PTR_BN_set_word_006a7730)(pBVar7,0);
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(b,a);
        if (iVar8 == 0) goto LAB_005f0738;
        iVar8 = (*(code *)PTR_BN_copy_006a8450)(pBVar5,n);
        if (iVar8 == 0) goto LAB_005f0738;
      }
      pBVar5->neg = 0;
      iVar8 = b->neg;
      if (iVar8 == 0) {
        iVar8 = (*(code *)PTR_BN_ucmp_006a7fb4)(b,pBVar5);
        if (-1 < iVar8) {
          iVar8 = b->neg;
          goto LAB_005f0608;
        }
      }
      else {
LAB_005f0608:
        local_3c = b->top;
        local_40 = b->d;
        local_38 = b->dmax;
        local_30 = b->flags & 0xfffffffeU | 6;
        local_34 = iVar8;
        iVar8 = (*(code *)PTR_BN_nnmod_006a8548)(b,&local_40,pBVar5,ctx);
        if (iVar8 == 0) goto LAB_005f0730;
      }
      unaff_s6 = (BIGNUM *)0xffffffff;
      if (b->top == 0) {
LAB_005f0e80:
        a_00 = pBVar7;
        b = pBVar5;
        iVar8 = BN_sub(a_00,n,a_00);
        if (iVar8 == 0) goto LAB_005f0730;
      }
      else {
        pBVar3 = a_01;
        a_01 = b;
        pBVar4 = a_00;
        do {
          a_00 = pBVar4;
          b = a_01;
          a_01 = pBVar3;
          local_54.d = pBVar5->d;
          local_54.top = pBVar5->top;
          local_54.dmax = pBVar5->dmax;
          local_54.neg = pBVar5->neg;
          local_54.flags = pBVar5->flags & 0xfffffffeU | 6;
          iVar8 = BN_div(pBVar6,a_01,&local_54,b,ctx);
          if (((iVar8 == 0) ||
              (iVar8 = (*(code *)PTR_BN_mul_006a853c)(pBVar5,pBVar6,a_00,ctx), iVar8 == 0)) ||
             (iVar8 = BN_add(pBVar5,pBVar5,pBVar7), iVar8 == 0)) goto LAB_005f0730;
          unaff_s6 = (BIGNUM *)-(int)unaff_s6;
          pBVar3 = pBVar7;
          pBVar4 = pBVar5;
          pBVar7 = a_00;
          pBVar5 = b;
        } while (a_01->top != 0);
        if (unaff_s6 == (BIGNUM *)0xffffffff) goto LAB_005f0e80;
      }
      if (((b->top == 1) && (*b->d == 1)) && (b->neg == 0)) {
        iVar8 = a_00->neg;
        goto LAB_005f0b6c;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x8b,0x6c,"bn_gcd.c",0x2b4);
      goto LAB_005f0730;
    }
  }
  local_68 = (BIGNUM *)0x0;
LAB_005f0730:
  if (ret == (BIGNUM *)0x0) {
LAB_005f0d70:
    (*(code *)PTR_BN_free_006a701c)(local_68);
    local_68 = (BIGNUM *)0x0;
  }
  else {
LAB_005f0738:
    local_68 = (BIGNUM *)0x0;
  }
LAB_005f073c:
  (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
  if (local_2c == *(int *)puVar2) {
    return local_68;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  while ((iVar8 = BN_uadd(unaff_s6,unaff_s6,a_00), iVar8 != 0 &&
         (iVar8 = BN_usub(a_01,a_01,b), iVar8 != 0))) {
LAB_005f0914:
    while( true ) {
      iVar8 = 0;
      pBVar3 = a_01;
      if (b->top == 0) goto LAB_005f1014;
      while (iVar9 = (*(code *)PTR_BN_is_bit_set_006a8538)(b,iVar8), iVar9 == 0) {
        iVar8 = iVar8 + 1;
        if ((((0 < a_00->top) && ((*a_00->d & 1) != 0)) &&
            (iVar9 = BN_uadd(a_00,a_00,n), iVar9 == 0)) ||
           (iVar9 = (*(code *)PTR_BN_rshift1_006a7958)(a_00,a_00), iVar9 == 0)) goto LAB_005f0730;
      }
      if ((iVar8 != 0) && (iVar8 = (*(code *)PTR_BN_rshift_006a85d4)(b,b,iVar8), iVar8 == 0))
      goto LAB_005f0730;
      iVar8 = 0;
      while (iVar9 = (*(code *)PTR_BN_is_bit_set_006a8538)(a_01,iVar8), iVar9 == 0) {
        iVar8 = iVar8 + 1;
        if ((((0 < unaff_s6->top) && ((*unaff_s6->d & 1) != 0)) &&
            (iVar9 = BN_uadd(unaff_s6,unaff_s6,n), iVar9 == 0)) ||
           (iVar9 = (*(code *)PTR_BN_rshift1_006a7958)(unaff_s6,unaff_s6), iVar9 == 0))
        goto LAB_005f0730;
      }
      if ((iVar8 != 0) && (iVar8 = (*(code *)PTR_BN_rshift_006a85d4)(a_01,a_01,iVar8), iVar8 == 0))
      goto LAB_005f0730;
      iVar8 = (*(code *)PTR_BN_ucmp_006a7fb4)(b,a_01);
      if (iVar8 < 0) break;
      iVar8 = BN_uadd(a_00,a_00,unaff_s6);
      if ((iVar8 == 0) || (iVar8 = BN_usub(b,b,a_01), iVar8 == 0)) goto LAB_005f0730;
    }
  }
  goto LAB_005f0730;
LAB_005f1014:
  a_01 = pBVar3;
  iVar8 = BN_sub(unaff_s6,n,unaff_s6);
  pBVar5 = a_01;
  if (iVar8 == 0) goto LAB_005f0730;
LAB_005f0eac:
  a_00 = unaff_s6;
  b = pBVar5;
  unaff_s6 = a_00;
  if (((b->top != 1) || (*b->d != 1)) || (b->neg != 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x6e,0x6c,"bn_gcd.c",0x20d);
    goto LAB_005f0730;
  }
  iVar8 = a_00->neg;
LAB_005f0b6c:
  if ((iVar8 == 0) && (iVar8 = (*(code *)PTR_BN_ucmp_006a7fb4)(a_00,n), iVar8 < 0)) {
    iVar8 = (*(code *)PTR_BN_copy_006a8450)(local_68,a_00);
  }
  else {
    iVar8 = (*(code *)PTR_BN_nnmod_006a8548)(local_68,a_00,n,ctx);
  }
  if (iVar8 == 0) goto LAB_005f0730;
  goto LAB_005f073c;
}

