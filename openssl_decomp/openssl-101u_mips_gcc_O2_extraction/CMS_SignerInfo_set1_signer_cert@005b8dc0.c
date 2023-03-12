
void CMS_SignerInfo_set1_signer_cert(CMS_SignerInfo *si,X509 *signer)

{
  undefined4 uVar1;
  
  if (signer != (X509 *)0x0) {
    (*(code *)PTR_CRYPTO_add_lock_006a805c)(&signer->references,1,3,"cms_sd.c",0x1e2);
    if (*(int *)(si + 0x20) != 0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
    }
    uVar1 = (*(code *)PTR_X509_get_pubkey_006a6f08)(signer);
    *(undefined4 *)(si + 0x20) = uVar1;
  }
  if (*(int *)(si + 0x1c) != 0) {
    (*(code *)PTR_X509_free_006a6e90)();
  }
  *(X509 **)(si + 0x1c) = signer;
  return;
}

