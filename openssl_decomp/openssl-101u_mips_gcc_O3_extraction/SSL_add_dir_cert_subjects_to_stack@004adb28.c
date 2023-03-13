
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_430 = 0;
  local_2c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x2f9);
  do {
    iVar3 = OPENSSL_DIR_read(&local_430,dir);
    if (iVar3 == 0) {
      piVar4 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      if (*piVar4 == 0) {
        iVar3 = 1;
        goto LAB_004adccc;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(2,10,*piVar4,"ssl_cert.c",0x312);
      (*(code *)PTR_ERR_add_error_data_006a813c)(3,"OPENSSL_DIR_read(&ctx, \'",dir,&DAT_00647d34);
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xd7,2,"ssl_cert.c",0x314);
LAB_004adcc8:
      iVar3 = 0;
LAB_004adccc:
      if (local_430 != 0) {
        OPENSSL_DIR_end(&local_430);
      }
      pcVar6 = "ssl_cert.c";
      id = &DAT_00000018;
      CRYPTO_lock(10,0x18,"ssl_cert.c",0x31d);
      if (local_2c != *(SSL **)puVar1) {
        ssl = local_2c;
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
        iVar3 = 10;
        while( true ) {
          iVar3 = iVar3 + -1;
          iVar5 = (*(code *)PTR_RAND_bytes_006a7574)(id,*(uint *)pcVar6);
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
    iVar5 = (*(code *)PTR_strlen_006a9a24)(dir);
    iVar2 = (*(code *)PTR_strlen_006a9a24)(iVar3);
    if (0x400 < iVar5 + iVar2 + 2U) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xd7,0x10e,"ssl_cert.c",0x303);
      goto LAB_004adcc8;
    }
    iVar3 = (*(code *)PTR_BIO_snprintf_006a6f60)(acStack_42c,0x400,"%s/%s",dir,iVar3);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(stackCAs,acStack_42c), iVar3 == 0))
    goto LAB_004adcc8;
  } while( true );
}

