
/* WARNING: Type propagation algorithm not settling */

int RAND_query_egd_bytes(char *path,uchar *buf,int bytes)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *path_00;
  undefined2 *bytes_00;
  undefined2 *puVar7;
  undefined2 *num;
  uchar *puVar8;
  uchar *local_1a8;
  undefined2 local_1a0;
  char acStack_19e [110];
  byte local_130;
  undefined local_12f;
  uchar auStack_12c [256];
  char *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  bytes_00 = (undefined2 *)0x0;
  local_2c = *(char **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_memset_006a99f4)(&local_1a0,0,0x6e);
  local_1a0 = 1;
  uVar2 = (*(code *)PTR_strlen_006a9a24)(path);
  if (uVar2 < 0x6c) {
    BUF_strlcpy(acStack_19e,path,0x6c);
    iVar3 = (*(code *)PTR_strlen_006a9a24)(path);
    bytes_00 = (undefined2 *)&SUB_00000002;
    iVar4 = (*(code *)PTR_socket_006a9984)(1,2,0);
    if (iVar4 != -1) {
LAB_0052d574:
      do {
        bytes_00 = &local_1a0;
        iVar5 = (*(code *)PTR_connect_006a9950)(iVar4,&local_1a0,iVar3 + 2);
        if (iVar5 == 0) {
LAB_0052d588:
          puVar8 = (uchar *)0x0;
          if (bytes < 1) goto LAB_0052d644;
          goto LAB_0052d5a4;
        }
        piVar6 = (int *)(*(code *)PTR___errno_location_006a99e8)();
        iVar5 = *piVar6;
        if (iVar5 == 0x85) goto LAB_0052d588;
        if (iVar5 < 0x86) {
          if ((iVar5 != 4) && (iVar5 != 0xb)) {
            puVar8 = (uchar *)0x0;
            goto LAB_0052d644;
          }
          goto LAB_0052d574;
        }
      } while (iVar5 - 0x95U < 2);
      puVar8 = (uchar *)0x0;
      goto LAB_0052d644;
    }
  }
  puVar8 = (uchar *)0xffffffff;
  goto LAB_0052d654;
LAB_0052d63c:
  puVar8 = (uchar *)0xffffffff;
  goto LAB_0052d644;
  while (RAND_seed(auStack_12c,(int)num), bytes_00 = num, 0 < bytes) {
LAB_0052d5a4:
    iVar3 = 0;
    local_130 = 1;
    local_12f = 0xff;
    if (bytes < 0x100) {
      local_12f = (undefined)bytes;
    }
    do {
      while( true ) {
        bytes_00 = (undefined2 *)((int)&local_130 + iVar3);
        iVar5 = (*(code *)PTR_write_006a9a1c)(iVar4,bytes_00,2 - iVar3);
        if (iVar5 < 0) break;
        iVar3 = iVar3 + iVar5;
LAB_0052d5dc:
        if (iVar3 == 2) {
          iVar3 = 0;
          goto LAB_0052d5fc;
        }
      }
      piVar6 = (int *)(*(code *)PTR___errno_location_006a99e8)();
      if (*piVar6 == 4) goto LAB_0052d5dc;
      if (*piVar6 != 0xb) goto LAB_0052d63c;
    } while (iVar3 != 2);
    iVar3 = 0;
LAB_0052d5fc:
    do {
      bytes_00 = (undefined2 *)&local_130;
      iVar5 = (*(code *)PTR_read_006a9b10)(iVar4,&local_130,1);
      if (iVar5 == 0) goto LAB_0052d644;
      if (iVar5 < 1) {
        piVar6 = (int *)(*(code *)PTR___errno_location_006a99e8)();
        if ((*piVar6 != 4) && (*piVar6 != 0xb)) goto LAB_0052d63c;
      }
      else {
        iVar3 = iVar3 + iVar5;
      }
      puVar7 = (undefined2 *)(uint)local_130;
    } while (iVar3 != 1);
    if (puVar7 == (undefined2 *)0x0) break;
    local_1a8 = buf + (int)puVar8;
    if (buf == (uchar *)0x0) {
      local_1a8 = auStack_12c;
      num = (undefined2 *)0x0;
    }
    else {
      num = (undefined2 *)0x0;
    }
    while (num != puVar7) {
      bytes_00 = (undefined2 *)(local_1a8 + (int)num);
      iVar3 = (*(code *)PTR_read_006a9b10)(iVar4,bytes_00,(int)puVar7 - (int)num);
      if (iVar3 == 0) goto LAB_0052d644;
      if (iVar3 < 1) {
        piVar6 = (int *)(*(code *)PTR___errno_location_006a99e8)();
        if (*piVar6 == 4) goto LAB_0052d764;
        puVar7 = (undefined2 *)(uint)local_130;
        if (*piVar6 != 0xb) goto LAB_0052d63c;
      }
      else {
        num = (undefined2 *)((int)num + iVar3);
LAB_0052d764:
        puVar7 = (undefined2 *)(uint)local_130;
      }
    }
    puVar8 = puVar8 + (int)num;
    bytes = bytes - (int)num;
    if (buf != (uchar *)0x0) {
      if (bytes < 1) break;
      goto LAB_0052d5a4;
    }
  }
LAB_0052d644:
  (*(code *)PTR_close_006a994c)(iVar4);
LAB_0052d654:
  if (local_2c != *(char **)puVar1) {
    path_00 = local_2c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar3 = RAND_query_egd_bytes(path_00,(uchar *)0x0,(int)bytes_00);
    if ((iVar3 < 1) || (iVar4 = RAND_status(), iVar4 != 1)) {
      iVar3 = 0;
    }
    return iVar3;
  }
  return (int)puVar8;
}

