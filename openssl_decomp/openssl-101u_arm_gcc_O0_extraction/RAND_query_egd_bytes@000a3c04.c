
int RAND_query_egd_bytes(char *path,uchar *buf,int bytes)

{
  size_t sVar1;
  int __fd;
  int iVar2;
  ssize_t sVar3;
  int *piVar4;
  uint num;
  int iVar5;
  int iVar6;
  uint uVar7;
  uchar *puVar8;
  byte local_1a0 [4];
  sockaddr local_19c [7];
  uchar auStack_12c [256];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  memset(local_19c,0,0x6e);
  local_19c[0].sa_family = 1;
  sVar1 = strlen(path);
  if (sVar1 < 0x6c) {
    BUF_strlcpy(local_19c[0].sa_data,path,0x6c);
    sVar1 = strlen(path);
    __fd = socket(1,1,0);
    if (__fd != -1) {
LAB_000a3c5a:
      do {
        iVar2 = connect(__fd,local_19c,sVar1 + 2);
        if (iVar2 == 0) {
LAB_000a3c66:
          iVar2 = 0;
          if (0 < bytes) goto LAB_000a3c74;
          goto LAB_000a3cb6;
        }
        piVar4 = __errno_location();
        iVar2 = *piVar4;
        if (iVar2 == 0x6a) goto LAB_000a3c66;
        if (iVar2 < 0x6b) {
          if ((iVar2 != 4) && (iVar2 != 0xb)) {
            iVar2 = 0;
            goto LAB_000a3cb6;
          }
          goto LAB_000a3c5a;
        }
      } while (iVar2 - 0x72U < 2);
      iVar2 = 0;
      goto LAB_000a3cb6;
    }
  }
  iVar2 = -1;
  goto LAB_000a3cbe;
LAB_000a3cb2:
  iVar2 = -1;
  goto LAB_000a3cb6;
  while( true ) {
    puVar8 = buf + iVar2;
    if (buf == (uchar *)0x0) {
      puVar8 = auStack_12c;
    }
    uVar7 = 0;
    while (num != uVar7) {
      sVar3 = read(__fd,puVar8 + uVar7,num - uVar7);
      if (sVar3 == 0) goto LAB_000a3cb6;
      if (sVar3 < 1) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_000a3cb2;
      }
      else {
        uVar7 = uVar7 + sVar3;
      }
      num = (uint)local_1a0[0];
    }
    iVar2 = iVar2 + num;
    bytes = bytes - num;
    if (buf == (uchar *)0x0) {
      RAND_seed(auStack_12c,num);
    }
    if (bytes < 1) break;
LAB_000a3c74:
    iVar6 = 0;
    local_1a0[0] = 1;
    iVar5 = 0xff;
    if (bytes < 0x100) {
      iVar5 = bytes;
    }
    local_1a0[1] = (byte)iVar5;
    do {
      sVar3 = write(__fd,local_1a0 + iVar6,2 - iVar6);
      if (sVar3 < 0) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_000a3cb2;
      }
      else {
        iVar6 = iVar6 + sVar3;
      }
    } while (iVar6 != 2);
    iVar6 = 0;
    do {
      sVar3 = read(__fd,local_1a0,1);
      if (sVar3 == 0) goto LAB_000a3cb6;
      if (sVar3 < 1) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_000a3cb2;
      }
      else {
        iVar6 = iVar6 + sVar3;
      }
    } while (iVar6 != 1);
    num = (uint)local_1a0[0];
    if (num == 0) break;
  }
LAB_000a3cb6:
  close(__fd);
LAB_000a3cbe:
  if (local_2c == __stack_chk_guard) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

