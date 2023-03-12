
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  BN_RECP_CTX *local_fc;
  uint local_f8;
  int local_f4;
  int local_ec;
  BN_RECP_CTX local_d4;
  BIGNUM *local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)&p->flags & 4) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x108);
    iVar3 = -1;
    goto LAB_080f4331;
  }
  local_f4 = BN_num_bits(p);
  if (local_f4 == 0) {
    iVar3 = BN_set_word(r,1);
    goto LAB_080f4331;
  }
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a0[0] = pBVar2;
  if ((a_00 == (BIGNUM *)0x0) || (pBVar2 == (BIGNUM *)0x0)) {
LAB_080f4387:
    iVar3 = 0;
  }
  else {
    BN_RECP_CTX_init(&local_d4);
    pBVar5 = m;
    if (m->neg != 0) {
      pBVar5 = BN_copy(a_00,m);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_080f4387;
      a_00->neg = 0;
      pBVar5 = a_00;
    }
    iVar3 = BN_RECP_CTX_set(&local_d4,pBVar5,ctx);
    if ((iVar3 < 1) || (iVar3 = BN_nnmod(pBVar2,a,m,ctx), iVar3 == 0)) goto LAB_080f4387;
    if (pBVar2->top == 0) {
      iVar3 = 1;
      BN_set_word(r,0);
    }
    else {
      if (local_f4 < 0x2a0) {
        if (0xef < local_f4) {
          local_f8 = 0x10;
          local_ec = 5;
          goto LAB_080f43b8;
        }
        if (0x4f < local_f4) {
          local_f8 = 8;
          local_ec = 4;
          goto LAB_080f43b8;
        }
        if (0x17 < local_f4) {
          local_f8 = 4;
          local_ec = 3;
          goto LAB_080f43b8;
        }
        local_ec = 1;
      }
      else {
        local_f8 = 0x20;
        local_ec = 6;
LAB_080f43b8:
        iVar3 = BN_mod_mul_reciprocal(a_00,pBVar2,pBVar2,&local_d4,ctx);
        if (iVar3 == 0) goto LAB_080f4387;
        iVar3 = 1;
        do {
          pBVar2 = BN_CTX_get(ctx);
          local_a0[iVar3] = pBVar2;
          if ((pBVar2 == (BIGNUM *)0x0) ||
             (iVar7 = BN_mod_mul_reciprocal(pBVar2,local_a0[iVar3 + -1],a_00,&local_d4,ctx),
             iVar7 == 0)) goto LAB_080f4387;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)local_f8);
      }
      iVar3 = BN_set_word(r,1);
      if (iVar3 == 0) goto LAB_080f4387;
      local_f4 = local_f4 + -1;
      bVar1 = true;
      while( true ) {
        while (iVar3 = BN_is_bit_set(p,local_f4), iVar3 != 0) {
          local_f8 = 1;
          iVar3 = 0;
          if ((local_ec != 1) && (iVar7 = local_f4 + -1, -1 < iVar7)) {
            iVar6 = 1;
            do {
              iVar4 = BN_is_bit_set(p,iVar7);
              if (iVar4 != 0) {
                local_f8 = local_f8 << ((char)iVar6 - (char)iVar3 & 0x1fU) | 1;
                iVar3 = iVar6;
              }
              iVar6 = iVar6 + 1;
            } while ((iVar6 != local_ec) && (iVar7 = iVar7 + -1, iVar7 != -1));
          }
          iVar7 = 0;
          if (!bVar1) {
            do {
              iVar6 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx);
              if (iVar6 == 0) goto LAB_080f4387;
              iVar7 = iVar7 + 1;
            } while (iVar7 <= iVar3);
          }
          iVar7 = BN_mod_mul_reciprocal(r,r,local_a0[(int)local_f8 >> 1],&local_d4,ctx);
          if (iVar7 == 0) goto LAB_080f4387;
          local_f4 = local_f4 - (iVar3 + 1);
          if (local_f4 < 0) goto LAB_080f44a8;
          bVar1 = false;
        }
        if ((!bVar1) && (iVar3 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx), iVar3 == 0))
        goto LAB_080f4387;
        if (local_f4 == 0) break;
        local_f4 = local_f4 + -1;
      }
LAB_080f44a8:
      iVar3 = 1;
    }
  }
  local_fc = &local_d4;
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(local_fc);
LAB_080f4331:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}

