
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  undefined *puVar1;
  undefined uVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  BIGNUM *pBVar7;
  undefined *puVar8;
  BIGNUM *pBVar9;
  uint uVar10;
  BIGNUM **ppBVar11;
  BIGNUM **ppBVar12;
  int in_GS_OFFSET;
  BIGNUM *local_8c;
  BIGNUM *local_88;
  BIGNUM *local_84;
  undefined4 local_80;
  BIGNUM *local_7c;
  BIGNUM *local_78;
  int local_74;
  void *local_70;
  size_t local_6c;
  BIGNUM *local_68;
  undefined *local_64;
  BIGNUM *local_60;
  BIGNUM *local_5c;
  BN_MONT_CTX *local_58;
  BN_MONT_CTX *local_54;
  BIGNUM *local_50;
  undefined *local_48;
  BIGNUM *local_44;
  BIGNUM *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  BIGNUM local_34;
  int local_20;
  
  local_60 = rr;
  local_5c = a;
  local_50 = p;
  local_54 = in_mont;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)m->d & 1) == 0) {
    ERR_put_error(3,0x7c,0x66,"bn_exp.c",599);
    ppBVar11 = &local_8c;
    uVar10 = 0;
    goto LAB_080f4720;
  }
  pBVar7 = (BIGNUM *)m->top;
  local_68 = (BIGNUM *)BN_num_bits(p);
  if (local_68 == (BIGNUM *)0x0) {
    uVar10 = BN_set_word(local_60,1);
    ppBVar11 = &local_8c;
    goto LAB_080f4720;
  }
  BN_CTX_start(ctx);
  ppBVar11 = &local_8c;
  ppBVar12 = &local_8c;
  local_58 = local_54;
  if (local_54 == (BN_MONT_CTX *)0x0) {
    local_58 = BN_MONT_CTX_new();
    if (local_58 != (BN_MONT_CTX *)0x0) {
      iVar4 = BN_MONT_CTX_set(local_58,m,ctx);
      if (iVar4 != 0) goto LAB_080f45a3;
      local_64 = (undefined *)0x0;
      local_6c = 0;
      uVar10 = 0;
      local_70 = (void *)0x0;
      goto LAB_080f4830;
    }
LAB_080f4c2b:
    uVar10 = 0;
  }
  else {
LAB_080f45a3:
    if ((int)local_68 < 0x3aa) {
      if ((int)local_68 < 0x133) {
        if ((int)local_68 < 0x5a) {
          local_78 = (BIGNUM *)&DAT_00000008;
          local_74 = 8;
          if ((int)local_68 < 0x17) {
            local_78 = (BIGNUM *)0x2;
          }
          if ((int)local_68 < 0x17) {
            local_74 = 2;
          }
          local_80 = (uint)(0x16 < (int)local_68) * 2 + 1;
        }
        else {
          local_74 = 0x10;
          local_78 = (BIGNUM *)&DAT_00000010;
          local_80 = 4;
        }
      }
      else {
        local_74 = 0x20;
        local_78 = (BIGNUM *)&DAT_00000020;
        local_80 = 5;
      }
    }
    else {
      local_74 = 0x40;
      local_78 = (BIGNUM *)0x40;
      local_80 = 6;
    }
    pBVar3 = (BIGNUM *)((int)pBVar7 * 2);
    if ((int)(BIGNUM *)((int)pBVar7 * 2) < (int)local_78) {
      pBVar3 = local_78;
    }
    local_6c = (int)((int)&pBVar3->d + (int)local_78 * (int)pBVar7) * 4;
    if ((int)local_6c < 0xc00) {
      iVar4 = -(local_6c + 0x5e & 0xfffffff0);
      *(size_t *)(&stack0xffffff6c + iVar4) = local_6c;
      *(undefined4 *)(&stack0xffffff68 + iVar4) = 0;
      local_64 = (undefined *)(((int)&local_80 + iVar4 + 3 & 0xffffffc0U) + 0x40);
      *(undefined **)(&stack0xffffff64 + iVar4) = local_64;
      *(undefined4 *)(&stack0xffffff60 + iVar4) = 0x80f460a;
      memset(*(void **)(&stack0xffffff64 + iVar4),*(int *)(&stack0xffffff68 + iVar4),
             *(size_t *)(&stack0xffffff6c + iVar4));
      local_70 = (void *)0x0;
      ppBVar12 = (BIGNUM **)((int)&local_8c + iVar4);
    }
    else {
      local_70 = CRYPTO_malloc(local_6c + 0x40,"bn_exp.c",0x27f);
      if (local_70 == (void *)0x0) {
        if (local_54 != (BN_MONT_CTX *)0x0) goto LAB_080f4c2b;
        local_64 = (undefined *)0x0;
        uVar10 = 0;
        ppBVar12 = &local_8c;
        goto LAB_080f4830;
      }
      local_64 = (undefined *)(((uint)local_70 & 0xffffffc0) + 0x40);
      memset(local_64,0,local_6c);
      ppBVar12 = &local_8c;
    }
    local_84 = (BIGNUM *)((int)pBVar7 * 4);
    local_34.top = 0;
    local_44 = (BIGNUM *)0x0;
    local_34.dmax = (int)pBVar7;
    local_40 = pBVar7;
    local_34.neg = 0;
    local_3c = 0;
    local_34.flags = 2;
    local_38 = 2;
    local_48 = local_64 + (int)local_84 * local_74;
    local_34.d = (ulong *)(local_64 + (int)local_84 * local_74 + (int)local_84);
    local_7c = &local_58->RR;
    *(undefined4 *)((int)ppBVar12 + -4) = 0x80f466d;
    pBVar3 = BN_value_one();
    *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
    *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
    *(BIGNUM **)((int)ppBVar12 + -0x18) = local_7c;
    *(BIGNUM **)((int)ppBVar12 + -0x1c) = pBVar3;
    *(undefined ***)((int)ppBVar12 + -0x20) = &local_48;
    *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f4681;
    iVar4 = BN_mod_mul_montgomery
                      (*(BIGNUM **)((int)ppBVar12 + -0x20),*(BIGNUM **)((int)ppBVar12 + -0x1c),
                       *(BIGNUM **)((int)ppBVar12 + -0x18),*(BN_MONT_CTX **)((int)ppBVar12 + -0x14),
                       *(BN_CTX **)((int)ppBVar12 + -0x10));
    if (iVar4 == 0) {
LAB_080f46ca:
      uVar10 = 0;
    }
    else {
      if (local_5c->neg == 0) {
        *(BIGNUM **)((int)ppBVar12 + -0xc) = m;
        *(BIGNUM **)((int)ppBVar12 + -0x10) = local_5c;
        *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f469e;
        iVar4 = BN_ucmp(*(BIGNUM **)((int)ppBVar12 + -0x10),*(BIGNUM **)((int)ppBVar12 + -0xc));
        if (-1 < iVar4) goto LAB_080f46a9;
        pBVar3 = &local_34;
        *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
        *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
        *(BIGNUM **)((int)ppBVar12 + -0x18) = local_7c;
        *(BIGNUM **)((int)ppBVar12 + -0x1c) = local_5c;
        local_5c = pBVar3;
      }
      else {
LAB_080f46a9:
        *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
        *(BIGNUM **)((int)ppBVar12 + -0x14) = m;
        *(BIGNUM **)((int)ppBVar12 + -0x18) = local_5c;
        *(BIGNUM **)((int)ppBVar12 + -0x1c) = &local_34;
        *(undefined4 *)((int)ppBVar12 + -0x20) = 0;
        local_5c = &local_34;
        *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f46bf;
        iVar4 = BN_div(*(BIGNUM **)((int)ppBVar12 + -0x20),*(BIGNUM **)((int)ppBVar12 + -0x1c),
                       *(BIGNUM **)((int)ppBVar12 + -0x18),*(BIGNUM **)((int)ppBVar12 + -0x14),
                       *(BN_CTX **)((int)ppBVar12 + -0x10));
        pBVar3 = local_5c;
        if (iVar4 == 0) goto LAB_080f46ca;
        *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
        *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
        *(BIGNUM **)((int)ppBVar12 + -0x18) = local_7c;
        *(BIGNUM **)((int)ppBVar12 + -0x1c) = pBVar3;
      }
      *(BIGNUM **)((int)ppBVar12 + -0x20) = pBVar3;
      *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f4884;
      iVar4 = BN_mod_mul_montgomery
                        (*(BIGNUM **)((int)ppBVar12 + -0x20),*(BIGNUM **)((int)ppBVar12 + -0x1c),
                         *(BIGNUM **)((int)ppBVar12 + -0x18),
                         *(BN_MONT_CTX **)((int)ppBVar12 + -0x14),
                         *(BN_CTX **)((int)ppBVar12 + -0x10));
      pBVar3 = local_5c;
      if (iVar4 == 0) goto LAB_080f46ca;
      pBVar9 = local_44;
      if ((int)pBVar7 <= (int)local_44) {
        pBVar9 = pBVar7;
      }
      iVar4 = 0;
      if ((int)pBVar9 * 4 != 0) {
        local_7c = pBVar7;
        puVar8 = local_64;
        do {
          puVar1 = local_48 + iVar4;
          iVar4 = iVar4 + 1;
          *puVar8 = *puVar1;
          puVar8 = puVar8 + local_74;
        } while (iVar4 != (int)pBVar9 * 4);
      }
      puVar8 = local_64 + 1;
      pBVar9 = (BIGNUM *)local_34.top;
      if ((int)pBVar7 <= local_34.top) {
        pBVar9 = pBVar7;
      }
      iVar4 = 0;
      if ((int)pBVar9 * 4 != 0) {
        local_7c = pBVar7;
        do {
          puVar1 = (undefined *)((int)local_34.d + iVar4);
          iVar4 = iVar4 + 1;
          *puVar8 = *puVar1;
          puVar8 = puVar8 + local_74;
        } while (iVar4 != (int)pBVar9 * 4);
      }
      if (local_80 == 1) {
        local_7c = (BIGNUM *)0x0;
        local_78 = (BIGNUM *)((int)&local_68[-1].flags + 3);
LAB_080f4a10:
        pBVar3 = local_50;
        local_88 = pBVar7;
        iVar4 = 0;
        local_8c = (BIGNUM *)ctx;
        local_68 = (BIGNUM *)((int)local_7c - (int)local_78);
        pBVar7 = local_78;
        do {
          *(BIGNUM **)((int)ppBVar12 + -0xc) = pBVar7;
          *(BIGNUM **)((int)ppBVar12 + -0x10) = pBVar3;
          pBVar7 = (BIGNUM *)((int)&pBVar7[-1].flags + 3);
          *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f4a3f;
          iVar5 = BN_is_bit_set(*(BIGNUM **)((int)ppBVar12 + -0x10),*(int *)((int)ppBVar12 + -0xc));
          iVar4 = iVar4 * 2 + iVar5;
        } while (-1 < (int)((int)&pBVar7->d + (int)&local_68->d));
        pBVar7 = (BIGNUM *)0x0;
        if (-1 < (int)local_7c) {
          pBVar7 = local_7c;
        }
        local_78 = (BIGNUM *)((int)local_78 + (-1 - (int)pBVar7));
        pBVar7 = local_88;
        ctx = (BN_CTX *)local_8c;
      }
      else {
        *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
        *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
        *(BIGNUM **)((int)ppBVar12 + -0x18) = pBVar3;
        *(BIGNUM **)((int)ppBVar12 + -0x1c) = pBVar3;
        *(undefined ***)((int)ppBVar12 + -0x20) = &local_48;
        *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f491c;
        iVar5 = BN_mod_mul_montgomery
                          (*(BIGNUM **)((int)ppBVar12 + -0x20),*(BIGNUM **)((int)ppBVar12 + -0x1c),
                           *(BIGNUM **)((int)ppBVar12 + -0x18),
                           *(BN_MONT_CTX **)((int)ppBVar12 + -0x14),
                           *(BN_CTX **)((int)ppBVar12 + -0x10));
        iVar4 = local_74;
        if (iVar5 == 0) goto LAB_080f46ca;
        pBVar3 = local_44;
        if ((int)pBVar7 <= (int)local_44) {
          pBVar3 = pBVar7;
        }
        puVar8 = local_64 + 2;
        iVar6 = 0;
        iVar5 = (int)pBVar3 * 4;
        while (iVar5 != 0) {
          puVar1 = local_48 + iVar6;
          iVar6 = iVar6 + 1;
          *puVar8 = *puVar1;
          puVar8 = puVar8 + local_74;
          iVar5 = (int)pBVar3 * 4 - iVar6;
        }
        pBVar3 = (BIGNUM *)(local_64 + 3);
        local_88 = (BIGNUM *)(local_64 + (int)local_78);
        if (3 < (int)local_78) {
          local_7c = pBVar7;
          local_78 = (BIGNUM *)ctx;
          do {
            *(BIGNUM **)((int)ppBVar12 + -0x10) = local_78;
            *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
            *(undefined ***)((int)ppBVar12 + -0x18) = &local_48;
            *(BIGNUM **)((int)ppBVar12 + -0x1c) = local_5c;
            *(undefined ***)((int)ppBVar12 + -0x20) = &local_48;
            *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f49a6;
            iVar5 = BN_mod_mul_montgomery
                              (*(BIGNUM **)((int)ppBVar12 + -0x20),
                               *(BIGNUM **)((int)ppBVar12 + -0x1c),
                               *(BIGNUM **)((int)ppBVar12 + -0x18),
                               *(BN_MONT_CTX **)((int)ppBVar12 + -0x14),
                               *(BN_CTX **)((int)ppBVar12 + -0x10));
            ctx = (BN_CTX *)local_78;
            if (iVar5 == 0) goto LAB_080f46ca;
            pBVar7 = local_44;
            if ((int)local_7c <= (int)local_44) {
              pBVar7 = local_7c;
            }
            iVar5 = 0;
            pBVar9 = pBVar3;
            if ((int)pBVar7 * 4 != 0) {
              do {
                puVar8 = local_48 + iVar5;
                iVar5 = iVar5 + 1;
                *(undefined *)&pBVar9->d = *puVar8;
                pBVar9 = (BIGNUM *)((int)&pBVar9->d + iVar4);
              } while (iVar5 != (int)pBVar7 * 4);
            }
            pBVar3 = (BIGNUM *)((int)&pBVar3->d + 1);
            pBVar7 = local_7c;
          } while (pBVar3 != local_88);
        }
        iVar4 = 0;
        local_78 = (BIGNUM *)((int)&local_68[-1].flags + 3);
        local_7c = (BIGNUM *)((int)local_78 % local_80);
        if (-1 < (int)local_7c) goto LAB_080f4a10;
      }
      if ((int)local_40 < (int)pBVar7) {
        *(BIGNUM **)((int)ppBVar12 + -0xc) = pBVar7;
        *(undefined ***)((int)ppBVar12 + -0x10) = &local_48;
        *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f4c75;
        pBVar3 = bn_expand2(*(BIGNUM **)((int)ppBVar12 + -0x10),*(int *)((int)ppBVar12 + -0xc));
        if (pBVar3 != (BIGNUM *)0x0) goto LAB_080f4a78;
LAB_080f4c80:
        uVar10 = 0;
      }
      else {
LAB_080f4a78:
        pBVar3 = (BIGNUM *)0x0;
        puVar8 = local_64 + iVar4;
        if (local_84 != (BIGNUM *)0x0) {
          local_68 = pBVar7;
          local_7c = (BIGNUM *)ctx;
          do {
            uVar2 = *puVar8;
            puVar8 = puVar8 + local_74;
            local_48[(int)pBVar3] = uVar2;
            pBVar3 = (BIGNUM *)((int)&pBVar3->d + 1);
          } while (local_84 != pBVar3);
        }
        local_44 = pBVar7;
        if (0 < (int)pBVar7) {
          do {
            if (*(int *)((undefined *)((int)local_84 + (int)pBVar7 * -4 + -4) + (int)local_48 +
                        (int)local_44 * 4) != 0) break;
            local_44 = (BIGNUM *)((int)&local_44[-1].flags + 3);
          } while (local_44 != (BIGNUM *)0x0);
        }
        local_88 = (BIGNUM *)((int)local_84 + (int)pBVar7 * -4 + -4);
        if (-1 < (int)local_78) {
          local_7c = pBVar7;
          pBVar7 = local_78;
          do {
            iVar4 = 0;
            local_68 = (BIGNUM *)((int)pBVar7 - local_80);
            do {
              *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
              *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
              *(undefined ***)((int)ppBVar12 + -0x18) = &local_48;
              *(undefined ***)((int)ppBVar12 + -0x1c) = &local_48;
              *(undefined ***)((int)ppBVar12 + -0x20) = &local_48;
              *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f4b2a;
              iVar5 = BN_mod_mul_montgomery
                                (*(BIGNUM **)((int)ppBVar12 + -0x20),
                                 *(BIGNUM **)((int)ppBVar12 + -0x1c),
                                 *(BIGNUM **)((int)ppBVar12 + -0x18),
                                 *(BN_MONT_CTX **)((int)ppBVar12 + -0x14),
                                 *(BN_CTX **)((int)ppBVar12 + -0x10));
              if (iVar5 == 0) goto LAB_080f46ca;
              *(BIGNUM **)((int)ppBVar12 + -0xc) = pBVar7;
              *(BIGNUM **)((int)ppBVar12 + -0x10) = local_50;
              pBVar7 = (BIGNUM *)((int)&pBVar7[-1].flags + 3);
              *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f4b46;
              iVar5 = BN_is_bit_set(*(BIGNUM **)((int)ppBVar12 + -0x10),
                                    *(int *)((int)ppBVar12 + -0xc));
              iVar4 = iVar4 * 2 + iVar5;
            } while (pBVar7 != local_68);
            if (local_34.dmax < (int)local_7c) {
              *(BIGNUM **)((int)ppBVar12 + -0xc) = local_7c;
              *(BIGNUM **)((int)ppBVar12 + -0x10) = local_5c;
              *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f4cb5;
              pBVar7 = bn_expand2(*(BIGNUM **)((int)ppBVar12 + -0x10),*(int *)((int)ppBVar12 + -0xc)
                                 );
              if (pBVar7 == (BIGNUM *)0x0) goto LAB_080f4c80;
            }
            puVar8 = local_64 + iVar4;
            pBVar7 = (BIGNUM *)0x0;
            if (local_84 != (BIGNUM *)0x0) {
              local_78 = local_84;
              do {
                uVar2 = *puVar8;
                puVar8 = puVar8 + local_74;
                *(undefined *)((int)local_34.d + (int)pBVar7) = uVar2;
                pBVar7 = (BIGNUM *)((int)&pBVar7->d + 1);
              } while (local_84 != pBVar7);
            }
            local_34.top = (int)local_7c;
            if (0 < (int)local_7c) {
              do {
                if (*(int *)((int)local_34.d + (int)(&local_88->d + local_34.top)) != 0) break;
                local_34.top = (int)&((BIGNUM *)(local_34.top + -0x14))->flags + 3;
              } while ((BIGNUM *)local_34.top != (BIGNUM *)0x0);
            }
            *(BN_CTX **)((int)ppBVar12 + -0x10) = ctx;
            *(BN_MONT_CTX **)((int)ppBVar12 + -0x14) = local_58;
            *(BIGNUM **)((int)ppBVar12 + -0x18) = local_5c;
            *(undefined ***)((int)ppBVar12 + -0x1c) = &local_48;
            *(undefined ***)((int)ppBVar12 + -0x20) = &local_48;
            *(undefined4 *)((int)ppBVar12 + -0x24) = 0x80f4bc3;
            iVar4 = BN_mod_mul_montgomery
                              (*(BIGNUM **)((int)ppBVar12 + -0x20),
                               *(BIGNUM **)((int)ppBVar12 + -0x1c),
                               *(BIGNUM **)((int)ppBVar12 + -0x18),
                               *(BN_MONT_CTX **)((int)ppBVar12 + -0x14),
                               *(BN_CTX **)((int)ppBVar12 + -0x10));
            if (iVar4 == 0) goto LAB_080f46ca;
            pBVar7 = local_68;
          } while (-1 < (int)local_68);
        }
        *(BN_CTX **)((int)ppBVar12 + -4) = ctx;
        *(BN_MONT_CTX **)((int)ppBVar12 + -8) = local_58;
        *(undefined ***)((int)ppBVar12 + -0xc) = &local_48;
        *(BIGNUM **)((int)ppBVar12 + -0x10) = local_60;
        *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f4beb;
        iVar4 = BN_from_montgomery(*(BIGNUM **)((int)ppBVar12 + -0x10),
                                   *(BIGNUM **)((int)ppBVar12 + -0xc),
                                   *(BN_MONT_CTX **)((int)ppBVar12 + -8),
                                   *(BN_CTX **)((int)ppBVar12 + -4));
        uVar10 = (uint)(iVar4 != 0);
      }
    }
    if (local_54 == (BN_MONT_CTX *)0x0) {
LAB_080f4830:
      *(BN_MONT_CTX **)((int)ppBVar12 + -0x10) = local_58;
      *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f483b;
      BN_MONT_CTX_free(*(BN_MONT_CTX **)((int)ppBVar12 + -0x10));
      ppBVar11 = ppBVar12;
      if (local_64 == (undefined *)0x0) goto LAB_080f46fb;
    }
    *(size_t *)((int)ppBVar12 + -0xc) = local_6c;
    *(undefined **)((int)ppBVar12 + -0x10) = local_64;
    *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f46e5;
    OPENSSL_cleanse(*(void **)((int)ppBVar12 + -0x10),*(size_t *)((int)ppBVar12 + -0xc));
    ppBVar11 = ppBVar12;
    if (local_70 != (void *)0x0) {
      *(void **)((int)ppBVar12 + -0x10) = local_70;
      *(undefined4 *)((int)ppBVar12 + -0x14) = 0x80f46f8;
      CRYPTO_free(*(void **)((int)ppBVar12 + -0x10));
    }
  }
LAB_080f46fb:
  *(BN_CTX **)((int)ppBVar11 + -0x10) = ctx;
  *(undefined4 *)((int)ppBVar11 + -0x14) = 0x80f4704;
  BN_CTX_end(*(BN_CTX **)((int)ppBVar11 + -0x10));
LAB_080f4720:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    *(undefined4 *)((int)ppBVar11 + -4) = 0x80f4cc6;
    __stack_chk_fail();
  }
  return uVar10;
}

