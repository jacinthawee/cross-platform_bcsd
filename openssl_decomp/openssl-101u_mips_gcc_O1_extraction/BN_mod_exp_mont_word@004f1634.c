
int BN_mod_exp_mont_word(BIGNUM *r,ulong a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *a_00;
  BIGNUM *pBVar5;
  int iVar6;
  uint uVar7;
  ulong w;
  BN_MONT_CTX *local_38;
  
  if ((p->flags & 4U) != 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x75,0x42,"bn_exp.c",0x3b3);
    return -1;
  }
  if ((m->top < 1) || (uVar7 = *m->d, (uVar7 & 1) == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x75,0x66,"bn_exp.c",0x3bb);
    return 0;
  }
  if (m->top == 1) {
    if (uVar7 == 0) {
      trap(7);
    }
    a = a % uVar7;
    iVar3 = BN_num_bits(p);
    if (iVar3 != 0) goto LAB_004f1734;
    iVar3 = m->top;
  }
  else {
    iVar3 = BN_num_bits(p);
    if (iVar3 != 0) {
LAB_004f1734:
      if (a == 0) goto LAB_004f19fc;
      BN_CTX_start(ctx);
      pBVar4 = BN_CTX_get(ctx);
      a_00 = BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      if (((pBVar4 == (BIGNUM *)0x0) || (a_00 == (BIGNUM *)0x0)) || (pBVar5 == (BIGNUM *)0x0)) {
LAB_004f1aa4:
        uVar7 = 0;
      }
      else {
        local_38 = m_ctx;
        if (m_ctx == (BN_MONT_CTX *)0x0) {
          local_38 = BN_MONT_CTX_new();
          if (local_38 == (BN_MONT_CTX *)0x0) goto LAB_004f1aa4;
          iVar6 = BN_MONT_CTX_set(local_38,m,ctx);
          if (iVar6 != 0) goto LAB_004f17a0;
          uVar7 = 0;
        }
        else {
LAB_004f17a0:
          iVar3 = iVar3 + -2;
          if (iVar3 < 0) {
            if (a != 1) {
LAB_004f1ba4:
              iVar3 = BN_set_word(a_00,a);
              if (iVar3 != 0) {
                iVar3 = BN_mod_mul_montgomery(a_00,a_00,&local_38->RR,local_38,ctx);
joined_r0x004f1bdc:
                if (iVar3 != 0) goto LAB_004f1afc;
              }
              goto LAB_004f1924;
            }
LAB_004f1bf4:
            iVar3 = BN_set_word(r,1);
            uVar7 = (uint)(iVar3 != 0);
          }
          else {
            bVar1 = true;
            w = a;
            do {
              uVar7 = w * w;
              if (w == 0) {
                trap(7);
              }
              if (w == uVar7 / w) {
                bVar2 = !bVar1;
                bVar1 = true;
                pBVar4 = a_00;
                if (bVar2) goto LAB_004f1814;
              }
              else {
                if (bVar1) {
                  iVar6 = BN_set_word(a_00,w);
                  if (iVar6 == 0) goto LAB_004f1924;
                  iVar6 = BN_mod_mul_montgomery(a_00,a_00,&local_38->RR,local_38,ctx);
                  pBVar4 = a_00;
                }
                else {
                  iVar6 = BN_mul_word(a_00,w);
                  if (iVar6 == 0) goto LAB_004f1924;
                  iVar6 = (*(code *)PTR_BN_div_006a855c)(0,pBVar5,a_00,m,ctx);
                  pBVar4 = pBVar5;
                  pBVar5 = a_00;
                }
                a_00 = pBVar4;
                if (iVar6 == 0) goto LAB_004f1924;
                uVar7 = 1;
LAB_004f1814:
                iVar6 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_38,ctx);
                if (iVar6 == 0) goto LAB_004f1924;
                bVar1 = false;
                pBVar4 = a_00;
              }
              iVar6 = BN_is_bit_set(p,iVar3);
              a_00 = pBVar4;
              w = uVar7;
              if (iVar6 != 0) {
                if (a == 0) {
                  trap(7);
                }
                w = a * uVar7;
                if ((a * uVar7) / a != uVar7) {
                  if (bVar1) {
                    iVar6 = BN_set_word(pBVar4,uVar7);
                    if ((iVar6 == 0) ||
                       (iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar4,&local_38->RR,local_38,ctx),
                       iVar6 == 0)) goto LAB_004f1924;
                    bVar1 = false;
                    w = a;
                  }
                  else {
                    iVar6 = BN_mul_word(pBVar4,uVar7);
                    if ((iVar6 == 0) ||
                       (iVar6 = (*(code *)PTR_BN_div_006a855c)(0,pBVar5,pBVar4,m,ctx), a_00 = pBVar5
                       , pBVar5 = pBVar4, w = a, iVar6 == 0)) goto LAB_004f1924;
                  }
                }
              }
              iVar3 = iVar3 + -1;
            } while (iVar3 != -1);
            if (w == 1) {
              if (bVar1) goto LAB_004f1bf4;
LAB_004f1afc:
              iVar3 = BN_from_montgomery(r,a_00,local_38,ctx);
              uVar7 = (uint)(iVar3 != 0);
            }
            else {
              a = w;
              if (bVar1) goto LAB_004f1ba4;
              iVar3 = BN_mul_word(a_00,w);
              if (iVar3 != 0) {
                iVar3 = (*(code *)PTR_BN_div_006a855c)(0,pBVar5,a_00,m,ctx);
                a_00 = pBVar5;
                goto joined_r0x004f1bdc;
              }
LAB_004f1924:
              uVar7 = 0;
            }
          }
          if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_004f1934;
        }
        BN_MONT_CTX_free(local_38);
      }
LAB_004f1934:
      BN_CTX_end(ctx);
      return uVar7;
    }
    iVar3 = m->top;
  }
  if (((iVar3 != 1) || (*m->d != 1)) || (m->neg != 0)) {
    iVar3 = BN_set_word(r,1);
    return iVar3;
  }
LAB_004f19fc:
  BN_set_word(r,0);
  return 1;
}
