
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_poll(void)

{
  __pid_t _Var1;
  int iVar2;
  int iVar3;
  ssize_t sVar4;
  char *path;
  size_t len;
  undefined **ppuVar5;
  uint uVar6;
  stat *__stat_buf;
  char **ppcVar7;
  undefined4 in_stack_fffffe98;
  pollfd local_160;
  undefined local_158 [12];
  __ino_t local_14c;
  int local_100;
  int iStack_fc;
  __ino_t local_f4;
  uchar auStack_4c [32];
  int local_2c;
  
  ppcVar7 = (char **)PTR_s_S_0010b0e0;
  uVar6 = 0;
  __stat_buf = (stat *)local_158;
  len = 0;
  local_2c = __stack_chk_guard;
  _Var1 = getpid();
  memset(local_158,0,0x108);
  do {
    ppcVar7 = ppcVar7 + 1;
    iVar2 = open(*ppcVar7,0x900);
    if (-1 < iVar2) {
      iVar3 = __fxstat(3,iVar2,__stat_buf);
      if ((iVar3 == 0) &&
         ((uVar6 == 0 ||
          (((local_14c != __stat_buf->st_ino ||
            (local_158._4_4_ != *(int *)((int)&__stat_buf->st_dev + 4) ||
             local_158._0_4_ != *(int *)&__stat_buf->st_dev)) &&
           ((uVar6 != 2 ||
            ((__stat_buf->st_ino != local_f4 ||
             (iStack_fc != *(int *)((int)&__stat_buf->st_dev + 4) ||
              local_100 != *(int *)&__stat_buf->st_dev)))))))))) {
        local_160.events = 1;
        local_160.revents = 0;
        local_160.fd = iVar2;
        iVar3 = poll(&local_160,1,10);
        if ((-1 < iVar3) &&
           (((int)((uint)(ushort)local_160.revents << 0x1f) < 0 &&
            (sVar4 = read(iVar2,auStack_4c + len,0x20 - len), 0 < sVar4)))) {
          len = len + sVar4;
        }
      }
      close(iVar2);
    }
    uVar6 = uVar6 + 1;
    __stat_buf = __stat_buf + 1;
  } while (uVar6 < 3 && (int)len < 0x20);
  ppuVar5 = &egdsockets_12593;
  path = egdsockets_12593;
  while (path != (undefined *)0x0) {
    if (0x1f < (int)len) goto LAB_0010b094;
    iVar2 = RAND_query_egd_bytes(path,auStack_4c + len,0x20 - len);
    if (0 < iVar2) {
      len = len + iVar2;
    }
    ppuVar5 = ppuVar5 + 1;
    path = *ppuVar5;
  }
  if (len != 0) {
LAB_0010b094:
    RAND_add(auStack_4c,0x20,(double)CONCAT44(_Var1,in_stack_fffffe98));
    OPENSSL_cleanse(auStack_4c,len);
  }
  local_160.fd = _Var1;
  RAND_add(&local_160,4,(double)CONCAT44(_Var1,in_stack_fffffe98));
  local_160.fd = getuid();
  RAND_add(&local_160,4,(double)CONCAT44(_Var1,in_stack_fffffe98));
  local_160.fd = time((time_t *)0x0);
  RAND_add(&local_160,4,(double)CONCAT44(_Var1,in_stack_fffffe98));
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

