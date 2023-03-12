
BIGNUM * RSA_eay_private_encrypt
                   (BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,int param_5)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BN_CTX *ctx;
  BIGNUM *pBVar4;
  int iVar5;
  uchar *to;
  BIGNUM *pBVar6;
  int iVar7;
  ulong *puVar8;
  BIGNUM *pBVar9;
  BN_MONT_CTX *pBVar10;
  undefined4 uVar11;
  ulong **ppuVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  BIGNUM *unaff_s0;
  BIGNUM *unaff_s1;
  BIGNUM *unaff_s3;
  uchar *unaff_s4;
  BIGNUM *unaff_s5;
  BIGNUM *unaff_s6;
  code *pcVar16;
  int iStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  int iStack_9c;
  BIGNUM *pBStack_98;
  BIGNUM *pBStack_94;
  BIGNUM *pBStack_90;
  BIGNUM *pBStack_8c;
  uchar *puStack_88;
  BIGNUM *pBStack_84;
  BIGNUM *pBStack_80;
  BIGNUM *pBStack_7c;
  undefined *puStack_78;
  code *pcStack_74;
  BIGNUM *local_60;
  int local_5c;
  undefined *local_58;
  BIGNUM *local_50;
  BIGNUM *local_4c;
  int local_44;
  BIGNUM local_40;
  int local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  local_58 = &_gp;
  local_44 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pBVar9 = param_4;
  local_50 = param_2;
  local_4c = param_3;
  pBVar2 = (BIGNUM *)BN_CTX_new();
  if (pBVar2 == (BIGNUM *)0x0) {
    pBStack_90 = (BIGNUM *)0xffffffff;
  }
  else {
    unaff_s6 = (BIGNUM *)(CAST_S_table6 + 0x370);
    BN_CTX_start((BN_CTX *)pBVar2);
    unaff_s3 = BN_CTX_get((BN_CTX *)pBVar2);
    unaff_s5 = BN_CTX_get((BN_CTX *)pBVar2);
    iVar3 = BN_num_bits((BIGNUM *)param_4->flags);
    iVar7 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar7 = iVar3 + 0xe;
    }
    unaff_s0 = (BIGNUM *)(iVar7 >> 3);
    unaff_s4 = (uchar *)(**(code **)(local_58 + -0x7dd8))(unaff_s0,&DAT_006675b8,0x171);
    unaff_s1 = pBVar2;
    if (((unaff_s3 == (BIGNUM *)0x0) || (unaff_s5 == (BIGNUM *)0x0)) || (unaff_s4 == (uchar *)0x0))
    {
      pBVar9 = (BIGNUM *)&DAT_006675b8;
      param_3 = (BIGNUM *)&DAT_00000041;
      param_2 = (BIGNUM *)0x66;
      local_60 = (BIGNUM *)0x174;
      pBStack_90 = (BIGNUM *)0xffffffff;
      (**(code **)(local_58 + -0x6eb0))(4);
      BN_CTX_end((BN_CTX *)pBVar2);
      BN_CTX_free((BN_CTX *)pBVar2);
      if (unaff_s4 == (uchar *)0x0) goto LAB_0050eba0;
      pcVar16 = *(code **)(local_58 + -0x7d6c);
    }
    else {
      if (param_5 == 3) {
        pcVar16 = *(code **)(local_58 + -0x66c8);
LAB_0050ebe4:
        param_3 = local_50;
        pBVar9 = param_1;
        iVar7 = (*pcVar16)(unaff_s4,unaff_s0);
        if ((iVar7 < 1) ||
           (param_3 = unaff_s3, pBVar4 = BN_bin2bn(unaff_s4,(int)unaff_s0,unaff_s3),
           pBVar4 == (BIGNUM *)0x0)) goto LAB_0050eb58;
        iVar7 = BN_ucmp(unaff_s3,(BIGNUM *)param_4->flags);
        if (-1 < iVar7) {
          pcVar16 = *(code **)(local_58 + -0x6eb0);
          param_3 = (BIGNUM *)&DAT_00000084;
          local_60 = (BIGNUM *)0x18f;
          goto LAB_0050eb48;
        }
        puVar8 = param_4[3].d;
        if (((uint)puVar8 & 0x80) == 0) {
          param_1 = (BIGNUM *)rsa_get_blinding(param_4,&local_44,pBVar2);
          if (param_1 == (BIGNUM *)0x0) {
            pcVar16 = *(code **)(local_58 + -0x6eb0);
            param_3 = (BIGNUM *)0x44;
            local_60 = (BIGNUM *)0x198;
            goto LAB_0050eb48;
          }
          if (local_44 == 0) {
            local_50 = BN_CTX_get((BN_CTX *)pBVar2);
            if (local_50 == (BIGNUM *)0x0) {
              pcVar16 = *(code **)(local_58 + -0x6eb0);
              param_3 = (BIGNUM *)&DAT_00000041;
              local_60 = (BIGNUM *)0x1a1;
              goto LAB_0050eb48;
            }
            (**(code **)(local_58 + -0x6c74))(9,0x19,&DAT_006675b8,0x149);
            pBVar4 = (BIGNUM *)(**(code **)(local_58 + -0x66b0))(unaff_s3,local_50,param_1,pBVar2);
            param_3 = (BIGNUM *)&DAT_006675b8;
            pBVar9 = (BIGNUM *)0x14b;
            (**(code **)(local_58 + -0x6c74))(10,0x19);
            unaff_s6 = pBVar4;
          }
          else {
            param_3 = param_1;
            pBVar9 = pBVar2;
            pBVar4 = (BIGNUM *)(**(code **)(local_58 + -0x66b0))(unaff_s3,0);
            local_50 = (BIGNUM *)0x0;
          }
          if (pBVar4 == (BIGNUM *)0x0) goto LAB_0050eb58;
          puVar8 = param_4[3].d;
        }
        else {
          param_1 = (BIGNUM *)0x0;
          local_50 = (BIGNUM *)0x0;
        }
        if ((((uint)puVar8 & 0x20) == 0) &&
           (((param_4[1].dmax == 0 || (param_4[1].neg == 0)) ||
            ((param_4[1].flags == 0 || ((param_4[2].d == (ulong *)0x0 || (param_4[2].top == 0)))))))
           ) {
          if (((uint)puVar8 & 0x100) == 0) {
            unaff_s6 = &local_40;
            BN_init(unaff_s6);
            ppuVar12 = (ulong **)param_4[1].top;
            puVar8 = param_4[3].d;
            local_40.d = *ppuVar12;
            local_40.top = (int)ppuVar12[1];
            local_40.dmax = (int)ppuVar12[2];
            local_40.neg = (int)ppuVar12[3];
            local_40.flags = local_40.flags & 1U | (uint)ppuVar12[4] & 0xfffffffe | 6;
          }
          else {
            unaff_s6 = (BIGNUM *)param_4[1].top;
          }
          if (((uint)puVar8 & 2) != 0) {
            param_3 = (BIGNUM *)param_4->flags;
            pBVar9 = pBVar2;
            pBVar10 = BN_MONT_CTX_set_locked
                                ((BN_MONT_CTX **)&param_4[3].top,9,param_3,(BN_CTX *)pBVar2);
            if (pBVar10 == (BN_MONT_CTX *)0x0) goto LAB_0050eb58;
          }
          local_5c = param_4[3].top;
          pBVar9 = (BIGNUM *)param_4->flags;
          param_3 = unaff_s6;
          local_60 = pBVar2;
          iVar7 = (**(code **)(param_4->dmax + 0x18))(unaff_s5,unaff_s3);
          if (iVar7 != 0) goto LAB_0050ecb8;
          pBStack_90 = (BIGNUM *)0xffffffff;
        }
        else {
          param_3 = param_4;
          pBVar9 = pBVar2;
          iVar7 = (**(code **)(param_4->dmax + 0x14))(unaff_s5,unaff_s3);
          if (iVar7 == 0) goto LAB_0050eb58;
LAB_0050ecb8:
          if ((param_1 != (BIGNUM *)0x0) &&
             (param_3 = param_1, pBVar9 = pBVar2,
             iVar7 = (**(code **)(local_58 + -0x66b8))(unaff_s5,local_50), iVar7 == 0))
          goto LAB_0050eb58;
          if (param_5 == 5) {
            (**(code **)(local_58 + -0x6814))(unaff_s3,param_4->flags,unaff_s5);
            iVar7 = BN_cmp(unaff_s5,unaff_s3);
            if (iVar7 != 0) {
              unaff_s5 = unaff_s3;
            }
          }
          iVar3 = BN_num_bits(unaff_s5);
          pBVar4 = local_4c;
          iVar7 = iVar3 + 7;
          if (iVar3 + 7 < 0) {
            iVar7 = iVar3 + 0xe;
          }
          iVar7 = BN_bn2bin(unaff_s5,(uchar *)((int)local_4c + ((int)unaff_s0 - (iVar7 >> 3))));
          param_3 = (BIGNUM *)((int)unaff_s0 - iVar7);
          pBStack_90 = unaff_s0;
          if (0 < (int)param_3) {
            (**(code **)(local_58 + -0x53e0))(pBVar4,0);
          }
        }
      }
      else {
        if (param_5 == 5) {
          pcVar16 = *(code **)(local_58 + -0x66bc);
          goto LAB_0050ebe4;
        }
        if (param_5 == 1) {
          pcVar16 = *(code **)(local_58 + -0x66b4);
          goto LAB_0050ebe4;
        }
        pcVar16 = *(code **)(local_58 + -0x6eb0);
        param_3 = (BIGNUM *)&DAT_00000076;
        local_60 = (BIGNUM *)0x185;
LAB_0050eb48:
        pBVar9 = (BIGNUM *)&DAT_006675b8;
        (*pcVar16)(4,0x66);
LAB_0050eb58:
        pBStack_90 = (BIGNUM *)0xffffffff;
      }
      BN_CTX_end((BN_CTX *)pBVar2);
      BN_CTX_free((BN_CTX *)pBVar2);
      pcVar16 = *(code **)(local_58 + -0x7d6c);
    }
    param_2 = unaff_s0;
    (*pcVar16)(unaff_s4);
    (**(code **)(local_58 + -0x7f58))(unaff_s4);
  }
LAB_0050eba0:
  if (local_2c == *(int *)puStack_78) {
    return pBStack_90;
  }
  pcStack_74 = RSA_eay_private_decrypt;
  iVar7 = local_2c;
  (**(code **)(local_58 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_b4 = 0;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  pBStack_98 = unaff_s0;
  pBStack_94 = unaff_s1;
  pBStack_8c = unaff_s3;
  puStack_88 = unaff_s4;
  pBStack_84 = unaff_s5;
  pBStack_80 = unaff_s6;
  pBStack_7c = param_1;
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    pBVar9 = (BIGNUM *)0xffffffff;
    goto LAB_0050f26c;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  iVar5 = BN_num_bits((BIGNUM *)pBVar9->flags);
  iVar3 = iVar5 + 7;
  if (iVar5 + 7 < 0) {
    iVar3 = iVar5 + 0xe;
  }
  iVar3 = iVar3 >> 3;
  to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,&DAT_006675b8,0x200);
  if (((pBVar2 == (BIGNUM *)0x0) || (pBVar4 == (BIGNUM *)0x0)) || (to == (uchar *)0x0)) {
    pBVar9 = (BIGNUM *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x65,0x41,&DAT_006675b8,0x203);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) goto LAB_0050f26c;
  }
  else {
    if (iVar3 < iVar7) {
      uVar14 = 0x6c;
      uVar11 = 0x20b;
LAB_0050f47c:
      pBVar9 = (BIGNUM *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x65,uVar14,&DAT_006675b8,uVar11);
    }
    else {
      pBVar6 = BN_bin2bn((uchar *)param_2,iVar7,pBVar2);
      if (pBVar6 == (BIGNUM *)0x0) {
LAB_0050f34c:
        pBVar9 = (BIGNUM *)0xffffffff;
      }
      else {
        iVar7 = BN_ucmp(pBVar2,(BIGNUM *)pBVar9->flags);
        if (-1 < iVar7) {
          uVar14 = 0x84;
          uVar11 = 0x214;
          goto LAB_0050f47c;
        }
        puVar8 = pBVar9[3].d;
        pBVar6 = (BIGNUM *)0x0;
        if (((uint)puVar8 & 0x80) == 0) {
          iVar7 = rsa_get_blinding(pBVar9,&iStack_b4,ctx);
          if (iVar7 == 0) {
            uVar14 = 0x44;
            uVar11 = 0x21d;
            goto LAB_0050f47c;
          }
          if (iStack_b4 == 0) {
            pBVar6 = BN_CTX_get(ctx);
            if (pBVar6 == (BIGNUM *)0x0) {
              uVar14 = 0x41;
              uVar11 = 0x226;
              goto LAB_0050f47c;
            }
            (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x19,&DAT_006675b8,0x149);
            iVar5 = (*(code *)PTR_BN_BLINDING_convert_ex_006a9830)(pBVar2,pBVar6,iVar7,ctx);
            (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x19,&DAT_006675b8,0x14b);
          }
          else {
            iVar5 = (*(code *)PTR_BN_BLINDING_convert_ex_006a9830)(pBVar2,0,iVar7,ctx);
            pBVar6 = (BIGNUM *)0x0;
          }
          if (iVar5 == 0) goto LAB_0050f34c;
          puVar8 = pBVar9[3].d;
        }
        else {
          iVar7 = 0;
        }
        if ((((uint)puVar8 & 0x20) == 0) &&
           (((pBVar9[1].dmax == 0 || (pBVar9[1].neg == 0)) ||
            ((pBVar9[1].flags == 0 || ((pBVar9[2].d == (ulong *)0x0 || (pBVar9[2].top == 0)))))))) {
          puVar15 = &uStack_b0;
          if (((uint)puVar8 & 0x100) == 0) {
            puVar13 = (undefined4 *)pBVar9[1].top;
            uStack_b0 = *puVar13;
            uStack_ac = puVar13[1];
            uStack_a8 = puVar13[2];
            uStack_a4 = puVar13[3];
            uStack_a0 = uStack_a0 & 1 | puVar13[4] & 0xfffffffe | 6;
          }
          else {
            puVar15 = (undefined4 *)pBVar9[1].top;
          }
          if ((((uint)puVar8 & 2) != 0) &&
             (pBVar10 = BN_MONT_CTX_set_locked
                                  ((BN_MONT_CTX **)&pBVar9[3].top,9,(BIGNUM *)pBVar9->flags,ctx),
             pBVar10 == (BN_MONT_CTX *)0x0)) goto LAB_0050f34c;
          iVar5 = (**(code **)(pBVar9->dmax + 0x18))
                            (pBVar4,pBVar2,puVar15,pBVar9->flags,ctx,pBVar9[3].top);
        }
        else {
          iVar5 = (**(code **)(pBVar9->dmax + 0x14))(pBVar4,pBVar2,pBVar9,ctx);
        }
        if ((iVar5 == 0) ||
           ((iVar7 != 0 &&
            (iVar7 = (*(code *)PTR_BN_BLINDING_invert_ex_006a9828)(pBVar4,pBVar6,iVar7,ctx),
            iVar7 == 0)))) goto LAB_0050f34c;
        iVar7 = BN_bn2bin(pBVar4,to);
        pcVar16 = (code *)PTR_RSA_padding_check_SSLv23_006a983c;
        if (local_60 == (BIGNUM *)&SUB_00000002) {
LAB_0050f2bc:
          pBVar9 = (BIGNUM *)(*pcVar16)(param_3,iVar3,to,iVar7,iVar3);
        }
        else {
          if ((int)local_60 < 3) {
            pcVar16 = (code *)PTR_RSA_padding_check_PKCS1_type_2_006a9838;
            if (local_60 != (BIGNUM *)0x1) {
LAB_0050f468:
              uVar14 = 0x76;
              uVar11 = 0x264;
              goto LAB_0050f47c;
            }
            goto LAB_0050f2bc;
          }
          pcVar16 = (code *)PTR_RSA_padding_check_none_006a980c;
          if (local_60 == (BIGNUM *)0x3) goto LAB_0050f2bc;
          if (local_60 != (BIGNUM *)&SUB_00000004) goto LAB_0050f468;
          pBVar9 = (BIGNUM *)
                   RSA_padding_check_PKCS1_OAEP
                             ((uchar *)param_3,iVar3,to,iVar7,iVar3,(uchar *)0x0,0);
        }
        if ((int)pBVar9 < 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x65,0x72,&DAT_006675b8,0x268);
        }
      }
    }
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(to,iVar3);
  (*(code *)PTR_CRYPTO_free_006a7f88)(to);
LAB_0050f26c:
  if (iStack_9c == *(int *)puVar1) {
    return pBVar9;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (BIGNUM *)rsa_pkcs1_eay_meth;
}

