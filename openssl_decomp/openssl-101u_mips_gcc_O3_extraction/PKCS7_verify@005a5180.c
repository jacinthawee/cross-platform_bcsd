
int PKCS7_verify(PKCS7 *p7,stack_st_X509 *certs,X509_STORE *store,BIO *indata,BIO *out,int flags)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  stack_st_PKCS7_SIGNER_INFO *psVar5;
  stack_st_X509 *psVar6;
  BIO *bio;
  PKCS7 *p7_00;
  int iVar7;
  X509 *x509;
  PKCS7_RECIP_INFO *pPVar8;
  int iVar9;
  char *pcVar10;
  EVP_CIPHER *cipher;
  undefined4 uVar11;
  char *x509_00;
  BIO *pBVar12;
  BIO *pBVar13;
  undefined *puVar14;
  BIO *local_10c0;
  undefined local_10b8 [140];
  BIO aBStack_102c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (p7 == (PKCS7 *)0x0) {
    cipher = (EVP_CIPHER *)0x8f;
    uVar3 = 0x107;
  }
  else {
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
    if (iVar2 == 0x16) {
      x509_00 = (char *)0x0;
      lVar4 = PKCS7_ctrl(p7,2,0,(char *)0x0);
      if ((lVar4 == 0) || (x509_00 = "encrypt", indata != (BIO *)0x0)) {
        psVar5 = PKCS7_get_signer_info(p7);
        if ((psVar5 != (stack_st_PKCS7_SIGNER_INFO *)0x0) &&
           (iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar5), iVar2 != 0)) {
          cipher = (EVP_CIPHER *)flags;
          psVar6 = PKCS7_get0_signers(p7,certs,flags);
          if (psVar6 == (stack_st_X509 *)0x0) {
            pBVar12 = (BIO *)0x0;
            pcVar10 = (char *)certs;
            goto LAB_005a5228;
          }
          pBVar12 = (BIO *)(flags & 0x20);
          if (pBVar12 == (BIO *)0x0) {
            if ((flags & 0x2000U) == 0) {
              iVar2 = 0;
              puVar14 = local_10b8 + 4;
              if ((flags & 8U) == 0) {
                for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), iVar2 < iVar7;
                    iVar2 = iVar2 + 1) {
                  cipher = (EVP_CIPHER *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar2);
                  x509_00 = (char *)((p7->d).data)->data;
                  iVar7 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(puVar14,store);
                  if (iVar7 == 0) goto LAB_005a5918;
                  (*(code *)PTR_X509_STORE_CTX_set_default_006a8378)(puVar14,"smime_sign");
                  (*(code *)PTR_X509_STORE_CTX_set0_crls_006a7468)(puVar14,((p7->d).data)->flags);
                  iVar7 = (*(code *)PTR_X509_verify_cert_006a728c)(puVar14);
                  if (iVar7 < 1) goto LAB_005a53b8;
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(puVar14);
                }
              }
              else {
                for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), iVar2 < iVar7;
                    iVar2 = iVar2 + 1) {
                  cipher = (EVP_CIPHER *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar2);
                  x509_00 = (char *)0x0;
                  iVar7 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(puVar14,store);
                  if (iVar7 == 0) goto LAB_005a5944;
                  (*(code *)PTR_X509_STORE_CTX_set0_crls_006a7468)(puVar14,((p7->d).data)->flags);
                  iVar7 = (*(code *)PTR_X509_verify_cert_006a728c)(puVar14);
                  if (iVar7 < 1) goto LAB_005a53b8;
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(puVar14);
                }
              }
            }
            else {
              iVar2 = 0;
              puVar14 = local_10b8 + 4;
              if ((flags & 8U) == 0) {
                for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), iVar2 < iVar7;
                    iVar2 = iVar2 + 1) {
                  cipher = (EVP_CIPHER *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar2);
                  x509_00 = (char *)((p7->d).data)->data;
                  iVar7 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(puVar14,store);
                  if (iVar7 == 0) goto LAB_005a5918;
                  (*(code *)PTR_X509_STORE_CTX_set_default_006a8378)(puVar14,"smime_sign");
                  iVar7 = (*(code *)PTR_X509_verify_cert_006a728c)(puVar14);
                  if (iVar7 < 1) goto LAB_005a53b8;
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(puVar14);
                }
              }
              else {
                for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), iVar2 < iVar7;
                    iVar2 = iVar2 + 1) {
                  cipher = (EVP_CIPHER *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar2);
                  x509_00 = (char *)0x0;
                  iVar7 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(puVar14,store);
                  if (iVar7 == 0) goto LAB_005a5944;
                  iVar7 = (*(code *)PTR_X509_verify_cert_006a728c)(puVar14);
                  if (iVar7 < 1) goto LAB_005a53b8;
                  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(puVar14);
                }
              }
            }
          }
          if (indata == (BIO *)0x0) {
            pcVar10 = (char *)0x0;
            bio = PKCS7_dataInit(p7,(BIO *)0x0);
            if (bio == (BIO *)0x0) {
LAB_005a5984:
              pBVar12 = (BIO *)0x0;
            }
            else {
              local_10c0 = (BIO *)0x0;
LAB_005a5494:
              pBVar13 = out;
              if ((flags & 1U) == 0) {
LAB_005a54a8:
                while (pBVar13 != (BIO *)0x0) {
                  cipher = (EVP_CIPHER *)0x1000;
                  pcVar10 = (char *)aBStack_102c;
                  iVar2 = (*(code *)PTR_BIO_read_006a74c0)(bio,aBStack_102c);
                  if (iVar2 < 1) goto LAB_005a54cc;
                  (*(code *)PTR_BIO_write_006a6e14)(pBVar13,aBStack_102c,iVar2);
                }
                do {
                  cipher = (EVP_CIPHER *)0x1000;
                  pcVar10 = (char *)aBStack_102c;
                  iVar2 = (*(code *)PTR_BIO_read_006a74c0)(bio,aBStack_102c);
                } while (0 < iVar2);
LAB_005a54cc:
                if ((flags & 1U) != 0) {
                  iVar2 = (*(code *)PTR_SMIME_text_006a9198)(pBVar13,out);
                  if (iVar2 == 0) {
                    cipher = (EVP_CIPHER *)0x81;
                    x509_00 = "pk7_smime.c";
                    pcVar10 = (char *)0x75;
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,0x81,"pk7_smime.c",0x17b);
                    pBVar12 = (BIO *)0x0;
                    (*(code *)PTR_BIO_free_006a6e70)(pBVar13);
                    goto LAB_005a5558;
                  }
                  (*(code *)PTR_BIO_free_006a6e70)(pBVar13);
                  pcVar10 = (char *)out;
                }
                iVar2 = 0;
                if ((flags & 4U) == 0) {
                  for (; iVar7 = (*(code *)PTR_sk_num_006a6e2c)(psVar5), iVar2 < iVar7;
                      iVar2 = iVar2 + 1) {
                    cipher = (EVP_CIPHER *)(*(code *)PTR_sk_value_006a6e24)(psVar5,iVar2);
                    x509_00 = (char *)(*(code *)PTR_sk_value_006a6e24)(psVar6,iVar2);
                    pcVar10 = (char *)p7;
                    iVar7 = PKCS7_signatureVerify
                                      (bio,p7,(PKCS7_SIGNER_INFO *)cipher,(X509 *)x509_00);
                    if (iVar7 < 1) {
                      cipher = (EVP_CIPHER *)&DAT_00000069;
                      x509_00 = "pk7_smime.c";
                      pcVar10 = (char *)0x75;
                      pBVar12 = (BIO *)0x0;
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,0x69,"pk7_smime.c",0x189);
                      goto LAB_005a5558;
                    }
                  }
                }
                pBVar12 = (BIO *)0x1;
              }
              else {
                uVar3 = (*(code *)PTR_BIO_s_mem_006a7c18)();
                pBVar12 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar3);
                if (pBVar12 != (BIO *)0x0) {
                  x509_00 = (char *)0x0;
                  (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar12,0x82,0);
                  pBVar13 = pBVar12;
                  goto LAB_005a54a8;
                }
                cipher = (EVP_CIPHER *)&DAT_00000041;
                x509_00 = "pk7_smime.c";
                pcVar10 = (char *)0x75;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,0x41,"pk7_smime.c",0x169);
              }
LAB_005a5558:
              if ((indata == local_10c0) && (indata != (BIO *)0x0)) goto LAB_005a57c4;
            }
          }
          else {
            iVar2 = (*(code *)PTR_BIO_method_type_006a8328)(indata);
            if (iVar2 == 0x401) {
              x509_00 = local_10b8;
              cipher = (EVP_CIPHER *)0x0;
              uVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(indata,3);
              local_10c0 = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006a9148)(local_10b8._0_4_,uVar3);
              if (local_10c0 == (BIO *)0x0) {
                cipher = (EVP_CIPHER *)&DAT_00000041;
                uVar3 = 0x15e;
                goto LAB_005a5210;
              }
              pcVar10 = (char *)local_10c0;
              bio = PKCS7_dataInit(p7,local_10c0);
              if (bio != (BIO *)0x0) goto LAB_005a5494;
              if (indata != local_10c0) goto LAB_005a5984;
            }
            else {
              pcVar10 = (char *)indata;
              bio = PKCS7_dataInit(p7,indata);
              local_10c0 = indata;
              if (bio != (BIO *)0x0) goto LAB_005a5494;
            }
            pBVar12 = (BIO *)0x0;
LAB_005a57c4:
            (*(code *)PTR_BIO_pop_006a79c8)(bio);
          }
          (*(code *)PTR_BIO_free_all_006a6e74)(bio);
          goto LAB_005a5430;
        }
        cipher = (EVP_CIPHER *)0x7b;
        uVar3 = 0x125;
      }
      else {
        cipher = (EVP_CIPHER *)0x7a;
        uVar3 = 0x112;
      }
    }
    else {
      cipher = (EVP_CIPHER *)0x71;
      uVar3 = 0x10c;
    }
  }
LAB_005a5210:
  x509_00 = "pk7_smime.c";
  pcVar10 = (char *)0x75;
  pBVar12 = (BIO *)0x0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,cipher,"pk7_smime.c",uVar3);
  goto LAB_005a5228;
LAB_005a5918:
  cipher = (EVP_CIPHER *)&DAT_0000000b;
  x509_00 = "pk7_smime.c";
  pcVar10 = (char *)0x75;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,0xb,"pk7_smime.c",0x136);
  goto LAB_005a5430;
LAB_005a5944:
  cipher = (EVP_CIPHER *)&DAT_0000000b;
  x509_00 = "pk7_smime.c";
  pcVar10 = (char *)0x75;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,0xb,"pk7_smime.c",0x13c);
  goto LAB_005a5430;
LAB_005a53b8:
  uVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(local_10b8 + 4);
  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(local_10b8 + 4);
  x509_00 = "pk7_smime.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x75,0x75,"pk7_smime.c",0x148);
  cipher = (EVP_CIPHER *)(*(code *)PTR_X509_verify_cert_error_string_006a72a0)(uVar3);
  pcVar10 = "Verify error:";
  (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Verify error:");
LAB_005a5430:
  (*(code *)PTR_sk_free_006a6e80)(psVar6);
LAB_005a5228:
  if (local_2c == *(int *)puVar1) {
    return (int)pBVar12;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  p7_00 = PKCS7_new();
  if (p7_00 == (PKCS7 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x73,0x41,"pk7_smime.c",0x1e5);
  }
  else {
    iVar7 = PKCS7_set_type(p7_00,0x17);
    if (iVar7 != 0) {
      iVar7 = PKCS7_set_cipher(p7_00,cipher);
      if (iVar7 == 0) {
        uVar11 = 0x79;
        uVar3 = 0x1ec;
      }
      else {
        iVar7 = 0;
        do {
          iVar9 = (*(code *)PTR_sk_num_006a6e2c)(iVar2);
          if (iVar9 <= iVar7) {
            if (((uint)x509_00 & 0x1000) != 0) {
              return (int)p7_00;
            }
            pBVar12 = PKCS7_dataInit(p7_00,(BIO *)0x0);
            if (pBVar12 == (BIO *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x41,"pk7_smime.c",0x75);
            }
            else {
              (*(code *)PTR_SMIME_crlf_copy_006a9170)(pcVar10,pBVar12,x509_00);
              (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar12,0xb,0,0);
              iVar2 = PKCS7_dataFinal(p7_00,pBVar12);
              if (iVar2 != 0) {
                (*(code *)PTR_BIO_free_all_006a6e74)(pBVar12);
                return (int)p7_00;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x86,0x91,"pk7_smime.c",0x7e);
              (*(code *)PTR_BIO_free_all_006a6e74)(pBVar12);
            }
            goto LAB_005a5b10;
          }
          x509 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(iVar2,iVar7);
          pPVar8 = PKCS7_add_recipient(p7_00,x509);
          iVar7 = iVar7 + 1;
        } while (pPVar8 != (PKCS7_RECIP_INFO *)0x0);
        uVar11 = 0x78;
        uVar3 = 499;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x73,uVar11,"pk7_smime.c",uVar3);
    }
LAB_005a5b10:
    (*(code *)PTR_BIO_free_all_006a6e74)(0);
    PKCS7_free(p7_00);
  }
  return 0;
}

