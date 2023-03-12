
int SSL_add_file_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *file)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  stack_st_X509_NAME *stackCAs_00;
  SSL *ssl;
  uchar *id;
  char *pcVar7;
  int unaff_s1;
  int *unaff_s5;
  int iStack_478;
  char acStack_474 [1024];
  SSL *pSStack_74;
  int iStack_70;
  int iStack_6c;
  stack_st_X509_NAME *psStack_68;
  undefined *puStack_64;
  undefined4 uStack_60;
  int *piStack_5c;
  int local_28;
  stack_st_X509_NAME *local_24;
  
  puStack_64 = PTR___stack_chk_guard_006a9ae8;
  local_28 = 0;
  local_24 = *(stack_st_X509_NAME **)PTR___stack_chk_guard_006a9ae8;
  uStack_60 = (*(code *)PTR_sk_set_cmp_func_006a8384)(stackCAs,xname_cmp);
  uVar2 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar3 = (*(code *)PTR_BIO_new_006a6ea4)(uVar2);
  if (iVar3 == 0) {
    iStack_70 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xd8,0x41,"ssl_cert.c");
  }
  else {
    iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar3,0x6c,3,file);
    if (iVar4 != 0) {
      unaff_s5 = &local_28;
      do {
        iVar4 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)(iVar3,unaff_s5,0,0);
        while( true ) {
          if (iVar4 == 0) {
            iStack_70 = 1;
            (*(code *)PTR_ERR_clear_error_006a6ee0)();
            goto LAB_004ada64;
          }
          iVar4 = (*(code *)PTR_X509_get_subject_name_006a6f00)(local_28);
          if ((iVar4 == 0) || (iVar4 = (*(code *)PTR_X509_NAME_dup_006a713c)(iVar4), iVar4 == 0))
          goto LAB_004ada60;
          iVar5 = (*(code *)PTR_sk_find_006a8044)(stackCAs,iVar4);
          if (iVar5 < 0) break;
          (*(code *)PTR_X509_NAME_free_006a6ff8)(iVar4);
          iVar4 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)(iVar3,unaff_s5,0,0);
        }
        (*(code *)PTR_sk_push_006a6fa8)(stackCAs,iVar4);
      } while( true );
    }
LAB_004ada60:
    iStack_70 = 0;
LAB_004ada64:
    (*(code *)PTR_BIO_free_006a6e70)(iVar3);
    unaff_s1 = iVar3;
  }
  if (local_28 != 0) {
    (*(code *)PTR_X509_free_006a6e90)();
  }
  uVar2 = uStack_60;
  (*(code *)PTR_sk_set_cmp_func_006a8384)(stackCAs);
  if (local_24 == *(stack_st_X509_NAME **)puStack_64) {
    return iStack_70;
  }
  stackCAs_00 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_478 = 0;
  pSStack_74 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  iStack_6c = unaff_s1;
  psStack_68 = stackCAs;
  piStack_5c = unaff_s5;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x2f9);
  do {
    iVar3 = OPENSSL_DIR_read(&iStack_478,uVar2);
    if (iVar3 == 0) {
      piVar6 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      if (*piVar6 == 0) {
        iVar3 = 1;
        goto LAB_004adccc;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(2,10,*piVar6,"ssl_cert.c",0x312);
      (*(code *)PTR_ERR_add_error_data_006a813c)(3,"OPENSSL_DIR_read(&ctx, \'",uVar2,&DAT_00647d34);
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xd7,2,"ssl_cert.c",0x314);
LAB_004adcc8:
      iVar3 = 0;
LAB_004adccc:
      if (iStack_478 != 0) {
        OPENSSL_DIR_end(&iStack_478);
      }
      pcVar7 = "ssl_cert.c";
      id = &DAT_00000018;
      CRYPTO_lock(10,0x18,"ssl_cert.c",0x31d);
      if (pSStack_74 != *(SSL **)puVar1) {
        ssl = pSStack_74;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        iVar3 = 10;
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(id,*(uint *)pcVar7);
          if (iVar4 < 1) {
            return 0;
          }
          iVar4 = SSL_has_matching_session_id(ssl,id,*(uint *)pcVar7);
          if (iVar4 == 0) break;
          if (iVar3 == 0) {
            return 0;
          }
        }
        return 1;
      }
      return iVar3;
    }
    iVar4 = (*(code *)PTR_strlen_006a9a24)(uVar2);
    iVar5 = (*(code *)PTR_strlen_006a9a24)(iVar3);
    if (0x400 < iVar4 + iVar5 + 2U) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xd7,0x10e,"ssl_cert.c",0x303);
      goto LAB_004adcc8;
    }
    iVar3 = (*(code *)PTR_BIO_snprintf_006a6f60)(acStack_474,0x400,"%s/%s",uVar2,iVar3);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(stackCAs_00,acStack_474), iVar3 == 0))
    goto LAB_004adcc8;
  } while( true );
}

