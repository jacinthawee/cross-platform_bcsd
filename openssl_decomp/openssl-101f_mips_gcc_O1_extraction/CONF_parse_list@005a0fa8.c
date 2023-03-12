
int CONF_parse_list(char *list,int sep,int nospc,list_cb *list_cb,void *arg)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  
  if (list == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x77,0x73,"conf_mod.c",0x24c);
    return 0;
  }
  do {
    if (nospc == 0) {
LAB_005a1044:
      pcVar6 = (char *)(*(code *)PTR_strchr_006aab34)(list,sep);
      if ((list == pcVar6) || (*list == '\0')) goto LAB_005a10f8;
      if (pcVar6 == (char *)0x0) {
        iVar2 = (*(code *)PTR_strlen_006aab30)(list);
        pbVar4 = (byte *)(list + iVar2 + -1);
      }
      else {
        pbVar4 = (byte *)(pcVar6 + -1);
      }
      iVar2 = (int)pbVar4 - (int)list;
      if (nospc != 0) {
        piVar1 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
        do {
          pbVar5 = pbVar4;
          pbVar4 = pbVar5 + -1;
        } while ((*(ushort *)(*piVar1 + (uint)*pbVar5 * 2) & 0x20) != 0);
        iVar2 = (int)pbVar5 - (int)list;
      }
      iVar2 = (*list_cb)(list,iVar2 + 1,arg);
    }
    else {
      uVar3 = (uint)*list;
      pcVar6 = list;
      if (uVar3 != 0) {
        piVar1 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
        do {
          pcVar6 = list + 1;
          if ((*(ushort *)(*piVar1 + (uVar3 & 0xff) * 2) & 0x20) == 0) goto LAB_005a1044;
          uVar3 = (uint)*pcVar6;
          list = pcVar6;
        } while (uVar3 != 0);
      }
      pcVar6 = (char *)(*(code *)PTR_strchr_006aab34)(pcVar6,sep);
LAB_005a10f8:
      iVar2 = (*list_cb)((char *)0x0,0,arg);
    }
    if (iVar2 < 1) {
      return iVar2;
    }
    list = pcVar6 + 1;
    if (pcVar6 == (char *)0x0) {
      return 1;
    }
  } while( true );
}

