
int BN_mod_exp_simple(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  int iVar2;
  BIGNUM *r_00;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  uint local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  BIGNUM *apBStack_a4 [33];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)&p->flags & 4) == 0) {
    local_bc = BN_num_bits(p);
    if (local_bc == 0) {
      iVar2 = m->top;
      if (((iVar2 != 1) || (*m->d != 1)) || (m->neg != 0)) {
        if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
          iVar2 = BN_set_word(r,1);
          return iVar2;
        }
        goto LAB_080f4255;
      }
      BN_set_word(r,0);
    }
    else {
      BN_CTX_start(ctx);
      r_00 = BN_CTX_get(ctx);
      pBVar3 = BN_CTX_get(ctx);
      apBStack_a4[1] = pBVar3;
      if (((r_00 == (BIGNUM *)0x0) || (pBVar3 == (BIGNUM *)0x0)) ||
         (iVar2 = BN_nnmod(pBVar3,a,m,ctx), iVar2 == 0)) {
LAB_080f40a8:
        iVar2 = 0;
      }
      else if (pBVar3->top == 0) {
        iVar2 = 1;
        BN_set_word(r,0);
      }
      else {
        if (local_bc < 0x2a0) {
          if (0xef < local_bc) {
            local_c4 = 0x10;
            local_c0 = 5;
            goto LAB_080f4110;
          }
          if (0x4f < local_bc) {
            local_c4 = 8;
            local_c0 = 4;
            goto LAB_080f4110;
          }
          if (0x17 < local_bc) {
            local_c4 = 4;
            local_c0 = 3;
            goto LAB_080f4110;
          }
          local_c0 = 1;
        }
        else {
          local_c4 = 0x20;
          local_c0 = 6;
LAB_080f4110:
          iVar2 = BN_mod_mul(r_00,pBVar3,pBVar3,m,ctx);
          if (iVar2 == 0) goto LAB_080f40a8;
          iVar2 = 1;
          do {
            pBVar3 = BN_CTX_get(ctx);
            apBStack_a4[iVar2 + 1] = pBVar3;
            if ((pBVar3 == (BIGNUM *)0x0) ||
               (iVar4 = BN_mod_mul(pBVar3,apBStack_a4[iVar2],r_00,m,ctx), iVar4 == 0))
            goto LAB_080f40a8;
            iVar2 = iVar2 + 1;
          } while (iVar2 < local_c4);
        }
        iVar2 = BN_set_word(r,1);
        if (iVar2 == 0) goto LAB_080f40a8;
        bVar1 = true;
        local_bc = local_bc + -1;
        while( true ) {
          while (iVar2 = BN_is_bit_set(p,local_bc), iVar2 != 0) {
            if (local_c0 == 1) {
              local_c8 = 1;
              iVar2 = 0;
            }
            else {
              iVar2 = 0;
              local_c8 = 1;
              iVar4 = local_bc + -1;
              if (-1 < iVar4) {
                iVar6 = 1;
                do {
                  iVar5 = BN_is_bit_set(p,iVar4);
                  if (iVar5 != 0) {
                    local_c8 = local_c8 << ((char)iVar6 - (char)iVar2 & 0x1fU) | 1;
                    iVar2 = iVar6;
                  }
                  iVar6 = iVar6 + 1;
                } while ((iVar6 != local_c0) && (iVar4 = iVar4 + -1, iVar4 != -1));
              }
            }
            iVar4 = 0;
            if (!bVar1) {
              do {
                iVar6 = BN_mod_mul(r,r,r,m,ctx);
                if (iVar6 == 0) goto LAB_080f40a8;
                iVar4 = iVar4 + 1;
              } while (iVar4 <= iVar2);
            }
            iVar4 = BN_mod_mul(r,r,apBStack_a4[((int)local_c8 >> 1) + 1],m,ctx);
            if (iVar4 == 0) goto LAB_080f40a8;
            local_bc = local_bc - (iVar2 + 1);
            if (local_bc < 0) goto LAB_080f4204;
            bVar1 = false;
          }
          if ((!bVar1) && (iVar2 = BN_mod_mul(r,r,r,m,ctx), iVar2 == 0)) goto LAB_080f40a8;
          if (local_bc == 0) break;
          local_bc = local_bc + -1;
        }
LAB_080f4204:
        iVar2 = 1;
      }
      BN_CTX_end(ctx);
    }
  }
  else {
    iVar2 = -1;
    ERR_put_error(3,0x7e,0x42,"bn_exp.c",0x436);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
LAB_080f4255:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

