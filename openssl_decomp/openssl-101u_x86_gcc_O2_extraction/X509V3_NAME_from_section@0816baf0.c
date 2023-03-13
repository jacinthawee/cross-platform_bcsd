
int X509V3_NAME_from_section(X509_NAME *nm,stack_st_CONF_VALUE *dn_sk,ulong chtype)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  byte *pbVar5;
  int iVar6;
  byte *field;
  
  if (nm == (X509_NAME *)0x0) {
    return 0;
  }
  iVar6 = 0;
  do {
    iVar3 = sk_num(&dn_sk->stack);
    if (iVar3 <= iVar6) {
      return 1;
    }
    pvVar4 = sk_value(&dn_sk->stack,iVar6);
    field = *(byte **)((int)pvVar4 + 4);
    bVar1 = *field;
    pbVar5 = field;
    bVar2 = bVar1;
    if (bVar1 == 0) {
      iVar3 = 0;
    }
    else {
      do {
        if (((bVar2 & 0xfd) == 0x2c) || (bVar2 == 0x3a)) {
          if (pbVar5[1] != 0) {
            field = pbVar5 + 1;
            bVar1 = pbVar5[1];
          }
          break;
        }
        pbVar5 = pbVar5 + 1;
        bVar2 = *pbVar5;
      } while (bVar2 != 0);
      iVar3 = 0;
      if (bVar1 == 0x2b) {
        field = field + 1;
        iVar3 = -1;
      }
    }
    iVar3 = X509_NAME_add_entry_by_txt
                      (nm,(char *)field,chtype,*(uchar **)((int)pvVar4 + 8),-1,-1,iVar3);
    if (iVar3 == 0) {
      return 0;
    }
    iVar6 = iVar6 + 1;
  } while( true );
}

