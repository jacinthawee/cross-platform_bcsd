
ASN1_OCTET_STRING * a2i_IPADDRESS_NC(char *ipasc)

{
  char *pcVar1;
  char *__s;
  char *pcVar2;
  int iVar3;
  int iVar4;
  ASN1_OCTET_STRING *str;
  ASN1_OCTET_STRING *pAVar5;
  uint uVar6;
  int iVar7;
  uint local_80 [2];
  uint local_78 [2];
  uint local_70 [2];
  uint local_68;
  undefined4 local_64 [4];
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48 [4];
  undefined auStack_38 [20];
  int local_24;
  
  local_24 = __TMC_END__;
  pcVar1 = strchr(ipasc,0x2f);
  if ((pcVar1 != (char *)0x0) && (__s = BUF_strdup(ipasc), __s != (char *)0x0)) {
    __s[(int)pcVar1 - (int)ipasc] = '\0';
    pcVar2 = strchr(__s,0x3a);
    if (pcVar2 == (char *)0x0) {
      iVar7 = __isoc99_sscanf(__s,"%d.%d.%d.%d",local_80,local_78,local_70,&local_68);
      if ((((iVar7 == 4) && (local_80[0] < 0x100)) && (local_78[0] < 0x100)) &&
         ((local_70[0] < 0x100 && (local_68 < 0x100)))) {
        local_48[0] = CONCAT13((char)local_68,
                               CONCAT12((char)local_70[0],
                                        CONCAT11((char)local_78[0],(char)local_80[0])));
LAB_000d287e:
        iVar4 = a2i_ipadd((uchar *)(iVar7 + (int)local_48),__s + ((int)pcVar1 - (int)ipasc) + 1);
        CRYPTO_free(__s);
        uVar6 = count_leading_zeroes(iVar4);
        uVar6 = uVar6 >> 5;
        if (iVar4 != iVar7) {
          uVar6 = uVar6 | 1;
        }
        if ((uVar6 == 0) && (str = ASN1_OCTET_STRING_new(), str != (ASN1_OCTET_STRING *)0x0)) {
          pAVar5 = (ASN1_OCTET_STRING *)ASN1_OCTET_STRING_set(str,local_48,iVar4 + iVar7);
          if (pAVar5 == (ASN1_OCTET_STRING *)0x0) {
            ASN1_OCTET_STRING_free(str);
            str = pAVar5;
          }
          goto LAB_000d28cc;
        }
        goto LAB_000d28ca;
      }
    }
    else {
      local_54 = 0;
      local_4c = 0;
      local_50 = -1;
      iVar3 = CONF_parse_list(__s,0x3a,0,ipv6_cb + 1,local_64);
      iVar4 = local_50;
      iVar7 = local_54;
      if (iVar3 != 0) {
        if (local_50 == -1) {
          if (local_54 == 0x10) {
LAB_000d292e:
            local_48[0] = local_64[0];
LAB_000d287a:
            iVar7 = 0x10;
            goto LAB_000d287e;
          }
        }
        else if ((local_54 != 0x10) && (local_4c < 4)) {
          if (local_4c == 3) {
            if (local_54 < 1) {
LAB_000d2840:
              if (local_50 < 0) goto LAB_000d292e;
LAB_000d2844:
              __memcpy_chk(local_48,local_64,local_50,0x20);
              memset((void *)((int)local_48 + iVar4),0,0x10 - iVar7);
              if (iVar4 != iVar7) {
                memcpy((void *)(((iVar4 + 0x10) - iVar7) + (int)local_48),
                       (void *)((int)local_64 + iVar4),iVar7 - iVar4);
              }
              goto LAB_000d287a;
            }
          }
          else if (local_4c == 2) {
            if (local_50 == 0) goto LAB_000d2844;
            if (local_50 == local_54) goto LAB_000d2840;
          }
          else if ((local_50 != 0) && (local_50 != local_54)) goto LAB_000d2840;
        }
      }
    }
    CRYPTO_free(__s);
  }
LAB_000d28ca:
  str = (ASN1_OCTET_STRING *)0x0;
LAB_000d28cc:
  if (local_24 != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return str;
}

