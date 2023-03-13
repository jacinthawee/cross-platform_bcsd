
undefined4
rsa_pkey_ctrl(undefined4 param_1,undefined4 param_2,int param_3,PKCS7_SIGNER_INFO *param_4)

{
  ASN1_OBJECT *aobj;
  undefined4 uVar1;
  int in_GS_OFFSET;
  X509_ALGOR *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (X509_ALGOR *)0x0;
  switch(param_2) {
  default:
    uVar1 = 0xfffffffe;
    goto LAB_081bfb55;
  case 1:
    if (param_3 == 0) {
      PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,(X509_ALGOR **)0x0,&local_14);
LAB_081bfbdf:
      if (local_14 != (X509_ALGOR *)0x0) {
        aobj = OBJ_nid2obj(6);
        X509_ALGOR_set0(local_14,aobj,5,(void *)0x0);
        uVar1 = 1;
        goto LAB_081bfb55;
      }
    }
    break;
  case 2:
    if (param_3 == 0) {
      PKCS7_RECIP_INFO_get0_alg((PKCS7_RECIP_INFO *)param_4,&local_14);
      goto LAB_081bfbdf;
    }
    break;
  case 3:
    param_4->version = (ASN1_INTEGER *)0x40;
    break;
  case 5:
    if (param_3 == 0) {
      CMS_SignerInfo_get0_algs
                ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)0x0,
                 &local_14);
      goto LAB_081bfbdf;
    }
    break;
  case 7:
    if (param_3 == 0) {
      CMS_RecipientInfo_ktri_get0_algs
                ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_14);
      goto LAB_081bfbdf;
    }
  }
  uVar1 = 1;
LAB_081bfb55:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

