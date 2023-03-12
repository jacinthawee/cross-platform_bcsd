
int SSL_add_dir_cert_subjects_to_stack(stack_st_X509_NAME *stackCAs,char *dir)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  int *piVar3;
  int mode;
  int iVar4;
  int in_GS_OFFSET;
  char *pcVar5;
  undefined4 uVar6;
  int local_424;
  char local_420 [1024];
  int local_20;
  
  local_424 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar6 = 0x32c;
  pcVar5 = "ssl_cert.c";
  CRYPTO_lock(0,9,(char *)0x18,(int)"ssl_cert.c");
  do {
    __s = (char *)OPENSSL_DIR_read(&local_424,dir,pcVar5,uVar6);
    if (__s == (char *)0x0) {
      piVar3 = __errno_location();
      iVar4 = 1;
      if (*piVar3 == 0) goto LAB_080c58b2;
      ERR_put_error(2,10,*piVar3,"ssl_cert.c",0x348);
      ERR_add_error_data(3,"OPENSSL_DIR_read(&ctx, \'",dir,&DAT_081ffd8b);
      ERR_put_error(0x14,0xd7,2,"ssl_cert.c",0x34a);
      break;
    }
    sVar1 = strlen(dir);
    sVar2 = strlen(__s);
    if (0x400 < sVar1 + 2 + sVar2) {
      ERR_put_error(0x14,0xd7,0x10e,"ssl_cert.c",0x337);
      break;
    }
    iVar4 = BIO_snprintf(local_420,0x400,"%s/%s",dir,__s);
    if (0x3fe < iVar4 - 1U) break;
    iVar4 = SSL_add_file_cert_subjects_to_stack(stackCAs,local_420);
  } while (iVar4 != 0);
  iVar4 = 0;
LAB_080c58b2:
  mode = local_424;
  if (local_424 != 0) {
    mode = OPENSSL_DIR_end(&local_424);
  }
  CRYPTO_lock(mode,10,(char *)0x18,(int)"ssl_cert.c");
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

