
void app_get_pass_part_0(BIO *param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  BIO *pBVar3;
  long fd;
  BIO_METHOD *type;
  char acStack_41c [1024];
  int local_1c;
  
  local_1c = __TMC_END__;
  if ((param_3 == 0) || (pwdbio_19320 == (BIO *)0x0)) {
    iVar1 = strncmp(param_2,"file:",5);
    if (iVar1 == 0) {
      pBVar3 = BIO_new_file(param_2 + 5,"r");
      pwdbio_19320 = pBVar3;
      if (pBVar3 == (BIO *)0x0) {
        BIO_printf(param_1,"Can\'t open file %s\n",param_2 + 5);
        goto LAB_000332dc;
      }
    }
    else {
      iVar1 = strncmp(param_2,"fd:",3);
      if (iVar1 == 0) {
        fd = strtol(param_2 + 3,(char **)0x0,10);
        if ((fd < 0) || (pwdbio_19320 = BIO_new_fd(fd,0), pwdbio_19320 == (BIO *)0x0)) {
          BIO_printf(param_1,"Can\'t access file descriptor %s\n",param_2 + 3);
          pBVar3 = (BIO *)0x0;
          goto LAB_000332dc;
        }
        type = BIO_f_buffer();
        pBVar3 = BIO_new(type);
        pwdbio_19320 = BIO_push(pBVar3,pwdbio_19320);
      }
      else {
        iVar1 = strcmp(param_2,"stdin");
        if (iVar1 != 0) {
          BIO_printf(param_1,"Invalid password argument \"%s\"\n",param_2);
          pBVar3 = (BIO *)0x0;
          goto LAB_000332dc;
        }
        pBVar3 = BIO_new_fp(stdin,0);
        pwdbio_19320 = pBVar3;
        if (pBVar3 == (BIO *)0x0) {
          BIO_printf(param_1,"Can\'t open BIO for stdin\n");
          goto LAB_000332dc;
        }
      }
    }
  }
  iVar1 = BIO_gets(pwdbio_19320,acStack_41c,0x400);
  if (param_3 != 1) {
    BIO_free_all(pwdbio_19320);
    pwdbio_19320 = (BIO *)0x0;
  }
  if (iVar1 < 1) {
    BIO_printf(param_1,"Error reading password from BIO\n");
    pBVar3 = (BIO *)0x0;
  }
  else {
    pcVar2 = strchr(acStack_41c,10);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    pBVar3 = (BIO *)BUF_strdup(acStack_41c);
  }
LAB_000332dc:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(pBVar3);
  }
  return;
}

