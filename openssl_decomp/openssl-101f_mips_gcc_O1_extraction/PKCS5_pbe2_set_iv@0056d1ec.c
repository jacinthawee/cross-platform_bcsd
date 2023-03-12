
X509_ALGOR *
PKCS5_pbe2_set_iv(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen,uchar *aiv,int prf_nid)

{
  undefined *puVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  ASN1_TYPE *pAVar4;
  int iVar5;
  undefined4 uVar6;
  X509_ALGOR *pXVar7;
  X509_ALGOR **val;
  int iVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  _union_257 *salt_00;
  char *saltlen_00;
  int unaff_s2;
  X509_ALGOR *unaff_s4;
  undefined *puStack_1c4;
  int iStack_1bc;
  undefined auStack_1b8 [140];
  undefined auStack_12c [16];
  int iStack_11c;
  X509_ALGOR **ppXStack_118;
  X509_ALGOR *pXStack_114;
  int iStack_110;
  EVP_CIPHER *pEStack_10c;
  X509_ALGOR *pXStack_108;
  undefined *puStack_104;
  undefined4 uStack_100;
  uchar *puStack_fc;
  int iStack_f8;
  code *pcStack_f4;
  undefined1 *puStack_ec;
  undefined auStack_c8 [140];
  undefined auStack_3c [16];
  int local_2c;
  
  puStack_104 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  salt_00 = (_union_257 *)salt;
  saltlen_00 = (char *)saltlen;
  iVar2 = (*(code *)PTR_EVP_CIPHER_type_006a9d90)();
  if (iVar2 == 0) {
    salt_00 = (_union_257 *)&DAT_0000006c;
    saltlen_00 = "p5_pbev2.c";
    ppXStack_118 = (X509_ALGOR **)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7);
    pXStack_114 = (X509_ALGOR *)0x0;
LAB_0056d4ac:
    puStack_ec = PBE2PARAM_it;
    ASN1_item_free((ASN1_VALUE *)ppXStack_118,(ASN1_ITEM *)PBE2PARAM_it);
    X509_ALGOR_free((X509_ALGOR *)0x0);
    X509_ALGOR_free(pXStack_114);
    pXVar7 = (X509_ALGOR *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
    ppXStack_118 = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    unaff_s2 = iVar2;
    if (ppXStack_118 == (X509_ALGOR **)0x0) {
LAB_0056d4e8:
      pXVar7 = (X509_ALGOR *)0x0;
LAB_0056d4ec:
      salt_00 = (_union_257 *)&DAT_00000041;
      saltlen_00 = "p5_pbev2.c";
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7);
      pXStack_114 = pXVar7;
      goto LAB_0056d4ac;
    }
    unaff_s4 = ppXStack_118[1];
    unaff_s4->algorithm = pAVar3;
    pAVar4 = ASN1_TYPE_new();
    unaff_s4->parameter = pAVar4;
    if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_0056d4e8;
    iVar5 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(cipher);
    if (iVar5 != 0) {
      if (aiv != (uchar *)0x0) {
        uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)();
        (*(code *)PTR___memcpy_chk_006aab54)(auStack_3c,aiv,uVar6,0x10);
        goto LAB_0056d2fc;
      }
      uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(cipher);
      iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_3c,uVar6);
      if (-1 < iVar5) goto LAB_0056d2fc;
LAB_0056d4a8:
      pXStack_114 = (X509_ALGOR *)0x0;
      goto LAB_0056d4ac;
    }
LAB_0056d2fc:
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_c8);
    saltlen_00 = (char *)0x0;
    salt_00 = (_union_257 *)0x0;
    iVar5 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(auStack_c8,cipher);
    if (iVar5 == 0) goto LAB_0056d4a8;
    iVar5 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a9f18)(auStack_c8,unaff_s4->parameter);
    if (iVar5 < 0) {
      salt_00 = (_union_257 *)0x72;
      saltlen_00 = "p5_pbev2.c";
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7);
      pXStack_114 = (X509_ALGOR *)0x0;
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_c8);
      goto LAB_0056d4ac;
    }
    if ((prf_nid == -1) &&
       (iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_ctrl_006a9320)(auStack_c8,7,0,&prf_nid), iVar5 < 1)) {
      (*(code *)PTR_ERR_clear_error_006a7fe0)();
      prf_nid = 0xa3;
    }
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_c8);
    if (iVar2 == 0x25) {
      iVar2 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(cipher);
    }
    else {
      iVar2 = -1;
    }
    X509_ALGOR_free(*ppXStack_118);
    saltlen_00 = (char *)prf_nid;
    pXVar7 = PKCS5_pbkdf2_set(iter,salt,saltlen,prf_nid,iVar2);
    *ppXStack_118 = pXVar7;
    if ((pXVar7 == (X509_ALGOR *)0x0) || (pXVar7 = X509_ALGOR_new(), pXVar7 == (X509_ALGOR *)0x0))
    goto LAB_0056d4e8;
    pAVar4 = ASN1_TYPE_new();
    pXVar7->parameter = pAVar4;
    if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_0056d4ec;
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0xa1);
    pXVar7->algorithm = pAVar3;
    salt_00 = &pXVar7->parameter->value;
    iVar2 = (*(code *)PTR_ASN1_item_pack_006a9f14)(ppXStack_118,PBE2PARAM_it);
    if (iVar2 == 0) goto LAB_0056d4ec;
    puStack_ec = PBE2PARAM_it;
    pXVar7->parameter->type = 0x10;
    ASN1_item_free((ASN1_VALUE *)ppXStack_118,(ASN1_ITEM *)PBE2PARAM_it);
    pXStack_114 = pXVar7;
  }
  if (local_2c == *(int *)puStack_104) {
    return pXVar7;
  }
  pcStack_f4 = PKCS5_pbe2_set;
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_1bc = -1;
  puStack_fc = aiv;
  uStack_100 = 0x690000;
  iStack_11c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_110 = unaff_s2;
  pEStack_10c = cipher;
  pXStack_108 = unaff_s4;
  iStack_f8 = saltlen;
  iVar5 = (*(code *)PTR_EVP_CIPHER_type_006a9d90)();
  if (iVar5 == 0) {
    val = (X509_ALGOR **)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7,0x6c,"p5_pbev2.c",0x67);
    pXVar7 = (X509_ALGOR *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar5);
    val = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    if (val == (X509_ALGOR **)0x0) {
LAB_0056d8bc:
      pXVar7 = (X509_ALGOR *)0x0;
    }
    else {
      pXVar7 = val[1];
      pXVar7->algorithm = pAVar3;
      pAVar4 = ASN1_TYPE_new();
      pXVar7->parameter = pAVar4;
      if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_0056d8bc;
      iVar8 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(iVar2);
      if (iVar8 != 0) {
        uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(iVar2);
        iVar8 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_12c,uVar6);
        if (-1 < iVar8) goto LAB_0056d6f4;
LAB_0056d87c:
        pXVar7 = (X509_ALGOR *)0x0;
        goto LAB_0056d880;
      }
LAB_0056d6f4:
      puStack_1c4 = auStack_12c;
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_1b8);
      iVar8 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(auStack_1b8,iVar2,0,0,puStack_1c4,0);
      if (iVar8 == 0) goto LAB_0056d87c;
      iVar8 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a9f18)(auStack_1b8,pXVar7->parameter);
      if (iVar8 < 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7,0x72,"p5_pbev2.c",0x84);
        pXVar7 = (X509_ALGOR *)0x0;
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_1b8);
        goto LAB_0056d880;
      }
      if ((iStack_1bc == -1) &&
         (iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_ctrl_006a9320)(auStack_1b8,7,0,&iStack_1bc),
         iVar8 < 1)) {
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        iStack_1bc = 0xa3;
      }
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_1b8);
      if (iVar5 == 0x25) {
        iVar2 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(iVar2);
      }
      else {
        iVar2 = -1;
      }
      X509_ALGOR_free(*val);
      pXVar7 = PKCS5_pbkdf2_set((int)puStack_ec,(uchar *)&salt_00->boolean,(int)saltlen_00,
                                iStack_1bc,iVar2);
      *val = pXVar7;
      if ((pXVar7 == (X509_ALGOR *)0x0) || (pXVar7 = X509_ALGOR_new(), pXVar7 == (X509_ALGOR *)0x0))
      goto LAB_0056d8bc;
      pAVar4 = ASN1_TYPE_new();
      pXVar7->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0xa1);
        pXVar7->algorithm = pAVar3;
        iVar2 = (*(code *)PTR_ASN1_item_pack_006a9f14)(val,PBE2PARAM_it,&pXVar7->parameter->value);
        if (iVar2 != 0) {
          puVar10 = PBE2PARAM_it;
          pXVar7->parameter->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
          goto LAB_0056d834;
        }
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7,0x41,"p5_pbev2.c",0xb6);
  }
LAB_0056d880:
  puVar10 = PBE2PARAM_it;
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar7);
  pXVar7 = (X509_ALGOR *)0x0;
LAB_0056d834:
  if (iStack_11c == *(int *)puVar1) {
    return pXVar7;
  }
  iVar2 = iStack_11c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((iVar2 == 2) &&
     (puVar9 = *(undefined4 **)(*(int *)(*(int *)puVar10 + 0xc) + 4), puVar9 != (undefined4 *)0x0))
  {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar9[2],*puVar9);
    return (X509_ALGOR *)0x1;
  }
  return (X509_ALGOR *)0x1;
}

