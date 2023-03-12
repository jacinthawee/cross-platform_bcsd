
stack_st_X509_INFO * PEM_X509_INFO_read_bio(BIO *bp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  undefined *puVar1;
  uchar *puVar2;
  X509_INFO *a;
  int iVar3;
  EVP_PKEY *pEVar4;
  X509_PKEY *pXVar5;
  stack_st_X509_INFO *psVar6;
  X509_INFO *pXVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  stack_st_X509_INFO *psVar11;
  code *local_64;
  int local_60;
  char *local_5c;
  char *local_54;
  char *local_50;
  uchar *local_4c;
  uchar *local_48;
  int local_44;
  EVP_CIPHER_INFO EStack_40;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_54 = (char *)0x0;
  local_50 = (char *)0x0;
  local_4c = (uchar *)0x0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar11 = sk;
  if ((sk == (stack_st_X509_INFO *)0x0) &&
     (psVar6 = (stack_st_X509_INFO *)(*(code *)PTR_sk_new_null_006a6fa4)(), psVar11 = psVar6,
     psVar6 == (stack_st_X509_INFO *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x74,0x41,"pem_info.c",0x6b);
    goto LAB_0056a7c8;
  }
  a = X509_INFO_new();
  psVar6 = psVar11;
  if (a == (X509_INFO *)0x0) goto LAB_0056a7c8;
LAB_0056a454:
  iVar3 = PEM_read_bio(bp,&local_54,&local_50,&local_4c,&local_44);
  if (iVar3 != 0) {
    do {
      pcVar10 = local_54;
      iVar3 = (*(code *)PTR_strcmp_006a9b18)(local_54,"CERTIFICATE");
      pXVar7 = a;
      if ((iVar3 == 0) ||
         (iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"X509 CERTIFICATE"), iVar3 == 0)) {
        if (a->x509 == (X509 *)0x0) goto code_r0x0056a518;
      }
      else {
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"TRUSTED CERTIFICATE");
        if (iVar3 == 0) {
          local_64 = (code *)PTR_d2i_X509_AUX_006a8e08;
          if (a->x509 == (X509 *)0x0) goto LAB_0056a524;
        }
        else {
          iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"X509 CRL");
          if (iVar3 == 0) {
            if (a->crl == (X509_CRL *)0x0) {
              local_64 = (code *)PTR_d2i_X509_CRL_006a8e14;
              pXVar7 = (X509_INFO *)&a->crl;
              goto LAB_0056a524;
            }
          }
          else {
            iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"RSA PRIVATE KEY");
            if (iVar3 == 0) {
              if (a->x_pkey == (X509_PKEY *)0x0) {
                a->enc_data = (char *)0x0;
                a->enc_len = 0;
                pXVar5 = X509_PKEY_new();
                a->x_pkey = pXVar5;
                if (pXVar5 != (X509_PKEY *)0x0) {
                  pXVar7 = (X509_INFO *)&pXVar5->dec_pkey;
                  local_64 = (code *)PTR_d2i_RSAPrivateKey_006a79e4;
                  local_5c = local_50;
                  iVar3 = (*(code *)PTR_strlen_006a9a24)(local_50);
                  local_60 = 6;
                  goto LAB_0056a6ac;
                }
                goto LAB_0056a934;
              }
            }
            else {
              iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"DSA PRIVATE KEY");
              if (iVar3 == 0) {
                if (a->x_pkey == (X509_PKEY *)0x0) {
                  a->enc_data = (char *)0x0;
                  a->enc_len = 0;
                  pXVar5 = X509_PKEY_new();
                  a->x_pkey = pXVar5;
                  if (pXVar5 != (X509_PKEY *)0x0) {
                    pXVar7 = (X509_INFO *)&pXVar5->dec_pkey;
                    local_64 = (code *)PTR_d2i_DSAPrivateKey_006a8e20;
                    local_5c = local_50;
                    iVar3 = (*(code *)PTR_strlen_006a9a24)(local_50);
                    local_60 = 0x74;
                    goto LAB_0056a6ac;
                  }
                  goto LAB_0056a934;
                }
              }
              else {
                iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"EC PRIVATE KEY");
                if (iVar3 != 0) goto LAB_0056a5bc;
                if (a->x_pkey == (X509_PKEY *)0x0) {
                  a->enc_data = (char *)0x0;
                  a->enc_len = 0;
                  pXVar5 = X509_PKEY_new();
                  a->x_pkey = pXVar5;
                  if (pXVar5 == (X509_PKEY *)0x0) goto LAB_0056a934;
                  pXVar7 = (X509_INFO *)&pXVar5->dec_pkey;
                  local_64 = (code *)PTR_d2i_ECPrivateKey_006a8e1c;
                  local_5c = local_50;
                  iVar3 = (*(code *)PTR_strlen_006a9a24)(local_50);
                  local_60 = 0x198;
LAB_0056a6ac:
                  if (iVar3 < 0xb) goto LAB_0056a530;
                  iVar3 = PEM_get_EVP_CIPHER_INFO(local_5c,&a->enc_cipher);
                  puVar2 = local_4c;
                  if (iVar3 == 0) goto LAB_0056a934;
                  local_4c = (uchar *)0x0;
                  a->enc_data = (char *)puVar2;
                  a->enc_len = local_44;
                  pcVar10 = local_54;
                  if (local_54 == (char *)0x0) goto LAB_0056a5d0;
                  goto LAB_0056a5bc;
                }
              }
            }
          }
        }
      }
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar11,a);
      if (iVar3 == 0) goto LAB_0056a934;
      a = X509_INFO_new();
      if (a == (X509_INFO *)0x0) goto LAB_0056a7c8;
    } while( true );
  }
  uVar9 = (*(code *)PTR_ERR_peek_last_error_006a7408)();
  if ((uVar9 & 0xfff) == 0x6c) {
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
    if (a->x509 == (X509 *)0x0) goto LAB_0056a9ec;
    goto LAB_0056a9c8;
  }
  goto LAB_0056a934;
code_r0x0056a518:
  local_64 = (code *)PTR_d2i_X509_006a7fe0;
LAB_0056a524:
  local_60 = 0;
  local_5c = local_50;
LAB_0056a530:
  iVar3 = PEM_get_EVP_CIPHER_INFO(local_5c,&EStack_40);
  if ((iVar3 == 0) || (iVar3 = PEM_do_header(&EStack_40,local_4c,&local_44,cb,u), iVar3 == 0))
  goto LAB_0056a934;
  local_48 = local_4c;
  if (local_60 == 0) {
    iVar3 = (*local_64)(pXVar7,&local_48,local_44);
    if (iVar3 == 0) {
      uVar8 = 0xf9;
      goto LAB_0056a920;
    }
  }
  else {
    pEVar4 = d2i_PrivateKey(local_60,(EVP_PKEY **)pXVar7,&local_48,local_44);
    if (pEVar4 == (EVP_PKEY *)0x0) {
      uVar8 = 0xf5;
LAB_0056a920:
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x74,0xd,"pem_info.c",uVar8);
LAB_0056a934:
      do {
        X509_INFO_free(a);
        psVar6 = psVar11;
LAB_0056a7c8:
        for (a = (X509_INFO *)0x0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar6), (int)a < iVar3;
            a = (X509_INFO *)((int)&a->x509 + 1)) {
          pXVar7 = (X509_INFO *)(*(code *)PTR_sk_value_006a6e24)(psVar6,a);
          X509_INFO_free(pXVar7);
        }
        if (psVar6 == sk) {
          psVar11 = (stack_st_X509_INFO *)0x0;
        }
        else {
          psVar11 = (stack_st_X509_INFO *)0x0;
          (*(code *)PTR_sk_free_006a6e80)(psVar6);
        }
        do {
          while( true ) {
            if (local_54 != (char *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
            }
            if (local_50 != (char *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
            }
            if (local_4c != (uchar *)0x0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
            }
            if (local_2c == *(int *)puVar1) {
              return psVar11;
            }
            (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0056a9ec:
            if (((a->crl != (X509_CRL *)0x0) || (a->x_pkey != (X509_PKEY *)0x0)) ||
               (a->enc_data != (char *)0x0)) break;
            X509_INFO_free(a);
          }
LAB_0056a9c8:
          iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar11,a);
        } while (iVar3 != 0);
      } while( true );
    }
  }
  pcVar10 = local_54;
  if (local_54 != (char *)0x0) {
LAB_0056a5bc:
    (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar10);
  }
LAB_0056a5d0:
  if (local_50 != (char *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (local_4c != (uchar *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  local_54 = (char *)0x0;
  local_50 = (char *)0x0;
  local_4c = (uchar *)0x0;
  goto LAB_0056a454;
}

