
int CONF_parse_list(char *list,int sep,int nospc,list_cb *list_cb,void *arg)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  char *pcVar6;
  
  if (list == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x77,0x73,"conf_mod.c",0x237);
    return 0;
  }
  do {
    if (nospc == 0) {
LAB_0059e2d4:
      pcVar6 = (char *)(*(code *)PTR_strchr_006a9a28)(list,sep);
      if ((list == pcVar6) || (*list == '\0')) goto LAB_0059e388;
      if (pcVar6 == (char *)0x0) {
        iVar2 = (*(code *)PTR_strlen_006a9a24)(list);
        pbVar4 = (byte *)(list + iVar2 + -1);
      }
      else {
        pbVar4 = (byte *)(pcVar6 + -1);
      }
      iVar2 = (int)pbVar4 - (int)list;
      if (nospc != 0) {
        piVar1 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
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
        piVar1 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
        do {
          pcVar6 = list + 1;
          if ((*(ushort *)(*piVar1 + (uVar3 & 0xff) * 2) & 0x20) == 0) goto LAB_0059e2d4;
          uVar3 = (uint)*pcVar6;
          list = pcVar6;
        } while (uVar3 != 0);
      }
      pcVar6 = (char *)(*(code *)PTR_strchr_006a9a28)(pcVar6,sep);
LAB_0059e388:
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

