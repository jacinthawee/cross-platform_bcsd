
int PKCS7_decrypt(PKCS7 *p7,EVP_PKEY *pkey,X509 *cert,BIO *data,int flags)

{
  int iVar1;
  BIO *pBVar2;
  int iVar3;
  BIO_METHOD *type;
  BIO *in;
  long lVar4;
  undefined auStack_1024 [4096];
  int local_24;
  
  local_24 = __TMC_END__;
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x72,0x8f,"pk7_smime.c",0x21d);
  }
  else {
    iVar1 = OBJ_obj2nid(p7->type);
    if (iVar1 == 0x17) {
      if ((cert == (X509 *)0x0) ||
         (pBVar2 = (BIO *)X509_check_private_key(cert,pkey), pBVar2 != (BIO *)0x0)) {
        p7 = (PKCS7 *)PKCS7_dataDecode(p7,pkey,(BIO *)0x0,cert);
        if ((BIO *)p7 == (BIO *)0x0) {
          ERR_put_error(0x21,0x72,0x77,"pk7_smime.c",0x22d);
        }
        else if (flags << 0x1f < 0) {
          type = BIO_f_buffer();
          pBVar2 = BIO_new(type);
          if (pBVar2 == (BIO *)0x0) {
            ERR_put_error(0x21,0x72,0x41,"pk7_smime.c",0x235);
            BIO_free_all((BIO *)p7);
            p7 = (PKCS7 *)pBVar2;
          }
          else {
            in = BIO_push(pBVar2,(BIO *)p7);
            if (in == (BIO *)0x0) {
              ERR_put_error(0x21,0x72,0x41,"pk7_smime.c",0x23a);
              BIO_free_all(pBVar2);
              BIO_free_all((BIO *)p7);
              p7 = (PKCS7 *)in;
            }
            else {
              pBVar2 = (BIO *)SMIME_text(in,data);
              if (((0 < (int)pBVar2) && (iVar1 = BIO_method_type((BIO *)p7), iVar1 == 0x20a)) &&
                 (lVar4 = BIO_ctrl((BIO *)p7,0x71,0,(void *)0x0), lVar4 == 0)) {
                pBVar2 = (BIO *)0x0;
              }
              BIO_free_all(in);
              p7 = (PKCS7 *)pBVar2;
            }
          }
        }
        else {
          do {
            iVar1 = BIO_read((BIO *)p7,auStack_1024,0x1000);
            if (iVar1 < 1) {
              iVar1 = BIO_method_type((BIO *)p7);
              if (iVar1 == 0x20a) {
                pBVar2 = (BIO *)BIO_ctrl((BIO *)p7,0x71,0,(void *)0x0);
                if (pBVar2 != (BIO *)0x0) {
                  pBVar2 = (BIO *)0x1;
                }
              }
              else {
                pBVar2 = (BIO *)0x1;
              }
              goto LAB_000dec42;
            }
            iVar3 = BIO_write(data,auStack_1024,iVar1);
          } while (iVar3 == iVar1);
          pBVar2 = (BIO *)0x0;
LAB_000dec42:
          BIO_free_all((BIO *)p7);
          p7 = (PKCS7 *)pBVar2;
        }
      }
      else {
        ERR_put_error(0x21,0x72,0x7f,"pk7_smime.c",0x228);
        p7 = (PKCS7 *)pBVar2;
      }
    }
    else {
      p7 = (PKCS7 *)0x0;
      ERR_put_error(0x21,0x72,0x71,"pk7_smime.c",0x222);
    }
  }
  if (local_24 == __TMC_END__) {
    return (int)(BIO *)p7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

