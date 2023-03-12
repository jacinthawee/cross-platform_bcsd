
int CMS_RecipientInfo_ktri_get0_signer_id
              (CMS_RecipientInfo *ri,ASN1_OCTET_STRING **keyid,X509_NAME **issuer,ASN1_INTEGER **sno
              )

{
  int iVar1;
  
  if (*(int *)ri == 0) {
    iVar1 = cms_SignerIdentifier_get0_signer_id(*(undefined4 *)(*(int *)(ri + 4) + 4));
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x8f,0x7c,"cms_env.c",0x100);
  return 0;
}

