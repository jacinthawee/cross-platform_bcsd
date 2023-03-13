
int ASN1_item_sign_ctx(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,
                      ASN1_BIT_STRING *signature,void *asn,EVP_MD_CTX *ctx)

{
  undefined *puVar1;
  int iVar2;
  ASN1_ITEM *pAVar3;
  EVP_MD_CTX *pEVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  ASN1_TEMPLATE *pAVar10;
  ASN1_BIT_STRING *pAVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  char *pcVar14;
  ASN1_ITEM *unaff_s1;
  ASN1_TYPE *pAVar15;
  code *pcVar16;
  int iStack_208;
  int iStack_204;
  undefined4 uStack_200;
  undefined auStack_1fc [24];
  int iStack_1e4;
  undefined *puStack_1e0;
  undefined *puStack_1dc;
  int iStack_1d8;
  code *pcStack_1d4;
  ASN1_ITEM *pAStack_1d0;
  ASN1_ITEM *pAStack_1cc;
  ASN1_ITEM *pAStack_1c8;
  code *pcStack_1c4;
  int iStack_1b0;
  undefined *puStack_1a8;
  char *pcStack_19c;
  int iStack_198;
  undefined auStack_194 [24];
  int *piStack_17c;
  undefined *puStack_178;
  char *pcStack_174;
  char *pcStack_170;
  ASN1_ITEM *pAStack_16c;
  X509_ALGOR *pXStack_168;
  undefined4 uStack_164;
  ASN1_ITEM *pAStack_160;
  ASN1_BIT_STRING *pAStack_15c;
  ASN1_ITEM *pAStack_158;
  undefined4 uStack_154;
  char *pcStack_140;
  undefined4 uStack_13c;
  undefined *puStack_138;
  int iStack_130;
  code *pcStack_12c;
  EVP_MD_CTX *pEStack_124;
  undefined *puStack_120;
  char *pcStack_11c;
  code *pcStack_118;
  code *pcStack_114;
  ASN1_ITEM *pAStack_100;
  undefined4 uStack_fc;
  undefined *puStack_f8;
  EVP_MD_CTX *pEStack_f0;
  ASN1_ITEM *pAStack_ec;
  EVP_MD_CTX *pEStack_e8;
  int iStack_e4;
  undefined *puStack_e0;
  ASN1_ITEM *pAStack_dc;
  ASN1_ITEM *pAStack_d8;
  X509_ALGOR *pXStack_d4;
  ASN1_ITEM *pAStack_d0;
  char *pcStack_cc;
  ASN1_ITEM *pAStack_c8;
  undefined4 uStack_c4;
  EVP_MD_CTX EStack_9c;
  code *pcStack_84;
  EVP_MD_CTX *pEStack_80;
  ASN1_ITEM *pAStack_7c;
  undefined *puStack_78;
  ASN1_ITEM *pAStack_74;
  ASN1_BIT_STRING *pAStack_70;
  ASN1_ITEM *pAStack_6c;
  void *pvStack_68;
  X509_ALGOR *pXStack_64;
  X509_ALGOR *pXStack_60;
  code *pcStack_5c;
  ASN1_ITEM *local_48;
  ASN1_ITEM *local_44;
  X509_ALGOR *local_40;
  int local_38;
  X509_ALGOR local_34;
  ASN1_ITEM *local_2c;
  
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  local_40 = (X509_ALGOR *)&_gp;
  local_38 = 0;
  local_34.algorithm = (ASN1_OBJECT *)0x0;
  local_2c = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pAStack_74 = (ASN1_ITEM *)(*(code *)PTR_EVP_MD_CTX_md_006a7500)(ctx);
  pAStack_7c = (ASN1_ITEM *)(*(code *)local_40[-0xb02].parameter)(ctx->pctx);
  if ((pAStack_74 == (ASN1_ITEM *)0x0) || (unaff_s1 = pAStack_7c, pAStack_7c == (ASN1_ITEM *)0x0)) {
    pAVar15 = local_40[-0xdd6].parameter;
    pXStack_d4 = (X509_ALGOR *)0xd9;
    local_48 = (ASN1_ITEM *)0xf7;
    pAStack_7c = unaff_s1;
LAB_006072c0:
    pcStack_cc = s_a_sign_c_00679744;
    pAStack_d8 = (ASN1_ITEM *)&DAT_000000dc;
    (*(code *)pAVar15)(0xd);
    pAVar3 = (ASN1_ITEM *)0x0;
  }
  else {
    iVar2 = pAStack_7c->tcount;
    pcStack_cc = (char *)algor1;
    if (*(code **)(iVar2 + 0x68) == (code *)0x0) {
      pAVar15 = local_40[-0xf43].parameter;
      if ((pAStack_74->tcount & 4U) == 0) {
LAB_00607194:
        local_34.parameter = (ASN1_TYPE *)pAStack_74->utype;
      }
      else {
LAB_00607278:
        uVar6 = (*(code *)pAVar15)(pAStack_74);
        iVar2 = (*(code *)local_40[-0xae5].parameter)
                          (&local_34.parameter,uVar6,*(undefined4 *)pAStack_7c->tcount);
        if (iVar2 == 0) {
LAB_00607330:
          pAVar15 = local_40[-0xdd6].parameter;
          pXStack_d4 = (X509_ALGOR *)0xc6;
          local_48 = (ASN1_ITEM *)0x114;
          goto LAB_006072c0;
        }
        iVar2 = pAStack_7c->tcount;
      }
      uVar6 = 0xffffffff;
      if ((*(uint *)(iVar2 + 8) & 4) != 0) {
        uVar6 = 5;
      }
      if (algor1 != (X509_ALGOR *)0x0) {
        uVar13 = (*(code *)local_40[-0xf94].algorithm)(local_34.parameter);
        pcStack_cc = (char *)0x0;
        (*(code *)local_40[-0xc20].parameter)(algor1,uVar13,uVar6);
      }
      if (algor2 != (X509_ALGOR *)0x0) {
        uVar13 = (*(code *)local_40[-0xf94].algorithm)(local_34.parameter);
        pcStack_cc = (char *)0x0;
        (*(code *)local_40[-0xc20].parameter)(algor2,uVar13,uVar6);
      }
LAB_00606fb4:
      it = (ASN1_ITEM *)(*(code *)local_40[-0xced].algorithm)(asn,&local_38,it);
      asn = (void *)0x680000;
      pAStack_74 = (ASN1_ITEM *)(*(code *)local_40[-0xf1d].algorithm)(pAStack_7c);
      local_34.algorithm = (ASN1_OBJECT *)pAStack_74;
      pAStack_7c = (ASN1_ITEM *)
                   (*(code *)local_40[-0xfbb].algorithm)(pAStack_74,s_a_sign_c_00679744,0x128);
      if ((local_38 == 0) || (pAStack_7c == (ASN1_ITEM *)0x0)) {
        pcStack_cc = s_a_sign_c_00679744;
        local_34.algorithm = (ASN1_OBJECT *)0x0;
        pXStack_d4 = (X509_ALGOR *)&DAT_00000041;
        pAStack_d8 = (ASN1_ITEM *)&DAT_000000dc;
        local_48 = (ASN1_ITEM *)0x12b;
        (*(code *)local_40[-0xdd6].parameter)(0xd);
        (*(code *)local_40[-0xff6].parameter)(ctx);
        if (local_38 != 0) goto LAB_00607154;
        goto LAB_00607174;
      }
      iVar2 = (*(code *)local_40[-0xf0c].algorithm)(ctx,local_38,it);
      if (iVar2 != 0) {
        pXStack_d4 = &local_34;
        pAStack_d8 = pAStack_7c;
        iVar2 = (*(code *)local_40[-0xf22].algorithm)(ctx);
        if (iVar2 != 0) {
          if (signature->data != (uchar *)0x0) {
            (*(code *)local_40[-0xfeb].algorithm)();
          }
          signature->data = (uchar *)pAStack_7c;
          signature->flags = signature->flags & 0xfffffff0U | 8;
          signature->length = (int)local_34.algorithm;
          goto LAB_00607138;
        }
      }
      pcStack_cc = s_a_sign_c_00679744;
      local_34.algorithm = (ASN1_OBJECT *)0x0;
      pXStack_d4 = (X509_ALGOR *)&DAT_00000006;
      local_48 = (ASN1_ITEM *)0x132;
      (*(code *)local_40[-0xdd6].parameter)(0xd,0xdc);
      (*(code *)local_40[-0xff6].parameter)(ctx);
      if (local_38 != 0) goto LAB_00607154;
      pAVar15 = local_40[-0xfae].parameter;
    }
    else {
      pAStack_d8 = it;
      pXStack_d4 = (X509_ALGOR *)asn;
      local_48 = (ASN1_ITEM *)algor2;
      local_44 = (ASN1_ITEM *)signature;
      iVar2 = (**(code **)(iVar2 + 0x68))(ctx);
      if (iVar2 == 1) {
        local_34.algorithm = (ASN1_OBJECT *)signature->length;
        pAStack_74 = (ASN1_ITEM *)0x0;
        it = (ASN1_ITEM *)0x0;
LAB_00607138:
        (*(code *)local_40[-0xff6].parameter)(ctx);
        pAVar3 = (ASN1_ITEM *)local_34.algorithm;
        if (local_38 == 0) goto LAB_006070ec;
        pAStack_7c = (ASN1_ITEM *)0x0;
      }
      else {
        if (0 < iVar2) {
          if (iVar2 == 2) {
            iVar2 = pAStack_7c->tcount;
            if ((pAStack_74->tcount & 4U) != 0) {
              if (iVar2 != 0) {
                pAVar15 = local_40[-0xf43].parameter;
                pcStack_cc = (char *)(ASN1_BIT_STRING *)0x680000;
                goto LAB_00607278;
              }
              goto LAB_00607330;
            }
            goto LAB_00607194;
          }
          goto LAB_00606fb4;
        }
        pXStack_d4 = (X509_ALGOR *)&DAT_00000006;
        pcStack_cc = s_a_sign_c_00679744;
        local_48 = (ASN1_ITEM *)0x107;
        pAStack_d8 = (ASN1_ITEM *)&DAT_000000dc;
        (*(code *)local_40[-0xdd6].parameter)(0xd);
        (*(code *)local_40[-0xff6].parameter)(ctx);
        pAVar3 = (ASN1_ITEM *)local_34.algorithm;
        if (local_38 == 0) goto LAB_006070ec;
        pAStack_74 = (ASN1_ITEM *)0x0;
        it = (ASN1_ITEM *)0x0;
        pAStack_7c = (ASN1_ITEM *)0x0;
      }
LAB_00607154:
      pAStack_d8 = it;
      (*(code *)local_40[-0xfae].parameter)();
      (*(code *)local_40[-0xfeb].algorithm)(local_38);
LAB_00607174:
      pAVar15 = local_40[-0xfae].parameter;
      pAVar3 = (ASN1_ITEM *)local_34.algorithm;
      if (pAStack_7c == (ASN1_ITEM *)0x0) goto LAB_006070ec;
    }
    pAStack_d8 = pAStack_74;
    (*(code *)pAVar15)(pAStack_7c);
    (*(code *)local_40[-0xfeb].algorithm)(pAStack_7c);
    pAVar3 = (ASN1_ITEM *)local_34.algorithm;
  }
LAB_006070ec:
  if (local_2c == *(ASN1_ITEM **)puStack_78) {
    return (int)pAVar3;
  }
  pcStack_5c = ASN1_item_sign;
  pAStack_dc = local_2c;
  (*(code *)local_40[-0xa66].algorithm)();
  pXStack_168 = local_40;
  pAStack_c8 = local_44;
  pAStack_d0 = local_48;
  puStack_e0 = PTR___stack_chk_guard_006a9ae8;
  pEStack_80 = ctx;
  pEStack_124 = &EStack_9c;
  pcStack_84 = *(code **)PTR___stack_chk_guard_006a9ae8;
  pAStack_70 = signature;
  pAStack_6c = it;
  pvStack_68 = asn;
  pXStack_64 = algor1;
  pXStack_60 = algor2;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(pEStack_124);
  pAStack_15c = (ASN1_BIT_STRING *)0x0;
  pAStack_1c8 = (ASN1_ITEM *)0x0;
  pAStack_158 = pAStack_c8;
  iStack_e4 = (*(code *)PTR_EVP_DigestSignInit_006a6e20)(pEStack_124);
  if (iStack_e4 == 0) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(pEStack_124);
  }
  else {
    pAStack_1c8 = pAStack_d8;
    pXStack_168 = pXStack_d4;
    pAStack_15c = (ASN1_BIT_STRING *)pcStack_cc;
    pAStack_158 = pAStack_d0;
    iStack_e4 = ASN1_item_sign_ctx(pAStack_dc,(X509_ALGOR *)pAStack_d8,pXStack_d4,
                                   (ASN1_BIT_STRING *)pcStack_cc,pAStack_d0,pEStack_124);
  }
  if (pcStack_84 == *(code **)puStack_e0) {
    return iStack_e4;
  }
  uStack_c4 = 0x607474;
  pcStack_118 = pcStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  puStack_f8 = &_gp;
  pAStack_ec = *(ASN1_ITEM **)PTR___stack_chk_guard_006a9ae8;
  pEStack_e8 = pEStack_124;
  pcStack_11c = (char *)(*pcStack_118)(pXStack_168,0);
  pEVar4 = (EVP_MD_CTX *)(**(code **)(puStack_f8 + -0x7dd8))(pcStack_11c,s_a_digest_c_00679750,0x52)
  ;
  if (pEVar4 == (EVP_MD_CTX *)0x0) {
    pcStack_170 = s_a_digest_c_00679750;
    pAVar11 = (ASN1_BIT_STRING *)&DAT_00000041;
    pcStack_174 = (char *)0xb8;
    pAStack_100 = (ASN1_ITEM *)0x53;
    (**(code **)(puStack_f8 + -0x6eac))(0xd,0xb8,0x41);
    iVar2 = 0;
  }
  else {
    pEStack_f0 = pEVar4;
    (*pcStack_118)(pXStack_168,&pEStack_f0);
    uStack_fc = 0;
    pcStack_174 = pcStack_11c;
    pAVar11 = pAStack_15c;
    pcStack_170 = &pAStack_158->itype;
    pAStack_100 = pAStack_1c8;
    iVar2 = (**(code **)(puStack_f8 + -0x73cc))(pEVar4,pcStack_11c,pAStack_15c);
    pEStack_124 = pEVar4;
    if (iVar2 != 0) {
      (**(code **)(puStack_f8 + -0x7f58))(pEVar4);
      iVar2 = 1;
    }
  }
  if (pAStack_ec == *(ASN1_ITEM **)puStack_120) {
    return iVar2;
  }
  pcStack_114 = ASN1_item_digest;
  pAStack_1cc = pAStack_ec;
  (**(code **)(puStack_f8 + -0x5330))();
  pAStack_16c = pAStack_100;
  puStack_178 = PTR___stack_chk_guard_006a9ae8;
  piVar9 = &iStack_130;
  puStack_138 = &_gp;
  iStack_130 = 0;
  pcStack_12c = *(code **)PTR___stack_chk_guard_006a9ae8;
  pAStack_1d0 = (ASN1_ITEM *)pcStack_170;
  piVar5 = (int *)(*(code *)PTR_ASN1_item_i2d_006a8678)(pAVar11);
  if (iStack_130 == 0) {
LAB_0060766c:
    piVar5 = piVar9;
    iVar2 = 0;
  }
  else {
    uStack_13c = 0;
    pAStack_1cc = (ASN1_ITEM *)pcStack_170;
    pAStack_1d0 = pAStack_16c;
    pcStack_140 = pcStack_174;
    iVar2 = (**(code **)(puStack_138 + -0x73cc))();
    piVar9 = piVar5;
    if (iVar2 == 0) goto LAB_0060766c;
    (**(code **)(puStack_138 + -0x7f58))(iStack_130);
    iVar2 = 1;
  }
  if (pcStack_12c == *(code **)puStack_178) {
    return iVar2;
  }
  uStack_154 = 0x6076bc;
  pcStack_1d4 = pcStack_12c;
  (**(code **)(puStack_138 + -0x5330))();
  puStack_1dc = PTR___stack_chk_guard_006a9ae8;
  puStack_1e0 = auStack_194;
  pcStack_19c = pcStack_140;
  uStack_164 = 0x680000;
  puStack_1a8 = &_gp;
  piStack_17c = *(int **)PTR___stack_chk_guard_006a9ae8;
  pAStack_160 = pAStack_1c8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_1e0);
  uVar6 = (**(code **)(puStack_1a8 + -0x7cb4))(*piVar5);
  uVar6 = (**(code **)(puStack_1a8 + -0x7d44))(uVar6);
  iVar2 = (**(code **)(puStack_1a8 + -0x7eb4))(uVar6);
  if (iVar2 == 0) {
    pcVar16 = *(code **)(puStack_1a8 + -0x6eac);
    puVar12 = (undefined4 *)0xa1;
    iStack_1b0 = 0x59;
LAB_006078ec:
    pcVar14 = "a_verify.c";
    pAVar10 = (ASN1_TEMPLATE *)&DAT_00000089;
    iStack_1d8 = -1;
    (*pcVar16)(0xd,0x89,puVar12,"a_verify.c");
  }
  else {
    if ((pAStack_1cc->utype == 3) && ((pAStack_1cc->tcount & 7U) != 0)) {
      pcVar16 = *(code **)(puStack_1a8 + -0x6eac);
      puVar12 = (undefined4 *)&DAT_000000dc;
      iStack_1b0 = 0x5e;
      goto LAB_006078ec;
    }
    pAStack_1c8 = (ASN1_ITEM *)(*pcStack_1d4)(pAStack_1d0,0);
    iVar7 = (**(code **)(puStack_1a8 + -0x7dd8))(pAStack_1c8,"a_verify.c",99);
    if (iVar7 == 0) {
      pcVar14 = "a_verify.c";
      puVar12 = (undefined4 *)&DAT_00000041;
      pAVar10 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_1b0 = 0x65;
      iStack_1d8 = -1;
      (**(code **)(puStack_1a8 + -0x6eac))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_198 = iVar7;
      (*pcStack_1d4)(pAStack_1d0,&iStack_198);
      iVar2 = (**(code **)(puStack_1a8 + -0x7864))(puStack_1e0,iVar2,0);
      if ((iVar2 == 0) ||
         (iVar2 = (**(code **)(puStack_1a8 + -0x7860))(puStack_1e0,iVar7,pAStack_1c8), iVar2 == 0))
      {
        pcVar16 = *(code **)(puStack_1a8 + -0x6eac);
        iStack_1b0 = 0x6d;
      }
      else {
        (**(code **)(puStack_1a8 + -0x7d6c))(iVar7,pAStack_1c8);
        (**(code **)(puStack_1a8 + -0x7f58))(iVar7);
        puVar12 = *(undefined4 **)pAStack_1cc;
        pAVar10 = pAStack_1cc->templates;
        pcVar14 = pcStack_19c;
        iVar2 = (**(code **)(puStack_1a8 + -0x6e04))(puStack_1e0,pAVar10,puVar12,pcStack_19c);
        if (0 < iVar2) {
          iStack_1d8 = 1;
          goto LAB_0060782c;
        }
        pcVar16 = *(code **)(puStack_1a8 + -0x6eac);
        iStack_1b0 = 0x77;
      }
      pcVar14 = "a_verify.c";
      puVar12 = (undefined4 *)&DAT_00000006;
      pAVar10 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_1d8 = 0;
      (*pcVar16)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_0060782c:
  (**(code **)(puStack_1a8 + -0x7fac))(puStack_1e0);
  if (piStack_17c == *(int **)puStack_1dc) {
    return iStack_1d8;
  }
  pcStack_1c4 = ASN1_item_verify;
  piVar9 = piStack_17c;
  (**(code **)(puStack_1a8 + -0x5330))();
  iVar2 = iStack_1b0;
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_208 = 0;
  iStack_1e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iStack_1b0 == 0) {
    uVar13 = 0x43;
    uVar6 = 0x92;
  }
  else {
    if ((puVar12[1] != 3) || ((puVar12[3] & 7) == 0)) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_1fc);
      uVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar10->flags);
      iVar7 = (*(code *)PTR_OBJ_find_sigid_algs_006a834c)(uVar6,&iStack_204,&uStack_200);
      if (iVar7 == 0) {
        uVar13 = 199;
        uVar6 = 0x9f;
LAB_00607b58:
        piVar5 = (int *)0xc5;
        iVar2 = -1;
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar13,"a_verify.c",uVar6);
      }
      else {
        if (iStack_204 != 0) {
          uVar6 = (*(code *)PTR_OBJ_nid2sn_006a709c)();
          iVar7 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar6);
          if (iVar7 == 0) {
            uVar13 = 0xa1;
            uVar6 = 0xb6;
          }
          else {
            iVar8 = (*(code *)PTR_EVP_PKEY_type_006a97e0)(uStack_200);
            if (iVar8 == **(int **)(iVar2 + 0xc)) {
              iVar2 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(auStack_1fc,0,iVar7,0,iVar2);
              if (iVar2 != 0) goto LAB_00607b88;
              uVar6 = 0xc1;
              goto LAB_00607bd8;
            }
            uVar13 = 200;
            uVar6 = 0xbc;
          }
          goto LAB_00607b58;
        }
        if ((*(int *)(iVar2 + 0xc) == 0) ||
           (pcVar16 = *(code **)(*(int *)(iVar2 + 0xc) + 100), pcVar16 == (code *)0x0)) {
          uVar13 = 199;
          uVar6 = 0xa5;
          goto LAB_00607b58;
        }
        piVar5 = piVar9;
        iVar2 = (*pcVar16)(auStack_1fc,piVar9,pcVar14,pAVar10,puVar12,iVar2);
        if (iVar2 == 2) {
LAB_00607b88:
          uVar6 = (*(code *)PTR_ASN1_item_i2d_006a8678)(pcVar14,&iStack_208,piVar9);
          if (iStack_208 == 0) {
            uVar13 = 0x41;
            uVar6 = 0xcb;
            goto LAB_00607b58;
          }
          iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_1fc,iStack_208,uVar6);
          if (iVar2 == 0) {
            uVar6 = 0xd0;
          }
          else {
            (*(code *)PTR_OPENSSL_cleanse_006a7074)(iStack_208,uVar6);
            (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_208);
            piVar5 = (int *)puVar12[2];
            iVar2 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)(auStack_1fc,piVar5,*puVar12);
            if (0 < iVar2) {
              iVar2 = 1;
              goto LAB_00607a64;
            }
            uVar6 = 0xda;
          }
LAB_00607bd8:
          piVar5 = (int *)0xc5;
          iVar2 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,6,"a_verify.c",uVar6);
        }
      }
LAB_00607a64:
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_1fc);
      goto LAB_00607a78;
    }
    uVar13 = 0xdc;
    uVar6 = 0x97;
  }
  piVar5 = (int *)0xc5;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc5,uVar13,"a_verify.c",uVar6);
  iVar2 = -1;
LAB_00607a78:
  if (iStack_1e4 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    *piVar5 = *piVar5 + 1;
    return 1;
  }
  return iVar2;
}

