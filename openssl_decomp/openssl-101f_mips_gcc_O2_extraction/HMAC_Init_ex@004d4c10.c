
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  undefined *puVar1;
  int iVar2;
  uchar *puVar3;
  EVP_MD *pEVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  EVP_MD *pEVar9;
  EVP_MD **ppEVar10;
  EVP_MD **ppEVar11;
  uchar *unaff_s6;
  EVP_MD **ppEVar12;
  code *pcVar13;
  EVP_MD *pEVar14;
  uint auStack_17c [32];
  uint auStack_fc [2];
  HMAC_CTX *pHStack_f4;
  EVP_MD *pEStack_f0;
  undefined *puStack_ec;
  EVP_MD *pEStack_e8;
  ENGINE *pEStack_e4;
  HMAC_CTX *pHStack_e0;
  uchar *puStack_dc;
  EVP_MD_CTX *pEStack_d8;
  code *pcStack_d4;
  undefined *local_c0;
  int local_b4;
  EVP_MD local_ac;
  EVP_MD **local_2c;
  
  puStack_ec = PTR___stack_chk_guard_006aabf0;
  local_c0 = &_gp;
  local_2c = *(EVP_MD ***)PTR___stack_chk_guard_006aabf0;
  pEStack_f0 = md;
  pEStack_e8 = (EVP_MD *)len;
  if (md == (EVP_MD *)0x0) {
    if (key != (void *)0x0) {
      pEStack_f0 = ctx->md;
      goto LAB_004d4c74;
    }
LAB_004d4e18:
    pEStack_d8 = &ctx->i_ctx;
    pEVar9 = (EVP_MD *)pEStack_d8;
    iVar2 = (**(code **)(local_c0 + -0x6cb4))(&ctx->md_ctx);
    uVar8 = (uint)(iVar2 != 0);
  }
  else {
    ctx->md = md;
    if (key == (void *)0x0) {
LAB_004d4cec:
      unaff_s6 = ctx->key;
      key = ctx + 1;
      puVar3 = unaff_s6;
      pEVar9 = &local_ac;
      do {
        uVar8 = *(uint *)puVar3;
        puVar3 = puVar3 + 4;
        pEVar9->type = (int)(uVar8 ^ 0x36363636);
        pEVar9 = (EVP_MD *)&pEVar9->pkey_type;
      } while (puVar3 != (uchar *)key);
      pEStack_d8 = &ctx->i_ctx;
      pEVar9 = pEStack_f0;
      pEVar4 = (EVP_MD *)impl;
      iVar2 = (**(code **)(local_c0 + -0x7870))(pEStack_d8);
      pEStack_e8 = &local_ac;
      if (iVar2 != 0) {
        pEVar4 = (EVP_MD *)(**(code **)(local_c0 + -0x6900))(pEStack_f0);
        pEVar9 = &local_ac;
        iVar2 = (**(code **)(local_c0 + -0x786c))(pEStack_d8);
        pEVar14 = &local_ac;
        if (iVar2 != 0) {
          do {
            uVar8 = *(uint *)unaff_s6;
            unaff_s6 = unaff_s6 + 4;
            pEVar14->type = (int)(uVar8 ^ 0x5c5c5c5c);
            pEVar14 = (EVP_MD *)&pEVar14->pkey_type;
          } while (unaff_s6 != (uchar *)key);
          key = &ctx->o_ctx;
          pEVar9 = pEStack_f0;
          pEVar4 = (EVP_MD *)impl;
          iVar2 = (**(code **)(local_c0 + -0x7870))(key);
          if (iVar2 != 0) {
            len = (**(code **)(local_c0 + -0x6900))(pEStack_f0);
            pEVar9 = &local_ac;
            iVar2 = (**(code **)(local_c0 + -0x786c))(key);
            pEVar4 = (EVP_MD *)len;
            if (iVar2 != 0) goto LAB_004d4e18;
          }
        }
      }
    }
    else {
LAB_004d4c74:
      iVar2 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(pEStack_f0);
      if (iVar2 < 0x81) {
        pcVar13 = *(code **)(local_c0 + -0x7870);
        if (iVar2 < len) goto LAB_004d4e34;
LAB_004d4c98:
        if (0x80 < (uint)len) {
          OpenSSLDie("hmac.c",0x75,"len>=0 && len<=(int)sizeof(ctx->key)");
        }
        (**(code **)(local_c0 + -0x52ec))(ctx->key,key,len);
        ctx->key_length = len;
LAB_004d4cc8:
        if (len != 0x80) {
          (**(code **)(local_c0 + -0x53e0))(ctx->key + len,0,0x80 - len);
        }
        goto LAB_004d4cec;
      }
      local_b4 = iVar2;
      OpenSSLDie("hmac.c",0x68,"j <= (int)sizeof(ctx->key)");
      if (len <= local_b4) goto LAB_004d4c98;
      pcVar13 = *(code **)(local_c0 + -0x7870);
LAB_004d4e34:
      pEStack_d8 = &ctx->md_ctx;
      pEVar9 = pEStack_f0;
      pEVar4 = (EVP_MD *)impl;
      iVar2 = (*pcVar13)(pEStack_d8);
      if ((iVar2 != 0) &&
         (pEVar9 = (EVP_MD *)key, pEVar4 = (EVP_MD *)len,
         iVar2 = (**(code **)(local_c0 + -0x786c))(pEStack_d8), iVar2 != 0)) {
        unaff_s6 = ctx->key;
        pEVar4 = (EVP_MD *)&ctx->key_length;
        pEVar9 = (EVP_MD *)unaff_s6;
        iVar2 = (**(code **)(local_c0 + -0x7868))(pEStack_d8);
        if (iVar2 != 0) {
          len = ctx->key_length;
          goto LAB_004d4cc8;
        }
      }
    }
    uVar8 = 0;
    len = (int)pEVar4;
  }
  if (local_2c == *(EVP_MD ***)puStack_ec) {
    return uVar8;
  }
  pcStack_d4 = HMAC_Init;
  ppEVar10 = local_2c;
  (**(code **)(local_c0 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pEStack_e4 = impl;
  auStack_fc[0] = *(uint *)PTR___stack_chk_guard_006aabf0;
  pHStack_f4 = ctx;
  pHStack_e0 = (HMAC_CTX *)key;
  puStack_dc = unaff_s6;
  if (pEVar9 == (EVP_MD *)0x0) {
    if (md != (EVP_MD *)0x0) {
      *ppEVar10 = md;
      goto LAB_004d5014;
    }
LAB_004d513c:
    iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(ppEVar10 + 1,ppEVar10 + 7);
    uVar8 = (uint)(iVar2 != 0);
  }
  else {
    if (md == (EVP_MD *)0x0) {
      md = *ppEVar10;
    }
    else {
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(ppEVar10 + 7);
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(ppEVar10 + 0xd);
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(ppEVar10 + 1);
      *ppEVar10 = md;
    }
    iVar2 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(md);
    if (iVar2 < 0x81) {
      if (iVar2 < len) goto LAB_004d5158;
LAB_004d4fc0:
      if ((EVP_MD *)&DAT_00000080 < (uint)len) {
        OpenSSLDie("hmac.c",0x75,"len>=0 && len<=(int)sizeof(ctx->key)");
      }
      (*(code *)PTR_memcpy_006aabf4)(ppEVar10 + 0x14,pEVar9,len);
      ppEVar10[0x13] = (EVP_MD *)len;
LAB_004d4ff0:
      if ((EVP_MD *)len != (EVP_MD *)&DAT_00000080) {
        (*(code *)PTR_memset_006aab00)
                  ((undefined *)((int)ppEVar10 + (int)&((EVP_MD *)(len + 0x4c))->pkey_type),0,
                   0x80 - len);
      }
LAB_004d5014:
      ppEVar12 = ppEVar10 + 0x14;
      puVar5 = auStack_17c;
      ppEVar11 = ppEVar12;
      do {
        pEVar9 = *ppEVar11;
        puVar6 = puVar5 + 1;
        ppEVar11 = ppEVar11 + 1;
        *puVar5 = (uint)pEVar9 ^ 0x36363636;
        puVar5 = puVar6;
      } while (puVar6 != auStack_fc);
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(ppEVar10 + 7,md,0);
      if (iVar2 != 0) {
        uVar7 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(md);
        iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(ppEVar10 + 7,auStack_17c,uVar7);
        puVar5 = auStack_17c;
        if (iVar2 != 0) {
          do {
            pEVar9 = *ppEVar12;
            puVar6 = puVar5 + 1;
            ppEVar12 = ppEVar12 + 1;
            *puVar5 = (uint)pEVar9 ^ 0x5c5c5c5c;
            puVar5 = puVar6;
          } while (puVar6 != auStack_fc);
          iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(ppEVar10 + 0xd,md,0);
          if (iVar2 != 0) {
            uVar7 = (*(code *)PTR_EVP_MD_block_size_006a95e0)(md);
            iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(ppEVar10 + 0xd,auStack_17c,uVar7);
            if (iVar2 != 0) goto LAB_004d513c;
          }
        }
      }
    }
    else {
      OpenSSLDie("hmac.c",0x68,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar2) goto LAB_004d4fc0;
LAB_004d5158:
      ppEVar11 = ppEVar10 + 1;
      iVar2 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(ppEVar11,md,0);
      if (((iVar2 != 0) &&
          (iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(ppEVar11,pEVar9,len), iVar2 != 0)) &&
         (iVar2 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)
                            (ppEVar11,ppEVar10 + 0x14,ppEVar10 + 0x13), iVar2 != 0)) {
        len = (int)ppEVar10[0x13];
        goto LAB_004d4ff0;
      }
    }
    uVar8 = 0;
  }
  if (auStack_fc[0] != *(uint *)puVar1) {
    uVar8 = auStack_fc[0];
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x004d5244. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(uVar8 + 4);
    return iVar2;
  }
  return uVar8;
}

