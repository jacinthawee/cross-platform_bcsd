
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  int iVar2;
  BIGNUM *a_00;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  int local_f8;
  BN_RECP_CTX *local_f4;
  uint local_f0;
  int local_e8;
  BN_RECP_CTX local_d4;
  BIGNUM *local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)&p->flags & 4) != 0) {
    iVar2 = -1;
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x10e);
    goto LAB_080f1ef5;
  }
  local_e8 = BN_num_bits(p);
  if (local_e8 == 0) {
    iVar2 = m->top;
    if (((iVar2 == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
    }
    else {
      iVar2 = BN_set_word(r,1);
    }
    goto LAB_080f1ef5;
  }
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar3 = BN_CTX_get(ctx);
  local_a0[0] = pBVar3;
  if ((a_00 == (BIGNUM *)0x0) || (pBVar3 == (BIGNUM *)0x0)) {
LAB_080f2180:
    iVar2 = 0;
  }
  else {
    BN_RECP_CTX_init(&local_d4);
    pBVar4 = m;
    if (m->neg != 0) {
      pBVar4 = BN_copy(a_00,m);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_080f2180;
      a_00->neg = 0;
      pBVar4 = a_00;
    }
    iVar2 = BN_RECP_CTX_set(&local_d4,pBVar4,ctx);
    if ((iVar2 < 1) || (iVar2 = BN_nnmod(pBVar3,a,m,ctx), iVar2 == 0)) goto LAB_080f2180;
    if (pBVar3->top == 0) {
      iVar2 = 1;
      BN_set_word(r,0);
    }
    else {
      if (local_e8 < 0x2a0) {
        if (0xef < local_e8) {
          iVar2 = 0x10;
          local_f8 = 5;
          goto LAB_080f2205;
        }
        if (0x4f < local_e8) {
          iVar2 = 8;
          local_f8 = 4;
          goto LAB_080f2205;
        }
        if (0x17 < local_e8) {
          iVar2 = 4;
          local_f8 = 3;
          goto LAB_080f2205;
        }
        local_f8 = 1;
      }
      else {
        iVar2 = 0x20;
        local_f8 = 6;
LAB_080f2205:
        iVar5 = BN_mod_mul_reciprocal(a_00,pBVar3,pBVar3,&local_d4,ctx);
        if (iVar5 == 0) goto LAB_080f2180;
        iVar5 = 1;
        do {
          pBVar3 = BN_CTX_get(ctx);
          local_a0[iVar5] = pBVar3;
          if ((pBVar3 == (BIGNUM *)0x0) ||
             (iVar7 = BN_mod_mul_reciprocal(pBVar3,local_a0[iVar5 + -1],a_00,&local_d4,ctx),
             iVar7 == 0)) goto LAB_080f2180;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar2);
      }
      iVar2 = BN_set_word(r,1);
      if (iVar2 == 0) goto LAB_080f2180;
      local_e8 = local_e8 + -1;
      bVar1 = true;
      while( true ) {
        while (iVar2 = BN_is_bit_set(p,local_e8), iVar2 != 0) {
          if (local_f8 == 1) {
            local_f0 = 1;
            iVar2 = 0;
          }
          else {
            iVar2 = 0;
            local_f0 = 1;
            iVar5 = local_e8 + -1;
            if (-1 < iVar5) {
              iVar7 = 1;
              do {
                iVar6 = BN_is_bit_set(p,iVar5);
                if (iVar6 != 0) {
                  local_f0 = local_f0 << ((char)iVar7 - (char)iVar2 & 0x1fU) | 1;
                  iVar2 = iVar7;
                }
                iVar7 = iVar7 + 1;
              } while ((iVar7 != local_f8) && (iVar5 = iVar5 + -1, iVar5 != -1));
            }
          }
          if (!bVar1) {
            iVar5 = 0;
            do {
              iVar7 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx);
              if (iVar7 == 0) goto LAB_080f2180;
              iVar5 = iVar5 + 1;
            } while (iVar5 <= iVar2);
          }
          iVar5 = BN_mod_mul_reciprocal(r,r,local_a0[(int)local_f0 >> 1],&local_d4,ctx);
          if (iVar5 == 0) goto LAB_080f2180;
          local_e8 = local_e8 - (iVar2 + 1);
          if (local_e8 < 0) goto LAB_080f22ac;
          bVar1 = false;
        }
        if ((!bVar1) && (iVar2 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx), iVar2 == 0))
        goto LAB_080f2180;
        if (local_e8 == 0) break;
        local_e8 = local_e8 + -1;
      }
LAB_080f22ac:
      iVar2 = 1;
    }
  }
  local_f4 = &local_d4;
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(local_f4);
LAB_080f1ef5:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

