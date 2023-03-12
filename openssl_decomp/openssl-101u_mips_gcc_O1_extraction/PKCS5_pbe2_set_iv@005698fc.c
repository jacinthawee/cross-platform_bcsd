
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
  int *piVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
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
  
  puStack_104 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  salt_00 = (_union_257 *)salt;
  saltlen_00 = (char *)saltlen;
  iVar2 = (*(code *)PTR_EVP_CIPHER_type_006a8df8)();
  if (iVar2 == 0) {
    salt_00 = (_union_257 *)&DAT_0000006c;
    saltlen_00 = "p5_pbev2.c";
    ppXStack_118 = (X509_ALGOR **)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7);
    pXStack_114 = (X509_ALGOR *)0x0;
LAB_00569bbc:
    puStack_ec = PBE2PARAM_it;
    ASN1_item_free((ASN1_VALUE *)ppXStack_118,(ASN1_ITEM *)PBE2PARAM_it);
    X509_ALGOR_free((X509_ALGOR *)0x0);
    X509_ALGOR_free(pXStack_114);
    pXVar7 = (X509_ALGOR *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar2);
    ppXStack_118 = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    unaff_s2 = iVar2;
    if (ppXStack_118 == (X509_ALGOR **)0x0) {
LAB_00569bf8:
      pXVar7 = (X509_ALGOR *)0x0;
LAB_00569bfc:
      salt_00 = (_union_257 *)&DAT_00000041;
      saltlen_00 = "p5_pbev2.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7);
      pXStack_114 = pXVar7;
      goto LAB_00569bbc;
    }
    unaff_s4 = ppXStack_118[1];
    unaff_s4->algorithm = pAVar3;
    pAVar4 = ASN1_TYPE_new();
    unaff_s4->parameter = pAVar4;
    if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_00569bf8;
    iVar5 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(cipher);
    if (iVar5 != 0) {
      if (aiv != (uchar *)0x0) {
        uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)();
        (*(code *)PTR___memcpy_chk_006a9a48)(auStack_3c,aiv,uVar6,0x10);
        goto LAB_00569a0c;
      }
      uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(cipher);
      iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_3c,uVar6);
      if (0 < iVar5) goto LAB_00569a0c;
LAB_00569bb8:
      pXStack_114 = (X509_ALGOR *)0x0;
      goto LAB_00569bbc;
    }
LAB_00569a0c:
    (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_c8);
    saltlen_00 = (char *)0x0;
    salt_00 = (_union_257 *)0x0;
    iVar5 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(auStack_c8,cipher);
    if (iVar5 == 0) goto LAB_00569bb8;
    iVar5 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a8dfc)(auStack_c8,unaff_s4->parameter);
    if (iVar5 < 0) {
      salt_00 = (_union_257 *)0x72;
      saltlen_00 = "p5_pbev2.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7);
      pXStack_114 = (X509_ALGOR *)0x0;
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_c8);
      goto LAB_00569bbc;
    }
    if ((prf_nid == -1) &&
       (iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_ctrl_006a81f4)(auStack_c8,7,0,&prf_nid), iVar5 < 1)) {
      (*(code *)PTR_ERR_clear_error_006a6ee0)();
      prf_nid = 0xa3;
    }
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_c8);
    if (iVar2 == 0x25) {
      iVar2 = (*(code *)PTR_EVP_CIPHER_key_length_006a7554)(cipher);
    }
    else {
      iVar2 = -1;
    }
    X509_ALGOR_free(*ppXStack_118);
    saltlen_00 = (char *)prf_nid;
    pXVar7 = PKCS5_pbkdf2_set(iter,salt,saltlen,prf_nid,iVar2);
    *ppXStack_118 = pXVar7;
    if ((pXVar7 == (X509_ALGOR *)0x0) || (pXVar7 = X509_ALGOR_new(), pXVar7 == (X509_ALGOR *)0x0))
    goto LAB_00569bf8;
    pAVar4 = ASN1_TYPE_new();
    pXVar7->parameter = pAVar4;
    if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_00569bfc;
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0xa1);
    pXVar7->algorithm = pAVar3;
    salt_00 = &pXVar7->parameter->value;
    iVar2 = (*(code *)PTR_ASN1_item_pack_006a8df4)(ppXStack_118,PBE2PARAM_it);
    if (iVar2 == 0) goto LAB_00569bfc;
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
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_1bc = -1;
  puStack_fc = aiv;
  uStack_100 = 0x690000;
  iStack_11c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_110 = unaff_s2;
  pEStack_10c = cipher;
  pXStack_108 = unaff_s4;
  iStack_f8 = saltlen;
  iVar5 = (*(code *)PTR_EVP_CIPHER_type_006a8df8)();
  if (iVar5 == 0) {
    val = (X509_ALGOR **)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7,0x6c,"p5_pbev2.c",0x68);
    pXVar7 = (X509_ALGOR *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar5);
    val = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    if (val == (X509_ALGOR **)0x0) {
LAB_00569fcc:
      pXVar7 = (X509_ALGOR *)0x0;
    }
    else {
      pXVar7 = val[1];
      pXVar7->algorithm = pAVar3;
      pAVar4 = ASN1_TYPE_new();
      pXVar7->parameter = pAVar4;
      if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_00569fcc;
      iVar8 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(iVar2);
      if (iVar8 != 0) {
        uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(iVar2);
        iVar8 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_12c,uVar6);
        if (0 < iVar8) goto LAB_00569e04;
LAB_00569f8c:
        pXVar7 = (X509_ALGOR *)0x0;
        goto LAB_00569f90;
      }
LAB_00569e04:
      puStack_1c4 = auStack_12c;
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_1b8);
      iVar8 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(auStack_1b8,iVar2,0,0,puStack_1c4,0);
      if (iVar8 == 0) goto LAB_00569f8c;
      iVar8 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a8dfc)(auStack_1b8,pXVar7->parameter);
      if (iVar8 < 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7,0x72,"p5_pbev2.c",0x85);
        pXVar7 = (X509_ALGOR *)0x0;
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1b8);
        goto LAB_00569f90;
      }
      if ((iStack_1bc == -1) &&
         (iVar8 = (*(code *)PTR_EVP_CIPHER_CTX_ctrl_006a81f4)(auStack_1b8,7,0,&iStack_1bc),
         iVar8 < 1)) {
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        iStack_1bc = 0xa3;
      }
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_1b8);
      if (iVar5 == 0x25) {
        iVar2 = (*(code *)PTR_EVP_CIPHER_key_length_006a7554)(iVar2);
      }
      else {
        iVar2 = -1;
      }
      X509_ALGOR_free(*val);
      pXVar7 = PKCS5_pbkdf2_set((int)puStack_ec,(uchar *)&salt_00->boolean,(int)saltlen_00,
                                iStack_1bc,iVar2);
      *val = pXVar7;
      if ((pXVar7 == (X509_ALGOR *)0x0) || (pXVar7 = X509_ALGOR_new(), pXVar7 == (X509_ALGOR *)0x0))
      goto LAB_00569fcc;
      pAVar4 = ASN1_TYPE_new();
      pXVar7->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0xa1);
        pXVar7->algorithm = pAVar3;
        iVar2 = (*(code *)PTR_ASN1_item_pack_006a8df4)(val,PBE2PARAM_it,&pXVar7->parameter->value);
        if (iVar2 != 0) {
          puVar11 = PBE2PARAM_it;
          pXVar7->parameter->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
          goto LAB_00569f44;
        }
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7,0x41,"p5_pbev2.c",0xba);
  }
LAB_00569f90:
  puVar11 = PBE2PARAM_it;
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar7);
  pXVar7 = (X509_ALGOR *)0x0;
LAB_00569f44:
  if (iStack_11c == *(int *)puVar1) {
    return pXVar7;
  }
  iVar2 = iStack_11c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((((iVar2 == 2) && (piVar9 = *(int **)(*(int *)puVar11 + 0xc), piVar9 != (int *)0x0)) &&
      (*piVar9 == 4)) && (puVar10 = (undefined4 *)piVar9[1], puVar10 != (undefined4 *)0x0)) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar10[2],*puVar10);
    return (X509_ALGOR *)0x1;
  }
  return (X509_ALGOR *)0x1;
}

