
/* WARNING: Could not reconcile some variable overlaps */

ASN1_OCTET_STRING * a2i_IPADDRESS_NC(char *ipasc)

{
  char *pcVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  int iVar4;
  ASN1_OCTET_STRING *str;
  int iVar5;
  int in_GS_OFFSET;
  int *local_74;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  int local_5c [4];
  int local_4c;
  int local_48;
  int local_44;
  int local_40 [4];
  undefined auStack_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar1 = strchr(ipasc,0x2f);
  if ((pcVar1 == (char *)0x0) || (__s = BUF_strdup(ipasc), __s == (char *)0x0)) {
LAB_0816d8c0:
    str = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    __s[(int)pcVar1 - (int)ipasc] = '\0';
    pcVar2 = strchr(__s,0x3a);
    if (pcVar2 == (char *)0x0) {
      iVar5 = __isoc99_sscanf(__s,"%d.%d.%d.%d",&local_6c,&local_68,&local_64,&local_60);
      if ((((iVar5 == 4) && (local_6c < 0x100)) && (local_68 < 0x100)) &&
         ((local_64 < 0x100 && (local_60 < 0x100)))) {
        local_40[0] = (local_64 & 0xff) << 0x10;
        local_40[0] = CONCAT13((char)local_60,
                               (uint3)local_40[0] | (uint3)CONCAT11((char)local_68,(char)local_6c));
        iVar4 = 4;
LAB_0816d81c:
        local_74 = local_40;
        iVar4 = a2i_ipadd((uchar *)(iVar4 + (int)local_74),__s + ((int)pcVar1 - (int)ipasc) + 1);
        CRYPTO_free(__s);
        if (((iVar4 != 0) && (iVar4 == iVar5)) &&
           (str = ASN1_OCTET_STRING_new(), str != (ASN1_OCTET_STRING *)0x0)) {
          iVar5 = ASN1_OCTET_STRING_set(str,local_74,iVar5 + iVar4);
          if (iVar5 == 0) {
            ASN1_OCTET_STRING_free(str);
            str = (ASN1_OCTET_STRING *)0x0;
          }
          goto LAB_0816d89e;
        }
        goto LAB_0816d8c0;
      }
    }
    else {
      local_4c = 0;
      local_48 = -1;
      local_44 = 0;
      iVar3 = CONF_parse_list(__s,0x3a,0,ipv6_cb,local_5c);
      iVar4 = local_48;
      iVar5 = local_4c;
      if (iVar3 != 0) {
        if (local_48 == -1) {
          if (local_4c == 0x10) {
LAB_0816d95b:
            local_40[0] = local_5c[0];
LAB_0816d812:
            iVar4 = 0x10;
            iVar5 = 0x10;
            goto LAB_0816d81c;
          }
        }
        else if ((local_4c != 0x10) && (local_44 < 4)) {
          if (local_44 == 3) {
            if (local_4c < 1) goto LAB_0816d7b1;
          }
          else if (local_44 == 2) {
            if ((local_48 == local_4c) || (local_48 == 0)) goto LAB_0816d7b1;
          }
          else if ((local_48 != local_4c) && (local_48 != 0)) {
LAB_0816d7b1:
            if (local_48 < 0) goto LAB_0816d95b;
            __memcpy_chk(local_40,local_5c,local_48,0x20);
            memset((void *)((int)local_40 + iVar4),0,0x10 - iVar5);
            if (iVar4 != iVar5) {
              memcpy((void *)(((iVar4 + 0x10) - iVar5) + (int)local_40),
                     (void *)((int)local_5c + iVar4),iVar5 - iVar4);
            }
            goto LAB_0816d812;
          }
        }
      }
    }
    CRYPTO_free(__s);
    str = (ASN1_OCTET_STRING *)0x0;
  }
LAB_0816d89e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return str;
}

