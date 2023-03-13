
undefined4
dsa_builtin_paramgen
          (int param_1,uint param_2,uint param_3,EVP_MD *param_4,int param_5,uint param_6,
          void *param_7,int *param_8,int *param_9,BN_GENCB *param_10)

{
  uint uVar1;
  byte *pbVar2;
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
  char *pcVar9;
  int iVar10;
  uint uVar11;
  char cVar12;
  uint uVar13;
  uint count;
  int in_GS_OFFSET;
  int local_114;
  EVP_MD *local_110;
  int local_100;
  uint local_dc;
  int local_d0;
  int local_cc;
  byte bStack_a1;
  undefined4 local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  undefined4 local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uchar local_60 [30];
  char acStack_42 [34];
  int local_20;
  
  local_110 = param_4;
  count = param_3 >> 3;
  local_100 = param_5;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((count & 0xfffffff7) != 0x14) && (uVar3 = 0, count != 0x20)) goto LAB_0810c7a4;
  if (param_4 == (EVP_MD *)0x0) {
    local_110 = EVP_sha1();
  }
  uVar13 = 0x200;
  if (param_2 < 0x200) {
    if (param_6 == 0) goto LAB_0810cb95;
LAB_0810c7f2:
    if (count <= param_6) goto LAB_0810cb95;
    local_100 = 0;
    local_dc = param_6;
    if (count <= param_6) {
      local_dc = count;
    }
  }
  else {
    uVar13 = param_2 + 0x3f & 0xffffffc0;
    if (param_6 != 0) goto LAB_0810c7f2;
LAB_0810cb95:
    if (count <= param_6) {
      param_6 = count;
    }
    local_dc = param_6;
    if (param_5 != 0) {
      __memcpy_chk(local_60,param_5,param_6,0x20);
    }
  }
  mont = BN_MONT_CTX_new();
  uVar3 = 0;
  if (mont != (BN_MONT_CTX *)0x0) {
    ctx = BN_CTX_new();
    uVar3 = 0;
    if (ctx != (BN_CTX *)0x0) {
      uVar13 = uVar13 - 1;
      BN_CTX_start(ctx);
      pBVar4 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      ret = BN_CTX_get(ctx);
      a = BN_CTX_get(ctx);
      rem = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      r_01 = BN_CTX_get(ctx);
      pBVar6 = BN_value_one();
      iVar7 = BN_lshift(r_01,pBVar6,uVar13);
      if (iVar7 != 0) {
        uVar1 = count - 1;
        iVar7 = (count - 4 >> 2) + 1;
        local_d0 = 0;
        while (iVar8 = BN_GENCB_call(param_10,0,local_d0), iVar8 != 0) {
          if ((local_dc == 0) || (local_100 == 0)) {
            iVar8 = RAND_bytes(local_60,count);
            if (iVar8 < 1) break;
            local_114 = 1;
          }
          else {
            local_114 = 0;
            local_dc = 0;
          }
          __memcpy_chk(acStack_42 + 2,local_60,count,0x20);
          __memcpy_chk(&local_80,local_60,count,0x20);
          if (uVar1 != 0xffffffff) {
            pcVar9 = acStack_42 + count + 1;
            *pcVar9 = *pcVar9 + '\x01';
            cVar12 = *pcVar9;
            for (pcVar9 = acStack_42 + count; (cVar12 == '\0' && (pcVar9 != acStack_42 + 1));
                pcVar9 = pcVar9 + -1) {
              cVar12 = *pcVar9 + '\x01';
              *pcVar9 = cVar12;
            }
          }
          iVar8 = EVP_Digest(local_60,count,(uchar *)&local_a0,(uint *)0x0,local_110,(ENGINE *)0x0);
          if ((iVar8 == 0) ||
             (iVar8 = EVP_Digest(acStack_42 + 2,count,(uchar *)&local_80,(uint *)0x0,local_110,
                                 (ENGINE *)0x0), iVar8 == 0)) break;
          if (count != 0) {
            if (uVar1 < 3) {
              uVar11 = 0;
            }
            else {
              local_a0 = local_a0 ^ local_80;
              if ((((((iVar7 != 1) && (local_9c = local_9c ^ local_7c, iVar7 != 2)) &&
                    (local_98 = local_98 ^ local_78, iVar7 != 3)) &&
                   ((local_94 = local_94 ^ local_74, iVar7 != 4 &&
                    (local_90 = local_90 ^ local_70, iVar7 != 5)))) &&
                  (local_8c = local_8c ^ local_6c, iVar7 != 6)) &&
                 (local_88 = local_88 ^ local_68, iVar7 != 7)) {
                local_84 = local_84 ^ local_64;
              }
              uVar11 = iVar7 * 4;
              if (count == iVar7 * 4) goto LAB_0810cb1e;
            }
            *(byte *)((int)&local_a0 + uVar11) =
                 *(byte *)((int)&local_a0 + uVar11) ^ *(byte *)((int)&local_80 + uVar11);
            if (((int)(uVar11 + 1) < (int)count) &&
               (pbVar2 = (byte *)((int)&local_a0 + uVar11 + 1),
               *pbVar2 = *pbVar2 ^ *(byte *)((int)&local_80 + uVar11 + 1),
               (int)(uVar11 + 2) < (int)count)) {
              pbVar2 = (byte *)((int)&local_a0 + uVar11 + 2);
              *pbVar2 = *pbVar2 ^ *(byte *)((int)&local_80 + uVar11 + 2);
            }
          }
LAB_0810cb1e:
          local_a0 = local_a0 | 0x80;
          (&bStack_a1)[count] = (&bStack_a1)[count] | 1;
          pBVar6 = BN_bin2bn((uchar *)&local_a0,count,ret);
          if (pBVar6 == (BIGNUM *)0x0) break;
          iVar8 = BN_is_prime_fasttest_ex(ret,0x32,ctx,local_114,param_10);
          if (0 < iVar8) {
            iVar8 = BN_GENCB_call(param_10,2,0);
            if ((iVar8 != 0) && (iVar8 = BN_GENCB_call(param_10,3,0), iVar8 != 0)) {
              local_cc = 0;
              do {
                iVar8 = 0;
                BN_set_word(pBVar5,0);
                local_114 = 0;
                do {
                  if (uVar1 != 0xffffffff) {
                    pcVar9 = acStack_42 + count + 1;
                    *pcVar9 = *pcVar9 + '\x01';
                    if (*pcVar9 == '\0') {
                      pcVar9 = acStack_42 + count;
                      do {
                        if (acStack_42 + 1 == pcVar9) break;
                        cVar12 = *pcVar9;
                        *pcVar9 = cVar12 + '\x01';
                        pcVar9 = pcVar9 + -1;
                      } while ((char)(cVar12 + '\x01') == '\0');
                    }
                  }
                  iVar10 = EVP_Digest(acStack_42 + 2,count,(uchar *)&local_a0,(uint *)0x0,local_110,
                                      (ENGINE *)0x0);
                  if ((((iVar10 == 0) ||
                       (pBVar6 = BN_bin2bn((uchar *)&local_a0,count,pBVar4), pBVar6 == (BIGNUM *)0x0
                       )) || (iVar10 = BN_lshift(pBVar4,pBVar4,iVar8), iVar10 == 0)) ||
                     (iVar10 = BN_add(pBVar5,pBVar5,pBVar4), iVar10 == 0)) goto LAB_0810ce20;
                  local_114 = local_114 + 1;
                  iVar8 = iVar8 + (param_3 & 0xfffffff8);
                } while (local_114 <= (int)(uVar13 / 0xa0));
                iVar8 = BN_mask_bits(pBVar5,uVar13);
                if (((iVar8 == 0) || (pBVar6 = BN_copy(a,pBVar5), pBVar6 == (BIGNUM *)0x0)) ||
                   ((iVar8 = BN_add(a,a,r_01), iVar8 == 0 ||
                    ((iVar8 = BN_lshift1(pBVar4,ret), iVar8 == 0 ||
                     (iVar8 = BN_div((BIGNUM *)0x0,rem,a,pBVar4,ctx), iVar8 == 0)))))) break;
                pBVar6 = BN_value_one();
                iVar8 = BN_sub(pBVar4,rem,pBVar6);
                if ((iVar8 == 0) || (iVar8 = BN_sub(r_00,a,pBVar4), iVar8 == 0)) break;
                iVar8 = BN_cmp(r_00,r_01);
                if (-1 < iVar8) {
                  iVar8 = BN_is_prime_fasttest_ex(r_00,0x32,ctx,1,param_10);
                  if (0 < iVar8) {
                    iVar7 = BN_GENCB_call(param_10,2,1);
                    if (iVar7 == 0) break;
                    pBVar5 = BN_value_one();
                    iVar7 = BN_sub(r_01,r_00,pBVar5);
                    if ((((iVar7 == 0) ||
                         (iVar7 = BN_div(pBVar4,(BIGNUM *)0x0,r_01,ret,ctx), iVar7 == 0)) ||
                        (iVar7 = BN_set_word(r_01,2), iVar7 == 0)) ||
                       (iVar7 = BN_MONT_CTX_set(mont,r_00,ctx), iVar7 == 0)) break;
                    iVar7 = 2;
                    goto LAB_0810cf39;
                  }
                  if (iVar8 != 0) break;
                }
                local_cc = local_cc + 1;
                if (local_cc == 0x1000) goto LAB_0810cb70;
                iVar8 = BN_GENCB_call(param_10,0,local_cc);
                if (iVar8 == 0) break;
              } while( true );
            }
            break;
          }
          if (iVar8 != 0) break;
LAB_0810cb70:
          local_d0 = local_d0 + 1;
        }
      }
LAB_0810ce20:
      uVar3 = 0;
LAB_0810ce22:
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
    }
    BN_MONT_CTX_free(mont);
  }
LAB_0810c7a4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0810cf39:
  iVar8 = BN_mod_exp_mont(r,r_01,pBVar4,r_00,ctx,mont);
  if (iVar8 == 0) goto LAB_0810ce20;
  if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) {
    iVar8 = BN_GENCB_call(param_10,3,1);
    if (iVar8 != 0) {
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
      if (((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0x10) != 0)) &&
         (pBVar4 != (BIGNUM *)0x0)) {
        if (param_8 != (int *)0x0) {
          *param_8 = local_cc;
        }
        if (param_9 != (int *)0x0) {
          *param_9 = iVar7;
        }
        uVar3 = 1;
        if (param_7 != (void *)0x0) {
          memcpy(param_7,local_60,count);
        }
        goto LAB_0810ce22;
      }
    }
    goto LAB_0810ce20;
  }
  pBVar5 = BN_value_one();
  iVar8 = BN_add(r_01,r_01,pBVar5);
  if (iVar8 == 0) goto LAB_0810ce20;
  iVar7 = iVar7 + 1;
  goto LAB_0810cf39;
}

