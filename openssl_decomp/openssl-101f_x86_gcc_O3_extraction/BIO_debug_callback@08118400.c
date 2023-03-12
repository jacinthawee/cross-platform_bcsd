
long BIO_debug_callback(BIO *bio,int cmd,char *argp,int argi,long argl,long ret)

{
  BIO *b;
  BIO_METHOD *pBVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  long lVar6;
  int in_GS_OFFSET;
  bool bVar7;
  char *format;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  uint local_120 [3];
  char local_112 [242];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar6 = 1;
  if ((cmd & 0x80U) != 0) {
    lVar6 = ret;
  }
  pcVar11 = "BIO[%08lX]:";
  pcVar10 = (char *)0x100;
  BIO_snprintf((char *)local_120,0x100,"BIO[%08lX]:",bio);
  pcVar8 = (char *)argi;
  if (cmd == 6) {
    pcVar9 = bio->method->name;
    format = "ctrl(%lu) - %s\n";
LAB_08118497:
    BIO_snprintf(local_112,0xf2,format,pcVar8,pcVar9,pcVar10,pcVar11);
    b = (BIO *)bio->cb_arg;
  }
  else {
    if (cmd < 7) {
      pcVar9 = (char *)argi;
      if (cmd == 3) {
        pBVar1 = bio->method;
        if ((pBVar1->type & 0x100U) == 0) {
          pcVar10 = pBVar1->name;
          format = "write(%d,%lu) - %s\n";
          pcVar8 = (char *)bio->num;
        }
        else {
          pcVar11 = (char *)bio->num;
          pcVar10 = pBVar1->name;
          format = "write(%d,%lu) - %s fd=%d\n";
          pcVar8 = pcVar11;
        }
        goto LAB_08118497;
      }
      if (cmd < 4) {
        if (cmd != 1) {
          if (cmd != 2) goto LAB_081185f8;
          pBVar1 = bio->method;
          if ((pBVar1->type & 0x100U) == 0) {
            pcVar10 = pBVar1->name;
            format = "read(%d,%lu) - %s\n";
            pcVar8 = (char *)bio->num;
          }
          else {
            pcVar11 = (char *)bio->num;
            pcVar10 = pBVar1->name;
            format = "read(%d,%lu) - %s fd=%d\n";
            pcVar8 = pcVar11;
          }
          goto LAB_08118497;
        }
        cmd = (int)bio->method->name;
        pcVar11 = "Free - %s\n";
      }
      else if (cmd == 4) {
        cmd = (int)bio->method->name;
        pcVar11 = "puts() - %s\n";
      }
      else {
        if (cmd == 5) {
          format = "gets(%lu) - %s\n";
          pcVar9 = bio->method->name;
          goto LAB_08118497;
        }
LAB_081185f8:
        pcVar11 = "bio callback - unknown type (%d)\n";
      }
    }
    else if (cmd == 0x84) {
      pcVar11 = "puts return %ld\n";
      cmd = ret;
    }
    else if (cmd < 0x85) {
      if (cmd == 0x82) {
        pcVar11 = "read return %ld\n";
        cmd = ret;
      }
      else {
        if (cmd != 0x83) goto LAB_081185f8;
        pcVar11 = "write return %ld\n";
        cmd = ret;
      }
    }
    else if (cmd == 0x85) {
      pcVar11 = "gets return %ld\n";
      cmd = ret;
    }
    else {
      if (cmd != 0x86) goto LAB_081185f8;
      pcVar11 = "ctrl return %ld\n";
      cmd = ret;
    }
    BIO_snprintf(local_112,0xf2,pcVar11,cmd);
    b = (BIO *)bio->cb_arg;
  }
  puVar5 = local_120;
  if (b == (BIO *)0x0) {
    fputs((char *)local_120,stderr);
  }
  else {
    do {
      puVar4 = puVar5;
      uVar2 = *puVar4 + 0xfefefeff & ~*puVar4;
      uVar3 = uVar2 & 0x80808080;
      puVar5 = puVar4 + 1;
    } while (uVar3 == 0);
    bVar7 = (uVar2 & 0x8080) == 0;
    if (bVar7) {
      uVar3 = uVar3 >> 0x10;
    }
    if (bVar7) {
      puVar5 = (uint *)((int)puVar4 + 6);
    }
    BIO_write(b,local_120,
              (int)((int)puVar5 + ((-3 - (uint)CARRY1((byte)uVar3,(byte)uVar3)) - (int)local_120)));
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return lVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

