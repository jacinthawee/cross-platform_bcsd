
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  BN_MONT_CTX *pBVar3;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  BN_MONT_CTX *pBVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  BN_MONT_CTX *unaff_s6;
  BN_MONT_CTX *local_f0;
  BN_MONT_CTX *local_ec;
  BIGNUM *local_e8;
  BIGNUM *local_e4;
  BN_MONT_CTX aBStack_e0 [2];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((m->top < 1) || ((*m->d & 1) == 0)) {
    if ((p->flags & 4U) != 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x7d,0x42,"bn_exp.c",0x108);
      pBVar3 = (BN_MONT_CTX *)0xffffffff;
      goto LAB_004f4bf8;
    }
    iVar9 = BN_num_bits(p);
    if (iVar9 != 0) {
      BN_CTX_start(ctx);
      unaff_s6 = (BN_MONT_CTX *)BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      aBStack_e0[0].Ni.dmax = (int)pBVar5;
      if ((unaff_s6 == (BN_MONT_CTX *)0x0) || (pBVar5 == (BIGNUM *)0x0)) {
        local_f0 = aBStack_e0;
        goto LAB_004f4d9c;
      }
      local_f0 = aBStack_e0;
      BN_RECP_CTX_init((BN_RECP_CTX *)local_f0);
      if (m->neg == 0) {
        iVar4 = BN_RECP_CTX_set((BN_RECP_CTX *)local_f0,m,ctx);
        if (iVar4 < 1) {
          pBVar3 = (BN_MONT_CTX *)0x0;
          goto LAB_004f4da0;
        }
      }
      else {
        pBVar6 = BN_copy((BIGNUM *)unaff_s6,m);
        if (pBVar6 == (BIGNUM *)0x0) goto LAB_004f4d9c;
        (unaff_s6->RR).dmax = 0;
        iVar4 = BN_RECP_CTX_set((BN_RECP_CTX *)local_f0,(BIGNUM *)unaff_s6,ctx);
        if (iVar4 < 1) goto LAB_004f4d9c;
      }
      iVar4 = BN_nnmod(pBVar5,a,m,ctx);
      if (iVar4 == 0) goto LAB_004f4d9c;
      if (pBVar5->top == 0) {
        BN_set_word(r,0);
        pBVar3 = (BN_MONT_CTX *)0x1;
        goto LAB_004f4da0;
      }
      if (iVar9 < 0x2a0) {
        if (iVar9 < 0xf0) {
          if (iVar9 < 0x50) {
            if (iVar9 < 0x18) {
              local_ec = (BN_MONT_CTX *)0x1;
              goto LAB_004f4a9c;
            }
            iVar4 = 4;
            local_ec = (BN_MONT_CTX *)0x3;
          }
          else {
            iVar4 = 8;
            local_ec = (BN_MONT_CTX *)&SUB_00000004;
          }
        }
        else {
          iVar4 = 0x10;
          local_ec = (BN_MONT_CTX *)&DAT_00000005;
        }
      }
      else {
        iVar4 = 0x20;
        local_ec = (BN_MONT_CTX *)&DAT_00000006;
      }
      iVar7 = BN_mod_mul_reciprocal((BIGNUM *)unaff_s6,pBVar5,pBVar5,(BN_RECP_CTX *)local_f0,ctx);
      if (iVar7 == 0) goto LAB_004f4d9c;
      piVar10 = &aBStack_e0[0].Ni.neg;
      a = (BIGNUM *)0x1;
      do {
        pBVar5 = BN_CTX_get(ctx);
        *piVar10 = (int)pBVar5;
        if (pBVar5 == (BIGNUM *)0x0) {
          pBVar3 = (BN_MONT_CTX *)0x0;
          goto LAB_004f4da0;
        }
        iVar7 = BN_mod_mul_reciprocal
                          (pBVar5,(BIGNUM *)piVar10[-1],(BIGNUM *)unaff_s6,(BN_RECP_CTX *)local_f0,
                           ctx);
        if (iVar7 == 0) goto LAB_004f4d9c;
        a = (BIGNUM *)((int)&a->d + 1);
        piVar10 = piVar10 + 1;
      } while ((int)a < iVar4);
LAB_004f4a9c:
      iVar4 = BN_set_word(r,1);
      if (iVar4 == 0) goto LAB_004f4d9c;
      local_e8 = (BIGNUM *)(iVar9 + -1);
      a = (BIGNUM *)0xffffffff;
      local_e4 = (BIGNUM *)0x1;
      goto LAB_004f4acc;
    }
LAB_004f4be4:
    pBVar3 = (BN_MONT_CTX *)BN_set_word(r,1);
    goto LAB_004f4bf8;
  }
  if ((a->top == 1) && (a->neg == 0)) {
    if ((p->flags & 4U) == 0) {
      pBVar3 = (BN_MONT_CTX *)BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
      goto LAB_004f4bf8;
    }
  }
  else if ((p->flags & 4U) == 0) {
    iVar9 = BN_num_bits(p);
    if (iVar9 == 0) goto LAB_004f4be4;
    BN_CTX_start(ctx);
    local_ec = (BN_MONT_CTX *)BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    pBVar6 = BN_CTX_get(ctx);
    unaff_s6 = local_ec;
    aBStack_e0[0].Ni.dmax = (int)pBVar6;
    if ((((local_ec == (BN_MONT_CTX *)0x0) || (pBVar5 == (BIGNUM *)0x0)) ||
        (pBVar6 == (BIGNUM *)0x0)) || (unaff_s6 = BN_MONT_CTX_new(), unaff_s6 == (BN_MONT_CTX *)0x0)
       ) {
      pBVar3 = (BN_MONT_CTX *)0x0;
    }
    else {
      iVar4 = BN_MONT_CTX_set(unaff_s6,m,ctx);
      if ((iVar4 == 0) ||
         (((a->neg != 0 || (iVar4 = BN_ucmp(a,m), pBVar2 = a, -1 < iVar4)) &&
          (iVar4 = BN_nnmod(pBVar6,a,m,ctx), pBVar2 = pBVar6, iVar4 == 0)))) {
LAB_004f4e7c:
        pBVar3 = (BN_MONT_CTX *)0x0;
      }
      else {
        a = pBVar2;
        if (a->top == 0) {
          BN_set_word(r,0);
          pBVar3 = (BN_MONT_CTX *)0x1;
        }
        else {
          local_e4 = &unaff_s6->RR;
          iVar4 = BN_mod_mul_montgomery(pBVar6,a,local_e4,unaff_s6,ctx);
          if (iVar4 == 0) goto LAB_004f4e7c;
          if (iVar9 < 0x2a0) {
            if (0xef < iVar9) {
              iVar4 = 0x10;
              local_e8 = (BIGNUM *)&DAT_00000005;
              goto LAB_004f50f4;
            }
            if (0x4f < iVar9) {
              iVar4 = 8;
              local_e8 = (BIGNUM *)&SUB_00000004;
              goto LAB_004f50f4;
            }
            if (0x17 < iVar9) {
              iVar4 = 4;
              local_e8 = (BIGNUM *)0x3;
              goto LAB_004f50f4;
            }
            local_e8 = (BIGNUM *)0x1;
          }
          else {
            iVar4 = 0x20;
            local_e8 = (BIGNUM *)&DAT_00000006;
LAB_004f50f4:
            iVar7 = BN_mod_mul_montgomery((BIGNUM *)local_ec,pBVar6,pBVar6,unaff_s6,ctx);
            if (iVar7 == 0) goto LAB_004f4e7c;
            piVar10 = &aBStack_e0[0].Ni.neg;
            a = (BIGNUM *)0x1;
            do {
              pBVar6 = BN_CTX_get(ctx);
              *piVar10 = (int)pBVar6;
              if (pBVar6 == (BIGNUM *)0x0) {
                pBVar3 = (BN_MONT_CTX *)0x0;
                goto LAB_004f4d60;
              }
              iVar7 = BN_mod_mul_montgomery
                                (pBVar6,(BIGNUM *)piVar10[-1],(BIGNUM *)local_ec,unaff_s6,ctx);
              if (iVar7 == 0) goto LAB_004f4e7c;
              a = (BIGNUM *)((int)&a->d + 1);
              piVar10 = piVar10 + 1;
            } while ((int)a < iVar4);
          }
          pBVar6 = BN_value_one();
          iVar4 = BN_mod_mul_montgomery(pBVar5,pBVar6,local_e4,unaff_s6,ctx);
          if (iVar4 == 0) goto LAB_004f4e7c;
          iVar9 = iVar9 + -1;
          local_e4 = (BIGNUM *)0x1;
LAB_004f5028:
          while (iVar4 = BN_is_bit_set(p,iVar9), iVar4 == 0) {
            if ((local_e4 == (BIGNUM *)0x0) &&
               (iVar4 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,unaff_s6,ctx), iVar4 == 0)) {
              pBVar3 = (BN_MONT_CTX *)0x0;
              goto LAB_004f4d60;
            }
            if (iVar9 == 0) goto LAB_004f51dc;
            iVar9 = iVar9 + -1;
          }
          if (local_e8 == (BIGNUM *)0x1) {
LAB_004f4e34:
            a = (BIGNUM *)0x0;
            uVar11 = 1;
          }
          else {
            uVar11 = 1;
            a = (BIGNUM *)0x0;
            if ((int)(BN_MONT_CTX *)(iVar9 + -1) < 0) goto LAB_004f4e34;
            pBVar6 = (BIGNUM *)0x1;
            pBVar3 = (BN_MONT_CTX *)(iVar9 + -1);
            do {
              local_ec = pBVar3;
              iVar4 = BN_is_bit_set(p,(int)local_ec);
              if (iVar4 != 0) {
                uVar11 = uVar11 << ((int)pBVar6 - (int)a & 0x1fU) | 1;
                a = pBVar6;
              }
              pBVar6 = (BIGNUM *)((int)&pBVar6->d + 1);
              pBVar3 = (BN_MONT_CTX *)((int)&local_ec[-1].flags + 3);
            } while ((pBVar6 != local_e8) && (pBVar3 != (BN_MONT_CTX *)0xffffffff));
          }
          iVar4 = 0;
          if (local_e4 == (BIGNUM *)0x0) {
            do {
              iVar7 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,unaff_s6,ctx);
              if (iVar7 == 0) goto LAB_004f4e7c;
              iVar4 = iVar4 + 1;
            } while (iVar4 <= (int)a);
          }
          iVar4 = BN_mod_mul_montgomery
                            (pBVar5,pBVar5,(BIGNUM *)aBStack_e0[0].n0[((int)uVar11 >> 1) + -3],
                             unaff_s6,ctx);
          if (iVar4 == 0) goto LAB_004f4e7c;
          a = (BIGNUM *)((int)&a->d + 1);
          iVar9 = iVar9 - (int)a;
          if (-1 < iVar9) {
            local_e4 = (BIGNUM *)0x0;
            goto LAB_004f5028;
          }
LAB_004f51dc:
          iVar9 = BN_from_montgomery(r,pBVar5,unaff_s6,ctx);
          pBVar3 = (BN_MONT_CTX *)(uint)(iVar9 != 0);
        }
      }
LAB_004f4d60:
      BN_MONT_CTX_free(unaff_s6);
    }
    BN_CTX_end(ctx);
    local_f0 = pBVar3;
    goto LAB_004f4bf8;
  }
  pBVar3 = (BN_MONT_CTX *)BN_mod_exp_mont_consttime(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
LAB_004f4bf8:
  if (local_2c == *(int *)puVar1) {
    return (int)pBVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  do {
    pBVar3 = (BN_MONT_CTX *)0x0;
LAB_004f4b50:
    if (local_e4 == (BIGNUM *)0x0) {
      iVar9 = 0;
      do {
        iVar4 = BN_mod_mul_reciprocal(r,r,r,(BN_RECP_CTX *)local_f0,ctx);
        if (iVar4 == 0) goto LAB_004f4d9c;
        iVar9 = iVar9 + 1;
      } while (iVar9 <= (int)pBVar3);
    }
    iVar9 = BN_mod_mul_reciprocal
                      (r,r,(BIGNUM *)aBStack_e0[0].n0[((int)unaff_s6 >> 1) + -3],
                       (BN_RECP_CTX *)local_f0,ctx);
    if (iVar9 == 0) goto LAB_004f4d9c;
    local_e8 = (BIGNUM *)((int)local_e8 - (int)((int)&pBVar3->ri + 1));
    if ((int)local_e8 < 0) {
LAB_004f4f64:
      pBVar3 = (BN_MONT_CTX *)0x1;
      goto LAB_004f4da0;
    }
    local_e4 = (BIGNUM *)0x0;
LAB_004f4acc:
    while (iVar9 = BN_is_bit_set(p,(int)local_e8), iVar9 == 0) {
      if ((local_e4 == (BIGNUM *)0x0) &&
         (iVar9 = BN_mod_mul_reciprocal(r,r,r,(BN_RECP_CTX *)local_f0,ctx), iVar9 == 0)) {
        pBVar3 = (BN_MONT_CTX *)0x0;
        goto LAB_004f4da0;
      }
      if (local_e8 == (BIGNUM *)0x0) goto LAB_004f4f64;
      local_e8 = (BIGNUM *)((int)&local_e8[-1].flags + 3);
    }
    unaff_s6 = (BN_MONT_CTX *)0x1;
  } while (local_ec == (BN_MONT_CTX *)0x1);
  pBVar5 = (BIGNUM *)((int)&local_e8[-1].flags + 3);
  pBVar3 = (BN_MONT_CTX *)0x0;
  if (-1 < (int)pBVar5) {
    pBVar8 = (BN_MONT_CTX *)0x1;
    do {
      iVar9 = BN_is_bit_set(p,(int)pBVar5);
      if (iVar9 != 0) {
        unaff_s6 = (BN_MONT_CTX *)((int)unaff_s6 << ((int)pBVar8 - (int)pBVar3 & 0x1fU) | 1);
        pBVar3 = pBVar8;
      }
      pBVar8 = (BN_MONT_CTX *)((int)&pBVar8->ri + 1);
      pBVar5 = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
    } while ((pBVar8 != local_ec) && (pBVar5 != a));
  }
  goto LAB_004f4b50;
LAB_004f4d9c:
  pBVar3 = (BN_MONT_CTX *)0x0;
LAB_004f4da0:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free((BN_RECP_CTX *)local_f0);
  local_ec = pBVar3;
  goto LAB_004f4bf8;
}

