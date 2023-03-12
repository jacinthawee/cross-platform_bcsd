
int PKCS7_dataVerify(X509_STORE *cert_store,X509_STORE_CTX *ctx,BIO *bio,PKCS7 *p7,
                    PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  X509 *x509;
  undefined4 uVar2;
  undefined4 uVar3;
  uchar *puVar4;
  
  if (p7 == (PKCS7 *)0x0) {
    uVar3 = 0x8f;
    uVar2 = 0x3d3;
  }
  else if ((p7->d).ptr == (char *)0x0) {
    uVar3 = 0x7a;
    uVar2 = 0x3d8;
  }
  else {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
    if ((iVar1 == 0x16) || (iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type), iVar1 == 0x18)) {
      puVar4 = ((p7->d).data)->data;
      x509 = (X509 *)(*(code *)PTR_X509_find_by_issuer_and_serial_006a9138)
                               (puVar4,si->issuer_and_serial->issuer,si->issuer_and_serial->serial);
      if (x509 == (X509 *)0x0) {
        uVar3 = 0x6a;
        uVar2 = 0x3ec;
      }
      else {
        iVar1 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(ctx,cert_store,x509,puVar4);
        if (iVar1 != 0) {
          (*(code *)PTR_X509_STORE_CTX_set_purpose_006a9168)(ctx,4);
          iVar1 = (*(code *)PTR_X509_verify_cert_006a728c)(ctx);
          if (iVar1 < 1) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x6b,0xb,"pk7_doit.c",0x3f8);
            (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(ctx);
            return 0;
          }
          (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(ctx);
          iVar1 = PKCS7_signatureVerify(bio,p7,si,x509);
          return iVar1;
        }
        uVar3 = 0xb;
        uVar2 = 0x3f2;
      }
    }
    else {
      uVar3 = 0x72;
      uVar2 = 0x3e1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x6b,uVar3,"pk7_doit.c",uVar2);
  return 0;
}

