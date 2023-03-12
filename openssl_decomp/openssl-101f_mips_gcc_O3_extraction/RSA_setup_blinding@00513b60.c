
/* WARNING: Removing unreachable block (ram,0x00514a94) */

BN_BLINDING * RSA_setup_blinding(RSA *rsa,BN_CTX *ctx)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  BIGNUM *pBVar4;
  undefined4 uVar5;
  BN_BLINDING *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *a;
  BIGNUM *pBVar8;
  BIGNUM *a_00;
  BIGNUM *pBVar9;
  int iVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  BN_MONT_CTX *pBVar14;
  undefined *puVar15;
  char *pcVar16;
  undefined *puVar17;
  undefined *puVar18;
  BIGNUM *in_a2;
  char *in_a3;
  uint uVar19;
  BIGNUM *unaff_s2;
  int iVar20;
  BIGNUM *unaff_s3;
  BIGNUM *pBVar21;
  ulong *puVar22;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  BIGNUM *unaff_s8;
  BN_MONT_CTX *num;
  double in_f12_13;
  BN_CTX *pBStack_184;
  BN_CTX *pBStack_168;
  BIGNUM *pBStack_158;
  BN_MONT_CTX *pBStack_154;
  BIGNUM *pBStack_150;
  int iStack_148;
  int iStack_144;
  BIGNUM *pBStack_140;
  BIGNUM *pBStack_13c;
  BIGNUM *pBStack_124;
  BIGNUM *pBStack_120;
  int iStack_11c;
  BIGNUM BStack_114;
  undefined4 uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  undefined4 uStack_d8;
  undefined auStack_d4 [32];
  undefined4 uStack_b4;
  uint uStack_b0;
  undefined4 uStack_ac;
  uint uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  int iStack_94;
  RSA *pRStack_90;
  undefined4 uStack_8c;
  BIGNUM *pBStack_88;
  BIGNUM *pBStack_84;
  BN_CTX *pBStack_80;
  undefined *puStack_7c;
  BIGNUM *pBStack_78;
  BIGNUM *pBStack_74;
  BIGNUM *pBStack_70;
  undefined4 uStack_6c;
  _func_1623 *in_stack_ffffffa8;
  BN_MONT_CTX *local_54;
  int *piStack_4c;
  BIGNUM *local_48;
  BIGNUM *local_44;
  BIGNUM local_40;
  int local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_8c = ctx;
  if ((ctx == (BN_CTX *)0x0) &&
     (pBVar21 = (BIGNUM *)ctx, uStack_8c = BN_CTX_new(), uStack_8c == (BN_CTX *)0x0)) {
    pBVar4 = (BIGNUM *)0x0;
  }
  else {
    BN_CTX_start(uStack_8c);
    unaff_s3 = BN_CTX_get(uStack_8c);
    if (unaff_s3 == (BIGNUM *)0x0) {
      in_a2 = (BIGNUM *)&DAT_00000041;
      in_stack_ffffffa8 = (_func_1623 *)&DAT_000000d0;
LAB_00513e14:
      in_a3 = "rsa_crpt.c";
      pBVar21 = (BIGNUM *)&DAT_00000088;
      pBVar4 = (BIGNUM *)0x0;
      ERR_put_error(4,0x88,(int)in_a2,"rsa_crpt.c",(int)in_stack_ffffffa8);
    }
    else {
      pBVar21 = rsa->e;
      unaff_s3 = pBVar21;
      if (pBVar21 == (BIGNUM *)0x0) {
        unaff_s6 = rsa->d;
        unaff_s7 = rsa->p;
        pBVar4 = rsa->q;
        if (((unaff_s6 != (BIGNUM *)0x0) && (unaff_s7 != (BIGNUM *)0x0)) &&
           (pBVar4 != (BIGNUM *)0x0)) {
          BN_CTX_start(uStack_8c);
          local_44 = BN_CTX_get(uStack_8c);
          local_48 = BN_CTX_get(uStack_8c);
          unaff_s8 = BN_CTX_get(uStack_8c);
          if (unaff_s8 != (BIGNUM *)0x0) {
            pBVar7 = BN_value_one();
            iVar3 = (*(code *)PTR_BN_sub_006a96cc)(local_48,unaff_s7,pBVar7);
            if (iVar3 != 0) {
              pBVar7 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a96cc)(unaff_s8,pBVar4,pBVar7);
              if ((iVar3 != 0) && (iVar3 = BN_mul(local_44,local_48,unaff_s8,uStack_8c), iVar3 != 0)
                 ) {
                unaff_s3 = (BIGNUM *)
                           (*(code *)PTR_BN_mod_inverse_006a9714)(0,unaff_s6,local_44,uStack_8c);
                BN_CTX_end(uStack_8c);
                if (unaff_s3 != (BIGNUM *)0x0) goto LAB_00513bec;
                goto LAB_00513e04;
              }
            }
          }
          BN_CTX_end(uStack_8c);
        }
LAB_00513e04:
        in_a2 = (BIGNUM *)&DAT_0000008c;
        in_stack_ffffffa8 = (_func_1623 *)0xd9;
        unaff_s3 = pBVar21;
        goto LAB_00513e14;
      }
LAB_00513bec:
      iVar3 = RAND_status();
      if (((iVar3 == 0) && (pBVar21 = rsa->d, pBVar21 != (BIGNUM *)0x0)) &&
         (pBVar21->d != (ulong *)0x0)) {
        RAND_add(pBVar21->d,pBVar21->dmax << 2,in_f12_13);
      }
      in_a2 = &local_40;
      if ((rsa->flags & 0x100U) == 0) {
        pBVar21 = rsa->n;
        local_40.d = pBVar21->d;
        local_40.top = pBVar21->top;
        local_40.dmax = pBVar21->dmax;
        local_40.neg = pBVar21->neg;
        local_40.flags = local_40.flags & 1U | pBVar21->flags & 0xfffffffeU | 6;
      }
      else {
        in_a2 = rsa->n;
      }
      local_54 = rsa->_method_mod_n;
      in_stack_ffffffa8 = rsa->meth->bn_mod_exp;
      pBVar21 = unaff_s3;
      in_a3 = (char *)uStack_8c;
      pBVar4 = (BIGNUM *)(*(code *)PTR_BN_BLINDING_create_param_006a9864)(0);
      if (pBVar4 == (BIGNUM *)0x0) {
        in_a2 = (BIGNUM *)0x0;
        in_a3 = "rsa_crpt.c";
        in_stack_ffffffa8 = (_func_1623 *)0xf5;
        pBVar21 = (BIGNUM *)&DAT_00000088;
        ERR_put_error(4,0x88,3,"rsa_crpt.c",0xf5);
      }
      else {
        uVar5 = (*(code *)PTR_BN_BLINDING_thread_id_006a9800)(pBVar4);
        (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(uVar5);
      }
    }
    BN_CTX_end(uStack_8c);
    if (ctx == (BN_CTX *)0x0) {
      BN_CTX_free(uStack_8c);
    }
    unaff_s2 = pBVar4;
    if (rsa->e == (BIGNUM *)0x0) {
      BN_free(unaff_s3);
      local_48 = pBVar4;
    }
  }
  if (local_2c == *(int *)puStack_7c) {
    return (BN_BLINDING *)pBVar4;
  }
  uStack_6c = 0x513f38;
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  num = (BN_MONT_CTX *)((uint)in_a2 >> 3);
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  pRStack_90 = rsa;
  pBStack_88 = unaff_s2;
  pBStack_84 = unaff_s3;
  pBStack_80 = ctx;
  pBStack_78 = unaff_s6;
  pBStack_74 = unaff_s7;
  pBStack_70 = unaff_s8;
  if ((((uint)num & 0xfffffff7) != 0x14) &&
     (pBVar6 = (BN_BLINDING *)0x0, num != (BN_MONT_CTX *)&DAT_00000020)) goto LAB_00513fe0;
  pBStack_184 = (BN_CTX *)in_a3;
  if ((BN_CTX *)in_a3 == (BN_CTX *)0x0) {
    pBStack_184 = (BN_CTX *)(*(code *)PTR_EVP_sha1_006a86c4)();
  }
  if (pBVar21 < (BIGNUM *)0x200) {
    uVar19 = 0x200;
    if (local_54 == (BN_MONT_CTX *)0x0) goto LAB_00514084;
LAB_0051403c:
    if (num <= local_54) {
      if (num < local_54) {
        local_54 = num;
      }
      goto LAB_00514084;
    }
    if (num < local_54) {
      local_54 = num;
    }
    pBStack_168 = BN_CTX_new();
  }
  else {
    uVar19 = (uint)((int)&pBVar21[3].d + 3) & 0xffffffc0;
    if (local_54 != (BN_MONT_CTX *)0x0) goto LAB_0051403c;
LAB_00514084:
    if (in_stack_ffffffa8 != (_func_1623 *)0x0) {
      (*(code *)PTR___memcpy_chk_006aab54)(&BStack_114,in_stack_ffffffa8,local_54,0x20);
    }
    pBStack_168 = BN_CTX_new();
  }
  if (pBStack_168 != (BN_CTX *)0x0) {
    pBStack_154 = BN_MONT_CTX_new();
    if (pBStack_154 == (BN_MONT_CTX *)0x0) goto LAB_0051479c;
    uVar19 = uVar19 - 1;
    BN_CTX_start(pBStack_168);
    pBStack_140 = BN_CTX_get(pBStack_168);
    pBVar21 = BN_CTX_get(pBStack_168);
    pBVar4 = BN_CTX_get(pBStack_168);
    pBVar7 = BN_CTX_get(pBStack_168);
    a = BN_CTX_get(pBStack_168);
    pBVar8 = BN_CTX_get(pBStack_168);
    a_00 = BN_CTX_get(pBStack_168);
    pBStack_13c = BN_CTX_get(pBStack_168);
    pBVar9 = BN_value_one();
    iVar10 = BN_lshift(pBStack_13c,pBVar9,uVar19);
    pBStack_158 = pBVar4;
    if (iVar10 == 0) goto LAB_0051479c;
    iStack_148 = 0;
    puVar17 = (undefined *)((int)&num[-1].flags + 3);
    iVar10 = ((uint)&num[-1].flags >> 2) + 1;
    puVar18 = (undefined *)((int)&num[-1].flags + 2);
    do {
      iVar11 = BN_GENCB_call((BN_GENCB *)local_44,0,iStack_148);
      pBStack_150 = pBVar7;
      pBStack_124 = a_00;
      pBStack_120 = pBVar21;
      iStack_11c = iVar3;
      if (iVar11 == 0) goto LAB_0051479c;
      pBStack_158 = &BStack_114;
      if (local_54 == (BN_MONT_CTX *)0x0) {
        RAND_pseudo_bytes((uchar *)pBStack_158,(int)num);
      }
      (*(code *)PTR___memcpy_chk_006aab54)(auStack_d4,pBStack_158,num,0x20);
      (*(code *)PTR___memcpy_chk_006aab54)(&uStack_b4,pBStack_158,num,0x20);
      if ((puVar17 != (undefined *)0xffffffff) &&
         (cVar1 = auStack_d4[(int)puVar17], auStack_d4[(int)puVar17] = cVar1 + '\x01',
         (char)(cVar1 + '\x01') == '\0')) {
        pcVar16 = auStack_d4 + (int)puVar18;
        do {
          if (pcVar16 == (char *)((int)&uStack_d8 + 3)) break;
          cVar1 = *pcVar16;
          *pcVar16 = cVar1 + '\x01';
          pcVar16 = pcVar16 + -1;
        } while ((char)(cVar1 + '\x01') == '\0');
      }
      iVar11 = (*(code *)PTR_EVP_Digest_006a8b04)(pBStack_158,num,&uStack_f4,0,pBStack_184,0);
      if (iVar11 == 0) goto LAB_0051479c;
      iVar11 = (*(code *)PTR_EVP_Digest_006a8b04)(auStack_d4,num,&uStack_b4,0,pBStack_184,0);
      if (iVar11 == 0) goto LAB_0051479c;
      if (num != (BN_MONT_CTX *)0x0) {
        if (puVar17 < (undefined *)0x3) {
          pBVar14 = (BN_MONT_CTX *)0x0;
        }
        else {
          uStack_f4 = uStack_b4 ^ uStack_f4;
          if (((((iVar10 != 1) && (uStack_f0 = uStack_b0 ^ uStack_f0, iVar10 != 2)) &&
               (uStack_ec = uStack_ec ^ uStack_ac, iVar10 != 3)) &&
              ((uStack_e8 = uStack_e8 ^ uStack_a8, iVar10 != 4 &&
               (uStack_e4 = uStack_e4 ^ uStack_a4, iVar10 != 5)))) &&
             ((uStack_e0 = uStack_e0 ^ uStack_a0, iVar10 != 6 &&
              (uStack_dc = uStack_dc ^ uStack_9c, iVar10 != 7)))) {
            uStack_d8 = uStack_d8 ^ uStack_98;
          }
          pBVar14 = (BN_MONT_CTX *)(iVar10 * 4);
          if (num == (BN_MONT_CTX *)(iVar10 * 4)) goto LAB_00514484;
        }
        puVar15 = (undefined *)((int)&pBVar14->ri + 1);
        *(byte *)((int)&uStack_f4 + (int)pBVar14) =
             *(byte *)((int)&uStack_b4 + (int)pBVar14) ^ *(byte *)((int)&uStack_f4 + (int)pBVar14);
        if ((int)puVar15 < (int)num) {
          puVar12 = (undefined *)((int)&pBVar14->ri + 2);
          *(byte *)((int)&uStack_f4 + (int)puVar15) =
               *(byte *)((int)&uStack_b4 + (int)puVar15) ^ *(byte *)((int)&uStack_f4 + (int)puVar15)
          ;
          if ((int)puVar12 < (int)num) {
            *(byte *)((int)&uStack_f4 + (int)puVar12) =
                 *(byte *)((int)&uStack_f4 + (int)puVar12) ^
                 *(byte *)((int)&uStack_b4 + (int)puVar12);
          }
        }
      }
LAB_00514484:
      uStack_f4 = uStack_f4 | 0x80000000;
      *(byte *)((int)&uStack_f4 + (int)puVar17) = *(byte *)((int)&uStack_f4 + (int)puVar17) | 1;
      pBVar9 = BN_bin2bn((uchar *)&uStack_f4,(int)num,pBVar7);
      if (pBVar9 == (BIGNUM *)0x0) goto LAB_0051479c;
      iVar11 = BN_is_prime_fasttest_ex
                         (pBVar7,0x32,pBStack_168,(uint)(local_54 == (BN_MONT_CTX *)0x0),
                          (BN_GENCB *)local_44);
      if (0 < iVar11) {
        iVar11 = BN_GENCB_call((BN_GENCB *)local_44,2,0);
        if (iVar11 == 0) goto LAB_0051479c;
        iVar11 = BN_GENCB_call((BN_GENCB *)local_44,3,0);
        if (iVar11 == 0) goto LAB_0051479c;
        iStack_144 = 0;
        do {
          iVar11 = 0;
          BN_set_word(pBVar4,0);
          iVar20 = 0;
          do {
            if ((puVar17 != (undefined *)0xffffffff) &&
               (cVar1 = auStack_d4[(int)puVar17], auStack_d4[(int)puVar17] = cVar1 + '\x01',
               (char)(cVar1 + '\x01') == '\0')) {
              pcVar16 = auStack_d4 + (int)puVar18;
              do {
                if ((char *)((int)&uStack_d8 + 3) == pcVar16) break;
                cVar1 = *pcVar16;
                *pcVar16 = cVar1 + '\x01';
                pcVar16 = pcVar16 + -1;
              } while ((char)(cVar1 + '\x01') == '\0');
            }
            iVar13 = (*(code *)PTR_EVP_Digest_006a8b04)(auStack_d4,num,&uStack_f4,0,pBStack_184,0);
            if (iVar13 == 0) goto LAB_0051479c;
            pBVar9 = BN_bin2bn((uchar *)&uStack_f4,(int)num,pBStack_140);
            if (pBVar9 == (BIGNUM *)0x0) goto LAB_0051479c;
            iVar13 = BN_lshift(pBStack_140,pBStack_140,iVar11);
            if (iVar13 == 0) goto LAB_0051479c;
            iVar13 = (*(code *)PTR_BN_add_006a96c8)(pBVar4,pBVar4,pBStack_140);
            if (iVar13 == 0) goto LAB_0051479c;
            iVar20 = iVar20 + 1;
            iVar11 = iVar11 + ((uint)in_a2 & 0xfffffff8);
          } while (iVar20 <= (int)(uVar19 / 0xa0));
          iVar11 = BN_mask_bits(pBVar4,uVar19);
          if (iVar11 == 0) goto LAB_0051479c;
          pBVar9 = BN_copy(a,pBVar4);
          if (pBVar9 == (BIGNUM *)0x0) goto LAB_0051479c;
          iVar11 = (*(code *)PTR_BN_add_006a96c8)(a,a,pBStack_13c);
          if (iVar11 == 0) goto LAB_0051479c;
          iVar11 = BN_lshift1(pBStack_140,pBVar7);
          if (iVar11 == 0) goto LAB_0051479c;
          iVar11 = (*(code *)PTR_BN_div_006a967c)(0,pBVar8,a,pBStack_140,pBStack_168);
          if (iVar11 == 0) goto LAB_0051479c;
          pBVar9 = BN_value_one();
          iVar11 = (*(code *)PTR_BN_sub_006a96cc)(pBStack_140,pBVar8,pBVar9);
          if (iVar11 == 0) goto LAB_0051479c;
          iVar11 = (*(code *)PTR_BN_sub_006a96cc)(a_00,a,pBStack_140);
          if (iVar11 == 0) goto LAB_0051479c;
          iVar11 = BN_cmp(a_00,pBStack_13c);
          if (-1 < iVar11) {
            iVar11 = BN_is_prime_fasttest_ex(a_00,0x32,pBStack_168,1,(BN_GENCB *)local_44);
            if (0 < iVar11) goto LAB_0051484c;
            if (iVar11 != 0) goto LAB_0051479c;
          }
          iStack_144 = iStack_144 + 1;
          if (iStack_144 == 0x1000) goto LAB_005144ec;
          iVar11 = BN_GENCB_call((BN_GENCB *)local_44,0,iStack_144);
          if (iVar11 == 0) goto LAB_0051479c;
        } while( true );
      }
      if (iVar11 != 0) goto LAB_0051479c;
LAB_005144ec:
      local_54 = (BN_MONT_CTX *)0x0;
      iStack_148 = iStack_148 + 1;
    } while( true );
  }
  pBVar6 = (BN_BLINDING *)0x0;
LAB_00513fe0:
  do {
    if (iStack_94 == *(int *)puVar2) {
      return pBVar6;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0051484c:
    iVar3 = BN_GENCB_call((BN_GENCB *)local_44,2,1);
    if (iVar3 != 0) {
      pBVar21 = BN_value_one();
      iVar3 = (*(code *)PTR_BN_sub_006a96cc)(pBStack_13c,pBStack_124,pBVar21);
      if ((((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_BN_div_006a967c)
                              (pBStack_140,0,pBStack_13c,pBStack_150,pBStack_168), iVar3 != 0)) &&
          (iVar3 = BN_set_word(pBStack_13c,2), iVar3 != 0)) &&
         (iVar3 = BN_MONT_CTX_set(pBStack_154,pBStack_124,pBStack_168), iVar3 != 0)) {
        puVar22 = (ulong *)0x2;
        while (iVar3 = (*(code *)PTR_BN_mod_exp_mont_006a96f4)
                                 (pBStack_120,pBStack_13c,pBStack_140,pBStack_124,pBStack_168,
                                  pBStack_154), iVar3 != 0) {
          if (((pBStack_120->top != 1) || (*pBStack_120->d != 1)) || (pBStack_120->neg != 0)) {
            iVar3 = BN_GENCB_call((BN_GENCB *)local_44,3,1);
            if (iVar3 != 0) {
              if (*(BIGNUM **)(iStack_11c + 0xc) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(iStack_11c + 0xc));
              }
              if (*(BIGNUM **)(iStack_11c + 0x10) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(iStack_11c + 0x10));
              }
              if (*(BIGNUM **)(iStack_11c + 0x14) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(iStack_11c + 0x14));
              }
              pBVar21 = BN_dup(pBStack_124);
              *(BIGNUM **)(iStack_11c + 0xc) = pBVar21;
              pBVar21 = BN_dup(pBStack_150);
              *(BIGNUM **)(iStack_11c + 0x10) = pBVar21;
              pBVar21 = BN_dup(pBStack_120);
              *(BIGNUM **)(iStack_11c + 0x14) = pBVar21;
              if (*(int *)(iStack_11c + 0xc) != 0) {
                pBVar6 = (BN_BLINDING *)0x0;
                if ((*(int *)(iStack_11c + 0x10) != 0) && (pBVar21 != (BIGNUM *)0x0)) {
                  if (piStack_4c != (int *)0x0) {
                    *piStack_4c = iStack_144;
                  }
                  if (local_48 != (BIGNUM *)0x0) {
                    local_48->d = puVar22;
                  }
                  pBVar6 = (BN_BLINDING *)0x1;
                  (*(code *)PTR_memcpy_006aabf4)(&_gp,pBStack_158,num);
                }
                goto LAB_005147a0;
              }
            }
            break;
          }
          pBVar21 = BN_value_one();
          iVar3 = (*(code *)PTR_BN_add_006a96c8)(pBStack_13c,pBStack_13c,pBVar21);
          if (iVar3 == 0) break;
          puVar22 = (ulong *)((int)puVar22 + 1);
        }
      }
    }
LAB_0051479c:
    pBVar6 = (BN_BLINDING *)0x0;
LAB_005147a0:
    BN_CTX_end(pBStack_168);
    BN_CTX_free(pBStack_168);
    if (pBStack_154 != (BN_MONT_CTX *)0x0) {
      BN_MONT_CTX_free(pBStack_154);
    }
  } while( true );
}

