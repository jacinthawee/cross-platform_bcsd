
X509_SIG *
PKCS8_encrypt(int pbe_nid,EVP_CIPHER *cipher,char *pass,int passlen,uchar *salt,int saltlen,int iter
             ,PKCS8_PRIV_KEY_INFO *p8)

{
  undefined *puVar1;
  X509_SIG *pXVar2;
  X509_ALGOR *algor;
  ASN1_OCTET_STRING *pAVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pXVar2 = (X509_SIG *)(*(code *)PTR_X509_SIG_new_006a8fcc)();
  if (pXVar2 == (X509_SIG *)0x0) {
    uVar5 = 0x41;
    uVar4 = 0x49;
  }
  else {
    if (pbe_nid == -1) {
      algor = (X509_ALGOR *)(*(code *)PTR_PKCS5_pbe2_set_006a91dc)(cipher,iter,salt,saltlen);
    }
    else {
      algor = (X509_ALGOR *)(*(code *)PTR_PKCS5_pbe_set_006a91e4)(pbe_nid,iter,salt,saltlen);
    }
    if (algor == (X509_ALGOR *)0x0) {
      uVar5 = 0xd;
      uVar4 = 0x52;
    }
    else {
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(pXVar2->algor);
      puVar1 = PTR_ASN1_STRING_free_006a879c;
      pXVar2->algor = algor;
      (*(code *)puVar1)(pXVar2->digest);
      pAVar3 = PKCS12_item_i2d_encrypt
                         (algor,(ASN1_ITEM *)PTR_PKCS8_PRIV_KEY_INFO_it_006a924c,pass,passlen,p8,1);
      pXVar2->digest = pAVar3;
      if (pAVar3 != (ASN1_OCTET_STRING *)0x0) {
        return pXVar2;
      }
      uVar5 = 0x67;
      uVar4 = 0x5c;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x7d,uVar5,"p12_p8e.c",uVar4);
  (*(code *)PTR_X509_SIG_free_006a7ca8)(pXVar2);
  return (X509_SIG *)0x0;
}

