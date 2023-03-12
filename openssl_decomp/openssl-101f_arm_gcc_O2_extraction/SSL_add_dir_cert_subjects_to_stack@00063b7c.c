
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
  
  local_24 = __TMC_END__;
  local_428 = 0;
  CRYPTO_lock(9,0x18,"ssl_cert.c",0x32c);
  while( true ) {
    __s = (char *)OPENSSL_DIR_read(&local_428,dir);
    if (__s == (char *)0x0) {
      piVar4 = __errno_location();
      if (*piVar4 == 0) {
        __s = (char *)0x1;
      }
      else {
        ERR_put_error(2,10,*piVar4,"ssl_cert.c",0x348);
        ERR_add_error_data(3,"OPENSSL_DIR_read(&ctx, \'",dir,&DAT_0013adec);
        ERR_put_error(0x14,0xd7,2,"ssl_cert.c",0x34a);
      }
      goto LAB_00063c2a;
    }
    sVar1 = strlen(dir);
    sVar2 = strlen(__s);
    if (0x400 < sVar2 + sVar1 + 2) break;
    iVar3 = BIO_snprintf(acStack_424,0x400,"%s/%s",dir,__s);
    if ((0x3fe < iVar3 - 1U) ||
       (iVar3 = SSL_add_file_cert_subjects_to_stack(stackCAs,acStack_424), iVar3 == 0))
    goto LAB_00063c28;
  }
  ERR_put_error(0x14,0xd7,0x10e,"ssl_cert.c",0x337);
LAB_00063c28:
  __s = (char *)0x0;
LAB_00063c2a:
  if (local_428 != 0) {
    OPENSSL_DIR_end(&local_428);
  }
  CRYPTO_lock(10,0x18,"ssl_cert.c",0x352);
  if (local_24 == __TMC_END__) {
    return (int)__s;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

