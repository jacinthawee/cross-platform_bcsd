
ASN1_OCTET_STRING * a2i_IPADDRESS(char *ipasc)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  ASN1_OCTET_STRING *str;
  ASN1_OCTET_STRING *pAVar4;
  int iVar5;
  uint local_68 [2];
  uint local_60 [2];
  uint local_58 [2];
  uint local_50 [2];
  undefined4 local_48 [4];
  undefined4 local_38 [4];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  local_1c = __TMC_END__;
  pcVar2 = strchr(ipasc,0x3a);
  if (pcVar2 == (char *)0x0) {
    iVar5 = __isoc99_sscanf(ipasc,"%d.%d.%d.%d",local_68,local_60,local_58,local_50);
    if ((((iVar5 == 4) && (local_68[0] < 0x100)) && (local_60[0] < 0x100)) &&
       ((local_58[0] < 0x100 && (local_50[0] < 0x100)))) {
      local_48[0] = CONCAT13((char)local_50[0],
                             CONCAT12((char)local_58[0],
                                      CONCAT11((char)local_60[0],(char)local_68[0])));
LAB_000d2602:
      str = ASN1_OCTET_STRING_new();
      if ((str != (ASN1_OCTET_STRING *)0x0) &&
         (pAVar4 = (ASN1_OCTET_STRING *)ASN1_OCTET_STRING_set(str,local_48,iVar5),
         pAVar4 == (ASN1_OCTET_STRING *)0x0)) {
        ASN1_OCTET_STRING_free(str);
        str = pAVar4;
      }
      goto LAB_000d2626;
    }
  }
  else {
    local_28 = 0;
    local_20 = 0;
    local_24 = -1;
    iVar3 = CONF_parse_list(ipasc,0x3a,0,ipv6_cb + 1,local_38);
    iVar1 = local_24;
    iVar5 = local_28;
    if (iVar3 != 0) {
      if (local_24 == -1) {
        if (local_28 == 0x10) {
LAB_000d2638:
          local_48[0] = local_38[0];
LAB_000d2600:
          iVar5 = 0x10;
          goto LAB_000d2602;
        }
      }
      else if ((local_28 != 0x10) && (local_20 < 4)) {
        if (local_20 == 3) {
          if (local_28 < 1) {
LAB_000d25cc:
            if (local_24 < 0) goto LAB_000d2638;
LAB_000d25d0:
            __memcpy_chk(local_48,local_38,local_24,0x10);
            memset((void *)((int)local_48 + iVar1),0,0x10 - iVar5);
            if (iVar1 != iVar5) {
              memcpy((void *)((int)local_38 + (iVar1 - iVar5)),(void *)((int)local_38 + iVar1),
                     iVar5 - iVar1);
            }
            goto LAB_000d2600;
          }
        }
        else if (local_20 == 2) {
          if (local_24 == 0) goto LAB_000d25d0;
          if (local_24 == local_28) goto LAB_000d25cc;
        }
        else if ((local_24 != 0) && (local_24 != local_28)) goto LAB_000d25cc;
      }
    }
  }
  str = (ASN1_OCTET_STRING *)0x0;
LAB_000d2626:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return str;
}

