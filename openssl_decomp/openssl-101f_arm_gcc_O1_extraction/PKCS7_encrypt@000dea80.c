
PKCS7 * PKCS7_encrypt(stack_st_X509 *certs,BIO *in,EVP_CIPHER *cipher,int flags)

{
  PKCS7 *p7;
  int iVar1;
  X509 *x509;
  PKCS7_RECIP_INFO *pPVar2;
  int iVar3;
  BIO *out;
  
  p7 = PKCS7_new();
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x73,0x41,"pk7_smime.c",500);
  }
  else {
    iVar1 = PKCS7_set_type(p7,0x17);
    if (iVar1 != 0) {
      iVar1 = PKCS7_set_cipher(p7,cipher);
      if (iVar1 == 0) {
        ERR_put_error(0x21,0x73,0x79,"pk7_smime.c",0x1fb);
      }
      else {
        iVar1 = 0;
        do {
          iVar3 = sk_num(&certs->stack);
          if (iVar3 <= iVar1) {
            if ((flags & 0x1000U) != 0) {
              return p7;
            }
            out = PKCS7_dataInit(p7,(BIO *)0x0);
            if (out == (BIO *)0x0) {
              ERR_put_error(0x21,0x86,0x41,"pk7_smime.c",0x79);
            }
            else {
              SMIME_crlf_copy(in,out,flags);
              BIO_ctrl(out,0xb,0,(void *)0x0);
              iVar1 = PKCS7_dataFinal(p7,out);
              if (iVar1 != 0) {
                BIO_free_all(out);
                return p7;
              }
              ERR_put_error(0x21,0x86,0x91,"pk7_smime.c",0x84);
              BIO_free_all(out);
            }
            goto LAB_000deb2c;
          }
          x509 = (X509 *)sk_value(&certs->stack,iVar1);
          pPVar2 = PKCS7_add_recipient(p7,x509);
          iVar1 = iVar1 + 1;
        } while (pPVar2 != (PKCS7_RECIP_INFO *)0x0);
        ERR_put_error(0x21,0x73,0x78,"pk7_smime.c",0x203);
      }
    }
LAB_000deb2c:
    BIO_free_all((BIO *)0x0);
    PKCS7_free(p7);
    p7 = (PKCS7 *)0x0;
  }
  return p7;
}

