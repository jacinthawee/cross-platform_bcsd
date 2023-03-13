
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  undefined4 uVar1;
  ulong uVar2;
  BIGNUM *pBVar3;
  int iVar4;
  ulong *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  ulong *puVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined *puVar14;
  undefined *puVar15;
  int in_GS_OFFSET;
  undefined auStack_8c [12];
  undefined4 local_80;
  int local_7c;
  BIGNUM *local_78;
  void *local_74;
  BIGNUM *local_70;
  size_t local_6c;
  undefined4 *local_68;
  BN_MONT_CTX *local_64;
  BIGNUM *local_60;
  BIGNUM *local_5c;
  BN_MONT_CTX *local_58;
  BIGNUM *local_54;
  BN_CTX *local_50;
  undefined4 *local_48;
  BIGNUM *local_44;
  BIGNUM *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  BIGNUM local_34;
  int local_20;
  
  local_54 = rr;
  pBVar9 = (BIGNUM *)m->top;
  local_5c = a;
  local_50 = ctx;
  local_58 = in_mont;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((int)pBVar9 < 1) || ((*(byte *)m->d & 1) == 0)) {
    uVar13 = 0;
    ERR_put_error(3,0x7c,0x66,"bn_exp.c",0x28d);
    puVar15 = auStack_8c;
    goto LAB_080f238d;
  }
  local_60 = (BIGNUM *)BN_num_bits(p);
  if (local_60 == (BIGNUM *)0x0) {
    uVar13 = m->top;
    if (((uVar13 == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(local_54,0);
      puVar15 = auStack_8c;
    }
    else {
      uVar13 = BN_set_word(local_54,1);
      puVar15 = auStack_8c;
    }
    goto LAB_080f238d;
  }
  BN_CTX_start(local_50);
  puVar14 = auStack_8c;
  puVar15 = auStack_8c;
  local_64 = local_58;
  if (local_58 == (BN_MONT_CTX *)0x0) {
    local_64 = BN_MONT_CTX_new();
    if (local_64 == (BN_MONT_CTX *)0x0) {
LAB_080f2949:
      uVar13 = 0;
      puVar15 = auStack_8c;
    }
    else {
      iVar4 = BN_MONT_CTX_set(local_64,m,local_50);
      if (iVar4 != 0) goto LAB_080f2414;
LAB_080f2976:
      uVar13 = 0;
      BN_MONT_CTX_free(local_64);
    }
  }
  else {
LAB_080f2414:
    if ((int)local_60 < 0x3aa) {
      if ((int)local_60 < 0x133) {
        if ((int)local_60 < 0x5a) {
          local_70 = (BIGNUM *)&DAT_00000008;
          local_78 = (BIGNUM *)&DAT_00000008;
          if ((int)local_60 < 0x17) {
            local_70 = (BIGNUM *)0x2;
          }
          if ((int)local_60 < 0x17) {
            local_78 = (BIGNUM *)0x2;
          }
          local_7c = (uint)(0x16 < (int)local_60) * 2 + 1;
        }
        else {
          local_78 = (BIGNUM *)&DAT_00000010;
          local_70 = (BIGNUM *)&DAT_00000010;
          local_7c = 4;
        }
      }
      else {
        local_78 = (BIGNUM *)&DAT_00000020;
        local_70 = (BIGNUM *)&DAT_00000020;
        local_7c = 5;
      }
    }
    else {
      local_78 = (BIGNUM *)0x40;
      local_70 = (BIGNUM *)0x40;
      local_7c = 6;
    }
    pBVar3 = (BIGNUM *)((int)pBVar9 * 2);
    if ((int)(BIGNUM *)((int)pBVar9 * 2) < (int)local_70) {
      pBVar3 = local_70;
    }
    local_6c = (int)((int)&pBVar3->d + (int)local_70 * (int)pBVar9) * 4;
    if ((int)local_6c < 0xc00) {
      iVar4 = -(local_6c + 0x5e & 0xfffffff0);
      puVar14 = auStack_8c + iVar4;
      *(size_t *)(&stack0xffffff6c + iVar4) = local_6c;
      *(undefined4 *)(&stack0xffffff68 + iVar4) = 0;
      local_68 = (undefined4 *)(((int)&local_80 + iVar4 + 3 & 0xffffffc0U) + 0x40);
      *(undefined4 **)(&stack0xffffff64 + iVar4) = local_68;
      *(undefined4 *)(&stack0xffffff60 + iVar4) = 0x80f247d;
      memset(*(void **)(&stack0xffffff64 + iVar4),*(int *)(&stack0xffffff68 + iVar4),
             *(size_t *)(&stack0xffffff6c + iVar4));
      local_74 = (void *)0x0;
    }
    else {
      local_74 = CRYPTO_malloc(local_6c + 0x40,"bn_exp.c",0x2c5);
      if (local_74 == (void *)0x0) {
        if (local_58 == (BN_MONT_CTX *)0x0) goto LAB_080f2976;
        goto LAB_080f2949;
      }
      local_68 = (undefined4 *)(((uint)local_74 & 0xffffffc0) + 0x40);
      memset(local_68,0,local_6c);
    }
    local_34.top = 0;
    local_44 = (BIGNUM *)0x0;
    local_34.dmax = (int)pBVar9;
    local_40 = pBVar9;
    local_34.neg = 0;
    local_48 = (undefined4 *)((int)local_78 * (int)pBVar9 * 4 + (int)local_68);
    local_3c = 0;
    local_34.flags = 2;
    local_38 = 2;
    local_34.d = local_48 + (int)pBVar9;
    local_78 = &local_64->RR;
    *(undefined4 *)(puVar14 + -4) = 0x80f24dd;
    pBVar3 = BN_value_one();
    *(BN_CTX **)(puVar14 + -0x10) = local_50;
    *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
    *(BIGNUM **)(puVar14 + -0x18) = local_78;
    *(BIGNUM **)(puVar14 + -0x1c) = pBVar3;
    *(undefined4 ***)(puVar14 + -0x20) = &local_48;
    *(undefined4 *)(puVar14 + -0x24) = 0x80f24f3;
    iVar4 = BN_mod_mul_montgomery
                      (*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                       *(BIGNUM **)(puVar14 + -0x18),*(BN_MONT_CTX **)(puVar14 + -0x14),
                       *(BN_CTX **)(puVar14 + -0x10));
    if (iVar4 == 0) {
LAB_080f253e:
      uVar13 = 0;
    }
    else {
      if (local_5c->neg == 0) {
        *(BIGNUM **)(puVar14 + -0xc) = m;
        *(BIGNUM **)(puVar14 + -0x10) = local_5c;
        *(undefined4 *)(puVar14 + -0x14) = 0x80f2510;
        iVar4 = BN_ucmp(*(BIGNUM **)(puVar14 + -0x10),*(BIGNUM **)(puVar14 + -0xc));
        if (-1 < iVar4) goto LAB_080f251b;
        pBVar3 = &local_34;
        *(BN_CTX **)(puVar14 + -0x10) = local_50;
        *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
        *(BIGNUM **)(puVar14 + -0x18) = local_78;
        *(BIGNUM **)(puVar14 + -0x1c) = local_5c;
        local_5c = pBVar3;
      }
      else {
LAB_080f251b:
        *(BN_CTX **)(puVar14 + -0x10) = local_50;
        *(BIGNUM **)(puVar14 + -0x14) = m;
        *(BIGNUM **)(puVar14 + -0x18) = local_5c;
        *(BIGNUM **)(puVar14 + -0x1c) = &local_34;
        *(undefined4 *)(puVar14 + -0x20) = 0;
        local_5c = &local_34;
        *(undefined4 *)(puVar14 + -0x24) = 0x80f2533;
        iVar4 = BN_div(*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                       *(BIGNUM **)(puVar14 + -0x18),*(BIGNUM **)(puVar14 + -0x14),
                       *(BN_CTX **)(puVar14 + -0x10));
        pBVar3 = local_5c;
        if (iVar4 == 0) goto LAB_080f253e;
        *(BN_CTX **)(puVar14 + -0x10) = local_50;
        *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
        *(BIGNUM **)(puVar14 + -0x18) = local_78;
        *(BIGNUM **)(puVar14 + -0x1c) = pBVar3;
      }
      *(BIGNUM **)(puVar14 + -0x20) = pBVar3;
      *(undefined4 *)(puVar14 + -0x24) = 0x80f25fe;
      iVar4 = BN_mod_mul_montgomery
                        (*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                         *(BIGNUM **)(puVar14 + -0x18),*(BN_MONT_CTX **)(puVar14 + -0x14),
                         *(BN_CTX **)(puVar14 + -0x10));
      pBVar3 = local_5c;
      if (iVar4 == 0) goto LAB_080f253e;
      pBVar10 = local_44;
      if ((int)pBVar9 <= (int)local_44) {
        pBVar10 = pBVar9;
      }
      if (0 < (int)pBVar10) {
        local_78 = pBVar9;
        puVar6 = local_48;
        puVar7 = local_68;
        do {
          uVar1 = *puVar6;
          puVar6 = puVar6 + 1;
          *puVar7 = uVar1;
          puVar7 = puVar7 + (int)local_70;
        } while (puVar6 != local_48 + (int)pBVar10);
      }
      pBVar10 = (BIGNUM *)local_34.top;
      if ((int)pBVar9 <= local_34.top) {
        pBVar10 = pBVar9;
      }
      if (0 < (int)pBVar10) {
        local_78 = pBVar9;
        puVar11 = local_68 + 1;
        puVar5 = local_34.d;
        do {
          uVar2 = *puVar5;
          puVar5 = puVar5 + 1;
          *puVar11 = uVar2;
          puVar11 = puVar11 + (int)local_70;
        } while (puVar5 != local_34.d + (int)pBVar10);
      }
      if (local_7c == 1) {
        local_78 = (BIGNUM *)0x0;
        local_70 = (BIGNUM *)((int)&local_60[-1].flags + 3);
LAB_080f2773:
        local_80 = pBVar9;
        iVar4 = 0;
        local_60 = (BIGNUM *)((int)local_78 - (int)local_70);
        pBVar9 = local_70;
        do {
          *(BIGNUM **)(puVar14 + -0xc) = pBVar9;
          *(BIGNUM **)(puVar14 + -0x10) = p;
          pBVar9 = (BIGNUM *)((int)&pBVar9[-1].flags + 3);
          *(undefined4 *)(puVar14 + -0x14) = 0x80f2797;
          iVar8 = BN_is_bit_set(*(BIGNUM **)(puVar14 + -0x10),*(int *)(puVar14 + -0xc));
          iVar4 = iVar4 * 2 + iVar8;
        } while (-1 < (int)((int)&pBVar9->d + (int)&local_60->d));
        pBVar9 = (BIGNUM *)0x0;
        if (-1 < (int)local_78) {
          pBVar9 = local_78;
        }
        local_70 = (BIGNUM *)((int)local_70 + (-1 - (int)pBVar9));
        pBVar9 = local_80;
      }
      else {
        *(BN_CTX **)(puVar14 + -0x10) = local_50;
        *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
        *(BIGNUM **)(puVar14 + -0x18) = pBVar3;
        *(BIGNUM **)(puVar14 + -0x1c) = pBVar3;
        *(undefined4 ***)(puVar14 + -0x20) = &local_48;
        *(undefined4 *)(puVar14 + -0x24) = 0x80f2699;
        iVar4 = BN_mod_mul_montgomery
                          (*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                           *(BIGNUM **)(puVar14 + -0x18),*(BN_MONT_CTX **)(puVar14 + -0x14),
                           *(BN_CTX **)(puVar14 + -0x10));
        pBVar3 = local_70;
        if (iVar4 == 0) goto LAB_080f253e;
        pBVar10 = local_44;
        if ((int)pBVar9 <= (int)local_44) {
          pBVar10 = pBVar9;
        }
        if (0 < (int)pBVar10) {
          puVar7 = local_68 + 2;
          puVar6 = local_48;
          do {
            uVar1 = *puVar6;
            puVar6 = puVar6 + 1;
            *puVar7 = uVar1;
            puVar7 = puVar7 + (int)local_70;
          } while (local_48 + (int)pBVar10 != puVar6);
        }
        puVar6 = local_68 + 3;
        local_78 = (BIGNUM *)(local_68 + (int)local_70);
        if (3 < (int)local_70) {
          local_80 = p;
          do {
            *(BN_CTX **)(puVar14 + -0x10) = local_50;
            *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
            *(undefined4 ***)(puVar14 + -0x18) = &local_48;
            *(BIGNUM **)(puVar14 + -0x1c) = local_5c;
            *(undefined4 ***)(puVar14 + -0x20) = &local_48;
            *(undefined4 *)(puVar14 + -0x24) = 0x80f271e;
            iVar4 = BN_mod_mul_montgomery
                              (*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                               *(BIGNUM **)(puVar14 + -0x18),*(BN_MONT_CTX **)(puVar14 + -0x14),
                               *(BN_CTX **)(puVar14 + -0x10));
            if (iVar4 == 0) goto LAB_080f253e;
            pBVar10 = local_44;
            if ((int)pBVar9 <= (int)local_44) {
              pBVar10 = pBVar9;
            }
            if (0 < (int)pBVar10) {
              local_70 = pBVar9;
              puVar7 = local_48;
              puVar12 = puVar6;
              do {
                uVar1 = *puVar7;
                puVar7 = puVar7 + 1;
                *puVar12 = uVar1;
                puVar12 = puVar12 + (int)pBVar3;
              } while (puVar7 != local_48 + (int)pBVar10);
            }
            puVar6 = puVar6 + 1;
            p = local_80;
          } while ((BIGNUM *)puVar6 != local_78);
        }
        iVar4 = 0;
        local_70 = (BIGNUM *)((int)&local_60[-1].flags + 3);
        local_78 = (BIGNUM *)((int)local_70 % local_7c);
        if (-1 < (int)local_78) goto LAB_080f2773;
      }
      *(int *)(puVar14 + -0xc) = local_7c;
      *(int *)(puVar14 + -0x10) = iVar4;
      *(undefined4 *)(puVar14 + -0x14) = 0x80f27d4;
      iVar4 = MOD_EXP_CTIME_COPY_FROM_PREBUF();
      if (iVar4 == 0) goto LAB_080f253e;
      if (-1 < (int)local_70) {
        local_78 = pBVar9;
        pBVar9 = local_70;
        do {
          iVar4 = 0;
          local_60 = (BIGNUM *)((int)pBVar9 - local_7c);
          do {
            *(BN_CTX **)(puVar14 + -0x10) = local_50;
            *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
            *(undefined4 ***)(puVar14 + -0x18) = &local_48;
            *(undefined4 ***)(puVar14 + -0x1c) = &local_48;
            *(undefined4 ***)(puVar14 + -0x20) = &local_48;
            *(undefined4 *)(puVar14 + -0x24) = 0x80f2814;
            iVar8 = BN_mod_mul_montgomery
                              (*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                               *(BIGNUM **)(puVar14 + -0x18),*(BN_MONT_CTX **)(puVar14 + -0x14),
                               *(BN_CTX **)(puVar14 + -0x10));
            if (iVar8 == 0) goto LAB_080f253e;
            *(BIGNUM **)(puVar14 + -0xc) = pBVar9;
            *(BIGNUM **)(puVar14 + -0x10) = p;
            pBVar9 = (BIGNUM *)((int)&pBVar9[-1].flags + 3);
            *(undefined4 *)(puVar14 + -0x14) = 0x80f282e;
            iVar8 = BN_is_bit_set(*(BIGNUM **)(puVar14 + -0x10),*(int *)(puVar14 + -0xc));
            iVar4 = iVar4 * 2 + iVar8;
          } while (pBVar9 != local_60);
          *(int *)(puVar14 + -0xc) = local_7c;
          *(int *)(puVar14 + -0x10) = iVar4;
          pBVar3 = local_5c;
          *(undefined4 *)(puVar14 + -0x14) = 0x80f284f;
          iVar4 = MOD_EXP_CTIME_COPY_FROM_PREBUF();
          if (iVar4 == 0) goto LAB_080f253e;
          *(BN_CTX **)(puVar14 + -0x10) = local_50;
          *(BN_MONT_CTX **)(puVar14 + -0x14) = local_64;
          *(BIGNUM **)(puVar14 + -0x18) = pBVar3;
          *(undefined4 ***)(puVar14 + -0x1c) = &local_48;
          *(undefined4 ***)(puVar14 + -0x20) = &local_48;
          *(undefined4 *)(puVar14 + -0x24) = 0x80f286e;
          iVar4 = BN_mod_mul_montgomery
                            (*(BIGNUM **)(puVar14 + -0x20),*(BIGNUM **)(puVar14 + -0x1c),
                             *(BIGNUM **)(puVar14 + -0x18),*(BN_MONT_CTX **)(puVar14 + -0x14),
                             *(BN_CTX **)(puVar14 + -0x10));
          if (iVar4 == 0) goto LAB_080f253e;
        } while (-1 < (int)pBVar9);
      }
      *(BN_CTX **)(puVar14 + -4) = local_50;
      *(BN_MONT_CTX **)(puVar14 + -8) = local_64;
      *(undefined4 ***)(puVar14 + -0xc) = &local_48;
      *(BIGNUM **)(puVar14 + -0x10) = local_54;
      *(undefined4 *)(puVar14 + -0x14) = 0x80f2895;
      iVar4 = BN_from_montgomery(*(BIGNUM **)(puVar14 + -0x10),*(BIGNUM **)(puVar14 + -0xc),
                                 *(BN_MONT_CTX **)(puVar14 + -8),*(BN_CTX **)(puVar14 + -4));
      uVar13 = (uint)(iVar4 != 0);
    }
    if (local_58 == (BN_MONT_CTX *)0x0) {
      *(BN_MONT_CTX **)(puVar14 + -0x10) = local_64;
      *(undefined4 *)(puVar14 + -0x14) = 0x80f28fb;
      BN_MONT_CTX_free(*(BN_MONT_CTX **)(puVar14 + -0x10));
    }
    *(size_t *)(puVar14 + -0xc) = local_6c;
    *(undefined4 **)(puVar14 + -0x10) = local_68;
    *(undefined4 *)(puVar14 + -0x14) = 0x80f2559;
    OPENSSL_cleanse(*(void **)(puVar14 + -0x10),*(size_t *)(puVar14 + -0xc));
    puVar15 = puVar14;
    if (local_74 != (void *)0x0) {
      *(void **)(puVar14 + -0x10) = local_74;
      *(undefined4 *)(puVar14 + -0x14) = 0x80f256c;
      CRYPTO_free(*(void **)(puVar14 + -0x10));
    }
  }
  *(BN_CTX **)(puVar15 + -0x10) = local_50;
  *(undefined4 *)(puVar15 + -0x14) = 0x80f257a;
  BN_CTX_end(*(BN_CTX **)(puVar15 + -0x10));
LAB_080f238d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)(puVar15 + -4) = &UNK_080f29c2;
    __stack_chk_fail();
  }
  return uVar13;
}

