
undefined4 dsa_pkey_ctrl(EVP_PKEY *param_1,int param_2,int param_3,PKCS7_SIGNER_INFO *param_4)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT *pAVar3;
  int local_24;
  X509_ALGOR *local_20;
  X509_ALGOR *local_1c [2];
  
  if (param_2 == 3) {
    param_4->version = (ASN1_INTEGER *)0x40;
    return 2;
  }
  if (param_2 == 5) {
    if (param_3 != 0) {
      return 1;
    }
    CMS_SignerInfo_get0_algs
              ((CMS_SignerInfo *)param_4,(EVP_PKEY **)0x0,(X509 **)0x0,&local_20,local_1c);
    if (((local_20 != (X509_ALGOR *)0x0) && (local_20->algorithm != (ASN1_OBJECT *)0x0)) &&
       (iVar1 = OBJ_obj2nid(local_20->algorithm), iVar1 != 0)) {
      iVar2 = EVP_PKEY_id(param_1);
      iVar1 = OBJ_find_sigid_by_algs(&local_24,iVar1,iVar2);
      if (iVar1 != 0) {
        pAVar3 = OBJ_nid2obj(local_24);
        X509_ALGOR_set0(local_1c[0],pAVar3,-1,(void *)0x0);
        return 1;
      }
    }
  }
  else {
    if (param_2 != 1) {
      return 0xfffffffe;
    }
    if (param_3 != 0) {
      return 1;
    }
    PKCS7_SIGNER_INFO_get0_algs(param_4,(EVP_PKEY **)0x0,&local_20,local_1c);
    if (((local_20 != (X509_ALGOR *)0x0) && (local_20->algorithm != (ASN1_OBJECT *)0x0)) &&
       (iVar1 = OBJ_obj2nid(local_20->algorithm), iVar1 != 0)) {
      iVar2 = EVP_PKEY_id(param_1);
      iVar1 = OBJ_find_sigid_by_algs(&local_24,iVar1,iVar2);
      if (iVar1 != 0) {
        pAVar3 = OBJ_nid2obj(local_24);
        X509_ALGOR_set0(local_1c[0],pAVar3,-1,(void *)0x0);
        return 1;
      }
    }
  }
  return 0xffffffff;
}

