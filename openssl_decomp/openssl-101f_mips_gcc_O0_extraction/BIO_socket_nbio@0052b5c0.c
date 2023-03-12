
int BIO_socket_nbio(int fd,int mode)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_18 = mode;
  iVar2 = (*(code *)PTR_ioctl_006aab90)(fd,0x667e,&local_18);
  if (iVar2 < 0) {
    piVar3 = (int *)(*(code *)PTR___errno_location_006aaaf4)();
    ERR_put_error(2,5,*piVar3,"b_sock.c",0x244);
  }
  if (local_14 != *(int *)puVar1) {
    iVar2 = local_14;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;
    puVar1 = PTR_CRYPTO_malloc_006a8108;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    puVar4 = (undefined4 *)(*(code *)puVar1)(0x20,"bss_acpt.c",0x94);
    if (puVar4 != (undefined4 *)0x0) {
      (*(code *)PTR_memset_006aab00)(puVar4,0,0x20);
      puVar4[2] = 0xffffffff;
      puVar4[6] = 0;
      *(undefined4 **)(iVar2 + 0x20) = puVar4;
      *puVar4 = 1;
      *(undefined4 *)(iVar2 + 0x10) = 1;
    }
    return (uint)(puVar4 != (undefined4 *)0x0);
  }
  return (uint)(iVar2 == 0);
}

