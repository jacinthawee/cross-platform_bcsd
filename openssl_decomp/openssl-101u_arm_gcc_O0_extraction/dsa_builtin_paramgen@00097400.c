
void dsa_builtin_paramgen
               (int param_1,uint param_2,uint param_3,EVP_MD *param_4,int param_5,uint param_6,
               void *param_7,int *param_8,int *param_9,BN_GENCB *param_10)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  BN_MONT_CTX *mont;
  BN_CTX *ctx;
  BIGNUM *pBVar4;
  BIGNUM *r;
  BIGNUM *pBVar5;
  BIGNUM *ret;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *pBVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  uint uVar12;
  int iVar13;
  uint do_trial_division;
  uint count;
  int iVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  EVP_MD *local_124;
  int local_120;
  uint local_114;
  uchar *local_f8;
  int local_f0;
  int local_d4;
  uchar auStack_ac [31];
  byte bStack_8d;
  undefined4 local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  undefined auStack_6c [32];
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  count = param_3 >> 3;
  local_120 = param_5;
  local_2c = __stack_chk_guard;
  if (((count & 0xfffffff7) != 0x14) && (count != 0x20)) {
    uVar3 = 0;
    goto LAB_00097440;
  }
  local_124 = param_4;
  if (param_4 == (EVP_MD *)0x0) {
    local_124 = EVP_sha1();
  }
  if (param_2 < 0x200) {
    uVar15 = 0x200;
  }
  else {
    uVar15 = param_2 + 0x3f & 0xffffffc0;
  }
  if ((param_6 == 0 || param_6 <= count) && (param_6 != 0 && count != param_6)) {
    local_120 = 0;
    local_114 = param_6;
    if (count <= param_6) {
      local_114 = count;
    }
  }
  else {
    if (count <= param_6) {
      param_6 = count;
    }
    local_114 = param_6;
    if (param_5 != 0) {
      __memcpy_chk(auStack_ac,param_5,param_6,0x20);
    }
  }
  mont = BN_MONT_CTX_new();
  if ((mont == (BN_MONT_CTX *)0x0) || (ctx = BN_CTX_new(), ctx == (BN_CTX *)0x0)) {
LAB_0009788a:
    uVar3 = 0;
  }
  else {
    BN_CTX_start(ctx);
    pBVar4 = BN_CTX_get(ctx);
    uVar15 = uVar15 - 1;
    r = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    ret = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = BN_CTX_get(ctx);
    pBVar6 = BN_value_one();
    uVar10 = uVar15;
    iVar7 = BN_lshift(r_01,pBVar6,uVar15);
    if (iVar7 != 0) {
      uVar9 = param_3 >> 5;
      bVar16 = uVar9 == 0;
      bVar1 = count != 3;
      bVar17 = count < 3;
      iVar7 = count - 1;
      if (!bVar16 && bVar17 || (bVar16 || !bVar1)) {
        uVar10 = 1;
      }
      if ((bVar16 || !bVar17) && (!bVar16 && bVar1)) {
        uVar10 = 0;
      }
      uVar12 = uVar9 << 2;
      if (!bVar16 && bVar17 || (bVar16 || !bVar1)) {
        uVar12 = 0;
      }
      local_f0 = 0;
      while (iVar8 = BN_GENCB_call(param_10,0,local_f0), iVar8 != 0) {
        do_trial_division = (uint)(local_120 == 0 || local_114 == 0);
        uVar2 = do_trial_division;
        if (local_120 == 0 || local_114 == 0) {
          iVar8 = RAND_bytes(auStack_ac,count);
          if (iVar8 < 1) break;
          do_trial_division = 1;
          uVar2 = local_114;
        }
        local_114 = uVar2;
        local_f8 = auStack_ac;
        __memcpy_chk(auStack_6c,local_f8,count,0x20);
        __memcpy_chk(&local_4c,local_f8,count,0x20);
        if (-1 < iVar7) {
          cVar11 = auStack_6c[count - 1] + '\x01';
          auStack_6c[count - 1] = cVar11;
          iVar8 = iVar7;
          while ((cVar11 == '\0' && (bVar17 = iVar8 != 0, iVar8 = iVar8 + -1, bVar17))) {
            cVar11 = auStack_6c[iVar8] + '\x01';
            auStack_6c[iVar8] = cVar11;
          }
        }
        iVar8 = EVP_Digest(local_f8,count,(uchar *)&local_8c,(uint *)0x0,local_124,(ENGINE *)0x0);
        if ((iVar8 == 0) ||
           (iVar8 = EVP_Digest(auStack_6c,count,(uchar *)&local_4c,(uint *)0x0,local_124,
                               (ENGINE *)0x0), iVar8 == 0)) break;
        if (count != 0) {
          if (uVar10 == 0) {
            local_8c = local_8c ^ local_4c;
            if ((((((1 < uVar9) && (local_88 = local_88 ^ local_48, uVar9 != 2)) &&
                  (local_84 = local_84 ^ local_44, uVar9 != 3)) &&
                 ((local_80 = local_40 ^ local_80, uVar9 != 4 &&
                  (local_7c = local_3c ^ local_7c, uVar9 != 5)))) &&
                (local_78 = local_38 ^ local_78, uVar9 != 6)) &&
               (local_74 = local_34 ^ local_74, uVar9 != 7)) {
              local_70 = local_30 ^ local_70;
            }
            if (count == uVar9 << 2) goto LAB_000976e2;
          }
          *(byte *)((int)&local_8c + uVar12) =
               *(byte *)((int)&local_8c + uVar12) ^ *(byte *)((int)&local_4c + uVar12);
          if ((uVar12 + 1 < count) &&
             (*(byte *)((int)&local_8c + uVar12 + 1) =
                   *(byte *)((int)&local_8c + uVar12 + 1) ^ *(byte *)((int)&local_4c + uVar12 + 1),
             uVar12 + 2 < count)) {
            *(byte *)((int)&local_8c + uVar12 + 2) =
                 *(byte *)((int)&local_4c + uVar12 + 2) ^ *(byte *)((int)&local_8c + uVar12 + 2);
          }
        }
LAB_000976e2:
        local_8c = local_8c | 0x80;
        (&bStack_8d)[count] = (&bStack_8d)[count] | 1;
        pBVar6 = BN_bin2bn((uchar *)&local_8c,count,ret);
        if (pBVar6 == (BIGNUM *)0x0) break;
        iVar8 = BN_is_prime_fasttest_ex(ret,0x32,ctx,do_trial_division,param_10);
        if (iVar8 < 1) {
          if (iVar8 != 0) break;
        }
        else {
          iVar8 = BN_GENCB_call(param_10,2,0);
          if ((iVar8 == 0) || (iVar8 = BN_GENCB_call(param_10,3,0), iVar8 == 0)) break;
          local_d4 = 0;
          while( true ) {
            iVar8 = 0;
            BN_set_word(pBVar5,0);
            iVar14 = 0;
            do {
              if (-1 < iVar7) {
                cVar11 = auStack_6c[count - 1] + '\x01';
                auStack_6c[count - 1] = cVar11;
                iVar13 = iVar7;
                while ((cVar11 == '\0' && (bVar17 = iVar13 != 0, iVar13 = iVar13 + -1, bVar17))) {
                  cVar11 = auStack_6c[iVar13] + '\x01';
                  auStack_6c[iVar13] = cVar11;
                }
              }
              iVar13 = EVP_Digest(auStack_6c,count,(uchar *)&local_8c,(uint *)0x0,local_124,
                                  (ENGINE *)0x0);
              if ((((iVar13 == 0) ||
                   (pBVar6 = BN_bin2bn((uchar *)&local_8c,count,pBVar4), pBVar6 == (BIGNUM *)0x0))
                  || (iVar13 = BN_lshift(pBVar4,pBVar4,iVar8), iVar13 == 0)) ||
                 (iVar13 = BN_add(pBVar5,pBVar5,pBVar4), iVar13 == 0)) goto LAB_00097886;
              iVar14 = iVar14 + 1;
              iVar8 = iVar8 + (param_3 & 0xfffffff8);
            } while (iVar14 <= (int)(uVar15 / 0xa0));
            iVar8 = BN_mask_bits(pBVar5,uVar15);
            if (((iVar8 == 0) || (pBVar6 = BN_copy(a,pBVar5), pBVar6 == (BIGNUM *)0x0)) ||
               ((iVar8 = BN_add(a,a,r_01), iVar8 == 0 ||
                ((iVar8 = BN_lshift1(pBVar4,ret), iVar8 == 0 ||
                 (iVar8 = BN_div((BIGNUM *)0x0,rem,a,pBVar4,ctx), iVar8 == 0))))))
            goto LAB_00097886;
            pBVar6 = BN_value_one();
            iVar8 = BN_sub(pBVar4,rem,pBVar6);
            if ((iVar8 == 0) || (iVar8 = BN_sub(r_00,a,pBVar4), iVar8 == 0)) goto LAB_00097886;
            iVar8 = BN_cmp(r_00,r_01);
            if (-1 < iVar8) {
              iVar8 = BN_is_prime_fasttest_ex(r_00,0x32,ctx,1,param_10);
              if (0 < iVar8) {
                iVar7 = BN_GENCB_call(param_10,2,1);
                if (iVar7 == 0) goto LAB_00097886;
                pBVar5 = BN_value_one();
                iVar7 = BN_sub(r_01,r_00,pBVar5);
                if ((((iVar7 == 0) ||
                     (iVar7 = BN_div(pBVar4,(BIGNUM *)0x0,r_01,ret,ctx), iVar7 == 0)) ||
                    (iVar7 = BN_set_word(r_01,2), iVar7 == 0)) ||
                   (iVar7 = BN_MONT_CTX_set(mont,r_00,ctx), iVar7 == 0)) goto LAB_00097886;
                iVar7 = 2;
                goto LAB_00097926;
              }
              if (iVar8 != 0) goto LAB_00097886;
            }
            local_d4 = local_d4 + 1;
            if (local_d4 == 0x1000) break;
            iVar8 = BN_GENCB_call(param_10,0,local_d4);
            if (iVar8 == 0) goto LAB_00097886;
          }
        }
        local_f0 = local_f0 + 1;
      }
    }
LAB_00097886:
    if (ctx == (BN_CTX *)0x0) goto LAB_0009788a;
LAB_000978a0:
    uVar3 = 0;
LAB_000978a2:
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
  }
LAB_00097440:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
LAB_00097926:
  iVar8 = BN_mod_exp_mont(r,r_01,pBVar4,r_00,ctx,mont);
  if (iVar8 == 0) goto LAB_00097886;
  if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) {
    iVar8 = BN_GENCB_call(param_10,3,1);
    if (iVar8 == 0) goto LAB_000978a0;
    if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0xc));
    }
    if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0x10));
    }
    if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0x14));
    }
    pBVar4 = BN_dup(r_00);
    *(BIGNUM **)(param_1 + 0xc) = pBVar4;
    pBVar4 = BN_dup(ret);
    *(BIGNUM **)(param_1 + 0x10) = pBVar4;
    pBVar4 = BN_dup(r);
    *(BIGNUM **)(param_1 + 0x14) = pBVar4;
    if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
       (pBVar4 == (BIGNUM *)0x0)) goto LAB_000978a0;
    if (param_8 != (int *)0x0) {
      *param_8 = local_d4;
    }
    if (param_9 != (int *)0x0) {
      *param_9 = iVar7;
    }
    if (param_7 == (void *)0x0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 1;
      memcpy(param_7,local_f8,count);
    }
    goto LAB_000978a2;
  }
  pBVar5 = BN_value_one();
  iVar8 = BN_add(r_01,r_01,pBVar5);
  if (iVar8 == 0) goto LAB_00097886;
  iVar7 = iVar7 + 1;
  goto LAB_00097926;
}

