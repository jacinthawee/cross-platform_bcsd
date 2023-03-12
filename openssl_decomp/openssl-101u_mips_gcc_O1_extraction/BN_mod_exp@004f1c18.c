
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  BN_MONT_CTX *pBVar3;
  BN_RECP_CTX *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  undefined *n;
  BN_MONT_CTX *pBVar8;
  uint uVar9;
  BN_MONT_CTX *unaff_s3;
  BN_MONT_CTX *unaff_s4;
  BN_MONT_CTX *pBVar10;
  BIGNUM **ppBVar11;
  BN_RECP_CTX *local_f0;
  BN_MONT_CTX *local_ec;
  BN_RECP_CTX BStack_e0;
  undefined local_ac [128];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((0 < m->top) && ((*m->d & 1) != 0)) {
    if ((a->top == 1) && (a->neg == 0)) {
      if ((p->flags & 4U) == 0) {
        pBVar4 = (BN_RECP_CTX *)BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
        goto LAB_004f1d30;
      }
    }
    else if ((p->flags & 4U) == 0) {
      unaff_s3 = (BN_MONT_CTX *)BN_num_bits(p);
      if (unaff_s3 != (BN_MONT_CTX *)0x0) {
        BN_CTX_start(ctx);
        pBVar10 = (BN_MONT_CTX *)BN_CTX_get(ctx);
        local_f0 = (BN_RECP_CTX *)BN_CTX_get(ctx);
        pBVar8 = (BN_MONT_CTX *)BN_CTX_get(ctx);
        unaff_s4 = pBVar10;
        local_ac._0_4_ = pBVar8;
        if ((((pBVar10 == (BN_MONT_CTX *)0x0) || (local_f0 == (BN_RECP_CTX *)0x0)) ||
            (pBVar8 == (BN_MONT_CTX *)0x0)) ||
           (unaff_s4 = BN_MONT_CTX_new(), unaff_s4 == (BN_MONT_CTX *)0x0)) {
          pBVar4 = (BN_RECP_CTX *)0x0;
          goto LAB_004f1eb0;
        }
        iVar7 = BN_MONT_CTX_set(unaff_s4,m,ctx);
        if (iVar7 == 0) goto LAB_004f2228;
        if (((a->neg != 0) || (iVar7 = BN_ucmp(a,m), pBVar3 = (BN_MONT_CTX *)a, -1 < iVar7)) &&
           (iVar7 = BN_nnmod((BIGNUM *)pBVar8,a,m,ctx), pBVar3 = pBVar8, iVar7 == 0))
        goto LAB_004f2228;
        a = (BIGNUM *)pBVar3;
        if ((((BN_MONT_CTX *)a)->RR).d != (ulong *)0x0) {
          iVar7 = BN_mod_mul_montgomery((BIGNUM *)pBVar8,a,&unaff_s4->RR,unaff_s4,ctx);
          if (iVar7 == 0) goto LAB_004f2228;
          m = (BIGNUM *)&DAT_00000006;
          if ((((int)unaff_s3 < 0x2a0) && (m = (BIGNUM *)&DAT_00000005, (int)unaff_s3 < 0xf0)) &&
             ((m = (BIGNUM *)&SUB_00000004, (int)unaff_s3 < 0x50 &&
              (m = (BIGNUM *)0x3, (int)unaff_s3 < 0x18)))) {
            m = (BIGNUM *)0x1;
          }
          else {
            iVar7 = BN_mod_mul_montgomery
                              ((BIGNUM *)pBVar10,(BIGNUM *)pBVar8,(BIGNUM *)pBVar8,unaff_s4,ctx);
            if (iVar7 == 0) goto LAB_004f2228;
            ppBVar11 = (BIGNUM **)(local_ac + 4);
            a = (BIGNUM *)
                (local_ac +
                (4 << ((uint)((int)&((BN_MONT_CTX *)((int)m + -0x4c))->flags + 3) & 0x1f)));
            do {
              pBVar6 = BN_CTX_get(ctx);
              *ppBVar11 = pBVar6;
              if (pBVar6 == (BIGNUM *)0x0) {
                pBVar4 = (BN_RECP_CTX *)0x0;
                goto LAB_004f1e98;
              }
              iVar7 = BN_mod_mul_montgomery(pBVar6,ppBVar11[-1],(BIGNUM *)pBVar10,unaff_s4,ctx);
              if (iVar7 == 0) goto LAB_004f2228;
              ppBVar11 = ppBVar11 + 1;
            } while (a != (BIGNUM *)ppBVar11);
          }
          pBVar6 = BN_value_one();
          iVar7 = BN_mod_mul_montgomery((BIGNUM *)local_f0,pBVar6,&unaff_s4->RR,unaff_s4,ctx);
          if (iVar7 == 0) goto LAB_004f2228;
          unaff_s3 = (BN_MONT_CTX *)((int)&unaff_s3[-1].flags + 3);
          a = (BIGNUM *)0x1;
          goto LAB_004f23b8;
        }
        BN_set_word(r,0);
        pBVar4 = (BN_RECP_CTX *)0x1;
        goto LAB_004f1e98;
      }
      goto LAB_004f1d00;
    }
    pBVar4 = (BN_RECP_CTX *)BN_mod_exp_mont_consttime(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
    goto LAB_004f1d30;
  }
  if ((p->flags & 4U) != 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7d,0x42,"bn_exp.c",0x10e);
    pBVar4 = (BN_RECP_CTX *)0xffffffff;
    goto LAB_004f1d30;
  }
  unaff_s3 = (BN_MONT_CTX *)BN_num_bits(p);
  if (unaff_s3 == (BN_MONT_CTX *)0x0) {
LAB_004f1d00:
    if (((m->top == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      pBVar4 = (BN_RECP_CTX *)0x1;
    }
    else {
      pBVar4 = (BN_RECP_CTX *)BN_set_word(r,1);
    }
    goto LAB_004f1d30;
  }
  BN_CTX_start(ctx);
  pBVar6 = BN_CTX_get(ctx);
  unaff_s4 = (BN_MONT_CTX *)BN_CTX_get(ctx);
  local_ac._0_4_ = unaff_s4;
  if ((pBVar6 == (BIGNUM *)0x0) || (unaff_s4 == (BN_MONT_CTX *)0x0)) goto LAB_004f2114;
  BN_RECP_CTX_init(&BStack_e0);
  if (m->neg == 0) {
    iVar7 = BN_RECP_CTX_set(&BStack_e0,m,ctx);
    if (0 < iVar7) {
LAB_004f1f4c:
      iVar7 = BN_nnmod((BIGNUM *)unaff_s4,a,m,ctx);
      if (iVar7 != 0) {
        if ((unaff_s4->RR).d == (ulong *)0x0) {
          BN_set_word(r,0);
          pBVar4 = (BN_RECP_CTX *)0x1;
          goto LAB_004f2118;
        }
        if ((int)unaff_s3 < 0x2a0) {
          if (0xef < (int)unaff_s3) {
            a = (BIGNUM *)&DAT_00000005;
            local_ec = (BN_MONT_CTX *)0x10;
            goto LAB_004f2238;
          }
          if (0x4f < (int)unaff_s3) {
            a = (BIGNUM *)&SUB_00000004;
            local_ec = (BN_MONT_CTX *)0x8;
            goto LAB_004f2238;
          }
          if (0x17 < (int)unaff_s3) {
            a = (BIGNUM *)0x3;
            local_ec = (BN_MONT_CTX *)0x4;
            goto LAB_004f2238;
          }
          a = (BIGNUM *)0x1;
        }
        else {
          a = (BIGNUM *)&DAT_00000006;
          local_ec = (BN_MONT_CTX *)0x20;
LAB_004f2238:
          iVar7 = BN_mod_mul_reciprocal(pBVar6,(BIGNUM *)unaff_s4,(BIGNUM *)unaff_s4,&BStack_e0,ctx)
          ;
          if (iVar7 == 0) goto LAB_004f2114;
          unaff_s4 = (BN_MONT_CTX *)(local_ac + 4);
          m = (BIGNUM *)0x1;
          do {
            pBVar5 = BN_CTX_get(ctx);
            unaff_s4->ri = (int)pBVar5;
            if (pBVar5 == (BIGNUM *)0x0) {
              pBVar4 = (BN_RECP_CTX *)0x0;
              goto LAB_004f2118;
            }
            iVar7 = BN_mod_mul_reciprocal(pBVar5,(BIGNUM *)unaff_s4[-1].flags,pBVar6,&BStack_e0,ctx)
            ;
            if (iVar7 == 0) goto LAB_004f2114;
            m = (BIGNUM *)((int)&((BN_MONT_CTX *)m)->ri + 1);
            unaff_s4 = (BN_MONT_CTX *)&unaff_s4->RR;
          } while ((int)m < (int)local_ec);
        }
        iVar7 = BN_set_word(r,1);
        if (iVar7 != 0) {
          bVar1 = true;
          local_ec = (BN_MONT_CTX *)((int)&unaff_s3[-1].flags + 3);
          while( true ) {
            while (iVar7 = BN_is_bit_set(p,(int)local_ec), unaff_s3 = local_ec, iVar7 == 0) {
              if ((!bVar1) && (iVar7 = BN_mod_mul_reciprocal(r,r,r,&BStack_e0,ctx), iVar7 == 0)) {
                pBVar4 = (BN_RECP_CTX *)0x0;
                goto LAB_004f2118;
              }
              if (local_ec == (BN_MONT_CTX *)0x0) goto LAB_004f22fc;
              local_ec = (BN_MONT_CTX *)((int)&local_ec[-1].flags + 3);
            }
            uVar9 = 1;
            if ((BN_MONT_CTX *)a == (BN_MONT_CTX *)0x1) {
              m = (BIGNUM *)0x0;
            }
            else {
              unaff_s4 = (BN_MONT_CTX *)((int)&local_ec[-1].flags + 3);
              m = (BIGNUM *)0x0;
              if (-1 < (int)unaff_s4) {
                unaff_s3 = (BN_MONT_CTX *)0x1;
                do {
                  iVar7 = BN_is_bit_set(p,(int)unaff_s4);
                  if (iVar7 != 0) {
                    uVar9 = uVar9 << ((int)unaff_s3 - (int)m & 0x1fU) | 1;
                    m = (BIGNUM *)unaff_s3;
                  }
                  unaff_s3 = (BN_MONT_CTX *)((int)&unaff_s3->ri + 1);
                } while ((unaff_s3 != (BN_MONT_CTX *)a) &&
                        (unaff_s4 = (BN_MONT_CTX *)((int)&unaff_s4[-1].flags + 3),
                        unaff_s4 != (BN_MONT_CTX *)0xffffffff));
              }
            }
            if (!bVar1) {
              unaff_s3 = (BN_MONT_CTX *)0x0;
              do {
                iVar7 = BN_mod_mul_reciprocal(r,r,r,&BStack_e0,ctx);
                if (iVar7 == 0) goto LAB_004f2114;
                unaff_s3 = (BN_MONT_CTX *)((int)&unaff_s3->ri + 1);
              } while ((int)unaff_s3 <= (int)m);
            }
            iVar7 = BN_mod_mul_reciprocal
                              (r,r,*(BIGNUM **)(local_ac + ((int)uVar9 >> 1) * 4),&BStack_e0,ctx);
            if (iVar7 == 0) goto LAB_004f2114;
            m = (BIGNUM *)((int)&((BN_MONT_CTX *)m)->ri + 1);
            pBVar10 = (BN_MONT_CTX *)((int)local_ec - (int)m);
            local_ec = unaff_s3;
            if ((int)pBVar10 < 0) break;
            bVar1 = false;
            local_ec = pBVar10;
          }
LAB_004f22fc:
          pBVar4 = (BN_RECP_CTX *)0x1;
          unaff_s3 = local_ec;
          goto LAB_004f2118;
        }
      }
    }
LAB_004f2114:
    pBVar4 = (BN_RECP_CTX *)0x0;
  }
  else {
    pBVar5 = BN_copy(pBVar6,m);
    if (pBVar5 == (BIGNUM *)0x0) goto LAB_004f2114;
    pBVar6->neg = 0;
    iVar7 = BN_RECP_CTX_set(&BStack_e0,pBVar6,ctx);
    if (0 < iVar7) goto LAB_004f1f4c;
    pBVar4 = (BN_RECP_CTX *)0x0;
  }
LAB_004f2118:
  local_f0 = &BStack_e0;
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(local_f0);
LAB_004f1d30:
  if (local_2c == *(int *)puVar2) {
    return (int)pBVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  while( true ) {
    if (((BN_MONT_CTX *)a == (BN_MONT_CTX *)0x0) &&
       (iVar7 = BN_mod_mul_montgomery(&local_f0->N,&local_f0->N,&local_f0->N,unaff_s4,ctx),
       iVar7 == 0)) {
      pBVar4 = (BN_RECP_CTX *)0x0;
      goto LAB_004f1e98;
    }
    if (unaff_s3 == (BN_MONT_CTX *)0x0) break;
    unaff_s3 = (BN_MONT_CTX *)((int)&unaff_s3[-1].flags + 3);
LAB_004f23b8:
    while (iVar7 = BN_is_bit_set(p,(int)unaff_s3), iVar7 != 0) {
      n = (undefined *)((int)&unaff_s3[-1].flags + 3);
      if ((BN_MONT_CTX *)m == (BN_MONT_CTX *)0x1) {
        uVar9 = 1;
        pBVar10 = (BN_MONT_CTX *)0x0;
      }
      else {
        uVar9 = 1;
        pBVar10 = (BN_MONT_CTX *)0x0;
        if (-1 < (int)n) {
          pBVar8 = (BN_MONT_CTX *)0x1;
          do {
            iVar7 = BN_is_bit_set(p,(int)n);
            if (iVar7 != 0) {
              uVar9 = uVar9 << ((int)pBVar8 - (int)pBVar10 & 0x1fU) | 1;
              pBVar10 = pBVar8;
            }
            pBVar8 = (BN_MONT_CTX *)((int)&pBVar8->ri + 1);
            n = n + -1;
          } while ((pBVar8 != (BN_MONT_CTX *)m) && (n != (undefined *)0xffffffff));
        }
      }
      bVar1 = (BN_MONT_CTX *)a == (BN_MONT_CTX *)0x0;
      a = (BIGNUM *)0x0;
      if (bVar1) {
        do {
          iVar7 = BN_mod_mul_montgomery(&local_f0->N,&local_f0->N,&local_f0->N,unaff_s4,ctx);
          if (iVar7 == 0) goto LAB_004f2228;
          a = (BIGNUM *)((int)&((BN_MONT_CTX *)a)->ri + 1);
        } while ((int)a <= (int)pBVar10);
      }
      iVar7 = BN_mod_mul_montgomery
                        (&local_f0->N,&local_f0->N,*(BIGNUM **)(local_ac + ((int)uVar9 >> 1) * 4),
                         unaff_s4,ctx);
      if (iVar7 == 0) goto LAB_004f2228;
      unaff_s3 = (BN_MONT_CTX *)((int)unaff_s3 - (int)((int)&pBVar10->ri + 1));
      if ((int)unaff_s3 < 0) goto LAB_004f2530;
      a = (BIGNUM *)0x0;
    }
  }
LAB_004f2530:
  iVar7 = BN_from_montgomery(r,&local_f0->N,unaff_s4,ctx);
  pBVar4 = (BN_RECP_CTX *)(uint)(iVar7 != 0);
  goto LAB_004f1e98;
LAB_004f2228:
  pBVar4 = (BN_RECP_CTX *)0x0;
LAB_004f1e98:
  BN_MONT_CTX_free(unaff_s4);
LAB_004f1eb0:
  BN_CTX_end(ctx);
  local_f0 = pBVar4;
  goto LAB_004f1d30;
}

