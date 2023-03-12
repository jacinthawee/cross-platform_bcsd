
int PKCS7_verify(PKCS7 *p7,stack_st_X509 *certs,X509_STORE *store,BIO *indata,BIO *out,int flags)

{
  int iVar1;
  long lVar2;
  _STACK *p_Var3;
  _STACK *p_Var4;
  X509 *pXVar5;
  char *pcVar6;
  BIO *b;
  PKCS7_SIGNER_INFO *si;
  BIO_METHOD *type;
  BIO *bp;
  BIO *bio;
  int in_GS_OFFSET;
  bool bVar7;
  int iVar8;
  void *local_10ac;
  X509_STORE_CTX local_10a8;
  undefined local_1020 [4096];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (p7 == (PKCS7 *)0x0) {
    iVar8 = 0x118;
    iVar1 = 0x8f;
  }
  else {
    iVar1 = OBJ_obj2nid(p7->type);
    if (iVar1 == 0x16) {
      lVar2 = PKCS7_ctrl(p7,2,0,(char *)0x0);
      bVar7 = indata == (BIO *)0x0;
      if ((lVar2 == 0) || (!bVar7)) {
        p_Var3 = (_STACK *)PKCS7_get_signer_info(p7);
        if ((p_Var3 != (_STACK *)0x0) && (iVar1 = sk_num(p_Var3), iVar1 != 0)) {
          p_Var4 = (_STACK *)PKCS7_get0_signers(p7,certs,flags);
          if (p_Var4 == (_STACK *)0x0) {
            bio = (BIO *)0x0;
            goto LAB_08180cf0;
          }
          bio = (BIO *)(flags & 0x20);
          if (bio == (BIO *)0x0) {
            iVar1 = 0;
            if ((flags & 0x2000U) == 0) {
              if ((flags & 8U) == 0) {
                for (; iVar8 = sk_num(p_Var4), iVar1 < iVar8; iVar1 = iVar1 + 1) {
                  pXVar5 = (X509 *)sk_value(p_Var4,iVar1);
                  iVar8 = X509_STORE_CTX_init(&local_10a8,store,pXVar5,((p7->d).sign)->cert);
                  if (iVar8 == 0) goto LAB_081812bc;
                  X509_STORE_CTX_set_default(&local_10a8,"smime_sign");
                  X509_STORE_CTX_set0_crls(&local_10a8,((p7->d).sign)->crl);
                  iVar8 = X509_verify_cert(&local_10a8);
                  if (iVar8 < 1) goto LAB_08180e46;
                  X509_STORE_CTX_cleanup(&local_10a8);
                }
              }
              else {
                for (; iVar8 = sk_num(p_Var4), iVar1 < iVar8; iVar1 = iVar1 + 1) {
                  pXVar5 = (X509 *)sk_value(p_Var4,iVar1);
                  iVar8 = X509_STORE_CTX_init(&local_10a8,store,pXVar5,(stack_st_X509 *)0x0);
                  if (iVar8 == 0) goto LAB_0818128c;
                  X509_STORE_CTX_set0_crls(&local_10a8,((p7->d).sign)->crl);
                  iVar8 = X509_verify_cert(&local_10a8);
                  if (iVar8 < 1) goto LAB_08180e46;
                  X509_STORE_CTX_cleanup(&local_10a8);
                }
              }
            }
            else if ((flags & 8U) == 0) {
              for (; iVar8 = sk_num(p_Var4), iVar1 < iVar8; iVar1 = iVar1 + 1) {
                pXVar5 = (X509 *)sk_value(p_Var4,iVar1);
                iVar8 = X509_STORE_CTX_init(&local_10a8,store,pXVar5,((p7->d).sign)->cert);
                if (iVar8 == 0) goto LAB_081812bc;
                X509_STORE_CTX_set_default(&local_10a8,"smime_sign");
                iVar8 = X509_verify_cert(&local_10a8);
                if (iVar8 < 1) goto LAB_08180e46;
                X509_STORE_CTX_cleanup(&local_10a8);
              }
            }
            else {
              for (; iVar8 = sk_num(p_Var4), iVar1 < iVar8; iVar1 = iVar1 + 1) {
                pXVar5 = (X509 *)sk_value(p_Var4,iVar1);
                iVar8 = X509_STORE_CTX_init(&local_10a8,store,pXVar5,(stack_st_X509 *)0x0);
                if (iVar8 == 0) goto LAB_0818128c;
                iVar8 = X509_verify_cert(&local_10a8);
                if (iVar8 < 1) goto LAB_08180e46;
                X509_STORE_CTX_cleanup(&local_10a8);
              }
            }
          }
          if (indata == (BIO *)0x0) {
            b = PKCS7_dataInit(p7,(BIO *)0x0);
            if (b != (BIO *)0x0) {
LAB_08180f0d:
              bp = out;
              if ((flags & 1U) != 0) {
                type = BIO_s_mem();
                bp = BIO_new(type);
                if (bp == (BIO *)0x0) {
                  iVar8 = 0x17b;
                  iVar1 = 0x41;
LAB_0818125a:
                  bio = (BIO *)0x0;
                  ERR_put_error(0x21,0x75,iVar1,"pk7_smime.c",iVar8);
                  goto LAB_081810f0;
                }
                BIO_ctrl(bp,0x82,0,(void *)0x0);
              }
              while (bp != (BIO *)0x0) {
                iVar1 = BIO_read(b,local_1020,0x1000);
                if (iVar1 < 1) goto LAB_08180f4e;
                BIO_write(bp,local_1020,iVar1);
              }
              do {
                iVar1 = BIO_read(b,local_1020,0x1000);
              } while (0 < iVar1);
LAB_08180f4e:
              if ((flags & 1U) != 0) {
                iVar1 = SMIME_text(bp,out);
                if (iVar1 == 0) {
                  bio = (BIO *)0x0;
                  ERR_put_error(0x21,0x75,0x81,"pk7_smime.c",0x18b);
                  BIO_free(bp);
                  goto LAB_081810f0;
                }
                BIO_free(bp);
              }
              bio = (BIO *)0x1;
              if ((flags & 4U) == 0) {
                for (iVar1 = 0; iVar8 = sk_num(p_Var3), iVar1 < iVar8; iVar1 = iVar1 + 1) {
                  si = (PKCS7_SIGNER_INFO *)sk_value(p_Var3,iVar1);
                  pXVar5 = (X509 *)sk_value(p_Var4,iVar1);
                  iVar8 = PKCS7_signatureVerify(b,p7,si,pXVar5);
                  if (iVar8 < 1) {
                    iVar8 = 0x19a;
                    iVar1 = 0x69;
                    goto LAB_0818125a;
                  }
                }
                bio = (BIO *)0x1;
              }
              goto LAB_081810f0;
            }
            bio = (BIO *)0x0;
          }
          else {
            iVar1 = BIO_method_type(indata);
            if (iVar1 == 0x401) {
              lVar2 = BIO_ctrl(indata,3,0,&local_10ac);
              bio = BIO_new_mem_buf(local_10ac,lVar2);
              if (bio == (BIO *)0x0) {
                ERR_put_error(0x21,0x75,0x41,"pk7_smime.c",0x16e);
                goto LAB_08180cf0;
              }
              b = PKCS7_dataInit(p7,bio);
              bVar7 = indata == bio;
              if (b != (BIO *)0x0) goto LAB_08180f0d;
              bio = (BIO *)0x0;
LAB_081810f0:
              if ((indata == (BIO *)0x0) || (!bVar7)) goto LAB_0818110b;
            }
            else {
              b = PKCS7_dataInit(p7,indata);
              if (b != (BIO *)0x0) {
                bVar7 = true;
                goto LAB_08180f0d;
              }
              bio = (BIO *)0x0;
            }
            BIO_pop(b);
          }
LAB_0818110b:
          BIO_free_all(b);
          sk_free(p_Var4);
          goto LAB_08180cf0;
        }
        iVar8 = 0x135;
        iVar1 = 0x7b;
      }
      else {
        iVar8 = 0x123;
        iVar1 = 0x7a;
      }
    }
    else {
      iVar8 = 0x11d;
      iVar1 = 0x71;
    }
  }
  bio = (BIO *)0x0;
  ERR_put_error(0x21,0x75,iVar1,"pk7_smime.c",iVar8);
  goto LAB_08180cf0;
LAB_081812bc:
  iVar1 = 0x146;
  goto LAB_08181298;
LAB_08180e46:
  iVar1 = X509_STORE_CTX_get_error(&local_10a8);
  X509_STORE_CTX_cleanup(&local_10a8);
  ERR_put_error(0x21,0x75,0x75,"pk7_smime.c",0x156);
  pcVar6 = X509_verify_cert_error_string(iVar1);
  ERR_add_error_data(2,"Verify error:",pcVar6);
  sk_free(p_Var4);
  goto LAB_08180cf0;
LAB_0818128c:
  iVar1 = 0x14c;
LAB_08181298:
  ERR_put_error(0x21,0x75,0xb,"pk7_smime.c",iVar1);
  sk_free(p_Var4);
LAB_08180cf0:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)bio;
}

