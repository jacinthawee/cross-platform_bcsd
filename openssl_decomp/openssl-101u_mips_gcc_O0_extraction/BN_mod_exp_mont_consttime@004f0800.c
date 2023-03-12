
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  BN_MONT_CTX *pBVar1;
  undefined *puVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  BIGNUM *pBVar5;
  ulong **ppuVar6;
  int iVar7;
  int iVar8;
  BIGNUM *pBVar9;
  int *piVar10;
  ulong *puVar11;
  undefined *puVar12;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s5;
  BIGNUM *pBVar13;
  int iVar14;
  code *pcVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined auStack_a0 [16];
  undefined4 local_90;
  undefined *local_88;
  BIGNUM *local_80;
  int local_7c;
  BIGNUM *local_78;
  BIGNUM *local_74;
  BIGNUM *local_70;
  uint local_6c;
  BIGNUM *local_68;
  int local_64;
  BIGNUM *local_60;
  BN_MONT_CTX *local_5c;
  undefined local_54 [16];
  int local_44;
  BIGNUM local_40;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar12 = auStack_a0;
  puVar16 = auStack_a0;
  puVar17 = auStack_a0;
  iVar14 = m->top;
  local_88 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((iVar14 < 1) || ((*m->d & 1) == 0)) {
    local_90 = 0x28d;
    p = (BIGNUM *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7c,0x66,"bn_exp.c");
    rr = unaff_s3;
    a = unaff_s5;
    puVar16 = auStack_a0;
    goto LAB_004f089c;
  }
  pBVar3 = (BIGNUM *)BN_num_bits(p);
  if (pBVar3 == (BIGNUM *)0x0) {
    p = (BIGNUM *)m->top;
    if (((p == (BIGNUM *)0x1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(rr,0);
      puVar16 = auStack_a0;
      goto LAB_004f089c;
    }
    p = (BIGNUM *)BN_set_word(rr,1);
    puVar16 = auStack_a0;
    goto LAB_004f089c;
  }
  local_60 = pBVar3;
  BN_CTX_start(ctx);
  local_5c = in_mont;
  if (in_mont == (BN_MONT_CTX *)0x0) {
    local_5c = BN_MONT_CTX_new();
    if (local_5c == (BN_MONT_CTX *)0x0) goto LAB_004f0f90;
    iVar7 = BN_MONT_CTX_set(local_5c,m,ctx);
    if (iVar7 == 0) {
      p = (BIGNUM *)0x0;
      local_60 = (BIGNUM *)0x0;
      local_64 = 0;
      local_6c = 0;
      goto LAB_004f0f68;
    }
  }
  if ((int)local_60 < 0x3aa) {
    if ((int)local_60 < 0x133) {
      if ((int)local_60 < 0x5a) {
        local_68 = (BIGNUM *)&DAT_00000008;
        if ((int)local_60 < 0x17) {
          local_68 = (BIGNUM *)&SUB_00000002;
        }
        local_7c = 3;
        local_70 = local_68;
        if ((int)local_60 < 0x17) {
          local_7c = 1;
        }
      }
      else {
        local_70 = (BIGNUM *)0x10;
        local_68 = (BIGNUM *)&SUB_00000010;
        local_7c = 4;
      }
    }
    else {
      local_70 = (BIGNUM *)0x20;
      local_68 = (BIGNUM *)&DAT_00000020;
      local_7c = 5;
    }
  }
  else {
    local_70 = (BIGNUM *)0x40;
    local_68 = (BIGNUM *)&DAT_00000040;
    local_7c = 6;
  }
  pBVar3 = local_68;
  if ((int)local_68 <= (int)(BIGNUM *)(iVar14 << 1)) {
    pBVar3 = (BIGNUM *)(iVar14 << 1);
  }
  local_64 = (int)((int)&pBVar3->d + iVar14 * (int)local_68) * 4;
  local_70 = local_68;
  if (local_64 < 0xc00) {
    local_74 = local_60;
    puVar16 = auStack_a0 + -(local_64 + 0x48);
    uVar4 = (int)&local_88 + -(local_64 + 0x48);
    local_60 = (BIGNUM *)((uVar4 - (uVar4 & 0x3f)) + 0x40);
    (**(code **)(local_88 + -0x53ec))(local_60,0);
    local_6c = 0;
  }
  else {
    local_6c = (**(code **)(local_88 + -0x7dd8))(local_64 + 0x40,"bn_exp.c",0x2c5);
    if (local_6c == 0) {
      if (in_mont == (BN_MONT_CTX *)0x0) {
        local_60 = (BIGNUM *)0x0;
        p = (BIGNUM *)0x0;
        puVar12 = auStack_a0;
        goto LAB_004f0f68;
      }
LAB_004f0f90:
      p = (BIGNUM *)0x0;
      goto LAB_004f0b1c;
    }
    local_74 = local_60;
    local_60 = (BIGNUM *)((local_6c - (local_6c & 0x3f)) + 0x40);
    (**(code **)(local_88 + -0x53ec))(local_60,0,local_64);
  }
  iVar7 = iVar14 * 4 * (int)local_68;
  local_78 = local_74;
  local_40.flags = 2;
  local_44 = 2;
  local_68 = (BIGNUM *)local_54;
  local_40.dmax = iVar14;
  local_74 = &local_5c->RR;
  local_54._0_4_ = (ulong **)((int)&local_60->d + iVar7);
  local_54._8_4_ = iVar14;
  local_40.top = 0;
  local_54._4_4_ = 0;
  local_40.neg = 0;
  local_40.d = (ulong *)(local_54._0_4_ + iVar14);
  local_54._12_4_ = 0;
  pBVar5 = BN_value_one();
  pBVar1 = local_5c;
  pBVar13 = local_68;
  pBVar3 = local_74;
  *(BN_CTX **)(puVar16 + 0x10) = ctx;
  iVar7 = BN_mod_mul_montgomery(pBVar13,pBVar5,pBVar3,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
  if (iVar7 == 0) goto LAB_004f0ae8;
  if (a->neg == 0) {
    iVar7 = BN_ucmp(a,m);
    pBVar1 = local_5c;
    pBVar3 = local_74;
    if (iVar7 < 0) {
      local_80 = local_78;
      local_78 = &local_40;
      *(BN_CTX **)(puVar16 + 0x10) = ctx;
      iVar7 = BN_mod_mul_montgomery(&local_40,a,pBVar3,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
      pBVar3 = local_80;
      pBVar13 = local_78;
      pBVar5 = local_68;
      pBVar1 = local_5c;
      goto joined_r0x004f0fdc;
    }
  }
  pcVar15 = *(code **)(local_88 + -0x6884);
  local_80 = local_78;
  *(BN_CTX **)(puVar16 + 0x10) = ctx;
  local_78 = &local_40;
  iVar7 = (*pcVar15)(0,&local_40,a,m);
  pBVar1 = local_5c;
  pBVar13 = local_74;
  pBVar3 = local_78;
  if (iVar7 == 0) goto LAB_004f0ae8;
  *(BN_CTX **)(puVar16 + 0x10) = ctx;
  iVar7 = BN_mod_mul_montgomery(pBVar3,pBVar3,pBVar13,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
  pBVar3 = local_80;
  pBVar13 = local_78;
  pBVar5 = local_68;
  pBVar1 = local_5c;
joined_r0x004f0fdc:
  local_80 = pBVar3;
  local_78 = pBVar13;
  local_68 = pBVar5;
  local_5c = pBVar1;
  if (iVar7 == 0) goto LAB_004f0ae8;
  iVar7 = local_54._4_4_;
  if (iVar14 <= local_54._4_4_) {
    iVar7 = iVar14;
  }
  if (0 < iVar7) {
    ppuVar6 = local_54._0_4_;
    pBVar9 = local_60;
    do {
      puVar11 = *ppuVar6;
      ppuVar6 = ppuVar6 + 1;
      pBVar9->d = puVar11;
      pBVar9 = (BIGNUM *)(&pBVar9->d + (int)local_70);
    } while (ppuVar6 != local_54._0_4_ + iVar7);
  }
  iVar7 = local_40.top;
  if (iVar14 <= local_40.top) {
    iVar7 = iVar14;
  }
  if (0 < iVar7) {
    piVar10 = &local_60->top;
    ppuVar6 = (ulong **)local_40.d;
    do {
      puVar11 = *ppuVar6;
      ppuVar6 = ppuVar6 + 1;
      *piVar10 = (int)puVar11;
      piVar10 = piVar10 + (int)local_70;
    } while (ppuVar6 != (ulong **)local_40.d + iVar7);
  }
  if (local_7c == 1) {
    local_80 = (BIGNUM *)0x0;
    a = (BIGNUM *)((int)&pBVar3[-1].flags + 3);
  }
  else {
    local_74 = pBVar3;
    *(BN_CTX **)(puVar16 + 0x10) = ctx;
    iVar7 = BN_mod_mul_montgomery(pBVar5,pBVar13,pBVar13,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
    pBVar13 = local_70;
    pBVar3 = local_74;
    if (iVar7 == 0) goto LAB_004f0ae8;
    iVar7 = local_54._4_4_;
    if (iVar14 <= local_54._4_4_) {
      iVar7 = iVar14;
    }
    if (0 < iVar7) {
      piVar10 = &local_60->dmax;
      ppuVar6 = local_54._0_4_;
      do {
        puVar11 = *ppuVar6;
        ppuVar6 = ppuVar6 + 1;
        *piVar10 = (int)puVar11;
        piVar10 = piVar10 + (int)local_70;
      } while (local_54._0_4_ + iVar7 != ppuVar6);
    }
    if (3 < (int)local_70) {
      a = (BIGNUM *)&local_60->neg;
      local_74 = (BIGNUM *)(&local_60->d + (int)local_70);
      local_70 = pBVar3;
      do {
        pBVar1 = local_5c;
        pBVar5 = local_68;
        pBVar3 = local_78;
        *(BN_CTX **)(puVar16 + 0x10) = ctx;
        iVar7 = BN_mod_mul_montgomery(pBVar5,pBVar3,pBVar5,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
        if (iVar7 == 0) goto LAB_004f0ae8;
        iVar7 = local_54._4_4_;
        if (iVar14 <= local_54._4_4_) {
          iVar7 = iVar14;
        }
        if (0 < iVar7) {
          ppuVar6 = local_54._0_4_;
          pBVar3 = a;
          do {
            puVar11 = *ppuVar6;
            ppuVar6 = ppuVar6 + 1;
            pBVar3->d = puVar11;
            pBVar3 = (BIGNUM *)(&pBVar3->d + (int)pBVar13);
          } while (ppuVar6 != local_54._0_4_ + iVar7);
        }
        a = (BIGNUM *)&a->top;
        pBVar3 = local_70;
      } while (a != local_74);
    }
    a = (BIGNUM *)((int)&pBVar3[-1].flags + 3);
    if (local_7c == 0) {
      trap(7);
    }
    local_80 = (BIGNUM *)((int)a % local_7c);
    if ((int)(BIGNUM *)((int)a % local_7c) < 0) goto LAB_004f0ff4;
  }
  puVar12 = (undefined *)0x0;
  local_74 = (BIGNUM *)((int)local_80 - (int)a);
  pBVar3 = a;
  do {
    local_70 = (BIGNUM *)((int)puVar12 << 1);
    pBVar13 = (BIGNUM *)((int)&pBVar3[-1].flags + 3);
    iVar7 = BN_is_bit_set(p,(int)pBVar3);
    puVar12 = (undefined *)((int)&local_70->d + iVar7);
    pBVar3 = pBVar13;
  } while (-1 < (int)((int)&pBVar13->d + (int)&local_74->d));
  pBVar3 = local_80;
  if ((int)local_80 < 0) {
    pBVar3 = (BIGNUM *)0x0;
  }
  a = (BIGNUM *)((int)a + (-1 - (int)pBVar3));
  do {
    pBVar13 = local_60;
    pBVar3 = local_68;
    *(int *)(puVar16 + 0x10) = local_7c;
    iVar7 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar3,iVar14,pBVar13,puVar12);
    if (iVar7 == 0) {
LAB_004f0ae8:
      p = (BIGNUM *)0x0;
    }
    else {
      do {
        if ((int)a < 0) {
          iVar7 = BN_from_montgomery(rr,local_68,local_5c,ctx);
          p = (BIGNUM *)(uint)(iVar7 != 0);
          goto LAB_004f0aec;
        }
        iVar7 = 0;
        local_70 = (BIGNUM *)((int)a - local_7c);
        do {
          pBVar1 = local_5c;
          pBVar3 = local_68;
          *(BN_CTX **)(puVar16 + 0x10) = ctx;
          iVar8 = BN_mod_mul_montgomery(pBVar3,pBVar3,pBVar3,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
          if (iVar8 == 0) goto LAB_004f0ae8;
          iVar8 = BN_is_bit_set(p,(int)a);
          pBVar13 = local_60;
          pBVar3 = local_78;
          a = (BIGNUM *)((int)&a[-1].flags + 3);
          iVar7 = iVar7 * 2 + iVar8;
        } while (a != local_70);
        *(int *)(puVar16 + 0x10) = local_7c;
        iVar7 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar3,iVar14,pBVar13,iVar7);
        pBVar1 = local_5c;
        pBVar13 = local_68;
        if (iVar7 == 0) goto LAB_004f0ae8;
        *(BN_CTX **)(puVar16 + 0x10) = ctx;
        iVar7 = BN_mod_mul_montgomery(pBVar13,pBVar13,pBVar3,pBVar1,*(BN_CTX **)(puVar16 + 0x10));
      } while (iVar7 != 0);
      p = (BIGNUM *)0x0;
    }
LAB_004f0aec:
    pcVar15 = *(code **)(local_88 + -0x7d6c);
    puVar12 = puVar16;
    if (in_mont == (BN_MONT_CTX *)0x0) {
LAB_004f0f68:
      BN_MONT_CTX_free(local_5c);
      puVar17 = puVar12;
      if (local_60 != (BIGNUM *)0x0) {
        pcVar15 = *(code **)(local_88 + -0x7d6c);
        goto LAB_004f0af4;
      }
    }
    else {
LAB_004f0af4:
      (*pcVar15)(local_60,local_64);
      puVar17 = puVar12;
      if (local_6c != 0) {
        (**(code **)(local_88 + -0x7f58))(local_6c);
      }
    }
LAB_004f0b1c:
    BN_CTX_end(ctx);
    puVar16 = puVar17;
LAB_004f089c:
    if (local_2c == *(int *)puVar2) {
      return (int)p;
    }
    (**(code **)(local_88 + -0x5330))();
LAB_004f0ff4:
    puVar12 = (undefined *)0x0;
  } while( true );
}

