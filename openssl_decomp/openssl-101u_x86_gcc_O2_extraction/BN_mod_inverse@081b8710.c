
/* WARNING: Type propagation algorithm not settling */

BIGNUM * BN_mod_inverse(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  ulong uVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  int iVar8;
  int iVar9;
  BIGNUM *pBVar10;
  int in_GS_OFFSET;
  BIGNUM *local_70;
  BIGNUM *local_6c;
  int local_64;
  BIGNUM *local_5c;
  int local_50;
  BIGNUM local_48;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((*(byte *)&a->flags & 4) == 0) && ((*(byte *)&n->flags & 4) == 0)) {
    BN_CTX_start(ctx);
    pBVar3 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    local_6c = BN_CTX_get(ctx);
    pBVar2 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    local_70 = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    if (pBVar5 == (BIGNUM *)0x0) goto LAB_081b8e3b;
    if (ret != (BIGNUM *)0x0) {
      BN_set_word(local_6c,1);
      BN_set_word(local_70,0);
      pBVar7 = BN_copy(pBVar4,a);
      if ((pBVar7 == (BIGNUM *)0x0) || (pBVar7 = BN_copy(pBVar3,n), pBVar7 == (BIGNUM *)0x0))
      goto LAB_081b8951;
      local_5c = ret;
LAB_081b8a48:
      pBVar3->neg = 0;
      if (((pBVar4->neg == 0) && (iVar8 = BN_ucmp(pBVar4,pBVar3), iVar8 < 0)) ||
         (iVar8 = BN_nnmod(pBVar4,pBVar4,pBVar3,ctx), iVar8 != 0)) {
        if (((n->top < 1) || ((*(byte *)n->d & 1) == 0)) || (iVar8 = BN_num_bits(n), 0x800 < iVar8))
        {
          if (pBVar4->top != 0) {
            local_50 = -1;
            pBVar7 = pBVar3;
            pBVar3 = pBVar4;
            do {
              pBVar10 = pBVar6;
              pBVar4 = pBVar7;
              pBVar6 = local_70;
              iVar8 = BN_num_bits(pBVar4);
              iVar9 = BN_num_bits(pBVar3);
              if (iVar8 == iVar9) {
LAB_081b8c7c:
                iVar8 = BN_set_word(pBVar2,1);
                pBVar7 = pBVar4;
joined_r0x081b8c8c:
                if ((iVar8 != 0) && (iVar8 = BN_sub(pBVar10,pBVar7,pBVar3), iVar8 != 0)) {
                  if (pBVar2->top == 1) goto LAB_081b8cb2;
LAB_081b8c02:
                  iVar8 = BN_mul(pBVar4,pBVar2,local_6c,ctx);
                  goto joined_r0x081b8c16;
                }
                goto LAB_081b8945;
              }
              iVar8 = BN_num_bits(pBVar4);
              iVar9 = BN_num_bits(pBVar3);
              if (iVar8 == iVar9 + 1) {
                iVar8 = BN_lshift1(pBVar5,pBVar3);
                if (iVar8 != 0) {
                  iVar8 = BN_ucmp(pBVar4,pBVar5);
                  if (iVar8 < 0) goto LAB_081b8c7c;
                  iVar8 = BN_sub(pBVar10,pBVar4,pBVar5);
                  if ((iVar8 != 0) && (iVar8 = BN_add(pBVar2,pBVar5,pBVar3), iVar8 != 0)) {
                    iVar8 = BN_ucmp(pBVar4,pBVar2);
                    if (-1 < iVar8) {
                      iVar8 = BN_set_word(pBVar2,3);
                      pBVar7 = pBVar10;
                      goto joined_r0x081b8c8c;
                    }
                    iVar8 = BN_set_word(pBVar2,2);
                    if (iVar8 != 0) goto LAB_081b8bf8;
                  }
                }
                goto LAB_081b8945;
              }
              iVar8 = BN_div(pBVar2,pBVar10,pBVar4,pBVar3,ctx);
              if (iVar8 == 0) goto LAB_081b8945;
LAB_081b8bf8:
              if (pBVar2->top != 1) goto LAB_081b8c02;
LAB_081b8cb2:
              uVar1 = *pBVar2->d;
              if (uVar1 == 1) {
                pBVar7 = local_6c;
                if (pBVar2->neg != 0) goto LAB_081b8cd1;
              }
              else {
                if (uVar1 == 2) {
                  if (pBVar2->neg != 0) goto LAB_081b8cd1;
                  iVar8 = BN_lshift1(pBVar4,local_6c);
                }
                else if ((uVar1 == 4) && (pBVar2->neg == 0)) {
                  iVar8 = BN_lshift(pBVar4,local_6c,2);
                }
                else {
LAB_081b8cd1:
                  pBVar7 = BN_copy(pBVar4,local_6c);
                  if (pBVar7 == (BIGNUM *)0x0) goto LAB_081b8945;
                  iVar8 = BN_mul_word(pBVar4,*pBVar2->d);
                }
joined_r0x081b8c16:
                pBVar7 = pBVar4;
                if (iVar8 == 0) goto LAB_081b8945;
              }
              iVar8 = BN_add(pBVar4,pBVar7,local_70);
              if (iVar8 == 0) goto LAB_081b8945;
              local_50 = -local_50;
              if (pBVar10->top == 0) goto LAB_081b8f90;
              local_70 = local_6c;
              pBVar7 = pBVar3;
              pBVar3 = pBVar10;
              local_6c = pBVar4;
            } while( true );
          }
          goto LAB_081b910e;
        }
        while( true ) {
          if (pBVar4->top == 0) goto LAB_081b910e;
          iVar8 = 0;
          while (iVar9 = BN_is_bit_set(pBVar4,iVar8), iVar9 == 0) {
            iVar8 = iVar8 + 1;
            if ((((0 < local_6c->top) && ((*(byte *)local_6c->d & 1) != 0)) &&
                (iVar9 = BN_uadd(local_6c,local_6c,n), iVar9 == 0)) ||
               (iVar9 = BN_rshift1(local_6c,local_6c), iVar9 == 0)) goto LAB_081b8945;
          }
          if ((iVar8 != 0) && (iVar8 = BN_rshift(pBVar4,pBVar4,iVar8), iVar8 == 0)) break;
          iVar8 = 0;
          while (iVar9 = BN_is_bit_set(pBVar3,iVar8), iVar9 == 0) {
            iVar8 = iVar8 + 1;
            if ((((0 < local_70->top) && ((*(byte *)local_70->d & 1) != 0)) &&
                (iVar9 = BN_uadd(local_70,local_70,n), iVar9 == 0)) ||
               (iVar9 = BN_rshift1(local_70,local_70), iVar9 == 0)) goto LAB_081b8945;
          }
          if ((iVar8 != 0) && (iVar8 = BN_rshift(pBVar3,pBVar3,iVar8), iVar8 == 0)) break;
          iVar8 = BN_ucmp(pBVar4,pBVar3);
          if (iVar8 < 0) {
            iVar8 = BN_uadd(local_70,local_70,local_6c);
            if (iVar8 == 0) break;
            iVar8 = BN_usub(pBVar3,pBVar3,pBVar4);
          }
          else {
            iVar8 = BN_uadd(local_6c,local_6c,local_70);
            if (iVar8 == 0) break;
            iVar8 = BN_usub(pBVar4,pBVar4,pBVar3);
          }
          if (iVar8 == 0) break;
        }
      }
      goto LAB_081b8945;
    }
    local_5c = BN_new();
    if (local_5c != (BIGNUM *)0x0) {
      BN_set_word(local_6c,1);
      BN_set_word(local_70,0);
      pBVar7 = BN_copy(pBVar4,a);
      if ((pBVar7 != (BIGNUM *)0x0) && (pBVar7 = BN_copy(pBVar3,n), pBVar7 != (BIGNUM *)0x0))
      goto LAB_081b8a48;
    }
    goto LAB_081b8b80;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  pBVar3 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  pBVar6 = BN_CTX_get(ctx);
  local_70 = BN_CTX_get(ctx);
  pBVar7 = BN_CTX_get(ctx);
  if (pBVar7 == (BIGNUM *)0x0) {
LAB_081b8e3b:
    local_5c = (BIGNUM *)0x0;
    goto LAB_081b8945;
  }
  if (ret == (BIGNUM *)0x0) {
    local_5c = BN_new();
    if (local_5c != (BIGNUM *)0x0) {
      BN_set_word(pBVar4,1);
      BN_set_word(local_70,0);
      pBVar7 = BN_copy(pBVar3,a);
      if ((pBVar7 != (BIGNUM *)0x0) && (pBVar7 = BN_copy(pBVar2,n), pBVar7 != (BIGNUM *)0x0))
      goto LAB_081b8818;
    }
    goto LAB_081b8b80;
  }
  BN_set_word(pBVar4,1);
  BN_set_word(local_70,0);
  pBVar7 = BN_copy(pBVar3,a);
  if ((pBVar7 != (BIGNUM *)0x0) && (pBVar7 = BN_copy(pBVar2,n), pBVar7 != (BIGNUM *)0x0)) {
    local_5c = ret;
LAB_081b8818:
    pBVar2->neg = 0;
    iVar8 = pBVar3->neg;
    if (iVar8 == 0) {
      iVar8 = BN_ucmp(pBVar3,pBVar2);
      if (-1 < iVar8) {
        iVar8 = pBVar3->neg;
        goto LAB_081b883a;
      }
    }
    else {
LAB_081b883a:
      local_34.d = pBVar3->d;
      local_34.top = pBVar3->top;
      local_34.dmax = pBVar3->dmax;
      local_34.flags = pBVar3->flags & 0xfffffffeU | 6;
      local_34.neg = iVar8;
      iVar8 = BN_nnmod(pBVar3,&local_34,pBVar2,ctx);
      if (iVar8 == 0) goto LAB_081b8945;
    }
    local_64 = -1;
    pBVar7 = pBVar2;
    pBVar10 = local_70;
    if (pBVar3->top == 0) {
LAB_081b8f0a:
      iVar8 = BN_sub(local_70,n,local_70);
      if (iVar8 == 0) goto LAB_081b8945;
    }
    else {
      do {
        local_70 = pBVar4;
        pBVar2 = pBVar3;
        pBVar4 = pBVar7;
        pBVar3 = pBVar6;
        local_48.d = pBVar4->d;
        local_48.top = pBVar4->top;
        local_48.dmax = pBVar4->dmax;
        local_48.neg = pBVar4->neg;
        local_48.flags = pBVar4->flags & 0xfffffffeU | 6;
        iVar8 = BN_div(pBVar5,pBVar3,&local_48,pBVar2,ctx);
        if (((iVar8 == 0) || (iVar8 = BN_mul(pBVar4,pBVar5,local_70,ctx), iVar8 == 0)) ||
           (iVar8 = BN_add(pBVar4,pBVar4,pBVar10), iVar8 == 0)) goto LAB_081b8945;
        local_64 = -local_64;
        pBVar6 = pBVar10;
        pBVar7 = pBVar2;
        pBVar10 = local_70;
      } while (pBVar3->top != 0);
      if (local_64 == -1) goto LAB_081b8f0a;
    }
    if (((pBVar2->top == 1) && (*pBVar2->d == 1)) && (pBVar2->neg == 0)) {
      local_6c = local_70;
      if ((local_70->neg == 0) && (iVar8 = BN_ucmp(local_70,n), iVar8 < 0)) goto LAB_081b8d65;
      goto LAB_081b8d89;
    }
    ERR_put_error(3,0x8b,0x6c,"bn_gcd.c",0x2b4);
    goto LAB_081b8945;
  }
LAB_081b8951:
  local_5c = (BIGNUM *)0x0;
LAB_081b8959:
  BN_CTX_end(ctx);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_5c;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_081b8f90:
  if (local_50 == -1) {
    local_70 = local_6c;
LAB_081b910e:
    local_6c = local_70;
    iVar8 = BN_sub(local_70,n,local_70);
    if (iVar8 == 0) goto LAB_081b8945;
  }
  if (((pBVar3->top == 1) && (*pBVar3->d == 1)) && (pBVar3->neg == 0)) {
    if ((local_6c->neg == 0) && (iVar8 = BN_ucmp(local_6c,n), iVar8 < 0)) {
LAB_081b8d65:
      pBVar6 = BN_copy(local_5c,local_6c);
    }
    else {
LAB_081b8d89:
      pBVar6 = (BIGNUM *)BN_nnmod(local_5c,local_6c,n,ctx);
    }
    if (pBVar6 != (BIGNUM *)0x0) goto LAB_081b8959;
  }
  else {
    ERR_put_error(3,0x6e,0x6c,"bn_gcd.c",0x20d);
  }
LAB_081b8945:
  if (ret == (BIGNUM *)0x0) {
LAB_081b8b80:
    BN_free(local_5c);
  }
  goto LAB_081b8951;
}

