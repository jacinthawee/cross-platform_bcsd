
int BN_mod_exp_mont_word(BIGNUM *r,ulong a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a_00;
  BIGNUM *rem;
  ulong uVar3;
  int iVar4;
  ulong extraout_r1;
  BN_MONT_CTX *pBVar5;
  ulong w;
  ulong w_00;
  bool bVar6;
  bool bVar7;
  BN_MONT_CTX *local_40;
  
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x75,0x42,"bn_exp.c",0x35b);
    return -1;
  }
  if ((m->top < 1) || (-1 < (int)(*m->d << 0x1f))) {
    ERR_put_error(3,0x75,0x66,"bn_exp.c",0x364);
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
    iVar1 = BN_set_word(r,1);
    return iVar1;
  }
  if (a == 0) {
    BN_set_word(r,0);
    return 1;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  if ((a_00 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0) || (rem == (BIGNUM *)0x0)) {
LAB_00089504:
    m_ctx = (BN_MONT_CTX *)0x0;
  }
  else {
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      local_40 = BN_MONT_CTX_new();
      if (local_40 == (BN_MONT_CTX *)0x0) goto LAB_00089504;
      iVar4 = BN_MONT_CTX_set(local_40,m,ctx);
      if (iVar4 != 0) goto LAB_000893f0;
    }
    else {
      local_40 = m_ctx;
LAB_000893f0:
      iVar1 = iVar1 + -2;
      if (iVar1 < 0) {
        if (a != 1) {
LAB_00089572:
          iVar1 = BN_set_word(a_00,a);
          if (iVar1 != 0) {
            iVar1 = BN_mod_mul_montgomery(a_00,a_00,&local_40->RR,local_40,ctx);
joined_r0x000895c8:
            if (iVar1 != 0) goto LAB_000895cc;
          }
          goto LAB_00089590;
        }
LAB_00089602:
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
            if (!bVar6) goto LAB_0008942e;
            bVar6 = true;
            pBVar2 = a_00;
          }
          else {
            if (bVar6) {
              iVar4 = BN_set_word(a_00,w);
              if (iVar4 == 0) goto LAB_00089590;
              iVar4 = BN_mod_mul_montgomery(a_00,a_00,&local_40->RR,local_40,ctx);
              pBVar2 = a_00;
            }
            else {
              iVar4 = BN_mul_word(a_00,w);
              if (iVar4 == 0) goto LAB_00089590;
              iVar4 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
              pBVar2 = rem;
              rem = a_00;
            }
            a_00 = pBVar2;
            if (iVar4 == 0) goto LAB_00089590;
            w_00 = 1;
LAB_0008942e:
            iVar4 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_40,ctx);
            if (iVar4 == 0) goto LAB_00089590;
            bVar6 = false;
            pBVar2 = a_00;
          }
          iVar4 = BN_is_bit_set(p,iVar1);
          a_00 = pBVar2;
          w = w_00;
          if (iVar4 != 0) {
            uVar3 = __udivsi3(a * w_00,a);
            w = a * w_00;
            if (w_00 != uVar3) {
              if (bVar6) {
                iVar4 = BN_set_word(pBVar2,w_00);
                if ((iVar4 == 0) ||
                   (iVar4 = BN_mod_mul_montgomery(pBVar2,pBVar2,&local_40->RR,local_40,ctx),
                   iVar4 == 0)) goto LAB_00089590;
                bVar6 = false;
                w = a;
              }
              else {
                iVar4 = BN_mul_word(pBVar2,w_00);
                if ((iVar4 == 0) ||
                   (iVar4 = BN_div((BIGNUM *)0x0,rem,pBVar2,m,ctx), a_00 = rem, w = a, rem = pBVar2,
                   iVar4 == 0)) goto LAB_00089590;
              }
            }
          }
          bVar7 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar7);
        if (w == 1) {
          if (bVar6) goto LAB_00089602;
LAB_000895cc:
          pBVar5 = (BN_MONT_CTX *)BN_from_montgomery(r,a_00,local_40,ctx);
          if (pBVar5 != (BN_MONT_CTX *)0x0) {
            pBVar5 = (BN_MONT_CTX *)0x1;
          }
        }
        else {
          a = w;
          if (bVar6) goto LAB_00089572;
          iVar1 = BN_mul_word(a_00,w);
          if (iVar1 != 0) {
            iVar1 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
            a_00 = rem;
            goto joined_r0x000895c8;
          }
LAB_00089590:
          pBVar5 = (BN_MONT_CTX *)0x0;
        }
      }
      bVar6 = m_ctx != (BN_MONT_CTX *)0x0;
      m_ctx = pBVar5;
      if (bVar6) goto LAB_00089506;
    }
    BN_MONT_CTX_free(local_40);
  }
LAB_00089506:
  BN_CTX_end(ctx);
  return (int)m_ctx;
}

