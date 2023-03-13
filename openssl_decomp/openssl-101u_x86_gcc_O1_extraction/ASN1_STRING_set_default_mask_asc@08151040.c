
int ASN1_STRING_set_default_mask_asc(char *p)

{
  ulong uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  bool bVar5;
  char *local_14;
  int local_10;
  
  iVar2 = 5;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  bVar5 = true;
  pcVar3 = p;
  pcVar4 = "MASK:";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  if (bVar5) {
    if ((p[5] == '\0') || (uVar1 = strtoul(p + 5,&local_14,0), *local_14 != '\0')) {
LAB_08151070:
      iVar2 = 0;
      goto LAB_08151072;
    }
  }
  else {
    iVar2 = 8;
    pcVar3 = p;
    pcVar4 = "nombstr";
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar5 = *pcVar3 == *pcVar4;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (bVar5);
    if (bVar5) {
      uVar1 = 0xffffd7ff;
    }
    else {
      iVar2 = 5;
      pcVar3 = p;
      pcVar4 = "pkix";
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar5 = *pcVar3 == *pcVar4;
        pcVar3 = pcVar3 + 1;
        pcVar4 = pcVar4 + 1;
      } while (bVar5);
      if (bVar5) {
        uVar1 = 0xfffffffb;
      }
      else {
        iVar2 = 9;
        pcVar3 = p;
        pcVar4 = "utf8only";
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar5 = *pcVar3 == *pcVar4;
          pcVar3 = pcVar3 + 1;
          pcVar4 = pcVar4 + 1;
        } while (bVar5);
        if (bVar5) {
          uVar1 = 0x2000;
        }
        else {
          iVar2 = 8;
          pcVar3 = "default";
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar5 = *p == *pcVar3;
            p = p + 1;
            pcVar3 = pcVar3 + 1;
          } while (bVar5);
          uVar1 = 0xffffffff;
          if (!bVar5) goto LAB_08151070;
        }
      }
    }
  }
  iVar2 = 1;
  global_mask = uVar1;
LAB_08151072:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

