
long BIO_debug_callback(BIO *bio,int cmd,char *argp,int argi,long argl,long ret)

{
  size_t len;
  char *pcVar1;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *b;
  long lVar4;
  char acStack_124 [14];
  char acStack_116 [242];
  int local_24;
  
  lVar4 = ret;
  if ((cmd & 0x80U) == 0) {
    lVar4 = 1;
  }
  local_24 = __TMC_END__;
  BIO_snprintf(acStack_124,0x100,"BIO[%08lX]:",bio);
  if (cmd == 6) {
    pBVar3 = bio->method;
    pcVar1 = "ctrl(%lu) - %s\n";
LAB_0009f1ae:
    BIO_snprintf(acStack_116,0xf2,pcVar1,argi,pBVar3->name);
    goto LAB_0009f1bc;
  }
  if (cmd < 7) {
    if (cmd == 3) {
      pBVar3 = bio->method;
      iVar2 = bio->num;
      if ((pBVar3->type & 0x100U) == 0) {
        pcVar1 = "write(%d,%lu) - %s\n";
LAB_0009f32a:
        BIO_snprintf(acStack_116,0xf2,pcVar1,iVar2,argi,pBVar3->name);
        goto LAB_0009f1bc;
      }
      pcVar1 = "write(%d,%lu) - %s fd=%d\n";
LAB_0009f2a4:
      BIO_snprintf(acStack_116,0xf2,pcVar1,iVar2,argi,pBVar3->name,iVar2);
      goto LAB_0009f1bc;
    }
    if (cmd < 4) {
      if (cmd == 1) {
        BIO_snprintf(acStack_116,0xf2,"Free - %s\n",bio->method->name);
        goto LAB_0009f1bc;
      }
      if (cmd == 2) {
        pBVar3 = bio->method;
        iVar2 = bio->num;
        if ((pBVar3->type & 0x100U) == 0) {
          pcVar1 = "read(%d,%lu) - %s\n";
          goto LAB_0009f32a;
        }
        pcVar1 = "read(%d,%lu) - %s fd=%d\n";
        goto LAB_0009f2a4;
      }
    }
    else {
      if (cmd == 4) {
        BIO_snprintf(acStack_116,0xf2,"puts() - %s\n",bio->method->name);
        goto LAB_0009f1bc;
      }
      if (cmd == 5) {
        pBVar3 = bio->method;
        pcVar1 = "gets(%lu) - %s\n";
        goto LAB_0009f1ae;
      }
    }
  }
  else {
    if (cmd == 0x84) {
      BIO_snprintf(acStack_116,0xf2,"puts return %ld\n",ret);
      goto LAB_0009f1bc;
    }
    if (cmd < 0x85) {
      if (cmd == 0x82) {
        BIO_snprintf(acStack_116,0xf2,"read return %ld\n",ret);
        goto LAB_0009f1bc;
      }
      if (cmd == 0x83) {
        BIO_snprintf(acStack_116,0xf2,"write return %ld\n",ret);
        goto LAB_0009f1bc;
      }
    }
    else {
      if (cmd == 0x85) {
        BIO_snprintf(acStack_116,0xf2,"gets return %ld\n",ret);
        goto LAB_0009f1bc;
      }
      if (cmd == 0x86) {
        BIO_snprintf(acStack_116,0xf2,"ctrl return %ld\n",ret);
        goto LAB_0009f1bc;
      }
    }
  }
  BIO_snprintf(acStack_116,0xf2,"bio callback - unknown type (%d)\n",cmd);
LAB_0009f1bc:
  b = (BIO *)bio->cb_arg;
  if (b == (BIO *)0x0) {
    fputs(acStack_124,stderr);
  }
  else {
    len = strlen(acStack_124);
    BIO_write(b,acStack_124,len);
  }
  if (local_24 == __TMC_END__) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

