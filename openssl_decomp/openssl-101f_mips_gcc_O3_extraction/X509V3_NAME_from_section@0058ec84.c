
int X509V3_NAME_from_section(X509_NAME *nm,stack_st_CONF_VALUE *dn_sk,ulong chtype)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int set;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  
  if (nm == (X509_NAME *)0x0) {
    return 0;
  }
  iVar7 = 0;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(dn_sk);
  if (0 < iVar4) {
    do {
      iVar4 = (*(code *)PTR_sk_value_006a7f24)(dn_sk,iVar7);
      pbVar5 = *(byte **)(iVar4 + 4);
      bVar1 = *pbVar5;
      if (bVar1 == 0) goto LAB_0058ed54;
      if ((bVar1 == 0x3a) || (pbVar3 = pbVar5, (bVar1 & 0xfd) == 0x2c)) {
        set = 0;
        pbVar6 = pbVar5;
        if ((pbVar5[1] != 0) && (pbVar6 = pbVar5 + 1, pbVar5[1] == 0x2b)) {
          pbVar6 = pbVar5 + 2;
          goto LAB_0058edd4;
        }
      }
      else {
        do {
          pbVar6 = pbVar3;
          bVar2 = pbVar6[1];
          if (bVar2 == 0) goto LAB_0058ed4c;
        } while ((bVar2 != 0x3a) && (pbVar3 = pbVar6 + 1, (bVar2 & 0xfd) != 0x2c));
        if (pbVar6[2] == 0) {
LAB_0058ed4c:
          if (bVar1 != 0x2b) {
LAB_0058ed54:
            set = 0;
            pbVar6 = pbVar5;
            goto LAB_0058ed58;
          }
          pbVar6 = pbVar5 + 1;
        }
        else {
          pbVar5 = pbVar6 + 2;
          if (pbVar6[2] != 0x2b) goto LAB_0058ed54;
          pbVar6 = pbVar6 + 3;
        }
LAB_0058edd4:
        set = -1;
      }
LAB_0058ed58:
      iVar4 = X509_NAME_add_entry_by_txt(nm,(char *)pbVar6,chtype,*(uchar **)(iVar4 + 8),-1,-1,set);
      if (iVar4 == 0) {
        return 0;
      }
      iVar7 = iVar7 + 1;
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(dn_sk);
    } while (iVar7 < iVar4);
  }
  return 1;
}

