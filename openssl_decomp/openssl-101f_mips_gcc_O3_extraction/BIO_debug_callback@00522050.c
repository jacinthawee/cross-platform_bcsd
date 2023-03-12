
long BIO_debug_callback(BIO *bio,int cmd,char *argp,int argi,long argl,long ret)

{
  undefined *puVar1;
  long lVar2;
  BIO_METHOD *pBVar3;
  int iVar4;
  BUF_MEM *pBVar5;
  char *pcVar6;
  char *format;
  BIO *b;
  char acStack_12c [14];
  char acStack_11e [242];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  lVar2 = 1;
  if ((cmd & 0x80U) != 0) {
    lVar2 = ret;
  }
  BIO_snprintf(acStack_12c,0x100,"BIO[%08lX]:",bio);
  if (cmd == 6) {
    pBVar3 = bio->method;
    pcVar6 = "ctrl(%lu) - %s\n";
LAB_0052211c:
    BIO_snprintf(acStack_11e,0xf2,pcVar6,argi,pBVar3->name);
    goto LAB_00522134;
  }
  if (cmd < 7) {
    if (cmd == 3) {
      pBVar3 = bio->method;
      if ((pBVar3->type & 0x100U) == 0) {
        pcVar6 = pBVar3->name;
        iVar4 = bio->num;
        format = "write(%d,%lu) - %s\n";
LAB_005223c4:
        BIO_snprintf(acStack_11e,0xf2,format,iVar4,argi,pcVar6);
        goto LAB_00522134;
      }
      iVar4 = bio->num;
      pcVar6 = "write(%d,%lu) - %s fd=%d\n";
LAB_005222e4:
      BIO_snprintf(acStack_11e,0xf2,pcVar6,iVar4,argi,pBVar3->name,iVar4);
      goto LAB_00522134;
    }
    if (cmd < 4) {
      if (cmd == 1) {
        BIO_snprintf(acStack_11e,0xf2,"Free - %s\n",bio->method->name);
        goto LAB_00522134;
      }
      if (cmd == 2) {
        pBVar3 = bio->method;
        if ((pBVar3->type & 0x100U) == 0) {
          pcVar6 = pBVar3->name;
          iVar4 = bio->num;
          format = "read(%d,%lu) - %s\n";
          goto LAB_005223c4;
        }
        iVar4 = bio->num;
        pcVar6 = "read(%d,%lu) - %s fd=%d\n";
        goto LAB_005222e4;
      }
    }
    else {
      if (cmd == 4) {
        BIO_snprintf(acStack_11e,0xf2,"puts() - %s\n",bio->method->name);
        goto LAB_00522134;
      }
      if (cmd == 5) {
        pBVar3 = bio->method;
        pcVar6 = "gets(%lu) - %s\n";
        goto LAB_0052211c;
      }
    }
  }
  else {
    if (cmd == 0x84) {
      BIO_snprintf(acStack_11e,0xf2,"puts return %ld\n",ret);
      goto LAB_00522134;
    }
    if (cmd < 0x85) {
      if (cmd == 0x82) {
        BIO_snprintf(acStack_11e,0xf2,"read return %ld\n",ret);
        goto LAB_00522134;
      }
      if (cmd == 0x83) {
        BIO_snprintf(acStack_11e,0xf2,"write return %ld\n",ret);
        goto LAB_00522134;
      }
    }
    else {
      if (cmd == 0x85) {
        BIO_snprintf(acStack_11e,0xf2,"gets return %ld\n",ret);
        goto LAB_00522134;
      }
      if (cmd == 0x86) {
        BIO_snprintf(acStack_11e,0xf2,"ctrl return %ld\n",ret);
        goto LAB_00522134;
      }
    }
  }
  BIO_snprintf(acStack_11e,0xf2,"bio callback - unknown type (%d)\n",cmd);
LAB_00522134:
  b = (BIO *)bio->cb_arg;
  if (b == (BIO *)0x0) {
    (*(code *)PTR_fputs_006aaa64)(acStack_12c,*(undefined4 *)PTR_stderr_006aac00);
  }
  else {
    iVar4 = (*(code *)PTR_strlen_006aab30)(acStack_12c);
    BIO_write(b,acStack_12c,iVar4);
  }
  if (local_2c != *(int *)puVar1) {
    iVar4 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pBVar5 = BUF_MEM_new();
    if (pBVar5 == (BUF_MEM *)0x0) {
      return 0;
    }
    *(BUF_MEM **)(iVar4 + 0x20) = pBVar5;
    *(undefined4 *)(iVar4 + 0x10) = 1;
    *(undefined4 *)(iVar4 + 0xc) = 1;
    *(undefined4 *)(iVar4 + 0x1c) = 0xffffffff;
    return 1;
  }
  return lVar2;
}

