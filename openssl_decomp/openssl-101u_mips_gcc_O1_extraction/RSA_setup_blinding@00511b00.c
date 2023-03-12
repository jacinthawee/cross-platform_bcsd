
/* WARNING: Removing unreachable block (ram,0x00512a48) */

BN_BLINDING * RSA_setup_blinding(RSA *rsa,BN_CTX *ctx)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  EVP_MD *pEVar4;
  undefined4 uVar5;
  BN_BLINDING *pBVar6;
  undefined *n;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  BIGNUM *r;
  BIGNUM *pBVar10;
  EVP_MD *pEVar11;
  int iVar12;
  int iVar13;
  undefined *puVar14;
  int iVar15;
  BN_MONT_CTX *pBVar16;
  undefined *puVar17;
  undefined *puVar18;
  char *pcVar19;
  BN_BLINDING *pBVar20;
  undefined *puVar21;
  BIGNUM *in_a2;
  char *in_a3;
  EVP_MD *ret;
  EVP_MD *unaff_s2;
  BIGNUM *unaff_s3;
  BIGNUM *pBVar22;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  BIGNUM *unaff_s8;
  BN_MONT_CTX *count;
  double in_f12_13;
  EVP_MD *pEStack_184;
  _func_1623 *p_Stack_174;
  BN_MONT_CTX *pBStack_158;
  EVP_MD *pEStack_154;
  uchar *puStack_150;
  int iStack_144;
  int iStack_140;
  uchar auStack_114 [32];
  undefined auStack_f4 [2];
  byte abStack_f2 [2];
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
  EVP_MD *pEStack_88;
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
  EVP_MD *local_48;
  BIGNUM *local_44;
  BIGNUM local_40;
  BN_BLINDING *local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(BN_BLINDING **)PTR___stack_chk_guard_006a9ae8;
  ret = (EVP_MD *)ctx;
  if ((ctx == (BN_CTX *)0x0) &&
     (pBVar22 = (BIGNUM *)ctx, ret = (EVP_MD *)BN_CTX_new(), ret == (EVP_MD *)0x0)) {
    pEVar4 = (EVP_MD *)0x0;
  }
  else {
    BN_CTX_start((BN_CTX *)ret);
    unaff_s3 = BN_CTX_get((BN_CTX *)ret);
    if (unaff_s3 == (BIGNUM *)0x0) {
      in_a2 = (BIGNUM *)&DAT_00000041;
      in_stack_ffffffa8 = (_func_1623 *)&DAT_000000cc;
LAB_00511db4:
      in_a3 = "rsa_crpt.c";
      pBVar22 = (BIGNUM *)&DAT_00000088;
      pEVar4 = (EVP_MD *)0x0;
      ERR_put_error(4,0x88,(int)in_a2,"rsa_crpt.c",(int)in_stack_ffffffa8);
    }
    else {
      pBVar22 = rsa->e;
      unaff_s3 = pBVar22;
      if (pBVar22 == (BIGNUM *)0x0) {
        unaff_s6 = rsa->d;
        unaff_s7 = rsa->p;
        pBVar7 = rsa->q;
        if (((unaff_s6 != (BIGNUM *)0x0) && (unaff_s7 != (BIGNUM *)0x0)) &&
           (pBVar7 != (BIGNUM *)0x0)) {
          BN_CTX_start((BN_CTX *)ret);
          local_44 = BN_CTX_get((BN_CTX *)ret);
          local_48 = (EVP_MD *)BN_CTX_get((BN_CTX *)ret);
          unaff_s8 = BN_CTX_get((BN_CTX *)ret);
          if (unaff_s8 != (BIGNUM *)0x0) {
            pBVar8 = BN_value_one();
            iVar3 = (*(code *)PTR_BN_sub_006a85a8)(local_48,unaff_s7,pBVar8);
            if (iVar3 != 0) {
              pBVar8 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s8,pBVar7,pBVar8);
              if ((iVar3 != 0) &&
                 (iVar3 = BN_mul(local_44,(BIGNUM *)local_48,unaff_s8,(BN_CTX *)ret), iVar3 != 0)) {
                unaff_s3 = (BIGNUM *)(*(code *)PTR_BN_mod_inverse_006a85f0)(0,unaff_s6,local_44,ret)
                ;
                BN_CTX_end((BN_CTX *)ret);
                if (unaff_s3 != (BIGNUM *)0x0) goto LAB_00511b8c;
                goto LAB_00511da4;
              }
            }
          }
          BN_CTX_end((BN_CTX *)ret);
        }
LAB_00511da4:
        in_a2 = (BIGNUM *)&DAT_0000008c;
        in_stack_ffffffa8 = (_func_1623 *)0xd3;
        unaff_s3 = pBVar22;
        goto LAB_00511db4;
      }
LAB_00511b8c:
      iVar3 = RAND_status();
      if (((iVar3 == 0) && (pBVar22 = rsa->d, pBVar22 != (BIGNUM *)0x0)) &&
         (pBVar22->d != (ulong *)0x0)) {
        RAND_add(pBVar22->d,pBVar22->dmax << 2,in_f12_13);
      }
      in_a2 = &local_40;
      if ((rsa->flags & 0x100U) == 0) {
        pBVar22 = rsa->n;
        local_40.d = pBVar22->d;
        local_40.top = pBVar22->top;
        local_40.dmax = pBVar22->dmax;
        local_40.neg = pBVar22->neg;
        local_40.flags = local_40.flags & 1U | pBVar22->flags & 0xfffffffeU | 6;
      }
      else {
        in_a2 = rsa->n;
      }
      local_54 = rsa->_method_mod_n;
      in_stack_ffffffa8 = rsa->meth->bn_mod_exp;
      pBVar22 = unaff_s3;
      in_a3 = (char *)ret;
      pEVar4 = (EVP_MD *)(*(code *)PTR_BN_BLINDING_create_param_006a8740)(0);
      if (pEVar4 == (EVP_MD *)0x0) {
        in_a2 = (BIGNUM *)0x0;
        in_a3 = "rsa_crpt.c";
        in_stack_ffffffa8 = (_func_1623 *)0xeb;
        pBVar22 = (BIGNUM *)&DAT_00000088;
        ERR_put_error(4,0x88,3,"rsa_crpt.c",0xeb);
      }
      else {
        uVar5 = (*(code *)PTR_BN_BLINDING_thread_id_006a86dc)(pEVar4);
        (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(uVar5);
      }
    }
    BN_CTX_end((BN_CTX *)ret);
    if (ctx == (BN_CTX *)0x0) {
      BN_CTX_free((BN_CTX *)ret);
    }
    unaff_s2 = pEVar4;
    if (rsa->e == (BIGNUM *)0x0) {
      BN_free(unaff_s3);
      local_48 = pEVar4;
    }
  }
  if (local_2c == *(BN_BLINDING **)puStack_7c) {
    return (BN_BLINDING *)pEVar4;
  }
  uStack_6c = 0x511ed8;
  pBVar20 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  count = (BN_MONT_CTX *)((uint)in_a2 >> 3);
  iStack_94 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pBVar7 = unaff_s3;
  pRStack_90 = rsa;
  uStack_8c = ret;
  pEStack_88 = unaff_s2;
  pBStack_84 = unaff_s3;
  pBStack_80 = ctx;
  pBStack_78 = unaff_s6;
  pBStack_74 = unaff_s7;
  pBStack_70 = unaff_s8;
  if ((((uint)count & 0xfffffff7) != 0x14) &&
     (pBVar6 = (BN_BLINDING *)0x0, count != (BN_MONT_CTX *)&DAT_00000020)) goto LAB_00511f80;
  pEStack_184 = (EVP_MD *)in_a3;
  if ((EVP_MD *)in_a3 == (EVP_MD *)0x0) {
    pEStack_184 = (EVP_MD *)(*(code *)PTR_EVP_sha1_006a75d0)();
  }
  if (pBVar22 < (BIGNUM *)0x200) {
    ret = (EVP_MD *)0x200;
    if (local_54 != (BN_MONT_CTX *)0x0) goto LAB_00511fe4;
LAB_0051202c:
    if (in_stack_ffffffa8 != (_func_1623 *)0x0) {
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_114,in_stack_ffffffa8,local_54,0x20);
    }
    pBStack_158 = BN_MONT_CTX_new();
  }
  else {
    ret = (EVP_MD *)((uint)((int)&pBVar22[3].d + 3) & 0xffffffc0);
    if (local_54 == (BN_MONT_CTX *)0x0) goto LAB_0051202c;
LAB_00511fe4:
    if (count <= local_54) {
      if (count < local_54) {
        local_54 = count;
      }
      goto LAB_0051202c;
    }
    p_Stack_174 = (_func_1623 *)0x0;
    if (count < local_54) {
      local_54 = count;
    }
    pBStack_158 = BN_MONT_CTX_new();
    in_stack_ffffffa8 = p_Stack_174;
  }
  if (pBStack_158 != (BN_MONT_CTX *)0x0) {
    pEVar4 = (EVP_MD *)BN_CTX_new();
    pEStack_154 = pEVar4;
    if (pEVar4 == (EVP_MD *)0x0) {
      pBVar6 = (BN_BLINDING *)0x0;
      goto LAB_00512778;
    }
    n = (undefined *)((int)&ret[-1].md_ctrl + 3);
    BN_CTX_start((BN_CTX *)pEVar4);
    pBVar22 = BN_CTX_get((BN_CTX *)pEVar4);
    pBVar7 = BN_CTX_get((BN_CTX *)pEVar4);
    ctx = (BN_CTX *)BN_CTX_get((BN_CTX *)pEVar4);
    ret = (EVP_MD *)BN_CTX_get((BN_CTX *)pEVar4);
    pBVar8 = BN_CTX_get((BN_CTX *)pEVar4);
    pBVar9 = BN_CTX_get((BN_CTX *)pEVar4);
    unaff_s2 = (EVP_MD *)BN_CTX_get((BN_CTX *)pEVar4);
    r = BN_CTX_get((BN_CTX *)pEVar4);
    pBVar10 = BN_value_one();
    iVar3 = BN_lshift(r,pBVar10,(int)n);
    pEVar11 = unaff_s2;
    unaff_s3 = pBVar7;
    if (iVar3 == 0) goto LAB_00512750;
    iStack_144 = 0;
    puVar21 = (undefined *)((int)&count[-1].flags + 3);
    iVar3 = ((uint)&count[-1].flags >> 2) + 1;
    puVar17 = (undefined *)((int)&count[-1].flags + 2);
    puStack_150 = auStack_114;
    pEVar11 = (EVP_MD *)((int)&pRStack_90 + (int)puVar21);
    do {
      iVar12 = BN_GENCB_call((BN_GENCB *)local_44,0,iStack_144);
      if (iVar12 == 0) goto LAB_00512750;
      if ((local_54 == (BN_MONT_CTX *)0x0) || (iVar12 = 0, in_stack_ffffffa8 == (_func_1623 *)0x0))
      {
        iVar12 = RAND_bytes(puStack_150,(int)count);
        if (iVar12 < 1) goto LAB_00512750;
        iVar12 = 1;
      }
      else {
        local_54 = (BN_MONT_CTX *)0x0;
      }
      (*(code *)PTR___memcpy_chk_006a9a48)(auStack_d4,puStack_150,count,0x20);
      (*(code *)PTR___memcpy_chk_006a9a48)(&uStack_b4,puStack_150,count,0x20);
      if ((puVar21 != (undefined *)0xffffffff) &&
         (cVar1 = auStack_d4[(int)puVar21], auStack_d4[(int)puVar21] = cVar1 + '\x01',
         (char)(cVar1 + '\x01') == '\0')) {
        pcVar19 = auStack_d4 + (int)puVar17;
        do {
          if (pcVar19 == (char *)((int)&uStack_d8 + 3)) break;
          cVar1 = *pcVar19;
          *pcVar19 = cVar1 + '\x01';
          pcVar19 = pcVar19 + -1;
        } while ((char)(cVar1 + '\x01') == '\0');
      }
      unaff_s3 = (BIGNUM *)auStack_f4;
      iVar13 = (*(code *)PTR_EVP_Digest_006a7a14)(puStack_150,count,unaff_s3,0,pEStack_184,0);
      if (iVar13 == 0) goto LAB_00512750;
      iVar13 = (*(code *)PTR_EVP_Digest_006a7a14)(auStack_d4,count,&uStack_b4,0,pEStack_184,0);
      if (iVar13 == 0) goto LAB_00512750;
      if (count != (BN_MONT_CTX *)0x0) {
        if (puVar21 < (undefined *)0x3) {
          pBVar16 = (BN_MONT_CTX *)0x0;
        }
        else {
          _auStack_f4 = (ulong *)(uStack_b4 ^ (uint)_auStack_f4);
          if (((((iVar3 != 1) && (uStack_f0 = uStack_b0 ^ uStack_f0, iVar3 != 2)) &&
               (uStack_ec = uStack_ec ^ uStack_ac, iVar3 != 3)) &&
              ((uStack_e8 = uStack_e8 ^ uStack_a8, iVar3 != 4 &&
               (uStack_e4 = uStack_e4 ^ uStack_a4, iVar3 != 5)))) &&
             ((uStack_e0 = uStack_e0 ^ uStack_a0, iVar3 != 6 &&
              (uStack_dc = uStack_dc ^ uStack_9c, iVar3 != 7)))) {
            uStack_d8 = uStack_d8 ^ uStack_98;
          }
          pBVar16 = (BN_MONT_CTX *)(iVar3 * 4);
          if (count == (BN_MONT_CTX *)(iVar3 * 4)) goto LAB_00512438;
        }
        puVar18 = (undefined *)((int)&pBVar16->ri + 1);
        auStack_f4[(int)pBVar16] =
             auStack_f4[(int)pBVar16] ^ *(byte *)((int)&uStack_b4 + (int)pBVar16);
        if ((int)puVar18 < (int)count) {
          puVar14 = (undefined *)((int)&pBVar16->ri + 2);
          auStack_f4[(int)puVar18] =
               auStack_f4[(int)puVar18] ^ *(byte *)((int)&uStack_b4 + (int)puVar18);
          if ((int)puVar14 < (int)count) {
            auStack_f4[(int)puVar14] =
                 auStack_f4[(int)puVar14] ^ *(byte *)((int)&uStack_b4 + (int)puVar14);
          }
        }
      }
LAB_00512438:
      _auStack_f4 = (ulong *)((uint)_auStack_f4 | 0x80000000);
      auStack_f4[(int)puVar21] = auStack_f4[(int)puVar21] | 1;
      pBVar10 = BN_bin2bn((uchar *)unaff_s3,(int)count,(BIGNUM *)ret);
      if (pBVar10 == (BIGNUM *)0x0) goto LAB_00512750;
      iVar12 = BN_is_prime_fasttest_ex
                         ((BIGNUM *)ret,0x32,(BN_CTX *)pEVar4,iVar12,(BN_GENCB *)local_44);
      if (0 < iVar12) {
        iVar12 = BN_GENCB_call((BN_GENCB *)local_44,2,0);
        if (iVar12 == 0) goto LAB_00512750;
        iVar12 = BN_GENCB_call((BN_GENCB *)local_44,3,0);
        if (iVar12 == 0) goto LAB_00512750;
        iStack_140 = 0;
        do {
          iVar12 = 0;
          BN_set_word((BIGNUM *)ctx,0);
          iVar13 = 0;
          do {
            if ((puVar21 != (undefined *)0xffffffff) &&
               (cVar1 = auStack_d4[(int)puVar21], auStack_d4[(int)puVar21] = cVar1 + '\x01',
               (char)(cVar1 + '\x01') == '\0')) {
              pcVar19 = auStack_d4 + (int)puVar17;
              do {
                if ((char *)((int)&uStack_d8 + 3) == pcVar19) break;
                cVar1 = *pcVar19;
                *pcVar19 = cVar1 + '\x01';
                pcVar19 = pcVar19 + -1;
              } while ((char)(cVar1 + '\x01') == '\0');
            }
            iVar15 = EVP_Digest(auStack_d4,(size_t)count,(uchar *)unaff_s3,(uint *)0x0,pEStack_184,
                                (ENGINE *)0x0);
            if (iVar15 == 0) goto LAB_00512750;
            pBVar10 = BN_bin2bn((uchar *)unaff_s3,(int)count,pBVar22);
            if (pBVar10 == (BIGNUM *)0x0) goto LAB_00512750;
            iVar15 = BN_lshift(pBVar22,pBVar22,iVar12);
            if (iVar15 == 0) goto LAB_00512750;
            iVar15 = (*(code *)PTR_BN_add_006a85a4)(ctx,ctx,pBVar22);
            if (iVar15 == 0) goto LAB_00512750;
            iVar13 = iVar13 + 1;
            iVar12 = iVar12 + ((uint)in_a2 & 0xfffffff8);
          } while (iVar13 <= (int)((uint)n / 0xa0));
          iVar12 = BN_mask_bits((BIGNUM *)ctx,(int)n);
          if (iVar12 == 0) goto LAB_00512750;
          pBVar10 = BN_copy(pBVar8,(BIGNUM *)ctx);
          if (pBVar10 == (BIGNUM *)0x0) goto LAB_00512750;
          iVar12 = (*(code *)PTR_BN_add_006a85a4)(pBVar8,pBVar8,r);
          if (iVar12 == 0) goto LAB_00512750;
          iVar12 = BN_lshift1(pBVar22,(BIGNUM *)ret);
          if (iVar12 == 0) goto LAB_00512750;
          iVar12 = (*(code *)PTR_BN_div_006a855c)(0,pBVar9,pBVar8,pBVar22,pEVar4);
          if (iVar12 == 0) goto LAB_00512750;
          pBVar10 = BN_value_one();
          iVar12 = (*(code *)PTR_BN_sub_006a85a8)(pBVar22,pBVar9,pBVar10);
          if (iVar12 == 0) goto LAB_00512750;
          iVar12 = (*(code *)PTR_BN_sub_006a85a8)(unaff_s2,pBVar8,pBVar22);
          if (iVar12 == 0) goto LAB_00512750;
          iVar12 = BN_cmp((BIGNUM *)unaff_s2,r);
          if (-1 < iVar12) {
            iVar12 = BN_is_prime_fasttest_ex
                               ((BIGNUM *)unaff_s2,0x32,(BN_CTX *)pEVar4,1,(BN_GENCB *)local_44);
            if (0 < iVar12) {
              iVar3 = BN_GENCB_call((BN_GENCB *)local_44,2,1);
              pEVar11 = unaff_s2;
              unaff_s3 = pBVar7;
              if (iVar3 == 0) goto LAB_00512750;
              pBVar8 = BN_value_one();
              iVar3 = (*(code *)PTR_BN_sub_006a85a8)(r,unaff_s2,pBVar8);
              if (iVar3 == 0) goto LAB_00512750;
              iVar3 = (*(code *)PTR_BN_div_006a855c)(pBVar22,0,r,ret,pEVar4);
              if (iVar3 == 0) goto LAB_00512750;
              iVar3 = BN_set_word(r,2);
              if (iVar3 == 0) goto LAB_00512750;
              iVar3 = BN_MONT_CTX_set(pBStack_158,(BIGNUM *)unaff_s2,(BN_CTX *)pEVar4);
              if (iVar3 == 0) goto LAB_00512750;
              ctx = (BN_CTX *)&SUB_00000002;
              do {
                iVar3 = (*(code *)PTR_BN_mod_exp_mont_006a85d0)
                                  (pBVar7,r,pBVar22,unaff_s2,pEVar4,pBStack_158);
                if (iVar3 == 0) goto LAB_00512750;
                if (pBVar7->top != 1) goto LAB_0051294c;
                if (*pBVar7->d != 1) goto LAB_0051294c;
                if (pBVar7->neg != 0) goto LAB_0051294c;
                pBVar8 = BN_value_one();
                iVar3 = (*(code *)PTR_BN_add_006a85a4)(r,r,pBVar8);
                if (iVar3 == 0) goto LAB_00512750;
                ctx = (BN_CTX *)((int)&((BIGNUM *)ctx)->d + 1);
              } while( true );
            }
            pBVar6 = (BN_BLINDING *)0x0;
            if (iVar12 != 0) goto LAB_00512754;
          }
          iStack_140 = iStack_140 + 1;
          if (iStack_140 == 0x1000) goto LAB_005124a0;
          iVar12 = BN_GENCB_call((BN_GENCB *)local_44,0,iStack_140);
          if (iVar12 == 0) goto LAB_00512750;
        } while( true );
      }
      pBVar6 = (BN_BLINDING *)0x0;
      if (iVar12 != 0) goto LAB_00512754;
LAB_005124a0:
      iStack_144 = iStack_144 + 1;
    } while( true );
  }
  pBVar6 = (BN_BLINDING *)0x0;
LAB_00511f80:
  do {
    if (iStack_94 == *(int *)puVar2) {
      return pBVar6;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0051294c:
    iVar3 = BN_GENCB_call((BN_GENCB *)local_44,3,1);
    pEVar11 = unaff_s2;
    unaff_s3 = pBVar7;
    if (iVar3 == 0) {
LAB_00512750:
      pBVar6 = (BN_BLINDING *)0x0;
    }
    else {
      if (*(BIGNUM **)(pBVar20 + 0xc) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(pBVar20 + 0xc));
      }
      if (*(BIGNUM **)(pBVar20 + 0x10) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(pBVar20 + 0x10));
      }
      if (*(BIGNUM **)(pBVar20 + 0x14) != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(pBVar20 + 0x14));
      }
      pBVar22 = BN_dup((BIGNUM *)unaff_s2);
      *(BIGNUM **)(pBVar20 + 0xc) = pBVar22;
      pBVar22 = BN_dup((BIGNUM *)ret);
      *(BIGNUM **)(pBVar20 + 0x10) = pBVar22;
      pBVar22 = BN_dup(pBVar7);
      *(BIGNUM **)(pBVar20 + 0x14) = pBVar22;
      if (*(int *)(pBVar20 + 0xc) == 0) goto LAB_00512750;
      pBVar6 = (BN_BLINDING *)0x0;
      if ((*(int *)(pBVar20 + 0x10) != 0) && (pBVar22 != (BIGNUM *)0x0)) {
        if (piStack_4c != (int *)0x0) {
          *piStack_4c = iStack_140;
        }
        if (local_48 != (EVP_MD *)0x0) {
          local_48->type = (int)ctx;
        }
        pBVar6 = (BN_BLINDING *)0x1;
        (*(code *)PTR_memcpy_006a9aec)(&_gp,puStack_150,count);
      }
    }
LAB_00512754:
    BN_CTX_end((BN_CTX *)pEStack_154);
    BN_CTX_free((BN_CTX *)pEStack_154);
    ret = pEStack_154;
    pEVar4 = pEVar11;
LAB_00512778:
    BN_MONT_CTX_free(pBStack_158);
    pBVar20 = pBVar6;
    unaff_s2 = pEVar4;
    pBVar7 = unaff_s3;
  } while( true );
}

