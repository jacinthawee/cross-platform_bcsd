
PKCS7 * PKCS12_pack_p7encdata
                  (int pbe_nid,char *pass,int passlen,uchar *salt,int saltlen,int iter,
                  stack_st_PKCS12_SAFEBAG *bags)

{
  undefined *puVar1;
  PKCS7 *p7;
  int iVar2;
  undefined4 uVar3;
  X509_ALGOR *algor;
  PKCS7_ENC_CONTENT *pPVar4;
  ASN1_OCTET_STRING *pAVar5;
  undefined4 uVar6;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x73,0x41,"p12_add.c",0xbb);
    return (PKCS7 *)0x0;
  }
  iVar2 = PKCS7_set_type(p7,0x1a);
  if (iVar2 == 0) {
    uVar6 = 0x78;
    uVar3 = 0xc0;
  }
  else {
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(pbe_nid);
    iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar3);
    if (iVar2 == 0) {
      algor = (X509_ALGOR *)(*(code *)PTR_PKCS5_pbe_set_006a91e4)(pbe_nid,iter,salt,saltlen);
    }
    else {
      algor = (X509_ALGOR *)(*(code *)PTR_PKCS5_pbe2_set_006a91dc)(iVar2,iter,salt,saltlen);
    }
    if (algor == (X509_ALGOR *)0x0) {
      uVar6 = 0x41;
      uVar3 = 0xcc;
    }
    else {
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)((((p7->d).sign)->md_algs->stack).data);
      puVar1 = PTR_ASN1_STRING_free_006a879c;
      pPVar4 = ((p7->d).encrypted)->enc_data;
      pPVar4->algorithm = algor;
      (*(code *)puVar1)(pPVar4->enc_data);
      pPVar4 = ((p7->d).encrypted)->enc_data;
      pAVar5 = PKCS12_item_i2d_encrypt
                         (algor,(ASN1_ITEM *)PTR_PKCS12_SAFEBAGS_it_006a91d4,pass,passlen,bags,1);
      pPVar4->enc_data = pAVar5;
      if (pAVar5 != (ASN1_OCTET_STRING *)0x0) {
        return p7;
      }
      uVar6 = 0x67;
      uVar3 = 0xd5;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x23,0x73,uVar6,"p12_add.c",uVar3);
  PKCS7_free(p7);
  return (PKCS7 *)0x0;
}

