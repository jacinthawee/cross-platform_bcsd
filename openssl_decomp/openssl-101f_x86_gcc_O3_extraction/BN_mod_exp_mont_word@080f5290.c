
int BN_mod_exp_mont_word(BIGNUM *r,ulong a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a_00;
  BIGNUM *rem;
  int iVar4;
  uint uVar5;
  ulong w;
  ulong local_40;
  BN_MONT_CTX *local_34;
  
  local_40 = a;
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x75,0x42,"bn_exp.c",0x35b);
    return -1;
  }
  if ((m->top < 1) || ((*m->d & 1) == 0)) {
    ERR_put_error(3,0x75,0x66,"bn_exp.c",0x364);
    return 0;
  }
  if (m->top == 1) {
    local_40 = a % *m->d;
  }
  iVar2 = BN_num_bits(p);
  if (iVar2 == 0) {
    iVar2 = BN_set_word(r,1);
    return iVar2;
  }
  if (local_40 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  rem = BN_CTX_get(ctx);
  if ((pBVar3 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) || (rem == (BIGNUM *)0x0)) {
LAB_080f5650:
    uVar5 = 0;
  }
  else {
    local_34 = m_ctx;
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      local_34 = BN_MONT_CTX_new();
      if (local_34 == (BN_MONT_CTX *)0x0) goto LAB_080f5650;
      iVar4 = BN_MONT_CTX_set(local_34,m,ctx);
      if (iVar4 != 0) goto LAB_080f537b;
      uVar5 = 0;
    }
    else {
LAB_080f537b:
      iVar2 = iVar2 + -2;
      if (iVar2 < 0) {
        if (local_40 != 1) {
LAB_080f5702:
          iVar2 = BN_set_word(a_00,local_40);
          if (iVar2 != 0) {
            iVar2 = BN_mod_mul_montgomery(a_00,a_00,&local_34->RR,local_34,ctx);
joined_r0x080f5733:
            if (iVar2 != 0) goto LAB_080f56b4;
          }
          goto LAB_080f54f8;
        }
LAB_080f574e:
        iVar2 = BN_set_word(r,1);
        uVar5 = (uint)(iVar2 != 0);
      }
      else {
        bVar1 = true;
        w = local_40;
        do {
          uVar5 = w * w;
          if (w == uVar5 / w) {
            if (!bVar1) goto LAB_080f53f7;
            bVar1 = true;
            pBVar3 = rem;
          }
          else {
            if (bVar1) {
              iVar4 = BN_set_word(a_00,w);
              if (iVar4 == 0) goto LAB_080f54f8;
              iVar4 = BN_mod_mul_montgomery(a_00,a_00,&local_34->RR,local_34,ctx);
              pBVar3 = rem;
            }
            else {
              iVar4 = BN_mul_word(a_00,w);
              if (iVar4 == 0) goto LAB_080f54f8;
              iVar4 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
              pBVar3 = a_00;
              a_00 = rem;
            }
            rem = pBVar3;
            if (iVar4 == 0) goto LAB_080f54f8;
            uVar5 = 1;
LAB_080f53f7:
            iVar4 = BN_mod_mul_montgomery(a_00,a_00,a_00,local_34,ctx);
            if (iVar4 == 0) goto LAB_080f54f8;
            bVar1 = false;
            pBVar3 = rem;
          }
          iVar4 = BN_is_bit_set(p,iVar2);
          w = uVar5;
          rem = pBVar3;
          if ((iVar4 != 0) && (w = local_40 * uVar5, (local_40 * uVar5) / local_40 != uVar5)) {
            if (bVar1) {
              iVar4 = BN_set_word(a_00,uVar5);
              if ((iVar4 == 0) ||
                 (iVar4 = BN_mod_mul_montgomery(a_00,a_00,&local_34->RR,local_34,ctx), iVar4 == 0))
              goto LAB_080f54f8;
              bVar1 = false;
              w = local_40;
            }
            else {
              iVar4 = BN_mul_word(a_00,uVar5);
              if ((iVar4 == 0) ||
                 (iVar4 = BN_div((BIGNUM *)0x0,pBVar3,a_00,m,ctx), w = local_40, rem = a_00,
                 a_00 = pBVar3, iVar4 == 0)) goto LAB_080f54f8;
            }
          }
          iVar2 = iVar2 + -1;
        } while (iVar2 != -1);
        if (w == 1) {
          if (bVar1) goto LAB_080f574e;
LAB_080f56b4:
          iVar2 = BN_from_montgomery(r,a_00,local_34,ctx);
          uVar5 = (uint)(iVar2 != 0);
        }
        else {
          local_40 = w;
          if (bVar1) goto LAB_080f5702;
          iVar2 = BN_mul_word(a_00,w);
          if (iVar2 != 0) {
            iVar2 = BN_div((BIGNUM *)0x0,rem,a_00,m,ctx);
            a_00 = rem;
            goto joined_r0x080f5733;
          }
LAB_080f54f8:
          uVar5 = 0;
        }
      }
      if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_080f5511;
    }
    BN_MONT_CTX_free(local_34);
  }
LAB_080f5511:
  BN_CTX_end(ctx);
  return uVar5;
}

