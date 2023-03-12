
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
  ASN1_OBJECT *pAVar16;
  code *pcVar17;
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
  undefined4 uStack_1cc;
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
  
  puStack_78 = PTR___stack_chk_guard_006aabf0;
  local_40 = (X509_ALGOR *)&_gp;
  local_38 = 0;
  local_34.algorithm = (ASN1_OBJECT *)0x0;
  local_2c = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pAStack_74 = (ASN1_ITEM *)(*(code *)PTR_EVP_MD_CTX_md_006a85fc)(ctx);
  pAStack_7c = (ASN1_ITEM *)(*(code *)local_40[-0xb00].algorithm)(ctx->pctx);
  if ((pAStack_74 == (ASN1_ITEM *)0x0) || (unaff_s1 = pAStack_7c, pAStack_7c == (ASN1_ITEM *)0x0)) {
    pAVar16 = local_40[-0xdd6].algorithm;
    pXStack_d4 = (X509_ALGOR *)0xd9;
    local_48 = (ASN1_ITEM *)0xf7;
    pAStack_7c = unaff_s1;
LAB_006090b0:
    pcStack_cc = s_a_sign_c_00679ff4;
    pAStack_d8 = (ASN1_ITEM *)&DAT_000000dc;
    (*(code *)pAVar16)(0xd);
    pAVar3 = (ASN1_ITEM *)0x0;
  }
  else {
    iVar2 = pAStack_7c->tcount;
    pcStack_cc = (char *)algor1;
    if (*(code **)(iVar2 + 0x68) == (code *)0x0) {
      pAVar15 = local_40[-0xf43].parameter;
      if ((pAStack_74->tcount & 4U) == 0) {
LAB_00608f84:
        local_34.parameter = (ASN1_TYPE *)pAStack_74->utype;
      }
      else {
LAB_00609068:
        uVar6 = (*(code *)pAVar15)(pAStack_74);
        iVar2 = (*(code *)local_40[-0xae4].parameter)
                          (&local_34.parameter,uVar6,*(undefined4 *)pAStack_7c->tcount);
        if (iVar2 == 0) {
LAB_00609120:
          pAVar16 = local_40[-0xdd6].algorithm;
          pXStack_d4 = (X509_ALGOR *)0xc6;
          local_48 = (ASN1_ITEM *)0x119;
          goto LAB_006090b0;
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
        (*(code *)local_40[-0xc1c].parameter)(algor1,uVar13,uVar6);
      }
      if (algor2 != (X509_ALGOR *)0x0) {
        uVar13 = (*(code *)local_40[-0xf94].algorithm)(local_34.parameter);
        pcStack_cc = (char *)0x0;
        (*(code *)local_40[-0xc1c].parameter)(algor2,uVar13,uVar6);
      }
LAB_00608da4:
      it = (ASN1_ITEM *)(*(code *)local_40[-0xce9].parameter)(asn,&local_38,it);
      asn = (void *)0x680000;
      pAStack_74 = (ASN1_ITEM *)(*(code *)local_40[-0xf1e].parameter)(pAStack_7c);
      local_34.algorithm = (ASN1_OBJECT *)pAStack_74;
      pAStack_7c = (ASN1_ITEM *)
                   (*(code *)local_40[-0xfbb].algorithm)(pAStack_74,s_a_sign_c_00679ff4,0x12e);
      if ((local_38 == 0) || (pAStack_7c == (ASN1_ITEM *)0x0)) {
        pcStack_cc = s_a_sign_c_00679ff4;
        local_34.algorithm = (ASN1_OBJECT *)0x0;
        pXStack_d4 = (X509_ALGOR *)&DAT_00000041;
        pAStack_d8 = (ASN1_ITEM *)&DAT_000000dc;
        local_48 = (ASN1_ITEM *)0x132;
        (*(code *)local_40[-0xdd6].algorithm)(0xd);
        (*(code *)local_40[-0xff6].parameter)(ctx);
        if (local_38 != 0) goto LAB_00608f44;
        goto LAB_00608f64;
      }
      iVar2 = (*(code *)local_40[-0xf0e].parameter)(ctx,local_38,it);
      if (iVar2 != 0) {
        pXStack_d4 = &local_34;
        pAStack_d8 = pAStack_7c;
        iVar2 = (*(code *)local_40[-0xf23].parameter)(ctx);
        if (iVar2 != 0) {
          if (signature->data != (uchar *)0x0) {
            (*(code *)local_40[-0xfeb].algorithm)();
          }
          signature->data = (uchar *)pAStack_7c;
          signature->flags = signature->flags & 0xfffffff0U | 8;
          signature->length = (int)local_34.algorithm;
          goto LAB_00608f28;
        }
      }
      pcStack_cc = s_a_sign_c_00679ff4;
      local_34.algorithm = (ASN1_OBJECT *)0x0;
      pXStack_d4 = (X509_ALGOR *)&DAT_00000006;
      local_48 = (ASN1_ITEM *)0x13a;
      (*(code *)local_40[-0xdd6].algorithm)(0xd,0xdc);
      (*(code *)local_40[-0xff6].parameter)(ctx);
      if (local_38 != 0) goto LAB_00608f44;
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
LAB_00608f28:
        (*(code *)local_40[-0xff6].parameter)(ctx);
        pAVar3 = (ASN1_ITEM *)local_34.algorithm;
        if (local_38 == 0) goto LAB_00608edc;
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
                goto LAB_00609068;
              }
              goto LAB_00609120;
            }
            goto LAB_00608f84;
          }
          goto LAB_00608da4;
        }
        pXStack_d4 = (X509_ALGOR *)&DAT_00000006;
        pcStack_cc = s_a_sign_c_00679ff4;
        local_48 = (ASN1_ITEM *)0x108;
        pAStack_d8 = (ASN1_ITEM *)&DAT_000000dc;
        (*(code *)local_40[-0xdd6].algorithm)(0xd);
        (*(code *)local_40[-0xff6].parameter)(ctx);
        pAVar3 = (ASN1_ITEM *)local_34.algorithm;
        if (local_38 == 0) goto LAB_00608edc;
        pAStack_74 = (ASN1_ITEM *)0x0;
        it = (ASN1_ITEM *)0x0;
        pAStack_7c = (ASN1_ITEM *)0x0;
      }
LAB_00608f44:
      pAStack_d8 = it;
      (*(code *)local_40[-0xfae].parameter)();
      (*(code *)local_40[-0xfeb].algorithm)(local_38);
LAB_00608f64:
      pAVar15 = local_40[-0xfae].parameter;
      pAVar3 = (ASN1_ITEM *)local_34.algorithm;
      if (pAStack_7c == (ASN1_ITEM *)0x0) goto LAB_00608edc;
    }
    pAStack_d8 = pAStack_74;
    (*(code *)pAVar15)(pAStack_7c);
    (*(code *)local_40[-0xfeb].algorithm)(pAStack_7c);
    pAVar3 = (ASN1_ITEM *)local_34.algorithm;
  }
LAB_00608edc:
  if (local_2c == *(ASN1_ITEM **)puStack_78) {
    return (int)pAVar3;
  }
  pcStack_5c = ASN1_item_sign;
  pAStack_dc = local_2c;
  (*(code *)local_40[-0xa65].algorithm)();
  pXStack_168 = local_40;
  pAStack_c8 = local_44;
  pAStack_d0 = local_48;
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  pEStack_80 = ctx;
  pEStack_124 = &EStack_9c;
  pcStack_84 = *(code **)PTR___stack_chk_guard_006aabf0;
  pAStack_70 = signature;
  pAStack_6c = it;
  pvStack_68 = asn;
  pXStack_64 = algor1;
  pXStack_60 = algor2;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(pEStack_124);
  pAStack_15c = (ASN1_BIT_STRING *)0x0;
  pAStack_1c8 = (ASN1_ITEM *)0x0;
  pAStack_158 = pAStack_c8;
  iStack_e4 = (*(code *)PTR_EVP_DigestSignInit_006a7f20)(pEStack_124);
  if (iStack_e4 == 0) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(pEStack_124);
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
  uStack_c4 = 0x609264;
  pcStack_118 = pcStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_120 = PTR___stack_chk_guard_006aabf0;
  uStack_1cc = 0x680000;
  puStack_f8 = &_gp;
  pAStack_ec = *(ASN1_ITEM **)PTR___stack_chk_guard_006aabf0;
  pEStack_e8 = pEStack_124;
  pcStack_11c = (char *)(*pcStack_118)(pXStack_168,0);
  pEVar4 = (EVP_MD_CTX *)(**(code **)(puStack_f8 + -0x7dd8))(pcStack_11c,s_a_digest_c_0067a000,0x52)
  ;
  if (pEVar4 == (EVP_MD_CTX *)0x0) {
    pcStack_170 = s_a_digest_c_0067a000;
    pAVar11 = (ASN1_BIT_STRING *)&DAT_00000041;
    pcStack_174 = (char *)0xb8;
    pAStack_100 = (ASN1_ITEM *)0x54;
    (**(code **)(puStack_f8 + -0x6eb0))(0xd,0xb8,0x41);
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
    iVar2 = (**(code **)(puStack_f8 + -0x73dc))(pEVar4,pcStack_11c,pAStack_15c);
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
  pAVar3 = pAStack_ec;
  (**(code **)(puStack_f8 + -0x5328))();
  pAStack_16c = pAStack_100;
  puStack_178 = PTR___stack_chk_guard_006aabf0;
  piVar9 = &iStack_130;
  puStack_138 = &_gp;
  iStack_130 = 0;
  pcStack_12c = *(code **)PTR___stack_chk_guard_006aabf0;
  pAStack_1d0 = (ASN1_ITEM *)pcStack_170;
  piVar5 = (int *)(*(code *)PTR_ASN1_item_i2d_006a979c)(pAVar11);
  if (iStack_130 == 0) {
LAB_0060945c:
    piVar5 = piVar9;
    iVar2 = 0;
  }
  else {
    uStack_13c = 0;
    pAVar3 = (ASN1_ITEM *)pcStack_170;
    pAStack_1d0 = pAStack_16c;
    pcStack_140 = pcStack_174;
    iVar2 = (**(code **)(puStack_138 + -0x73dc))();
    piVar9 = piVar5;
    if (iVar2 == 0) goto LAB_0060945c;
    (**(code **)(puStack_138 + -0x7f58))(iStack_130);
    iVar2 = 1;
  }
  if (pcStack_12c == *(code **)puStack_178) {
    return iVar2;
  }
  uStack_154 = 0x6094ac;
  pcStack_1d4 = pcStack_12c;
  (**(code **)(puStack_138 + -0x5328))();
  puStack_1dc = PTR___stack_chk_guard_006aabf0;
  puStack_1e0 = auStack_194;
  pcStack_19c = pcStack_140;
  puStack_1a8 = &_gp;
  uStack_164 = 0x680000;
  piStack_17c = *(int **)PTR___stack_chk_guard_006aabf0;
  pAStack_160 = pAStack_1c8;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_1e0);
  uVar6 = (**(code **)(puStack_1a8 + -0x7cb4))(*piVar5);
  uVar6 = (**(code **)(puStack_1a8 + -0x7d44))(uVar6);
  iVar2 = (**(code **)(puStack_1a8 + -0x7eb4))(uVar6);
  if (iVar2 == 0) {
    puVar12 = (undefined4 *)0xa1;
    pcVar14 = "a_verify.c";
    iStack_1b0 = 0x5a;
    pAVar10 = (ASN1_TEMPLATE *)&DAT_00000089;
    iStack_1d8 = -1;
    (**(code **)(puStack_1a8 + -0x6eb0))(0xd,0x89,0xa1,"a_verify.c");
  }
  else {
    uStack_1cc = (*pcStack_1d4)(pAStack_1d0,0);
    pAStack_1c8 = (ASN1_ITEM *)0x680000;
    iVar7 = (**(code **)(puStack_1a8 + -0x7dd8))(uStack_1cc,"a_verify.c",0x5f);
    if (iVar7 == 0) {
      pcVar14 = "a_verify.c";
      puVar12 = (undefined4 *)&DAT_00000041;
      pAVar10 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_1b0 = 0x62;
      iStack_1d8 = -1;
      (**(code **)(puStack_1a8 + -0x6eb0))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_198 = iVar7;
      (*pcStack_1d4)(pAStack_1d0,&iStack_198);
      iVar2 = (**(code **)(puStack_1a8 + -0x7870))(puStack_1e0,iVar2,0);
      if ((iVar2 == 0) ||
         (iVar2 = (**(code **)(puStack_1a8 + -0x786c))(puStack_1e0,iVar7,uStack_1cc), iVar2 == 0)) {
        pcVar17 = *(code **)(puStack_1a8 + -0x6eb0);
        iStack_1b0 = 0x6b;
      }
      else {
        (**(code **)(puStack_1a8 + -0x7d6c))(iVar7,uStack_1cc);
        (**(code **)(puStack_1a8 + -0x7f58))(iVar7);
        puVar12 = *(undefined4 **)pAVar3;
        pAVar10 = pAVar3->templates;
        pcVar14 = pcStack_19c;
        iVar2 = (**(code **)(puStack_1a8 + -0x6e64))(puStack_1e0,pAVar10,puVar12,pcStack_19c);
        if (0 < iVar2) {
          iStack_1d8 = 1;
          goto LAB_00609610;
        }
        pcVar17 = *(code **)(puStack_1a8 + -0x6eb0);
        iStack_1b0 = 0x76;
      }
      pcVar14 = "a_verify.c";
      puVar12 = (undefined4 *)&DAT_00000006;
      pAVar10 = (ASN1_TEMPLATE *)&DAT_00000089;
      iStack_1d8 = 0;
      (*pcVar17)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_00609610:
  (**(code **)(puStack_1a8 + -0x7fac))(puStack_1e0);
  if (piStack_17c == *(int **)puStack_1dc) {
    return iStack_1d8;
  }
  pcStack_1c4 = ASN1_item_verify;
  piVar9 = piStack_17c;
  (**(code **)(puStack_1a8 + -0x5328))();
  iVar2 = iStack_1b0;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_208 = 0;
  iStack_1e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (iStack_1b0 == 0) {
    piVar5 = (int *)0xc5;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,0x43,"a_verify.c",0x91);
    iVar2 = -1;
    goto LAB_00609824;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_1fc);
  uVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(pAVar10->flags);
  iVar7 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(uVar6,&iStack_204,&uStack_200);
  if (iVar7 == 0) {
    uVar13 = 199;
    uVar6 = 0x9a;
LAB_0060986c:
    piVar5 = (int *)0xc5;
    iVar2 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,uVar13,"a_verify.c",uVar6);
  }
  else {
    if (iStack_204 != 0) {
      uVar6 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar7 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar6);
      if (iVar7 == 0) {
        uVar13 = 0xa1;
        uVar6 = 0xb4;
      }
      else {
        iVar8 = (*(code *)PTR_EVP_PKEY_type_006aa8f0)(uStack_200);
        if (iVar8 == **(int **)(iVar2 + 0xc)) {
          iVar2 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(auStack_1fc,0,iVar7,0,iVar2);
          if (iVar2 != 0) goto LAB_006098f4;
          uVar6 = 0xc1;
          goto LAB_00609944;
        }
        uVar13 = 200;
        uVar6 = 0xbb;
      }
      goto LAB_0060986c;
    }
    if ((*(int *)(iVar2 + 0xc) == 0) ||
       (pcVar17 = *(code **)(*(int *)(iVar2 + 0xc) + 100), pcVar17 == (code *)0x0)) {
      uVar13 = 199;
      uVar6 = 0xa1;
      goto LAB_0060986c;
    }
    piVar5 = piVar9;
    iVar2 = (*pcVar17)(auStack_1fc,piVar9,pcVar14,pAVar10,puVar12,iVar2);
    if (iVar2 == 2) {
LAB_006098f4:
      uVar6 = (*(code *)PTR_ASN1_item_i2d_006a979c)(pcVar14,&iStack_208,piVar9);
      if (iStack_208 == 0) {
        uVar13 = 0x41;
        uVar6 = 0xcc;
        goto LAB_0060986c;
      }
      iVar2 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_1fc,iStack_208,uVar6);
      if (iVar2 == 0) {
        uVar6 = 0xd2;
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_208,uVar6);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_208);
        piVar5 = (int *)puVar12[2];
        iVar2 = (*(code *)PTR_EVP_DigestVerifyFinal_006a85c8)(auStack_1fc,piVar5,*puVar12);
        if (0 < iVar2) {
          iVar2 = 1;
          goto LAB_00609810;
        }
        uVar6 = 0xdd;
      }
LAB_00609944:
      piVar5 = (int *)0xc5;
      iVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,6,"a_verify.c",uVar6);
    }
  }
LAB_00609810:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_1fc);
LAB_00609824:
  if (iStack_1e4 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    *piVar5 = *piVar5 + 1;
    return 1;
  }
  return iVar2;
}

