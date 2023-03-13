
long BIO_debug_callback(BIO *bio,int cmd,char *argp,int argi,long argl,long ret)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  BUF_MEM *pBVar4;
  BIO_METHOD *pBVar5;
  char *buf;
  size_t n;
  char *format;
  BIO *b;
  char acStack_12c [256];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  lVar2 = 1;
  if ((cmd & 0x80U) != 0) {
    lVar2 = ret;
  }
  iVar3 = BIO_snprintf(acStack_12c,0x100,"BIO[%p]: ",bio);
  buf = acStack_12c + iVar3;
  n = 0x100 - iVar3;
  if (cmd == 6) {
    BIO_snprintf(buf,n,"ctrl(%lu) - %s\n",argi,bio->method->name);
    goto LAB_00520258;
  }
  if (cmd < 7) {
    if (cmd == 3) {
      pBVar5 = bio->method;
      if ((pBVar5->type & 0x100U) == 0) {
        BIO_snprintf(buf,n,"write(%d,%lu) - %s\n",bio->num,argi,pBVar5->name);
        goto LAB_00520258;
      }
      iVar3 = bio->num;
      format = "write(%d,%lu) - %s fd=%d\n";
LAB_005203dc:
      BIO_snprintf(buf,n,format,iVar3,argi,pBVar5->name,iVar3);
      goto LAB_00520258;
    }
    if (cmd < 4) {
      if (cmd == 1) {
        BIO_snprintf(buf,n,"Free - %s\n",bio->method->name);
        goto LAB_00520258;
      }
      if (cmd == 2) {
        pBVar5 = bio->method;
        if ((pBVar5->type & 0x100U) == 0) {
          BIO_snprintf(buf,n,"read(%d,%lu) - %s\n",bio->num,argi,pBVar5->name);
          goto LAB_00520258;
        }
        iVar3 = bio->num;
        format = "read(%d,%lu) - %s fd=%d\n";
        goto LAB_005203dc;
      }
    }
    else {
      if (cmd == 4) {
        BIO_snprintf(buf,n,"puts() - %s\n",bio->method->name);
        goto LAB_00520258;
      }
      if (cmd == 5) {
        BIO_snprintf(buf,n,"gets(%lu) - %s\n",argi,bio->method->name);
        goto LAB_00520258;
      }
    }
  }
  else {
    if (cmd == 0x84) {
      BIO_snprintf(buf,n,"puts return %ld\n",ret);
      goto LAB_00520258;
    }
    if (cmd < 0x85) {
      if (cmd == 0x82) {
        BIO_snprintf(buf,n,"read return %ld\n",ret);
        goto LAB_00520258;
      }
      if (cmd == 0x83) {
        BIO_snprintf(buf,n,"write return %ld\n",ret);
        goto LAB_00520258;
      }
    }
    else {
      if (cmd == 0x85) {
        BIO_snprintf(buf,n,"gets return %ld\n",ret);
        goto LAB_00520258;
      }
      if (cmd == 0x86) {
        BIO_snprintf(buf,n,"ctrl return %ld\n",ret);
        goto LAB_00520258;
      }
    }
  }
  BIO_snprintf(buf,n,"bio callback - unknown type (%d)\n",cmd);
LAB_00520258:
  b = (BIO *)bio->cb_arg;
  if (b == (BIO *)0x0) {
    (*(code *)PTR_fputs_006a9954)(acStack_12c,*(undefined4 *)PTR_stderr_006a9af8);
  }
  else {
    iVar3 = (*(code *)PTR_strlen_006a9a24)(acStack_12c);
    BIO_write(b,acStack_12c,iVar3);
  }
  if (local_2c != *(int *)puVar1) {
    iVar3 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pBVar4 = BUF_MEM_new();
    if (pBVar4 == (BUF_MEM *)0x0) {
      return 0;
    }
    *(BUF_MEM **)(iVar3 + 0x20) = pBVar4;
    *(undefined4 *)(iVar3 + 0x10) = 1;
    *(undefined4 *)(iVar3 + 0xc) = 1;
    *(undefined4 *)(iVar3 + 0x1c) = 0xffffffff;
    return 1;
  }
  return lVar2;
}

