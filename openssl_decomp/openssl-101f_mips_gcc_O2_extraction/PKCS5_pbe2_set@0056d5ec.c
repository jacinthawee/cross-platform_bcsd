
X509_ALGOR * PKCS5_pbe2_set(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen)

{
  undefined *puVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  X509_ALGOR **val;
  ASN1_TYPE *pAVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  X509_ALGOR *pXVar9;
  undefined *local_d4;
  int local_cc;
  undefined auStack_c8 [140];
  undefined auStack_3c [16];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_cc = -1;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_CIPHER_type_006a9d90)();
  if (iVar2 == 0) {
    val = (X509_ALGOR **)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7,0x6c,"p5_pbev2.c",0x67);
    pXVar9 = (X509_ALGOR *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2);
    val = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    if (val == (X509_ALGOR **)0x0) {
LAB_0056d8bc:
      pXVar9 = (X509_ALGOR *)0x0;
    }
    else {
      pXVar9 = val[1];
      pXVar9->algorithm = pAVar3;
      pAVar4 = ASN1_TYPE_new();
      pXVar9->parameter = pAVar4;
      if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_0056d8bc;
      iVar5 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(cipher);
      if (iVar5 != 0) {
        uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a865c)(cipher);
        iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(auStack_3c,uVar6);
        if (-1 < iVar5) goto LAB_0056d6f4;
LAB_0056d87c:
        pXVar9 = (X509_ALGOR *)0x0;
        goto LAB_0056d880;
      }
LAB_0056d6f4:
      local_d4 = auStack_3c;
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a8b50)(auStack_c8);
      iVar5 = (*(code *)PTR_EVP_CipherInit_ex_006a864c)(auStack_c8,cipher,0,0,local_d4,0);
      if (iVar5 == 0) goto LAB_0056d87c;
      iVar5 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a9f18)(auStack_c8,pXVar9->parameter);
      if (iVar5 < 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7,0x72,"p5_pbev2.c",0x84);
        pXVar9 = (X509_ALGOR *)0x0;
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_c8);
        goto LAB_0056d880;
      }
      if ((local_cc == -1) &&
         (iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_ctrl_006a9320)(auStack_c8,7,0,&local_cc), iVar5 < 1))
      {
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
        local_cc = 0xa3;
      }
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)(auStack_c8);
      if (iVar2 == 0x25) {
        iVar2 = (*(code *)PTR_EVP_CIPHER_key_length_006a903c)(cipher);
      }
      else {
        iVar2 = -1;
      }
      X509_ALGOR_free(*val);
      pXVar9 = PKCS5_pbkdf2_set(iter,salt,saltlen,local_cc,iVar2);
      *val = pXVar9;
      if ((pXVar9 == (X509_ALGOR *)0x0) || (pXVar9 = X509_ALGOR_new(), pXVar9 == (X509_ALGOR *)0x0))
      goto LAB_0056d8bc;
      pAVar4 = ASN1_TYPE_new();
      pXVar9->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(0xa1);
        pXVar9->algorithm = pAVar3;
        iVar2 = (*(code *)PTR_ASN1_item_pack_006a9f14)(val,PBE2PARAM_it,&pXVar9->parameter->value);
        if (iVar2 != 0) {
          puVar8 = PBE2PARAM_it;
          pXVar9->parameter->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
          goto LAB_0056d834;
        }
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xa7,0x41,"p5_pbev2.c",0xb6);
  }
LAB_0056d880:
  puVar8 = PBE2PARAM_it;
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar9);
  pXVar9 = (X509_ALGOR *)0x0;
LAB_0056d834:
  if (local_2c == *(int *)puVar1) {
    return pXVar9;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((iVar2 == 2) &&
     (puVar7 = *(undefined4 **)(*(int *)(*(int *)puVar8 + 0xc) + 4), puVar7 != (undefined4 *)0x0)) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar7[2],*puVar7);
    return (X509_ALGOR *)0x1;
  }
  return (X509_ALGOR *)0x1;
}

