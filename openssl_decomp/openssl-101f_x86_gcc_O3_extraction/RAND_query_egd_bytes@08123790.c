
int RAND_query_egd_bytes(char *path,uchar *buf,int bytes)

{
  size_t sVar1;
  int iVar2;
  ssize_t sVar3;
  int *piVar4;
  int iVar5;
  uint num;
  sockaddr *psVar6;
  byte *pbVar7;
  int in_GS_OFFSET;
  int local_1a4;
  sockaddr local_190 [6];
  byte local_121 [257];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  psVar6 = local_190;
  for (iVar5 = 0x1b; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)psVar6 = 0;
    psVar6 = (sockaddr *)(psVar6->sa_data + 2);
  }
  local_190[0].sa_family = 1;
  psVar6->sa_family = 0;
  sVar1 = strlen(path);
  if (sVar1 < 0x6c) {
    BUF_strlcpy(local_190[0].sa_data,path,0x6c);
    sVar1 = strlen(path);
    iVar5 = socket(1,1,0);
    if (iVar5 != -1) {
LAB_08123823:
      do {
        iVar2 = connect(iVar5,local_190,sVar1 + 2);
        if (iVar2 == 0) {
LAB_08123839:
          local_1a4 = 0;
          if (bytes < 1) goto LAB_081238c8;
          goto LAB_08123853;
        }
        piVar4 = __errno_location();
        iVar2 = *piVar4;
        if (iVar2 == 0x6a) goto LAB_08123839;
        if (0x6a < iVar2) {
          if (1 < iVar2 - 0x72U) {
            local_1a4 = 0;
            goto LAB_081238c8;
          }
          goto LAB_08123823;
        }
      } while ((iVar2 == 4) || (iVar2 == 0xb));
      local_1a4 = 0;
      goto LAB_081238c8;
    }
  }
  local_1a4 = -1;
  goto LAB_081238d8;
LAB_081238bd:
  local_1a4 = -1;
  goto LAB_081238c8;
  while( true ) {
    pbVar7 = buf + local_1a4;
    if (buf == (uchar *)0x0) {
      pbVar7 = local_121 + 2;
    }
    num = 0;
    while (num != local_121[0]) {
      sVar3 = read(iVar5,pbVar7 + num,local_121[0] - num);
      if (sVar3 == 0) goto LAB_081238c8;
      if (sVar3 < 1) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_081238bd;
      }
      else {
        num = num + sVar3;
      }
    }
    local_1a4 = local_1a4 + num;
    bytes = bytes - num;
    if (buf == (uchar *)0x0) {
      RAND_seed(local_121 + 2,num);
    }
    if (bytes < 1) break;
LAB_08123853:
    local_121[1] = 0xff;
    local_121[0] = 1;
    if (bytes < 0x100) {
      local_121[1] = (byte)bytes;
    }
    iVar2 = 0;
    do {
      sVar3 = write(iVar5,local_121 + iVar2,2 - iVar2);
      if (sVar3 < 0) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_081238bd;
      }
      else {
        iVar2 = iVar2 + sVar3;
      }
    } while (iVar2 != 2);
    iVar2 = 0;
    do {
      sVar3 = read(iVar5,local_121,1);
      if (sVar3 == 0) goto LAB_081238c8;
      if (sVar3 < 1) {
        piVar4 = __errno_location();
        if ((*piVar4 != 4) && (*piVar4 != 0xb)) goto LAB_081238bd;
      }
      else {
        iVar2 = iVar2 + sVar3;
      }
    } while (iVar2 != 1);
    if (local_121[0] == 0) break;
  }
LAB_081238c8:
  close(iVar5);
LAB_081238d8:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_1a4;
}

