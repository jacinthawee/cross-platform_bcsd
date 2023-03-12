
undefined4
rsa_pkey_ctrl(undefined4 param_1,undefined4 param_2,int param_3,PKCS7_SIGNER_INFO *param_4)

{
  X509_ALGOR *alg;
  ASN1_OBJECT *aobj;
  X509_ALGOR *local_14 [2];
  
  local_14[0] = (X509_ALGOR *)0x0;
  switch(param_2) {
  case 1:
    if (param_3 != 0) {
      return 1;
    }
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,(X509_ALGOR **)0x0,local_14);
    break;
  case 2:
    if (param_3 != 0) {
      return 1;
    }
    PKCS7_RECIP_INFO_get0_alg((PKCS7_RECIP_INFO *)param_4,local_14);
    break;
  case 3:
    param_4->version = (ASN1_INTEGER *)0x40;
    return 1;
  default:
    return 0xfffffffe;
  case 5:
    if (param_3 != 0) {
      return 1;
    }
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,(X509_ALGOR **)0x0,local_14);
    break;
  case 7:
    if (param_3 != 0) {
      return 1;
    }
    CMS_RecipientInfo_ktri_get0_algs
              ((CMS_RecipientInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,local_14);
  }
  alg = local_14[0];
  if (local_14[0] != (X509_ALGOR *)0x0) {
    aobj = OBJ_nid2obj(6);
    X509_ALGOR_set0(alg,aobj,5,(void *)0x0);
  }
  return 1;
}

