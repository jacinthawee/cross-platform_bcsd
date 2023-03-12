
X509_ALGOR * PKCS5_pbe2_set(EVP_CIPHER *cipher,int iter,uchar *salt,int saltlen)

{
  undefined *puVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  X509_ALGOR **val;
  ASN1_TYPE *pAVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  X509_ALGOR *pXVar10;
  undefined *local_d4;
  int local_cc;
  undefined auStack_c8 [140];
  undefined auStack_3c [16];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_cc = -1;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_EVP_CIPHER_type_006a8df8)();
  if (iVar2 == 0) {
    val = (X509_ALGOR **)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7,0x6c,"p5_pbev2.c",0x68);
    pXVar10 = (X509_ALGOR *)0x0;
  }
  else {
    pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(iVar2);
    val = (X509_ALGOR **)ASN1_item_new((ASN1_ITEM *)PBE2PARAM_it);
    if (val == (X509_ALGOR **)0x0) {
LAB_00569fcc:
      pXVar10 = (X509_ALGOR *)0x0;
    }
    else {
      pXVar10 = val[1];
      pXVar10->algorithm = pAVar3;
      pAVar4 = ASN1_TYPE_new();
      pXVar10->parameter = pAVar4;
      if (pAVar4 == (ASN1_TYPE *)0x0) goto LAB_00569fcc;
      iVar5 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(cipher);
      if (iVar5 != 0) {
        uVar6 = (*(code *)PTR_EVP_CIPHER_iv_length_006a7550)(cipher);
        iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(auStack_3c,uVar6);
        if (0 < iVar5) goto LAB_00569e04;
LAB_00569f8c:
        pXVar10 = (X509_ALGOR *)0x0;
        goto LAB_00569f90;
      }
LAB_00569e04:
      local_d4 = auStack_3c;
      (*(code *)PTR_EVP_CIPHER_CTX_init_006a7a64)(auStack_c8);
      iVar5 = (*(code *)PTR_EVP_CipherInit_ex_006a7560)(auStack_c8,cipher,0,0,local_d4,0);
      if (iVar5 == 0) goto LAB_00569f8c;
      iVar5 = (*(code *)PTR_EVP_CIPHER_param_to_asn1_006a8dfc)(auStack_c8,pXVar10->parameter);
      if (iVar5 < 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7,0x72,"p5_pbev2.c",0x85);
        pXVar10 = (X509_ALGOR *)0x0;
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_c8);
        goto LAB_00569f90;
      }
      if ((local_cc == -1) &&
         (iVar5 = (*(code *)PTR_EVP_CIPHER_CTX_ctrl_006a81f4)(auStack_c8,7,0,&local_cc), iVar5 < 1))
      {
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
        local_cc = 0xa3;
      }
      (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a7a74)(auStack_c8);
      if (iVar2 == 0x25) {
        iVar2 = (*(code *)PTR_EVP_CIPHER_key_length_006a7554)(cipher);
      }
      else {
        iVar2 = -1;
      }
      X509_ALGOR_free(*val);
      pXVar10 = PKCS5_pbkdf2_set(iter,salt,saltlen,local_cc,iVar2);
      *val = pXVar10;
      if ((pXVar10 == (X509_ALGOR *)0x0) ||
         (pXVar10 = X509_ALGOR_new(), pXVar10 == (X509_ALGOR *)0x0)) goto LAB_00569fcc;
      pAVar4 = ASN1_TYPE_new();
      pXVar10->parameter = pAVar4;
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a7140)(0xa1);
        pXVar10->algorithm = pAVar3;
        iVar2 = (*(code *)PTR_ASN1_item_pack_006a8df4)(val,PBE2PARAM_it,&pXVar10->parameter->value);
        if (iVar2 != 0) {
          puVar9 = PBE2PARAM_it;
          pXVar10->parameter->type = 0x10;
          ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
          goto LAB_00569f44;
        }
      }
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa7,0x41,"p5_pbev2.c",0xba);
  }
LAB_00569f90:
  puVar9 = PBE2PARAM_it;
  ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PBE2PARAM_it);
  X509_ALGOR_free((X509_ALGOR *)0x0);
  X509_ALGOR_free(pXVar10);
  pXVar10 = (X509_ALGOR *)0x0;
LAB_00569f44:
  if (local_2c == *(int *)puVar1) {
    return pXVar10;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((((iVar2 == 2) && (piVar7 = *(int **)(*(int *)puVar9 + 0xc), piVar7 != (int *)0x0)) &&
      (*piVar7 == 4)) && (puVar8 = (undefined4 *)piVar7[1], puVar8 != (undefined4 *)0x0)) {
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar8[2],*puVar8);
    return (X509_ALGOR *)0x1;
  }
  return (X509_ALGOR *)0x1;
}

