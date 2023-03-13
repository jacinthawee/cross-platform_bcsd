
long BIO_debug_callback(BIO *bio,int cmd,char *argp,int argi,long argl,long ret)

{
  char *buf;
  BIO_METHOD *pBVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  size_t n;
  uint *puVar5;
  uint *puVar6;
  long lVar7;
  int in_GS_OFFSET;
  bool bVar8;
  uint local_120 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar7 = 1;
  if ((cmd & 0x80U) != 0) {
    lVar7 = ret;
  }
  iVar2 = BIO_snprintf((char *)local_120,0x100,"BIO[%p]: ",bio);
  buf = (char *)((int)local_120 + iVar2);
  n = 0x100 - iVar2;
  if (cmd == 6) {
    BIO_snprintf(buf,n,"ctrl(%lu) - %s\n",argi,bio->method->name);
    goto LAB_08116de0;
  }
  if (cmd < 7) {
    if (cmd == 3) {
      pBVar1 = bio->method;
      if ((pBVar1->type & 0x100U) == 0) {
        BIO_snprintf(buf,n,"write(%d,%lu) - %s\n",bio->num,argi,pBVar1->name);
      }
      else {
        BIO_snprintf(buf,n,"write(%d,%lu) - %s fd=%d\n",bio->num,argi,pBVar1->name,bio->num);
      }
      goto LAB_08116de0;
    }
    if (cmd < 4) {
      if (cmd == 1) {
        BIO_snprintf(buf,n,"Free - %s\n",bio->method->name);
        goto LAB_08116de0;
      }
      if (cmd == 2) {
        pBVar1 = bio->method;
        if ((pBVar1->type & 0x100U) == 0) {
          BIO_snprintf(buf,n,"read(%d,%lu) - %s\n",bio->num,argi,pBVar1->name);
        }
        else {
          BIO_snprintf(buf,n,"read(%d,%lu) - %s fd=%d\n",bio->num,argi,pBVar1->name,bio->num);
        }
        goto LAB_08116de0;
      }
    }
    else {
      if (cmd == 4) {
        BIO_snprintf(buf,n,"puts() - %s\n",bio->method->name);
        goto LAB_08116de0;
      }
      if (cmd == 5) {
        BIO_snprintf(buf,n,"gets(%lu) - %s\n",argi,bio->method->name);
        goto LAB_08116de0;
      }
    }
  }
  else {
    if (cmd == 0x84) {
      BIO_snprintf(buf,n,"puts return %ld\n",ret);
      goto LAB_08116de0;
    }
    if (cmd < 0x85) {
      if (cmd == 0x82) {
        BIO_snprintf(buf,n,"read return %ld\n",ret);
        goto LAB_08116de0;
      }
      if (cmd == 0x83) {
        BIO_snprintf(buf,n,"write return %ld\n",ret);
        goto LAB_08116de0;
      }
    }
    else {
      if (cmd == 0x85) {
        BIO_snprintf(buf,n,"gets return %ld\n",ret);
        goto LAB_08116de0;
      }
      if (cmd == 0x86) {
        BIO_snprintf(buf,n,"ctrl return %ld\n",ret);
        goto LAB_08116de0;
      }
    }
  }
  BIO_snprintf(buf,n,"bio callback - unknown type (%d)\n",cmd);
LAB_08116de0:
  puVar6 = local_120;
  if ((BIO *)bio->cb_arg == (BIO *)0x0) {
    fputs((char *)local_120,stderr);
  }
  else {
    do {
      puVar5 = puVar6;
      uVar3 = *puVar5 + 0xfefefeff & ~*puVar5;
      uVar4 = uVar3 & 0x80808080;
      puVar6 = puVar5 + 1;
    } while (uVar4 == 0);
    bVar8 = (uVar3 & 0x8080) == 0;
    if (bVar8) {
      uVar4 = uVar4 >> 0x10;
    }
    if (bVar8) {
      puVar6 = (uint *)((int)puVar5 + 6);
    }
    BIO_write((BIO *)bio->cb_arg,local_120,
              (int)((int)puVar6 + ((-3 - (uint)CARRY1((byte)uVar4,(byte)uVar4)) - (int)local_120)));
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}

