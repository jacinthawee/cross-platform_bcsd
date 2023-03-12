
int a2i_ipadd(uchar *ipout,char *ipasc)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  uint local_58 [2];
  uint local_50 [2];
  uint local_48 [2];
  uint local_40 [2];
  undefined4 local_38 [4];
  size_t local_28;
  size_t local_24;
  int local_20;
  int local_1c;
  
  local_1c = __TMC_END__;
  pcVar3 = strchr(ipasc,0x3a);
  if (pcVar3 == (char *)0x0) {
    iVar4 = __isoc99_sscanf(ipasc,"%d.%d.%d.%d",local_58,local_50,local_48,local_40);
    if ((((iVar4 == 4) && (local_58[0] < 0x100)) && (local_50[0] < 0x100)) &&
       ((local_48[0] < 0x100 && (local_40[0] < 0x100)))) {
      *ipout = (uchar)local_58[0];
      ipout[1] = (uchar)local_50[0];
      ipout[2] = (uchar)local_48[0];
      ipout[3] = (uchar)local_40[0];
      goto LAB_000d2744;
    }
  }
  else {
    local_28 = 0;
    local_20 = 0;
    local_24 = 0xffffffff;
    iVar4 = CONF_parse_list(ipasc,0x3a,0,ipv6_cb + 1,local_38);
    sVar2 = local_24;
    sVar1 = local_28;
    if (iVar4 != 0) {
      if (local_24 == 0xffffffff) {
        if (local_28 == 0x10) {
LAB_000d2758:
          *(undefined4 *)ipout = local_38[0];
          *(undefined4 *)(ipout + 4) = local_38[1];
          *(undefined4 *)(ipout + 8) = local_38[2];
          *(undefined4 *)(ipout + 0xc) = local_38[3];
LAB_000d2738:
          iVar4 = 0x10;
          goto LAB_000d2744;
        }
      }
      else if ((local_28 != 0x10) && (local_20 < 4)) {
        if (local_20 == 3) {
          if ((int)local_28 < 1) {
LAB_000d2706:
            if ((int)local_24 < 0) goto LAB_000d2758;
LAB_000d270a:
            memcpy(ipout,local_38,local_24);
            memset(ipout + sVar2,0,0x10 - sVar1);
            if (sVar2 != sVar1) {
              memcpy(ipout + ((sVar2 + 0x10) - sVar1),(void *)((int)local_38 + sVar2),sVar1 - sVar2)
              ;
            }
            goto LAB_000d2738;
          }
        }
        else if (local_20 == 2) {
          if (local_24 == 0) goto LAB_000d270a;
          if (local_24 == local_28) goto LAB_000d2706;
        }
        else if ((local_24 != 0) && (local_24 != local_28)) goto LAB_000d2706;
      }
    }
  }
  iVar4 = 0;
LAB_000d2744:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}

