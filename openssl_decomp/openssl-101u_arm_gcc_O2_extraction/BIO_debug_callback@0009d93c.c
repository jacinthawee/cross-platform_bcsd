
long BIO_debug_callback(BIO *bio,int cmd,char *argp,int argi,long argl,long ret)

{
  int iVar1;
  char *buf;
  size_t sVar2;
  BIO *b;
  BIO_METHOD *pBVar3;
  long lVar4;
  char acStack_124 [256];
  int local_24;
  
  lVar4 = ret;
  if ((cmd & 0x80U) == 0) {
    lVar4 = 1;
  }
  local_24 = __stack_chk_guard;
  iVar1 = BIO_snprintf(acStack_124,0x100,"BIO[%p]: ",bio);
  buf = acStack_124 + iVar1;
  sVar2 = 0x100 - iVar1;
  if (cmd == 6) {
    BIO_snprintf(buf,sVar2,"ctrl(%lu) - %s\n",argi,bio->method->name);
    goto LAB_0009d9b0;
  }
  if (cmd < 7) {
    if (cmd == 3) {
      pBVar3 = bio->method;
      iVar1 = bio->num;
      if ((pBVar3->type & 0x100U) == 0) {
        BIO_snprintf(buf,sVar2,"write(%d,%lu) - %s\n",iVar1,argi,pBVar3->name);
      }
      else {
        BIO_snprintf(buf,sVar2,"write(%d,%lu) - %s fd=%d\n",iVar1,argi,pBVar3->name,iVar1);
      }
      goto LAB_0009d9b0;
    }
    if (cmd < 4) {
      if (cmd == 1) {
        BIO_snprintf(buf,sVar2,"Free - %s\n",bio->method->name);
        goto LAB_0009d9b0;
      }
      if (cmd == 2) {
        pBVar3 = bio->method;
        iVar1 = bio->num;
        if ((pBVar3->type & 0x100U) == 0) {
          BIO_snprintf(buf,sVar2,"read(%d,%lu) - %s\n",iVar1,argi,pBVar3->name);
        }
        else {
          BIO_snprintf(buf,sVar2,"read(%d,%lu) - %s fd=%d\n",iVar1,argi,pBVar3->name,iVar1);
        }
        goto LAB_0009d9b0;
      }
    }
    else {
      if (cmd == 4) {
        BIO_snprintf(buf,sVar2,"puts() - %s\n",bio->method->name);
        goto LAB_0009d9b0;
      }
      if (cmd == 5) {
        BIO_snprintf(buf,sVar2,"gets(%lu) - %s\n",argi,bio->method->name);
        goto LAB_0009d9b0;
      }
    }
  }
  else {
    if (cmd == 0x84) {
      BIO_snprintf(buf,sVar2,"puts return %ld\n",ret);
      goto LAB_0009d9b0;
    }
    if (cmd < 0x85) {
      if (cmd == 0x82) {
        BIO_snprintf(buf,sVar2,"read return %ld\n",ret);
        goto LAB_0009d9b0;
      }
      if (cmd == 0x83) {
        BIO_snprintf(buf,sVar2,"write return %ld\n",ret);
        goto LAB_0009d9b0;
      }
    }
    else {
      if (cmd == 0x85) {
        BIO_snprintf(buf,sVar2,"gets return %ld\n",ret);
        goto LAB_0009d9b0;
      }
      if (cmd == 0x86) {
        BIO_snprintf(buf,sVar2,"ctrl return %ld\n",ret);
        goto LAB_0009d9b0;
      }
    }
  }
  BIO_snprintf(buf,sVar2,"bio callback - unknown type (%d)\n",cmd);
LAB_0009d9b0:
  b = (BIO *)bio->cb_arg;
  if (b == (BIO *)0x0) {
    fputs(acStack_124,stderr);
  }
  else {
    sVar2 = strlen(acStack_124);
    BIO_write(b,acStack_124,sVar2);
  }
  if (local_24 == __stack_chk_guard) {
    return lVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

