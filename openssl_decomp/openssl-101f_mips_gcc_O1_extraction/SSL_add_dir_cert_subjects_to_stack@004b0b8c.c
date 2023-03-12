
int SSL_add_dir_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *dir)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  SSL *ssl;
  uchar *id;
  char *pcVar6;
  int local_430;
  char acStack_42c [1024];
  SSL *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_430 = 0;
  local_2c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x32c);
  do {
    iVar3 = OPENSSL_DIR_read(&local_430,dir);
    if (iVar3 == 0) {
      piVar4 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
      if (*piVar4 == 0) {
        iVar3 = 1;
        goto LAB_004b0d30;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(2,10,*piVar4,"ssl_cert.c",0x348);
      (*(code *)PTR_ERR_add_error_data_006a9264)(3,"OPENSSL_DIR_read(&ctx, \'",dir,&DAT_00648304);
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd7,2,"ssl_cert.c",0x34a);
LAB_004b0d2c:
      iVar3 = 0;
LAB_004b0d30:
      if (local_430 != 0) {
        OPENSSL_DIR_end(&local_430);
      }
      pcVar6 = "ssl_cert.c";
      id = &DAT_00000018;
      CRYPTO_lock(10,0x18,"ssl_cert.c",0x352);
      if (local_2c != *(SSL **)puVar1) {
        ssl = local_2c;
        (*(code *)PTR___stack_chk_fail_006aabb8)();
        iVar3 = 10;
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(id,*(uint *)pcVar6);
          if (iVar5 < 1) {
            return 0;
          }
          iVar5 = SSL_has_matching_session_id(ssl,id,*(uint *)pcVar6);
          if (iVar5 == 0) break;
          if (iVar3 == 0) {
            return 0;
          }
        }
        return 1;
      }
      return iVar3;
    }
    iVar5 = (*(code *)PTR_strlen_006aab30)(dir);
    iVar2 = (*(code *)PTR_strlen_006aab30)(iVar3);
    if (0x400 < iVar5 + iVar2 + 2U) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd7,0x10e,"ssl_cert.c",0x337);
      goto LAB_004b0d2c;
    }
    iVar3 = (*(code *)PTR_BIO_snprintf_006a8060)(acStack_42c,0x400,"%s/%s",dir,iVar3);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(stackCAs,acStack_42c), iVar3 == 0))
    goto LAB_004b0d2c;
  } while( true );
}

