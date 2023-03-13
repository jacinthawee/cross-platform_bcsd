
ASN1_OCTET_STRING * a2i_IPADDRESS(char *ipasc)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  ASN1_OCTET_STRING *str;
  int iVar4;
  int in_GS_OFFSET;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c [4];
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30 [4];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar2 = strchr(ipasc,0x3a);
  if (pcVar2 == (char *)0x0) {
    iVar4 = __isoc99_sscanf(ipasc,"%d.%d.%d.%d",&local_5c,&local_58,&local_54,&local_50);
    if ((((iVar4 == 4) && (local_5c < 0x100)) && (local_58 < 0x100)) &&
       ((local_54 < 0x100 && (local_50 < 0x100)))) {
      local_30[0] = CONCAT13((char)local_50,
                             CONCAT12((char)local_54,CONCAT11((char)local_58,(char)local_5c)));
LAB_0816b4ec:
      str = ASN1_OCTET_STRING_new();
      if (str != (ASN1_OCTET_STRING *)0x0) {
        iVar4 = ASN1_OCTET_STRING_set(str,local_30,iVar4);
        if (iVar4 != 0) goto LAB_0816b522;
        ASN1_OCTET_STRING_free(str);
      }
    }
  }
  else {
    local_3c = 0;
    local_38 = -1;
    local_34 = 0;
    iVar3 = CONF_parse_list(ipasc,0x3a,0,ipv6_cb,local_4c);
    iVar1 = local_38;
    iVar4 = local_3c;
    if (iVar3 != 0) {
      if (local_38 == -1) {
        if (local_3c == 0x10) {
LAB_0816b547:
          local_30[0] = local_4c[0];
LAB_0816b4e7:
          iVar4 = 0x10;
          goto LAB_0816b4ec;
        }
      }
      else if ((local_3c != 0x10) && (local_34 < 4)) {
        if (local_34 == 3) {
          if (local_3c < 1) goto LAB_0816b49a;
        }
        else if (local_34 == 2) {
          if ((local_38 == local_3c) || (local_38 == 0)) goto LAB_0816b49a;
        }
        else if ((local_38 != local_3c) && (local_38 != 0)) {
LAB_0816b49a:
          if (local_38 < 0) goto LAB_0816b547;
          __memcpy_chk(local_30,local_4c,local_38,0x10);
          memset((void *)((int)local_30 + iVar1),0,0x10 - iVar4);
          if (iVar1 != iVar4) {
            memcpy((void *)((int)local_30 + ((iVar1 + 0x10) - iVar4)),
                   (void *)((int)local_4c + iVar1),iVar4 - iVar1);
          }
          goto LAB_0816b4e7;
        }
      }
    }
  }
  str = (ASN1_OCTET_STRING *)0x0;
LAB_0816b522:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return str;
}

