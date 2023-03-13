
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_poll(void)

{
  __pid_t _Var1;
  int iVar2;
  ssize_t sVar3;
  char *path;
  int iVar4;
  size_t len;
  uint uVar5;
  undefined1 *puVar6;
  stat *psVar7;
  int in_GS_OFFSET;
  byte bVar8;
  stat *local_168;
  pollfd local_150;
  uint local_148;
  uint local_144;
  __ino_t local_13c;
  uint local_f0;
  uint local_ec;
  __ino_t local_e4;
  uint local_98;
  uint local_94;
  uchar local_40 [32];
  int local_20;
  
  bVar8 = 0;
  uVar5 = 0;
  len = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  _Var1 = getpid();
  local_168 = (stat *)&local_148;
  psVar7 = local_168;
  for (iVar4 = 0x42; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(uint *)&psVar7->st_dev = 0;
    psVar7 = (stat *)((int)psVar7 + (uint)bVar8 * -8 + 4);
  }
  do {
    iVar4 = open(*(char **)(randomfiles_9977 + uVar5 * 4),0x900);
    if (-1 < iVar4) {
      iVar2 = __fxstat(3,iVar4,local_168);
      if ((iVar2 == 0) &&
         ((uVar5 == 0 ||
          (((local_13c != local_168->st_ino ||
            ((local_144 ^ *(uint *)((int)&local_168->st_dev + 4) |
             local_148 ^ *(uint *)&local_168->st_dev) != 0)) &&
           ((uVar5 != 2 ||
            ((local_168->st_ino != local_e4 || ((local_ec ^ local_94 | local_f0 ^ local_98) != 0))))
           )))))) {
        local_150.events = 1;
        local_150.revents = 0;
        local_150.fd = iVar4;
        iVar2 = poll(&local_150,1,10);
        if ((-1 < iVar2) && ((local_150.revents & 1U) != 0)) {
          sVar3 = read(iVar4,local_40 + len,0x20 - len);
          if (0 < sVar3) {
            len = len + sVar3;
          }
        }
      }
      close(iVar4);
    }
    uVar5 = uVar5 + 1;
    local_168 = local_168 + 1;
  } while ((uVar5 < 3) && ((int)len < 0x20));
  if (egdsockets_9981._0_4_ == (char *)0x0) {
LAB_081c847b:
    if (len == 0) goto LAB_081c847f;
  }
  else if ((int)len < 0x20) {
    puVar6 = egdsockets_9981;
    path = egdsockets_9981._0_4_;
    do {
      iVar4 = RAND_query_egd_bytes(path,local_40 + len,0x20 - len);
      if (0 < iVar4) {
        len = len + iVar4;
      }
      puVar6 = (undefined1 *)((int)puVar6 + 4);
      path = *(char **)puVar6;
      if (path == (char *)0x0) goto LAB_081c847b;
    } while ((int)len < 0x20);
  }
  RAND_add(local_40,0x20,(double)len);
  OPENSSL_cleanse(local_40,len);
LAB_081c847f:
  local_150.fd = _Var1;
  RAND_add(&local_150,4,0.0);
  local_150.fd = getuid();
  RAND_add(&local_150,4,0.0);
  local_150.fd = time((time_t *)0x0);
  RAND_add(&local_150,4,0.0);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

