
int CMS_RecipientInfo_ktri_cert_cmp(CMS_RecipientInfo *ri,X509 *cert)

{
  int iVar1;
  
  if (*(int *)ri == 0) {
    iVar1 = cms_SignerIdentifier_cert_cmp(*(undefined4 *)(*(int *)(ri + 4) + 4));
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8b,0x7c,"cms_env.c",0x10c);
  return -2;
}
