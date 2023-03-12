
int BN_mod_exp_mont_word(BIGNUM *r,ulong a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a_00;
  BIGNUM *rem;
  ulong uVar3;
  int iVar4;
  BN_MONT_CTX *pBVar5;
  ulong extraout_r1;
  ulong w;
  ulong w_00;
  bool bVar6;
  bool bVar7;
  BN_MONT_CTX *local_38;
  
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x75,0x42,"bn_exp.c",0x3b3);
    return -1;
  }
  if ((m->top < 1) || (-1 < (int)(*m->d << 0x1f))) {
    ERR_put_error(3,0x75,0x66,"bn_exp.c",0x3bb);
    return 0;
  }
  if (m->top == 1) {
    __aeabi_uidivmod(a);
    iVar1 = BN_num_bits(p);
    a = extraout_r1;
  }
  else {
    iVar1 = BN_num_bits(p);
  }
  if (iVar1 == 0) {
    if (((m->top != 1) || (*m->d != 1)) || (m->neg != 0)) {
      iVar1 = BN_set_word(r,1);
      return iVar1;
    }
LAB_000873de:
    BN_set_word(r,0);
    return 1;
  }
  if (a == 0) goto LAB_000873de;
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  if ((a_00 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0) || (rem == (BIGNUM *)0x0)) {
LAB_0008741e:
    m_ctx = (BN_MONT_CTX *)0x0;
  }
  else {
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      local_38 = BN_MONT_CTX_new();
      if (local_38 == (BN_MONT_CTX *)0x0) goto LAB_0008741e;
      iVar4 = BN_MONT_CTX_set(local_38,m,ctx);
      if (iVar4 != 0) goto LAB_000872ba;
    }
    else {
      local_38 = m_ctx;
LAB_000872ba:
      iVar1 = iVar1 + -2;
      if (iVar1 < 0) {
        if (a != 1) {
LAB_00087456:
          iVar1 = BN_set_word(a_00,a);
          if (iVar1 != 0) {
            iVar1 = BN_mod_mul_montgomery(a_00,a_00,&local_38->RR,local_38,ctx);
joined_r0x00087478:
            if (iVar1 != 0) goto LAB_0008747c;
          }
          goto LAB_00087430;
        }
LAB_000874e0:
        pBVar5 = (BN_MONT_CTX *)BN_set_word(r,1);
        if (pBVar5 != (BN_MONT_CTX *)0x0) {
          pBVar5 = (BN_MONT_CTX *)0x1;
        }
      }
      else {
        bVar6 = true;
        w = a;
        do {
          w_00 = w * w;
          uVar3 = __udivsi3(w_00,w);
          if (uVar3 == w) {
            if (!bVar6) goto LAB_000872fa;
            bVar6 = true;
            pBVar2 = a_00;
          }
          else {
            if (bVar6) {
              iVar4 = BN_set_word(a_00,w);
              if (iVar4 == 0) goto LAB_00087430;
              iVar4 = BN_mod_mul_montgomery(a_00,a_00,&local_38->RR,local_38,ctx);
              pBVar2 = a_00;
            }
            else {
              iVar4 = BN_mul_word(a_00,w);
              if (iVar4 == 0) goto LAB_00087430;
              iVar4 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
              pBVar2 = rem;
              rem = a_00;
            }
            a_00 = pBVar2;
            if (iVar4 == 0) goto LAB_00087430;
            w_00 = 1;
LAB_000872fa:
            iVar4 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_38,ctx);
            if (iVar4 == 0) goto LAB_00087430;
            bVar6 = false;
            pBVar2 = a_00;
          }
          iVar4 = BN_is_bit_set(p,iVar1);
          a_00 = pBVar2;
          w = w_00;
          if (iVar4 != 0) {
            w = a * w_00;
            uVar3 = __udivsi3(w,a);
            if (w_00 != uVar3) {
              if (bVar6) {
                iVar4 = BN_set_word(pBVar2,w_00);
                if ((iVar4 == 0) ||
                   (iVar4 = BN_mod_mul_montgomery(pBVar2,pBVar2,&local_38->RR,local_38,ctx),
                   iVar4 == 0)) goto LAB_00087430;
                bVar6 = false;
                w = a;
              }
              else {
                iVar4 = BN_mul_word(pBVar2,w_00);
                if ((iVar4 == 0) ||
                   (iVar4 = BN_div((BIGNUM *)0x0,rem,pBVar2,m,ctx), a_00 = rem, w = a, rem = pBVar2,
                   iVar4 == 0)) goto LAB_00087430;
              }
            }
          }
          bVar7 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar7);
        if (w == 1) {
          if (bVar6) goto LAB_000874e0;
LAB_0008747c:
          pBVar5 = (BN_MONT_CTX *)BN_from_montgomery(r,a_00,local_38,ctx);
          if (pBVar5 != (BN_MONT_CTX *)0x0) {
            pBVar5 = (BN_MONT_CTX *)0x1;
          }
        }
        else {
          a = w;
          if (bVar6) goto LAB_00087456;
          iVar1 = BN_mul_word(a_00,w);
          if (iVar1 != 0) {
            iVar1 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
            a_00 = rem;
            goto joined_r0x00087478;
          }
LAB_00087430:
          pBVar5 = (BN_MONT_CTX *)0x0;
        }
      }
      bVar6 = m_ctx != (BN_MONT_CTX *)0x0;
      m_ctx = pBVar5;
      if (bVar6) goto LAB_00087420;
    }
    BN_MONT_CTX_free(local_38);
  }
LAB_00087420:
  BN_CTX_end(ctx);
  return (int)m_ctx;
}

