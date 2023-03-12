
void dsa_builtin_paramgen
               (int param_1,uint param_2,uint param_3,EVP_MD *param_4,int param_5,uint param_6,
               void *param_7,int *param_8,int *param_9,BN_GENCB *param_10)

{
  bool bVar1;
  BN_CTX *ctx;
  BIGNUM *pBVar2;
  BIGNUM *r;
  BIGNUM *pBVar3;
  BIGNUM *ret;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int extraout_r1;
  char cVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  BN_CTX *pBVar13;
  uint count;
  uint uVar14;
  int iVar15;
  bool bVar16;
  bool bVar17;
  EVP_MD *local_120;
  BN_MONT_CTX *local_11c;
  uchar *local_114;
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
  local_2c = __TMC_END__;
  if (((count & 0xfffffff7) == 0x14) || (count == 0x20)) {
    local_120 = param_4;
    if (param_4 == (EVP_MD *)0x0) {
      local_120 = EVP_sha1();
    }
    if (param_2 < 0x200) {
      uVar14 = 0x200;
    }
    else {
      uVar14 = param_2 + 0x3f & 0xffffffc0;
    }
    uVar12 = count;
    if (param_6 <= count) {
      uVar12 = param_6;
    }
    if ((param_6 != 0 && count < param_6 || (param_6 == 0 || count == param_6)) && (param_5 != 0)) {
      __memcpy_chk(auStack_ac,param_5,uVar12,0x20);
    }
    ctx = BN_CTX_new();
    if ((ctx == (BN_CTX *)0x0) || (local_11c = BN_MONT_CTX_new(), local_11c == (BN_MONT_CTX *)0x0))
    {
      local_11c = (BN_MONT_CTX *)0x0;
    }
    else {
      uVar14 = uVar14 - 1;
      BN_CTX_start(ctx);
      pBVar2 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      pBVar3 = BN_CTX_get(ctx);
      ret = BN_CTX_get(ctx);
      a = BN_CTX_get(ctx);
      rem = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      r_01 = BN_CTX_get(ctx);
      pBVar4 = BN_value_one();
      iVar5 = BN_lshift(r_01,pBVar4,uVar14);
      if (iVar5 != 0) {
        uVar6 = param_3 >> 5;
        bVar16 = uVar6 == 0;
        bVar1 = count != 3;
        bVar17 = count < 3;
        iVar5 = extraout_r1;
        if (!bVar16 && bVar17 || (bVar16 || !bVar1)) {
          iVar5 = 1;
        }
        if ((bVar16 || !bVar17) && (!bVar16 && bVar1)) {
          iVar5 = 0;
        }
        iVar7 = count - 1;
        uVar10 = uVar6 << 2;
        if (!bVar16 && bVar17 || (bVar16 || !bVar1)) {
          uVar10 = 0;
        }
        local_f0 = 0;
        while (iVar8 = BN_GENCB_call(param_10,0,local_f0), iVar8 != 0) {
          if (uVar12 == 0) {
            RAND_pseudo_bytes(auStack_ac,count);
          }
          local_114 = auStack_ac;
          __memcpy_chk(auStack_6c,local_114,count,0x20);
          __memcpy_chk(&local_4c,local_114,count,0x20);
          if (-1 < iVar7) {
            cVar9 = auStack_6c[count - 1] + '\x01';
            auStack_6c[count - 1] = cVar9;
            iVar8 = iVar7;
            while ((cVar9 == '\0' && (bVar17 = iVar8 != 0, iVar8 = iVar8 + -1, bVar17))) {
              cVar9 = auStack_6c[iVar8] + '\x01';
              auStack_6c[iVar8] = cVar9;
            }
          }
          iVar8 = EVP_Digest(local_114,count,(uchar *)&local_8c,(uint *)0x0,local_120,(ENGINE *)0x0)
          ;
          if ((iVar8 == 0) ||
             (iVar8 = EVP_Digest(auStack_6c,count,(uchar *)&local_4c,(uint *)0x0,local_120,
                                 (ENGINE *)0x0), iVar8 == 0)) break;
          if (count != 0) {
            if (iVar5 == 0) {
              local_8c = local_8c ^ local_4c;
              if ((((((1 < uVar6) && (local_88 = local_88 ^ local_48, uVar6 != 2)) &&
                    (local_84 = local_84 ^ local_44, uVar6 != 3)) &&
                   ((local_80 = local_40 ^ local_80, uVar6 != 4 &&
                    (local_7c = local_3c ^ local_7c, uVar6 != 5)))) &&
                  (local_78 = local_38 ^ local_78, uVar6 != 6)) &&
                 (local_74 = local_34 ^ local_74, uVar6 != 7)) {
                local_70 = local_30 ^ local_70;
              }
              if (count == uVar6 << 2) goto LAB_00098f5a;
            }
            *(byte *)((int)&local_8c + uVar10) =
                 *(byte *)((int)&local_8c + uVar10) ^ *(byte *)((int)&local_4c + uVar10);
            if ((uVar10 + 1 < count) &&
               (*(byte *)((int)&local_8c + uVar10 + 1) =
                     *(byte *)((int)&local_4c + uVar10 + 1) ^ *(byte *)((int)&local_8c + uVar10 + 1)
               , uVar10 + 2 < count)) {
              *(byte *)((int)&local_8c + uVar10 + 2) =
                   *(byte *)((int)&local_4c + uVar10 + 2) ^ *(byte *)((int)&local_8c + uVar10 + 2);
            }
          }
LAB_00098f5a:
          local_8c = local_8c | 0x80;
          (&bStack_8d)[count] = (&bStack_8d)[count] | 1;
          pBVar4 = BN_bin2bn((uchar *)&local_8c,count,ret);
          if (pBVar4 == (BIGNUM *)0x0) break;
          iVar8 = BN_is_prime_fasttest_ex(ret,0x32,ctx,(uint)(uVar12 == 0),param_10);
          if (iVar8 < 1) {
            if (iVar8 != 0) break;
          }
          else {
            iVar8 = BN_GENCB_call(param_10,2,0);
            if ((iVar8 == 0) || (iVar8 = BN_GENCB_call(param_10,3,0), iVar8 == 0)) break;
            local_d4 = 0;
            while( true ) {
              iVar8 = 0;
              BN_set_word(pBVar3,0);
              iVar15 = 0;
              do {
                if (-1 < iVar7) {
                  cVar9 = auStack_6c[count - 1] + '\x01';
                  auStack_6c[count - 1] = cVar9;
                  iVar11 = iVar7;
                  while ((cVar9 == '\0' && (bVar17 = iVar11 != 0, iVar11 = iVar11 + -1, bVar17))) {
                    cVar9 = auStack_6c[iVar11] + '\x01';
                    auStack_6c[iVar11] = cVar9;
                  }
                }
                iVar11 = EVP_Digest(auStack_6c,count,(uchar *)&local_8c,(uint *)0x0,local_120,
                                    (ENGINE *)0x0);
                if ((((iVar11 == 0) ||
                     (pBVar4 = BN_bin2bn((uchar *)&local_8c,count,pBVar2), pBVar4 == (BIGNUM *)0x0))
                    || (iVar11 = BN_lshift(pBVar2,pBVar2,iVar8), iVar11 == 0)) ||
                   (iVar11 = BN_add(pBVar3,pBVar3,pBVar2), iVar11 == 0)) goto LAB_00098fa8;
                iVar15 = iVar15 + 1;
                iVar8 = iVar8 + (param_3 & 0xfffffff8);
              } while (iVar15 <= (int)(uVar14 / 0xa0));
              iVar8 = BN_mask_bits(pBVar3,uVar14);
              if (((iVar8 == 0) || (pBVar4 = BN_copy(a,pBVar3), pBVar4 == (BIGNUM *)0x0)) ||
                 ((iVar8 = BN_add(a,a,r_01), iVar8 == 0 ||
                  ((iVar8 = BN_lshift1(pBVar2,ret), iVar8 == 0 ||
                   (iVar8 = BN_div((BIGNUM *)0x0,rem,a,pBVar2,ctx), iVar8 == 0))))))
              goto LAB_00098fa8;
              pBVar4 = BN_value_one();
              iVar8 = BN_sub(pBVar2,rem,pBVar4);
              if ((iVar8 == 0) || (iVar8 = BN_sub(r_00,a,pBVar2), iVar8 == 0)) goto LAB_00098fa8;
              iVar8 = BN_cmp(r_00,r_01);
              if (-1 < iVar8) {
                iVar8 = BN_is_prime_fasttest_ex(r_00,0x32,ctx,1,param_10);
                if (0 < iVar8) {
                  iVar5 = BN_GENCB_call(param_10,2,1);
                  if (iVar5 == 0) goto LAB_00098fa8;
                  pBVar3 = BN_value_one();
                  iVar5 = BN_sub(r_01,r_00,pBVar3);
                  if ((((iVar5 == 0) ||
                       (iVar5 = BN_div(pBVar2,(BIGNUM *)0x0,r_01,ret,ctx), iVar5 == 0)) ||
                      (iVar5 = BN_set_word(r_01,2), iVar5 == 0)) ||
                     (iVar5 = BN_MONT_CTX_set(local_11c,r_00,ctx), iVar5 == 0)) goto LAB_00098fa8;
                  iVar5 = 2;
                  goto LAB_000991b4;
                }
                if (iVar8 != 0) goto LAB_00098fa8;
              }
              local_d4 = local_d4 + 1;
              if (local_d4 == 0x1000) break;
              iVar8 = BN_GENCB_call(param_10,0,local_d4);
              if (iVar8 == 0) goto LAB_00098fa8;
            }
          }
          local_f0 = local_f0 + 1;
          uVar12 = 0;
        }
      }
    }
LAB_00098fa8:
    if (ctx != (BN_CTX *)0x0) {
LAB_00098fbc:
      pBVar13 = (BN_CTX *)0x0;
LAB_00098fbe:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
      ctx = pBVar13;
    }
    if (local_11c != (BN_MONT_CTX *)0x0) {
      BN_MONT_CTX_free(local_11c);
    }
  }
  else {
    ctx = (BN_CTX *)0x0;
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(ctx);
LAB_000991b4:
  iVar7 = BN_mod_exp_mont(r,r_01,pBVar2,r_00,ctx,local_11c);
  if (iVar7 == 0) goto LAB_00098fa8;
  if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) {
    iVar7 = BN_GENCB_call(param_10,3,1);
    if (iVar7 == 0) goto LAB_00098fbc;
    if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0xc));
    }
    if (*(BIGNUM **)(param_1 + 0x10) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0x10));
    }
    if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(param_1 + 0x14));
    }
    pBVar2 = BN_dup(r_00);
    *(BIGNUM **)(param_1 + 0xc) = pBVar2;
    pBVar2 = BN_dup(ret);
    *(BIGNUM **)(param_1 + 0x10) = pBVar2;
    pBVar2 = BN_dup(r);
    *(BIGNUM **)(param_1 + 0x14) = pBVar2;
    if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
       (pBVar2 == (BIGNUM *)0x0)) goto LAB_00098fbc;
    if (param_8 != (int *)0x0) {
      *param_8 = local_d4;
    }
    if (param_9 != (int *)0x0) {
      *param_9 = iVar5;
    }
    if (param_7 == (void *)0x0) {
      pBVar13 = (BN_CTX *)0x1;
    }
    else {
      pBVar13 = (BN_CTX *)0x1;
      memcpy(param_7,local_114,count);
    }
    goto LAB_00098fbe;
  }
  pBVar3 = BN_value_one();
  iVar7 = BN_add(r_01,r_01,pBVar3);
  if (iVar7 == 0) goto LAB_00098fa8;
  iVar5 = iVar5 + 1;
  goto LAB_000991b4;
}

