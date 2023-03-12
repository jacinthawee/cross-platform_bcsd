
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
    (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x73,0x41,"p12_add.c",0xb0);
    return (PKCS7 *)0x0;
  }
  iVar2 = PKCS7_set_type(p7,0x1a);
  if (iVar2 == 0) {
    uVar6 = 0x78;
    uVar3 = 0xb5;
  }
  else {
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(pbe_nid);
    iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar3);
    if (iVar2 == 0) {
      algor = (X509_ALGOR *)(*(code *)PTR_PKCS5_pbe_set_006aa2fc)(pbe_nid,iter,salt,saltlen);
    }
    else {
      algor = (X509_ALGOR *)(*(code *)PTR_PKCS5_pbe2_set_006aa2f4)(iVar2,iter,salt,saltlen);
    }
    if (algor != (X509_ALGOR *)0x0) {
      (*(code *)PTR_X509_ALGOR_free_006a8f94)((((p7->d).sign)->md_algs->stack).data);
      puVar1 = PTR_ASN1_STRING_free_006a98bc;
      pPVar4 = ((p7->d).encrypted)->enc_data;
      pPVar4->algorithm = algor;
      (*(code *)puVar1)(pPVar4->enc_data);
      pPVar4 = ((p7->d).encrypted)->enc_data;
      pAVar5 = PKCS12_item_i2d_encrypt
                         (algor,(ASN1_ITEM *)PTR_PKCS12_SAFEBAGS_it_006aa2ec,pass,passlen,bags,1);
      pPVar4->enc_data = pAVar5;
      if (pAVar5 != (ASN1_OCTET_STRING *)0x0) {
        return p7;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x73,0x67,"p12_add.c",0xca);
      return (PKCS7 *)0x0;
    }
    uVar6 = 0x41;
    uVar3 = 0xc1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x73,uVar6,"p12_add.c",uVar3);
  return (PKCS7 *)0x0;
}

