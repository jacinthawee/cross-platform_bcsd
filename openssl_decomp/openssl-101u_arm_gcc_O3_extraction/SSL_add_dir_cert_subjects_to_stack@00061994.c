
int SSL_add_dir_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *dir)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *__s;
  int *piVar4;
  int local_428;
  char acStack_424 [1024];
  int local_24;
  
  local_24 = __stack_chk_guard;
  local_428 = 0;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x2f9);
  while( true ) {
    __s = (char *)OPENSSL_DIR_read(&local_428,dir);
    if (__s == (char *)0x0) {
      piVar4 = __errno_location();
      if (*piVar4 == 0) {
        __s = (char *)0x1;
      }
      else {
        ERR_put_error(2,10,*piVar4,"ssl_cert.c",0x312);
        ERR_add_error_data(3,"OPENSSL_DIR_read(&ctx, \'",dir,&DAT_00139dd8);
        ERR_put_error(0x14,0xd7,2,"ssl_cert.c",0x314);
      }
      goto LAB_00061a42;
    }
    sVar1 = strlen(dir);
    sVar2 = strlen(__s);
    if (0x400 < sVar2 + sVar1 + 2) break;
    iVar3 = BIO_snprintf(acStack_424,0x400,"%s/%s",dir,__s);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(stackCAs,acStack_424), iVar3 == 0))
    goto LAB_00061a40;
  }
  ERR_put_error(0x14,0xd7,0x10e,"ssl_cert.c",0x303);
LAB_00061a40:
  __s = (char *)0x0;
LAB_00061a42:
  if (local_428 != 0) {
    OPENSSL_DIR_end(&local_428);
  }
  CRYPTO_lock(10,0x18,"ssl_cert.c",0x31d);
  if (local_24 == __stack_chk_guard) {
    return (int)__s;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

