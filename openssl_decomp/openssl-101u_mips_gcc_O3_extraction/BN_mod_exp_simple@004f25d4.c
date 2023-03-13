
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
  ulong *puVar8;
  undefined4 uVar9;
  uint uVar10;
  ulong *puVar11;
  ulong *puVar12;
  BIGNUM *a_00;
  ulong uVar13;
  undefined4 uVar14;
  ulong uVar15;
  ulong uVar16;
  int iVar17;
  ulong *puVar18;
  undefined *n;
  BIGNUM **ppBVar19;
  BIGNUM *local_bc;
  int local_b8;
  BIGNUM *local_ac [32];
  BIGNUM *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
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
         (iVar17 = BN_nnmod(pBVar6,a,m,ctx), a_00 = a, iVar17 == 0)) {
LAB_004f28c0:
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
            goto LAB_004f2940;
          }
          if (0x4f < iVar4) {
            local_bc = (BIGNUM *)0x8;
            local_b8 = 4;
            goto LAB_004f2940;
          }
          if (0x17 < iVar4) {
            local_bc = (BIGNUM *)0x4;
            local_b8 = 3;
            goto LAB_004f2940;
          }
          local_b8 = 1;
        }
        else {
          local_bc = (BIGNUM *)0x20;
          local_b8 = 6;
LAB_004f2940:
          iVar17 = BN_mod_mul(pBVar5,pBVar6,pBVar6,m,ctx);
          a_00 = pBVar6;
          if (iVar17 == 0) goto LAB_004f28c0;
          ppBVar19 = local_ac;
          iVar17 = 1;
          do {
            ppBVar19 = ppBVar19 + 1;
            pBVar6 = BN_CTX_get(ctx);
            *ppBVar19 = pBVar6;
            if (pBVar6 == (BIGNUM *)0x0) goto LAB_004f28c0;
            a_00 = ppBVar19[-1];
            iVar7 = BN_mod_mul(pBVar6,a_00,pBVar5,m,ctx);
            if (iVar7 == 0) goto LAB_004f28c0;
            iVar17 = iVar17 + 1;
          } while (iVar17 < (int)local_bc);
        }
        a_00 = (BIGNUM *)0x1;
        iVar17 = BN_set_word(r,1);
        if (iVar17 == 0) goto LAB_004f28c0;
        local_bc = (BIGNUM *)(iVar4 + -1);
        bVar2 = true;
        do {
          while (a_00 = local_bc, iVar4 = BN_is_bit_set(p,(int)local_bc), iVar4 != 0) {
            uVar10 = 1;
            if (local_b8 == 1) {
              iVar4 = 0;
            }
            else {
              n = (undefined *)((int)&local_bc[-1].flags + 3);
              iVar4 = 0;
              if (-1 < (int)n) {
                iVar17 = 1;
                do {
                  iVar7 = BN_is_bit_set(p,(int)n);
                  if (iVar7 != 0) {
                    uVar10 = uVar10 << (iVar17 - iVar4 & 0x1fU) | 1;
                    iVar4 = iVar17;
                  }
                  iVar17 = iVar17 + 1;
                } while ((iVar17 != local_b8) && (n = n + -1, n != (undefined *)0xffffffff));
              }
            }
            if (!bVar2) {
              iVar17 = 0;
              do {
                a_00 = r;
                iVar7 = BN_mod_mul(r,r,r,m,ctx);
                if (iVar7 == 0) goto LAB_004f28c0;
                iVar17 = iVar17 + 1;
              } while (iVar17 <= iVar4);
            }
            a_00 = r;
            iVar17 = BN_mod_mul(r,r,local_ac[(int)uVar10 >> 1],m,ctx);
            if (iVar17 == 0) goto LAB_004f28c0;
            local_bc = (BIGNUM *)((int)local_bc - (iVar4 + 1));
            if ((int)local_bc < 0) goto LAB_004f2a38;
            bVar2 = false;
          }
          if ((!bVar2) && (a_00 = r, iVar4 = BN_mod_mul(r,r,r,m,ctx), iVar4 == 0))
          goto LAB_004f28c0;
          bVar1 = local_bc != (BIGNUM *)0x0;
          local_bc = (BIGNUM *)((int)&local_bc[-1].flags + 3);
        } while (bVar1);
LAB_004f2a38:
        iVar4 = 1;
      }
      BN_CTX_end(ctx);
      goto LAB_004f28d4;
    }
    iVar4 = m->top;
    if (((iVar4 == 1) && (*m->d == 1)) && (m->neg == 0)) {
      a_00 = (BIGNUM *)0x0;
      BN_set_word(r,0);
      goto LAB_004f28d4;
    }
    if (local_2c == *(BIGNUM **)puVar3) {
      iVar4 = BN_set_word(r,1);
      return iVar4;
    }
  }
  else {
    a_00 = (BIGNUM *)0x7e;
    iVar4 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7e,0x42,"bn_exp.c",0x436);
LAB_004f28d4:
    pBVar5 = local_2c;
    if (local_2c == *(BIGNUM **)puVar3) {
      return iVar4;
    }
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (0xffffff < (int)a_00) {
    uVar14 = 0x72;
    uVar9 = 0x128;
LAB_004f2bb4:
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x78,uVar14,"bn_lib.c",uVar9);
    return 0;
  }
  if ((pBVar5->flags & 2U) != 0) {
    uVar14 = 0x69;
    uVar9 = 300;
    goto LAB_004f2bb4;
  }
  puVar8 = (ulong *)(*(code *)PTR_CRYPTO_malloc_006a7008)((int)a_00 << 2,"bn_lib.c",0x12f);
  if (puVar8 == (ulong *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x78,0x41,"bn_lib.c",0x131);
    return 0;
  }
  puVar18 = pBVar5->d;
  if (puVar18 == (ulong *)0x0) {
    return (int)puVar8;
  }
  uVar10 = pBVar5->top;
  iVar17 = (int)uVar10 >> 2;
  puVar11 = puVar8;
  puVar12 = puVar18;
  iVar4 = iVar17;
  if (0 < iVar17) {
    do {
      uVar16 = puVar12[1];
      uVar15 = puVar12[2];
      iVar4 = iVar4 + -1;
      uVar13 = puVar12[3];
      *puVar11 = *puVar12;
      puVar11[1] = uVar16;
      puVar11[2] = uVar15;
      puVar11[3] = uVar13;
      puVar11 = puVar11 + 4;
      puVar12 = puVar12 + 4;
    } while (iVar4 != 0);
    uVar10 = pBVar5->top;
    puVar18 = puVar18 + iVar17 * 4;
    puVar11 = puVar8 + iVar17 * 4;
  }
  uVar10 = uVar10 & 3;
  if (uVar10 != 2) {
    if (uVar10 != 3) {
      if (uVar10 != 1) {
        return (int)puVar8;
      }
      goto LAB_004f2b84;
    }
    puVar11[2] = puVar18[2];
  }
  puVar11[1] = puVar18[1];
LAB_004f2b84:
  *puVar11 = *puVar18;
  return (int)puVar8;
}

