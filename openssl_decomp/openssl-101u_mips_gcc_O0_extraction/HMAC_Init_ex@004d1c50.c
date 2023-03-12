
int HMAC_Init_ex(HMAC_CTX *ctx,void *key,int len,EVP_MD *md,ENGINE *impl)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uchar *puVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  EVP_MD *pEVar8;
  EVP_MD *pEVar9;
  EVP_MD **ppEVar10;
  ENGINE **ppEVar11;
  uchar *unaff_s4;
  EVP_MD **ppEVar12;
  int *piVar13;
  EVP_MD_CTX *unaff_s6;
  _func_1081 **pp_Var14;
  code *pcVar15;
  EVP_MD *apEStack_174 [32];
  EVP_MD *pEStack_f4;
  undefined *puStack_f0;
  ENGINE *pEStack_ec;
  EVP_MD *pEStack_e8;
  EVP_MD *pEStack_e4;
  uchar *puStack_e0;
  EVP_MD *pEStack_dc;
  EVP_MD_CTX *pEStack_d8;
  code *pcStack_d4;
  undefined *local_c0;
  int local_b4;
  EVP_MD local_ac;
  EVP_MD *local_2c [2];
  
  puStack_f0 = PTR___stack_chk_guard_006a9ae8;
  local_c0 = &_gp;
  local_2c[0] = *(EVP_MD **)PTR___stack_chk_guard_006a9ae8;
  pEStack_e8 = (EVP_MD *)len;
  pEStack_e4 = (EVP_MD *)key;
  if (md == (EVP_MD *)0x0) {
    pEStack_dc = ctx->md;
    uVar2 = 0;
    if (pEStack_dc != (EVP_MD *)0x0) {
      if (key != (void *)0x0) goto LAB_004d1ccc;
LAB_004d1f30:
      unaff_s6 = &ctx->i_ctx;
      key = unaff_s6;
      iVar3 = (**(code **)(local_c0 + -0x6cdc))(&ctx->md_ctx);
      uVar2 = (uint)(iVar3 != 0);
    }
  }
  else {
    pEStack_dc = md;
    if (md == ctx->md) {
      unaff_s4 = ctx->key;
      if (key != (void *)0x0) goto LAB_004d1ccc;
LAB_004d1e14:
      unaff_s4 = ctx->key;
      puVar4 = unaff_s4;
      pEVar9 = &local_ac;
      do {
        uVar2 = *(uint *)puVar4;
        puVar4 = puVar4 + 4;
        pEVar9->type = (int)(uVar2 ^ 0x36363636);
        pEVar9 = (EVP_MD *)&pEVar9->pkey_type;
      } while ((HMAC_CTX *)puVar4 != ctx + 1);
      unaff_s6 = &ctx->i_ctx;
      pEVar9 = pEStack_dc;
      pcVar5 = (char *)impl;
      iVar3 = (**(code **)(local_c0 + -0x7864))(unaff_s6);
      pEStack_e8 = &local_ac;
      pEStack_e4 = &local_ac;
      if (iVar3 != 0) {
        pcVar5 = (char *)(**(code **)(local_c0 + -0x6920))(pEStack_dc);
        pEVar9 = &local_ac;
        iVar3 = (**(code **)(local_c0 + -0x7860))(unaff_s6);
        if (iVar3 != 0) {
          pEVar9 = &local_ac;
          do {
            uVar2 = *(uint *)unaff_s4;
            ppEVar11 = (ENGINE **)&pEVar9->pkey_type;
            unaff_s4 = unaff_s4 + 4;
            pEVar9->type = (int)(uVar2 ^ 0x5c5c5c5c);
            pEVar9 = (EVP_MD *)ppEVar11;
          } while (local_2c != (EVP_MD **)ppEVar11);
          pEStack_e4 = (EVP_MD *)&ctx->o_ctx;
          pEVar9 = pEStack_dc;
          pcVar5 = (char *)impl;
          iVar3 = (**(code **)(local_c0 + -0x7864))(pEStack_e4);
          if (iVar3 != 0) {
            len = (**(code **)(local_c0 + -0x6920))(pEStack_dc);
            key = &local_ac;
            iVar3 = (**(code **)(local_c0 + -0x7860))(pEStack_e4);
            if (iVar3 != 0) goto LAB_004d1f30;
            uVar2 = 0;
            goto LAB_004d1cfc;
          }
        }
      }
    }
    else {
      uVar2 = 0;
      if ((key == (void *)0x0) || (len < 0)) goto LAB_004d1cfc;
      ctx->md = md;
LAB_004d1ccc:
      pEVar9 = (EVP_MD *)key;
      pcVar5 = (char *)len;
      iVar3 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(pEStack_dc);
      if (iVar3 < 0x81) {
        pcVar15 = *(code **)(local_c0 + -0x7864);
        if (iVar3 < len) goto LAB_004d1d34;
LAB_004d1cec:
        if ((uint)len < 0x81) {
          (**(code **)(local_c0 + -0x52f4))(ctx->key,key,len);
          ctx->key_length = len;
          goto LAB_004d1dec;
        }
      }
      else {
        pcVar5 = "j <= (int)sizeof(ctx->key)";
        pEVar9 = (EVP_MD *)&DAT_0000006a;
        local_b4 = iVar3;
        OpenSSLDie("hmac.c",0x6a,"j <= (int)sizeof(ctx->key)");
        if (len <= local_b4) goto LAB_004d1cec;
        pcVar15 = *(code **)(local_c0 + -0x7864);
LAB_004d1d34:
        unaff_s6 = &ctx->md_ctx;
        pEVar9 = pEStack_dc;
        pcVar5 = (char *)impl;
        iVar3 = (*pcVar15)(unaff_s6);
        if ((iVar3 != 0) &&
           (pEVar9 = (EVP_MD *)key, pcVar5 = (char *)len,
           iVar3 = (**(code **)(local_c0 + -0x7860))(unaff_s6), iVar3 != 0)) {
          unaff_s4 = ctx->key;
          pcVar5 = (char *)&ctx->key_length;
          pEVar9 = (EVP_MD *)unaff_s4;
          iVar3 = (**(code **)(local_c0 + -0x785c))(unaff_s6);
          if (iVar3 != 0) {
            len = ctx->key_length;
LAB_004d1dec:
            if (len != 0x80) {
              (**(code **)(local_c0 + -0x53ec))(ctx->key + len,0,0x80 - len);
            }
            goto LAB_004d1e14;
          }
        }
      }
    }
    len = (int)pcVar5;
    key = pEVar9;
    uVar2 = 0;
  }
LAB_004d1cfc:
  if (local_2c[0] == *(EVP_MD **)puStack_f0) {
    return uVar2;
  }
  pcStack_d4 = HMAC_Init;
  pEVar9 = local_2c[0];
  (**(code **)(local_c0 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pEStack_ec = impl;
  pEStack_f4 = *(EVP_MD **)PTR___stack_chk_guard_006a9ae8;
  puStack_e0 = unaff_s4;
  pEStack_d8 = unaff_s6;
  if ((EVP_MD *)key == (EVP_MD *)0x0) {
    pEVar8 = pEVar9;
    if (md == (EVP_MD *)0x0) goto LAB_004d2278;
    if (md != (EVP_MD *)pEVar9->type) goto LAB_004d2014;
  }
  else {
    if (md == (EVP_MD *)0x0) {
      md = (EVP_MD *)pEVar9->type;
      if (md == (EVP_MD *)0x0) {
        uVar2 = 0;
        goto LAB_004d2018;
      }
    }
    else {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&pEVar9->copy);
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(pEVar9->required_pkey_type + 2);
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(&pEVar9->pkey_type);
      if (len < 0) {
        pEVar9->type = 0;
        goto LAB_004d2014;
      }
      pEVar9->type = (int)md;
    }
    iVar3 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(md);
    if (iVar3 < 0x81) {
      if (iVar3 < len) goto LAB_004d204c;
LAB_004d2008:
      if (&DAT_00000080 < (uint)len) goto LAB_004d2014;
      (*(code *)PTR_memcpy_006a9aec)(&pEVar9[1].pkey_type,key,len);
      pEVar9[1].type = len;
    }
    else {
      OpenSSLDie("hmac.c",0x6a,"j <= (int)sizeof(ctx->key)");
      if (len <= iVar3) goto LAB_004d2008;
LAB_004d204c:
      piVar6 = &pEVar9->pkey_type;
      iVar3 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(piVar6,md,0);
      if (((iVar3 == 0) ||
          (iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(piVar6,key,len), iVar3 == 0)) ||
         (iVar3 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(piVar6,&pEVar9[1].pkey_type,pEVar9 + 1)
         , iVar3 == 0)) goto LAB_004d2014;
      len = pEVar9[1].type;
    }
    if ((undefined *)len != &DAT_00000080) {
      (*(code *)PTR_memset_006a99f4)
                ((undefined *)(len + (int)(pEVar9->required_pkey_type + 9)),0,0x80 - len);
    }
  }
  piVar13 = &pEVar9[1].pkey_type;
  piVar6 = piVar13;
  ppEVar10 = apEStack_174;
  do {
    uVar2 = *piVar6;
    piVar6 = piVar6 + 1;
    *ppEVar10 = (EVP_MD *)(uVar2 ^ 0x36363636);
    ppEVar10 = ppEVar10 + 1;
  } while (piVar6 != pEVar9[2].required_pkey_type + 3);
  pp_Var14 = &pEVar9->copy;
  iVar3 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(pp_Var14,md,0);
  if (iVar3 != 0) {
    uVar7 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(md);
    iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(pp_Var14,apEStack_174,uVar7);
    if (iVar3 != 0) {
      ppEVar10 = apEStack_174;
      do {
        uVar2 = *piVar13;
        ppEVar12 = ppEVar10 + 1;
        piVar13 = piVar13 + 1;
        *ppEVar10 = (EVP_MD *)(uVar2 ^ 0x5c5c5c5c);
        ppEVar10 = ppEVar12;
      } while (&pEStack_f4 != ppEVar12);
      iVar3 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(pEVar9->required_pkey_type + 2,md,0);
      if (iVar3 != 0) {
        uVar7 = (*(code *)PTR_EVP_MD_block_size_006a84c0)(md);
        iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                          (pEVar9->required_pkey_type + 2,apEStack_174,uVar7);
        if (iVar3 != 0) goto LAB_004d221c;
      }
    }
  }
LAB_004d2014:
  do {
    uVar2 = 0;
LAB_004d2018:
    while( true ) {
      if (pEStack_f4 == *(EVP_MD **)puVar1) {
        return uVar2;
      }
      pEVar8 = pEStack_f4;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004d2278:
      pp_Var14 = &pEVar8->copy;
      if (pEVar8->type == 0) break;
LAB_004d221c:
      iVar3 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(&pEVar9->pkey_type,pp_Var14);
      uVar2 = (uint)(iVar3 != 0);
    }
  } while( true );
}

