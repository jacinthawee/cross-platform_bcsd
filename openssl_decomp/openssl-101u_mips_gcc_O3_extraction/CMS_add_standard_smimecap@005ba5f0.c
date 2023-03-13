
int CMS_add_standard_smimecap(stack_st_X509_ALGOR **smcap)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  stack_st_X509_ALGOR *psVar4;
  
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x1ab);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1ab);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) goto LAB_005ba698;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x329);
  iVar2 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x329);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) goto LAB_005ba698;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x32d);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x32d);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) goto LAB_005ba698;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x1a7);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1a7);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) goto LAB_005ba698;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x1a3);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1a3);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) goto LAB_005ba698;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x2c);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x2c);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) goto LAB_005ba698;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x25);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
    if (iVar2 == 0) {
      return 0;
    }
    iVar3 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar2,0x80);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar3 == 0) {
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar2);
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x25);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar3,uVar1,2,iVar2);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005baa08;
    }
    iVar2 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar3);
    if (iVar2 == 0) {
LAB_005baa08:
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(iVar3);
      return 0;
    }
  }
  iVar2 = cms_add_cipher_smcap(smcap,0x25,0x40);
  if (iVar2 == 0) {
    return 0;
  }
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(0x1f);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x1f);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,0xffffffff,0);
    psVar4 = *smcap;
    if (psVar4 == (stack_st_X509_ALGOR *)0x0) {
      psVar4 = (stack_st_X509_ALGOR *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *smcap = psVar4;
      if (psVar4 == (stack_st_X509_ALGOR *)0x0) goto LAB_005ba698;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar4,iVar2);
    if (iVar3 == 0) {
LAB_005ba698:
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(iVar2);
      return 0;
    }
  }
  iVar2 = cms_add_cipher_smcap(smcap,0x25,0x28);
  return (uint)(iVar2 != 0);
}

