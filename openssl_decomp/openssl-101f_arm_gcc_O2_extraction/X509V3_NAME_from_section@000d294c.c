
int X509V3_NAME_from_section(X509_NAME *nm,stack_st_CONF_VALUE *dn_sk,ulong chtype)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  byte *field;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  
  if (nm == (X509_NAME *)0x0) {
    return 0;
  }
  iVar6 = 0;
  iVar2 = sk_num(&dn_sk->stack);
  if (0 < iVar2) {
    do {
      pvVar3 = sk_value(&dn_sk->stack,iVar6);
      field = *(byte **)((int)pvVar3 + 4);
      bVar4 = *field;
      if (bVar4 == 0) {
LAB_000d29ac:
        iVar2 = 0;
      }
      else {
        pbVar5 = field;
        if (bVar4 != 0x3a && (bVar4 & 0xfd) != 0x2c) {
          do {
            pbVar5 = pbVar5 + 1;
            bVar1 = *pbVar5;
            if (bVar1 == 0) goto LAB_000d29a0;
          } while (bVar1 != 0x3a && (bVar1 & 0xfd) != 0x2c);
        }
        if (pbVar5[1] != 0) {
          field = pbVar5 + 1;
          bVar4 = pbVar5[1];
        }
LAB_000d29a0:
        if (bVar4 != 0x2b) goto LAB_000d29ac;
        field = field + 1;
        iVar2 = -1;
      }
      iVar2 = X509_NAME_add_entry_by_txt
                        (nm,(char *)field,chtype,*(uchar **)((int)pvVar3 + 8),-1,-1,iVar2);
      if (iVar2 == 0) {
        return 0;
      }
      iVar6 = iVar6 + 1;
      iVar2 = sk_num(&dn_sk->stack);
    } while (iVar6 < iVar2);
  }
  return 1;
}

