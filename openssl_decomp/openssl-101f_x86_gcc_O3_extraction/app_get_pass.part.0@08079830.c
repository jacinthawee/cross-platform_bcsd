
char * __regparm3 app_get_pass_part_0(BIO *param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  long fd;
  BIO_METHOD *type;
  BIO *b;
  char *pcVar3;
  int in_GS_OFFSET;
  bool bVar4;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  bVar4 = param_3 == 0;
  if (bVar4) {
LAB_080798e8:
    iVar1 = 5;
    pcVar2 = param_2;
    pcVar3 = "file:";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      pwdbio_16708 = BIO_new_file(param_2 + 5,"r");
      if (pwdbio_16708 == (BIO *)0x0) {
        BIO_printf(param_1,"Can\'t open file %s\n",param_2 + 5);
        pcVar2 = (char *)0x0;
        goto LAB_080798c3;
      }
    }
    else {
      iVar1 = 3;
      pcVar2 = param_2;
      pcVar3 = "fd:";
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar2 == *pcVar3;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (bVar4) {
        fd = strtol(param_2 + 3,(char **)0x0,10);
        if (-1 < fd) {
          pwdbio_16708 = BIO_new_fd(fd,0);
          if (pwdbio_16708 != (BIO *)0x0) {
            type = BIO_f_buffer();
            b = BIO_new(type);
            pwdbio_16708 = BIO_push(b,pwdbio_16708);
            goto LAB_08079862;
          }
        }
        BIO_printf(param_1,"Can\'t access file descriptor %s\n",param_2 + 3);
        pcVar2 = (char *)0x0;
        goto LAB_080798c3;
      }
      pcVar2 = "-stdin";
      iVar1 = 6;
      pcVar3 = param_2;
      do {
        pcVar2 = pcVar2 + 1;
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pcVar3 == *pcVar2;
        pcVar3 = pcVar3 + 1;
      } while (bVar4);
      if (!bVar4) {
        BIO_printf(param_1,"Invalid password argument \"%s\"\n",param_2);
        pcVar2 = (char *)0x0;
        goto LAB_080798c3;
      }
      pwdbio_16708 = BIO_new_fp(stdin,0);
      if (pwdbio_16708 == (BIO *)0x0) {
        BIO_printf(param_1,"Can\'t open BIO for stdin\n");
        pcVar2 = (char *)0x0;
        goto LAB_080798c3;
      }
    }
  }
  else {
    bVar4 = pwdbio_16708 == (BIO *)0x0;
    if (bVar4) goto LAB_080798e8;
  }
LAB_08079862:
  iVar1 = BIO_gets(pwdbio_16708,local_420,0x400);
  if (param_3 != 1) {
    BIO_free_all(pwdbio_16708);
    pwdbio_16708 = (BIO *)0x0;
  }
  if (iVar1 < 1) {
    BIO_printf(param_1,"Error reading password from BIO\n");
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = strchr(local_420,10);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '\0';
    }
    pcVar2 = BUF_strdup(local_420);
  }
LAB_080798c3:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pcVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

