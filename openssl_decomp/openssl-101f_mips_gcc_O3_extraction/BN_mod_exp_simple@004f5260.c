
/* WARNING: Type propagation algorithm not settling */

int BN_mod_exp_simple(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  int iVar8;
  ulong *puVar9;
  undefined4 uVar10;
  uint uVar11;
  ulong *puVar12;
  ulong *puVar13;
  BIGNUM *a_00;
  ulong uVar14;
  undefined4 uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong *puVar18;
  undefined *n;
  BIGNUM **ppBVar19;
  BIGNUM *local_bc;
  int local_b8;
  BIGNUM *local_ac [32];
  BIGNUM *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  if ((p->flags & 4U) == 0) {
    pBVar5 = p;
    a_00 = a;
    iVar4 = BN_num_bits(p);
    if (iVar4 != 0) {
      BN_CTX_start(ctx);
      pBVar5 = BN_CTX_get(ctx);
      pBVar6 = BN_CTX_get(ctx);
      local_ac[0] = pBVar6;
      if (((pBVar5 == (BIGNUM *)0x0) || (pBVar6 == (BIGNUM *)0x0)) ||
         (iVar7 = BN_nnmod(pBVar6,a,m,ctx), a_00 = a, iVar7 == 0)) {
LAB_004f5340:
        iVar4 = 0;
      }
      else if (pBVar6->top == 0) {
        a_00 = (BIGNUM *)0x0;
        iVar4 = 1;
        BN_set_word(r,0);
      }
      else {
        if (iVar4 < 0x2a0) {
          if (0xef < iVar4) {
            local_bc = (BIGNUM *)0x10;
            local_b8 = 5;
            goto LAB_004f556c;
          }
          if (0x4f < iVar4) {
            local_bc = (BIGNUM *)0x8;
            local_b8 = 4;
            goto LAB_004f556c;
          }
          if (0x17 < iVar4) {
            local_bc = (BIGNUM *)0x4;
            local_b8 = 3;
            goto LAB_004f556c;
          }
          local_b8 = 1;
        }
        else {
          local_bc = (BIGNUM *)0x20;
          local_b8 = 6;
LAB_004f556c:
          iVar7 = BN_mod_mul(pBVar5,pBVar6,pBVar6,m,ctx);
          a_00 = pBVar6;
          if (iVar7 == 0) goto LAB_004f5340;
          ppBVar19 = local_ac;
          iVar7 = 1;
          do {
            ppBVar19 = ppBVar19 + 1;
            pBVar6 = BN_CTX_get(ctx);
            *ppBVar19 = pBVar6;
            if (pBVar6 == (BIGNUM *)0x0) goto LAB_004f5340;
            a_00 = ppBVar19[-1];
            iVar8 = BN_mod_mul(pBVar6,a_00,pBVar5,m,ctx);
            if (iVar8 == 0) goto LAB_004f5340;
            iVar7 = iVar7 + 1;
          } while (iVar7 < (int)local_bc);
        }
        a_00 = (BIGNUM *)0x1;
        iVar7 = BN_set_word(r,1);
        if (iVar7 == 0) goto LAB_004f5340;
        local_bc = (BIGNUM *)(iVar4 + -1);
        bVar2 = true;
        do {
          while (a_00 = local_bc, iVar4 = BN_is_bit_set(p,(int)local_bc), iVar4 != 0) {
            uVar11 = 1;
            if (local_b8 == 1) {
              iVar4 = 0;
            }
            else {
              n = (undefined *)((int)&local_bc[-1].flags + 3);
              iVar4 = 0;
              if (-1 < (int)n) {
                iVar7 = 1;
                do {
                  iVar8 = BN_is_bit_set(p,(int)n);
                  if (iVar8 != 0) {
                    uVar11 = uVar11 << (iVar7 - iVar4 & 0x1fU) | 1;
                    iVar4 = iVar7;
                  }
                  iVar7 = iVar7 + 1;
                } while ((iVar7 != local_b8) && (n = n + -1, n != (undefined *)0xffffffff));
              }
            }
            if (!bVar2) {
              iVar7 = 0;
              do {
                a_00 = r;
                iVar8 = BN_mod_mul(r,r,r,m,ctx);
                if (iVar8 == 0) goto LAB_004f5340;
                iVar7 = iVar7 + 1;
              } while (iVar7 <= iVar4);
            }
            a_00 = r;
            iVar7 = BN_mod_mul(r,r,local_ac[(int)uVar11 >> 1],m,ctx);
            if (iVar7 == 0) goto LAB_004f5340;
            local_bc = (BIGNUM *)((int)local_bc - (iVar4 + 1));
            if ((int)local_bc < 0) goto LAB_004f5664;
            bVar2 = false;
          }
          if ((!bVar2) && (a_00 = r, iVar4 = BN_mod_mul(r,r,r,m,ctx), iVar4 == 0)) {
            iVar4 = 0;
            goto LAB_004f5344;
          }
          bVar1 = local_bc != (BIGNUM *)0x0;
          local_bc = (BIGNUM *)((int)&local_bc[-1].flags + 3);
        } while (bVar1);
LAB_004f5664:
        iVar4 = 1;
      }
LAB_004f5344:
      BN_CTX_end(ctx);
      goto LAB_004f5358;
    }
    if (local_2c == *(BIGNUM **)puVar3) {
      iVar4 = BN_set_word(r,1);
      return iVar4;
    }
  }
  else {
    a_00 = (BIGNUM *)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x7e,0x42,"bn_exp.c",0x3e3);
    iVar4 = -1;
LAB_004f5358:
    pBVar5 = local_2c;
    if (local_2c == *(BIGNUM **)puVar3) {
      return iVar4;
    }
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0xffffff < (int)a_00) {
    uVar15 = 0x72;
    uVar10 = 0x135;
LAB_004f5814:
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x78,uVar15,"bn_lib.c",uVar10);
    return 0;
  }
  if ((pBVar5->flags & 2U) != 0) {
    uVar15 = 0x69;
    uVar10 = 0x13a;
    goto LAB_004f5814;
  }
  puVar9 = (ulong *)(*(code *)PTR_CRYPTO_malloc_006a8108)((int)a_00 << 2,"bn_lib.c",0x13d);
  if (puVar9 == (ulong *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x78,0x41,"bn_lib.c",0x140);
    return 0;
  }
  puVar18 = pBVar5->d;
  if (puVar18 == (ulong *)0x0) {
    return (int)puVar9;
  }
  uVar11 = pBVar5->top;
  iVar7 = (int)uVar11 >> 2;
  puVar12 = puVar9;
  puVar13 = puVar18;
  iVar4 = iVar7;
  if (0 < iVar7) {
    do {
      uVar17 = puVar13[1];
      uVar16 = puVar13[2];
      iVar4 = iVar4 + -1;
      uVar14 = puVar13[3];
      *puVar12 = *puVar13;
      puVar12[1] = uVar17;
      puVar12[2] = uVar16;
      puVar12[3] = uVar14;
      puVar12 = puVar12 + 4;
      puVar13 = puVar13 + 4;
    } while (iVar4 != 0);
    uVar11 = pBVar5->top;
    puVar18 = puVar18 + iVar7 * 4;
    puVar12 = puVar9 + iVar7 * 4;
  }
  uVar11 = uVar11 & 3;
  if (uVar11 != 2) {
    if (uVar11 != 3) {
      if (uVar11 != 1) {
        return (int)puVar9;
      }
      goto LAB_004f57e4;
    }
    puVar12[2] = puVar18[2];
  }
  puVar12[1] = puVar18[1];
LAB_004f57e4:
  *puVar12 = *puVar18;
  return (int)puVar9;
}

