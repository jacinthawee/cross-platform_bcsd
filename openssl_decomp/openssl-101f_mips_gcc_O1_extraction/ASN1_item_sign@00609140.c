
int ASN1_item_sign(ASN1_ITEM *it,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
                  void *data,EVP_PKEY *pkey,EVP_MD *type)

{
  undefined *puVar1;
  EVP_MD_CTX *pEVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  EVP_PKEY *pEVar8;
  int *piVar9;
  undefined4 *puVar10;
  ASN1_BIT_STRING *pAVar11;
  ASN1_OBJECT *pAVar12;
  undefined4 uVar13;
  char *pcVar14;
  code *pcVar15;
  int iStack_1b0;
  int iStack_1ac;
  undefined4 uStack_1a8;
  undefined auStack_1a4 [24];
  int iStack_18c;
  undefined *puStack_188;
  undefined *puStack_184;
  int iStack_180;
  code *pcStack_17c;
  EVP_PKEY *pEStack_178;
  undefined4 uStack_174;
  EVP_PKEY *pEStack_170;
  code *pcStack_16c;
  int iStack_158;
  undefined *puStack_150;
  char *pcStack_144;
  int iStack_140;
  undefined auStack_13c [24];
  int *piStack_124;
  undefined *puStack_120;
  char *pcStack_11c;
  char *pcStack_118;
  EVP_PKEY *pEStack_114;
  EVP_MD *pEStack_110;
  undefined4 uStack_10c;
  EVP_PKEY *pEStack_108;
  ASN1_BIT_STRING *pAStack_104;
  EVP_PKEY *pEStack_100;
  undefined4 uStack_fc;
  char *pcStack_e8;
  undefined4 uStack_e4;
  undefined *puStack_e0;
  int iStack_d8;
  code *pcStack_d4;
  EVP_MD_CTX *pEStack_cc;
  undefined *puStack_c8;
  char *pcStack_c4;
  code *pcStack_c0;
  code *pcStack_bc;
  EVP_PKEY *pEStack_a8;
  undefined4 uStack_a4;
  undefined *puStack_a0;
  EVP_MD_CTX *pEStack_98;
  EVP_PKEY *pEStack_94;
  EVP_MD_CTX *pEStack_90;
  int iStack_8c;
  undefined *puStack_88;
  ASN1_ITEM *pAStack_84;
  X509_ALGOR *pXStack_80;
  X509_ALGOR *pXStack_7c;
  void *pvStack_78;
  ASN1_BIT_STRING *pAStack_74;
  EVP_PKEY *pEStack_70;
  undefined4 uStack_6c;
  EVP_MD_CTX EStack_44;
  code *local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006aabf0;
  pEStack_cc = &EStack_44;
  local_2c = *(code **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(pEStack_cc);
  pAStack_104 = (ASN1_BIT_STRING *)0x0;
  pEStack_170 = (EVP_PKEY *)0x0;
  pEStack_100 = pkey;
  iStack_8c = (*(code *)PTR_EVP_DigestSignInit_006a7f20)(pEStack_cc);
  if (iStack_8c == 0) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(pEStack_cc);
  }
  else {
    pEStack_170 = (EVP_PKEY *)algor1;
    type = (EVP_MD *)algor2;
    pAStack_104 = signature;
    pEStack_100 = (EVP_PKEY *)data;
    iStack_8c = ASN1_item_sign_ctx(it,algor1,algor2,signature,data,pEStack_cc);
  }
  if (local_2c == *(code **)puStack_88) {
    return iStack_8c;
  }
  uStack_6c = 0x609264;
  pcStack_c0 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_c8 = PTR___stack_chk_guard_006aabf0;
  pvStack_78 = data;
  pEStack_70 = pkey;
  uStack_174 = 0x680000;
  puStack_a0 = &_gp;
  pEStack_94 = *(EVP_PKEY **)PTR___stack_chk_guard_006aabf0;
  pEStack_90 = pEStack_cc;
  pAStack_84 = it;
  pXStack_80 = algor1;
  pXStack_7c = algor2;
  pAStack_74 = signature;
  pcStack_c4 = (char *)(*pcStack_c0)(type,0);
  pEVar2 = (EVP_MD_CTX *)(**(code **)(puStack_a0 + -0x7dd8))(pcStack_c4,s_a_digest_c_0067a020,0x52);
  if (pEVar2 == (EVP_MD_CTX *)0x0) {
    pcStack_118 = s_a_digest_c_0067a020;
    pAVar11 = (ASN1_BIT_STRING *)&DAT_00000041;
    pcStack_11c = (char *)0xb8;
    pEStack_a8 = (EVP_PKEY *)0x54;
    (**(code **)(puStack_a0 + -0x6eb0))(0xd,0xb8,0x41);
    iVar3 = 0;
  }
  else {
    pEStack_98 = pEVar2;
    (*pcStack_c0)(type,&pEStack_98);
    uStack_a4 = 0;
    pcStack_11c = pcStack_c4;
    pAVar11 = pAStack_104;
    pcStack_118 = (char *)pEStack_100;
    pEStack_a8 = pEStack_170;
    iVar3 = (**(code **)(puStack_a0 + -0x73dc))(pEVar2,pcStack_c4,pAStack_104);
    pEStack_cc = pEVar2;
    if (iVar3 != 0) {
      (**(code **)(puStack_a0 + -0x7f58))(pEVar2);
      iVar3 = 1;
    }
  }
  if (pEStack_94 == *(EVP_PKEY **)puStack_c8) {
    return iVar3;
  }
  pcStack_bc = ASN1_item_digest;
  pEVar8 = pEStack_94;
  (**(code **)(puStack_a0 + -0x5328))();
  pEStack_114 = pEStack_a8;
  puStack_120 = PTR___stack_chk_guard_006aabf0;
  piVar9 = &iStack_d8;
  puStack_e0 = &_gp;
  iStack_d8 = 0;
  pcStack_d4 = *(code **)PTR___stack_chk_guard_006aabf0;
  pEStack_178 = (EVP_PKEY *)pcStack_118;
  piVar4 = (int *)(*(code *)PTR_ASN1_item_i2d_006a979c)(pAVar11);
  if (iStack_d8 == 0) {
LAB_0060945c:
    piVar4 = piVar9;
    iVar3 = 0;
  }
  else {
    uStack_e4 = 0;
    pEVar8 = (EVP_PKEY *)pcStack_118;
    pEStack_178 = pEStack_114;
    pcStack_e8 = pcStack_11c;
    iVar3 = (**(code **)(puStack_e0 + -0x73dc))();
    piVar9 = piVar4;
    if (iVar3 == 0) goto LAB_0060945c;
    (**(code **)(puStack_e0 + -0x7f58))(iStack_d8);
    iVar3 = 1;
  }
  if (pcStack_d4 == *(code **)puStack_120) {
    return iVar3;
  }
  uStack_fc = 0x6094ac;
  pcStack_17c = pcStack_d4;
  (**(code **)(puStack_e0 + -0x5328))();
  puStack_184 = PTR___stack_chk_guard_006aabf0;
  puStack_188 = auStack_13c;
  pcStack_144 = pcStack_e8;
  puStack_150 = &_gp;
  uStack_10c = 0x680000;
  piStack_124 = *(int **)PTR___stack_chk_guard_006aabf0;
  pEStack_110 = type;
  pEStack_108 = pEStack_170;
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(puStack_188);
  uVar5 = (**(code **)(puStack_150 + -0x7cb4))(*piVar4);
  uVar5 = (**(code **)(puStack_150 + -0x7d44))(uVar5);
  iVar3 = (**(code **)(puStack_150 + -0x7eb4))(uVar5);
  if (iVar3 == 0) {
    pAVar12 = (ASN1_OBJECT *)0xa1;
    pcVar14 = "a_verify.c";
    iStack_158 = 0x5a;
    puVar10 = (undefined4 *)&DAT_00000089;
    iStack_180 = -1;
    (**(code **)(puStack_150 + -0x6eb0))(0xd,0x89,0xa1,"a_verify.c");
  }
  else {
    uStack_174 = (*pcStack_17c)(pEStack_178,0);
    pEStack_170 = (EVP_PKEY *)0x680000;
    iVar6 = (**(code **)(puStack_150 + -0x7dd8))(uStack_174,"a_verify.c",0x5f);
    if (iVar6 == 0) {
      pcVar14 = "a_verify.c";
      pAVar12 = (ASN1_OBJECT *)&DAT_00000041;
      puVar10 = (undefined4 *)&DAT_00000089;
      iStack_158 = 0x62;
      iStack_180 = -1;
      (**(code **)(puStack_150 + -0x6eb0))(0xd,0x89,0x41,"a_verify.c");
    }
    else {
      iStack_140 = iVar6;
      (*pcStack_17c)(pEStack_178,&iStack_140);
      iVar3 = (**(code **)(puStack_150 + -0x7870))(puStack_188,iVar3,0);
      if (iVar3 == 0) {
LAB_006095e8:
        pcVar15 = *(code **)(puStack_150 + -0x6eb0);
        iStack_158 = 0x6b;
      }
      else {
        iVar3 = (**(code **)(puStack_150 + -0x786c))(puStack_188,iVar6,uStack_174);
        if (iVar3 == 0) goto LAB_006095e8;
        (**(code **)(puStack_150 + -0x7d6c))(iVar6,uStack_174);
        (**(code **)(puStack_150 + -0x7f58))(iVar6);
        pAVar12 = (ASN1_OBJECT *)pEVar8->type;
        puVar10 = (undefined4 *)pEVar8->references;
        pcVar14 = pcStack_144;
        iVar3 = (**(code **)(puStack_150 + -0x6e64))(puStack_188,puVar10,pAVar12,pcStack_144);
        if (0 < iVar3) {
          iStack_180 = 1;
          goto LAB_00609610;
        }
        pcVar15 = *(code **)(puStack_150 + -0x6eb0);
        iStack_158 = 0x76;
      }
      pcVar14 = "a_verify.c";
      pAVar12 = (ASN1_OBJECT *)&DAT_00000006;
      puVar10 = (undefined4 *)&DAT_00000089;
      iStack_180 = 0;
      (*pcVar15)(0xd,0x89,6,"a_verify.c");
    }
  }
LAB_00609610:
  (**(code **)(puStack_150 + -0x7fac))(puStack_188);
  if (piStack_124 == *(int **)puStack_184) {
    return iStack_180;
  }
  pcStack_16c = ASN1_item_verify;
  piVar9 = piStack_124;
  (**(code **)(puStack_150 + -0x5328))();
  iVar3 = iStack_158;
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_1b0 = 0;
  iStack_18c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (iStack_158 == 0) {
    piVar4 = (int *)0xc5;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,0x43,"a_verify.c",0x91);
    iVar3 = -1;
    goto LAB_00609824;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_1a4);
  uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar10);
  iVar6 = (*(code *)PTR_OBJ_find_sigid_algs_006a9468)(uVar5,&iStack_1ac,&uStack_1a8);
  if (iVar6 == 0) {
    uVar13 = 199;
    uVar5 = 0x9a;
LAB_0060986c:
    piVar4 = (int *)0xc5;
    iVar3 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,uVar13,"a_verify.c",uVar5);
  }
  else {
    if (iStack_1ac != 0) {
      uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar6 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar5);
      if (iVar6 == 0) {
        uVar13 = 0xa1;
        uVar5 = 0xb4;
      }
      else {
        iVar7 = (*(code *)PTR_EVP_PKEY_type_006aa8f0)(uStack_1a8);
        if (iVar7 == **(int **)(iVar3 + 0xc)) {
          iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(auStack_1a4,0,iVar6,0,iVar3);
          if (iVar3 != 0) goto LAB_006098f4;
          uVar5 = 0xc1;
          goto LAB_00609944;
        }
        uVar13 = 200;
        uVar5 = 0xbb;
      }
      goto LAB_0060986c;
    }
    if ((*(int *)(iVar3 + 0xc) == 0) ||
       (pcVar15 = *(code **)(*(int *)(iVar3 + 0xc) + 100), pcVar15 == (code *)0x0)) {
      uVar13 = 199;
      uVar5 = 0xa1;
      goto LAB_0060986c;
    }
    piVar4 = piVar9;
    iVar3 = (*pcVar15)(auStack_1a4,piVar9,pcVar14,puVar10,pAVar12,iVar3);
    if (iVar3 == 2) {
LAB_006098f4:
      uVar5 = (*(code *)PTR_ASN1_item_i2d_006a979c)(pcVar14,&iStack_1b0,piVar9);
      if (iStack_1b0 == 0) {
        uVar13 = 0x41;
        uVar5 = 0xcc;
        goto LAB_0060986c;
      }
      iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_1a4,iStack_1b0,uVar5);
      if (iVar3 == 0) {
        uVar5 = 0xd2;
      }
      else {
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(iStack_1b0,uVar5);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iStack_1b0);
        piVar4 = (int *)pAVar12->nid;
        iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a85c8)(auStack_1a4,piVar4,pAVar12->sn);
        if (0 < iVar3) {
          iVar3 = 1;
          goto LAB_00609810;
        }
        uVar5 = 0xdd;
      }
LAB_00609944:
      piVar4 = (int *)0xc5;
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc5,6,"a_verify.c",uVar5);
    }
  }
LAB_00609810:
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_1a4);
LAB_00609824:
  if (iStack_18c == *(int *)puVar1) {
    return iVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *piVar4 = *piVar4 + 1;
  return 1;
}

