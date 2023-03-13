
undefined4
pkey_ctrl_gost(EVP_PKEY *param_1,undefined4 param_2,int param_3,PKCS7_SIGNER_INFO *param_4)

{
  int n;
  ASN1_OBJECT *pAVar1;
  void *pval;
  undefined4 uVar2;
  int in_GS_OFFSET;
  X509_ALGOR *local_28;
  X509_ALGOR *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  switch(param_2) {
  default:
    uVar2 = 0xfffffffe;
    goto LAB_081d9128;
  case 1:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_081d9128;
    local_28 = (X509_ALGOR *)0x0;
    local_24 = (X509_ALGOR *)0x0;
    n = EVP_PKEY_base_id(param_1);
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,&local_28,&local_24);
    goto LAB_081d9182;
  case 2:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_081d9128;
    pval = (void *)encode_gost_algor_params();
    if (pval != (void *)0x0) {
      PKCS7_RECIP_INFO_get0_alg((PKCS7_RECIP_INFO *)param_4,&local_24);
LAB_081d925c:
      uVar2 = 1;
      pAVar1 = OBJ_nid2obj(param_1->type);
      X509_ALGOR_set0(local_24,pAVar1,0x10,pval);
      goto LAB_081d9128;
    }
    break;
  case 3:
    param_4->version = (ASN1_INTEGER *)0x329;
    uVar2 = 2;
    goto LAB_081d9128;
  case 5:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_081d9128;
    local_28 = (X509_ALGOR *)0x0;
    local_24 = (X509_ALGOR *)0x0;
    n = EVP_PKEY_base_id(param_1);
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_28,&local_24);
LAB_081d9182:
    uVar2 = 1;
    pAVar1 = OBJ_nid2obj(0x329);
    X509_ALGOR_set0(local_28,pAVar1,5,(void *)0x0);
    if (n != 0) {
      pAVar1 = OBJ_nid2obj(n);
      X509_ALGOR_set0(local_24,pAVar1,5,(void *)0x0);
      goto LAB_081d9128;
    }
    break;
  case 7:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_081d9128;
    local_24 = (X509_ALGOR *)0x0;
    pval = (void *)encode_gost_algor_params();
    if (pval != (void *)0x0) {
      CMS_RecipientInfo_ktri_get0_algs
                ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_24);
      goto LAB_081d925c;
    }
  }
  uVar2 = 0xffffffff;
LAB_081d9128:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

