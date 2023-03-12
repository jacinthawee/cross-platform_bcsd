
BIGNUM * BN_mod_inverse(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  int *piVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *a_00;
  BIGNUM *pBVar7;
  int iVar8;
  BIGNUM *pBVar9;
  int iVar10;
  ulong uVar11;
  BIGNUM *b;
  int iVar12;
  BIGNUM *local_58;
  BIGNUM local_50;
  BIGNUM local_3c;
  
  if ((a->flags << 0x1d < 0) || (n->flags << 0x1d < 0)) {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    local_58 = BN_CTX_get(ctx);
    if (local_58 == (BIGNUM *)0x0) goto LAB_00103764;
    local_58 = ret;
    if ((ret == (BIGNUM *)0x0) && (local_58 = BN_new(), local_58 == (BIGNUM *)0x0))
    goto LAB_0010389e;
    BN_set_word(pBVar4,1);
    BN_set_word(a_00,0);
    pBVar7 = BN_copy(pBVar3,a);
    if ((pBVar7 == (BIGNUM *)0x0) || (pBVar7 = BN_copy(pBVar2,n), pBVar7 == (BIGNUM *)0x0))
    goto LAB_00103764;
    pBVar2->neg = 0;
    iVar12 = pBVar3->neg;
    if (iVar12 == 0) {
      iVar12 = BN_ucmp(pBVar3,pBVar2);
      if (-1 < iVar12) {
        iVar12 = pBVar3->neg;
        goto LAB_001036a4;
      }
    }
    else {
LAB_001036a4:
      local_3c.d = pBVar3->d;
      local_3c.dmax = pBVar3->dmax;
      local_3c.top = pBVar3->top;
      local_3c.flags = pBVar3->flags & 0xfffffffeU | local_3c.flags & 1U | 6;
      local_3c.neg = iVar12;
      iVar12 = BN_nnmod(pBVar3,&local_3c,pBVar2,ctx);
      if (iVar12 == 0) goto LAB_00103764;
    }
    if (pBVar3->top == 0) {
LAB_00103ad8:
      iVar12 = BN_sub(a_00,n,a_00);
      if (iVar12 != 0) goto LAB_001039a4;
    }
    else {
      iVar12 = -1;
      pBVar7 = pBVar2;
      pBVar9 = a_00;
      do {
        a_00 = pBVar4;
        pBVar2 = pBVar3;
        pBVar3 = pBVar6;
        pBVar4 = pBVar7;
        local_50.d = pBVar4->d;
        iVar12 = -iVar12;
        local_50.top = pBVar4->top;
        local_50.neg = pBVar4->neg;
        local_50.flags = local_50.flags & 1U | pBVar4->flags & 0xfffffffeU | 6;
        local_50.dmax = pBVar4->dmax;
        iVar8 = BN_div(pBVar5,pBVar3,&local_50,pBVar2,ctx);
        if (((iVar8 == 0) || (iVar8 = BN_mul(pBVar4,pBVar5,a_00,ctx), iVar8 == 0)) ||
           (iVar8 = BN_add(pBVar4,pBVar4,pBVar9), iVar8 == 0)) goto LAB_00103764;
        pBVar7 = pBVar2;
        pBVar6 = pBVar9;
        pBVar9 = a_00;
      } while (pBVar3->top != 0);
      if (iVar12 == -1) goto LAB_00103ad8;
LAB_001039a4:
      if (((pBVar2->top == 1) && (*pBVar2->d == 1)) && (pBVar2->neg == 0)) {
        if ((a_00->neg == 0) && (iVar12 = BN_ucmp(a_00,n), iVar12 < 0)) {
          pBVar6 = BN_copy(local_58,a_00);
        }
        else {
LAB_001039dc:
          pBVar6 = (BIGNUM *)BN_nnmod(local_58,a_00,n,ctx);
        }
        goto joined_r0x00103c1c;
      }
      ERR_put_error(3,0x8b,0x6c,"bn_gcd.c",0x286);
    }
LAB_00103764:
    if (ret != (BIGNUM *)0x0) {
      local_58 = (BIGNUM *)0x0;
      goto LAB_00103770;
    }
  }
  else {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    pBVar7 = BN_CTX_get(ctx);
    local_58 = pBVar7;
    if (pBVar7 == (BIGNUM *)0x0) goto LAB_00103764;
    local_58 = ret;
    if ((ret != (BIGNUM *)0x0) || (local_58 = BN_new(), local_58 != (BIGNUM *)0x0)) {
      BN_set_word(pBVar3,1);
      BN_set_word(a_00,0);
      pBVar9 = BN_copy(pBVar6,a);
      if (((pBVar9 == (BIGNUM *)0x0) || (pBVar9 = BN_copy(pBVar2,n), pBVar9 == (BIGNUM *)0x0)) ||
         (((pBVar2->neg = 0, pBVar6->neg != 0 || (iVar12 = BN_ucmp(pBVar6,pBVar2), -1 < iVar12)) &&
          (iVar12 = BN_nnmod(pBVar6,pBVar6,pBVar2,ctx), iVar12 == 0)))) goto LAB_00103764;
      if (((0 < n->top) && ((int)(*n->d << 0x1f) < 0)) && (iVar12 = BN_num_bits(n), iVar12 < 0x801))
      {
        while( true ) {
          if (pBVar6->top == 0) goto LAB_00103bc0;
          iVar12 = 0;
          while (iVar8 = BN_is_bit_set(pBVar6,iVar12), iVar8 == 0) {
            iVar12 = iVar12 + 1;
            if ((((0 < pBVar3->top) && ((int)(*pBVar3->d << 0x1f) < 0)) &&
                (iVar8 = BN_uadd(pBVar3,pBVar3,n), iVar8 == 0)) ||
               (iVar8 = BN_rshift1(pBVar3,pBVar3), iVar8 == 0)) goto LAB_00103764;
          }
          if ((iVar12 != 0) && (iVar12 = BN_rshift(pBVar6,pBVar6,iVar12), iVar12 == 0)) break;
          iVar12 = 0;
          while (iVar8 = BN_is_bit_set(pBVar2,iVar12), iVar8 == 0) {
            iVar12 = iVar12 + 1;
            if ((((0 < a_00->top) && ((int)(*a_00->d << 0x1f) < 0)) &&
                (iVar8 = BN_uadd(a_00,a_00,n), iVar8 == 0)) ||
               (iVar8 = BN_rshift1(a_00,a_00), iVar8 == 0)) goto LAB_00103764;
          }
          if ((iVar12 != 0) && (iVar12 = BN_rshift(pBVar2,pBVar2,iVar12), iVar12 == 0)) break;
          iVar12 = BN_ucmp(pBVar6,pBVar2);
          if (iVar12 < 0) {
            iVar12 = BN_uadd(a_00,a_00,pBVar3);
            if (iVar12 == 0) break;
            iVar12 = BN_usub(pBVar2,pBVar2,pBVar6);
          }
          else {
            iVar12 = BN_uadd(pBVar3,pBVar3,a_00);
            if (iVar12 == 0) break;
            iVar12 = BN_usub(pBVar6,pBVar6,pBVar2);
          }
          if (iVar12 == 0) break;
        }
        goto LAB_00103764;
      }
      if (pBVar6->top == 0) {
LAB_00103bc0:
        iVar12 = BN_sub(a_00,n,a_00);
        if (iVar12 == 0) goto LAB_00103764;
      }
      else {
        iVar12 = -1;
        pBVar9 = pBVar2;
        b = a_00;
        do {
          a_00 = pBVar3;
          pBVar2 = pBVar6;
          pBVar3 = pBVar9;
          iVar8 = BN_num_bits(pBVar3);
          iVar10 = BN_num_bits(pBVar2);
          if (iVar8 == iVar10) {
LAB_00103940:
            iVar8 = BN_set_word(pBVar5,1);
            if ((iVar8 == 0) || (iVar8 = BN_sub(pBVar4,pBVar3,pBVar2), iVar8 == 0))
            goto LAB_00103764;
            iVar8 = pBVar5->top;
          }
          else {
            iVar8 = BN_num_bits(pBVar3);
            iVar10 = BN_num_bits(pBVar2);
            if (iVar8 == iVar10 + 1) {
              iVar8 = BN_lshift1(pBVar7,pBVar2);
              if (iVar8 == 0) goto LAB_00103764;
              iVar8 = BN_ucmp(pBVar3,pBVar7);
              if (iVar8 < 0) goto LAB_00103940;
              iVar8 = BN_sub(pBVar4,pBVar3,pBVar7);
              if ((iVar8 == 0) || (iVar8 = BN_add(pBVar5,pBVar7,pBVar2), iVar8 == 0))
              goto LAB_00103764;
              iVar8 = BN_ucmp(pBVar3,pBVar5);
              if (iVar8 < 0) {
                iVar8 = BN_set_word(pBVar5,2);
              }
              else {
                iVar8 = BN_set_word(pBVar5,3);
                if (iVar8 == 0) goto LAB_00103764;
                iVar8 = BN_sub(pBVar4,pBVar4,pBVar2);
              }
            }
            else {
              iVar8 = BN_div(pBVar5,pBVar4,pBVar3,pBVar2,ctx);
            }
            if (iVar8 == 0) goto LAB_00103764;
            iVar8 = pBVar5->top;
          }
          if (iVar8 == 1) {
            uVar11 = *pBVar5->d;
            if (uVar11 != 1) {
              if (uVar11 == 2) {
                if (pBVar5->neg != 0) goto LAB_0010397c;
                iVar8 = BN_lshift1(pBVar3,a_00);
              }
              else if ((uVar11 == 4) && (pBVar5->neg == 0)) {
                iVar8 = BN_lshift(pBVar3,a_00,2);
              }
              else {
LAB_0010397c:
                pBVar6 = BN_copy(pBVar3,a_00);
                if (pBVar6 == (BIGNUM *)0x0) goto LAB_00103764;
                iVar8 = BN_mul_word(pBVar3,*pBVar5->d);
              }
              if (iVar8 != 0) goto LAB_00103904;
              goto LAB_00103764;
            }
            if (pBVar5->neg != 0) goto LAB_0010397c;
            iVar8 = BN_add(pBVar3,a_00,b);
          }
          else {
            iVar8 = BN_mul(pBVar3,pBVar5,a_00,ctx);
            if (iVar8 == 0) goto LAB_00103764;
LAB_00103904:
            iVar8 = BN_add(pBVar3,pBVar3,b);
          }
          if (iVar8 == 0) goto LAB_00103764;
          piVar1 = &pBVar4->top;
          iVar12 = -iVar12;
          pBVar9 = pBVar2;
          pBVar6 = pBVar4;
          pBVar4 = b;
          b = a_00;
        } while (*piVar1 != 0);
        if (iVar12 == -1) goto LAB_00103bc0;
      }
      if (((pBVar2->top != 1) || (*pBVar2->d != 1)) || (pBVar2->neg != 0)) {
        ERR_put_error(3,0x6e,0x6c,"bn_gcd.c",0x1ec);
        goto LAB_00103764;
      }
      if ((a_00->neg != 0) || (iVar12 = BN_ucmp(a_00,n), -1 < iVar12)) goto LAB_001039dc;
      pBVar6 = BN_copy(local_58,a_00);
joined_r0x00103c1c:
      if (pBVar6 != (BIGNUM *)0x0) goto LAB_00103770;
      goto LAB_00103764;
    }
  }
LAB_0010389e:
  pBVar6 = local_58;
  local_58 = (BIGNUM *)0x0;
  BN_free(pBVar6);
LAB_00103770:
  BN_CTX_end(ctx);
  return local_58;
}

