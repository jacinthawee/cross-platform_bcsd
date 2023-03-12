
PKCS7 * PKCS7_sign(X509 *signcert,EVP_PKEY *pkey,stack_st_X509 *certs,BIO *data,int flags)

{
  PKCS7 *p7;
  int iVar1;
  PKCS7_SIGNER_INFO *pPVar2;
  X509 *x509;
  BIO *out;
  uint uVar3;
  BIO *bio;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x74,0x41,"pk7_smime.c",0x4c);
    return (PKCS7 *)0x0;
  }
  iVar1 = PKCS7_set_type(p7,0x16);
  if ((iVar1 != 0) && (iVar1 = PKCS7_content_new(p7,0x15), iVar1 != 0)) {
    if ((pkey == (EVP_PKEY *)0x0) ||
       (pPVar2 = PKCS7_sign_add_signer(p7,signcert,pkey,(EVP_MD *)0x0,flags),
       pPVar2 != (PKCS7_SIGNER_INFO *)0x0)) {
      uVar3 = flags & 2U;
      if ((flags & 2U) == 0) {
        do {
          iVar1 = sk_num(&certs->stack);
          if (iVar1 <= (int)uVar3) goto LAB_000de326;
          x509 = (X509 *)sk_value(&certs->stack,uVar3);
          iVar1 = PKCS7_add_certificate(p7,x509);
          uVar3 = uVar3 + 1;
        } while (iVar1 != 0);
      }
      else {
LAB_000de326:
        if (flags << 0x19 < 0) {
          PKCS7_ctrl(p7,1,1,(char *)0x0);
        }
        if ((flags & 0x5000U) != 0) {
          return p7;
        }
        bio = (BIO *)(flags & 0x5000);
        out = PKCS7_dataInit(p7,bio);
        if (out == (BIO *)0x0) {
          ERR_put_error(0x21,0x86,0x41,"pk7_smime.c",0x79);
        }
        else {
          SMIME_crlf_copy(data,out,flags);
          BIO_ctrl(out,0xb,(long)bio,bio);
          iVar1 = PKCS7_dataFinal(p7,out);
          if (iVar1 != 0) {
            BIO_free_all(out);
            return p7;
          }
          ERR_put_error(0x21,0x86,0x91,"pk7_smime.c",0x84);
          BIO_free_all(out);
        }
      }
    }
    else {
      ERR_put_error(0x21,0x74,0x99,"pk7_smime.c",0x58);
    }
  }
  PKCS7_free(p7);
  return (PKCS7 *)0x0;
}

