
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  BN_MONT_CTX *pBVar1;
  undefined *puVar2;
  BIGNUM *pBVar3;
  ulong **ppuVar4;
  BIGNUM *pBVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BIGNUM *pBVar9;
  int *piVar10;
  ulong *puVar11;
  uint uVar12;
  int iVar13;
  BIGNUM *unaff_s1;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s5;
  undefined *puVar14;
  BIGNUM *pBVar15;
  code *pcVar16;
  undefined *puVar17;
  undefined *puVar18;
  BIGNUM **ppBVar19;
  BIGNUM *local_c4;
  BIGNUM *local_c0;
  BN_MONT_CTX *local_bc;
  int local_b8;
  BIGNUM *local_b4;
  BIGNUM *local_ac [3];
  undefined auStack_a0 [16];
  undefined4 uStack_90;
  undefined *puStack_88;
  BIGNUM *pBStack_80;
  int iStack_7c;
  BIGNUM *pBStack_78;
  BIGNUM *pBStack_74;
  BIGNUM *pBStack_70;
  uint uStack_6c;
  BIGNUM *pBStack_68;
  int iStack_64;
  BIGNUM *pBStack_60;
  BN_MONT_CTX *pBStack_5c;
  undefined auStack_54 [16];
  int iStack_44;
  BIGNUM BStack_40;
  BIGNUM *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  uVar12 = p->flags & 4;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  if (uVar12 != 0) {
    pBVar5 = r;
    if (local_2c != *(BIGNUM **)PTR___stack_chk_guard_006a9ae8) goto LAB_004f15f8;
    puVar14 = auStack_a0;
    puVar17 = auStack_a0;
    puVar18 = auStack_a0;
    iVar8 = m->top;
    puStack_88 = &_gp;
    local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
    if ((iVar8 < 1) || ((*m->d & 1) == 0)) {
      uStack_90 = 0x28d;
      p = (BIGNUM *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7c,0x66,"bn_exp.c");
      r = unaff_s3;
      a = unaff_s5;
      puVar17 = auStack_a0;
      goto LAB_004f089c;
    }
    pBVar5 = (BIGNUM *)BN_num_bits(p);
    if (pBVar5 == (BIGNUM *)0x0) {
      p = (BIGNUM *)m->top;
      if (((p == (BIGNUM *)0x1) && (*m->d == 1)) && (m->neg == 0)) {
        BN_set_word(r,0);
        puVar17 = auStack_a0;
        goto LAB_004f089c;
      }
      p = (BIGNUM *)BN_set_word(r,1);
      puVar17 = auStack_a0;
      goto LAB_004f089c;
    }
    pBStack_60 = pBVar5;
    BN_CTX_start(ctx);
    pBStack_5c = m_ctx;
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      pBStack_5c = BN_MONT_CTX_new();
      if (pBStack_5c == (BN_MONT_CTX *)0x0) goto LAB_004f0f90;
      iVar13 = BN_MONT_CTX_set(pBStack_5c,m,ctx);
      if (iVar13 == 0) {
        p = (BIGNUM *)0x0;
        pBStack_60 = (BIGNUM *)0x0;
        iStack_64 = 0;
        uStack_6c = 0;
        goto LAB_004f0f68;
      }
    }
    if ((int)pBStack_60 < 0x3aa) {
      if ((int)pBStack_60 < 0x133) {
        if ((int)pBStack_60 < 0x5a) {
          pBStack_68 = (BIGNUM *)&DAT_00000008;
          if ((int)pBStack_60 < 0x17) {
            pBStack_68 = (BIGNUM *)&SUB_00000002;
          }
          iStack_7c = 3;
          pBStack_70 = pBStack_68;
          if ((int)pBStack_60 < 0x17) {
            iStack_7c = 1;
          }
        }
        else {
          pBStack_70 = (BIGNUM *)0x10;
          pBStack_68 = (BIGNUM *)&SUB_00000010;
          iStack_7c = 4;
        }
      }
      else {
        pBStack_70 = (BIGNUM *)0x20;
        pBStack_68 = (BIGNUM *)&DAT_00000020;
        iStack_7c = 5;
      }
    }
    else {
      pBStack_70 = (BIGNUM *)0x40;
      pBStack_68 = (BIGNUM *)&DAT_00000040;
      iStack_7c = 6;
    }
    pBVar5 = pBStack_68;
    if ((int)pBStack_68 <= (int)(BIGNUM *)(iVar8 << 1)) {
      pBVar5 = (BIGNUM *)(iVar8 << 1);
    }
    iStack_64 = (int)((int)&pBVar5->d + iVar8 * (int)pBStack_68) * 4;
    pBStack_70 = pBStack_68;
    if (iStack_64 < 0xc00) {
      pBStack_74 = pBStack_60;
      puVar17 = auStack_a0 + -(iStack_64 + 0x48);
      uVar12 = (int)&puStack_88 + -(iStack_64 + 0x48);
      pBStack_60 = (BIGNUM *)((uVar12 - (uVar12 & 0x3f)) + 0x40);
      (**(code **)(puStack_88 + -0x53ec))(pBStack_60,0);
      uStack_6c = 0;
    }
    else {
      uStack_6c = (**(code **)(puStack_88 + -0x7dd8))(iStack_64 + 0x40,"bn_exp.c",0x2c5);
      if (uStack_6c == 0) {
        if (m_ctx == (BN_MONT_CTX *)0x0) {
          pBStack_60 = (BIGNUM *)0x0;
          p = (BIGNUM *)0x0;
          puVar14 = auStack_a0;
          goto LAB_004f0f68;
        }
LAB_004f0f90:
        p = (BIGNUM *)0x0;
        goto LAB_004f0b1c;
      }
      pBStack_74 = pBStack_60;
      pBStack_60 = (BIGNUM *)((uStack_6c - (uStack_6c & 0x3f)) + 0x40);
      (**(code **)(puStack_88 + -0x53ec))(pBStack_60,0,iStack_64);
    }
    iVar13 = iVar8 * 4 * (int)pBStack_68;
    pBStack_78 = pBStack_74;
    BStack_40.flags = 2;
    iStack_44 = 2;
    pBStack_68 = (BIGNUM *)auStack_54;
    BStack_40.dmax = iVar8;
    pBStack_74 = &pBStack_5c->RR;
    auStack_54._0_4_ = (ulong **)((int)&pBStack_60->d + iVar13);
    auStack_54._8_4_ = iVar8;
    BStack_40.top = 0;
    auStack_54._4_4_ = 0;
    BStack_40.neg = 0;
    BStack_40.d = (ulong *)(auStack_54._0_4_ + iVar8);
    auStack_54._12_4_ = 0;
    pBVar3 = BN_value_one();
    pBVar1 = pBStack_5c;
    pBVar15 = pBStack_68;
    pBVar5 = pBStack_74;
    *(BN_CTX **)(puVar17 + 0x10) = ctx;
    iVar13 = BN_mod_mul_montgomery(pBVar15,pBVar3,pBVar5,pBVar1,*(BN_CTX **)(puVar17 + 0x10));
    if (iVar13 == 0) goto LAB_004f0ae8;
    if (a->neg == 0) {
      iVar13 = BN_ucmp(a,m);
      pBVar1 = pBStack_5c;
      pBVar5 = pBStack_74;
      if (iVar13 < 0) {
        pBStack_80 = pBStack_78;
        pBStack_78 = &BStack_40;
        *(BN_CTX **)(puVar17 + 0x10) = ctx;
        iVar13 = BN_mod_mul_montgomery(&BStack_40,a,pBVar5,pBVar1,*(BN_CTX **)(puVar17 + 0x10));
        pBVar5 = pBStack_80;
        pBVar15 = pBStack_78;
        pBVar3 = pBStack_68;
        pBVar1 = pBStack_5c;
        goto joined_r0x004f0fdc;
      }
    }
    pcVar16 = *(code **)(puStack_88 + -0x6884);
    pBStack_80 = pBStack_78;
    *(BN_CTX **)(puVar17 + 0x10) = ctx;
    pBStack_78 = &BStack_40;
    iVar13 = (*pcVar16)(0,&BStack_40,a,m);
    pBVar1 = pBStack_5c;
    pBVar15 = pBStack_74;
    pBVar5 = pBStack_78;
    if (iVar13 == 0) goto LAB_004f0ae8;
    *(BN_CTX **)(puVar17 + 0x10) = ctx;
    iVar13 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar15,pBVar1,*(BN_CTX **)(puVar17 + 0x10));
    pBVar5 = pBStack_80;
    pBVar15 = pBStack_78;
    pBVar3 = pBStack_68;
    pBVar1 = pBStack_5c;
joined_r0x004f0fdc:
    pBStack_80 = pBVar5;
    pBStack_78 = pBVar15;
    pBStack_68 = pBVar3;
    pBStack_5c = pBVar1;
    if (iVar13 == 0) goto LAB_004f0ae8;
    iVar13 = auStack_54._4_4_;
    if (iVar8 <= auStack_54._4_4_) {
      iVar13 = iVar8;
    }
    if (0 < iVar13) {
      ppuVar4 = auStack_54._0_4_;
      pBVar9 = pBStack_60;
      do {
        puVar11 = *ppuVar4;
        ppuVar4 = ppuVar4 + 1;
        pBVar9->d = puVar11;
        pBVar9 = (BIGNUM *)(&pBVar9->d + (int)pBStack_70);
      } while (ppuVar4 != auStack_54._0_4_ + iVar13);
    }
    iVar13 = BStack_40.top;
    if (iVar8 <= BStack_40.top) {
      iVar13 = iVar8;
    }
    if (0 < iVar13) {
      piVar10 = &pBStack_60->top;
      ppuVar4 = (ulong **)BStack_40.d;
      do {
        puVar11 = *ppuVar4;
        ppuVar4 = ppuVar4 + 1;
        *piVar10 = (int)puVar11;
        piVar10 = piVar10 + (int)pBStack_70;
      } while (ppuVar4 != (ulong **)BStack_40.d + iVar13);
    }
    if (iStack_7c == 1) {
      pBStack_80 = (BIGNUM *)0x0;
      a = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
    }
    else {
      pBStack_74 = pBVar5;
      *(BN_CTX **)(puVar17 + 0x10) = ctx;
      iVar13 = BN_mod_mul_montgomery(pBVar3,pBVar15,pBVar15,pBVar1,*(BN_CTX **)(puVar17 + 0x10));
      pBVar15 = pBStack_70;
      pBVar5 = pBStack_74;
      if (iVar13 == 0) goto LAB_004f0ae8;
      iVar13 = auStack_54._4_4_;
      if (iVar8 <= auStack_54._4_4_) {
        iVar13 = iVar8;
      }
      if (0 < iVar13) {
        piVar10 = &pBStack_60->dmax;
        ppuVar4 = auStack_54._0_4_;
        do {
          puVar11 = *ppuVar4;
          ppuVar4 = ppuVar4 + 1;
          *piVar10 = (int)puVar11;
          piVar10 = piVar10 + (int)pBStack_70;
        } while (auStack_54._0_4_ + iVar13 != ppuVar4);
      }
      if (3 < (int)pBStack_70) {
        a = (BIGNUM *)&pBStack_60->neg;
        pBStack_74 = (BIGNUM *)(&pBStack_60->d + (int)pBStack_70);
        pBStack_70 = pBVar5;
        do {
          pBVar1 = pBStack_5c;
          pBVar3 = pBStack_68;
          pBVar5 = pBStack_78;
          *(BN_CTX **)(puVar17 + 0x10) = ctx;
          iVar13 = BN_mod_mul_montgomery(pBVar3,pBVar5,pBVar3,pBVar1,*(BN_CTX **)(puVar17 + 0x10));
          if (iVar13 == 0) goto LAB_004f0ae8;
          iVar13 = auStack_54._4_4_;
          if (iVar8 <= auStack_54._4_4_) {
            iVar13 = iVar8;
          }
          if (0 < iVar13) {
            ppuVar4 = auStack_54._0_4_;
            pBVar5 = a;
            do {
              puVar11 = *ppuVar4;
              ppuVar4 = ppuVar4 + 1;
              pBVar5->d = puVar11;
              pBVar5 = (BIGNUM *)(&pBVar5->d + (int)pBVar15);
            } while (ppuVar4 != auStack_54._0_4_ + iVar13);
          }
          a = (BIGNUM *)&a->top;
          pBVar5 = pBStack_70;
        } while (a != pBStack_74);
      }
      a = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
      if (iStack_7c == 0) {
        trap(7);
      }
      pBStack_80 = (BIGNUM *)((int)a % iStack_7c);
      if ((int)(BIGNUM *)((int)a % iStack_7c) < 0) goto LAB_004f0ff4;
    }
    puVar14 = (undefined *)0x0;
    pBStack_74 = (BIGNUM *)((int)pBStack_80 - (int)a);
    pBVar5 = a;
    do {
      pBStack_70 = (BIGNUM *)((int)puVar14 << 1);
      pBVar15 = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
      iVar13 = BN_is_bit_set(p,(int)pBVar5);
      puVar14 = (undefined *)((int)&pBStack_70->d + iVar13);
      pBVar5 = pBVar15;
    } while (-1 < (int)((int)&pBVar15->d + (int)&pBStack_74->d));
    pBVar5 = pBStack_80;
    if ((int)pBStack_80 < 0) {
      pBVar5 = (BIGNUM *)0x0;
    }
    a = (BIGNUM *)((int)a + (-1 - (int)pBVar5));
    do {
      pBVar15 = pBStack_60;
      pBVar5 = pBStack_68;
      *(int *)(puVar17 + 0x10) = iStack_7c;
      iVar13 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar5,iVar8,pBVar15,puVar14);
      if (iVar13 == 0) {
LAB_004f0ae8:
        p = (BIGNUM *)0x0;
      }
      else {
        do {
          if ((int)a < 0) {
            iVar13 = BN_from_montgomery(r,pBStack_68,pBStack_5c,ctx);
            p = (BIGNUM *)(uint)(iVar13 != 0);
            goto LAB_004f0aec;
          }
          iVar13 = 0;
          pBStack_70 = (BIGNUM *)((int)a - iStack_7c);
          do {
            pBVar1 = pBStack_5c;
            pBVar5 = pBStack_68;
            *(BN_CTX **)(puVar17 + 0x10) = ctx;
            iVar7 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,pBVar1,*(BN_CTX **)(puVar17 + 0x10));
            if (iVar7 == 0) goto LAB_004f0ae8;
            iVar7 = BN_is_bit_set(p,(int)a);
            pBVar15 = pBStack_60;
            pBVar5 = pBStack_78;
            a = (BIGNUM *)((int)&a[-1].flags + 3);
            iVar13 = iVar13 * 2 + iVar7;
          } while (a != pBStack_70);
          *(int *)(puVar17 + 0x10) = iStack_7c;
          iVar13 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar5,iVar8,pBVar15,iVar13);
          pBVar1 = pBStack_5c;
          pBVar15 = pBStack_68;
          if (iVar13 == 0) goto LAB_004f0ae8;
          *(BN_CTX **)(puVar17 + 0x10) = ctx;
          iVar13 = BN_mod_mul_montgomery(pBVar15,pBVar15,pBVar5,pBVar1,*(BN_CTX **)(puVar17 + 0x10))
          ;
        } while (iVar13 != 0);
        p = (BIGNUM *)0x0;
      }
LAB_004f0aec:
      pcVar16 = *(code **)(puStack_88 + -0x7d6c);
      puVar14 = puVar17;
      if (m_ctx == (BN_MONT_CTX *)0x0) {
LAB_004f0f68:
        BN_MONT_CTX_free(pBStack_5c);
        puVar18 = puVar14;
        if (pBStack_60 != (BIGNUM *)0x0) {
          pcVar16 = *(code **)(puStack_88 + -0x7d6c);
          goto LAB_004f0af4;
        }
      }
      else {
LAB_004f0af4:
        (*pcVar16)(pBStack_60,iStack_64);
        puVar18 = puVar14;
        if (uStack_6c != 0) {
          (**(code **)(puStack_88 + -0x7f58))(uStack_6c);
        }
      }
LAB_004f0b1c:
      BN_CTX_end(ctx);
      puVar17 = puVar18;
LAB_004f089c:
      if (local_2c == (BIGNUM *)*(int *)puVar2) {
        return (int)p;
      }
      (**(code **)(puStack_88 + -0x5330))();
LAB_004f0ff4:
      puVar14 = (undefined *)0x0;
    } while( true );
  }
  if ((m->top < 1) || ((*m->d & 1) == 0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x6d,0x66,"bn_exp.c",0x19b);
    r = unaff_s1;
    p = unaff_s3;
    goto LAB_004f10c4;
  }
  iVar8 = BN_num_bits(p);
  if (iVar8 == 0) {
    uVar12 = m->top;
    if (((uVar12 == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      goto LAB_004f10c4;
    }
    pBVar5 = local_2c;
    unaff_s1 = r;
    unaff_s3 = p;
    if (local_2c != *(BIGNUM **)puVar2) goto LAB_004f15f8;
    iVar8 = BN_set_word(r,1);
    return iVar8;
  }
  BN_CTX_start(ctx);
  local_c4 = BN_CTX_get(ctx);
  local_c0 = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  local_ac[0] = pBVar5;
  if (((local_c4 == (BIGNUM *)0x0) || (local_c0 == (BIGNUM *)0x0)) || (pBVar5 == (BIGNUM *)0x0)) {
LAB_004f13c4:
    uVar12 = 0;
    goto LAB_004f12b8;
  }
  local_bc = m_ctx;
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_bc = BN_MONT_CTX_new();
    if (local_bc == (BN_MONT_CTX *)0x0) goto LAB_004f13c4;
    iVar13 = BN_MONT_CTX_set(local_bc,m,ctx);
    if (iVar13 == 0) {
      uVar12 = 0;
      goto LAB_004f1308;
    }
  }
  if (((a->neg != 0) || (iVar13 = BN_ucmp(a,m), -1 < iVar13)) &&
     (iVar13 = BN_nnmod(pBVar5,a,m,ctx), a = pBVar5, iVar13 == 0)) goto LAB_004f13bc;
  if (a->top == 0) {
    uVar12 = 1;
    BN_set_word(r,0);
    goto LAB_004f12b0;
  }
  local_b4 = &local_bc->RR;
  iVar13 = BN_mod_mul_montgomery(pBVar5,a,local_b4,local_bc,ctx);
  if (iVar13 == 0) goto LAB_004f13bc;
  if (iVar8 < 0x2a0) {
    if (0xef < iVar8) {
      iVar13 = 0x10;
      local_b8 = 5;
      goto LAB_004f1340;
    }
    if (0x4f < iVar8) {
      iVar13 = 8;
      local_b8 = 4;
      goto LAB_004f1340;
    }
    if (0x17 < iVar8) {
      iVar13 = 4;
      local_b8 = 3;
      goto LAB_004f1340;
    }
    local_b8 = 1;
  }
  else {
    iVar13 = 0x20;
    local_b8 = 6;
LAB_004f1340:
    iVar7 = BN_mod_mul_montgomery(local_c4,pBVar5,pBVar5,local_bc,ctx);
    if (iVar7 == 0) goto LAB_004f13bc;
    ppBVar19 = local_ac;
    iVar7 = 1;
    do {
      ppBVar19 = ppBVar19 + 1;
      pBVar5 = BN_CTX_get(ctx);
      *ppBVar19 = pBVar5;
      if ((pBVar5 == (BIGNUM *)0x0) ||
         (iVar6 = BN_mod_mul_montgomery(pBVar5,ppBVar19[-1],local_c4,local_bc,ctx), iVar6 == 0))
      goto LAB_004f13bc;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar13);
  }
  pBVar5 = BN_value_one();
  iVar13 = BN_mod_mul_montgomery(local_c0,pBVar5,local_b4,local_bc,ctx);
  if (iVar13 != 0) {
    local_b4 = (BIGNUM *)0x1;
    pBVar5 = (BIGNUM *)(iVar8 + -1);
    goto LAB_004f1474;
  }
LAB_004f13bc:
  uVar12 = 0;
LAB_004f12b0:
  do {
    if (m_ctx == (BN_MONT_CTX *)0x0) {
LAB_004f1308:
      BN_MONT_CTX_free(local_bc);
    }
LAB_004f12b8:
    BN_CTX_end(ctx);
LAB_004f10c4:
    pBVar5 = local_2c;
    unaff_s1 = r;
    unaff_s3 = p;
    if (local_2c == *(BIGNUM **)puVar2) {
      return uVar12;
    }
LAB_004f15f8:
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    r = unaff_s1;
    p = unaff_s3;
    while (iVar8 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,local_bc,ctx), iVar8 != 0) {
      do {
        pBVar5 = (BIGNUM *)((int)&local_c4[-1].flags + 3);
        if (local_c4 == (BIGNUM *)0x0) {
LAB_004f15b0:
          iVar8 = BN_from_montgomery(r,local_c0,local_bc,ctx);
          uVar12 = (uint)(iVar8 != 0);
          goto LAB_004f12b0;
        }
LAB_004f1474:
        while (local_c4 = pBVar5, iVar8 = BN_is_bit_set(p,(int)local_c4), iVar8 != 0) {
          uVar12 = 1;
          if (local_b8 == 1) {
            iVar8 = 0;
          }
          else {
            puVar14 = (undefined *)((int)&local_c4[-1].flags + 3);
            iVar8 = 0;
            if (-1 < (int)puVar14) {
              iVar13 = 1;
              do {
                iVar7 = BN_is_bit_set(p,(int)puVar14);
                if (iVar7 != 0) {
                  uVar12 = uVar12 << (iVar13 - iVar8 & 0x1fU) | 1;
                  iVar8 = iVar13;
                }
                iVar13 = iVar13 + 1;
              } while ((iVar13 != local_b8) &&
                      (puVar14 = puVar14 + -1, puVar14 != (undefined *)0xffffffff));
            }
          }
          if (local_b4 == (BIGNUM *)0x0) {
            iVar13 = 0;
            do {
              iVar7 = BN_mod_mul_montgomery(local_c0,local_c0,local_c0,local_bc,ctx);
              if (iVar7 == 0) goto LAB_004f13bc;
              iVar13 = iVar13 + 1;
            } while (iVar13 <= iVar8);
          }
          iVar13 = BN_mod_mul_montgomery(local_c0,local_c0,local_ac[(int)uVar12 >> 1],local_bc,ctx);
          if (iVar13 == 0) goto LAB_004f13bc;
          local_c4 = (BIGNUM *)((int)local_c4 - (iVar8 + 1));
          if ((int)local_c4 < 0) goto LAB_004f15b0;
          local_b4 = (BIGNUM *)0x0;
          pBVar5 = local_c4;
        }
        pBVar5 = local_c0;
      } while (local_b4 != (BIGNUM *)0x0);
    }
    uVar12 = 0;
  } while( true );
}

