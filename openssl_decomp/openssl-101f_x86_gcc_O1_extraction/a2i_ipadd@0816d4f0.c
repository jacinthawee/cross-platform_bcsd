
int a2i_ipadd(uchar *ipout,char *ipasc)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int in_GS_OFFSET;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c [4];
  size_t local_2c;
  size_t local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar3 = strchr(ipasc,0x3a);
  if (pcVar3 == (char *)0x0) {
    iVar4 = __isoc99_sscanf(ipasc,"%d.%d.%d.%d",&local_4c,&local_48,&local_44,&local_40);
    if ((((iVar4 == 4) && (local_4c < 0x100)) && (local_48 < 0x100)) &&
       ((local_44 < 0x100 && (local_40 < 0x100)))) {
      ipout[1] = (uchar)local_48;
      *ipout = (uchar)local_4c;
      ipout[2] = (uchar)local_44;
      ipout[3] = (uchar)local_40;
      goto LAB_0816d5f2;
    }
  }
  else {
    local_2c = 0;
    local_28 = 0xffffffff;
    local_24 = 0;
    iVar4 = CONF_parse_list(ipasc,0x3a,0,ipv6_cb,local_3c);
    sVar2 = local_28;
    sVar1 = local_2c;
    if (iVar4 != 0) {
      if (local_28 == 0xffffffff) {
        if (local_2c == 0x10) {
LAB_0816d617:
          *(undefined4 *)ipout = local_3c[0];
          *(undefined4 *)(ipout + 4) = local_3c[1];
          *(undefined4 *)(ipout + 8) = local_3c[2];
          *(undefined4 *)(ipout + 0xc) = local_3c[3];
LAB_0816d5d7:
          iVar4 = 0x10;
          goto LAB_0816d5f2;
        }
      }
      else if ((local_2c != 0x10) && (local_24 < 4)) {
        if (local_24 == 3) {
          if ((int)local_2c < 1) goto LAB_0816d58e;
        }
        else if (local_24 == 2) {
          if ((local_28 == 0) || (local_28 == local_2c)) goto LAB_0816d58e;
        }
        else if ((local_28 != local_2c) && (local_28 != 0)) {
LAB_0816d58e:
          if ((int)local_28 < 0) goto LAB_0816d617;
          memcpy(ipout,local_3c,local_28);
          memset(ipout + sVar2,0,0x10 - sVar1);
          if (sVar2 != sVar1) {
            memcpy(ipout + ((sVar2 + 0x10) - sVar1),(void *)((int)local_3c + sVar2),sVar1 - sVar2);
          }
          goto LAB_0816d5d7;
        }
      }
    }
  }
  iVar4 = 0;
LAB_0816d5f2:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

